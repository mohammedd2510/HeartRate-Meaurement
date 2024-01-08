/* 
 * File:   HeartRate_Measure.h
 * Author: Mohamed Osama
 *
 * Created on January 7, 2024, 5:01 PM
 */

#ifndef HEARTRATE_MEASURE_H
#define	HEARTRATE_MEASURE_H

/* Section : Includes */
#include"MCAL_Layer/mcal_layer_init.h"
#include"ECU_Layer/ecu_layer_init.h"


/* Section : Macros Declaration */


/* Section : Macro Functions Declaration */


/* Section : Data Types Declaration */


/* Section : Functions Declaration */

/**
 * @brief Displays a welcome message on the LCD for the Heart Rate Measurement project.
 * @param void
 * @retval None
 * 
 * This function initializes the LCD and prints a welcome message 
 * along with the project creator's name and a custom heart icon.
 */
void Welcome_Message(void); 
/**
 * @brief Initializes the heart rate measurement system.
 * @param void
 * @retval None
 * 
 * This function initializes the microcontroller abstraction layer (MCAL)
 * and the electronic control unit (ECU) layer for heart rate measurement.
 */
void HeartRate_Measure_Init(void);
/**
 * @brief Calculates the heart rate in beats per minute (BPM) based on the provided parameters.
 * 
 * @param XTAL_FREQ_MHZ     Crystal frequency in MHz
 * @param TimerPrescaler    Timer prescaler value
 * @param HeartRate_BPM     Pointer to store the calculated heart rate BPM
 * 
 * @retval None
 * 
 * This function calculates the heart rate in BPM using the crystal frequency,
 * timer prescaler, and updates the HeartRate_BPM pointer with the result.
 */
void HeartRate_Calculate(uint32 XTAL_FREQ_MHZ, uint8 TimerPrescaler, uint8* HeartRate_BPM);

/**
 * @brief Displays the heart rate on the LCD.
 * @param HeartRate_BPM   Heart rate in beats per minute (BPM)
 * @retval None
 * 
 * This function displays the heart rate (BPM) on the LCD screen
 * along with a toggling heart icon to indicate the heart rate.
 */
void HeartRate_Display(uint8 HeartRate_BPM);

/**
 * @brief Interrupt service routine for CCP1 capture event.
 * @param None
 * @retval None
 * 
 * This function handles the CCP1 capture event and performs necessary actions based on the capture flag.
 */
void CCP1_Callback_ISR(void);
/**
 * @brief Interrupt service routine for Timer 3 overflow event.
 * @param None
 * @retval None
 * 
 * This function increments the overflow count to keep track of Timer 3 overflow events.
 */
void TMR3_Callback_ISR(void);

#endif	/* HEARTRATE_MEASURE_H */

