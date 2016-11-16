#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "op_lista.h"

/*USEM TRUE E FALSE USEM TRUE E FALSE USEM TRUE E FALSE USEM TRUE E FALSE USEM TRUE E FALSE*/

void mostrafloat(void *k) {
	printf("%d", *(int*)k);	
}

int main() {
	
	LDE l1;

	IniciaLista(&l1, sizeof(int));

	inicializa_numero(&l1, "100");
	

	mostraLista(&l1, mostrafloat);
	
	/*Criar uma multilista como ponteiro
	
	Cada nó de LISTA_PRINCIPAL aponta para outra lista que contém os nums

	*/

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
		mostraLista(sub, mostra_int);
		printf("\n");
	}
	
	
	printf("\n");
	system("pause");

	return 0;
}

