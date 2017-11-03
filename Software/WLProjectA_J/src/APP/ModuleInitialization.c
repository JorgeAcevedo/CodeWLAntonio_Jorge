/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: AntiPinch.c $
 * $Revision: version 1$
 * $Author: Jorge Acevedo $
 * $Date: 02/11/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Contains the AntiPinch functionality of the window lifter module.
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
/*Jorge Acevedo        |         1          |AntiPinch functionality developed*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: AntiPinch.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\ModuleInitialization.h"


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
void ModuleInitialization(void){

	    DisableWDOG();
		InitClock (PCC_PORTB);
		InitClock (PCC_PORTC);
		InitClock (PCC_PORTD);
		InitClock (PCC_PORTE);
	    InitSOSC();
		InitSPLL();
		InitNormalRunMode();
		EnableLPIT(LPIT0,1);
		InitPORTCInput  (FILTER, PTC13);
		InitPORTCInput  (FILTER, PTC12);
		InitPORTEInput  (PULLER, PTE0);

		InitPORTBOutput  (PTB14);
		InitPORTBOutput  (PTB15);
		InitPORTBOutput  (PTB16);
		InitPORTBOutput  (PTB17);
		InitPORTCOutput  (PTC3);
		InitPORTCOutput  (PTC7);
		InitPORTCOutput  (PTC14);
		InitPORTEOutput  (PTE9);
		InitPORTEOutput  (PTE15);
		InitPORTEOutput  (PTE16);
		InitPORTDOutput  (PTD0);
		InitPORTDOutput  (PTD16);
}



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
