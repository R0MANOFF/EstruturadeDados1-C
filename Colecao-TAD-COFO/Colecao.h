#ifndef  _Colecao_H_
#define  _Colecao_H_
#ifndef  _Colecao_C_  /* testa se o arquivo existe*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX = 50
#define TRUE 1
#define FALSE 0

typedef struct _aluno_
{
  long int matricula;
  char *nomeAluno; 
  float CR;
}Aluno;

typedef struct _colecao_
{
  int maxItens;
  int numItens;
  int curItem;
  void* *item;
}Colecao;



Colecao *colCriar(int maxItens);
int colInserir(Colecao *c, void* item);
int cpm(const void* elm, const void* nome);
void *colBuscar(Colecao *c, void* key,int(*cmp)(const void*, const void*));
int coldestruir(Colecao *c);
void *colRemover(Colecao *c, void* key,int(*cmpNomeAluno)(const void*, const void*));
void *imprimirColecao(Colecao *c, int i);



#else // Defina cada função 

  typedef struct _colecao_ Colecao;
  typedef struct _aluno_ Aluno;
  extern Colecao *colCriar(int maxItens);
  extern int colInserir(Colecao *c, void* item);
  extern void *colBuscar(Colecao *c, void* key, int(*cmp)(const void*, const void*));;
  extern int cpm(const void* elm, const void* nome);
  extern int coldestruir(Colecao *c);
  extern void *colRemover(Colecao *c, void* key,int(*cmpNomeAluno)(const void*, const void*));

#endif
#endif