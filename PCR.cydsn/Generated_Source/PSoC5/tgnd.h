/*******************************************************************************
* File Name: tgnd.h  
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

#if !defined(CY_PINS_tgnd_H) /* Pins tgnd_H */
#define CY_PINS_tgnd_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tgnd_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tgnd__PORT == 15 && ((tgnd__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tgnd_Write(uint8 value);
void    tgnd_SetDriveMode(uint8 mode);
uint8   tgnd_ReadDataReg(void);
uint8   tgnd_Read(void);
void    tgnd_SetInterruptMode(uint16 position, uint16 mode);
uint8   tgnd_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tgnd_SetDriveMode() function.
     *  @{
     */
        #define tgnd_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tgnd_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tgnd_DM_RES_UP          PIN_DM_RES_UP
        #define tgnd_DM_RES_DWN         PIN_DM_RES_DWN
        #define tgnd_DM_OD_LO           PIN_DM_OD_LO
        #define tgnd_DM_OD_HI           PIN_DM_OD_HI
        #define tgnd_DM_STRONG          PIN_DM_STRONG
        #define tgnd_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tgnd_MASK               tgnd__MASK
#define tgnd_SHIFT              tgnd__SHIFT
#define tgnd_WIDTH              1u

/* Interrupt constants */
#if defined(tgnd__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tgnd_SetInterruptMode() function.
     *  @{
     */
        #define tgnd_INTR_NONE      (uint16)(0x0000u)
        #define tgnd_INTR_RISING    (uint16)(0x0001u)
        #define tgnd_INTR_FALLING   (uint16)(0x0002u)
        #define tgnd_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tgnd_INTR_MASK      (0x01u) 
#endif /* (tgnd__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tgnd_PS                     (* (reg8 *) tgnd__PS)
/* Data Register */
#define tgnd_DR                     (* (reg8 *) tgnd__DR)
/* Port Number */
#define tgnd_PRT_NUM                (* (reg8 *) tgnd__PRT) 
/* Connect to Analog Globals */                                                  
#define tgnd_AG                     (* (reg8 *) tgnd__AG)                       
/* Analog MUX bux enable */
#define tgnd_AMUX                   (* (reg8 *) tgnd__AMUX) 
/* Bidirectional Enable */                                                        
#define tgnd_BIE                    (* (reg8 *) tgnd__BIE)
/* Bit-mask for Aliased Register Access */
#define tgnd_BIT_MASK               (* (reg8 *) tgnd__BIT_MASK)
/* Bypass Enable */
#define tgnd_BYP                    (* (reg8 *) tgnd__BYP)
/* Port wide control signals */                                                   
#define tgnd_CTL                    (* (reg8 *) tgnd__CTL)
/* Drive Modes */
#define tgnd_DM0                    (* (reg8 *) tgnd__DM0) 
#define tgnd_DM1                    (* (reg8 *) tgnd__DM1)
#define tgnd_DM2                    (* (reg8 *) tgnd__DM2) 
/* Input Buffer Disable Override */
#define tgnd_INP_DIS                (* (reg8 *) tgnd__INP_DIS)
/* LCD Common or Segment Drive */
#define tgnd_LCD_COM_SEG            (* (reg8 *) tgnd__LCD_COM_SEG)
/* Enable Segment LCD */
#define tgnd_LCD_EN                 (* (reg8 *) tgnd__LCD_EN)
/* Slew Rate Control */
#define tgnd_SLW                    (* (reg8 *) tgnd__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tgnd_PRTDSI__CAPS_SEL       (* (reg8 *) tgnd__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tgnd_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tgnd__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tgnd_PRTDSI__OE_SEL0        (* (reg8 *) tgnd__PRTDSI__OE_SEL0) 
#define tgnd_PRTDSI__OE_SEL1        (* (reg8 *) tgnd__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tgnd_PRTDSI__OUT_SEL0       (* (reg8 *) tgnd__PRTDSI__OUT_SEL0) 
#define tgnd_PRTDSI__OUT_SEL1       (* (reg8 *) tgnd__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tgnd_PRTDSI__SYNC_OUT       (* (reg8 *) tgnd__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tgnd__SIO_CFG)
    #define tgnd_SIO_HYST_EN        (* (reg8 *) tgnd__SIO_HYST_EN)
    #define tgnd_SIO_REG_HIFREQ     (* (reg8 *) tgnd__SIO_REG_HIFREQ)
    #define tgnd_SIO_CFG            (* (reg8 *) tgnd__SIO_CFG)
    #define tgnd_SIO_DIFF           (* (reg8 *) tgnd__SIO_DIFF)
#endif /* (tgnd__SIO_CFG) */

/* Interrupt Registers */
#if defined(tgnd__INTSTAT)
    #define tgnd_INTSTAT            (* (reg8 *) tgnd__INTSTAT)
    #define tgnd_SNAP               (* (reg8 *) tgnd__SNAP)
    
	#define tgnd_0_INTTYPE_REG 		(* (reg8 *) tgnd__0__INTTYPE)
#endif /* (tgnd__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tgnd_H */


/* [] END OF FILE */
