#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "op_lista.h"

/*USEM TRUE E FALSE USEM TRUE E FALSE USEM TRUE E FALSE USEM TRUE E FALSE USEM TRUE E FALSE*/

void menu() {
	int op = 0;

	do
	{
		printf("\n\n");
		printf("SEJA BEM VINDO AO VAI TOMAR NO SEU CU,digite a opção que deseja fdp\n");
		printf("\nDigite 0 para sair\n");
		printf("Digite 1 para adicionar um numero à lista\n");
		printf("Digite 2 para ver o maior numero\n");
		printf("Digite 3 para ver o menor numero\n");
	} while (op == TRUE);

	scanf("%d", &op);

	switch (op) {
		case 0:
			exit(0);
			break;
		case 1:
			system("cls");			
			break;
		default:
			system("cls");
			menu();
			break;
	}
}


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

	LDE *LISTA_PRINCIPAL = malloc(sizeof(LDE));

	IniciaLista(LISTA_PRINCIPAL, sizeof(LDE));


	
	menu();
	printf("\n");
	system("pause");

	return 0;
}

