/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO.c $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    GPIO mapping.

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
/* JOSÉ ANTONIO V.T.   |         1          |Development of the GPIO functions*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MAL/GPIO.h"


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
void CfgPinOutput (S_GPIO* PTR, T_UBYTE PIN){
	PTR->PDDR |= (1<<PIN);
}

void CfgPinInput (S_GPIO* cps_PTR, T_UBYTE lul_PIN){
	cps_PTR->PDDR &= ~(1<<lul_PIN);
}

void SetPin      (S_GPIO* PTR, T_UBYTE PIN){
	PTR->PSOR |= (1<<PIN);
}

void ClearPin    (S_GPIO* PTR, T_UBYTE PIN){
	PTR ->PCOR |= (1<<PIN);
}

void TogglePin (S_GPIO* PTR, T_UBYTE PIN){
	PTR->PTOR |= (1<<PIN);
}

T_UBYTE GetPinValue (S_GPIO* PTR, T_UBYTE PIN){
	if(PTR->PDIR & 1<<PIN){
		return 1;
	}
	else{
			return 0;
		}
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
