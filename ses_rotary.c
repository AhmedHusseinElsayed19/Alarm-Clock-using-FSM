/* INCLUDES ******************************************************************/

#include "ses_rotary.h"

/* DEFINES & MACROS **********************************************************/
#define A_ROTARY_PORT    PORTB
#define A_ROTARY_PIN     5

#define B_ROTARY_PORT    PORTG
#define B_ROTARY_PIN     2

#define ROTARY_DEBOUNCE_PERIOD          5  //  30 ms, should be less than the period of the encoder pulses

#define ROTARY_LEFT     0x01
#define ROTARY_RIGHT    0x02

volatile static pTypeRotaryCallback rotaryClockwiseCallback;
volatile static pTypeRotaryCallback rotaryCounterClockwiseCallback;

/* FUNCTION DEFINITION *******************************************************/

void rotary_init()
{
     //Set pin direction
     DDR_REGISTER(A_ROTARY_PORT) &= ~(1U<<A_ROTARY_PIN);
     DDR_REGISTER(B_ROTARY_PORT) &= ~(1U<<B_ROTARY_PIN);
     //Set pull-ups to sense the grounding
     A_ROTARY_PORT |= (1U<<A_ROTARY_PIN);              
     B_ROTARY_PORT |= (1U<<B_ROTARY_PIN);
     // Timer4 used to debounce the rotary Encoder
     timer4_setCallback(rotary_checkState);
     timer4_start();
}

void rotary_setClockwiseCallback(pTypeRotaryCallback callback)
{
     rotaryClockwiseCallback = callback;  
}

void rotary_setCounterClockwiseCallback(pTypeRotaryCallback callback)
{
     rotaryCounterClockwiseCallback = callback;
}

bool rotaty_isPinAtriggered(void)
{
     // return pinA status
     return (PIN_REGISTER(A_ROTARY_PORT) & (1 << A_ROTARY_PIN));
}

bool rotaty_isPinBtriggered(void)
{
     // return pinB status
     return (PIN_REGISTER(B_ROTARY_PORT) & (1 << B_ROTARY_PIN));
}

void rotary_checkState()
 {
    // Save last check signal, to avoid multiple calls
     static bool last_pinA_signal = true;
     // if pin A status recently changed to 0"rotated", execute once
     if((rotaty_isPinAtriggered()) != last_pinA_signal && !rotaty_isPinAtriggered()) 
     {    
          // if pin B is High, CCW direction
          if (rotaty_isPinBtriggered() && rotaryClockwiseCallback != NULL)
          {
               rotaryClockwiseCallback();
          }
          else if (rotaryCounterClockwiseCallback !=NULL && !rotaty_isPinBtriggered())
          {
               rotaryCounterClockwiseCallback();
          }
     }
     // save last sensed signal of pin A
     last_pinA_signal = rotaty_isPinAtriggered(); 
 }