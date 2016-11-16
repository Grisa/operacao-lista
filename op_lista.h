#pragma once
#include "lista.h"
#define TRUE 1
#define FALSE 0
#define ERRO_MEMORIA -1
#define ERR0_NUMERO_INVALIDO -2

LDE *adiciona(LDE *l1,int pos1,int pos2);
LDE *multiplica(LDE *l1,LDE *l2);
int inicializa_numero(LDE *l1, char *num);
int verifica_caracteres(char *num);
