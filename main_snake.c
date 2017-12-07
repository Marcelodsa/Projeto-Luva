#include "main_snake.h"

#pragma udata BIGDATA
int matrizS[16][8];
#pragma udata

#pragma udata CORPO
celula corpo[128];
#pragma udata

int sementeS;

void AtrasarS(void){
	int i;
	for(i = 0;i < 145; i++){}
}   

void ZerarS(void){
	int linhas,colunas;
	for(linhas = 0; linhas < 16; linhas++){
		for(colunas = 0; colunas < 8; colunas++){
			matrizS[linhas][colunas] = 0;
		}
	}
}

void SetarS(void){
	int linhas,colunas;
	for(linhas = 0; linhas < 16; linhas++){
		for(colunas = 0; colunas < 8; colunas++){
			matrizS[linhas][colunas] = 1;
		}
	}
}


void MostrarTelaS(void){
	int linhas, colunas;
	int coluna[8] = {254,253,251,247,239,223,191,127};
	for(colunas = 7; colunas >= 0; colunas--){
		LATB = coluna[colunas];
		if(matrizS[15][colunas] == 0){
			LATCbits.LATC0 = 0;
		}
		else{
			LATCbits.LATC0 = 1;
		}
		if(matrizS[14][colunas] == 0){
			LATCbits.LATC1 = 0;
		}
		else{
			LATCbits.LATC1 = 1;
		}
		if(matrizS[13][colunas] == 0){
			LATCbits.LATC2 = 0;
		}
		else{
			LATCbits.LATC2 = 1;
		}
		if(matrizS[12][colunas] == 0){
			LATCbits.LATC3 = 0;
		}
		else{
			LATCbits.LATC3 = 1;
		}
		if(matrizS[11][colunas] == 0){
			LATCbits.LATC4 = 0;
		}
		else{
			LATCbits.LATC4 = 1;
		}
		if(matrizS[10][colunas] == 0){
			LATCbits.LATC5 = 0;
		}
		else{
			LATCbits.LATC5 = 1;
		}
		if(matrizS[9][colunas] == 0){
			LATCbits.LATC6 = 0;
		}
		else{
			LATCbits.LATC6 = 1;
		}
		if(matrizS[8][colunas] == 0){
			LATCbits.LATC7 = 0;
		}
		else{
			LATCbits.LATC7 = 1;
		}
		if(matrizS[7][colunas] == 0){
			LATDbits.LATD0 = 0;
		}
		else{
			LATDbits.LATD0 = 1;
		}
		if(matrizS[6][colunas] == 0){
			LATDbits.LATD1 = 0;
		}
		else{
			LATDbits.LATD1 = 1;
		}
		if(matrizS[5][colunas] == 0){
			LATDbits.LATD2 = 0;
		}
		else{
			LATDbits.LATD2 = 1;
		}
		if(matrizS[4][colunas] == 0){
			LATDbits.LATD3 = 0;
		}
		else{
			LATDbits.LATD3 = 1;
		}
		if(matrizS[3][colunas] == 0){
			LATDbits.LATD4 = 0;
		}
		else{
			LATDbits.LATD4 = 1;
		}
		if(matrizS[2][colunas] == 0){
			LATDbits.LATD5 = 0;
		}
		else{
			LATDbits.LATD5 = 1;
		}
		if(matrizS[1][colunas] == 0){
			LATDbits.LATD6 = 0;
		}
		else{
			LATDbits.LATD6 = 1;
		}
		if(matrizS[0][colunas] == 0){
			LATDbits.LATD7 = 0;
		}
		else{
			LATDbits.LATD7 = 1;
		}
		AtrasarS();
		LATB = 0b11111111;
		LATC = 0b00000000;
		LATD = 0b00000000;
	}
}


int Retornar_Coordenadas(int valor, int* linha, int* coluna){
	*linha = corpo[valor - 1].x;
	*coluna = corpo[valor - 1].y;
}

void Deslocar_Corpo(int* tamanho, int direcao, int cabecax_old, int cabecay_old){
	int i,l,c;	
	Retornar_Coordenadas(*tamanho,&l,&c);
	matrizS[l][c] = 0;
	for(i = *tamanho; i > 2; i--){
		Retornar_Coordenadas(i - 1,&l,&c);
		matrizS[l][c] = i;
		corpo[i - 1].x = corpo[i - 2].x;
		corpo[i - 1].y = corpo[i - 2].y;
	}
	matrizS[cabecax_old][cabecay_old] = 2;
	corpo[1].x = cabecax_old;
	corpo[1].y = cabecay_old;
}

void Piscar_TelaS(void){
	int q;
	ZerarS();
	for(q = 0; q < 25; q++){
		MostrarTelaS();
	}
	SetarS();
	for(q = 0; q < 25; q++){
		MostrarTelaS();
	}
}


