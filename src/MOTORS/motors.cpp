#include <avr/io.h>
#include <util/delay.h>

#include "motors.h"
#include "../ADC/adc.h"


void motors_init(void)
{
	DDRD |= MOTOR_LEFT_1 | MOTOR_LEFT_2 | MOTOR_RIGHT_1; // wyjœciowy kierunek pinów steruj¹cych kierunkiem obrotów silników
	DDRB |= MOTOR_RIGHT_2;

	// *** USTAWIENIA PWM ***
	DDRB |= MOTOR_RIGHT_PWM | MOTOR_LEFT_PWM; // wyjœciowy kierunek pinów PWM

	// Timer1 - wyjœcia OC1A i OC1B - ustawienia logiki PWM
	PWM_LEFT_ON;
	PWM_RIGHT_ON;

	TCCR1A |= (1<<WGM10); // ustawienie trybu Fast PWM 8-bit
	TCCR1B |= (1<<WGM12);


	TCCR1B |= (1<<CS12); // preskaler = 256; czêstotliwoœæ PWM = F_CPU / preskaler / rozdzielczoœæ (w tym przypadku 8-bit) = 122 Hz

	motors_dir(1);
}

void motors_dir(uint8_t dir)
{
	if(dir)
	{
		MOTOR_LEFT_DIR_RIGHT;
		MOTOR_RIGHT_DIR_LEFT;
	}
	else
	{
		MOTOR_LEFT_DIR_LEFT;
		MOTOR_RIGHT_DIR_RIGHT;
	}
}

void motors_forward(void)
{
	MOTOR_LEFT = 255;
	MOTOR_RIGHT = 255;
}

void motors_for_left(void)
{
	MOTOR_LEFT = 150;
	MOTOR_RIGHT = 255;
}

void motors_for_right(void)
{
	MOTOR_LEFT = 255;
	MOTOR_RIGHT = 150;
}

void motors_left(void)
{
	MOTOR_LEFT = 0;
	MOTOR_RIGHT = 255;
}
void motors_right(void)
{
	MOTOR_LEFT = 255;
	MOTOR_RIGHT = 0;
}

void motors_stop(void)
{
	MOTOR_LEFT = 0;
	MOTOR_RIGHT = 0;
}

void drive(void)
{
	uint8_t dir_switch = adc_motors_read();
    switch (dir_switch)
    {
    case FRONT:
		motors_forward();
		break;
    
    case FRONT_RIGHT:
		motors_for_right();
		break;
    
    case FRONT_LEFT:
		motors_for_left();
		break;
    
    case RIGHT:
		motors_right();
		break;
    
    case LEFT:
      	motors_left();
      	break;

    default:
    	motors_stop();
      break;
    }
}
