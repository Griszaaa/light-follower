#ifndef ADC_ADC_H_
#define ADC_ADC_H_

// *** DEFNICJE STA£YCH ***
#define FRONT 2
#define FRONT_RIGHT 1
#define FRONT_LEFT 3
#define RIGHT 0
#define LEFT 4

#define KEY (1<<PD2)

// *** DEKLARACJE FUNKCJI ***
void adc_init(void);
void key_init(void);
uint8_t adc_motors_read(void);
uint8_t tab_max(uint16_t tab[], uint8_t size);
uint16_t measure(uint8_t channel);

#endif /* ADC_ADC_H_ */

