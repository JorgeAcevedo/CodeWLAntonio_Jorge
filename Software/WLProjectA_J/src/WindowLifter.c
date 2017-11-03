/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: WindowLifter.c $
 * $Revision: 1 $
 * $Author: Jos� Antonio $
 * $Date: 29/10/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    main function for the window Lifter Application.
   
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
/*Jos� Antonio V.T     |         1.1        |Application Window Lifter UP     */
/*----------------------------------------------------------------------------*/
/*Jorge Acevedo        |         1.2        |Application Window Lifter DOWN   */
/*----------------------------------------------------------------------------*/
/*Merge                |         2          |Application Window Lifter INTEGRATION   */
/*----------------------------------------------------------------------------*/
/*Jorge Acevedo        |         2.1        |Minor Problems solved            */
/*----------------------------------------------------------------------------*/
/*Jos� Antonio V.T.    |         3          |Final Version                    */
/*============================================================================*/
/*Jorge Acevedo        |         4          |APP functions created & names    */
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
#include "APP/AntiPinch.h"




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

T_UWORD *lpuw_PtrTimeCounterValidation =& luw_TimeCounterValidation;
T_UWORD *lpuw_PtrTimeCounterLEDBarChange =& luw_TimeCounterLEDBarChange;
T_UBYTE *lpub_PtrLEDBarState =& lub_LEDBarState;
T_UBYTE *lpub_PtrAntiPinchBlock =& lub_AntiPinchBlock;
T_UBYTE *lpub_PtrFlagOneTouchUp =& lub_FlagOneTouchUp;
T_UBYTE *lpub_PtrFlagOneTouchDown =& lub_FlagOneTouchDown;
T_UWORD *lpuw_PtrTimeCounterAntiPinchChanges =& luw_TimeCounterAntiPinchChanges;


/* Private functions prototypes */
/*============================================================================*/
int main (void);


