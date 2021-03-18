/*******************************************************************************
* File Name: Calib_GND.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Calib_GND_H) /* Pins Calib_GND_H */
#define CY_PINS_Calib_GND_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Calib_GND_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Calib_GND__PORT == 15 && ((Calib_GND__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Calib_GND_Write(uint8 value);
void    Calib_GND_SetDriveMode(uint8 mode);
uint8   Calib_GND_ReadDataReg(void);
uint8   Calib_GND_Read(void);
void    Calib_GND_SetInterruptMode(uint16 position, uint16 mode);
uint8   Calib_GND_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Calib_GND_SetDriveMode() function.
     *  @{
     */
        #define Calib_GND_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Calib_GND_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Calib_GND_DM_RES_UP          PIN_DM_RES_UP
        #define Calib_GND_DM_RES_DWN         PIN_DM_RES_DWN
        #define Calib_GND_DM_OD_LO           PIN_DM_OD_LO
        #define Calib_GND_DM_OD_HI           PIN_DM_OD_HI
        #define Calib_GND_DM_STRONG          PIN_DM_STRONG
        #define Calib_GND_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Calib_GND_MASK               Calib_GND__MASK
#define Calib_GND_SHIFT              Calib_GND__SHIFT
#define Calib_GND_WIDTH              1u

/* Interrupt constants */
#if defined(Calib_GND__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Calib_GND_SetInterruptMode() function.
     *  @{
     */
        #define Calib_GND_INTR_NONE      (uint16)(0x0000u)
        #define Calib_GND_INTR_RISING    (uint16)(0x0001u)
        #define Calib_GND_INTR_FALLING   (uint16)(0x0002u)
        #define Calib_GND_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Calib_GND_INTR_MASK      (0x01u) 
#endif /* (Calib_GND__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Calib_GND_PS                     (* (reg8 *) Calib_GND__PS)
/* Data Register */
#define Calib_GND_DR                     (* (reg8 *) Calib_GND__DR)
/* Port Number */
#define Calib_GND_PRT_NUM                (* (reg8 *) Calib_GND__PRT) 
/* Connect to Analog Globals */                                                  
#define Calib_GND_AG                     (* (reg8 *) Calib_GND__AG)                       
/* Analog MUX bux enable */
#define Calib_GND_AMUX                   (* (reg8 *) Calib_GND__AMUX) 
/* Bidirectional Enable */                                                        
#define Calib_GND_BIE                    (* (reg8 *) Calib_GND__BIE)
/* Bit-mask for Aliased Register Access */
#define Calib_GND_BIT_MASK               (* (reg8 *) Calib_GND__BIT_MASK)
/* Bypass Enable */
#define Calib_GND_BYP                    (* (reg8 *) Calib_GND__BYP)
/* Port wide control signals */                                                   
#define Calib_GND_CTL                    (* (reg8 *) Calib_GND__CTL)
/* Drive Modes */
#define Calib_GND_DM0                    (* (reg8 *) Calib_GND__DM0) 
#define Calib_GND_DM1                    (* (reg8 *) Calib_GND__DM1)
#define Calib_GND_DM2                    (* (reg8 *) Calib_GND__DM2) 
/* Input Buffer Disable Override */
#define Calib_GND_INP_DIS                (* (reg8 *) Calib_GND__INP_DIS)
/* LCD Common or Segment Drive */
#define Calib_GND_LCD_COM_SEG            (* (reg8 *) Calib_GND__LCD_COM_SEG)
/* Enable Segment LCD */
#define Calib_GND_LCD_EN                 (* (reg8 *) Calib_GND__LCD_EN)
/* Slew Rate Control */
#define Calib_GND_SLW                    (* (reg8 *) Calib_GND__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Calib_GND_PRTDSI__CAPS_SEL       (* (reg8 *) Calib_GND__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Calib_GND_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Calib_GND__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Calib_GND_PRTDSI__OE_SEL0        (* (reg8 *) Calib_GND__PRTDSI__OE_SEL0) 
#define Calib_GND_PRTDSI__OE_SEL1        (* (reg8 *) Calib_GND__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Calib_GND_PRTDSI__OUT_SEL0       (* (reg8 *) Calib_GND__PRTDSI__OUT_SEL0) 
#define Calib_GND_PRTDSI__OUT_SEL1       (* (reg8 *) Calib_GND__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Calib_GND_PRTDSI__SYNC_OUT       (* (reg8 *) Calib_GND__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Calib_GND__SIO_CFG)
    #define Calib_GND_SIO_HYST_EN        (* (reg8 *) Calib_GND__SIO_HYST_EN)
    #define Calib_GND_SIO_REG_HIFREQ     (* (reg8 *) Calib_GND__SIO_REG_HIFREQ)
    #define Calib_GND_SIO_CFG            (* (reg8 *) Calib_GND__SIO_CFG)
    #define Calib_GND_SIO_DIFF           (* (reg8 *) Calib_GND__SIO_DIFF)
#endif /* (Calib_GND__SIO_CFG) */

/* Interrupt Registers */
#if defined(Calib_GND__INTSTAT)
    #define Calib_GND_INTSTAT            (* (reg8 *) Calib_GND__INTSTAT)
    #define Calib_GND_SNAP               (* (reg8 *) Calib_GND__SNAP)
    
	#define Calib_GND_0_INTTYPE_REG 		(* (reg8 *) Calib_GND__0__INTTYPE)
#endif /* (Calib_GND__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Calib_GND_H */


/* [] END OF FILE */
