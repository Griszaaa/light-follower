#include <Arduino.h>

#include "ADC/adc.h"
#include "MOTORS/motors.h"

int main(void)
{
	motors_init();
	adc_init();
  DDRD |= (1<<PD4);
  PORTD |= (1<<PD4);
  motors_stop();


  uint8_t dir_switch = 5;

  while(1)
  {
    dir_switch = adc_motors_read();
    switch (dir_switch)
    {
    case 0:
      PORTD &= ~(1<<PD4);
      motors_forward();
      break;
    
    case 1:
      PORTD &= ~(1<<PD4);
      motors_for_right();
    break;
    
    case 2:
      PORTD &= ~(1<<PD4);
      motors_for_left();
      break;
    
    case 3:
      PORTD &= ~(1<<PD4);
      motors_right();
      break;
    
    case 4:
      PORTD &= ~(1<<PD4);
      motors_left();
      break;

    default:
      motors_stop();
      PORTD |= (1<<PD4);
      break;
    }
  }
}
