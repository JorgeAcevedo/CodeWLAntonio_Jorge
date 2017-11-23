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
#include "APP/WindowLifter.h"

/* Constants and types */
/*============================================================================*/
#define NO_RESPONSE_TIME 5010



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void AntiPinchfunction(T_UBYTE *lpub_PtrAntiPinchBlock, T_UBYTE *lpub_PtrLEDBarState,T_UWORD *lpuw_PtrTimeCounterAntiPinchChanges);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
