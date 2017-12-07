#include"animacoes.h"

void Zerar(int matriz[18][8]){
	int linhas,colunas;
	for(linhas = 0; linhas < 18; linhas++){
		for(colunas = 0; colunas < 8; colunas++){
			matriz[linhas][colunas] = 0;
		}
	}
}

void Setar(int matriz[18][8]){
	int linhas,colunas;
	for(linhas = 0; linhas < 18; linhas++){
		for(colunas = 0; colunas < 8; colunas++){
			matriz[linhas][colunas] = 1;
		}
	}
}

void Piscar_Tela(int matriz[18][8]){
	int q;
	Zerar(matriz);
	for(q = 0; q < 25; q++){
		MostrarTela(matriz);
	}
	Setar(matriz);
	for(q = 0; q < 25; q++){
		MostrarTela(matriz);
	}
}


void Game_Over_Animacao(int matriz[18][8]){
	int i,j,q;
	Zerar(matriz);
	MostrarTela(matriz);
	for(i = 17; i > 1; i--){
		if(i%2== 1){
			for(j = 0; j < 8; j++){
				matriz[i][j] = 1;
				MostrarTela(matriz);
			}
		}
		else{
			for(j = 7; j >= 0; j--){
				matriz[i][j] = 1;
				MostrarTela(matriz);
			}
		}
	}
	for(q = 0; q < 3; q++){Piscar_Tela(matriz);}
	Zerar(matriz);
}

void Splash_Screen(int matriz[18][8]){
	int q,tempo;
	tempo = 40;
	//faz o T
	matriz[2][1] = 1;
	matriz[2][2] = 1;
	matriz[2][3] = 1;
	matriz[3][2] = 1;
	matriz[4][2] = 1;
	matriz[5][2] = 1;
	matriz[6][2] = 1;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
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
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//faz o T
	matriz[7][1] = 1;
	matriz[7][2] = 1;
	matriz[7][3] = 1;
	matriz[8][2] = 1;
	matriz[9][2] = 1;
	matriz[10][2] = 1;
	matriz[11][2] = 1;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
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
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
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
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//faz o S
	matriz[12][4] = 1;
	matriz[12][5] = 1;
	matriz[12][6] = 1;
	matriz[13][4] = 1;
	for(q = 4; q < 7; q++){
		matriz[14][q] = 1;
	}
	matriz[15][6] = 1;
	matriz[16][4] = 1;
	matriz[16][5] = 1;
	matriz[16][6] = 1;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//apaga o S
	matriz[12][4] = 0;
	matriz[12][5] = 0;
	matriz[12][6] = 0;
	matriz[13][4] = 0;
	for(q = 4; q < 7; q++){
		matriz[14][q] = 0;
	}
	matriz[15][6] = 0;
	matriz[16][4] = 0;
	matriz[16][5] = 0;
	matriz[16][6] = 0;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//apaga o I
	matriz[12][1] = 0;
	matriz[12][2] = 0;
	matriz[12][3] = 0;
	matriz[13][2] = 0;
	for(q = 14; q < 17; q++){
		matriz[q][2] = 0;
	}
	matriz[16][1] = 0;
	matriz[16][3] = 0;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//apaga o R
	matriz[7][4] = 0;
	matriz[7][5] = 0;
	matriz[8][4] = 0;
	matriz[9][4] = 0;
	matriz[10][4] = 0;
	matriz[11][4] = 0;
	matriz[8][6] = 0;
	matriz[9][6] = 0;
	matriz[10][5] = 0;
	matriz[11][6] = 0;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//apaga o T
	matriz[7][1] = 0;
	matriz[7][2] = 0;
	matriz[7][3] = 0;
	matriz[8][2] = 0;
	matriz[9][2] = 0;
	matriz[10][2] = 0;
	matriz[11][2] = 0;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//apaga o E
	matriz[2][4] = 0;
	matriz[2][5] = 0;
	matriz[2][6] = 0;
	matriz[3][4] = 0;
	matriz[4][4] = 0;
	matriz[4][5] = 0;
	matriz[4][6] = 0;
	matriz[5][4] = 0;
	matriz[6][4] = 0;
	matriz[6][5] = 0;
	matriz[6][6] = 0;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
	//apaga o T
	matriz[2][1] = 0;
	matriz[2][2] = 0;
	matriz[2][3] = 0;
	matriz[3][2] = 0;
	matriz[4][2] = 0;
	matriz[5][2] = 0;
	matriz[6][2] = 0;
	for(q = 0; q < tempo; q++){
		MostrarTela(matriz);
	}
}