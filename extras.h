#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <math.h>

// DEIXAR AS FUNCOES EXTRAS AQUI PRA FICAR BONITOSO

struct elemento{
	int pecas;
	struct elemento *prox; 
};

typedef struct elemento Elem; 

Pilha *** criando_pilha(Pilha ***pi,int tamanho){
	int i,j;
	for(i=0;i<tamanho;i++){
		pi[i] =(Pilha**)malloc(tamanho*sizeof(Pilha*));
		for(j=0;j<tamanho;j++){
			pi[i][j] = criar();
		}
	}
	return pi;
}

int tam_cadaListaDePecas(Lista *li,int peca){
	int cont =0;
	if(li == NULL){
		return 0;
	}

	struct elemento *aux;
	aux = *li;

	while(aux != NULL){
		if(aux->pecas == peca){
			cont++;
		}
		aux = aux->prox;
	}
	
	return cont;
}

int topo(Pilha* pi){
	if((*pi)==NULL){
		return 3;
	}
	else if((*pi)->pecas == 0){
		return 2;
	}

	if((*pi)->pecas == 1 || (*pi)->pecas == 2){
		return 1;
	}
	else{										
	    return 0;
	}
}
			
int valida (int linha,int coluna,int peca,Pilha ***pi,Lista * li){
	//Se peca == teto(1) só pode ser colocada se antes tiver andares
	//Se peca == parque (2) só pode ser colocado se tiver vazio
    //Se peca == andar (0) só pode ser colocado se antes estiver vazio ou com andares 
	int a;
	if(linha == 0 || linha == 1 || linha == 2 || linha == 3 || linha == 4){
		 if(coluna == 0 || coluna == 1 || coluna == 2 || coluna == 3 || coluna == 4){
			if(peca == 0 || peca == 1 || peca == 2){
				a = 1;		
			}
		}
	}

	if(a==1){
		if(tam_cadaListaDePecas(li,peca)==0){
			return 0;
		}
		else if(peca == 0){ // andar
			if(topo(pi[linha][coluna])==3){
				return 1;
			}
			else if(topo(pi[linha][coluna])==1){
				return 0;
			}else{
				return 1;
			}  
		}
		else if(peca == 1){ //teto
		    if(topo (pi[linha][coluna]) == 3){
				return 0;
			}
			else if(topo(pi[linha][coluna])==1){
				return 0;
			}
			else{
				return 1;
			}
		}
		else if(peca == 2){ //parque
			if(topo(pi[linha][coluna]) == 3){
				return 1;
			}
			else if(topo(pi[linha][coluna])==2){
				return 0;
			}
			else if(topo(pi[linha][coluna])==1){
				return 0;
			}
			else{
				return 1;
			}
		}
	}
	else{
		 return 0;
	}      
}
	
int tam_deCadaPilha(Pilha* pi){
	int cont=0;
	if(pi == NULL){
		return 0;
	}
	else{
		Elem *aux;
		aux = *pi;

		while(aux != NULL){
			cont++;
			aux = aux->prox;
		}
	}
	return cont;
}

void imprimir_tabuleiro(Pilha ***pi,int tam){
	int i=0,j,k,l=0,m;
	printf("         ");
	while(i<=tam*2){ 
		if(i == tam){
			printf("OESTE    ");
		} 

		if(i%2==0){ 
			for(j=0;j<tam;j++){
				printf("+---");//Formando as linhas
			}
			printf("+");
		}
		else{
			for(j=0;j<tam*2;j++){
				if(j%2==0){
					if(i==tam && j==tam){
						printf("|");
					}
					else{
						l = floor(i/2);
						m = floor(j/2);
						if(tam_deCadaPilha(pi[l][m])==0){
							printf("|   ");//Formando as coluna
						}
						else if(topo(pi[l][m])== 1){
							printf("|[%d]",tam_deCadaPilha(pi[l][m]));
						}
						else {
							printf("| %d ",tam_deCadaPilha(pi[l][m]));
						}
					}
				}
				if(j==(tam*2)-1){
					k = floor(i/2);
					printf("| %c", k+97);

					if((k+97)==99){
						printf("     LESTE");
					}
				}
			} 
		}

		printf("\n");
		if(i != tam-1){
			printf("         ");
		}

		if(i==tam*2){
			printf("  ");
			for(k=1;k<=tam;k++){
				printf("%d   ",k);

			}
		}

		i++;
	}

	printf("\n\n                  SUL\n");
	printf("\n");
}

