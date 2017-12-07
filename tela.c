#include"tela.h"

void Atrasar(void){
	int i;
	for(i = 0;i < 140; i++){}
}   

void MostrarTela(int matriz[18][8]){
	int linhas, colunas;
	int coluna[8] = {254,253,251,247,239,223,191,127};
	for(colunas = 0; colunas < 8; colunas++){
		LATB = coluna[colunas];
		LATCbits.LATC0 = matriz[17][colunas];
		LATCbits.LATC1 = matriz[16][colunas];
		LATCbits.LATC2 = matriz[15][colunas];
		LATCbits.LATC3 = matriz[14][colunas];
		LATCbits.LATC4 = matriz[13][colunas];
		LATCbits.LATC5 = matriz[12][colunas];
		LATCbits.LATC6 = matriz[11][colunas];
		LATCbits.LATC7 = matriz[10][colunas];
		LATDbits.LATD0 = matriz[9][colunas];
		LATDbits.LATD1 = matriz[8][colunas];
		LATDbits.LATD2 = matriz[7][colunas];
		LATDbits.LATD3 = matriz[6][colunas];
		LATDbits.LATD4 = matriz[5][colunas];
		LATDbits.LATD5 = matriz[4][colunas];
		LATDbits.LATD6 = matriz[3][colunas];
		LATDbits.LATD7 = matriz[2][colunas];
		Atrasar();
		LATB = 0b11111111;
		LATC = 0b00000000;
		LATD = 0b00000000;
	}
}