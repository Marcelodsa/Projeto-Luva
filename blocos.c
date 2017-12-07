#include "blocos.h"

double semente;

int Gerar_Peca(void){
	int peca_atual;
	//srand(semente);
	peca_atual = rand()%7;
	return peca_atual;
}

//funcoes do bloco quadrado
void Gerar_Quadrado(bloco* q, int matriz[18][8]){
	matriz[1][4] = 1;
	matriz[1][5] = 1;
	matriz[0][4] = 1;
	matriz[0][5] = 1;
	q->x1 = 0;
	q->y1 = 4;
	q->x2 = 0;
	q->y2 = 5;
	q->x3 = 1;
	q->y3 = 4;
	q->x4 = 1;
	q->y4 = 5;
}

int Pode_Deslocar_Baixo_Q(bloco* q,int matriz[18][8]){
	if(q->x3 < 17 && q->x4 < 17){
		if(matriz[(q->x3)+1][q->y3] == 0 && matriz[(q->x4)+1][q->y4] == 0){
			return 1;
		}
	}
	return 0;
}

void Deslocar_Baixo_Q(bloco* q,int matriz[18][8]){
	matriz[q->x1][q->y1] = 0;
	matriz[q->x2][q->y2] = 0;
	matriz[q->x3][q->y3] = 0;
	matriz[q->x4][q->y4] = 0;
	q->x1 = q->x1 + 1;
	q->x2 = q->x2 + 1;
	q->x3 = q->x3 + 1;
	q->x4 = q->x4 + 1;
	matriz[q->x1][q->y1] = 1;
	matriz[q->x2][q->y2] = 1;
	matriz[q->x3][q->y3] = 1;
	matriz[q->x4][q->y4] = 1;
}

int Pode_Deslocar_Esquerda_Q(bloco* q,int matriz[18][8]){
	if(q->y3 > 0 && q->y1 > 0){
		if(matriz[q->x1][(q->y1) - 1] == 0 && matriz[q->x3][(q->y3) - 1] == 0){
			return 1;
		}
	}
	return 0;
}

void Deslocar_Esquerda_Q(bloco* q,int matriz[18][8]){
	matriz[q->x1][q->y1] = 0;
	matriz[q->x2][q->y2] = 0;
	matriz[q->x3][q->y3] = 0;
	matriz[q->x4][q->y4] = 0;
	q->y1 = q->y1 - 1;
	q->y2 = q->y2 - 1;
	q->y3 = q->y3 - 1;
	q->y4 = q->y4 - 1;
	matriz[q->x1][q->y1] = 1;
	matriz[q->x2][q->y2] = 1;
	matriz[q->x3][q->y3] = 1;
	matriz[q->x4][q->y4] = 1;
}

int Pode_Deslocar_Direita_Q(bloco* q,int matriz[18][8]){
	if(q->y2 < 7 && q->y4 < 7){
		if(matriz[q->x2][(q->y2) + 1] == 0 && matriz[q->x4][(q->y4) + 1] == 0){
			return 1;
		}
	}
	return 0;
}

void Deslocar_Direita_Q(bloco* q,int matriz[18][8]){
	matriz[q->x1][q->y1] = 0;
	matriz[q->x2][q->y2] = 0;
	matriz[q->x3][q->y3] = 0;
	matriz[q->x4][q->y4] = 0;
	q->y1 = q->y1 + 1;
	q->y2 = q->y2 + 1;
	q->y3 = q->y3 + 1;
	q->y4 = q->y4 + 1;
	matriz[q->x1][q->y1] = 1;
	matriz[q->x2][q->y2] = 1;
	matriz[q->x3][q->y3] = 1;
	matriz[q->x4][q->y4] = 1;
}

