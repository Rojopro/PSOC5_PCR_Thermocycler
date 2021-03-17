/*******************************************************************************
* File Name: DieTemp_DieTemp.c
* Version 2.10
*
* Description:
*  Provides the API to acquire the die temperature.
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.H>
#include <DieTemp.h>


#define DieTemp_NUMBER_OF_SAMPLES      (0x1u)
#define DieTemp_TIMER_PERIOD           (0xFFFu)
#define DieTemp_CLK_DIV_SELECT         (0x4u)
#define DieTemp_SPC_CLK_PERIOD         (120u) /* In nano seconds. */
#define DieTemp_NANO_TO_MILLI_FACTOR   (1000000u)
#define DieTemp_FRM_EXEC_TIME          (1000u) /* In nano seconds. */

#define DieTemp_GET_TEMPR_TIME     (uint32)(((((uint32)1u << (DieTemp_NUMBER_OF_SAMPLES + 1u))) * \
                                                ((uint32)(DieTemp_SPC_CLK_PERIOD * \
                                                DieTemp_CLK_DIV_SELECT)) * \
                                                ((uint32)DieTemp_TIMER_PERIOD)) + \
                                                (uint32)DieTemp_FRM_EXEC_TIME)

#define DieTemp_MAX_WAIT           (uint16)(((DieTemp_GET_TEMPR_TIME + \
                                                DieTemp_NANO_TO_MILLI_FACTOR) - 1u) / \
                                                DieTemp_NANO_TO_MILLI_FACTOR)  /* In milli seconds */
#define DieTemp_MAX_WAIT_USEC          (DieTemp_MAX_WAIT * 1000u)    /* In usec */
#define DieTemp_USEC_STEP              (10u) /* Step in usec */

static cystatus DieTemp_GetTempT(int16 * temperature);


/*******************************************************************************
* Function Name: DieTemp_Start
********************************************************************************
*
* Summary:
*  Sends the command and parameters to the SPC to start a Die Temperature 
*  reading. This function returns before the SPC finishes. 
*  This function call must always be paired with a call to the DieTemp_Query()
*  API to complete the Die Temperature read
*
* Parameters:
*  void.
*
* Return:
*  CYRET_STARTED if the spc command startes successfully.
*  CYRET_UNKNOWN if the spc command failes.
*  CYRET_LOCKED if the spc is busy.
*
*******************************************************************************/
cystatus DieTemp_Start(void) 
{
    cystatus status;

    /* Plan for failure. */
    status = CYRET_UNKNOWN;

    /* Power up the SPC. */
    CySpcStart();

    if(CySpcLock() == CYRET_SUCCESS)
    {
        #if(CY_PSOC5A)
            if(CYRET_STARTED == CySpcGetTemp(DieTemp_NUMBER_OF_SAMPLES,
                                             DieTemp_TIMER_PERIOD,
                                             DieTemp_CLK_DIV_SELECT))
            {
                status = CYRET_STARTED;
            }
        #else
            if(CYRET_STARTED == CySpcGetTemp(DieTemp_NUMBER_OF_SAMPLES))
            {
                status = CYRET_STARTED;
            }
        #endif  /* (CY_PSOC5A) */
        CySpcUnlock();
    }
    else
    {
        status = CYRET_LOCKED;
    }
    return (status);
}


/*******************************************************************************
* FUNCTION NAME:   DieTemp_Stop
********************************************************************************
*
* Summary:
*  There is no need to stop or disable this component. This component is
*  naturally a slave that sends request to SPC through SPC API of cy_boot
*  and waits for data to be ready or in the case of non-blocking operation it
*  sends the request to SPC and the user can manually poll the result.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void DieTemp_Stop(void) 
{
    /* There aren't anything to stop */
}


