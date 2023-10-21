#include <avr/io.h>
#include <util/delay.h>

#include "adc.h"
#include "../MOTORS/motors.h"

void adc_init(void)
{
	ADMUX |= (1<<REFS0) | (1<<REFS1); // wybór Ÿród³a odnieniesia - wewnêtrzne 2,56 V
	ADCSRA |= (1<<ADEN) | (1<<	ADPS2) | (1<<ADPS1); // w³¹czenie przetwornika oraz preskaler - 64 (próbkowanie przy 10-bitach musi byæ od 50 - 200 kHz, w tym przypadku 125 kHz)
}

uint8_t adc_motors_read(void)
{
	uint16_t sensors[5] = {0,0,0,0,0};
	uint8_t dir_switch = 0;
	uint8_t emptiness = 0;

	for(uint8_t i = 0; i < 5; i++)
	{
		uint16_t meas = measure(i);
		if(meas < TRESHOLD)
		{
			sensors[i] = 0;
			emptiness++;
		}
		else sensors[i] = meas;
	}

	if(emptiness == 5)
	{
		return 5;
	}
	else
	{
		emptiness = 0;
		dir_switch = tab_max(sensors, 5);
		return dir_switch;
	}
}

uint8_t tab_max(uint16_t tab[], uint8_t size)
{
	uint8_t index_max = 0;
	for(uint8_t i = 1; i < size; i++)
	{
		if(tab[i] > tab[index_max]) index_max = i;
	}
	return index_max;
}

uint16_t measure(uint16_t channel)
{
	ADMUX = (ADMUX & 0xF8) | channel; // wybór kana³u
	ADCSRA |= (1<<ADSC); // start konwersji
	while(ADCSRA & (1<<ADSC)); // oczekiwanie na zakoñczenie pomiaru
	return ADC; // zwrócenie wyniku
}
