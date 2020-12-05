#ifndef  _SLList_H_
#define  _SLList_H_
#ifndef  _SLList_C_  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX = 50
#define TRUE 1
#define FALSE 0

typedef struct _SLNode_{
  struct _SLNode_ *next;
  void *data;
}SLNode;

typedef struct _SLList_{
  SLNode *first;
}SLList;

typedef struct _aluno_{
  int matricula;
  char nomeAluno[30]; 
  float CR;
}Aluno;


SLList *SLCreate();
int slInsertFirst(SLList *l, void *elm);
int sllDestroy (SLList *l);
int sllGetNumElms(SLList *l);
void* sllQuery (SLList *l, void *key, int (*cpm) (const void *, const void *));
void* sllRemoveQuery ( SLList *l, void *key, int (*cpm) (const void *, const void *));
int cpm(const void* nome1, const void* nome2);
void* imprimir(SLList *l, int i);


#else

typedef struct _SLNode_ SLNode;
typedef struct _SLList_ SLList;
typedef struct _aluno_ Aluno;

extern SLList *SLCreate();
extern int slInsertFirst (SLList *l, void *elm);
extern int sllDestroy (SLList *l);
extern int sllGetNumElms(Sllist *l);
extern void* sllQuery (SLList *l, void* key, int (*cpm) (const void*, const void*));
extern int cpm(const void* nome1, const void* nome2);
extern void* sllRemoveQuery ( SLList *l, void *key, int (*cpm) (const void *, const void *));
extern void* imprimir(SLList *l, int i);

#endif
#endif

