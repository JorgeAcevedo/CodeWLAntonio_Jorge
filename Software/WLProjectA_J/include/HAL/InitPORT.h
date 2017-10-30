/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: InitPORT.h $
 * $Revision: 1 $
 * $Author: José Antonio $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    PORT initialization.
    functions to initialize
    clocks, set input or output for ports

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
/*JOSÉ ANTONIO V.T.    |         1          |PORT initialization, using MCAL
 *                                          |    functions                    */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef INITPORT_H
#define INITPORT_H

/* Includes */
/*============================================================================*/
#include "MAL/PCC.h"
#include "MAL/PORTS.h"
#include "MAL/GPIO.h"

/* Constants and types */
/*============================================================================*/
#define FILTER   (T_UBYTE)0
#define PULLER (T_UBYTE)1
#define DISABLE  (T_UBYTE)2*/

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void InitPORTInput  (S_PORT* PTR1,S_GPIO* PTR, T_UBYTE PLLDWNFLTR, T_ULONG PIN);
void InitPORTOutput  (S_PORT* PTR1,S_GPIO* PTR, T_ULONG PIN);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
