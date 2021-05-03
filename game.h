//andar = 0 / teto = 1 / parque = 2 
//Lista-------------------
typedef struct elemento *Lista;
Lista *criar_lista();
void inserir_l(Lista *,int);
int removerMeio(Lista * ,int );
int tamanho(Lista *);
void imprimir(Lista *);
//Pilha-------------------
typedef struct elemento *Pilha;
Pilha * criar();
Pilha ***criar_tabuleiro(int);
void inserir(Pilha*,int );
