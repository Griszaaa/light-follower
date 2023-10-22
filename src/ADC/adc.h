#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#define FRONT 0
#define FRONT_RIGHT 1
#define FRONT_LEFT 2
#define RIGHT 3
#define LEFT 4

#define TRESHOLD 200

void adc_init(void);
uint8_t adc_motors_read(void);
uint8_t tab_max(uint16_t tab[], uint8_t size);
uint16_t measure(uint16_t channel);

#endif /* ADC_ADC_H_ */

