/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.x $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    mapping for the low power interrupt timer.

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
/* JOSÉ ANTONIO V.T    | 1                  |  MAPPING OF THE LPIT            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef LPIT_MAP_H
#define LPIT_MAP_H

/* Includes */
/*============================================================================*/
#include "S32K144p.h"

/* Constants and types */
/*============================================================================*/
typedef struct {
    T_ULONG VERID;                             /**< Versin ID Register, ffset: 0x0 */
    T_ULONG PARAM;                             /**< Parameter Register, ffset: 0x4 */
   T_ULONG MCR;                               /**< Mdule Cntrl Register, ffset: 0x8 */
   T_ULONG MSR;                               /**< Mdule Status Register, ffset: 0xC */
   T_ULONG MIER;                              /**< Mdule Interrupt Enable Register, ffset: 0x10 */
   T_ULONG SETTEN;                            /**< Set Timer Enable Register, ffset: 0x14 */
   T_ULONG CLRTEN;                            /**< Clear Timer Enable Register, ffset: 0x18 */
       T_UBYTE RESERVED_0[4];
  struct {                                         /* ffset: 0x20, array step: 0x10 */
     T_ULONG TVAL;                              /**< Timer Value Register, array ffset: 0x20, array step: 0x10 */
      T_ULONG CVAL;                              /**< Current Timer Value, array ffset: 0x24, array step: 0x10 */
     T_ULONG TCTRL;                             /**< Timer Cntrl Register, array ffset: 0x28, array step: 0x10 */
         T_UBYTE RESERVED_0[4];
  } TMR[4];
} S_LPIT;

#define LPIT_BASE_ADDRESS			 0x40037000u
#define cps_LPIT 					 ((S_LPIT *)LPIT_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
