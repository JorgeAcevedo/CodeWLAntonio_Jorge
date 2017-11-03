/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: ReadPin.h $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Read the PIN's value.

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
/*----------------------------------------------------------------------------*/
/*José Antonio V.T     |         2          |Functions to be called at APP level*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef READPIN_H
#define READPIN_H

/* Includes */
/*============================================================================*/
#include "MAL/GPIO.h"

/* Constants and types */
/*============================================================================*/
#define UP    (T_UBYTE)1
#define DOWN  (T_UBYTE)2
#define PINCH (T_UBYTE)3

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
T_UBYTE ButtonPress (T_UBYTE UPDOWNPINCH);
T_UBYTE ButtonNotPress (T_UBYTE UPDOWNPINCH);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
