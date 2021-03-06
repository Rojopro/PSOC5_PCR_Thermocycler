/*******************************************************************************
* File Name: IDAC_OUT.h  
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

#if !defined(CY_PINS_IDAC_OUT_H) /* Pins IDAC_OUT_H */
#define CY_PINS_IDAC_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IDAC_OUT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IDAC_OUT__PORT == 15 && ((IDAC_OUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IDAC_OUT_Write(uint8 value);
void    IDAC_OUT_SetDriveMode(uint8 mode);
uint8   IDAC_OUT_ReadDataReg(void);
uint8   IDAC_OUT_Read(void);
void    IDAC_OUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   IDAC_OUT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IDAC_OUT_SetDriveMode() function.
     *  @{
     */
        #define IDAC_OUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IDAC_OUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IDAC_OUT_DM_RES_UP          PIN_DM_RES_UP
        #define IDAC_OUT_DM_RES_DWN         PIN_DM_RES_DWN
        #define IDAC_OUT_DM_OD_LO           PIN_DM_OD_LO
        #define IDAC_OUT_DM_OD_HI           PIN_DM_OD_HI
        #define IDAC_OUT_DM_STRONG          PIN_DM_STRONG
        #define IDAC_OUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IDAC_OUT_MASK               IDAC_OUT__MASK
#define IDAC_OUT_SHIFT              IDAC_OUT__SHIFT
#define IDAC_OUT_WIDTH              1u

/* Interrupt constants */
#if defined(IDAC_OUT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IDAC_OUT_SetInterruptMode() function.
     *  @{
     */
        #define IDAC_OUT_INTR_NONE      (uint16)(0x0000u)
        #define IDAC_OUT_INTR_RISING    (uint16)(0x0001u)
        #define IDAC_OUT_INTR_FALLING   (uint16)(0x0002u)
        #define IDAC_OUT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IDAC_OUT_INTR_MASK      (0x01u) 
#endif /* (IDAC_OUT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IDAC_OUT_PS                     (* (reg8 *) IDAC_OUT__PS)
/* Data Register */
#define IDAC_OUT_DR                     (* (reg8 *) IDAC_OUT__DR)
/* Port Number */
#define IDAC_OUT_PRT_NUM                (* (reg8 *) IDAC_OUT__PRT) 
/* Connect to Analog Globals */                                                  
#define IDAC_OUT_AG                     (* (reg8 *) IDAC_OUT__AG)                       
/* Analog MUX bux enable */
#define IDAC_OUT_AMUX                   (* (reg8 *) IDAC_OUT__AMUX) 
/* Bidirectional Enable */                                                        
#define IDAC_OUT_BIE                    (* (reg8 *) IDAC_OUT__BIE)
/* Bit-mask for Aliased Register Access */
#define IDAC_OUT_BIT_MASK               (* (reg8 *) IDAC_OUT__BIT_MASK)
/* Bypass Enable */
#define IDAC_OUT_BYP                    (* (reg8 *) IDAC_OUT__BYP)
/* Port wide control signals */                                                   
#define IDAC_OUT_CTL                    (* (reg8 *) IDAC_OUT__CTL)
/* Drive Modes */
#define IDAC_OUT_DM0                    (* (reg8 *) IDAC_OUT__DM0) 
#define IDAC_OUT_DM1                    (* (reg8 *) IDAC_OUT__DM1)
#define IDAC_OUT_DM2                    (* (reg8 *) IDAC_OUT__DM2) 
/* Input Buffer Disable Override */
#define IDAC_OUT_INP_DIS                (* (reg8 *) IDAC_OUT__INP_DIS)
/* LCD Common or Segment Drive */
#define IDAC_OUT_LCD_COM_SEG            (* (reg8 *) IDAC_OUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define IDAC_OUT_LCD_EN                 (* (reg8 *) IDAC_OUT__LCD_EN)
/* Slew Rate Control */
#define IDAC_OUT_SLW                    (* (reg8 *) IDAC_OUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IDAC_OUT_PRTDSI__CAPS_SEL       (* (reg8 *) IDAC_OUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IDAC_OUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IDAC_OUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IDAC_OUT_PRTDSI__OE_SEL0        (* (reg8 *) IDAC_OUT__PRTDSI__OE_SEL0) 
#define IDAC_OUT_PRTDSI__OE_SEL1        (* (reg8 *) IDAC_OUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IDAC_OUT_PRTDSI__OUT_SEL0       (* (reg8 *) IDAC_OUT__PRTDSI__OUT_SEL0) 
#define IDAC_OUT_PRTDSI__OUT_SEL1       (* (reg8 *) IDAC_OUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IDAC_OUT_PRTDSI__SYNC_OUT       (* (reg8 *) IDAC_OUT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IDAC_OUT__SIO_CFG)
    #define IDAC_OUT_SIO_HYST_EN        (* (reg8 *) IDAC_OUT__SIO_HYST_EN)
    #define IDAC_OUT_SIO_REG_HIFREQ     (* (reg8 *) IDAC_OUT__SIO_REG_HIFREQ)
    #define IDAC_OUT_SIO_CFG            (* (reg8 *) IDAC_OUT__SIO_CFG)
    #define IDAC_OUT_SIO_DIFF           (* (reg8 *) IDAC_OUT__SIO_DIFF)
#endif /* (IDAC_OUT__SIO_CFG) */

/* Interrupt Registers */
#if defined(IDAC_OUT__INTSTAT)
    #define IDAC_OUT_INTSTAT            (* (reg8 *) IDAC_OUT__INTSTAT)
    #define IDAC_OUT_SNAP               (* (reg8 *) IDAC_OUT__SNAP)
    
	#define IDAC_OUT_0_INTTYPE_REG 		(* (reg8 *) IDAC_OUT__0__INTTYPE)
#endif /* (IDAC_OUT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IDAC_OUT_H */


/* [] END OF FILE */
