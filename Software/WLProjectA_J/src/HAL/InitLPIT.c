/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: InitLPIT.c $
 * $Revision: 1 $
 * $Author: Jorge Acevedo $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Sending or receiving signals from IO Pins..

*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  AUTHOR             |        VERSION     | DESCRIPTION                     */
/*----------------------------------------------------------------------------*/
/*Jorge Acevedo        |         1          |startting Low Power Timer Interrupt*/
/*----------------------------------------------------------------------------*/
/*Jorge Acevedo        |         2          | LPIT read interrupt flag        */
/*============================================================================*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/InitLPIT.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/




/* Exported functions */
/*============================================================================*/
void EnableLPIT (T_UBYTE Channel, T_UBYTE Timer){
	    cps_PCC->PCC[PCC_LPIT] = 0x06000000u;
	    InitClock (PCC_LPIT);
		EnableLPITClock();
		SetLPITMilisec (Channel, Timer);
		EnableLPITChannel (Channel);
}

T_UBYTE ReadLPITTimmerFlag(){
	T_UBYTE lub_FlagState= (T_UBYTE)0;

	if(0==(cps_LPIT->MSR & 0x00000001u)){
		lub_FlagState= (T_UBYTE)1;
	}
	return lub_FlagState;
}



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