/*******************************************************************************
* Function Name: DieTemp_Query
********************************************************************************
*
* Summary:
*  Checks to see if the SPC command started by DieTemp_Start() has finished. 
*  If the command has not finished, the temperature value is not read and
*  returned. The caller will need to poll this function while the return status 
*  remains CYRET_STARTED.
*  This can be used only in conjunction with the DieTemp_Start() API to 
*  successfully get the correct Die Temperature.
*  The Die Temperature reading returned on the first sequence of DieTemp_Start() 
*  followed by DieTemp_Query() can be unreliable, so you must do this sequence
*  twice and use the value returned from the second sequence.
*
* Parameters:
*  temperature: Address to store the two-byte temperature value.
*
* Return:
*  CYRET_SUCCESS if the temperature command completes successfully.
*  CYRET_UNKNOWN if the spc failures.
*  CYRET_STARTED if the temperature command has not completed.
*  CYRET_TIMEOUT if waites too long before reading data.
*
*******************************************************************************/
cystatus DieTemp_Query(int16 * temperature) 
{
    uint8 temp[2u];
    cystatus status;

    if(CY_SPC_BUSY)
    {
        if((CY_SPC_STATUS_REG>>2u) == CYRET_SUCCESS)
        {
            /* See if any data is ready. */
            if(CY_SPC_DATA_READY)
            {
                temp[0u] = CY_SPC_CPU_DATA_REG;
                /* Wait for second byte to be ready */
                while(!CY_SPC_DATA_READY)
                {
                    CyDelayUs(1u);
                }
                temp[1u] = CY_SPC_CPU_DATA_REG;
                status = CYRET_SUCCESS;
            }
            else
            {
            	status = CYRET_STARTED;
            }

            if (status == CYRET_SUCCESS)
            {
                if(temp[0u] == 1u)
                {
                    *temperature = (int16) ((uint16) temp[1]);
                }
                else
                {
                    *temperature = (int16) - ((int16) temp[1]);
                }
                status = CYRET_SUCCESS;
            }
        }
        else
        {
            status = CYRET_STARTED;
        }
    }
    else
    {
        status = CYRET_TIMEOUT;
    }

    if(status != CYRET_STARTED)
    {
        /* Unlock the SPC so someone else can use it. */
        CySpcUnlock();
    }

    return (status);
}


/*******************************************************************************
* Function Name: DieTemp_GetTempT
********************************************************************************
*
* Summary:
*  Sends the command and parameters to the SPC to start a Die Temperature 
*  reading and waits until it fails or completes. This is a blocking function.
*  This function starts the temperature reading and returns the temperature 
*  value after the SPC temperature command completes successfully.
*
* Parameters:
*  temperature: Address to store the two byte temperature value.
*
* Return:
*  CYRET_SUCCESS if the command completes successfully.
*  The Status code from DieTemp_Start or DieTemp_Query.
*
*******************************************************************************/
static cystatus DieTemp_GetTempT(int16 * temperature) 
{
    uint16 us;
    cystatus status;

    /* Start the temp reading */
    status = DieTemp_Start();

    if(status == CYRET_STARTED)
    {
        /**************************************************************************
        * Wait for SPC to finish temperature reading. If state changes and SPC
        * finishes - break cycle.
        * DieTemp_MAX_WAIT_USEC is maximum time in usec to wait for SPC.
        **************************************************************************/
        for (us=(DieTemp_MAX_WAIT_USEC); us>0u; us-=DieTemp_USEC_STEP)
        {
            if((CYRET_STARTED != status)&&(CY_SPC_IDLE))
            {
                break;
            }
            else if(CYRET_STARTED == status)
            {
                status = DieTemp_Query(temperature);
            }
            else
            {
                /* SPC has not finished reading or isn't idle */
            }
            CyDelayUs(DieTemp_USEC_STEP);
        }
    }

    return status;
}


/*******************************************************************************
* Function Name: DieTemp_GetTemp
********************************************************************************
*
* Summary:
*  Sends the command and parameters to the SPC to start a Die Temperature 
*  reading and waits until it fails or completes. This is a blocking API.
*  This function reads the Die Temperature twice and returns the second value
*  to work around an issue in the silicon that causes the first value read 
*  to be unreliable.
*
* Parameters:
*  temperature: Address to store the two byte temperature value.
*
* Return:
*  CYRET_SUCCESS if the command completes successfully.
*  The Status code from DieTemp_Start or DieTemp_Query.
*
*******************************************************************************/
cystatus DieTemp_GetTemp(int16 * temperature) 
{
    cystatus status;
    uint8 count = 2u;
    while (count != 0u)
    {
        status = DieTemp_GetTempT(temperature);
        if (status != CYRET_SUCCESS)
        {
            break;
        }
        count--;
    }
    return status;
}


/* [] END OF FILE */
