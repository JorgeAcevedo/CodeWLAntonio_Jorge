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
/*José Antonio V.T     |         1          |                                 */
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
T_UWORD luw_Counter;
T_UWORD luw_Process;
T_UBYTE lub_LED;
T_UBYTE lub_AntiPinchBloq;
T_UBYTE lub_FOTU;
T_UBYTE lub_FOTD;
T_UBYTE lub_Value;
T_UWORD luw_CounterAntiPinch;


/* Private functions prototypes */
/*============================================================================*/
int main (void);



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

int main (void){
	luw_Counter =0; lub_LED = 10; luw_Process = 0; lub_AntiPinchBloq = 0; lub_FOTU = 0; lub_FOTD = 0; luw_CounterAntiPinch=0;
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

   while (0==(cps_LPIT->MSR & 0x00000001u)){}
    	if(cps_GPIOC->PDIR & 1<<PTC13  && lub_LED == 10){luw_Process=0;}
    	if(cps_GPIOC->PDIR & 1<<PTC13 && lub_LED <=9 && luw_Counter <10){luw_Counter++;}
    	if(cps_GPIOC->PDIR & 1<<PTC13 && lub_LED <=9 && luw_Counter >=10 && luw_Counter<500 &&  lub_AntiPinchBloq == 0){
    		lub_FOTU=1; luw_Counter++; TurnOnLED(BlueLED);
    	}
    	if(cps_GPIOC->PDIR & 1<<PTC13 && lub_LED <=9 && luw_Counter ==500){
    		lub_FOTU=0; TurnOnLED(BlueLED);
    		if(lub_AntiPinchBloq == 0){
    			if(luw_Process==0){
    		lub_LED++;
    		WindowControl(lub_LED);
    			luw_Process++;}
    			if(luw_Process !=0 && luw_Process <400){
    			luw_Process++;
    			}
    			if(luw_Process ==400){
    				luw_Process=0;
    			}
    		}

    		if(lub_AntiPinchBloq == 1){
    			if(lub_LED !=0){
    				if(luw_CounterAntiPinch==10){
    				    			    WindowControl(lub_LED);
    				    			    lub_LED--;
    				    			    luw_CounterAntiPinch++;}
    				 if(luw_CounterAntiPinch >10 && luw_CounterAntiPinch <410){
    				    			    luw_CounterAntiPinch++;
    				    			    			}
    				 if(luw_CounterAntiPinch ==410){
    				    			    luw_CounterAntiPinch=10;
    				    			    			}
    			}
    			else{
    				if(luw_CounterAntiPinch <5010){
    					luw_CounterAntiPinch++;
    				}
    				else{
    					luw_CounterAntiPinch=0;
    					lub_AntiPinchBloq=0;
    				}
    			}
    		}
    	}

    	if(cps_GPIOC->PDIR & 1<<PTC12  && lub_LED == 0){luw_Process=0;}
    	    	if(cps_GPIOC->PDIR & 1<<PTC12 && lub_LED >=1 && luw_Counter <10){luw_Counter++;}
    	    	if(cps_GPIOC->PDIR & 1<<PTC12 && lub_LED >=1 && luw_Counter >=10 && luw_Counter<500){
    	    		lub_FOTD=1; luw_Counter++; TurnOnLED(GreenLED);
    	    	}
    	    	if(cps_GPIOC->PDIR & 1<<PTC12 && lub_LED >=1 && luw_Counter ==500){
    	    		lub_FOTD=0; TurnOnLED(GreenLED);
    	    		if(luw_Process==0){
    	    			   WindowControl(lub_LED);
    	    			   lub_LED--;
    	    			    luw_Process++;
    	    			    			}
    	    		if(luw_Process !=0 && luw_Process <400){
    	    			    luw_Process++;
    	    			    			}
    	    		if(luw_Process == 400){
    	    			    luw_Process = 0;
    	    			    			}
    	    		else{}}


    	if((cps_GPIOC->PDIR & 1<<PTC13)==0){
    		cps_GPIOD->PSOR |= 1<<0;
    		if (0 == (cps_GPIOC->PDIR & 1<<12)){
    			cps_GPIOD->PSOR |= 1<<16;
    			luw_Counter = 0;
    			}}

    	if((cps_GPIOC->PDIR & 1<<PTC13)==0 && lub_FOTU == 1){
    		if(lub_AntiPinchBloq == 0 && 0 == (cps_GPIOC->PDIR & 1<<12)){
    			if(lub_LED !=10){
    		    			if(luw_Process==0){
    		    		lub_LED++;
    		    		WindowControl(lub_LED);
    		    			luw_Process++;}
    		    			if(luw_Process !=0 && luw_Process <400){
    		    			luw_Process++;
    		    			}
    		    			if(luw_Process ==400){
    		    				luw_Process=0;
    		    			}}
    			if(lub_LED == 10){
    				lub_FOTU=0;
    			}
    		}
    		if(lub_AntiPinchBloq == 0 && cps_GPIOC->PDIR & 1<<12){
    			lub_FOTU = 0;
    		}
    		if(lub_AntiPinchBloq == 1){
    			lub_FOTU = 0;
    		    			if(lub_LED !=0){
    		    				if(luw_CounterAntiPinch==10){
    		    				    			    WindowControl(lub_LED);
    		    				    			    lub_LED--;
    		    				    			    luw_CounterAntiPinch++;}
    		    				 if(luw_CounterAntiPinch >10 && luw_CounterAntiPinch <410){
    		    				    			    luw_CounterAntiPinch++;
    		    				    			    			}
    		    				 if(luw_CounterAntiPinch ==410){
    		    				    			    luw_CounterAntiPinch=10;
    		    				    			    			}
    		    			}
    		    			else{
    		    				if(luw_CounterAntiPinch <5010){
    		    					luw_CounterAntiPinch++;
    		    				}
    		    				else{
    		    					luw_CounterAntiPinch=0;
    		    					lub_AntiPinchBloq=0;
    		    				}
    		    			}
    		    		}
    	}

    	if((cps_GPIOC->PDIR & 1<<PTC13)==0 && lub_FOTU == 0 && lub_AntiPinchBloq ==1){
    		if(lub_LED !=0){
    		    	if(luw_CounterAntiPinch==10){
    		    		    WindowControl(lub_LED);
    		    		    lub_LED--;
    		    		    luw_CounterAntiPinch++;}
    		    	if(luw_CounterAntiPinch >10 && luw_CounterAntiPinch <410){
    		    		     luw_CounterAntiPinch++;
    		    		    			    			}
    		    	if(luw_CounterAntiPinch ==410){
    		    		    luw_CounterAntiPinch=10;
    		    		    				    			    			}
    		    		    			}
    		 else{
    		       if(luw_CounterAntiPinch <5010){
    		    		    luw_CounterAntiPinch++;
    		    		    				}
    		       else{
    		    		    luw_CounterAntiPinch=0;
    		    		    lub_AntiPinchBloq=0;
    		    		    				}
    		    		    			}
    	}

    	if(cps_GPIOE->PDIR & 1<<PTE0 && luw_CounterAntiPinch <10){luw_CounterAntiPinch++;}
    	if(cps_GPIOE->PDIR & 1<<PTE0 && luw_CounterAntiPinch ==10 &&
    			(cps_GPIOC->PDIR & 1<<PTC13 || lub_FOTU == 1) &&
				((cps_GPIOC->PIDR & 1<<PTC12)==0) && lub_FOTD == 0)
    	{lub_AntiPinchBloq=1;}



    	if((cps_GPIOC->PDIR & 1<<PTC12)==0 && lub_FOTD == 1){
    		if(0 == (cps_GPIOC->PDIR & 1<<13)){
    		   if(lub_LED !=0){
		    			if(luw_Process==0){
		    		          WindowControl(lub_LED);
		    		          lub_LED--;
		    			      luw_Process++;}
		    			if(luw_Process !=0 && luw_Process <400){
		    			luw_Process++;
		    			}
		    			if(luw_Process ==400){
		    				luw_Process=0;
		    			}}
			   if(lub_LED == 0){
				  lub_FOTD=0;
			}
		}
    	if(cps_GPIOC->PDIR & 1<<13){
    		    			lub_FOTD = 0;
    		    		}}
    	cps_LPIT->MSR |= 0x00000001u;
    }

return 0;
}



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
