/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: InitLPIT.h $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \InitLPIT
    functions to initializate interrupt timer.

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
/*  AUTHOR             |        VERSION     |  DESCRIPTION                    */
/*----------------------------------------------------------------------------*/
/*José Antonio V.T     |         1          |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef INITLPIT_H
#define INITLPIT_H

/* Includes */
/*============================================================================*/
#include "MAL/LPIT.h"
#include "HAL/InitClock.h"

/* Constants and types */
/*============================================================================*/
#define LPIT0 (T_UBYTE)0
#define LPIT1 (T_UBYTE)1
#define LPIT2 (T_UBYTE)2
#define LPIT3 (T_UBYTE)3
/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void EnableLPIT (T_UBYTE Channel, T_UBYTE Timer);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