int Game_OverS(int* cabecax, int* cabecay, int* tamanho, int* direcao){
	int i,j,q;
	ZerarS();
	MostrarTelaS();
	for(i = 15; i >= 0; i--){
		if(i%2== 1){
			for(j = 0; j < 8; j++){
				matrizS[i][j] = 1;
				MostrarTelaS();
			}
		}
		else{
			for(j = 7; j >= 0; j--){
				matrizS[i][j] = 1;
				MostrarTelaS();
			}
		}
	}
	for(q = 0; q < 2; q++){Piscar_TelaS();}
	ZerarS();
	*cabecax = 8;
	*cabecay = 4;
	matrizS[*cabecax][*cabecay] = 1;
	*tamanho = 1;
	*direcao = 0;
	matrizS[3][1] = -1;
	return 0;
}

void Deslocar(int* cabecax, int* cabecay, int direcao,int *tamanho){
	int i,cabecax_old,cabecay_old;
	cabecax_old = *cabecax;
	cabecay_old = *cabecay;
	matrizS[*cabecax][*cabecay] = 0;
	if(direcao == 0){
		(*cabecax)--;
		if(*cabecax < 0){
			*cabecax = 15;
		}
	}
	else if(direcao == 1){
		(*cabecax)++;
		if(*cabecax > 15){
			*cabecax = 0;
		}
	}
	else if(direcao == 2){
		(*cabecay)++;
		if(*cabecay > 7){
			*cabecay = 0;
		}
	}
	else{
		(*cabecay)--;
		if(*cabecay < 0){
			*cabecay = 7;
		}
	}
	if(matrizS[*cabecax][*cabecay] > 0){
		Game_OverS(cabecax,cabecay,tamanho,&direcao);
	}
	matrizS[*cabecax][*cabecay] = 1;
	corpo[0].x = *cabecax;
	corpo[0].y = *cabecay;
	if(*tamanho > 1){Deslocar_Corpo(tamanho,direcao,cabecax_old,cabecay_old);}
}

void AtrasarTela(int* cabecax, int* cabecay, int* direcao, int* tamanho,int velocidade){
	int i,j;
	for(i = 0; i < velocidade; i++){
		MostrarTelaS();
		if(cima){
			if(*direcao == 3 || *direcao == 2){
				sementeS += 5;
				i = 0;
				for(j = 0; j < velocidade; j++){MostrarTelaS();}
				*direcao = 0;
				Deslocar(cabecax,cabecay,*direcao,tamanho);
			}
		}
		if(baixo){
			if(*direcao == 3 || *direcao == 2){
				sementeS /=2;
				i = 0;
				for(j = 0; j < velocidade; j++){MostrarTelaS();}
				*direcao = 1;
				Deslocar(cabecax,cabecay,*direcao,tamanho);
			}
		}
		if(direita){
			if(*direcao == 0 || *direcao == 1){
				sementeS += 30;
				i = 0;
				for(j = 0; j < velocidade; j++){MostrarTelaS();}
				*direcao = 2;
				Deslocar(cabecax,cabecay,*direcao,tamanho);
			}
		}
		if(esquerda){
			if(*direcao == 0 || *direcao == 1){
				sementeS *= 50;
				i = 0;
				for(j = 0; j < velocidade; j++){MostrarTelaS();}
				*direcao = 3;
				Deslocar(cabecax,cabecay,*direcao,tamanho);
			}
		}
	}	
}	

void Gerar_Fruta(int* frutax, int* frutay){
	int i,j;
	srand(sementeS);
	//do{
		i = rand()%16;
		j = rand()%8;
	//}while(matrizS[*frutax][*frutay] > 0);
	*frutax = i;
	*frutay = j;
	matrizS[*frutax][*frutay] = -1;
}

int Existe_Fruta(void){
	int i,j;
	for(i = 0;i < 16; i++){
		for(j = 0;j < 8; j++){
			if(matrizS[i][j] == -1){
				return  1;
			}	
		}	
	}
	return 0;
}

void Crescer_Cobra(int* tamanho, int direcao){
	int l,c;
	l = corpo[*tamanho - 1].x;
	c = corpo[*tamanho - 1].y;
	if(direcao == 0){
		matrizS[l + 1][c] = *tamanho + 1;
		corpo[*tamanho].x = l + 1;
		corpo[*tamanho].y = c;
	}
	else if(direcao == 1){
		matrizS[l - 1][c] = *tamanho + 1;
		corpo[*tamanho].x = l - 1;
		corpo[*tamanho].y = c;
	}
	else if(direcao == 2){
		matrizS[l][c - 1] = *tamanho + 1;
		corpo[*tamanho].x = l;
		corpo[*tamanho].y = c - 1;
	}
	else{
		matrizS[l][c + 1] = *tamanho + 1;
		corpo[*tamanho].x = l;
		corpo[*tamanho].y = c + 1;
	}
	(*tamanho)++;
	corpo[*tamanho - 1].valor = *tamanho;
}

