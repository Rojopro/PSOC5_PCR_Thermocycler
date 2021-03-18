/*******************************************************************************
* File Name: AMux_Adc.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "AMux_Adc.h"

static uint8 AMux_Adc_lastChannel = AMux_Adc_NULL_CHANNEL;


/*******************************************************************************
* Function Name: AMux_Adc_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Adc_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < AMux_Adc_CHANNELS ; chan++)
    {
#if (AMux_Adc_MUXTYPE == AMux_Adc_MUX_SINGLE)
        AMux_Adc_Unset(chan);
#else
        AMux_Adc_CYAMUXSIDE_A_Unset(chan);
        AMux_Adc_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    AMux_Adc_lastChannel = AMux_Adc_NULL_CHANNEL;
}


#if (!AMux_Adc_ATMOSTONE)
/*******************************************************************************
* Function Name: AMux_Adc_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Adc_Select(uint8 channel) 
{
    AMux_Adc_DisconnectAll();        /* Disconnect all previous connections */
    AMux_Adc_Connect(channel);       /* Make the given selection */
    AMux_Adc_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: AMux_Adc_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Adc_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( AMux_Adc_lastChannel != AMux_Adc_NULL_CHANNEL)
    {
        AMux_Adc_Disconnect(AMux_Adc_lastChannel);
    }

    /* Make the new channel connection */
#if (AMux_Adc_MUXTYPE == AMux_Adc_MUX_SINGLE)
    AMux_Adc_Set(channel);
#else
    AMux_Adc_CYAMUXSIDE_A_Set(channel);
    AMux_Adc_CYAMUXSIDE_B_Set(channel);
#endif


    AMux_Adc_lastChannel = channel;   /* Update last channel */
}


#if (AMux_Adc_MUXTYPE == AMux_Adc_MUX_DIFF)
#if (!AMux_Adc_ATMOSTONE)
/*******************************************************************************
* Function Name: AMux_Adc_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Adc_Connect(uint8 channel) 
{
    AMux_Adc_CYAMUXSIDE_A_Set(channel);
    AMux_Adc_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: AMux_Adc_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Adc_Disconnect(uint8 channel) 
{
    AMux_Adc_CYAMUXSIDE_A_Unset(channel);
    AMux_Adc_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (AMux_Adc_ATMOSTONE)
/*******************************************************************************
* Function Name: AMux_Adc_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMux_Adc_DisconnectAll(void) 
{
    if(AMux_Adc_lastChannel != AMux_Adc_NULL_CHANNEL) 
    {
        AMux_Adc_Disconnect(AMux_Adc_lastChannel);
        AMux_Adc_lastChannel = AMux_Adc_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
