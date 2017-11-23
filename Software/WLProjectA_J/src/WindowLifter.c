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
/*/*  AUTHOR             |        VERSION     | DESCRIPTION                     */
/*----------------------------------------------------------------------------*/
/*José Antonio V.T     |         1.1        |Application Window Lifter UP     */
/*----------------------------------------------------------------------------*/
/*Jorge Acevedo        |         1.2        |Application Window Lifter DOWN   */
/*----------------------------------------------------------------------------*/
/*Merge                |         2          |Application Window Lifter INTEGRATION   */
/*----------------------------------------------------------------------------*/
/*Jorge Acevedo        |         2.1        |Minor Problems solved            */
/*----------------------------------------------------------------------------*/
/*José Antonio V.T.    |         3          |Final Version                    */
/*----------------------------------------------------------------------------*/
/*José Antonio V.T     |         4.1        |Revised version                  */
/*============================================================================*/
/*Jorge Acevedo        |         4.2        |APP functions created & names    */
/*                     |                    |in functions and constants change*/
/*============================================================================*/
/*José Antonio         |         4.3        |Main function modified with APP  */
/*                     |                    |functions                        */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "APP/WindowLifter.h"




/* Constants and types  */
/*============================================================================*/


#define NOTPRESS         (T_UBYTE)0


/* Variables */
/*============================================================================*/
T_UWORD luw_TimeCounterValidation;
T_UWORD luw_TimeCounterLEDBarChange;
T_UBYTE lub_LEDBarState;
T_UBYTE lub_AntiPinchBlock;
T_UBYTE lub_FlagOneTouchUp;
T_UBYTE lub_FlagOneTouchDown;
T_UWORD luw_TimeCounterAntiPinchChanges;



T_UWORD *lpuw_PtrTimeCounterValidation = &luw_TimeCounterValidation;
T_UWORD *lpuw_PtrTimeCounterLEDBarChange = &luw_TimeCounterLEDBarChange;
T_UBYTE *lpub_PtrLEDBarState = &lub_LEDBarState;
T_UBYTE *lpub_PtrAntiPinchBlock = &lub_AntiPinchBlock;
T_UBYTE *lpub_PtrFlagOneTouchUp = &lub_FlagOneTouchUp;
T_UBYTE *lpub_PtrFlagOneTouchDown = &lub_FlagOneTouchDown;
T_UWORD *lpuw_PtrTimeCounterAntiPinchChanges = &luw_TimeCounterAntiPinchChanges;


/* Private functions prototypes */
/*============================================================================*/
int main (void);


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


