#ifndef  _TREE_H_
#define  _TREE_H_
#ifndef  _TREE_C_  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define TRUE 1
#define FALSE 0



typedef struct _tnode_{
  void* data;
  struct _tnode_ *left;
  struct _tnode_ *right;
}TNode;


typedef struct _aluno_{
  int matricula;
  char nomeAluno[30]; 
  float CR;
}Aluno;


TNode* abpCreate();
void* abpQuery(TNode *t, void* key, int (*cmp)(const void*, const void*));
TNode *abpInsert(TNode *t, void* data, int (*cmp)(const void*, const void*));
TNode *abpRemove(TNode *t, void* key, int (*cmp)(const void*, const void*),TNode *raiz);
TNode* abpMenor(TNode *t);
int destroy(TNode *t);
void simetrico(TNode *t, void(*visit)(void*));
void visit(void* data);
int cmp(const void* nome1, const void* nome2);


#else
  typedef struct _tnode_ TNode;
  typedef struct _aluno_ Aluno;
  extern TNode* abpCreate();
  extern void* abpQuery(TNode *t, void* key, int (*cmp)(const void*, const void*));
  extern TNode *abpInsert(TNode *t, void* data, int (*cmp)(const void*, const void*));
  extern TNode *abpRemove(TNode *t, void* key, int (*cmp)(const void*, const void*),TNode *raiz);
  extern TNode* abpMenor(TNode *t);
  extern int destroy(TNode *t);
  extern void simetrico(TNode *t, void(*visit)(void*));
  extern void visit(void* data);
  extern int cmp(const void* nome1, const void* nome2);
#endif
#endif



