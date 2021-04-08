#include <project.h>
#include <stdlib.h>
#include "math.h"
#include "ssd1306.h"
#include <stdio.h>
#include <stdlib.h>

#define DISPLAY_ADDRESS 0x3C // 011110+SA0+RW - 0x3C or 0x3D

/*
    L= length
    W=trace width
    T=trace height
*/
const float P = 0.125;
const float I = 1;
const float D = 0.001;

const int RIcalib = 998;    ///////à calibrer -> mesurer au multimetre

const float W = 0.00001;    //0.01*10^-3 //constant
const float L = 0.3447;     // ~30.10^3  //constant //utilisé pour la calib manuelle
const float T = 0.0003;     //0.3*10^-3   //variable

const float temp0 = 0.00;
const float temp1 = 94.00;
const int T1 = 15;      //120s
const float temp2 = 55.00;
const int T2 = 15;       //20s
const float temp3 = 72.00;
const int T3 = 30;      //300s

int step = 0;
int InterruptCnt;
int8 btnState = -1;
int16 IdacCalib_temperature = 0;
int Adc_Offset = 0;
int Idac_Offset = 0;
int current = 125; //(255 = 2.04mA / 125 = 1mA)
float Rmes;

float reg = 0.00;

float deriv = 0;
float prevTemp = 0.00;
int prevTime = 0;


CY_ISR(InterruptHandler)
{
   	Timer_STATUS;
    InterruptCnt++;    
}
CY_ISR(sw1Handler)
{
    btnState++;    
}

void DMA_Config(void)   //WIP - non validé
{
    /* Declare variable to hold the handle for DMA channel */
    uint8 channelHandle;

    /* Declare DMA Transaction Descriptor for memory transfer into
     * Filter Channel.
     */
    uint8 tdChanA;

    /* Configure the DMA to Transfer the data in 1 burst with individual trigger
     * for each burst.
     */
    channelHandle = DMA_DmaInitialize((1u), (1u), HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_PERIPH_BASE));

    /* This function allocates a TD for use with an initialized DMA channel */
    tdChanA = CyDmaTdAllocate();

    /* Configure the tdChanA to transfer 1 byte with no next TD */
    CyDmaTdSetConfiguration(tdChanA, 1u, DMA_INVALID_TD, 0u);

    /* Set the source address as ADC_DelSig and the destination as
     * Filter Channel A.
     */
    CyDmaTdSetAddress(tdChanA, LO16((uint32)ADC_DEC_SAMP_PTR), LO16((uint32)Filter_1_STAGEAH_PTR));

    /* Set tdChanA to be the initial TD associated with channelHandle */
    CyDmaChSetInitialTd(channelHandle, tdChanA);

    /* Enable the DMA channel represented by channelHandle and preserve the TD */
    CyDmaChEnable(channelHandle, 1u);
}

void Calibration(){
    
int loop = 0;  
int V_calib_theorique = RIcalib*(current*2040/255);
	
    AMux_Adc_Select(2);     
    
    for(loop = 0; loop < 4; loop++) //calibration ADC
    {    
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        Adc_Offset += ADC_CountsTo_uVolts(ADC_GetResult32());  
        ADC_StopConvert();
    }

    Adc_Offset /= 4;

    AMux_Adc_Select(0);
    AMux_Idac_Select(0);
    IDAC_SetValue(current);

    for(loop = 0; loop < 4; loop++) //calibration IDAC
    {    
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        Idac_Offset += ADC_CountsTo_uVolts(ADC_GetResult32());  
        ADC_StopConvert();
    }

    IDAC_SetValue(0);
    Idac_Offset /=4;
    Idac_Offset -= V_calib_theorique;
    Idac_Offset /= RIcalib;
    
    
    Idac_Offset *= 255/2040;

}

float GetTemp(){
	int V_mes = 0;
    float temp;
    float Vol;
   
    /*                         //formule
    R=ρ⋅(L/T⋅W)⋅[1+α⋅(temp−25)]
    
    ρ=resistivity
    L= length
    W=trace width
    T=trace height
    ρ copper  =  1.7 x 10-6 ohm-cm
        -> gold 2.4 x 10-6
    α copper (temperature coefficient) = 3.9 x 10-3 ohm/ohm/C
        -> gold 0.003715 -> empiriquement 2.365*10-3 ?
    */
	
	AMux_Idac_Select(1); 
	AMux_Adc_Select(1);
        
    IDAC_SetValue(current-Idac_Offset);
    
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);        
        ADC_StopConvert();
        V_mes = ADC_CountsTo_uVolts(ADC_GetResult32())-Adc_Offset; 
        
       /* while (Filter_1_IsInterruptChannelA() == 0) ;                     ///////overflow du filtre
	    V_mes = ADC_CountsTo_uVolts(Filter_1_Read16(Filter_1_CHANNEL_A));*/
	
	IDAC_SetValue(0);
    
    Rmes = (float)V_mes / ((float)(current*2040/255)-(float)Idac_Offset);
    Vol = L/(W*T);
    temp = (((Rmes/(0.0000024*Vol))-1)/0.002358)+25;
    
    return(temp);  
}

