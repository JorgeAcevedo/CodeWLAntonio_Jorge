/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: AntiPinch.h $
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
/* Jorge Acevedo     |         1          |AntiPinch function added         */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: AntiPinch.h  $
  ============================================================================*/
#ifndef ANTIPINCH_H
#define ANTIPINCH_H

/* Includes */
/*============================================================================*/
#include "MAL\TypDef.h"

/* Constants and types */
/*============================================================================*/
#define ANTIPINCH_ACTIVATED 1
#define ANTIPINCH_DESACTIVATED 0
#define WINDOW_COMPLETELY_OPEN 0
#define VALIDATION_SIGNAL_TIME 10
#define CHANGE_WINDOW_STATE_TIME 410
#define NO_RESPONSE_TIME 5010
#define REESTART_TIME_COUNTER 0


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void AntiPinchfunction(T_UBYTE *lpub_PtrAntiPinchBlock, T_UBYTE *lpub_PtrLEDBarState,T_UWORD *lpuw_PtrTimeCounterAntiPinchChanges);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
