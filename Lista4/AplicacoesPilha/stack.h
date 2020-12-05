#ifndef _STACK_H_
#define _STACK_H_
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack_{
  int top;
  int maxItens;
  void* *itens;
}Stack;

Stack *stkCreate ( int max_itens); // cria
int stkPush( Stack *s, void *item ); // recebe elemento e o coloca no topo da pilha
void *stkPop( Stack *s ); //recebe a pilha e retira o primeiro elemento
void *stkFirst( Stack *s ); // retorna o primeiro elemento da pilha
int stkIsEmpty( Stack *s ); // retorna true se estiver vazia ou false se n estiver vazia
int stkDestroy (Stack *s); //recebe a pilha e a destroi somente se estiver vazia

#endif