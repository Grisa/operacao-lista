#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "op_lista.h"



int main() {

	LDE *principal = malloc(sizeof(LDE));

	IniciaLista(principal, sizeof(LDE));	
	
	for (int i = 0; i < 4; i++)
	{
		LDE *sub = malloc(sizeof(LDE));
		IniciaLista(sub, sizeof(LDE));

		char numero[1000];
		scanf("%s", numero);
		inicializa_numero(sub,numero);
		insereFim(principal, sub);			
		printf("\n");
	}
	
	

	adiciona(principal,0,3);

	for (int i = 0; i < 4; i++)
	{
		LDE *sub = malloc(sizeof(LDE));
		IniciaLista(sub, sizeof(LDE));		
		leNaPosicao(principal, sub, i);
		insereFim(principal, sub);
		//mostraLista(sub, mostra_int);
		printf("\n");
	}
	printf("\n");
	system("pause");

	return 0;
}