void menu_pecas(Lista* componentes,int jogador){
	int a,b,c;
	a = tam_cadaListaDePecas(componentes,0);
	b = tam_cadaListaDePecas(componentes,2);
	c = tam_cadaListaDePecas(componentes,1);
	if(jogador == 1){
		printf("Vez do jogador com a Vista do Sul !\nEscolha qual peca deseja jogar (0 = Andar [%d], 2 = Parque [%d], 1 = Teto [%d])",a,b,c);
	}
	if(jogador == 2){
		printf("Vez do jogador com a Vista do Oeste !\nEscolha qual peca deseja jogar (0 = Andar [%d], 2 = Parque [%d], 1 = Teto [%d])",a,b,c);
	}
	if(jogador == 3){
		printf("Vez do jogador com a Vista do Norte !\nEscolha qual peca deseja jogar (0 = Andar [%d], 2 = Parque [%d], 1 = Teto [%d])",a,b,c);
	}
	if(jogador == 4){
		printf("Vez do jogador com a Vista do Leste !\nEscolha qual peca deseja jogar (0 = Andar [%d], 2 = Parque [%d], 1 = Teto [%d])",a,b,c);
	}
}

int trocar(char letra){
	if(letra == 'a'){
		return 1;
	}
	else if(letra == 'b'){
		return 2;
	}
	else if(letra == 'c'){
		return 3;
	}
	else if(letra == 'd'){
		return 4;
	}
	else if(letra == 'e'){
		return 5;
	}
	else{
		return 0;
	}
}

int fim(Lista *componente1, Lista *componente2, Lista *componente3, Lista *componente4){
	if((tam_cadaListaDePecas(componente1,0)) == 0){
		printf("Pecas de andar SUL acabaram\n");
		return 1;
	}
	else if ((tam_cadaListaDePecas(componente2,0)) == 0){
		printf("Pecas de andar OESTE acabaram\n");
		return 1;
	}
	else if ((tam_cadaListaDePecas(componente3,0)) == 0){
		printf("Pecas de andar NORTE acabaram\n");
		return 1;
	}
	else if((tam_cadaListaDePecas(componente4,0)) == 0){
		printf("Pecas de andar LESTE acabaram\n");
		return 1;
	}
	else{
		return 0;
	}
}

void imprimir_pecinha(int x){
	if(x==0){
		printf("           ");
	}
	else if(x==1){
		printf("     #     ");
	}
	else if(x==2){
		printf("    ###    ");
	}
	else if(x==3){
		printf("   #####   ");
	}
	else if(x==4){
		printf("  #######  ");
	}
	else if(x==5){
		printf(" ######### ");
	}
}

int maiorPilha(Pilha *** pi){
	int i,j,maior=0;
	for(j=0;j<=4;j++){
		for(i=0;i<=4;i++){
			if(tam_deCadaPilha(pi[i][j])  > maior){ 
				maior = tam_deCadaPilha(pi[i][j]);	
			}
		}
	}
	return maior;
}

void vista(Pilha*** pi,int jogador){
	int i,j,x=0,cont=0;
	int maior;
	maior = maiorPilha(pi);
	if(jogador==1){
		printf("\n                  * VISTA DO JOGADOR SUL * \n\n");
		while(maior != 0){ //Vista do Sul
			for(j=0;j<=4;j++){
				for(i=0;i<=4;i++){
					cont++;
					if(tam_deCadaPilha(pi[i][j])>=maior){
						x = cont;
			   		 }
				}
				imprimir_pecinha(x);
				x = 0;
				cont = 0;
			}
	    maior--;
	    printf("\n");
		}
	}
	if(jogador==2){
		printf("\n                  * VISTA DO JOGADOR OESTE * \n\n");
		while(maior != 0){ //Vista do Oeste
			for(j=0;j<=4;j++){
				for(i=0;i<=4;i++){
					cont++;
					if(tam_deCadaPilha(pi[j][4-i])>=maior){
						x = cont;
			   		 }
				}
				imprimir_pecinha(x);
				x = 0;
				cont = 0;
			}
	    maior--;
	    printf("\n");
		}
	}
	if(jogador==3){
		printf("\n                  * VISTA DO JOGADOR NORTE * \n\n");
			while(maior != 0){ //Vista do Norte
			for(j=0;j<=4;j++){
				for(i=0;i<=4;i++){
					cont++;
					if(tam_deCadaPilha(pi[4-i][4-j])>=maior){
						x = cont;
			   		}
				}
				imprimir_pecinha(x);
				x = 0;
				cont = 0;
			}
	    maior--;
	    printf("\n");
		}
	}
	if(jogador==4){
		printf("\n                  * VISTA DO JOGADOR LESTE * \n\n");
		while(maior != 0){ //Vista do Leste
			for(j=0;j<=4;j++){
				for(i=0;i<=4;i++){
					cont++;
					if(tam_deCadaPilha(pi[4-j][i])>=maior){
						x = cont;
			   		}
				}
				imprimir_pecinha(x);
				x = 0;
				cont = 0;
			}
	    maior--;
	    printf("\n");
		}
	}
	printf("----------------------------------------------------------------");
}

