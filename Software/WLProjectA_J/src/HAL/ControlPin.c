/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: 1 $
 * $Author: José Antonio $
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
/*José Antonio V.T     |         1          |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/ControlPin.h"


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


void TurnONPin (S_GPIO* PTR, T_UBYTE PIN){
	 SetPin (PTR, PIN);
}

void TurnOffPin (S_GPIO* PTR, T_UBYTE PIN){
	ClearPin (PTR, PIN);
}

void TurnOnLED (T_UBYTE LED){
		ClearPin  (cps_GPIOD, LED);
		}

void TurnOffLED (T_UBYTE LED){
	 SetPin (cps_GPIOD, LED);}

void TogglePORTBPin (T_UBYTE PIN){
	TogglePin (cps_GPIOB, PIN);
}

void TogglePORTCPin (T_UBYTE PIN){
	TogglePin (cps_GPIOC, PIN);
}

void TogglePORTDPin (T_UBYTE PIN){
	TogglePin (cps_GPIOD, PIN);
}

void TogglePORTEPin (T_UBYTE PIN){
	TogglePin (cps_GPIOE, PIN);
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
