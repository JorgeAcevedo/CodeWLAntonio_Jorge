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
/** \ReadPin.c
 * Functions to read PIN's value

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
#include "HAL/ReadPin.h"


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

T_UBYTE ButtonPress (T_UBYTE UPDOWNPINCH){
	if(UPDOWNPINCH==UP){
		return GetPinValue(cps_GPIOC,PTC13);
		}
	if(UPDOWNPINCH==DOWN){
		return GetPinValue(cps_GPIOC,PTC12);
	}
	if(UPDOWNPINCH==PINCH){
		return GetPinValue(cps_GPIOE,PTE0);
	}
}


T_UBYTE ButtonNotPress (T_UBYTE UPDOWNPINCH){
	if(UPDOWNPINCH == UP){
		return ~(GetPinValue(cps_GPIOC, PTC13));
	}
	if(UPDOWNPINCH == DOWN){
		return ~(GetPinValue(cps_GPIOC, PTC12));}
	if(UPDOWNPINCH == PINCH){
		return ~GetPinValue(cps_GPIOE, PTE0);
	}
}




 /* Notice: the file ends with a blank new line to avoid compiler warnings */
