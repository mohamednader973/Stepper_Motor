/*
 * Stepper_Motor.c
 *
 * Created: 9/27/2020 3:43:57 AM
 * Author : monad
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void Stepper_Motor_FUNC(unsigned char step);
int main(void)
{
	DDRD |=(1<<1)|(1<<2)|(1<<3)|(1<<4);
	/* Replace with your application code */
	while (1)
	{
		Stepper_Motor_FUNC(1);
		_delay_ms(1000);
		Stepper_Motor_FUNC(2);
		_delay_ms(1000);
		Stepper_Motor_FUNC(3);
		_delay_ms(1000);
		Stepper_Motor_FUNC(4);
		_delay_ms(1000);
	}
}
void Stepper_Motor_FUNC(unsigned char step)
{
	switch(step)
	{
		case 1:
		PORTD |=(1<<1)|(1<<2);
		PORTD &=~(1<<3)|(1<<4);
		break;
		case 2:
		PORTD |=(1<<3)|(1<<2);
		PORTD &=~(1<<1)|(1<<4);
		break;
		case 3:
		PORTD |=(1<<3)|(1<<1);
		PORTD &=~(1<<2)|(1<<4);
		break;
		case 4:
		PORTD |=(1<<3)|(1<<4);
		PORTD &=~(1<<2)|(1<<1);
		break;
	}
}
