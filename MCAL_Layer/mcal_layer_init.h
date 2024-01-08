/* 
 * File:   mcal_layer_init.h
 * Author: Mohamed Osama
 *
 * Created on January 7, 2024, 4:46 PM
 */

#ifndef MCAL_LAYER_INIT_H
#define	MCAL_LAYER_INIT_H

/* Section : Includes */
#include "CCP/hal_ccp.h"
#include"Timer3/hal_timer3.h"

/* Section : Macros Declaration */


/* Section : Macro Functions Declaration */


/* Section : Data Types Declaration */
Std_ReturnType ret=E_NOT_OK;
timer3_t timer3_obj;
ccp_t ccp1_obj;

/* Section : Functions Declaration */
void Timer3_Timer_Init(void);
void CCP1_Capture_Mode_Init(void);
void CCP1_Callback_ISR(void);
void TMR3_Callback_ISR(void);
void mcal_layer_initialize(void);
#endif	/* MCAL_LAYER_INIT_H */

