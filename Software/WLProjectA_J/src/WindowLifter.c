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
/*  AUTHOR             |        VERSION     | DESCRIPTION                     */
/*----------------------------------------------------------------------------*/
/*José Antonio V.T     |         4.1        |Revised version                  */
/*============================================================================*/
/*Jorge Acevedo        |         4.2        |APP functions created & names    */
/*                     |                    |in functions and constants change*/
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

	luw_TimeCounterValidation =0; lub_LEDBarState = 10; luw_TimeCounterLEDBarChange = 0; lub_AntiPinchBlock = 0; lub_FlagOneTouchUp = 0; lub_FlagOneTouchDown = 0; luw_TimeCounterAntiPinchChanges = 0;
	DisableWDOG();
	InitClock (PCC_PORTB);
	InitClock (PCC_PORTC);
	InitClock (PCC_PORTD);
	InitClock (PCC_PORTE);
    InitSOSC();
	InitSPLL();
	InitNormalRunMode();
	EnableLPIT(LPIT0,1);
	InitPORTCInput  (FILTER, PTC13);
	InitPORTCInput  (FILTER, PTC12);
	InitPORTEInput  (PULLER, PTE0);

	InitPORTBOutput  (PTB14);
	InitPORTBOutput  (PTB15);
	InitPORTBOutput  (PTB16);
	InitPORTBOutput  (PTB17);
	InitPORTCOutput  (PTC3);
	InitPORTCOutput  (PTC7);
	InitPORTCOutput  (PTC14);
	InitPORTEOutput  (PTE9);
	InitPORTEOutput  (PTE15);
	InitPORTEOutput  (PTE16);
	InitPORTDOutput  (PTD0);
	InitPORTDOutput  (PTD16);

	TurnOffLED(BlueLED);
	TurnOffLED(GreenLED);



    for(;;){

   
   while (ReadLPITTimmerFlag()){}

    	if(ButtonPress(UP)  && lub_LEDBarState == 10){luw_TimeCounterLEDBarChange=0;}
    	if(ButtonPress(UP) && lub_LEDBarState <=9 && luw_TimeCounterValidation <10){luw_TimeCounterValidation++;}
    	if(ButtonPress(UP) && lub_LEDBarState <=9 && luw_TimeCounterValidation >=10 && luw_TimeCounterValidation<500 &&  lub_AntiPinchBlock == 0){
    		lub_FlagOneTouchUp=1; luw_TimeCounterValidation++; TurnOnLED(BlueLED);
    	}
    	
    	if(ButtonPress(UP) && lub_LEDBarState <=9 && luw_TimeCounterValidation == 500 &&  lub_AntiPinchBlock == 0){
            TurnOnLED(BlueLED);
    		WindowUP(lpub_PtrLEDBarState, lpuw_PtrTimeCounterLEDBarChange);
    		lub_FlagOneTouchUp=0;}
    			
    			



    			

    		if(lub_LEDBarState !=0 && luw_TimeCounterValidation == 500 &&  lub_AntiPinchBlock == 1){
                 AntiPinchfunction(lpub_PtrAntiPinchBlock, lpub_PtrLEDBarState, lpuw_PtrTimeCounterAntiPinchChanges);}

    	


    	if(ButtonPress(DOWN)  && lub_LEDBarState == 0){luw_TimeCounterLEDBarChange=0;}
    	    	if(ButtonPress(DOWN) && lub_LEDBarState >=1 && luw_TimeCounterValidation <10){luw_TimeCounterValidation++;}
    	    	if(ButtonPress(DOWN) && lub_LEDBarState >=1 && luw_TimeCounterValidation >=10 && luw_TimeCounterValidation<500){
    	    		lub_FlagOneTouchDown=1; luw_TimeCounterValidation++; TurnOnLED(GreenLED);
    	    	}
    	    	if(ButtonPress(DOWN) && lub_LED >=1 && luw_Counter ==500){
    	    		TurnOnLED(GreenLED);
    		        WindowDOWN(lpub_PtrLEDBarState, lpuw_PtrTimeCounterLEDBarChange);
    		        lub_FlagOneTouchUp=0;}
    	    	


    	if(ButtonNotPress(UP)){
    		TurnOffLED(BlueLED);
    		if (ButtonNotPress(DOWN)){
    			TurnOffLED(GreenLED);
    			luw_TimeCounterValidation = 0;
    			}}
/*
    	if (ButtonNotPress(UP) && ButtonNotPress(DOWN) && (*lpub_PtrFlagOneTouchUp) == 1 && (*lpub_PtrAntiPinchBlock) == 0 && (*lpub_PtrLEDBarState) < 10)
    	      {WindowUP(lpub_PtrLEDBarState, lpuw_PtrTimeCounterLEDBarChange);}

    	




/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
