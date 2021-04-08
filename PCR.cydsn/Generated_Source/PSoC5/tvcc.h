/*******************************************************************************
* File Name: tvcc.h  
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

#if !defined(CY_PINS_tvcc_H) /* Pins tvcc_H */
#define CY_PINS_tvcc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tvcc_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tvcc__PORT == 15 && ((tvcc__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tvcc_Write(uint8 value);
void    tvcc_SetDriveMode(uint8 mode);
uint8   tvcc_ReadDataReg(void);
uint8   tvcc_Read(void);
void    tvcc_SetInterruptMode(uint16 position, uint16 mode);
uint8   tvcc_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tvcc_SetDriveMode() function.
     *  @{
     */
        #define tvcc_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tvcc_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tvcc_DM_RES_UP          PIN_DM_RES_UP
        #define tvcc_DM_RES_DWN         PIN_DM_RES_DWN
        #define tvcc_DM_OD_LO           PIN_DM_OD_LO
        #define tvcc_DM_OD_HI           PIN_DM_OD_HI
        #define tvcc_DM_STRONG          PIN_DM_STRONG
        #define tvcc_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tvcc_MASK               tvcc__MASK
#define tvcc_SHIFT              tvcc__SHIFT
#define tvcc_WIDTH              1u

/* Interrupt constants */
#if defined(tvcc__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tvcc_SetInterruptMode() function.
     *  @{
     */
        #define tvcc_INTR_NONE      (uint16)(0x0000u)
        #define tvcc_INTR_RISING    (uint16)(0x0001u)
        #define tvcc_INTR_FALLING   (uint16)(0x0002u)
        #define tvcc_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tvcc_INTR_MASK      (0x01u) 
#endif /* (tvcc__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tvcc_PS                     (* (reg8 *) tvcc__PS)
/* Data Register */
#define tvcc_DR                     (* (reg8 *) tvcc__DR)
/* Port Number */
#define tvcc_PRT_NUM                (* (reg8 *) tvcc__PRT) 
/* Connect to Analog Globals */                                                  
#define tvcc_AG                     (* (reg8 *) tvcc__AG)                       
/* Analog MUX bux enable */
#define tvcc_AMUX                   (* (reg8 *) tvcc__AMUX) 
/* Bidirectional Enable */                                                        
#define tvcc_BIE                    (* (reg8 *) tvcc__BIE)
/* Bit-mask for Aliased Register Access */
#define tvcc_BIT_MASK               (* (reg8 *) tvcc__BIT_MASK)
/* Bypass Enable */
#define tvcc_BYP                    (* (reg8 *) tvcc__BYP)
/* Port wide control signals */                                                   
#define tvcc_CTL                    (* (reg8 *) tvcc__CTL)
/* Drive Modes */
#define tvcc_DM0                    (* (reg8 *) tvcc__DM0) 
#define tvcc_DM1                    (* (reg8 *) tvcc__DM1)
#define tvcc_DM2                    (* (reg8 *) tvcc__DM2) 
/* Input Buffer Disable Override */
#define tvcc_INP_DIS                (* (reg8 *) tvcc__INP_DIS)
/* LCD Common or Segment Drive */
#define tvcc_LCD_COM_SEG            (* (reg8 *) tvcc__LCD_COM_SEG)
/* Enable Segment LCD */
#define tvcc_LCD_EN                 (* (reg8 *) tvcc__LCD_EN)
/* Slew Rate Control */
#define tvcc_SLW                    (* (reg8 *) tvcc__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tvcc_PRTDSI__CAPS_SEL       (* (reg8 *) tvcc__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tvcc_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tvcc__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tvcc_PRTDSI__OE_SEL0        (* (reg8 *) tvcc__PRTDSI__OE_SEL0) 
#define tvcc_PRTDSI__OE_SEL1        (* (reg8 *) tvcc__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tvcc_PRTDSI__OUT_SEL0       (* (reg8 *) tvcc__PRTDSI__OUT_SEL0) 
#define tvcc_PRTDSI__OUT_SEL1       (* (reg8 *) tvcc__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tvcc_PRTDSI__SYNC_OUT       (* (reg8 *) tvcc__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tvcc__SIO_CFG)
    #define tvcc_SIO_HYST_EN        (* (reg8 *) tvcc__SIO_HYST_EN)
    #define tvcc_SIO_REG_HIFREQ     (* (reg8 *) tvcc__SIO_REG_HIFREQ)
    #define tvcc_SIO_CFG            (* (reg8 *) tvcc__SIO_CFG)
    #define tvcc_SIO_DIFF           (* (reg8 *) tvcc__SIO_DIFF)
#endif /* (tvcc__SIO_CFG) */

/* Interrupt Registers */
#if defined(tvcc__INTSTAT)
    #define tvcc_INTSTAT            (* (reg8 *) tvcc__INTSTAT)
    #define tvcc_SNAP               (* (reg8 *) tvcc__SNAP)
    
	#define tvcc_0_INTTYPE_REG 		(* (reg8 *) tvcc__0__INTTYPE)
#endif /* (tvcc__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tvcc_H */


/* [] END OF FILE */
