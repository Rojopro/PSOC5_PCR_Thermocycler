/*******************************************************************************
* File Name: AMux_Idac.h
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

#if !defined(CY_AMUX_AMux_Idac_H)
#define CY_AMUX_AMux_Idac_H

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

void AMux_Idac_Start(void) ;
#define AMux_Idac_Init() AMux_Idac_Start()
void AMux_Idac_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void AMux_Idac_Stop(void); */
/* void AMux_Idac_Select(uint8 channel); */
/* void AMux_Idac_Connect(uint8 channel); */
/* void AMux_Idac_Disconnect(uint8 channel); */
/* void AMux_Idac_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define AMux_Idac_CHANNELS  2u
#define AMux_Idac_MUXTYPE   1
#define AMux_Idac_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define AMux_Idac_NULL_CHANNEL 0xFFu
#define AMux_Idac_MUX_SINGLE   1
#define AMux_Idac_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if AMux_Idac_MUXTYPE == AMux_Idac_MUX_SINGLE
# if !AMux_Idac_ATMOSTONE
#  define AMux_Idac_Connect(channel) AMux_Idac_Set(channel)
# endif
# define AMux_Idac_Disconnect(channel) AMux_Idac_Unset(channel)
#else
# if !AMux_Idac_ATMOSTONE
void AMux_Idac_Connect(uint8 channel) ;
# endif
void AMux_Idac_Disconnect(uint8 channel) ;
#endif

#if AMux_Idac_ATMOSTONE
# define AMux_Idac_Stop() AMux_Idac_DisconnectAll()
# define AMux_Idac_Select(channel) AMux_Idac_FastSelect(channel)
void AMux_Idac_DisconnectAll(void) ;
#else
# define AMux_Idac_Stop() AMux_Idac_Start()
void AMux_Idac_Select(uint8 channel) ;
# define AMux_Idac_DisconnectAll() AMux_Idac_Start()
#endif

#endif /* CY_AMUX_AMux_Idac_H */


/* [] END OF FILE */
