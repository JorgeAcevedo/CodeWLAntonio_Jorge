/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: LPIT.c $
 * $Revision: 1 $
 * $Author: Jorge Acevedo $
 * $Date: 26/Oct/17 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/**
 * Configuration of  Low Power Interrupt Timer for working at 10msec
 * when Run mode is activated
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
/*  AUTHOR           |       VERSION      |          DESCRIPTION              */
/*----------------------------------------------------------------------------*/
/*Jorge Acevedo        |        1           |Configuration LPIT0 FOR 1msec
 * 					   |					|		timer                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: LPIT.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MAL\LPIT.h"
#include "MAL\PCC.h"

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
void EnableLPITClock(void)
{
	cps_LPIT->MCR |= (1<<0);
}

void SetLPITMilisec (T_UBYTE Channel, T_UBYTE Timer){
	cps_LPIT->TMR[Channel].TVAL = 40000*Timer;
}

void EnableLPITChannel (T_UBYTE Channel){
	cps_LPIT->TMR[Channel].TCTRL |= (1<<0);
}

void DisableLPITChannel (T_UBYTE Channel){
	cps_LPIT ->TMR[Channel].TCTRL &= ~(1<<0);
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
