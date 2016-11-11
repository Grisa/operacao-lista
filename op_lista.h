#pragma once
#include "lista.h"
#define TRUE 1
#define FALSE 0
#define ERRO_MEMORIA -1
#define ERR0_NUMERO_INVALIDO -2

void adiciona(LDE *l1, LDE *l2, LDE *l3);
void multiplica(LDE *l1, LDE *l2, LDE *l3);
int inicializa_numero(LDE *l1, char *num);
int verifica_caracteres(char *num);