/* Inline functions */
/*============================================================================*/
/*void AntiPinchfunction(T_UBYTE *lpub_PtrAntiPinchBlock, T_UBYTE *lpub_PtrLEDBarState,T_UWORD *lpuw_PtrTimeCounterAntiPinchChanges){
if((*lpub_PtrAntiPinchBlock) == 1){
    			if((*lpub_PtrLEDBarState) !=0){
    				if((*lpuw_PtrTimeCounterAntiPinchChanges)==10){
    				    			    WindowControl((*lpub_PtrLEDBarState));
    				    			    (*lpub_PtrLEDBarState)--;
    				    			    (*lpuw_PtrTimeCounterAntiPinchChanges)++;}
    				 if((*lpuw_PtrTimeCounterAntiPinchChanges) >10){
    					 (*lpuw_PtrTimeCounterAntiPinchChanges)++;
    				    			    			}
    				 if((*lpuw_PtrTimeCounterAntiPinchChanges) ==410){
    					 (*lpuw_PtrTimeCounterAntiPinchChanges)=10;
    				    			    			}
    			}
    			else{
    				if((*lpuw_PtrTimeCounterAntiPinchChanges) <5010){
    					(*lpuw_PtrTimeCounterAntiPinchChanges)++;
    				}
    				else{
    					(*lpuw_PtrTimeCounterAntiPinchChanges)=0;
    					(*lpub_PtrAntiPinchBlock)=0;
    				}
    			}
    		}
}*/


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

    WindowClosed ();


    for(;;){

   while (ReadLPITTimmerFlag()){}
    	if(cps_GPIOC->PDIR & 1<<PTC13  && lub_LEDBarState == 10){luw_TimeCounterLEDBarChange=0;}
    	if(cps_GPIOC->PDIR & 1<<PTC13 && lub_LEDBarState <=9 && luw_TimeCounterValidation <10){luw_TimeCounterValidation++;}
    	if(cps_GPIOC->PDIR & 1<<PTC13 && lub_LEDBarState <=9 && luw_TimeCounterValidation >=10 && luw_TimeCounterValidation<500 && lub_AntiPinchBlock == 0){
    		lub_FlagOneTouchUp=1; luw_TimeCounterValidation++; TurnOnLED(BlueLED);
    	}
    	if(cps_GPIOC->PDIR & 1<<PTC13 && lub_LEDBarState <=9 && luw_TimeCounterValidation ==500){
    		lub_FlagOneTouchUp=0; TurnOnLED(BlueLED);
    		if(lub_AntiPinchBlock == 0){
    			if(luw_TimeCounterLEDBarChange==0){
    		lub_LEDBarState++;
    		WindowControl(lub_LEDBarState);
    			luw_TimeCounterLEDBarChange++;}
    			if(luw_TimeCounterLEDBarChange !=0 && luw_TimeCounterLEDBarChange <400){
    			luw_TimeCounterLEDBarChange++;
    			}
    			if(luw_TimeCounterLEDBarChange ==400){
    				luw_TimeCounterLEDBarChange=0;
    			}
    		}
//Antipinch

    		/*if(lub_AntiPinchBlock == 1){
    			if(lub_LEDBarState !=0){
    				if(luw_TimeCounterAntiPinchChanges==10){
    				    			    WindowControl(lub_LEDBarState);
    				    			    lub_LEDBarState--;
    				    			    luw_TimeCounterAntiPinchChanges++;}
    				 if(luw_TimeCounterAntiPinchChanges >10){
    				    			    luw_TimeCounterAntiPinchChanges++;
    				    			    			}
    				 if(luw_TimeCounterAntiPinchChanges ==410){
    				    			    luw_TimeCounterAntiPinchChanges=10;
    				    			    			}
    			}
    			else{
    				if(luw_TimeCounterAntiPinchChanges <5010){
    					luw_TimeCounterAntiPinchChanges++;
    				}
    				else{
    					luw_TimeCounterAntiPinchChanges=0;
    					lub_AntiPinchBlock=0;
    				}
    			}
    		}*/
    		AntiPinchfunction(lpub_PtrAntiPinchBlock, lpub_PtrLEDBarState, lpuw_PtrTimeCounterAntiPinchChanges);

    	}

    	if(cps_GPIOC->PDIR & 1<<PTC12  && lub_LEDBarState == 0){luw_TimeCounterLEDBarChange=0;}
    	    	if(cps_GPIOC->PDIR & 1<<PTC12 && lub_LEDBarState >=1 && luw_TimeCounterValidation <10){luw_TimeCounterValidation++;}
    	    	if(cps_GPIOC->PDIR & 1<<PTC12 && lub_LEDBarState >=1 && luw_TimeCounterValidation >=10 && luw_TimeCounterValidation<500){
    	    		lub_FlagOneTouchDown=1; luw_TimeCounterValidation++; TurnOnLED(GreenLED);
    	    	}
    	    	if(cps_GPIOC->PDIR & 1<<PTC12 && lub_LEDBarState >=1 && luw_TimeCounterValidation ==500){
    	    		lub_FlagOneTouchDown=0; TurnOnLED(GreenLED);
    	    		if(luw_TimeCounterLEDBarChange==0){
    	    			   WindowControl(lub_LEDBarState);
    	    			   lub_LEDBarState--;
    	    			    luw_TimeCounterLEDBarChange++;
    	    			    			}
    	    		if(luw_TimeCounterLEDBarChange !=0 && luw_TimeCounterLEDBarChange <400){
    	    			    luw_TimeCounterLEDBarChange++;
    	    			    			}
    	    		if(luw_TimeCounterLEDBarChange == 400){
    	    			    luw_TimeCounterLEDBarChange = 0;
    	    			    			}
    	    		else{}}


    	if((cps_GPIOC->PDIR & 1<<PTC13)==0){
    		cps_GPIOD->PSOR |= 1<<0;
    		if (0 == (cps_GPIOC->PDIR & 1<<12)){
    			cps_GPIOD->PSOR |= 1<<16;
    			luw_TimeCounterValidation = 0;
    			}}

    	if((cps_GPIOC->PDIR & 1<<PTC13)==0 && lub_FlagOneTouchUp == 1){
    		if(lub_AntiPinchBlock == 0 && 0 == (cps_GPIOC->PDIR & 1<<12)){
    			if(lub_LEDBarState !=10){
    		    			if(luw_TimeCounterLEDBarChange==0){
    		    		lub_LEDBarState++;
    		    		WindowControl(lub_LEDBarState);
    		    			luw_TimeCounterLEDBarChange++;}
    		    			if(luw_TimeCounterLEDBarChange !=0 && luw_TimeCounterLEDBarChange <400){
    		    			luw_TimeCounterLEDBarChange++;
    		    			}
    		    			if(luw_TimeCounterLEDBarChange ==400){
    		    				luw_TimeCounterLEDBarChange=0;
    		    			}}
    			if(lub_LEDBarState == 10){
    				lub_FlagOneTouchUp=0;
    			}
    		}
    		if(lub_AntiPinchBlock == 0 && cps_GPIOC->PDIR & 1<<12){
    			lub_FlagOneTouchUp = 0;
    		}
    		if(lub_AntiPinchBlock == 1){
    			lub_FlagOneTouchUp =0;
    		    			if(lub_LEDBarState !=0){
    		    				if(luw_TimeCounterAntiPinchChanges==10){
    		    				    			    WindowControl(lub_LEDBarState);
    		    				    			    lub_LEDBarState--;
    		    				    			    luw_TimeCounterAntiPinchChanges++;}
    		    				 if(luw_TimeCounterAntiPinchChanges >10){
    		    				    			    luw_TimeCounterAntiPinchChanges++;
    		    				    			    			}
    		    				 if(luw_TimeCounterAntiPinchChanges ==410){
    		    				    			    luw_TimeCounterAntiPinchChanges=10;
    		    				    			    			}
    		    			}
    		    			else{
    		    				if(luw_TimeCounterAntiPinchChanges <5010){
    		    					luw_TimeCounterAntiPinchChanges++;
    		    				}
    		    				else{
    		    					luw_TimeCounterAntiPinchChanges=0;
    		    					lub_AntiPinchBlock=0;

    		    				}
    		    			}
    		    		}
    	}

    	if((cps_GPIOC->PDIR & 1<<PTC13)==0 && lub_FlagOneTouchUp == 0 && lub_AntiPinchBlock ==1){

    			/*if(lub_LEDBarState !=0){
    	    			if(luw_TimeCounterAntiPinchChanges==10){
    	    		    		    WindowControl(lub_LEDBarState);
    	    		    		    lub_LEDBarState--;
    	    		    		    luw_TimeCounterAntiPinchChanges++;}
    	    		    	if(luw_TimeCounterAntiPinchChanges >10 && luw_TimeCounterAntiPinchChanges <410){
    	    		    		     luw_TimeCounterAntiPinchChanges++;
    	    		    		    			    			}
    	    		    	if(luw_TimeCounterAntiPinchChanges ==410){
    	    		    		    luw_TimeCounterAntiPinchChanges=10;
    	    		    		    				    			    			}
    	    		    		    			}
    	    		 else{
    	    		       if(luw_TimeCounterAntiPinchChanges <5010){
    	    		    		    luw_TimeCounterAntiPinchChanges++;
    	    		    		    				}
    	    		       else{
    	    		    		    luw_TimeCounterAntiPinchChanges=0;
    	    		    		    lub_AntiPinchBlock=0;

    	    		    		    				}

    	    		    		    			}*/
    		AntiPinchfunction(lpub_PtrAntiPinchBlock, lpub_PtrLEDBarState, lpuw_PtrTimeCounterAntiPinchChanges);
    	    	}


    	if(cps_GPIOE->PDIR & 1<<PTE0 && luw_TimeCounterAntiPinchChanges <10){luw_TimeCounterAntiPinchChanges++;}
    	if(cps_GPIOE->PDIR & 1<<PTE0 && luw_TimeCounterAntiPinchChanges ==10  && (cps_GPIOC->PDIR & 1<<PTC13 || lub_FlagOneTouchUp == 1))
    	{lub_AntiPinchBlock=1;}



    	if((cps_GPIOC->PDIR & 1<<PTC12)==0 && lub_FlagOneTouchDown == 1){
    		if(0 == (cps_GPIOC->PDIR & 1<<13)){
    		   if(lub_LEDBarState !=0){
		    			if(luw_TimeCounterLEDBarChange==0){
		    		          WindowControl(lub_LEDBarState);
		    		          lub_LEDBarState--;
		    			      luw_TimeCounterLEDBarChange++;}
		    			if(luw_TimeCounterLEDBarChange !=0 && luw_TimeCounterLEDBarChange <400){
		    			luw_TimeCounterLEDBarChange++;
		    			}
		    			if(luw_TimeCounterLEDBarChange ==400){
		    				luw_TimeCounterLEDBarChange=0;
		    			}}
			   if(lub_LEDBarState == 0){
				  lub_FlagOneTouchDown=0;
			}
		}
    	if(cps_GPIOC->PDIR & 1<<13){
    		    			lub_FlagOneTouchDown = 0;
    		    		}}
    	cps_LPIT->MSR |= 0x00000001u;
    }

return 0;
}



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
