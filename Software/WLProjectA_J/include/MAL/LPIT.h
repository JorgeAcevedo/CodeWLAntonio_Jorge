/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: LPIT.x $
 * $Revision: 1 $
 * $Author: Jorge Acevedo $
 * $Date: 26/10/17 $
 */
/*============================================================================*/
/* DESCRIPTION :
 *  Map of the Low Power Interrupt Timer                 */
/**

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
/* Jorge Acevedo       |        1           |Configuration of the LPIT       */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef LPIT_H
#define LPIT_H

/* Includes */
/*============================================================================*/
#include "MAL\typDef.h"


/* Constants and types */
/*============================================================================*/
typedef struct {
    T_ULONG VERID;
    T_ULONG PARAM;
   T_ULONG MCR;
   T_ULONG MSR;
   T_ULONG MIER;
   T_ULONG SETTEN;
   T_ULONG CLRTEN;
       T_UBYTE RESERVED_0[4];
  struct {
     T_ULONG TVAL;
      T_ULONG CVAL;
     T_ULONG TCTRL;
         T_UBYTE RESERVED_0[4];
  } TMR[4];
} S_LPIT;

#define LPIT_BASE_ADDRESS			 0x40037000u
#define cps_LPIT 					 ((S_LPIT *)LPIT_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void EnableLPITClock(void);
void SetLPITMilisec (T_UBYTE Channel, T_UBYTE Timer);
void EnableLPITChannel (T_UBYTE Channel);
void DisableLPITChannel (T_UBYTE Channel);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
