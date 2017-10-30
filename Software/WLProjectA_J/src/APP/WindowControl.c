/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: WindowControl.c $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 27/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
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
#include "APP/WindowControl.h"


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

void WindowControl (T_UBYTE LED){
	switch (LED){
		case LED10:
			TogglePORTEPin (PTE9);
			break;
		case LED9:
			TogglePORTCPin (PTC7);
			break;
		case LED8:
			TogglePORTBPin (PTB17 );
			break;
		case LED7:
			TogglePORTBPin (PTB14);
			break;
		case LED6:
			TogglePORTBPin (PTB15 );
			break;
		case LED5:
			TogglePORTBPin (PTB16);
			break;
		case LED4:
			TogglePORTCPin (PTC14);
			break;
		case LED3:
			TogglePORTCPin (PTC3);
			break;
		case LED2:
			TogglePORTEPin (PTE16);
			break;
		case LED1:
			TogglePORTEPin (PTE15);
			break;

		default:
			break;

		}
}

void WindowClosed (void){
	TogglePORTEPin (PTE9);
	TogglePORTCPin (PTC7);
	TogglePORTBPin (PTB17);
	TogglePORTBPin (PTB14);
	TogglePORTBPin (PTB15);
	TogglePORTBPin (PTB16);
	TogglePORTCPin (PTC14);
	TogglePORTCPin (PTC3);
	TogglePORTEPin (PTE16);
	TogglePORTEPin (PTE15);}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