int main (void){
	luw_TimeCounterValidation =0; lub_LEDBarState = 10; luw_TimeCounterLEDBarChange = 0;
	lub_AntiPinchBlock = 0; lub_FlagOneTouchUp = 0; lub_FlagOneTouchDown = 0;
	luw_TimeCounterAntiPinchChanges = 0;



	/*Start Conditions for the Window Lifter*/
    ModuleInitialization();
	ModuleStartConditions();

    for(;;){

   
        while (ReadLPITTimmerFlag()){}

/*DOWN functions to close the windows, to verified the button press validation and manual control*/
        if(ButtonPress(DOWN) && lub_LEDBarState == WINDOW_COMPLETELY_OPEN){luw_TimeCounterLEDBarChange= START_TIME_COUNTER;}

            	if(ButtonPress(DOWN) && lub_LEDBarState > WINDOW_COMPLETELY_OPEN && luw_TimeCounterValidation < VALIDATION_SIGNAL_TIME)
            	{luw_TimeCounterValidation++;}

        if(ButtonPress(DOWN) && lub_LEDBarState > WINDOW_COMPLETELY_OPEN && luw_TimeCounterValidation >= VALIDATION_SIGNAL_TIME
            			&& luw_TimeCounterValidation < MANUAL_FUNCTION_TIME){
            	    		lub_FlagOneTouchDown= ACTIVATED; lub_FlagOneTouchUp= DESACTIVATED; luw_TimeCounterValidation++; TurnOnLED(GreenLED);
            	    	}

        if(ButtonPress(DOWN) && lub_LEDBarState > WINDOW_COMPLETELY_OPEN && luw_TimeCounterValidation == MANUAL_FUNCTION_TIME){
            	    		TurnOnLED(GreenLED);
            		        WindowDOWN(lpub_PtrLEDBarState, lpuw_PtrTimeCounterLEDBarChange);
            		        lub_FlagOneTouchDown= DESACTIVATED;}

        if (ButtonPress(UP)==NOTPRESS && ButtonPress(DOWN)== NOTPRESS && (*lpub_PtrFlagOneTouchDown) == ACTIVATED && (*lpub_PtrLEDBarState) > WINDOW_COMPLETELY_OPEN)
            	    	      {WindowDOWN(lpub_PtrLEDBarState, lpuw_PtrTimeCounterLEDBarChange);}


/*UP functions to close the windows, to verified the button press validation and manual control*/

    	if(ButtonPress(UP)  && lub_LEDBarState == WINDOW_COMPLETELY_CLOSED){luw_TimeCounterLEDBarChange=START_TIME_COUNTER; lub_FlagOneTouchDown = DESACTIVATED;}

    	if(ButtonPress(UP) && lub_LEDBarState < WINDOW_COMPLETELY_CLOSED && luw_TimeCounterValidation < VALIDATION_SIGNAL_TIME){luw_TimeCounterValidation++;}

    	if(ButtonPress(UP) && lub_LEDBarState < WINDOW_COMPLETELY_CLOSED && luw_TimeCounterValidation >= VALIDATION_SIGNAL_TIME
    			&& luw_TimeCounterValidation < MANUAL_FUNCTION_TIME &&  lub_AntiPinchBlock == DESACTIVATED){
    		lub_FlagOneTouchUp=ACTIVATED; lub_FlagOneTouchDown = DESACTIVATED; luw_TimeCounterValidation++; TurnOnLED(BlueLED);
    	}
    	
    	if(ButtonPress(UP) && lub_LEDBarState < WINDOW_COMPLETELY_CLOSED && luw_TimeCounterValidation == MANUAL_FUNCTION_TIME &&  lub_AntiPinchBlock == DESACTIVATED){
            TurnOnLED(BlueLED);
    		WindowUP(lpub_PtrLEDBarState, lpuw_PtrTimeCounterLEDBarChange);
    		lub_FlagOneTouchUp=DESACTIVATED;}

    	if (ButtonPress(UP)==NOTPRESS && ButtonPress(DOWN) == NOTPRESS && (*lpub_PtrFlagOneTouchUp) == ACTIVATED
    	    			&& (*lpub_PtrAntiPinchBlock) == DESACTIVATED && (*lpub_PtrLEDBarState) < WINDOW_COMPLETELY_CLOSED)
    	    	      {WindowUP(lpub_PtrLEDBarState, lpuw_PtrTimeCounterLEDBarChange);}


/*AntiPinch function*/
        if(lub_AntiPinchBlock == ACTIVATED){
        	lub_FlagOneTouchUp = DESACTIVATED;
        	AntiPinchfunction(lpub_PtrAntiPinchBlock, lpub_PtrLEDBarState, lpuw_PtrTimeCounterAntiPinchChanges);}


/*AntiPinch button press validation*/
    	if(ButtonPress(PINCH) && luw_TimeCounterAntiPinchChanges < VALIDATION_SIGNAL_TIME && (ButtonPress(UP)||lub_FlagOneTouchUp == ACTIVATED))
    	{luw_TimeCounterAntiPinchChanges++;}
    	if(ButtonPress(PINCH) && luw_TimeCounterAntiPinchChanges == VALIDATION_SIGNAL_TIME && (ButtonPress(UP)||lub_FlagOneTouchUp == ACTIVATED))
    	{*lpub_PtrAntiPinchBlock = 1;}
    	    	

/*Counter reset if there is no button pressed*/
    	if(ButtonPress(UP)==NOTPRESS){
    		     TurnOffLED(BlueLED);
    	    if (ButtonPress(DOWN)==NOTPRESS){
    		     TurnOffLED(GreenLED);
    		     luw_TimeCounterValidation = START_TIME_COUNTER;
    		}}


        ResetLPITTimerFlag();}
    return 0;
}
    	




/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
