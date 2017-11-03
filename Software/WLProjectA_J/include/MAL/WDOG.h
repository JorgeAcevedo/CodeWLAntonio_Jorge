/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: WDOG.h $
 * $Revision: 1 $
* $Author: José Antonio  $
 * $Date: 26/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    WDOG mapping.

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
/*JOSÉ ANTONIO V.T.    |        1           |WDOG mapping and functions       */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef WDOG_H
#define WDOG_H

/* Includes */
/*============================================================================*/
#include "TypDef.h"

/* Constants and types */
/*============================================================================*/
typedef struct{
	T_ULONG CS;
	T_ULONG CNT;
	T_ULONG TOVAL;
	T_ULONG WIN;
}S_WDOG;

#define WDOG_BASE_ADDRESS    0x40052000

#define cps_WDOG             ((S_WDOG *) WDOG_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
