#include "op_lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sobra = 0;


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
	
	/*Chegar até o final da L1 e L2 recursivamente para fazer uma pilha implicita

	igualar numero de digitos inserindo 0 no começo

	adicionar info das listas junto com sobra

	criar um Elemento para cada soma de l1 e l2 (junto com a sobra) e inserir no inicio da lista;
	*/

	ElementoDuplo *temp = l1->cabeca;

	for (int i = 0; i < pos1; i++)
	{
		if (temp->proximo != NULL) temp = temp->proximo;
	}
	for (int i = pos1; i <= pos2; i++){
		LDE *sub = malloc(sizeof(LDE));
		leNaPosicao(l1, sub, i);
		printf("quantidade de elementos na lista %d === %d\n",i+1,sub->quantidade_elementos);
		
	}

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
		return ERR0_NUMERO_INVALIDO;
	}

 	int i = 0;
		
	for  (i = 0;num[i] != '\0';i++){
		int x = num[i] - '0';
		insereFim(l, &x);
	}
		
}
