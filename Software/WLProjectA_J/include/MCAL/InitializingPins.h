/*============================================================================*/
/*!
 * $Source: InitializingPins.h $
 * $Revision: 1 $
 * $Author: JorgeAcevedo $
 * $Date: 24/Oct/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Initialization of the input/output Pins

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
/*  JORGE ACEVEDO    |         1          |CREATION OF THE INITIALIZING       */
/*                   |                    |         FUNCTION                  */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: InitializingPin.h  $
  ============================================================================*/
#ifndef MAL_INITIALIZINGPINS_H_
#define MAL_INITIALIZINGPINS_H_

/* Includes */
/*============================================================================*/
#ifndef MAL_MAPING_TYPEDEF_H_
#include "MAL\Maping_TypeDef.h"
#endif

/* Constants and types */
/*============================================================================*/

//Input Buttons
#define PTC12   12	//SW2
#define PTC13   13	//SW3
#define PTE0	0	//Physical Button

//Output LED
#define PTD0    0	//Blue LED Internal
#define PTD16   16	//Green LED Internal

#define PTE9    9
#define PTC7    7
#define PTB17   17
#define PTB14   14
#define PTB15   15
#define PTB16	16
#define PTC14   14
#define PTC3    3
#define PTE16   16
#define PTE15   15


/* Exported Variables */
/*===============================s=============================================*/


/* Exported functions prototypes */
/*============================================================================*/
void InitializingPins(void);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
