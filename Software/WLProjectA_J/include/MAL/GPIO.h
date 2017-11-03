/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO.h $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    GPIO mapping

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
/* JOSÉ ANTONIO V.T.   |          1         | GPIO mapping and definitions    */
/*----------------------------------------------------------------------------*/
/* JOSÉ ANTONIO V.T.   |          2         | Functions to read pin's values  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef GPIO_H
#define GPIO_H

/* Includes */
/*============================================================================*/
#include "TypDef.h"

/* Constants and types */
/*============================================================================*/
typedef struct {
	T_ULONG PDOR;
	T_ULONG PSOR;
	T_ULONG PCOR;
	T_ULONG PTOR;
	T_ULONG PDIR;
	T_ULONG PDDR;
	T_ULONG PIDR;
}S_GPIO;

#define GPIO_PORTA_BASE_ADDRESS      0x400FF000
#define GPIO_PORTB_BASE_ADDRESS      0x400FF040
#define GPIO_PORTC_BASE_ADDRESS      0x400FF080
#define GPIO_PORTD_BASE_ADDRESS      0x400FF0C0
#define GPIO_PORTE_BASE_ADDRESS      0x400FF100


#define cps_GPIOA           ((S_GPIO *)GPIO_PORTA_BASE_ADDRESS)
#define cps_GPIOB           ((S_GPIO *)GPIO_PORTB_BASE_ADDRESS)
#define cps_GPIOC           ((S_GPIO *)GPIO_PORTC_BASE_ADDRESS)
#define cps_GPIOD           ((S_GPIO *)GPIO_PORTD_BASE_ADDRESS)
#define cps_GPIOE           ((S_GPIO *)GPIO_PORTE_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void CfgPinOutput   (S_GPIO* PTR, T_UBYTE PIN);
void CfgPinInput (S_GPIO* cps_PTR, T_UBYTE lul_PIN);
void SetPin      (S_GPIO* PTR, T_UBYTE PIN);
void ClearPin    (S_GPIO* PTR, T_UBYTE PIN);
T_UBYTE GetPinValue (S_GPIO* PTR, T_UBYTE PIN);



#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
