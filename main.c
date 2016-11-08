#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "op_lista.h"


void mostrafloat(void *k) {
	printf("%f\n", *(float*)k);
}

int main() {
	LDE l1, l2,l3;
	IniciaLista(&l1, sizeof(float));
	int info = 1;
	insereFim(&l1, &info);
	insereInicio(&l1, &info);

	info = 2;

	insereInicio(&l2, &info);
	insereFim(&l2, &info);

	/////////////////////////////////////

	//adiciona(&l1, &l2,&l3);

	system("pause");

	return 0;
}
