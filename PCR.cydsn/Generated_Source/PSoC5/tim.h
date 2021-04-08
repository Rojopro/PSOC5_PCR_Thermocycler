/*******************************************************************************
* File Name: tim.h
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
#if !defined(CY_ISR_tim_H)
#define CY_ISR_tim_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void tim_Start(void);
void tim_StartEx(cyisraddress address);
void tim_Stop(void);

CY_ISR_PROTO(tim_Interrupt);

void tim_SetVector(cyisraddress address);
cyisraddress tim_GetVector(void);

void tim_SetPriority(uint8 priority);
uint8 tim_GetPriority(void);

void tim_Enable(void);
uint8 tim_GetState(void);
void tim_Disable(void);

void tim_SetPending(void);
void tim_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the tim ISR. */
#define tim_INTC_VECTOR            ((reg32 *) tim__INTC_VECT)

/* Address of the tim ISR priority. */
#define tim_INTC_PRIOR             ((reg8 *) tim__INTC_PRIOR_REG)

/* Priority of the tim interrupt. */
#define tim_INTC_PRIOR_NUMBER      tim__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable tim interrupt. */
#define tim_INTC_SET_EN            ((reg32 *) tim__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the tim interrupt. */
#define tim_INTC_CLR_EN            ((reg32 *) tim__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the tim interrupt state to pending. */
#define tim_INTC_SET_PD            ((reg32 *) tim__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the tim interrupt. */
#define tim_INTC_CLR_PD            ((reg32 *) tim__INTC_CLR_PD_REG)


#endif /* CY_ISR_tim_H */


/* [] END OF FILE */
