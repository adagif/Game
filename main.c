#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "extras.h"
#include <time.h>

int main(){
	int i,cont,coluna,peca,sair,l,v,vista_doJogo; //1-SUL 2-OESTE 3-NORTE 4-LESTE
	char linha;
	int tam = 5;
	//Criando pilha do tabuleiro
	Pilha ***p;
	Pilha ***p2;
	p = criar_tabuleiro(tam);
	p2 = criando_pilha(p,tam);
	Lista *componentes1 = NULL;//SUL
	Lista *componentes2 = NULL;//OESTE
	Lista *componentes3 = NULL;//NORTE
	Lista *componentes4 = NULL;//LESTE

    componentes1 = criar();
	for(i=0;i<12;i++){
		inserir_l(componentes1,0);
	}
	for(i=13;i<=14;i++){
		inserir_l(componentes1,1);
	}
	for(i=14;i<15;i++){
		inserir_l(componentes1,2);
	}

	componentes2 = criar();
	for(i=0;i<12;i++){
		inserir_l(componentes2,0);
	}
	for(i=13;i<=14;i++){
		inserir_l(componentes2,1);
	}
	for(i=14;i<15;i++){
		inserir_l(componentes2,2);
	}

	componentes3 = criar();
	for(i=0;i<12;i++){
		inserir_l(componentes3,0);
	}
	for(i=13;i<=14;i++){
		inserir_l(componentes3,1);
	}
	for(i=14;i<15;i++){
		inserir_l(componentes3,2);
	}

	componentes4 = criar();
	for(i=0;i<12;i++){
		inserir_l(componentes4,0);
	}
	for(i=13;i<=14;i++){
		inserir_l(componentes4,1);
	}
	for(i=14;i<15;i++){
		inserir_l(componentes4,2);
	}

	int al1,al2;
	srand(time(NULL));
	for (i=0;i<6;++i){
		al1 = rand()%4 ;
		al2 = rand()%4 ;
		while(al1 == 0){
			al1 = rand()%4 ;
		}
		while(al2 == 0){
			al2 = rand()%4 ;
		}
		while(al1 == 2 && al2 == 2){
			al1 = rand()%4 ;
			while(al1 == 0){
				al1 = rand()%4 ;
			}
		}
		inserir(p2[al1][al2],0); //pecas aleatorias
	}

	inserir(p2[2][2],2);//parque central
	apresentacao();

	do{
		cont = 1;
		if(cont == 1){ //JOGADOR SUL
			printf("\n             | SKYLINERS |\n");
			printf("\n                 NORTE\n\n");
			imprimir_tabuleiro(p2,tam);
			menu_pecas(componentes1,cont);
			printf("\n");
			vista(p2,cont);

			printf("\n\nLinha:\n->");
			scanf("%s",&linha);
			while( getchar() != '\n' );
			printf("Coluna:\n->");
			scanf("%d",&coluna);
			while( getchar() != '\n' );
			printf("Peca:\n->");
			scanf("%d",&peca);
			while( getchar() != '\n' );

			l = trocar(linha);
			v = valida(l-1,coluna-1,peca,p2,componentes1);

			while(v == 0){
				printf("Nao e permitido! \n");

				printf("\nLinha:\n->");
				scanf("%s",&linha);
				while( getchar() != '\n' );
				printf("Coluna:\n->");
				scanf("%d",&coluna);
				while( getchar() != '\n' );
				printf("Peca:\n->");
				scanf("%d",&peca);
				while( getchar() != '\n' );

				l = trocar(linha);
				v = valida(l-1,coluna-1,peca,p2,componentes1);
			}
			inserir(p2[l-1][coluna-1],peca);
			removerMeio(componentes1,peca);
		}
		cont++;

		if(cont == 2){ //JOGADOR OESTE
			printf("\n             | SKYLINERS |\n");
			printf("\n                 NORTE\n\n");
			imprimir_tabuleiro(p2,tam); 
			menu_pecas(componentes2,cont);
			printf("\n");
			vista(p2,cont);

			printf("\n\nLinha:\n->");
			scanf("%s",&linha);
			while( getchar() != '\n' );
			printf("Coluna:\n->");
			scanf("%d",&coluna);
			while( getchar() != '\n' );
			printf("Peca:\n->");
			scanf("%d",&peca);
			while( getchar() != '\n' );

			l = trocar(linha);
			v = valida(l-1,coluna-1,peca,p2,componentes2);

			while(v == 0){
				printf("Nao e permitido! \n");

				printf("\nLinha:\n->");
				scanf("%s",&linha);
				printf("Coluna:\n->");
				scanf("%d",&coluna);
				printf("Peca:\n->");
				scanf("%d",&peca);

				l = trocar(linha);
				v = valida(l-1,coluna-1,peca,p2,componentes2);
			}
			inserir(p2[l-1][coluna-1],peca);
			removerMeio(componentes2,peca);
		}
		cont ++;

		if(cont == 3){ //JOGADOR NORTE	
			printf("\n             | SKYLINERS |\n");
			printf("\n                 NORTE\n\n");
			imprimir_tabuleiro(p2,tam);
			menu_pecas(componentes3,cont);
			printf("\n");
			vista(p2,cont);

			printf("\n\nLinha:\n->");
			scanf("%s",&linha);
			while( getchar() != '\n' );
			printf("Coluna:\n->");
			scanf("%d",&coluna);
			while( getchar() != '\n' );
			printf("Peca:\n->");
			scanf("%d",&peca);
			while( getchar() != '\n' );

			l = trocar(linha);
			v = valida(l-1,coluna-1,peca,p2,componentes3);

			while(v == 0){
				printf("Nao e permitido! \n");

				printf("\nLinha:\n->");
				scanf("%s",&linha);
				while( getchar() != '\n' );
				printf("Coluna:\n->");
				scanf("%d",&coluna);
				while( getchar() != '\n' );
				printf("Peca:\n->");
				scanf("%d",&peca);
				while( getchar() != '\n' );

				l = trocar(linha);
				v = valida(l-1,coluna-1,peca,p2,componentes3);
			}
			inserir(p2[l-1][coluna-1],peca);
			removerMeio(componentes3,peca);
		}
		cont++;

		if(cont == 4){ //JOGADOR LESTE
			printf("\n             | SKYLINERS |\n");
			printf("\n                 NORTE\n\n");
			imprimir_tabuleiro(p2,tam);
			menu_pecas(componentes4,cont);

			printf("\n");
			vista(p2,cont);

			printf("\n\nLinha:\n->");
			scanf("%s",&linha);
			while( getchar() != '\n' );
			printf("Coluna:\n->");
			scanf("%d",&coluna);
			while( getchar() != '\n' );
			printf("Peca:\n->");
			scanf("%d",&peca);
			while( getchar() != '\n' );

			l = trocar(linha);
			v = valida(l-1,coluna-1,peca,p2,componentes4);
			while(v == 0){
				printf("Nao e permitido! \n");

				printf("\nLinha:\n->");
				scanf("%s",&linha);
				while( getchar() != '\n' );
				printf("Coluna:\n->");
				scanf("%d",&coluna);
				while( getchar() != '\n' );
				printf("Peca:\n->");
				scanf("%d",&peca);
				while( getchar() != '\n' );

				l = trocar(linha);
				v = valida(l-1,coluna-1,peca,p2,componentes4);
			}
			inserir(p2[l-1][coluna-1],peca);
			removerMeio(componentes4,peca);
		}
		sair = fim(componentes1,componentes2,componentes3,componentes4);
		if(sair == 1){
			printf("\n             | SKYLINERS |\n");
			printf("\n                 NORTE\n\n");
			imprimir_tabuleiro(p2,tam);
			vitoria(p2);
			sair = 2;
		}
	}
	while(sair != 2);
	return 0;
}