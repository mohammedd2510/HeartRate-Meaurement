#include"mcal_layer_init.h"
void mcal_layer_initialize(void)
{
    Timer3_Timer_Init();
    CCP1_Capture_Mode_Init();    
}

void CCP1_Capture_Mode_Init(void)
{
    ccp1_obj.CCP_Interrupt_Handler =CCP1_Callback_ISR;
    ccp1_obj.ccp_capt_comp_timer = CCP1_CCP2_TIMER3;
    ccp1_obj.ccp_inst =CCP1_INST;
    ccp1_obj.ccp_mode =CCP_CAPTURE_MODE_SELECTED;
    ccp1_obj.ccp_mode_variant = CCP_CAPTURE_MODE_1_RISING_EDGE;
    ccp1_obj.ccp_pin.direction=INPUT;
    ccp1_obj.ccp_pin.port=PORTC_INDEX;
    ccp1_obj.ccp_pin.pin=PIN2;
    CCP_Init(&ccp1_obj);
}
void Timer3_Timer_Init(void){
    timer3_obj.timer3_preload_value = 0;
    timer3_obj.timer3_mode = TIMER3_TIMER_MODE;
    timer3_obj.timer3_reg_wr_mode = TIMER3_RW_REG_8BIT_MODE;
    timer3_obj.prescaler_value = TIMER3_PRESCALER_DIV_BY_8;
    timer3_obj.TMR3_InterruptHandler = TMR3_Callback_ISR;
    ret=Timer3_Init(&timer3_obj);
}
