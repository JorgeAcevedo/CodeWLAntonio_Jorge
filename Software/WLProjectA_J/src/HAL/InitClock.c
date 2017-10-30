/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: InitClock.c $
 * $Revision: 1 $
 * $Author: Jorge Acevedo $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Clock initialization

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
/*Jorge Acevedo        |         1          |Send instructions to initializate clocks*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/InitClock.h"


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
void InitSOSC (void)
{
	//Init 8MHz
	cps_SCG->SOSCDIV = 0x00000101u;
	cps_SCG->SOSCCFG = 0x00000024u;
	while(cps_SCG->SOSCCSR & 0x00800000u);
	cps_SCG->SOSCCSR = 0x00000001u;
	while(!(cps_SCG->SOSCCSR & 0x01000000u));
}

void InitSPLL(void){
	//Init 160MHz
	while (cps_SCG->SPLLCSR & 0x00800000u);
	cps_SCG->SPLLCSR = 0x00000000u;
	cps_SCG->SPLLDIV = 0x00000302u;
	cps_SCG->SPLLCFG = 0x00180000u;
	while (cps_SCG->SPLLCSR & 0x00800000u);
	cps_SCG->SPLLCSR = 0x00000001u;
	while (!(cps_SCG->SPLLCSR & 0x01000000u));

}

void InitNormalRunMode(void)
{
	//Init 80MHz
	cps_SCG->RCCR = 0x06010012u;
	while ((cps_SCG->CSR & 0x0F000000u)!= 0x06000000u){}
}

void InitClock (T_UBYTE DIREC){
	cps_PCC->PCC[DIREC] |= 0x40000000u;
}






 /* Notice: the file ends with a blank new line to avoid compiler warnings */
