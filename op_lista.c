#include "op_lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int verifica_caracteres(char *num)
{
	/*Verificar caracter por caracter para ver se n tem nenhuma letra ou carac invalido
	se houver,retornar erro
	*/

	int i = 0;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (isdigit(num[i]) == FALSE)
			return FALSE;
	}
		
	return TRUE; // OK;
}


LDE *adiciona(LDE *l1,int pos1,int pos2){
	
	/*Chegar até o final da L1 e L2 - OK

	igualar numero de digitos inserindo 0 no começo - OK

	adicionar info das listas junto com sobra - incompleto

	criar um Elemento para cada soma de l1 e l2 (junto com a sobra) e inserir no inicio da lista; - Incompleto
	*/
	LDE *A = malloc(sizeof(LDE));
	LDE *B = malloc(sizeof(LDE));

	IniciaLista(A, sizeof(int));
	IniciaLista(B, sizeof(int));

	leNaPosicao(l1, A, pos1);
	leNaPosicao(l1, B, pos2);

	/*Pegar a diferença de digitos entre as listas e adicionar zero no começo da lista menor*/
	int dif = A->quantidade_elementos - B->quantidade_elementos;
	if (dif < 0) dif = dif * -1;

	
	for (int i = 0;i < dif;i++)
	{
		if (A->quantidade_elementos > B->quantidade_elementos) 
		     { int info = 0; insereInicio(B, &info); }
		else 
		     { int info = 0; insereInicio(A, &info); }
	}	
	
    /*Criar a lista resultante*/

	LDE *lista_resultante = malloc(sizeof(LDE));
	IniciaLista(lista_resultante, sizeof(LDE));	
	
	ElementoDuplo *p = A->cabeca;	//A = pos1, B = pos2
	ElementoDuplo *z = B->cabeca;	
	
	//chegar no ultimo elemento de cada lista
	while ((p->proximo != NULL) && (z->proximo != NULL))
	{			
		p = p->proximo;
		z = z->proximo;		
	}
		
	//somar de tras para frente e add na resultante
	int sobra_soma, soma = 0;

	while ((p != NULL) && (z != NULL)) //incompleto
	{
		int a, b, x = 0;
		memcpy(&a, p->info, sizeof(int));
		memcpy(&b, z->info, sizeof(int));

		x = a + b;
		if (x >= 10) {
			x -= 10;
		}
		insereInicio(lista_resultante, &x);		
		z = z->ant;
		p = p->ant;
	}		
	
	return lista_resultante;
}

LDE *multiplica(LDE * l1, LDE * l2){

}

int inicializa_numero(LDE *l,char *num)
{
	/*Verificar os caracteres
	
	Inserir números no fim da lista

	Fazer a correção da tabela ASCII diminuindo 48 ou '0'

	*/

	if (verifica_caracteres(num) == FALSE) {
		puts("NUMERO INVALIDO");
		return ERRO_NUMERO_INVALIDO;
	}

 	int i = 0;
		
	for  (i = 0;num[i] != '\0';i++){
		int x = num[i] - '0';
		insereFim(l, &x);
	}
		
		
}