int AtrasarTela_Q(bloco* q,int matriz[18][8], int tempo_descida){
	int i,j;
	for(i = 0; i < tempo_descida; i++){
		MostrarTela(matriz);
		if(PORTAbits.RA2){
			semente *= 3;
			if(Pode_Deslocar_Baixo_Q(q,matriz)){
				for(j = 0; j < tempo_descida_forcada; j++){MostrarTela(matriz);}
				Deslocar_Baixo_Q(q,matriz);
			}
		}
		if(PORTAbits.RA3){
			semente += 20;
			if(Pode_Deslocar_Esquerda_Q(q,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_Q(q,matriz)){Deslocar_Baixo_Q(q,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Esquerda_Q(q,matriz);
			}
		}
		if(PORTAbits.RA1){
			semente -= 5;
			if(Pode_Deslocar_Direita_Q(q,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_Q(q,matriz)){Deslocar_Baixo_Q(q,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Direita_Q(q,matriz);
			}
		}
	}
}

//funcoes do bloco linha

void Gerar_Reta(bloco* r, int matriz[18][8]){
	matriz[1][0] = 1;
	matriz[1][1] = 1;
	matriz[1][2] = 1;
	matriz[1][3] = 1;
	r->x1 = 1;
	r->y1 = 0;
	r->x2 = 1;
	r->y2 = 1;
	r->x3 = 1;
	r->y3 = 2;
	r->x4 = 1;
	r->y4 = 3;
	r->orientacao = 0;
}

int Pode_Deslocar_Baixo_R(bloco* r, int matriz[18][8]){
	if(r->orientacao == 0){
		if(r->x1 < 17){
			if(matriz[(r->x1) + 1][r->y1] == 0 && matriz[(r->x2) + 1][r->y2] == 0 && matriz[(r->x3) + 1][r->y3] == 0 && matriz[(r->x4) + 1][r->y4] == 0){
				return 1;
			}
		}
	}
	else{
		if(r->x4 < 17){
			if(matriz[(r->x4) + 1][r->y4] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Baixo_R(bloco* r, int matriz[18][8]){
	matriz[r->x1][r->y1] = 0;
	matriz[r->x2][r->y2] = 0;
	matriz[r->x3][r->y3] = 0;
	matriz[r->x4][r->y4] = 0;
	r->x1++;
	r->x2++;
	r->x3++;
	r->x4++;
	matriz[r->x1][r->y1] = 1;
	matriz[r->x2][r->y2] = 1;
	matriz[r->x3][r->y3] = 1;
	matriz[r->x4][r->y4] = 1;
}

int Pode_Deslocar_Esquerda_R(bloco* r,int matriz[18][8]){
	if(r->orientacao == 0){
		if(r->y1 > 0){
			if(matriz[r->x1][(r->y1) - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(r->y1 > 0){
			if(matriz[r->x1][r->y1 - 1] == 0 && matriz[r->x2][r->y2 - 1] == 0 && matriz[r->x3][r->y3 - 1] == 0 && matriz[r->x4][r->y4 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Esquerda_R(bloco* r,int matriz[18][8]){
	matriz[r->x1][r->y1] = 0;
	matriz[r->x2][r->y2] = 0;
	matriz[r->x3][r->y3] = 0;
	matriz[r->x4][r->y4] = 0;
	r->y1--;
	r->y2--;
	r->y3--;
	r->y4--;
	matriz[r->x1][r->y1] = 1;
	matriz[r->x2][r->y2] = 1;
	matriz[r->x3][r->y3] = 1;
	matriz[r->x4][r->y4] = 1;
}

int Pode_Deslocar_Direita_R(bloco* r,int matriz[18][8]){
	if(r->orientacao == 0){
		if(r->y4 < 7){
			if(matriz[r->x1][(r->y4) + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(r->y4 < 7){
			if(matriz[r->x1][r->y1 + 1] == 0 && matriz[r->x2][r->y2 + 1] == 0 && matriz[r->x3][r->y3 + 1] == 0 && matriz[r->x4][r->y4 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Direita_R(bloco* r,int matriz[18][8]){
	matriz[r->x1][r->y1] = 0;
	matriz[r->x2][r->y2] = 0;
	matriz[r->x3][r->y3] = 0;
	matriz[r->x4][r->y4] = 0;
	r->y1++;
	r->y2++;
	r->y3++;
	r->y4++;
	matriz[r->x1][r->y1] = 1;
	matriz[r->x2][r->y2] = 1;
	matriz[r->x3][r->y3] = 1;
	matriz[r->x4][r->y4] = 1;
}

int Pode_Rotacionar_R(bloco* r,int matriz[18][8]){
	if(r->orientacao == 0){
		if(r->x1 > 2  && r->x4 < 16){
			if(matriz[r->x2 - 1][r->y2] == 0 && matriz[r->x2 + 1][r->y2] == 0 && matriz[r->x2 + 2][r->y2] == 0){
				return 1;
			}
		}
	}
	else{
		if(r->y1 > 0 && r->y4 < 6){
			if(matriz[r->x1 + 1][r->y1 - 1] == 0 && matriz[r->x3 - 1][r->y3 + 1] == 0 && matriz[r->x4 - 2][r->y4 + 2] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_R(bloco* r,int matriz[18][8]){
	matriz[r->x1][r->y1] = 0;
	matriz[r->x2][r->y2] = 0;
	matriz[r->x3][r->y3] = 0;
	matriz[r->x4][r->y4] = 0;
	if(r->orientacao == 0){
		r->x1--;
		r->y1++;
		r->x3++;
		r->y3--;
		r->x4 += 2;
		r->y4 -= 2; 
		r->orientacao = 1;	
	}
	else{
		r->x1++;
		r->y1--;
		r->x3--;
		r->y3++;
		r->x4 -= 2;
		r->y4 +=2;
		r->orientacao = 0;
	}
	matriz[r->x1][r->y1] = 1;
	matriz[r->x2][r->y2] = 1;
	matriz[r->x3][r->y3] = 1;
	matriz[r->x4][r->y4] = 1;
}

int AtrasarTela_R(bloco* r,int matriz[18][8], int tempo_descida){
	int i,j;
	for(i = 0; i < tempo_descida; i++){
		MostrarTela(matriz);
		if(PORTAbits.RA2){
			semente *= 2;
			if(Pode_Deslocar_Baixo_R(r,matriz)){
				for(j = 0; j < tempo_descida_forcada; j++){MostrarTela(matriz);}
				Deslocar_Baixo_R(r,matriz);
			}
		}
		if(PORTAbits.RA3){
			semente /= 7;
			if(Pode_Deslocar_Esquerda_R(r,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_R(r,matriz)){Deslocar_Baixo_R(r,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Esquerda_R(r,matriz);
			}
		}
		if(PORTAbits.RA1){
			semente += 34;
			if(Pode_Deslocar_Direita_R(r,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_R(r,matriz)){Deslocar_Baixo_R(r,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Direita_R(r,matriz);
			}
		}
		if(PORTAbits.RA0){
			semente -= 13;
			if(Pode_Rotacionar_R(r,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_R(r,matriz)){Deslocar_Baixo_R(r,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Rotacionar_R(r,matriz);
			}
		}
	}
}

//funcoes do bloco z esquerda

void Gerar_Z_Esq(bloco* ze, int matriz[18][8]){
	matriz[0][1] = 1;
	matriz[0][2] = 1;
	matriz[1][2] = 1;
	matriz[1][3] = 1;
	ze->x1 = 0;
	ze->y1 = 1;
	ze->x2 = 0;
	ze->y2 = 2;
	ze->x3 = 1;
	ze->y3 = 2;
	ze->x4 = 1;
	ze->y4 = 3;
	ze->orientacao = 0;
}

int Pode_Deslocar_Baixo_ZE(bloco* ze, int matriz[18][8]){
	if(ze->orientacao == 0){
		if(ze->x3 < 17){
			if(matriz[ze->x1 + 1][ze->y1] == 0 && matriz[ze->x3 + 1][ze->y3] == 0 && matriz[ze->x4 + 1][ze->y4] == 0){
				return 1;
			}
		}
	}
	else{
		if(ze->x4 < 17){
			if(matriz[ze->x4 + 1][ze->y4] == 0 && matriz[ze->x2 + 1][ze->y2] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Baixo_ZE(bloco* ze, int matriz[18][8]){
	matriz[ze->x1][ze->y1] = 0;
	matriz[ze->x2][ze->y2] = 0;
	matriz[ze->x3][ze->y3] = 0;
	matriz[ze->x4][ze->y4] = 0;
	ze->x1++;
	ze->x2++;
	ze->x3++;
	ze->x4++;
	matriz[ze->x1][ze->y1] = 1;
	matriz[ze->x2][ze->y2] = 1;
	matriz[ze->x3][ze->y3] = 1;
	matriz[ze->x4][ze->y4] = 1;
}

int Pode_Deslocar_Esquerda_ZE(bloco* ze, int matriz[18][8]){
	if(ze->orientacao == 0){
		if(ze->y1 > 0){
			if(matriz[ze->x1][ze->y1 - 1] == 0 && matriz[ze->x3][ze->y3 - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(ze->y3 > 0){
			if(matriz[ze->x3][ze->y3 - 1] == 0 && matriz[ze->x4][ze->y4 - 1] == 0 && matriz[ze->x1][ze->y1 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Esquerda_ZE(bloco* ze, int matriz[18][8]){
	matriz[ze->x1][ze->y1] = 0;
	matriz[ze->x2][ze->y2] = 0;
	matriz[ze->x3][ze->y3] = 0;
	matriz[ze->x4][ze->y4] = 0;
	ze->y1--;
	ze->y2--;
	ze->y3--;
	ze->y4--;
	matriz[ze->x1][ze->y1] = 1;
	matriz[ze->x2][ze->y2] = 1;
	matriz[ze->x3][ze->y3] = 1;
	matriz[ze->x4][ze->y4] = 1;
}

int Pode_Deslocar_Direita_ZE(bloco* ze, int matriz[18][8]){
	if(ze->orientacao == 0){
		if(ze->y4 < 7){
			if(matriz[ze->x2][ze->y2 + 1] == 0 && matriz[ze->x4][ze->y4 + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(ze->y1 < 7){
			if(matriz[ze->x1][ze->y1 + 1] == 0 && matriz[ze->x2][ze->y2 + 1] == 0 && matriz[ze->x4][ze->y4 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Direita_ZE(bloco* ze, int matriz[18][8]){
	matriz[ze->x1][ze->y1] = 0;
	matriz[ze->x2][ze->y2] = 0;
	matriz[ze->x3][ze->y3] = 0;
	matriz[ze->x4][ze->y4] = 0;
	ze->y1++;
	ze->y2++;
	ze->y3++;
	ze->y4++;
	matriz[ze->x1][ze->y1] = 1;
	matriz[ze->x2][ze->y2] = 1;
	matriz[ze->x3][ze->y3] = 1;
	matriz[ze->x4][ze->y4] = 1;
}

int Pode_Rotacionar_ZE(bloco* ze, int matriz[18][8]){
	if(ze->orientacao == 0){
		if(ze->x1 > 4 && ze->x4 < 19){
			if(matriz[ze->x3 + 1][ze->y3] == 0 && matriz[ze->x2][ze->y2 + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(ze->y3 > 0){
			if(matriz[ze->x3 - 1][ze->y3 - 1] == 0 && matriz[ze->x3 - 1][ze->y3] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_ZE(bloco* ze, int matriz[18][8]){
	matriz[ze->x1][ze->y1] = 0;
	matriz[ze->x2][ze->y2] = 0;
	matriz[ze->x3][ze->y3] = 0;
	matriz[ze->x4][ze->y4] = 0;
	if(ze->orientacao == 0){
		ze->y1 += 2;
		ze->x2++;
		ze->y2++;
		ze->x4++;
		ze->y4--; 
		ze->orientacao = 1;	
	}
	else{
		ze->y1 -= 2;
		ze->x2--;
		ze->y2--;
		ze->x4--;
		ze->y4++; 
		ze->orientacao = 0;
	}
	matriz[ze->x1][ze->y1] = 1;
	matriz[ze->x2][ze->y2] = 1;
	matriz[ze->x3][ze->y3] = 1;
	matriz[ze->x4][ze->y4] = 1;
}

int AtrasarTela_ZE(bloco* ze, int matriz[18][8], int tempo_descida){
	int i,j;
	for(i = 0; i < tempo_descida; i++){
		MostrarTela(matriz);
		if(PORTAbits.RA2){
			semente *= 6;
			if(Pode_Deslocar_Baixo_ZE(ze,matriz)){
				for(j = 0; j < tempo_descida_forcada; j++){MostrarTela(matriz);}
				Deslocar_Baixo_ZE(ze,matriz);
			}
		}
		if(PORTAbits.RA3){
			semente += 8;
			if(Pode_Deslocar_Esquerda_ZE(ze,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_ZE(ze,matriz)){Deslocar_Baixo_ZE(ze,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Esquerda_ZE(ze,matriz);
			}
		}
		if(PORTAbits.RA1){
			semente -= 1;
			if(Pode_Deslocar_Direita_ZE(ze,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_ZE(ze,matriz)){Deslocar_Baixo_ZE(ze,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Direita_ZE(ze,matriz);
			}
		}
		if(PORTAbits.RA0){
			semente /= 2;
			if(Pode_Rotacionar_ZE(ze,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_ZE(ze,matriz)){Deslocar_Baixo_ZE(ze,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Rotacionar_ZE(ze,matriz);
			}
		}
	}
}

//funcoes do bloco z direita

void Gerar_Z_Dir(bloco* zd, int matriz[18][8]){
	matriz[0][7] = 1;
	matriz[0][6] = 1;
	matriz[1][6] = 1;
	matriz[1][5] = 1;
	zd->x1 = 0;
	zd->y1 = 7;
	zd->x2 = 0;
	zd->y2 = 6;
	zd->x3 = 1;
	zd->y3 = 6;
	zd->x4 = 1;
	zd->y4 = 5;
	zd->orientacao = 0;
}

int Pode_Deslocar_Baixo_ZD(bloco* zd, int matriz[18][8]){
	if(zd->orientacao == 0){
		if(zd->x3 < 17){
			if(matriz[zd->x1 + 1][zd->y1] == 0 && matriz[zd->x3 + 1][zd->y3] == 0 && matriz[zd->x4 + 1][zd->y4] == 0){
				return 1;
			}
		}
	}
	else{
		if(zd->x4 < 17){
			if(matriz[zd->x4 + 1][zd->y4] == 0 && matriz[zd->x2 + 1][zd->y2] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Baixo_ZD(bloco* zd, int matriz[18][8]){
	matriz[zd->x1][zd->y1] = 0;
	matriz[zd->x2][zd->y2] = 0;
	matriz[zd->x3][zd->y3] = 0;
	matriz[zd->x4][zd->y4] = 0;
	zd->x1++;
	zd->x2++;
	zd->x3++;
	zd->x4++;
	matriz[zd->x1][zd->y1] = 1;
	matriz[zd->x2][zd->y2] = 1;
	matriz[zd->x3][zd->y3] = 1;
	matriz[zd->x4][zd->y4] = 1;
}

int Pode_Deslocar_Esquerda_ZD(bloco* zd, int matriz[18][8]){
	if(zd->orientacao == 0){
		if(zd->y4 > 0){
			if(matriz[zd->x4][zd->y4 - 1] == 0 && matriz[zd->x2][zd->y2 - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(zd->y2 > 0){
			if(matriz[zd->x1][zd->y1 - 1] == 0 && matriz[zd->x2][zd->y2 - 1] == 0 && matriz[zd->x4][zd->y4 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Esquerda_ZD(bloco* zd, int matriz[18][8]){
	matriz[zd->x1][zd->y1] = 0;
	matriz[zd->x2][zd->y2] = 0;
	matriz[zd->x3][zd->y3] = 0;
	matriz[zd->x4][zd->y4] = 0;
	zd->y1--;
	zd->y2--;
	zd->y3--;
	zd->y4--;
	matriz[zd->x1][zd->y1] = 1;
	matriz[zd->x2][zd->y2] = 1;
	matriz[zd->x3][zd->y3] = 1;
	matriz[zd->x4][zd->y4] = 1;
}

int Pode_Deslocar_Direita_ZD(bloco* zd, int matriz[18][8]){
	if(zd->orientacao == 0){
		if(zd->y1 < 7){
			if(matriz[zd->x1][zd->y1 + 1] == 0 && matriz[zd->x3][zd->y3 + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(zd->y4 < 7){
			if(matriz[zd->x1][zd->y1 + 1] == 0 && matriz[zd->x3][zd->y3 + 1] == 0 && matriz[zd->x4][zd->y4 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Direita_ZD(bloco* zd, int matriz[18][8]){
	matriz[zd->x1][zd->y1] = 0;
	matriz[zd->x2][zd->y2] = 0;
	matriz[zd->x3][zd->y3] = 0;
	matriz[zd->x4][zd->y4] = 0;
	zd->y1++;
	zd->y2++;
	zd->y3++;
	zd->y4++;
	matriz[zd->x1][zd->y1] = 1;
	matriz[zd->x2][zd->y2] = 1;
	matriz[zd->x3][zd->y3] = 1;
	matriz[zd->x4][zd->y4] = 1;
}

int Pode_Rotacionar_ZD(bloco* zd, int matriz[18][8]){
	if(zd->orientacao == 0){
		if(zd->x1 > 4 && zd->x4 < 17){
			if(matriz[zd->x3 - 1][zd->y3 - 1] == 0 && matriz[zd->x3 + 1][zd->y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(zd->y3 < 7){
			if(matriz[zd->x3 - 1][zd->y3 + 1] == 0 && matriz[zd->x3 - 1][zd->y3] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_ZD(bloco* zd, int matriz[18][8]){
	matriz[zd->x1][zd->y1] = 0;
	matriz[zd->x2][zd->y2] = 0;
	matriz[zd->x3][zd->y3] = 0;
	matriz[zd->x4][zd->y4] = 0;
	if(zd->orientacao == 0){
		zd->y1 -= 2;
		zd->x2++;
		zd->y2--;
		zd->x4++;
		zd->y4++; 
		zd->orientacao = 1;	
	}
	else{
		zd->y1 += 2;
		zd->x2--;
		zd->y2++;
		zd->x4--;
		zd->y4--; 
		zd->orientacao = 0;
	}
	matriz[zd->x1][zd->y1] = 1;
	matriz[zd->x2][zd->y2] = 1;
	matriz[zd->x3][zd->y3] = 1;
	matriz[zd->x4][zd->y4] = 1;
}

int AtrasarTela_ZD(bloco* zd, int matriz[18][8], int tempo_descida){
	int i,j;
	for(i = 0; i < tempo_descida; i++){
		MostrarTela(matriz);
		if(PORTAbits.RA2){
			semente += 9;
			if(Pode_Deslocar_Baixo_ZD(zd,matriz)){
				for(j = 0; j < tempo_descida_forcada; j++){MostrarTela(matriz);}
				Deslocar_Baixo_ZD(zd,matriz);
			}
		}
		if(PORTAbits.RA3){
			semente *= 10;
			if(Pode_Deslocar_Esquerda_ZD(zd,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_ZD(zd,matriz)){Deslocar_Baixo_ZD(zd,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Esquerda_ZD(zd,matriz);
			}
		}
		if(PORTAbits.RA1){
			semente /= 3;
			if(Pode_Deslocar_Direita_ZD(zd,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_ZD(zd,matriz)){Deslocar_Baixo_ZD(zd,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Direita_ZD(zd,matriz);
			}
		}
		if(PORTAbits.RA0){
			semente -= 12;
			if(Pode_Rotacionar_ZD(zd,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_ZD(zd,matriz)){Deslocar_Baixo_ZD(zd,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Rotacionar_ZD(zd,matriz);
			}
		}
	}
}

//funcoes do bloco t

void Gerar_T(bloco* t,int matriz[18][8]){
	matriz[0][6] = 1;
	matriz[1][5] = 1;
	matriz[1][6] = 1;
	matriz[1][7] = 1;
	t->x1 = 0;
	t->y1 = 6;
	t->x2 = 1;
	t->y2 = 5;
	t->x3 = 1;
	t->y3 = 6;
	t->x4 = 1;
	t->y4 = 7;
	t->orientacao = 0;
}

int Pode_Deslocar_Baixo_T(bloco* t,int matriz[18][8]){
	if(t->orientacao == 0){
		if(t->x3 < 17){
			if(matriz[t->x2 + 1][t->y2] == 0 && matriz[t->x3 + 1][t->y3] == 0 && matriz[t->x4 + 1][t->y4] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 1){
		if(t->x4 < 17){
			if(matriz[t->x4 + 1][t->y4] == 0 && matriz[t->x1 + 1][t->y1] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 2){
		if(t->x1 < 17){
			if(matriz[t->x4 + 1][t->y4] == 0 && matriz[t->x1 + 1][t->y1] == 0 && matriz[t->x2 + 1][t->y2] == 0){
				return 1;
			}
		}
	}
	else{
		if(t->x2 < 17){
			if(matriz[t->x2 + 1][t->y2] == 0 && matriz[t->x1 + 1][t->y1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Baixo_T(bloco* t, int matriz[18][8]){
	matriz[t->x1][t->y1] = 0;
	matriz[t->x2][t->y2] = 0;
	matriz[t->x3][t->y3] = 0;
	matriz[t->x4][t->y4] = 0;
	t->x1++;
	t->x2++;
	t->x3++;
	t->x4++;
	matriz[t->x1][t->y1] = 1;
	matriz[t->x2][t->y2] = 1;
	matriz[t->x3][t->y3] = 1;
	matriz[t->x4][t->y4] = 1;
}

int Pode_Deslocar_Esquerda_T(bloco* t,int matriz[18][8]){
	if(t->orientacao == 0){
		if(t->y2 > 0){
			if(matriz[t->x1][t->y1 - 1] == 0 && matriz[t->x2][t->y2 - 1] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 1){
		if(t->y3 > 0){
			if(matriz[t->x2][t->y2 - 1] == 0 && matriz[t->x3][t->y3 - 1] == 0 && matriz[t->x4][t->y4 - 1] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 2){
		if(t->y4 > 0){
			if(matriz[t->x4][t->y4 - 1] == 0 && matriz[t->x1][t->y1 - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(t->y1 > 0){
			if(matriz[t->x4][t->y4 - 1] == 0 && matriz[t->x1][t->y1 - 1] == 0 && matriz[t->x2][t->y2 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Esquerda_T(bloco* t,int matriz[18][8]){
	matriz[t->x1][t->y1] = 0;
	matriz[t->x2][t->y2] = 0;
	matriz[t->x3][t->y3] = 0;
	matriz[t->x4][t->y4] = 0;
	t->y1--;
	t->y2--;
	t->y3--;
	t->y4--;
	matriz[t->x1][t->y1] = 1;
	matriz[t->x2][t->y2] = 1;
	matriz[t->x3][t->y3] = 1;
	matriz[t->x4][t->y4] = 1;
}

int Pode_Deslocar_Direita_T(bloco* t,int matriz[18][8]){
	if(t->orientacao == 0){
		if(t->y4 < 7){
			if(matriz[t->x1][t->y1 + 1] == 0 && matriz[t->x4][t->y4 + 1] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 1){
		if(t->y1 < 7){
			if(matriz[t->x2][t->y2 + 1] == 0 && matriz[t->x1][t->y1 + 1] == 0 && matriz[t->x4][t->y4 + 1] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 2){
		if(t->y2 < 7){
			if(matriz[t->x2][t->y2 + 1] == 0 && matriz[t->x1][t->y1 + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(t->y3 < 7){
			if(matriz[t->x4][t->y4 + 1] == 0 && matriz[t->x3][t->y3 + 1] == 0 && matriz[t->x2][t->y2 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Direita_T(bloco* t,int matriz[18][8]){
	matriz[t->x1][t->y1] = 0;
	matriz[t->x2][t->y2] = 0;
	matriz[t->x3][t->y3] = 0;
	matriz[t->x4][t->y4] = 0;
	t->y1++;
	t->y2++;
	t->y3++;
	t->y4++;
	matriz[t->x1][t->y1] = 1;
	matriz[t->x2][t->y2] = 1;
	matriz[t->x3][t->y3] = 1;
	matriz[t->x4][t->y4] = 1;
}

int Pode_Rotacionar_T(bloco* t,int matriz[18][8]){
	if(t->orientacao == 0){
		if(t->x3 < 17){
			if(matriz[t->x3 + 1][t->y3] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 1){
		if(t->y3 > 0){
			if(matriz[t->x3][t->y3 - 1] == 0){
				return 1;
			}
		}
	}
	else if(t->orientacao == 2){
		if(t->x3 > 2){
			if(matriz[t->x3 - 1][t->y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(t->y3 < 7){
			if(matriz[t->x3][t->y3 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_T(bloco* t,int matriz[18][8]){
	matriz[t->x1][t->y1] = 0;
	matriz[t->x2][t->y2] = 0;
	matriz[t->x3][t->y3] = 0;
	matriz[t->x4][t->y4] = 0;
	if(t->orientacao == 0){
		t->x1++;
		t->y1++;
		t->x2--;
		t->y2++;
		t->x4++;
		t->y4--;
		t->orientacao = 1;
	}
	else if(t->orientacao == 1){
		t->x1++;
		t->y1--;
		t->x2++;
		t->y2++;
		t->x4--;
		t->y4--;
		t->orientacao = 2;
	}
	else if(t->orientacao == 2){
		t->x1--;
		t->y1--;
		t->x2++;
		t->y2--;
		t->x4--;
		t->y4++;
		t->orientacao = 3;
	}
	else{
		t->x1--;
		t->y1++;
		t->x2--;
		t->y2--;
		t->x4++;
		t->y4++;
		t->orientacao = 0;
	}
	matriz[t->x1][t->y1] = 1;
	matriz[t->x2][t->y2] = 1;
	matriz[t->x3][t->y3] = 1;
	matriz[t->x4][t->y4] = 1;
}

int AtrasarTela_T(bloco* t, int matriz[18][8], int tempo_descida){
	int i,j;
	for(i = 0; i < tempo_descida; i++){
		MostrarTela(matriz);
		if(PORTAbits.RA2){
			semente *= 4;
			if(Pode_Deslocar_Baixo_T(t,matriz)){
				for(j = 0; j < tempo_descida_forcada; j++){MostrarTela(matriz);}
				Deslocar_Baixo_T(t,matriz);
			}
		}
		if(PORTAbits.RA3){
			semente += 17;
			if(Pode_Deslocar_Esquerda_T(t,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_T(t,matriz)){Deslocar_Baixo_T(t,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Esquerda_T(t,matriz);
			}
		}
		if(PORTAbits.RA1){
			semente -= 14;
			if(Pode_Deslocar_Direita_T(t,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_T(t,matriz)){Deslocar_Baixo_T(t,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Direita_T(t,matriz);
			}
		}
		if(PORTAbits.RA0){
			semente += 5;
			if(Pode_Rotacionar_T(t,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_T(t,matriz)){Deslocar_Baixo_T(t,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Rotacionar_T(t,matriz);
			}
		}
	}
}

//funcoes do bloco L esquerda

void Gerar_LE(bloco* le,int matriz[18][8]){
	matriz[0][1] = 1;
	matriz[1][1] = 1;
	matriz[1][2] = 1;
	matriz[1][3] = 1;
	le->x1 = 0;
	le->y1 = 1;
	le->x2 = 1;
	le->y2 = 1;
	le->x3 = 1;
	le->y3 = 2;
	le->x4 = 1;
	le->y4 = 3;
	le->orientacao = 0;
}

int Pode_Deslocar_Baixo_LE(bloco* le,int matriz[18][8]){
	if(le->orientacao == 0){
		if(le->x3 < 17){
			if(matriz[le->x2 + 1][le->y2] == 0 && matriz[le->x3 + 1][le->y3] == 0 && matriz[le->x4 + 1][le->y4] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 1){
		if(le->x4 < 17){
			if(matriz[le->x4 + 1][le->y4] == 0 && matriz[le->x1 + 1][le->y1] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 2){
		if(le->x1 < 17){
			if(matriz[le->x4 + 1][le->y4] == 0 && matriz[le->x1 + 1][le->y1] == 0 && matriz[le->x3 + 1][le->y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(le->x2 < 17){
			if(matriz[le->x2 + 1][le->y2] == 0 && matriz[le->x1 + 1][le->y1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Baixo_LE(bloco* le, int matriz[18][8]){
	matriz[le->x1][le->y1] = 0;
	matriz[le->x2][le->y2] = 0;
	matriz[le->x3][le->y3] = 0;
	matriz[le->x4][le->y4] = 0;
	le->x1++;
	le->x2++;
	le->x3++;
	le->x4++;
	matriz[le->x1][le->y1] = 1;
	matriz[le->x2][le->y2] = 1;
	matriz[le->x3][le->y3] = 1;
	matriz[le->x4][le->y4] = 1;
}

int Pode_Deslocar_Esquerda_LE(bloco* le,int matriz[18][8]){
	if(le->orientacao == 0){
		if(le->y2 > 0){
			if(matriz[le->x1][le->y1 - 1] == 0 && matriz[le->x2][le->y2 - 1] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 1){
		if(le->y3 > 0){
			if(matriz[le->x2][le->y2 - 1] == 0 && matriz[le->x3][le->y3 - 1] == 0 && matriz[le->x4][le->y4 - 1] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 2){
		if(le->y4 > 0){
			if(matriz[le->x4][le->y4 - 1] == 0 && matriz[le->x1][le->y1 - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(le->y1 > 0){
			if(matriz[le->x4][le->y4 - 1] == 0 && matriz[le->x1][le->y1 - 1] == 0 && matriz[le->x3][le->y3 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Esquerda_LE(bloco* le,int matriz[18][8]){
	matriz[le->x1][le->y1] = 0;
	matriz[le->x2][le->y2] = 0;
	matriz[le->x3][le->y3] = 0;
	matriz[le->x4][le->y4] = 0;
	le->y1--;
	le->y2--;
	le->y3--;
	le->y4--;
	matriz[le->x1][le->y1] = 1;
	matriz[le->x2][le->y2] = 1;
	matriz[le->x3][le->y3] = 1;
	matriz[le->x4][le->y4] = 1;
}

int Pode_Deslocar_Direita_LE(bloco* le,int matriz[18][8]){
	if(le->orientacao == 0){
		if(le->y4 < 7){
			if(matriz[le->x1][le->y1 + 1] == 0 && matriz[le->x4][le->y4 + 1] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 1){
		if(le->y1 < 7){
			if(matriz[le->x3][le->y3 + 1] == 0 && matriz[le->x1][le->y1 + 1] == 0 && matriz[le->x4][le->y4 + 1] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 2){
		if(le->y2 < 7){
			if(matriz[le->x2][le->y2 + 1] == 0 && matriz[le->x1][le->y1 + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(le->y3 < 7){
			if(matriz[le->x4][le->y4 + 1] == 0 && matriz[le->x3][le->y3 + 1] == 0 && matriz[le->x2][le->y2 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Direita_LE(bloco* le,int matriz[18][8]){
	matriz[le->x1][le->y1] = 0;
	matriz[le->x2][le->y2] = 0;
	matriz[le->x3][le->y3] = 0;
	matriz[le->x4][le->y4] = 0;
	le->y1++;
	le->y2++;
	le->y3++;
	le->y4++;
	matriz[le->x1][le->y1] = 1;
	matriz[le->x2][le->y2] = 1;
	matriz[le->x3][le->y3] = 1;
	matriz[le->x4][le->y4] = 1;
}

int Pode_Rotacionar_LE(bloco* le,int matriz[18][8]){
	if(le->orientacao == 0){
		if(le->x3 < 17){
			if(matriz[le->x3 + 1][le->y3] == 0 && matriz[le->x3 - 1][le->y3] == 0 && matriz[le->x3 - 1][le->y3 + 1] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 1){
		if(le->y3 > 0){
			if(matriz[le->x3][le->y3 - 1] == 0 && matriz[le->x3][le->y3 + 1] == 0 && matriz[le->x3 + 1][le->y3 + 1] == 0){
				return 1;
			}
		}
	}
	else if(le->orientacao == 2){
		if(le->x3 > 2){
			if(matriz[le->x3 + 1][le->y3] == 0 && matriz[le->x3 + 1][le->y3 - 1] == 0 && matriz[le->x3 - 1][le->y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(le->y3 < 7){
			if(matriz[le->x3][le->y3 - 1] == 0 && matriz[le->x3][le->y3 + 1] == 0 && matriz[le->x3 - 1][le->y3 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_LE(bloco* le,int matriz[18][8]){
	matriz[le->x1][le->y1] = 0;
	matriz[le->x2][le->y2] = 0;
	matriz[le->x3][le->y3] = 0;
	matriz[le->x4][le->y4] = 0;
	if(le->orientacao == 0){
		le->y1+=2;
		le->x2--;
		le->y2++;
		le->x4++;
		le->y4--;
		le->orientacao = 1;
	}
	else if(le->orientacao == 1){
		le->x1+=2;
		le->x2++;
		le->y2++;
		le->x4--;
		le->y4--;
		le->orientacao = 2;
	}
	else if(le->orientacao == 2){
		le->y1-=2;
		le->x2++;
		le->y2--;
		le->x4--;
		le->y4++;
		le->orientacao = 3;
	}
	else{
		le->x1-=2;
		le->x2--;
		le->y2--;
		le->x4++;
		le->y4++;
		le->orientacao = 0;
	}
	matriz[le->x1][le->y1] = 1;
	matriz[le->x2][le->y2] = 1;
	matriz[le->x3][le->y3] = 1;
	matriz[le->x4][le->y4] = 1;
}

int AtrasarTela_LE(bloco* le, int matriz[18][8], int tempo_descida){
	int i,j;
	for(i = 0; i < tempo_descida; i++){
		MostrarTela(matriz);
		if(PORTAbits.RA2){
			semente += 2;
			if(Pode_Deslocar_Baixo_LE(le,matriz)){
				for(j = 0; j < tempo_descida_forcada; j++){MostrarTela(matriz);}
				Deslocar_Baixo_LE(le,matriz);
			}
		}
		if(PORTAbits.RA3){
			semente *= 6;
			if(Pode_Deslocar_Esquerda_LE(le,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_LE(le,matriz)){Deslocar_Baixo_LE(le,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Esquerda_LE(le,matriz);
			}
		}
		if(PORTAbits.RA1){
			semente /= 8;
			if(Pode_Deslocar_Direita_LE(le,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_LE(le,matriz)){Deslocar_Baixo_LE(le,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Direita_LE(le,matriz);
			}
		}
		if(PORTAbits.RA0){
			semente += 9;
			if(Pode_Rotacionar_LE(le,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_LE(le,matriz)){Deslocar_Baixo_LE(le,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Rotacionar_LE(le,matriz);
			}
		}
	}
}

//funcoes do bloco L direita

void Gerar_LD(bloco* ld,int matriz[18][8]){
	matriz[0][7] = 1;
	matriz[1][7] = 1;
	matriz[1][6] = 1;
	matriz[1][5] = 1;
	ld->x1 = 0;
	ld->y1 = 7;
	ld->x2 = 1;
	ld->y2 = 7;
	ld->x3 = 1;
	ld->y3 = 6;
	ld->x4 = 1;
	ld->y4 = 5;
	ld->orientacao = 0;
}

int Pode_Deslocar_Baixo_LD(bloco* ld,int matriz[18][8]){
	if(ld->orientacao == 0){
		if(ld->x3 < 17){
			if(matriz[ld->x2 + 1][ld->y2] == 0 && matriz[ld->x3 + 1][ld->y3] == 0 && matriz[ld->x4 + 1][ld->y4] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 1){
		if(ld->x1 < 17){
			if(matriz[ld->x2 + 1][ld->y2] == 0 && matriz[ld->x1 + 1][ld->y1] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 2){
		if(ld->x1 < 17){
			if(matriz[ld->x4 + 1][ld->y4] == 0 && matriz[ld->x1 + 1][ld->y1] == 0 && matriz[ld->x3 + 1][ld->y3] == 0){
				return 1;
			}
		}
	}
	else{
		if(ld->x4 < 17){
			if(matriz[ld->x4 + 1][ld->y4] == 0 && matriz[ld->x1 + 1][ld->y1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Baixo_LD(bloco* ld, int matriz[18][8]){
	matriz[ld->x1][ld->y1] = 0;
	matriz[ld->x2][ld->y2] = 0;
	matriz[ld->x3][ld->y3] = 0;
	matriz[ld->x4][ld->y4] = 0;
	ld->x1++;
	ld->x2++;
	ld->x3++;
	ld->x4++;
	matriz[ld->x1][ld->y1] = 1;
	matriz[ld->x2][ld->y2] = 1;
	matriz[ld->x3][ld->y3] = 1;
	matriz[ld->x4][ld->y4] = 1;
}

int Pode_Deslocar_Esquerda_LD(bloco* ld,int matriz[18][8]){
	if(ld->orientacao == 0){
		if(ld->y4 > 0){
			if(matriz[ld->x1][ld->y1 - 1] == 0 && matriz[ld->x4][ld->y4 - 1] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 1){
		if(ld->y3 > 0){
			if(matriz[ld->x2][ld->y2 - 1] == 0 && matriz[ld->x3][ld->y3 - 1] == 0 && matriz[ld->x4][ld->y4 - 1] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 2){
		if(ld->y2 > 0){
			if(matriz[ld->x2][ld->y2 - 1] == 0 && matriz[ld->x1][ld->y1 - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(ld->y1 > 0){
			if(matriz[ld->x4][ld->y4 - 1] == 0 && matriz[ld->x1][ld->y1 - 1] == 0 && matriz[ld->x3][ld->y3 - 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Esquerda_LD(bloco* ld,int matriz[18][8]){
	matriz[ld->x1][ld->y1] = 0;
	matriz[ld->x2][ld->y2] = 0;
	matriz[ld->x3][ld->y3] = 0;
	matriz[ld->x4][ld->y4] = 0;
	ld->y1--;
	ld->y2--;
	ld->y3--;
	ld->y4--;
	matriz[ld->x1][ld->y1] = 1;
	matriz[ld->x2][ld->y2] = 1;
	matriz[ld->x3][ld->y3] = 1;
	matriz[ld->x4][ld->y4] = 1;
}

int Pode_Deslocar_Direita_LD(bloco* ld,int matriz[18][8]){
	if(ld->orientacao == 0){
		if(ld->y1 < 7){
			if(matriz[ld->x1][ld->y1 + 1] == 0 && matriz[ld->x2][ld->y2 + 1] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 1){
		if(ld->y1 < 7){
			if(matriz[ld->x3][ld->y3 + 1] == 0 && matriz[ld->x1][ld->y1 + 1] == 0 && matriz[ld->x4][ld->y4 + 1] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 2){
		if(ld->y4 < 7){
			if(matriz[ld->x4][ld->y4 + 1] == 0 && matriz[ld->x1][ld->y1 + 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(ld->y3 < 7){
			if(matriz[ld->x4][ld->y4 + 1] == 0 && matriz[ld->x3][ld->y3 + 1] == 0 && matriz[ld->x2][ld->y2 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Deslocar_Direita_LD(bloco* ld,int matriz[18][8]){
	matriz[ld->x1][ld->y1] = 0;
	matriz[ld->x2][ld->y2] = 0;
	matriz[ld->x3][ld->y3] = 0;
	matriz[ld->x4][ld->y4] = 0;
	ld->y1++;
	ld->y2++;
	ld->y3++;
	ld->y4++;
	matriz[ld->x1][ld->y1] = 1;
	matriz[ld->x2][ld->y2] = 1;
	matriz[ld->x3][ld->y3] = 1;
	matriz[ld->x4][ld->y4] = 1;
}

int Pode_Rotacionar_LD(bloco* ld,int matriz[18][8]){
	if(ld->orientacao == 0){
		if(ld->x3 < 17){
			if(matriz[ld->x3 + 1][ld->y3] == 0 && matriz[ld->x3 + 1][ld->y3 + 1] == 0 && matriz[ld->x3 - 1][ld->y3] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 1){
		if(ld->y3 > 0){
			if(matriz[ld->x3][ld->y3 - 1] == 0 && matriz[ld->x3 + 1][ld->y3 - 1] == 0 && matriz[ld->x3][ld->y3 + 1] == 0){
				return 1;
			}
		}
	}
	else if(ld->orientacao == 2){
		if(ld->x3 > 2){
			if(matriz[ld->x3 - 1][ld->y3] == 0 && matriz[ld->x3 + 1][ld->y3] == 0 && matriz[ld->x3 - 1][ld->y3 - 1] == 0){
				return 1;
			}
		}
	}
	else{
		if(ld->y3 < 7){
			if(matriz[ld->x3][ld->y3 - 1] == 0 && matriz[ld->x3][ld->y3 + 1] == 0 && matriz[ld->x3 - 1][ld->y3 + 1] == 0){
				return 1;
			}
		}
	}
	return 0;
}

void Rotacionar_LD(bloco* ld,int matriz[18][8]){
	matriz[ld->x1][ld->y1] = 0;
	matriz[ld->x2][ld->y2] = 0;
	matriz[ld->x3][ld->y3] = 0;
	matriz[ld->x4][ld->y4] = 0;
	if(ld->orientacao == 0){
		ld->x1+=2;
		ld->x2++;
		ld->y2--;
		ld->x4--;
		ld->y4++;
		ld->orientacao = 1;
	}
	else if(ld->orientacao == 1){
		ld->y1-=2;
		ld->x2--;
		ld->y2--;
		ld->x4++;
		ld->y4++;
		ld->orientacao = 2;
	}
	else if(ld->orientacao == 2){
		ld->x1-=2;
		ld->x2--;
		ld->y2++;
		ld->x4++;
		ld->y4--;
		ld->orientacao = 3;
	}
	else{
		ld->y1+=2;
		ld->x2++;
		ld->y2++;
		ld->x4--;
		ld->y4--;
		ld->orientacao = 0;
	}
	matriz[ld->x1][ld->y1] = 1;
	matriz[ld->x2][ld->y2] = 1;
	matriz[ld->x3][ld->y3] = 1;
	matriz[ld->x4][ld->y4] = 1;
}

int AtrasarTela_LD(bloco* ld, int matriz[18][8], int tempo_descida){
	int i,j;
	for(i = 0; i < tempo_descida; i++){
		MostrarTela(matriz);
		if(PORTAbits.RA2){
			semente *= 4;
			if(Pode_Deslocar_Baixo_LD(ld,matriz)){
				for(j = 0; j < tempo_descida_forcada; j++){MostrarTela(matriz);}
				Deslocar_Baixo_LD(ld,matriz);
			}
		}
		if(PORTAbits.RA3){
			semente -= 10;
			if(Pode_Deslocar_Esquerda_LD(ld,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_LD(ld,matriz)){Deslocar_Baixo_LD(ld,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Esquerda_LD(ld,matriz);
			}
		}
		if(PORTAbits.RA1){
			semente /= 5;
			if(Pode_Deslocar_Direita_LD(ld,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_LD(ld,matriz)){Deslocar_Baixo_LD(ld,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Deslocar_Direita_LD(ld,matriz);
			}
		}
		if(PORTAbits.RA0){
			semente *= 13;
			if(Pode_Rotacionar_LD(ld,matriz)){
				for(j = 0; j < 20; j++){
					i++;
					if(i >= tempo_descida){
						i = 0;
						if(Pode_Deslocar_Baixo_LD(ld,matriz)){Deslocar_Baixo_LD(ld,matriz);}
						else{return 0;}
					}
					MostrarTela(matriz);
				}
				Rotacionar_LD(ld,matriz);
			}
		}
	}
}

