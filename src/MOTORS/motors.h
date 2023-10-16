#ifndef MOTORS_MOTORS_H_
#define MOTORS_MOTORS_H_

// *** DEFNICJE STA£YCH ***
#define MOTOR_LEFT_1 (1<<PD5)
#define MOTOR_LEFT_2 (1<<PD6)

#define MOTOR_RIGHT_1 (1<<PD7)
#define MOTOR_RIGHT_2 (1<<PB0)

#define MOTOR_LEFT_DIR_LEFT PORTD &= ~MOTOR_LEFT_1; PORTD |= MOTOR_LEFT_2;
#define MOTOR_LEFT_DIR_RIGHT PORTD |= MOTOR_LEFT_1; PORTD &= ~MOTOR_LEFT_2;

#define MOTOR_RIGHT_DIR_LEFT PORTD &= ~MOTOR_RIGHT_1; PORTB |= MOTOR_RIGHT_2;
#define MOTOR_RIGHT_DIR_RIGHT PORTD |= MOTOR_RIGHT_1; PORTB &= ~MOTOR_RIGHT_2;

#define MOTOR_LEFT_PWM (1<<PB1)
#define MOTOR_RIGHT_PWM (1<<PB2)

#define PWM_LEFT_ON TCCR1A |= (1<<COM1A1); TCCR1A &= ~(1<<COM1A0);
#define PWM_RIGHT_ON TCCR1A |= (1<<COM1B1); TCCR1A &= ~(1<<COM1B0);

#define PWM_LEFT_OFF TCCR1A &= ~((1<<COM1A1) | (1<<COM1A0))
#define PWM2_RIGHT_OFF TCCR1A &= ~((1<<COM1B1) | (1<<COM1B0))

#define MOTOR_LEFT OCR1A
#define MOTOR_RIGHT OCR1B

#define DRIVE_LED (1<<PD4)

// *** DEKLARACJE FUNKCJI ***
void motors_init(void);
void motors_dir(uint8_t dir);
void motors_forward(void);
void motors_for_left(void);
void motors_for_right(void);
void motors_left(void);
void motors_right(void);
void motors_stop(void);

void drive(void);
void drive_led_on(void);
void drive_led_off(void);



#endif /* MOTORS_MOTORS_H_ */