void Regulation(float actualTemp, float consigne){
    float error;
    
    error = consigne - actualTemp;
    
    //reg += (deriv*D);                 // D /!\ non calibré - risque de surchauffe /!\
    
    if(error>0 && reg < 65535 ){        // I
        reg+=I;}
    else if(error<0 && reg>0){
        reg-=I;}
    
    reg+=(error*P);                     // P
    
    if(reg<300){            //compensation offset de chauffe    //calib en fonction de la T la plus basse ?
        reg = 300;
    }
      
    if(consigne==0.00){     //turn off
        reg = 0;}

    PWM_1_WriteCompare((int)reg);
}

/////////////////////////////////////////////////////////main

int main(){

char buffer[100];
char usbbuffer[100];
char state[100];

float temperature;
int16 psoc_temperature;
int16 temperature_diff;
    CyDelay(2000);
    I2COLED_Start();
    
    PWM_1_Start();
    
    ADC_Start();
    IDAC_Start();
    
    AMux_Adc_Start(); 
	AMux_Idac_Start();
    
   // Filter_1_Start();                     //filtre en overflow
   // Filter_1_INT_CTRL_REG |= (1 << Filter_1_CHANNEL_A);
   // DMA_Config();
    
    CyGlobalIntEnable;
    tim_StartEx(InterruptHandler);
    sw1_StartEx(sw1Handler);
    Timer_Start();
    display_init(DISPLAY_ADDRESS);
    
    USBUART_Start(0u, USBUART_5V_OPERATION);
    USBUART_CDC_Init();

   Calibration();
    
DieTemp_GetTemp(&IdacCalib_temperature);

    for(;;){   
      DieTemp_GetTemp(&psoc_temperature);
		temperature_diff = psoc_temperature - IdacCalib_temperature;	
		if((temperature_diff > 10) || (temperature_diff  < -10))    //si la temperature du Die a changé
		{			
            Calibration();                                          //calib pour compenser le drift de l'IDAC
			IdacCalib_temperature = psoc_temperature; 
		}
        
        temperature = GetTemp();
        
        switch(step)
        {
        case 0: //off
            Regulation(temperature, temp0);
            
            sprintf(state,"off");
            sprintf(usbbuffer,"25");
            if(btnState>0){
              step=1;
              btnState=0;
            }
            break;
        case 1: //prechauffage T1
            Regulation(temperature, temp1);           
            sprintf(state,"S1|94C|WIP");    // WIP : injecter la variable T1 dans le sprintf
            sprintf(usbbuffer,"94");
                if(temperature>(temp1-2.00) && temperature<(temp1+2.00)){
                    step=2;
                    InterruptCnt=0;
                }
            break;
        case 2: //cuisson
            Regulation(temperature, temp1); 
            sprintf(usbbuffer,"94");
            sprintf(state,"S1|94C|%d", T1 - (int)(InterruptCnt/1000));    
                if((T1-(int)(InterruptCnt/1000))<=0){
                    step=3;
                }
                break;
        case 3: //prechauffage T2
            Regulation(temperature, temp2);      
            sprintf(state,"S2|55C|WIP");
            sprintf(usbbuffer,"55");
                if(temperature>(temp2-2.00) && temperature<(temp2+2.00)){
                    step=4;
                    InterruptCnt=0;
                }
            break;
        case 4: //cuisson
            Regulation(temperature, temp2);  
            sprintf(usbbuffer,"55");
            sprintf(state,"S1|55C|%d", T2 - (int)(InterruptCnt/1000));    
                if((T2-(int)(InterruptCnt/1000))<=0){
                    step=5;
                }
                break;
        case 5: //prechauffage T3
            Regulation(temperature, temp3); 
            sprintf(usbbuffer,"72");
            sprintf(state,"S3|72C|WIP");
                if(temperature>(temp3-2.00) && temperature<(temp3+2.00)){
                    step=6;
                    InterruptCnt=0;
                }            
            break;
        case 6: //cuisson
            Regulation(temperature, temp3); 
            sprintf(usbbuffer,"72");
            sprintf(state,"S1|72C|%d", T3 - (int)(InterruptCnt/1000));    
                if((T3-(int)(InterruptCnt/1000))<=0){
                    step=0;
                }
            break;
        }
        
        display_clear();
        gfx_setTextSize(2);
        gfx_setTextColor(WHITE);
        gfx_setCursor(0,0);
        gfx_print("R:");
        sprintf(buffer,"%d.%02u", (int) Rmes, (int) ((Rmes - (int) Rmes) * 100) );
        gfx_println(buffer);
        gfx_print("T:");
        sprintf(buffer,"%d.%02u", (int) temperature, (int) ((temperature - (int) temperature) * 100) );
        gfx_println(buffer);
        gfx_print(state);
        display_update();    
        
        if(USBUART_CDCIsReady()!=0u){   //envoi USB si port disponible
            sprintf(usbbuffer,"%s,%s\n",usbbuffer, buffer );
            USBUART_PutString(usbbuffer);
            }
        CyDelay(100);
        
        if(step!=0){    //prototype de dérivée pour asservissement - non validé
            deriv = (GetTemp()-prevTemp)/((float)(InterruptCnt-prevTime)/1000);
            prevTemp = GetTemp();
            prevTime = InterruptCnt;
        }
    }
}

/* [] END OF FILE */
