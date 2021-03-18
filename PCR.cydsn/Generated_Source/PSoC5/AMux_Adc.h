/*******************************************************************************
* File Name: AMux_Adc.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_AMux_Adc_H)
#define CY_AMUX_AMux_Adc_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*        Function Prototypes
***************************************/

void AMux_Adc_Start(void) ;
#define AMux_Adc_Init() AMux_Adc_Start()
void AMux_Adc_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void AMux_Adc_Stop(void); */
/* void AMux_Adc_Select(uint8 channel); */
/* void AMux_Adc_Connect(uint8 channel); */
/* void AMux_Adc_Disconnect(uint8 channel); */
/* void AMux_Adc_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define AMux_Adc_CHANNELS  3u
#define AMux_Adc_MUXTYPE   2
#define AMux_Adc_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define AMux_Adc_NULL_CHANNEL 0xFFu
#define AMux_Adc_MUX_SINGLE   1
#define AMux_Adc_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if AMux_Adc_MUXTYPE == AMux_Adc_MUX_SINGLE
# if !AMux_Adc_ATMOSTONE
#  define AMux_Adc_Connect(channel) AMux_Adc_Set(channel)
# endif
# define AMux_Adc_Disconnect(channel) AMux_Adc_Unset(channel)
#else
# if !AMux_Adc_ATMOSTONE
void AMux_Adc_Connect(uint8 channel) ;
# endif
void AMux_Adc_Disconnect(uint8 channel) ;
#endif

#if AMux_Adc_ATMOSTONE
# define AMux_Adc_Stop() AMux_Adc_DisconnectAll()
# define AMux_Adc_Select(channel) AMux_Adc_FastSelect(channel)
void AMux_Adc_DisconnectAll(void) ;
#else
# define AMux_Adc_Stop() AMux_Adc_Start()
void AMux_Adc_Select(uint8 channel) ;
# define AMux_Adc_DisconnectAll() AMux_Adc_Start()
#endif

#endif /* CY_AMUX_AMux_Adc_H */


/* [] END OF FILE */
