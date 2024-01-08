#include"HeartRate_Measure.h"

/* Static Global Variables Declarations */
volatile static uint32 Cap;
volatile static uint8  ovf_cnt;
volatile static uint8 cap_flag;
static uint8 Full_Heart_Custom_Char[]={0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04,0x00,0x00,  };
static uint8 Hollow_Heart_Custom_Char[]={0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00,0x00 };

/*******************************************************/

/*      Functions Definitions       */

/**
 * @brief Displays a welcome message on the LCD for the Heart Rate Measurement project.
 * @param void
 * @retval None
 * 
 * This function initializes the LCD and prints a welcome message 
 * along with the project creator's name and a custom heart icon.
 */
void Welcome_Message(void) {
    lcd_4bit_send_string_pos(&lcd1, 1, 1, "Heart Rate Measurement");
    __delay_ms(300);
    lcd_4bit_send_string_pos(&lcd1, 2, 1, "  Project Made by");
    __delay_ms(300);
    lcd_4bit_send_string_pos(&lcd1, 3, 1, "   Mohamed Osama");
    __delay_ms(300);
    lcd_4bit_send_custom_char(&lcd1, 4, 10, Hollow_Heart_Custom_Char, 0);
    __delay_ms(1300);
    lcd_4bit_send_command(&lcd1, _LCD_CLEAR);
}
/**
 * @brief Initializes the heart rate measurement system.
 * @param void
 * @retval None
 * 
 * This function initializes the microcontroller abstraction layer (MCAL)
 * and the electronic control unit (ECU) layer for heart rate measurement.
 */
void HeartRate_Measure_Init(void) {
    mcal_layer_initialize();
    ecu_layer_initialize();
}

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
void HeartRate_Calculate(uint32 XTAL_FREQ_MHZ, uint8 TimerPrescaler, uint8* HeartRate_BPM) {
    double beats_Time_Seconds = 0;
    uint8 BPM = 0;
    if (cap_flag == 2) {
        beats_Time_Seconds = ((double)(TimerPrescaler * Cap * 4.0)) / ((double)(XTAL_FREQ_MHZ * 1000000.0));
        BPM = 60.0 / beats_Time_Seconds;
        *HeartRate_BPM = BPM;
        cap_flag = 0;
    }
}

/**
 * @brief Displays the heart rate on the LCD.
 * @param HeartRate_BPM   Heart rate in beats per minute (BPM)
 * @retval None
 * 
 * This function displays the heart rate (BPM) on the LCD screen
 * along with a toggling heart icon to indicate the heart rate.
 */
void HeartRate_Display(uint8 HeartRate_BPM) {
    static uint8 flag = 0;
    uint8 BPM_Str[4] = {0};
    lcd_4bit_send_string_pos(&lcd1, 1, 1, " BPM = ");
    convert_uint8_to_string(HeartRate_BPM, BPM_Str);
    lcd_4bit_send_string(&lcd1, BPM_Str);
    if (flag == 0) {
        lcd_4bit_send_custom_char(&lcd1, 1, 11, Hollow_Heart_Custom_Char, 0);
        flag = 1;
        __delay_ms(100);
    } else if (flag == 1) {
        lcd_4bit_send_custom_char(&lcd1, 1, 11, Full_Heart_Custom_Char, 0);
        flag = 0;
        __delay_ms(100);
    }
}

/**
 * @brief Interrupt service routine for CCP1 capture event.
 * @param None
 * @retval None
 * 
 * This function handles the CCP1 capture event and performs necessary actions based on the capture flag.
 */
void CCP1_Callback_ISR(void) {
    if (cap_flag == 0) {
        cap_flag = 1;
        Timer3_Write_Value(&timer3_obj, 0);
        ovf_cnt = 0;
    } else if (cap_flag == 1) {
        Cap = 0;
        cap_flag = 2;
        CCP_Capture_Mode_Read_Value(&ccp1_obj, &Cap);
        Timer3_Write_Value(&timer3_obj, 0);
        Cap += (ovf_cnt * 65536);
        ovf_cnt = 0;
    }
}
/**
 * @brief Interrupt service routine for Timer 3 overflow event.
 * @param None
 * @retval None
 * 
 * This function increments the overflow count to keep track of Timer 3 overflow events.
 */
void TMR3_Callback_ISR(void) {
    ovf_cnt++;
}
/******************************************************/