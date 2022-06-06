/*
 * Servo_motor.c
 *
 * Created: 11/30/2021 12:52:18 AM
 * Author : chandula
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void servo(unsigned char x);
int main(void)
{
	while (1)
	{
		         //ultrasonic signal (1 = -90 ),(2 = 0 ),(3 = 90 )  
		servo(1);   
	}          	
}

void servo(unsigned char x){
	DDRD |= (1<<PD5);              
	TCNT1 = 0;                     
	ICR1 = 2499;                   
	TCCR1A = (1<<WGM11)|(1<<COM1A1);       
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	
	if(x==1){
		OCR1A = 65;//if ultrasonic sensor give signal 1 servo goes to -90 digrees
		_delay_ms(1500);
	}
	if(x==2){
		OCR1A = 187;//if ultrasonic sensor give signal 2 servo goes to 0 digrees
		_delay_ms(1500);
	}
	if(x==3){
		OCR1A = 300;//if ultrasonic sensor give signal 13 servo goes to 90 digrees
		_delay_ms(1500);
	}	
}


