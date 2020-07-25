#include "alarmClock.h"
//****************Define globalvariables and function****************
void joystickPressedDispatch(void * param);
void rotaryPressedDispatch(void * param);
void add_rotaryDispatch(void);  
void add_joystickDispatch(void);
void rotaryCounterClockWiseDispatch(void * param);
void rotaryClockWiseDispatch(void * param);

Fsm theFsm;
//*********** External events triggered by external devices (i.e. Buttons and switches) ***********

// Triggered when the Rotaty button pressed
static taskDescriptor rotary_dispatcher   = {.task = rotaryPressedDispatch, .param = NULL, .period = 0, .expire=0}; 	
// Triggered when the Joystick button pressed
static taskDescriptor joystick_dispatcher = {.task = joystickPressedDispatch, .param = NULL, .period = 0, .expire=0};	
// Triggered when the Rotary encoder, rotated CW
static taskDescriptor rotary_clock_wise_dispatcher = {.task = rotaryClockWiseDispatch, .param = NULL, .period = 0, .expire=0};	
// Triggered when the Rotary encoder, rotated CCW
static taskDescriptor rotary_counter_clock_wise_dispatcher = {.task = rotaryCounterClockWiseDispatch, .param = NULL, .period = 0, .expire=0};	

 //*********** Events passed when external events trigger by the scheduler ***********

void joystickPressedDispatch(void * param)
{
     Event e = {.signal = JOYSTICK_PRESSED};
     fsm_dispatch(&theFsm, &e);
}

void rotaryPressedDispatch(void * param) 
{
     Event e = {.signal = ROTARY_PRESSED};
     fsm_dispatch(&theFsm, &e);
}

void rotaryClockWiseDispatch(void * param) 
{
     Event e = {.signal = ROTARY_PRESSED};
     fsm_dispatch(&theFsm, &e);
}

void rotaryCounterClockWiseDispatch(void * param) 
{
     Event e = {.signal = ROTARY_LEFT_PRESSED};
     fsm_dispatch(&theFsm, &e);
}

 //*********** When external devices (switches or BUttons) events added to the scheduler qeue ***********

void add_rotaryDispatch(void)
{
	scheduler_add(&rotary_dispatcher);
}

void add_joystickDispatch(void)
{
	scheduler_add(&joystick_dispatcher);
}

void add_rotaryClockWiseDispatch(void)
{
	scheduler_add(&rotary_clock_wise_dispatcher);
}

void add_rotaryCounterClockWiseDispatch(void)
{
	scheduler_add(&rotary_counter_clock_wise_dispatcher);
}

//************************Main*****************
int main(void) 
{	
	
 	// Initializating the clock require the following:  
	lcd_init();
     scheduler_init();				
     button_init(true);
     rotary_init();
	// LEDs  initialization
     led_yellowInit();
     led_greenInit();
     led_redInit();
	// Add buttons call back
     button_setJoystickButtonCallback(&add_joystickDispatch);
     button_setRotaryButtonCallback(&add_rotaryDispatch);
     rotary_setClockwiseCallback(&add_rotaryClockWiseDispatch);
     rotary_setCounterClockwiseCallback(&add_rotaryCounterClockWiseDispatch);
	//fsm  initialization
     fsm_init(&theFsm, clock_set_hours);
     sei();
     scheduler_run();
	return 0;
}