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

T_UBYTE ButtonUPPush (void){
	GetPinValue (cps_GPIOC,PTC13);
	if(GetPinValue (cps_GPIOC,PTC13)==1){return 1;}
	else{return 0;}
}

T_UBYTE ButtonPush (T_UBYTE UDP){
	if(UDP == UP){
		GetPinValue (cps_GPIOC, PTC13);
		if(GetPinValue (cps_GPIOC, PTC13)==1){
			return 1;
		}else{return 0;}
	}

	if(UDP == DOWN){
		GetPinValue (cps_GPIOC, PTC12);

	}
	if(UDP == PINCH){
		GetPinValue (cps_GPIOE, PTE0);

	}
}

T_UBYTE ButtonNotPush (T_UBYTE UDP){
	if(UDP == UP){
		GetPinValue (cps_GPIOC, PTC13);
		if(GetPinValue (cps_GPIOC, PTC13)==0){return 1;}
			else{return 0;}
	}
	if(UDP == DOWN){
		GetPinValue (cps_GPIOC, PTC12);
		if(GetPinValue (cps_GPIOC, PTC12)==0){return 1;}
					else{return 0;}
	}
	if(UDP == PINCH){
		GetPinValue (cps_GPIOE, PTE0);
		if(GetPinValue (cps_GPIOE, PTE0)==0){return 1;}
					else{return 0;}
	}
}

T_UBYTE ButtonUPNotPush(void){
	GetPinValue (cps_GPIOC,PTC13);
	}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
