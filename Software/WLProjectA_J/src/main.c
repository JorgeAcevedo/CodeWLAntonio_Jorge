/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Window_Lifter.c $
 * $Revision: 1 $
 * $Author: José Antonio Vázquez $
 * $Date:  25/10/2017$
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Module to control a window.
    Multiple functions to
    control the movement of
    a window
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
/*  AUTHOR             |        VERSION     | DESCRIPTION     */
/*----------------------------------------------------------------------------*/
/* JOSÉ ANTONIO V.T.   |     1              |   MANUAL FUNCTION FOR DOWN      */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "S32K144p.h"
#include "SCG_MAP.h"
#include "LPIT_MAP.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/
void DISABLE_WDOG(){
	cps_WDOG->CNT = 0xD928C520u;
	cps_WDOG->TOVAL = 0x0000FFFFu;
	cps_WDOG->CS = 0x00002100u;
}

void PORT_init (void){

	cps_PCC->PCC_PORTB = 0x40000000u;
	cps_PCC->PCC_PORTC = 0x40000000u;
	cps_PCC->PCC_PORTD = 0x40000000u;
	cps_PCC->PCC_PORTE = 0x40000000u;

	    cps_PTB->PDDR |= 0x0003C000u;
		cps_PTC->PDDR |= 0x00004098u;
		cps_PTD->PDDR |= 0x00010001u;
		cps_PTE->PDDR |= 0x00018200u;

		cps_PORTB->PORT_PCR[14] =  0x00000100u;
		cps_PORTB->PORT_PCR[15] =  0x00000100u;
		cps_PORTB->PORT_PCR[16] =  0x00000100u;
		cps_PORTB->PORT_PCR[17] =  0x00000100u;

		cps_PORTC->PORT_PCR[3] = 0x00000100u;
		cps_PORTC->PORT_PCR[7] = 0x00000100u;
		cps_PORTC->PORT_PCR[14] = 0x00000100u;


		cps_PORTD->PORT_PCR[0] = 0x00000100u;
		cps_PORTD->PORT_PCR[16] = 0x00000100u;

		cps_PORTE->PORT_PCR[9] = 0x00000100u;
		cps_PORTE->PORT_PCR[15] = 0x00000100u;
		cps_PORTE->PORT_PCR[16] = 0x00000100u;

		cps_PORTC->PORT_PCR[12] = 0x00000110u;
		cps_PORTC->PORT_PCR[13] = 0x00000110u;

	}

//inicialización de reloj interno
void SOSC_init (void) { //8 MHz
	cps_SCG->SOSCDIV = 0x00000101u;
	cps_SCG->SOSCCFG = 0x00000024u;
	while(cps_SCG->SOSCCSR & 0x00800000u);
	cps_SCG->SOSCCSR = 0x00000001u;
	while(!(cps_SCG->SOSCCSR & 0x01000000u));
}

void SPLL_init (void){ //160MHz
	while (cps_SCG->SPLLCSR & 0x00800000u);
	cps_SCG->SPLLCSR = 0x00000000u;
	cps_SCG->SPLLDIV = 0x00000302u;
	cps_SCG->SPLLCFG = 0x00180000u;
	while (cps_SCG->SPLLCSR & 0x00800000u);
	cps_SCG->SPLLCSR = 0x00000001u;
	while (!(cps_SCG->SPLLCSR & 0x01000000u));
}

void NormalRUNmode_init (void){ //80 MHz
	cps_SCG->RCCR = 0x06010012u;
	while ((cps_SCG->CSR & 0x0F000000u)!= 0x06000000u){}
}

void LPIT0_init_10msec (void){
	cps_PCC->PCC_LPIT = 0x06000000u;
	cps_PCC->PCC_LPIT |= 0x40000000u;
	cps_LPIT->MCR = 0x00000001u;
	cps_LPIT->TMR[0].TVAL = 400000u;
	cps_LPIT->TMR[0].TCTRL = 0x00000001u;
}

/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

int main (void){
	T_ULONG lul_Counter=0u, lul_State=0u;
	DISABLE_WDOG ();
	PORT_init ();
	SOSC_init ();
	SPLL_init ();
	NormalRUNmode_init ();
	LPIT0_init_10msec ();
	cps_PTB->PSOR |= 0x0003C000;
	cps_PTC->PSOR |= 0x00004088;
	cps_PTD->PSOR |= 0x00010001;
	cps_PTE->PSOR |= 0x00018200;


	for(;;){
		while (0==(cps_LPIT->MSR & 0x00000001u)){}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter == 0u && lul_State == 0u){
			lul_Counter++;
		}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter < 50 && lul_State == 0){
			lul_Counter++;
		}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50 && lul_State >=0){
			if (lul_State <40){
				cps_PTE ->PCOR ^= (1<<9);
				lul_State++;
			}
			else {
				cps_PTE ->PCOR ^= (1<<9);
			}

			//cps_PTD ->PCOR |= 1<<0;
		}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50 && lul_State >=40){
			if (lul_State <80){
				cps_PTC->PCOR ^= 1<<7;
							lul_State++;
						}
						else {
							cps_PTC->PCOR ^= 1<<7;
						}
		}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=80){
			if (lul_State <120){
				cps_PTB->PCOR ^= 1<<17;
									lul_State++;
									}
									else {
										cps_PTB->PCOR ^= 1<<17;
									}
				}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=120){
					if (lul_State <160){
						cps_PTB->PCOR ^= 1<<14;
											lul_State++;
											}
											else {
												cps_PTB->PCOR ^= 1<<14;
											}
						}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=160){
					if (lul_State <200){
						cps_PTB->PCOR ^= 1<<15;
											lul_State++;
											}
											else {
												cps_PTB->PCOR ^= 1<<15;
											}
						}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=200){
					if (lul_State <240){
						cps_PTB->PCOR ^= 1<<16;
											lul_State++;
											}
											else {
												cps_PTB->PCOR ^= 1<<16;
											}
						}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=240){
					if (lul_State <280){
						cps_PTC->PCOR ^= 1<<14;
											lul_State++;
											}
											else {
												cps_PTC->PCOR ^= 1<<14;
											}
						}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=280){
					if (lul_State <320){
						cps_PTC->PCOR ^= 1<<3;
											lul_State++;
											}
											else {
												cps_PTC->PCOR ^= 1<<3;
											}
						}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=320){
					if (lul_State <360){
						cps_PTE->PCOR ^= 1<<16;
											lul_State++;
											}
											else {
												cps_PTE->PCOR ^= 1<<16;
											}
						}
		if (cps_PTC->PDIR & (1<<12) && lul_Counter >= 50u && lul_State >=360){
					if (lul_State <400){
						cps_PTE->PCOR ^= 1<<15;
											lul_State++;
											}
											else {
												cps_PTE->PCOR ^= 1<<15;
											}
						}
		cps_LPIT->MSR |= 0x00000001u;
	}
}
/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/
//uint8 algreqg_olp_CheckOLPAllow(uint8 ReqestedAction_u8,       /**< the requested action to be performed (e.g. unlock) */
                                //uint16 RequestedComponent_u16  /**< the mask of the doors which motors to be activated (e.g. front doors) */
                                //)
//{
	//return 0;
//}


/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
