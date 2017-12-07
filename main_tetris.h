#ifndef __main_tetris_h
#define __main_tetris_h

#include<p18f4685.h>
#include<stdlib.h>
#include "blocos.h"
#include "tela.h"
#include "animacoes.h"

void Clock_Shift(void);

void Clock_Latch(void);

void Mostrar_Placar(int level, int score);

int Existe_Linha_Completa(void);

void Limpar_Linhas(int);

int Random(void);

int Gerar_Peca(void);

int Game_Over(void);

void ClearWDT(void);

void Tetris(void);

void mainGame(void);

#endif