/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: WriteReadPins.h $
 * $Revision: 1 $
 * $Author: Jorge Acevedo $
 * $Date: 24/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    function prototyping for:
    Turning on the LED in bar
    Turning off the green and blue LED
    Reading the buttons
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
/* Jorge Acevedo      |         1          |  FUNCTION PROTOTYPING WRITING    */
/*                     |                    | ON LED AND READING BUTTON       */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef WRITEREADPINS_H_
#define WRITEREADPINS_H_



/* Includes */
/*============================================================================*/
#ifndef MAL_MAPING_TYPEDEF_H_
#include "MCAL\Maping_TypeDef.h"
#endif

#define LED10 (T_ULONG)10
#define LED9  (T_ULONG)9
#define LED8  (T_ULONG)8
#define LED7  (T_ULONG)7
#define LED6  (T_ULONG)6
#define LED5  (T_ULONG)5
#define LED4  (T_ULONG)4
#define LED3  (T_ULONG)3
#define LED2  (T_ULONG)2
#define LED1  (T_ULONG)1

#define BLUE_LED  (T_ULONG)11
#define GREEN_LED (T_ULONG)12

#define ButtonUp    (T_ULONG)13
#define ButtonDw    (T_ULONG)14
#define ButtonPinch (T_ULONG)15



/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
void TurnOnLed (T_ULONG);
void TurnOffLed(T_ULONG);
T_ULONG ReadButton(T_ULONG);
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */


/*


* WriteRead_Pins.h
 *
 *  Created on: 24 oct. 2017
 *      Author: Jorge Acevedo
 */

#ifndef HAL_WRITEREAD_PINS_H_
#define HAL_WRITEREAD_PINS_H_



#endif /* HAL_WRITEREAD_PINS_H_ */
