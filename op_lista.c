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
	
	/*Chegar at� o final da L1 e L2 recursivamente para fazer uma pilha implicita

	igualar numero de digitos inserindo 0 no come�o

	adicionar info das listas junto com sobra

	criar um Elemento para cada soma de l1 e l2 (junto com a sobra) e inserir no inicio da lista;
	*/

	ElementoDuplo *temp = l1->cabeca;

	/*Chegar at� a primeira posi��o para ser somada*/
	for (int i = 0; i < pos1; i++)
	{
		if (temp->proximo != NULL) temp = temp->proximo;
	}

	int x[2]; /*Gambiarra para guardar a qtd de numeros das 2 listas,funciona?Claro.Ta feio ? foda-se*/

	for (int i = pos1; i <= pos2; i++){
		LDE *sub = malloc(sizeof(LDE));
		leNaPosicao(l1, sub, i);
		
		if(i == pos1)
		 x[0] = sub->quantidade_elementos;
		if (i == pos2)
	     x[1] = sub->quantidade_elementos;
	}

	
	int dif = 0; 
	/* Pegar a diferen�a entre a quantidade de numeros nas listas
	   Testar se uma lista est� vazia                          */

//	if (x[0] || x[1] == 0) return ERRO_LISTA_VAZIA;
	

	if (x[0] > x[1]) {
		dif = x[0] - x[1];
	}
	else {
		dif = x[0] - x[1];
		dif *= -1; // -1 para deixar o n�mero positivx
	}

	printf("dif %d\n", dif);
	/*Adicionar os zeros no come�o da lista menor*/

	if (x[0] > x[1]) {
		int i = 0;
		
		for (i = pos1; i <= pos2; i++) {
			LDE *sub = malloc(sizeof(LDE));
			leNaPosicao(l1, sub, i);			
			if (i == pos2) {
				for (int j = 0; j < dif; j++)
				{
					int a = 0;
					inserePosicao(sub, &a,1);
				}
				
			}
		}
	}

	else {		
			int i = 0;

			for (i = pos1; i <= pos2; i++) {
				LDE *sub = malloc(sizeof(LDE));
				leNaPosicao(l1, sub, i);
				if (i == pos1) {
					for (int j = 0; j < dif; j++)
					{
						int a = 0;
						inserePosicao(sub, &a, 1);
					}
				}
			}
		}
	}


LDE *multiplica(LDE * l1, LDE * l2){

}

int inicializa_numero(LDE *l,char *num)
{
	/*Verificar os caracteres
	
	Inserir n�meros no fim da lista

	Fazer a corre��o da tabela ASCII diminuindo 48 ou '0'

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