void Desenhar_Numero_1(void){
	int j;
	ZerarS();
	for(j = 4; j < 11; j++){
			matrizS[j][4] = 1;
	}
	matrizS[5][3] = 1;
	matrizS[6][2] = 1;
}

void Desenhar_Numero_2(void){
	int j;
	ZerarS();
	for(j = 3; j < 6; j++){
		matrizS[4][j] = 1;
	}	
	matrizS[5][2] = 1;
	matrizS[5][6] = 1;
	matrizS[6][6] = 1;
	matrizS[7][5] = 1;
	j = 8;
	matrizS[j][4] = 1;
	j = 9;
	matrizS[j][3] = 1;
	for(j = 2; j < 7; j++){
		matrizS[10][j] = 1;
	}
}

void Desenhar_Numero_3(void){
	int j;
	ZerarS();
	for(j = 3; j < 6; j++){
		matrizS[4][j] = 1;
	}	
	matrizS[5][2] = 1;
	matrizS[5][6] = 1;
	matrizS[6][6] = 1;
	for(j = 3; j < 6; j++){
		matrizS[10][j] = 1;
	}	
	matrizS[9][2] = 1;
	matrizS[9][6] = 1;
	matrizS[8][6] = 1;
	j = 5;
	matrizS[7][j] = 1;
	j = 4;
	matrizS[7][j] = 1;
}

int Menu(int* velocidade){
	int op,j;
	op = 1;
	while(1){
		if(direita){
			for(j = 0; j < 25; j++){MostrarTelaS();}
			op++;
			if(op > 3){
				op = 1;
			}			
		}
		else if(esquerda){
			for(j = 0; j < 25; j++){MostrarTelaS();}
			op--;
			if(op < 1){
				op = 3;
			}
		}
		if(op == 1){
			Desenhar_Numero_1();
			MostrarTelaS();
		}
		else if(op == 2){
			Desenhar_Numero_2();
			MostrarTelaS();
		}
		else{
			Desenhar_Numero_3();
			MostrarTelaS();
		}
		if(cima){
			for(j = 0; j < 25; j++);
			if(op == 1){
				*velocidade = 15;
			}
			else if(op == 2){
				*velocidade = 5;
			}
			else{
				*velocidade = 2;
			}
			ZerarS();
			return 0;
		}
	}
}

void Snake(void){
	int q;
	for(q = 2; q < 6; q++){
		matrizS[0][q] = 1;
		matrizS[2][q] = 1;
		matrizS[4][q] = 1;
	}
	matrizS[1][2] = 1;
	matrizS[3][5] = 1;
	for(q = 6; q < 11; q++){
		matrizS[q][0] = 1;
		matrizS[q][3] = 1;
		matrizS[q][4] = 1;
		matrizS[q][7] = 1;
		matrizS[q + 5][0] = 1;
		matrizS[q + 5][5] = 1;
	}
	matrizS[7][1] = 1;
	matrizS[8][2] = 1;
	matrizS[6][5] = 1;
	matrizS[6][6] = 1;
	matrizS[8][5] = 1;
	matrizS[8][6] = 1;
	for(q = 5; q < 8; q++){
		matrizS[11][q] = 1;
		matrizS[13][q] = 1;
		matrizS[15][q] = 1;
	}
	matrizS[11][3] = 1;
	matrizS[12][2] = 1;
	matrizS[13][1] = 1;
	matrizS[14][2] = 1;
	matrizS[15][3] = 1;
	MostrarTelaS();
}

void main_snake_game(void){
	int cabecax,cabecay,direcao,tamanho,frutax,frutay,velocidade;
	LATC = 0b00000000;
	LATD = 0b00000000;
	LATB = 0b11111111;
	ZerarS();
	Menu(&velocidade);
	cabecax = 8;
	cabecay = 4;
	matrizS[cabecax][cabecay] = 1;
	corpo[0].valor = 1;
	corpo[0].x = 8;
	corpo[0].y = 4;
	tamanho = 1;
	direcao = 0;
	sementeS = 1;
	Gerar_Fruta(&frutax,&frutay);
	while(1){
		if(!Existe_Fruta()){
			Gerar_Fruta(&frutax,&frutay);
			Crescer_Cobra(&tamanho,direcao);
		}
		AtrasarTela(&cabecax,&cabecay,&direcao,&tamanho,velocidade);
		Deslocar(&cabecax,&cabecay,direcao,&tamanho);
	}
}