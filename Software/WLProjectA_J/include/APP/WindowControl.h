/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.h $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 26/10/2017 $
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
/*  AUTHOR             |        VERSION     |  DESCRIPTION                    */
/*----------------------------------------------------------------------------*/
/*José Antonio V.T     |         1          |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef LEDON_H
#define LEDON_H

/* Includes */
/*============================================================================*/
#include "HAL/ControlPin.h"

/* Constants and types */
/*============================================================================*/
#define LED10 (T_UBYTE)10
#define LED9  (T_UBYTE)9
#define LED8  (T_UBYTE)8
#define LED7  (T_UBYTE)7
#define LED6  (T_UBYTE)6
#define LED5  (T_UBYTE)5
#define LED4  (T_UBYTE)4
#define LED3  (T_UBYTE)3
#define LED2  (T_UBYTE)2
#define LED1  (T_UBYTE)1
#define LED0  (T_UBYTE)0



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

void WindowControl (T_UBYTE LED);
void WindowClosed (void);

T_UBYTE ButtonValidation (T_UBYTE UPDOWNFILTER, T_UWORD* AUTOMANUAL);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
