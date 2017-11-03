/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: AntiPinch.c $
 * $Revision: version 1$
 * $Author: Jorge Acevedo $
 * $Date: 02/11/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Contains the AntiPinch functionality of the window lifter module.
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
/*Jorge Acevedo        |         1          |AntiPinch functionality developed*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: AntiPinch.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP\AntiPinch.h"


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
void AntiPinchfunction(T_UBYTE *lpub_PtrAntiPinchBlock, T_UBYTE *lpub_PtrLEDBarState,T_UWORD *lpuw_PtrTimeCounterAntiPinchChanges){
if((*lpub_PtrAntiPinchBlock) == ANTIPINCH_ACTIVATED){
    			if((*lpub_PtrLEDBarState) !=WINDOW_COMPLETELY_OPEN){
    				if((*lpuw_PtrTimeCounterAntiPinchChanges)==VALIDATION_SIGNAL_TIME){
    				    			    WindowControl((*lpub_PtrLEDBarState));
    				    			    (*lpub_PtrLEDBarState)--;
    				    			    (*lpuw_PtrTimeCounterAntiPinchChanges)++;}
    				 if((*lpuw_PtrTimeCounterAntiPinchChanges) >VALIDATION_SIGNAL_TIME){
    					 (*lpuw_PtrTimeCounterAntiPinchChanges)++;
    				    			    			}
    				 if((*lpuw_PtrTimeCounterAntiPinchChanges) ==CHANGE_WINDOW_STATE_TIME){
    					 (*lpuw_PtrTimeCounterAntiPinchChanges)=VALIDATION_SIGNAL_TIME;
    				    			    			}
    			}
    			else{
    				if((*lpuw_PtrTimeCounterAntiPinchChanges) <NO_RESPONSE_TIME){
    					(*lpuw_PtrTimeCounterAntiPinchChanges)++;
    				}
    				else{
    					(*lpuw_PtrTimeCounterAntiPinchChanges)=REESTART_TIME_COUNTER;
    					(*lpub_PtrAntiPinchBlock)=ANTIPINCH_DESACTIVATED;
    				}
    			}
    		}
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
