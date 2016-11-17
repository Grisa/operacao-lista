#pragma once
#define ERRO_LISTA_VAZIA -1
#define ERRO_POSICAO_INVALIDA -2

typedef struct ele {
	void *info;
	struct ele *proximo, *ant;
	
}ElementoDuplo;

typedef struct {
	int tamInfo;
	ElementoDuplo *cabeca;
	int quantidade_elementos;
}LDE;


int limpa_lista(LDE *l);
int removeFim(LDE *l, void *info);
void IniciaLista(LDE *l, int t);
int insereInicio(LDE *l, void *info);
int inserePosicao(LDE *l, void *info, int posicao);
int removeInicio(LDE *l, void *info);
void mostraLista (LDE *l,void(*mostra)(void*));
int insereFim(LDE *l, void *info);
int ListaVazia(LDE *l);
int removePosicao(LDE *l, void *info, int posicao);
int leNaPosicao(LDE *l, void *info, int posicao);
ElementoDuplo *aloca_elemento(void *info, int tamInfo);