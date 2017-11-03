/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
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
/*  AUTHOR             |        VERSION     | DESCRIPTION                     */
/*----------------------------------------------------------------------------*/
/*José Antonio V.T     |         1          |Function to OneTouch functionality*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include <APP/WindowUp.h>


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/




/* Exported functions */
/*============================================================================*/
void WindowDOWN (T_UBYTE* lpub_PtrLEDBarState, T_UWORD* lpuw_PtrTimeCounterLEDBarChange){
	if((*lpuw_PtrTimeCounterLEDBarChange)==0){
	    		    		WindowControl((*lpub_PtrLEDBarState));
	    		    		(*lpub_PtrLEDBarState)--;
	    		    		(*lpuw_PtrTimeCounterLEDBarChange)++;}
	if((*lpuw_PtrTimeCounterLEDBarChange) !=0 && (*lpuw_PtrTimeCounterLEDBarChange) <400){
	    		    		(*lpuw_PtrTimeCounterLEDBarChange)++;
	    		    			}
	if((*lpuw_PtrTimeCounterLEDBarChange) ==400){
	    		    		(*lpuw_PtrTimeCounterLEDBarChange)=0;
	    		    			}}







 /* Notice: the file ends with a blank new line to avoid compiler warnings */
