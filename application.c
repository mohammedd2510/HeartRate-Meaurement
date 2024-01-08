/* 
 * File:   application.c
 * Author: Mohamed Osama
 *
 * Created on August 15, 2023, 9:03 AM
 */

#include "application.h"
#include "MCAL_Layer/Timer3/hal_timer3.h"

uint8 heart_rate_bpm = ZERO_INIT;

int main() 
{
    HeartRate_Measure_Init();
    Welcome_Message();
    while(1)
    {
        HeartRate_Calculate(4,8,&heart_rate_bpm);
        HeartRate_Display(heart_rate_bpm);
       
    }
    return (EXIT_SUCCESS);
}


