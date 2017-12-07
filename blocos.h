#ifndef __blocos_h
#define __blocos_h

#include<p18f4685.h>
#include "tela.h"
#include "main_tetris.h"

#define tempo_descida_forcada 5

typedef struct b{
	int x1,x2,x3,x4,y1,y2,y3,y4,orientacao;
}bloco;

//definicoes do quadrado
void Gerar_Quadrado(bloco*,int[18][8]);

int Pode_Deslocar_Baixo_Q(bloco*,int[18][8]);

void Deslocar_Baixo_Q(bloco*,int[18][8]);

int Pode_Deslocar_Esquerda_Q(bloco*,int[18][8]);

void Deslocar_Esquerda_Q(bloco*,int[18][8]);

int Pode_Deslocar_Direita_Q(bloco*,int[18][8]);

void Deslocar_Direita_Q(bloco*,int[18][8]);

int AtrasarTela_Q(bloco*,int[18][8],int);

//definicoes da linha

void Gerar_Reta(bloco*,int[18][8]);

int Pode_Deslocar_Baixo_R(bloco*,int[18][8]);

void Deslocar_Baixo_R(bloco*,int[18][8]);

int Pode_Deslocar_Esquerda_R(bloco*,int[18][8]);

void Deslocar_Esquerda_R(bloco*,int[18][8]);

int Pode_Deslocar_Direita_R(bloco*, int[18][8]);

void Deslocar_Direita_R(bloco*,int[18][8]);

int Pode_Rotacionar_R(bloco*,int[18][8]);

void Rotacionar_R(bloco*,int[18][8]);

int AtrasarTela_R(bloco*,int[18][8],int);

//definicoes do z esquerda

void Gerar_Z_Esq(bloco*,int[18][8]);

int Pode_Deslocar_Baixo_ZE(bloco*,int[18][8]);

void Deslocar_Baixo_ZE(bloco*,int[18][8]);

int Pode_Deslocar_Esquerda_ZE(bloco*,int[18][8]);

void Deslocar_Esquerda_ZE(bloco*,int[18][8]);

int Pode_Deslocar_Direita_ZE(bloco*,int[18][8]);

void Deslocar_Direita_ZE(bloco*,int[18][8]);

int Pode_Rotacionar_ZE(bloco*,int[18][8]);

void Rotacionar_ZE(bloco*,int[18][8]);

int AtrasarTela_ZE(bloco*,int[18][8],int);

//definicoes do z direita

void Gerar_Z_Dir(bloco*,int[18][8]);

int Pode_Deslocar_Baixo_ZD(bloco*,int[18][8]);

void Deslocar_Baixo_ZD(bloco*,int[18][8]);

int Pode_Deslocar_Esquerda_ZD(bloco*,int[18][8]);

void Deslocar_Esquerda_ZD(bloco*,int[18][8]);

int Pode_Deslocar_Direita_ZD(bloco*,int[18][8]);

void Deslocar_Direita_ZD(bloco*,int[18][8]);

int Pode_Rotacionar_ZD(bloco*,int[18][8]);

void Rotacionar_ZD(bloco*,int[18][8]);

int AtrasarTela_ZD(bloco*,int[18][8],int);

//definicoes do T

void Gerar_T(bloco*,int[18][8]);

int Pode_Deslocar_Baixo_T(bloco*,int[18][8]);

void Deslocar_Baixo_T(bloco*,int[18][8]);

int Pode_Deslocar_Esquerda_T(bloco*,int[18][8]);

void Deslocar_Esquerda_T(bloco*,int[18][8]);

int Pode_Deslocar_Direita_T(bloco*,int[18][8]);

void Deslocar_Direita_T(bloco*,int[18][8]);

int Pode_Rotacionar_T(bloco*,int[18][8]);

void Rotacionar_T(bloco*,int[18][8]);

int AtrasarTela_T(bloco*,int[18][8],int);

//definicoes do L esquerda

void Gerar_LE(bloco*,int[18][8]);

int Pode_Deslocar_Baixo_LE(bloco*,int[18][8]);

void Deslocar_Baixo_LE(bloco*,int[18][8]);

int Pode_Deslocar_Esquerda_LE(bloco*,int[18][8]);

void Deslocar_Esquerda_LE(bloco*,int[18][8]);

int Pode_Deslocar_Direita_LE(bloco*,int[18][8]);

void Deslocar_Direita_LE(bloco*,int[18][8]);

int Pode_Rotacionar_LE(bloco*,int[18][8]);

void Rotacionar_LE(bloco*,int[18][8]);

int AtrasarTela_LE(bloco*,int[18][8],int);

//definicoes do L direita

void Gerar_LD(bloco*,int[18][8]);

int Pode_Deslocar_Baixo_LD(bloco*,int[18][8]);

void Deslocar_Baixo_LD(bloco*,int[18][8]);

int Pode_Deslocar_Esquerda_LD(bloco*,int[18][8]);

void Deslocar_Esquerda_LD(bloco*,int[18][8]);

int Pode_Deslocar_Direita_LD(bloco*,int[18][8]);

void Deslocar_Direita_LD(bloco*,int[18][8]);

int Pode_Rotacionar_LD(bloco*,int[18][8]);

void Rotacionar_LD(bloco*,int[18][8]);

int AtrasarTela_LD(bloco*,int[18][8],int);

#endif