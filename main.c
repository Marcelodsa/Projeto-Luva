#include"main_tetris.h"
#include "main_snake.h"

#pragma config OSC = IRCIO67
#pragma config  WDT = OFF, MCLRE = OFF         
#pragma config DEBUG = ON, LVP = OFF, PWRT = ON  

void Configurar_PIC(void){
	OSCCON = 0x70;
	ADCON1 = 0x0F;
	TRISB = 0b00000000;
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	TRISAbits.TRISA0 = 1;
	TRISAbits.TRISA1 = 1;
	TRISAbits.TRISA2 = 1;
	TRISAbits.TRISA3 = 1;
	TRISEbits.TRISE0 = 0;
	TRISEbits.TRISE1 = 0;
	TRISEbits.TRISE2 = 0;
}

void main(void){
	int i;
	short op = 1;
	Configurar_PIC();
	while(1){
		if(PORTAbits.RA3){
			for(i = 0; i < 600; i++){}
			op--;
			if(op < 1){
				op = 2;
			}
			
		}
		if(PORTAbits.RA1){
			for(i = 0; i < 600; i++){}
			op++;
			if(op > 2){
				op = 1;
			}
		}
		if(op == 1){
			Tetris();
		}
		else{
			Snake();
		}
		if(PORTAbits.RA2){
			for(i = 0; i < 10000; i++){}
			if(op == 1){
				mainGame();
			}
			else{
				main_snake_game();
			}
		}
	}
}