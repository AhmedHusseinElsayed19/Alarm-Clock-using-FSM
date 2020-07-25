#ifndef ALARMCLOCK_H_
#define ALARMCLOCK_H__

/*INCLUDES *******************************************************************/
#include "ses_common.h"
#include <avr/io.h>
#include <util/delay.h>
#include "ses_uart.h"
#include "ses_lcd.h"
#include "ses_led.h"

/**
 * Prepare function pointer for buttons Interrupt
*/
typedef void (*pTypeRotaryCallback)();

/* FUNCTION PROTOTYPES *******************************************************/

/*
* Enable Encoder's buttons and timer 4 for decouncing and direction detection
*/
void rotary_init();

/**
* set clock wise direction call back
*@param  callback is a function pointer dedicated with the clock wise rotation
*/
void rotary_setClockwiseCallback(pTypeRotaryCallback callback);

/**
* set counter clock wise direction call back
*@param  callback is a function pointer dedicated with the counter clock wise rotation
*/
void rotary_setCounterClockwiseCallback(pTypeRotaryCallback callback);

/**
*  Return the current signal of the pin A 
*/
bool rotaty_isPinAtriggered(void);

/**
* Return the current signal of the pin B 
*/
bool rotaty_isPinBtriggered(void);

/*
* Check the sequence of Rotray's input signal and decided the direction of rotation. 
*/
void rotary_checkState();

#endif /* ALARMCLOCK_H_ */