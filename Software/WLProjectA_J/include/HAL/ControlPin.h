/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: ControlPin.h $
 * $Revision: 1 $
 * $Author: Jorge Acevedo $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Sending or receiving signals from IO Pins.

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
/*JORGE ACEVDO         |         1          |PERIPHERIALS CONTROL FUNCTIONS   */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef CONTROLPIN_H
#define CONTROLPIN_H

/* Includes */
/*============================================================================*/
#include "MAL/GPIO.h"

/* Constants and types */
/*============================================================================*/
#define BlueLED    (T_UBYTE)PTD0
#define GreenLED   (T_UBYTE)PTD16

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void TurnONPin (S_GPIO* PTR, T_UBYTE PIN);
void TurnOffPin (S_GPIO* PTR, T_UBYTE PIN);
void TurnOnLED (T_UBYTE LED);
void TurnOffLED (T_UBYTE LED);
void TooglePORTBPin (T_UBYTE PIN);
void TooglePORTCPin (T_UBYTE PIN);
void TooglePORTDPin (T_UBYTE PIN);
void TooglePORTEPin (T_UBYTE PIN);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
