/*******************************************************************************
* File Name: IDAC_Calib.h  
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

#if !defined(CY_PINS_IDAC_Calib_H) /* Pins IDAC_Calib_H */
#define CY_PINS_IDAC_Calib_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IDAC_Calib_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IDAC_Calib__PORT == 15 && ((IDAC_Calib__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IDAC_Calib_Write(uint8 value);
void    IDAC_Calib_SetDriveMode(uint8 mode);
uint8   IDAC_Calib_ReadDataReg(void);
uint8   IDAC_Calib_Read(void);
void    IDAC_Calib_SetInterruptMode(uint16 position, uint16 mode);
uint8   IDAC_Calib_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IDAC_Calib_SetDriveMode() function.
     *  @{
     */
        #define IDAC_Calib_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IDAC_Calib_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IDAC_Calib_DM_RES_UP          PIN_DM_RES_UP
        #define IDAC_Calib_DM_RES_DWN         PIN_DM_RES_DWN
        #define IDAC_Calib_DM_OD_LO           PIN_DM_OD_LO
        #define IDAC_Calib_DM_OD_HI           PIN_DM_OD_HI
        #define IDAC_Calib_DM_STRONG          PIN_DM_STRONG
        #define IDAC_Calib_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IDAC_Calib_MASK               IDAC_Calib__MASK
#define IDAC_Calib_SHIFT              IDAC_Calib__SHIFT
#define IDAC_Calib_WIDTH              1u

/* Interrupt constants */
#if defined(IDAC_Calib__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IDAC_Calib_SetInterruptMode() function.
     *  @{
     */
        #define IDAC_Calib_INTR_NONE      (uint16)(0x0000u)
        #define IDAC_Calib_INTR_RISING    (uint16)(0x0001u)
        #define IDAC_Calib_INTR_FALLING   (uint16)(0x0002u)
        #define IDAC_Calib_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IDAC_Calib_INTR_MASK      (0x01u) 
#endif /* (IDAC_Calib__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IDAC_Calib_PS                     (* (reg8 *) IDAC_Calib__PS)
/* Data Register */
#define IDAC_Calib_DR                     (* (reg8 *) IDAC_Calib__DR)
/* Port Number */
#define IDAC_Calib_PRT_NUM                (* (reg8 *) IDAC_Calib__PRT) 
/* Connect to Analog Globals */                                                  
#define IDAC_Calib_AG                     (* (reg8 *) IDAC_Calib__AG)                       
/* Analog MUX bux enable */
#define IDAC_Calib_AMUX                   (* (reg8 *) IDAC_Calib__AMUX) 
/* Bidirectional Enable */                                                        
#define IDAC_Calib_BIE                    (* (reg8 *) IDAC_Calib__BIE)
/* Bit-mask for Aliased Register Access */
#define IDAC_Calib_BIT_MASK               (* (reg8 *) IDAC_Calib__BIT_MASK)
/* Bypass Enable */
#define IDAC_Calib_BYP                    (* (reg8 *) IDAC_Calib__BYP)
/* Port wide control signals */                                                   
#define IDAC_Calib_CTL                    (* (reg8 *) IDAC_Calib__CTL)
/* Drive Modes */
#define IDAC_Calib_DM0                    (* (reg8 *) IDAC_Calib__DM0) 
#define IDAC_Calib_DM1                    (* (reg8 *) IDAC_Calib__DM1)
#define IDAC_Calib_DM2                    (* (reg8 *) IDAC_Calib__DM2) 
/* Input Buffer Disable Override */
#define IDAC_Calib_INP_DIS                (* (reg8 *) IDAC_Calib__INP_DIS)
/* LCD Common or Segment Drive */
#define IDAC_Calib_LCD_COM_SEG            (* (reg8 *) IDAC_Calib__LCD_COM_SEG)
/* Enable Segment LCD */
#define IDAC_Calib_LCD_EN                 (* (reg8 *) IDAC_Calib__LCD_EN)
/* Slew Rate Control */
#define IDAC_Calib_SLW                    (* (reg8 *) IDAC_Calib__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IDAC_Calib_PRTDSI__CAPS_SEL       (* (reg8 *) IDAC_Calib__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IDAC_Calib_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IDAC_Calib__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IDAC_Calib_PRTDSI__OE_SEL0        (* (reg8 *) IDAC_Calib__PRTDSI__OE_SEL0) 
#define IDAC_Calib_PRTDSI__OE_SEL1        (* (reg8 *) IDAC_Calib__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IDAC_Calib_PRTDSI__OUT_SEL0       (* (reg8 *) IDAC_Calib__PRTDSI__OUT_SEL0) 
#define IDAC_Calib_PRTDSI__OUT_SEL1       (* (reg8 *) IDAC_Calib__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IDAC_Calib_PRTDSI__SYNC_OUT       (* (reg8 *) IDAC_Calib__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IDAC_Calib__SIO_CFG)
    #define IDAC_Calib_SIO_HYST_EN        (* (reg8 *) IDAC_Calib__SIO_HYST_EN)
    #define IDAC_Calib_SIO_REG_HIFREQ     (* (reg8 *) IDAC_Calib__SIO_REG_HIFREQ)
    #define IDAC_Calib_SIO_CFG            (* (reg8 *) IDAC_Calib__SIO_CFG)
    #define IDAC_Calib_SIO_DIFF           (* (reg8 *) IDAC_Calib__SIO_DIFF)
#endif /* (IDAC_Calib__SIO_CFG) */

/* Interrupt Registers */
#if defined(IDAC_Calib__INTSTAT)
    #define IDAC_Calib_INTSTAT            (* (reg8 *) IDAC_Calib__INTSTAT)
    #define IDAC_Calib_SNAP               (* (reg8 *) IDAC_Calib__SNAP)
    
	#define IDAC_Calib_0_INTTYPE_REG 		(* (reg8 *) IDAC_Calib__0__INTTYPE)
#endif /* (IDAC_Calib__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IDAC_Calib_H */


/* [] END OF FILE */
