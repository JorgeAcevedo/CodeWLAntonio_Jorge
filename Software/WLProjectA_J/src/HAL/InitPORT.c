/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
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
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/InitPORT.h"


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
void InitPORTBInput  (T_UBYTE PLLDWNFLTR, T_UBYTE PIN){
	CfgPinInput (cps_GPIOB, PIN);
	if (PLLDWNFLTR == FILTER){
					FilterPin (cps_PORTB, PIN);
			}
	if (PLLDWNFLTR == PULLER){
					PullDownPin (cps_PORTB, PIN);
				}
	else{
	}
	MuxGPIOPin (cps_PORTB, PIN);
}

void InitPORTCInput  (T_UBYTE PLLDWNFLTR, T_UBYTE PIN){
	CfgPinInput (cps_GPIOC, PIN);
	if (PLLDWNFLTR == FILTER){
					FilterPin (cps_PORTC, PIN);
			}
	if (PLLDWNFLTR == PULLER){
					PullDownPin (cps_PORTC, PIN);
				}
	else{
	}
	MuxGPIOPin (cps_PORTC, PIN);
}

void InitPORTDInput  (T_UBYTE PLLDWNFLTR, T_UBYTE PIN){
	CfgPinInput (cps_GPIOD, PIN);
	if (PLLDWNFLTR == FILTER){
					FilterPin (cps_PORTD, PIN);
			}
	if (PLLDWNFLTR == PULLER){
					PullDownPin (cps_PORTD, PIN);
				}
	else{
	}
	MuxGPIOPin (cps_PORTD, PIN);
}

void InitPORTEInput  (T_UBYTE PLLDWNFLTR, T_UBYTE PIN){
	CfgPinInput (cps_GPIOE, PIN);
	if (PLLDWNFLTR == FILTER){
					FilterPin (cps_PORTE, PIN);
			}
	if (PLLDWNFLTR == PULLER){
					PullDownPin (cps_PORTE, PIN);
				}
	else{
	}
	MuxGPIOPin (cps_PORTE, PIN);
}

void InitPORTBOutput  (T_UBYTE PIN){
	CfgPinOutput (cps_GPIOB, PIN);
	MuxGPIOPin (cps_PORTB, PIN);
}

void InitPORTCOutput  (T_UBYTE PIN){
	CfgPinOutput (cps_GPIOC, PIN);
	MuxGPIOPin (cps_PORTC, PIN);
}

void InitPORTDOutput  (T_UBYTE PIN){
	CfgPinOutput (cps_GPIOD, PIN);
	MuxGPIOPin (cps_PORTD, PIN);
}

void InitPORTEOutput  (T_UBYTE PIN){
	CfgPinOutput (cps_GPIOE, PIN);
	MuxGPIOPin (cps_PORTE, PIN);
}




 /* Notice: the file ends with a blank new line to avoid compiler warnings */
