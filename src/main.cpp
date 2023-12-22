#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ADC/adc.h"
#include "MOTORS/motors.h"

int main(void)
{
	motors_init();
	adc_init();
  key_init();
  sei();
  while(1)
  {
    drive();
  }
}
