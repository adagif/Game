#include <stdio.h>
#include <stdlib.h>
#include "game.h"

struct elemento{
	int pecas;
	struct elemento *prox; 
};

typedef struct elemento Elem; 

Lista* criar_lista(){
	int i;
	Lista *novo;
	novo = (Lista*)malloc(sizeof(Lista));
	if(novo == NULL){
		printf("ERRO NA ALOCACAO!\n");
		return NULL;
	}
	*novo = NULL;
	return novo;
}

void inserir_l(Lista* li,int valor){
	int cont =0;
	if(li == NULL){
		printf("LISTA INEXISTENTE");
	}
	else{
		Elem * novo;
		novo = (Elem *)malloc(sizeof(Elem));
		if(novo == NULL){
			printf("ih o DEU RUIM, NAO ALOCOU\n");
		}
		novo->pecas = valor; 
		novo -> prox = *li;
		*li = novo;
	}
}

int removerMeio(Lista * li,int peca){
	if((*li)->pecas==peca){
		Elem *aux = *li;
		*li = aux->prox;
		free(aux);
		return 1;
	}
	else{
		Elem *a = *li;
		Elem *aux = a->prox;
		while(aux != NULL && aux->pecas != peca){
			a = aux;
			aux = aux->prox;
		}
		if(aux == NULL) return 0;
		a->prox = aux->prox;
		free(aux);
		return 1;
	}
}
//pilha abaixo---------------------------------------------------
Pilha* criar(){
	Pilha *pi;
	pi = (Pilha*)malloc(sizeof(Pilha));
	if (pi == NULL){
		printf("ERRO NA ALOCACAO\n");
	}
	else{
		*pi = NULL;
	}
	return pi;
}

Pilha ***criar_tabuleiro(int tamanho){
	int i,j;
	Pilha ***tab;
	tab = (Pilha***)malloc(tamanho*sizeof(Pilha**));
	if(tab == NULL){
		printf("DEU RUIM, ALOCOU NAO\n");
	}
	return tab;
}

void inserir(Pilha*pi,int x){
	if(pi == NULL){
		printf("DEU RUIM, TA ALOCADO NAO\n");
	}
	else{
		Elem *novo;
		novo = (Elem *)malloc(sizeof(Elem));
		if(novo == NULL){
			printf("DEU RUIM, TA ALOCADO NAO\n");
		}
		novo->pecas = x;
		novo->prox = *pi;
		*pi = novo;
	}
}

int vazia(Pilha *pi){
	if(pi == NULL){
		return 1;
	}
	else if(*pi == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
