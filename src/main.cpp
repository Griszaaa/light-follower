#include <Arduino.h>

#include "ADC/adc.h"
#include "MOTORS/motors.h"

int main(void)
{
	motors_init();
	adc_init();

  while(1)
  {
    drive();
  }
}
