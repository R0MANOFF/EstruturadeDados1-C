#include "sllist.h"


// função que cria a lista
SLList *SLCreate(){ 
  SLList *l;
  l = (SLList*)malloc(sizeof(SLList));
  if(l!=NULL){
    l->first = NULL;
    return l;
  }
  return NULL;
}


//função para inserir cada novo nó na primeira posição

int slInsertFirst (SLList *l, void* elm){
  SLNode *newnode;
  if ( l != NULL ){
    newnode = (SLNode *)malloc(sizeof(SLNode));
    if (newnode != NULL){
      newnode->data = elm;
      if (l->first == NULL ){
        newnode->next = NULL;
      } 
      else {
        newnode->next = l->first;
      }
      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}


// função que faz a busca de determinado elemento e retorna-o
// caso o elemento esteja na lista
void* sllQuery ( SLList *l, void *key, int (*cpm) (const void *, const void *)){
  SLNode *cur; 
  Aluno **aluno; 
  char *dataNome;
  if (l != NULL){
    if (l->first != NULL){
      cur = l->first;
      while (cur->next != NULL && cpm(cur->data,key) != TRUE){
        cur = cur->next;
      }
      if(cpm(cur->data,key) == TRUE){
        return cur->data;
      }
    }
  }
  return NULL;
}


// função que remove um elemento da lista
void* sllRemoveQuery ( SLList *l, void *key, int (*cpm) (const void *, const void *)){
  SLNode *cur, *prev; 
 void* aux;
  if (l != NULL){
    if (l->first != NULL){
      cur = l->first;
      while (cur->next != NULL && cpm(cur->data,key) != TRUE){
        prev = cur;
        cur = cur->next;
      }
      if(cpm(cur->data,key) == TRUE){
        aux = cur->data;
        if(cur == l->first){
          l->first = cur->next;
        }else{
          prev->next = cur->next;
        }
        free(cur);
        return aux;
      }
    }
  }
  return NULL;
}


// função que destroi a lista
int sllDestroy (SLList *l){
  if (l != NULL){
    if (l->first == NULL){
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}

// função que faz a contagem de quantos elementos há na lista
int sllGetNumElms(SLList *l){
  SLNode *cur; 
  int n=0;
  if (l != NULL){
    if (l->first != NULL){
      cur = l->first;
      while (cur->next != NULL ){
        n++;
        cur = cur->next;
      }
      n++;
      return n;
    }
    return 0;
  }
  return -1;
}




// função que retorna cada elemento para a main imprimir
void* imprimir(SLList *l, int i){
  SLNode *aux, *cur;
  int n = 0;
  if(l != NULL){
    if (l->first != NULL){
        cur = l->first;
        while (n != i){
          cur = cur->next;
          n++; 
        }
        aux = cur->data;
        return aux;
    }
  }
  return NULL;
}






