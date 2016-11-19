#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

void mostra_int(void *k) {
	printf("%d", *(int*)k);
}


void IniciaLista(LDE *l, int t) {
	l->tamInfo = t;
	l->cabeca = NULL;
	l->quantidade_elementos = 0;
}

ElementoDuplo *aloca_elemento(void *info, int tamInfo) {
	ElementoDuplo *p = malloc(sizeof(ElementoDuplo));
	if (p == NULL) return NULL;

	p->info = malloc(tamInfo);

	if (p->info == NULL) { free(p); return NULL; }

	memcpy(p->info, info, tamInfo);
	return p;
}

int insereInicio(LDE *l, void *info) {
	ElementoDuplo *p = aloca_elemento(info, l->tamInfo);

	if (p == NULL) return 0;

	p->proximo = l->cabeca;
	l->cabeca = p;

	if (p->proximo != NULL) p->proximo->ant = p;
	p->ant = NULL;
	l->quantidade_elementos++;
	return 1;
}

int insereFim(LDE *l, void *info) {
	if (ListaVazia(l)) return insereInicio(l, info);

	ElementoDuplo *p = l->cabeca;

	while (p->proximo != NULL) {
		p = p->proximo;
	}

	ElementoDuplo *novo = aloca_elemento(info, l->tamInfo);
	if (novo == NULL) return 0;

	p->proximo = novo;
	novo->proximo = NULL;
	novo->ant = p;

	l->quantidade_elementos++;
	return 1;
}

int inserePosicao(LDE *l, void *info, int posicao) {
	//criar um contador e atualizar a cada inserção e remoção da lista
	if (posicao < 0) return ERRO_POSICAO_INVALIDA;
	if (posicao == 0) return insereInicio(l, info);
	if (ListaVazia(l)) return ERRO_POSICAO_INVALIDA;

	ElementoDuplo *p = l->cabeca;
	int cont = 0;

	while ((cont < posicao - 1) && (p->proximo != NULL)) {
		p = p->proximo;
		cont++;
	}

	if (cont != posicao - 1) return ERRO_POSICAO_INVALIDA;

	ElementoDuplo *novo = aloca_elemento(info, l->tamInfo);
	if (novo == NULL) return 0;//erro por falta de memória;

	novo->proximo = p->proximo;
	p->proximo = novo;

	if (novo->proximo != NULL)
		novo->proximo->ant = novo;

	l->quantidade_elementos++;
	return 1;
}



int ListaVazia(LDE *l) {
	return l->cabeca == NULL;
}


int removePosicao(LDE *l, void *info, int posicao) {

	if (posicao < 0) return ERRO_POSICAO_INVALIDA;
	if (posicao == 0) return insereInicio(l, info);
	if (ListaVazia(l)) return ERRO_POSICAO_INVALIDA;

	ElementoDuplo *p = l->cabeca;
	int cont = 0;

	while ((cont < posicao - 1) && (p->proximo != NULL)) {
		p = p->proximo;
		cont++;
	}

	if (p->proximo == NULL) return ERRO_POSICAO_INVALIDA;



	ElementoDuplo *x = p->proximo;
	p->proximo = x->proximo;

	if (x->proximo != NULL)
		x->proximo->ant = p;

	memcpy(info, p->proximo->info, l->tamInfo);
	free(x->info);
	free(x);

	l->quantidade_elementos--;

}
int removeInicio(LDE *l, void *info) {
	if (ListaVazia(l))
		return ERRO_LISTA_VAZIA;

	ElementoDuplo *p = l->cabeca;
	l->cabeca = p->proximo;
	memcpy(info, p->info, l->tamInfo);


	free(p->info);
	free(p);

	if (l->cabeca != NULL) //ou if(lista_vazia)
		l->cabeca->ant = NULL;
	l->quantidade_elementos--;
	return 1;
}

int removeFim(LDE *l, void *info) {
	if (ListaVazia(l)) return ERRO_LISTA_VAZIA;

	if (l->cabeca->proximo == NULL) //so 1 elemento;
		return removeInicio(l, info);

	ElementoDuplo *p = l->cabeca;

	while (p->proximo->proximo != NULL) {
		p = p->proximo;
	}

	memcpy(info, p->proximo->info, l->tamInfo);

	free(p->proximo->info);
	free(p->proximo);
	p->proximo = NULL;
	l->quantidade_elementos--;
	return 1;
}

void mostraLista(LDE *l,void(*mostra)(void*)) {
	if (ListaVazia(l))
		printf("Lista vazia!");
	else {
		ElementoDuplo *p = l->cabeca;
		printf("Dados da lista: \n");
		while (p != NULL) {
			mostra(p->info,l);
			p = p->proximo;
		}
	}
}

int limpa_lista(LDE *l) {
	if (ListaVazia(l)) return ERRO_LISTA_VAZIA;

	ElementoDuplo *p = l->cabeca;

	while (p != NULL) {
		ElementoDuplo *prox = p->proximo;
		free(p->info);
		free(p);
		l->cabeca = prox;
		p = prox;
	}
	l->quantidade_elementos = 0;
	return 1;
}

int leNaPosicao(LDE *l, void *info, int posicao) {
	if (posicao < 0)
		return ERRO_POSICAO_INVALIDA;

	// if(lista_vazia(l))
	// return ERRO_POSICAO_INVALIDA;

	ElementoDuplo *p = l->cabeca;
	int cont = 0;
	while (cont<posicao && p->proximo != NULL) {
		p = p->proximo;
		cont++;
	}

	if (cont != posicao)
		return ERRO_POSICAO_INVALIDA;

	memcpy(info, p->info, l->tamInfo); /* para modificar no posição, basta
									   inverter a ordem dos parâmetros */
	return 1;// SUCESSO
}