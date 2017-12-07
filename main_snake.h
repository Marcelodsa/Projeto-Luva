#ifndef __main_snake_h
#define __main_snake_h

#include<p18f4685.h>
#include<stdlib.h>

#define cima PORTAbits.RA0
#define direita PORTAbits.RA1
#define baixo PORTAbits.RA2
#define esquerda PORTAbits.RA3

typedef struct c{
	short valor,x,y;
}celula;

void AtrasarS(void); 

void ZerarS(void);

void SetarS(void);

void MostrarTelaS(void);

int Retornar_Coordenadas(int valor, int* linha, int* coluna);

void Deslocar_Corpo(int* tamanho, int direcao, int cabecax_old, int cabecay_old);

void Piscar_TelaS(void);

int Game_OverS(int* cabecax, int* cabecay, int* tamanho, int* direcao);

void Deslocar(int* cabecax, int* cabecay, int direcao,int *tamanho);

void AtrasarTela(int* cabecax, int* cabecay, int* direcao, int* tamanho,int velocidade);

void Gerar_Fruta(int* frutax, int* frutay);

int Existe_Fruta(void);

void Crescer_Cobra(int* tamanho, int direcao);

void Desenhar_Numero_1(void);

void Desenhar_Numero_2(void);

void Desenhar_Numero_3(void);

int Menu(int* velocidade);

void Snake(void);

void main_snake_game(void);

#endif