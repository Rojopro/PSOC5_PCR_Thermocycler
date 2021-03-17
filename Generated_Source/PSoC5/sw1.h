/*******************************************************************************
* File Name: sw1.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_sw1_H)
#define CY_ISR_sw1_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void sw1_Start(void);
void sw1_StartEx(cyisraddress address);
void sw1_Stop(void);

CY_ISR_PROTO(sw1_Interrupt);

void sw1_SetVector(cyisraddress address);
cyisraddress sw1_GetVector(void);

void sw1_SetPriority(uint8 priority);
uint8 sw1_GetPriority(void);

void sw1_Enable(void);
uint8 sw1_GetState(void);
void sw1_Disable(void);

void sw1_SetPending(void);
void sw1_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the sw1 ISR. */
#define sw1_INTC_VECTOR            ((reg32 *) sw1__INTC_VECT)

/* Address of the sw1 ISR priority. */
#define sw1_INTC_PRIOR             ((reg8 *) sw1__INTC_PRIOR_REG)

/* Priority of the sw1 interrupt. */
#define sw1_INTC_PRIOR_NUMBER      sw1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable sw1 interrupt. */
#define sw1_INTC_SET_EN            ((reg32 *) sw1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the sw1 interrupt. */
#define sw1_INTC_CLR_EN            ((reg32 *) sw1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the sw1 interrupt state to pending. */
#define sw1_INTC_SET_PD            ((reg32 *) sw1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the sw1 interrupt. */
#define sw1_INTC_CLR_PD            ((reg32 *) sw1__INTC_CLR_PD_REG)


#endif /* CY_ISR_sw1_H */


/* [] END OF FILE */