int vitoria(Pilha ***pi){
	int i,j,x=0,vencedor;
	int maior[4];
	int cont[4];

	for(i=0;i<=4;i++){
		maior[i] = 0;
		cont[i] = 0;
	}

	for(j=0;j<=4;j++){
		maior[0]=0;
		maior[1]=0;
		maior[2]=0;
		maior[3]=0;
		for(i=4;i>=0;i--){
			if(tam_deCadaPilha(pi[i][j])  > maior[0]){ //JOGADOR SUL
				maior[0] = tam_deCadaPilha(pi[i][j]);
				cont[0]++;
			}
			if(tam_deCadaPilha(pi[j][4-i])  > maior[1]){ // JOGADOR OESTE
				maior[1] = tam_deCadaPilha(pi[j][4-i]);
				cont[1]++;
			}
			if(tam_deCadaPilha(pi[4-i][4-j])  > maior[2]){ // JOGADOR NORTE
				maior[2] = tam_deCadaPilha(pi[4-i][4-j]);
				cont[2]++;
			}
			if(tam_deCadaPilha(pi[j][i])  > maior[3]){ //JOGADOR LESTE
				maior[3] = tam_deCadaPilha(pi[j][i]);
				cont[3]++;
			}
		}
	}
	printf("PONTUACAO\n");
	printf("SUL: %d \n",cont[0]);
	printf("OESTE: %d \n",cont[1]);
	printf("NORTE: %d \n",cont[2]);
	printf("LESTE: %d\n",cont[3]);
	for(i=0;i<=4;i++){
		if(cont[i] > x){
			x = cont[i];
			vencedor = i;
		}
	}

	printf("O vencedor foi o jogador: ");
	if(vencedor==0){
		printf("Sul\n\n");
		vista(pi,1);
		printf("\nPONTUACAO:");
	    printf("%d",cont[0]);
	    printf("\n");
	    printf("Ate, espero que tenha gostado do jogo :)\n");
	}
	else if(vencedor==1){
		printf("Oeste\n\n");
		vista(pi,2);
		printf("\nPONTUACAO: ");
		printf("%d",cont[1]);
		printf("\n");
	    printf("Ate, espero que tenha gostado do jogo :)\n");
	}
	else if(vencedor==2){
		printf("Norte\n\n");
		vista(pi,3);
		printf("\nPONTUACAO: ");
		printf("%d",cont[2]);
		printf("\n");
	    printf("Ate, espero que tenha gostado do jogo :)\n");
	}
	else if(vencedor==3){
		printf("Leste\n\n");
		vista(pi,4);
		printf("\nPONTUACAO: ");
		printf("%d",cont[3]);
		printf("\n");
	    printf("Ate, espero que tenha gostado do jogo :)\n");
	}
	return 0;				
}

void apresentacao(){
	printf("------------------------------------------------------------------------------------\n");
	printf("                                  SKYLINERS                               \n\n");
	printf("Construa uma cidade. Proteja sua visão. Destrua a do seus oponentes.\n\n");
	printf("Em Skyliners, cada jogador é representado por um ponto cardeal. São\ndispostos inicialmente 6 andares de forma aleatoria e um parque fixo\nno centro do tabuleiro, os jogadores devem escolher a linha e a \ncoluna adequada, colocando a peca escolhida (seguindo as regras),\no jogo termina quando as pecas de andar para algum jogador acabarem,\nsendo que todos os jogadores devem ter a mesma quantidade de rodadas\nfeitas. Vence o jogador com a maior pontuacao (em caso de empate,\ne decidido pela ordem de jogada.)");
	printf("\n\nCOMPONENTES\n*12 Andares\n*1 Parque\n*2 Tetos\n\n");
	printf("REGRAS:\nAndar no chao ou em cima de outro andar, parque no chao e sem nada\nem cima,teto apenas em cima de andares.\n\n");
	printf("BREVE HISTORIA\nO bordgame foi criado por Gabriele Bubola e traduzido entre aspas, para\nsoftware por Roberto Pinheiro, transformando-o em um projeto para uso\neducacional e avaliativo dos alunos de AED.\n\n");
		printf("\n------------------------------------------------------------------------------------\n\n");
	printf("QUE O JOGO COMECE E A SORTE ESTEJA A SEU FAVOR!\n\n");
}
