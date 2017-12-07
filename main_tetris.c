#include "main_tetris.h"

#define DATA LATEbits.LATE0
#define SHIFT LATEbits.LATE1
#define LATCH LATEbits.LATE2
#define tempo_descida_inicial 70

#pragma udata MATRIZ
int matriz[18][8];
#pragma udata

void Clock_Shift(void){
	SHIFT = 0;
	SHIFT = 1;
}

void Clock_Latch(void){
	LATCH = 0;
	LATCH = 1;
}

void Mostrar_Placar(int level, int score){
	int i;
	for(i = 0; i < 8; i++){
		DATA = level % 2;
		Clock_Shift();
		level = level >> 1;
	}
	for(i = 0; i < 8; i++){
		DATA = score % 2;
		Clock_Shift();
		score = score >> 1;
	}
	Clock_Latch();
}

int Existe_Linha_Completa(void){
	int i,j,qt;
	for(i = 17; i > 1; i--){
		qt = 0;
		for(j = 0; j < 8; j++){
			if(matriz[i][j] == 1){
				qt++;
			}
		}
		if(qt == 8){
			return i;
		}
	}
	return 0;
}

void Limpar_Linhas(int linha){
	int i,j;
	for(i = linha; i > 4; i--){
		for(j = 0; j < 8; j++){
			matriz[i][j] = matriz[i-1][j];
		}
	}
}

int Random(void)
{
    int rand_num = 0;
    rand_num = rand()%7 + 1 ;  // generates a random number between 1 and 7  
    return rand_num ;            // which are used to select the tetris shape
}

int Game_Over(void){
	int i;
	for(i = 0; i < 8; i++){
		if(matriz[1][i] == 1 && matriz[2][i] == 1 && matriz[3][i] == 1){
			return 1;
		}
	}
	return 0;
}

void ClearWDT(void){
	ClrWdt();
}

void Tetris(void){
	int q;
	//faz o T
	matriz[2][1] = 1;
	matriz[2][2] = 1;
	matriz[2][3] = 1;
	matriz[3][2] = 1;
	matriz[4][2] = 1;
	matriz[5][2] = 1;
	matriz[6][2] = 1;
	//faz o E
	matriz[2][4] = 1;
	matriz[2][5] = 1;
	matriz[2][6] = 1;
	matriz[3][4] = 1;
	matriz[4][4] = 1;
	matriz[4][5] = 1;
	matriz[4][6] = 1;
	matriz[5][4] = 1;
	matriz[6][4] = 1;
	matriz[6][5] = 1;
	matriz[6][6] = 1;
	//faz o T
	matriz[7][1] = 1;
	matriz[7][2] = 1;
	matriz[7][3] = 1;
	matriz[8][2] = 1;
	matriz[9][2] = 1;
	matriz[10][2] = 1;
	matriz[11][2] = 1;
	//faz o R
	matriz[7][4] = 1;
	matriz[7][5] = 1;
	matriz[8][4] = 1;
	matriz[9][4] = 1;
	matriz[10][4] = 1;
	matriz[11][4] = 1;
	matriz[8][6] = 1;
	matriz[9][6] = 1;
	matriz[10][5] = 1;
	matriz[11][6] = 1;
	//faz o I
	matriz[12][1] = 1;
	matriz[12][2] = 1;
	matriz[12][3] = 1;
	matriz[13][2] = 1;
	for(q = 14; q < 17; q++){
		matriz[q][2] = 1;
	}
	matriz[16][1] = 1;
	matriz[16][3] = 1;
	//faz o S
	for(q = 4; q <= 6; q++){
		matriz[12][q] = 1;
		matriz[16][q] = 1;
	}
	matriz[13][4] = 1;
	for(q = 4; q < 7; q++){
		matriz[14][q] = 1;
	}
	matriz[15][6] = 1;
	MostrarTela(matriz);
}

void mainGame(void){
	int tempo_descida,score,fator,level,peca_atual;
	bloco bloco_atual;
	LATEbits.LATE0 = 0;
	LATEbits.LATE1 = 0;
	LATEbits.LATE2 = 0;
	LATC = 0b00000000;
	LATD = 0b00000000;
	LATB = 0b11111111;
	Zerar(matriz); 
	tempo_descida = tempo_descida_inicial;
	score = 0;
	fator = 0;
	level = 0;
	Splash_Screen(matriz);
	while(1){
		peca_atual = Gerar_Peca();
		if(peca_atual == 1){
			Gerar_Quadrado(&bloco_atual,matriz);
			while(Pode_Deslocar_Baixo_Q(&bloco_atual,matriz)){
				Deslocar_Baixo_Q(&bloco_atual,matriz);
				AtrasarTela_Q(&bloco_atual,matriz,tempo_descida);
			}
		}
		if(peca_atual == 2){
			Gerar_Reta(&bloco_atual,matriz);
			while(Pode_Deslocar_Baixo_R(&bloco_atual,matriz)){
				Deslocar_Baixo_R(&bloco_atual,matriz);
				AtrasarTela_R(&bloco_atual,matriz,tempo_descida);
			}
		}
		if(peca_atual == 3){
			Gerar_Z_Esq(&bloco_atual,matriz);
			while(Pode_Deslocar_Baixo_ZE(&bloco_atual,matriz)){
				Deslocar_Baixo_ZE(&bloco_atual,matriz);
				AtrasarTela_ZE(&bloco_atual,matriz,tempo_descida);
			}
		}
		if(peca_atual == 4){
			Gerar_Z_Dir(&bloco_atual,matriz);
			while(Pode_Deslocar_Baixo_ZD(&bloco_atual,matriz)){
				Deslocar_Baixo_ZD(&bloco_atual,matriz);
				AtrasarTela_ZD(&bloco_atual,matriz,tempo_descida);
			}
		}
		if(peca_atual == 5){
			Gerar_T(&bloco_atual,matriz);
			while(Pode_Deslocar_Baixo_T(&bloco_atual,matriz)){
				Deslocar_Baixo_T(&bloco_atual,matriz);
				AtrasarTela_T(&bloco_atual,matriz,tempo_descida);
			}
		}
		if(peca_atual == 6){
			Gerar_LE(&bloco_atual,matriz);
			while(Pode_Deslocar_Baixo_LE(&bloco_atual,matriz)){
				Deslocar_Baixo_LE(&bloco_atual,matriz);
				AtrasarTela_LE(&bloco_atual,matriz,tempo_descida);
			}
		}
		if(peca_atual == 7){
			Gerar_LD(&bloco_atual,matriz);
			while(Pode_Deslocar_Baixo_LD(&bloco_atual,matriz)){
				Deslocar_Baixo_LD(&bloco_atual,matriz);
				AtrasarTela_LD(&bloco_atual,matriz,tempo_descida);
			}
		}
		if(Game_Over()){
			Game_Over_Animacao(matriz);
			score = 0;
			level = 0;	
			fator = 1;
		}
		while(Existe_Linha_Completa() >= 4){
			Limpar_Linhas(Existe_Linha_Completa());
			fator++;
			MostrarTela(matriz);
		}
		score = score + fator * 5;
		fator = 0;
		level = score / 30;
		tempo_descida = tempo_descida_inicial - 7 * level;
		MostrarTela(matriz);
		Mostrar_Placar(level,score);
		ClearWDT();
	}
}