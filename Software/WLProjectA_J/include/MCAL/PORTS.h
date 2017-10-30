/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: PORTS.h $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    PORT's configuration.

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
/*JOSÉ ANTONIO V.T.    |           1        |PORTS cfg management and mapping */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef PORTS_H
#define PORTS_H

/* Includes */
/*============================================================================*/
#include "TypDef.h"

/* Constants and types */
/*============================================================================*/
typedef struct{
  T_ULONG PCR[32];
  T_ULONG GPCLR;
  T_ULONG GPCHR;
  T_ULONG GICLR;
  T_ULONG GICHR;
  T_ULONG ISFR;
  T_ULONG DFER;
  T_ULONG DFCR;
  T_ULONG DFWR;
}S_PORT;

#define PORTA_BASE_ADDRESS         0x40049000
#define PORTB_BASE_ADDRESS         0x4004A000
#define PORTC_BASE_ADDRESS         0x4004B000
#define PORTD_BASE_ADDRESS         0x4004C000
#define PORTE_BASE_ADDRESS         0x4004D000

#define cps_PORTA         ((S_PORT *)PORTA_BASE_ADDRESS)
#define cps_PORTB         ((S_PORT *)PORTB_BASE_ADDRESS)
#define cps_PORTC         ((S_PORT *)PORTC_BASE_ADDRESS)
#define cps_PORTD         ((S_PORT *)PORTD_BASE_ADDRESS)
#define cps_PORTE         ((S_PORT *)PORTE_BASE_ADDRESS)


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

void MuxGPIOPin (S_PORT* PTR, T_UBYTE PIN);
void FilterPin  (S_PORT* PTR, T_UBYTE PIN);
void PullDownPin (S_PORT* PTR, T_UBYTE PIN);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
