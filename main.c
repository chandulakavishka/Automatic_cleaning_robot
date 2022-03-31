/*
 * brushless_motor.c
 *
 * Created: 11/26/2021 5:40:32 PM
 * Author : chandula
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void brushless_run(unsigned char power,unsigned char brushless_speed);
int main(void)
{
   DDRA=0X07; 
   
    while (1) 
    {
		brushless_run(1,'h');   //power on(0) ,off(0) and speed high(h) ,low(l)
    }
}
void brushless_run(unsigned char power,unsigned char brushless_speed)
{
	
	if(power==1){
		if(brushless_speed == 'h'){
			PORTA= PORTA | (1<<0) | (1<<1) & (~(1<<2));
			_delay_ms(10);
			PORTA= PORTA | (1<<0) & (~(1<<1)) & (~(1<<2));
			_delay_ms(10);
			PORTA= PORTA | (1<<0) & (~(1<<1)) | (1<<2);
			_delay_ms(10);
			PORTA= PORTA & (~(1<<0)) & (~(1<<1)) | (1<<2);
			_delay_ms(1);
			PORTA= PORTA & (~(1<<0)) | (1<<1) | (1<<2);
			_delay_ms(1);
			PORTA= PORTA & (~(1<<0)) | (1<<1) & (~(1<<2));
			_delay_ms(1);
		
			
			}else if(brushless_speed == 'l'){
			
			PORTA= PORTA | (1<<0) | (1<<1) & (~(1<<2));
			_delay_ms(1);
			PORTA= PORTA | (1<<0) & (~(1<<1)) & (~(1<<2));
			_delay_ms(10);
			PORTA= PORTA | (1<<0) & (~(1<<1)) | (1<<2);
			_delay_ms(100);
			PORTA= PORTA & (~(1<<0)) & (~(1<<1)) | (1<<2);
			_delay_ms(1000);
			PORTA= PORTA & (~(1<<0)) | (1<<1) | (1<<2);
			_delay_ms(10000);
			PORTA= PORTA & (~(1<<0)) | (1<<1) & (~(1<<2));
			_delay_ms(10000000);
			
		}
	}
	else if(power==0){
		PORTA= PORTA & (~(1<<0));
		PORTA= PORTA & (~(1<<1));
		PORTA= PORTA & (~(1<<2));
		
		
	}
}
	

	
