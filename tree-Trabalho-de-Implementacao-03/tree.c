#include "tree.h"


// função para criar uma árvore vázia
TNode* abpCreate(){
  return NULL;
}

// função para buscar um aluno na árvore
void* abpQuery(TNode *t, void* key, int (*cmp)(const void*, const void*)){
  int stat;

  if(t != NULL){
    stat = cmp(key, t->data);
    if(stat == 0){
      return t->data;
    }else{
      if(stat < 0){
        return abpQuery(t->left, key,cmp);
      }else{
        return abpQuery(t->right,key,cmp);
      }
    }
  }
  return NULL;   
}
  


// função para inserir um aluno na árvore
TNode *abpInsert(TNode *t, void* data, int (*cmp)(const void*, const void*)){
  TNode *newnode;
  int stat;

  if(t != NULL){
      stat = cmp(data, t->data);
      if(stat < 0){
        t->left = abpInsert(t->left,data, cmp);
      }else{
        if(stat > 0){
          t->right = abpInsert(t->right, data,cmp);
        }
      }
      return t;
  }else{
    newnode = (TNode*)malloc(sizeof(TNode));
    if(newnode != NULL){
      newnode->data = data;
      newnode->left = NULL;
      newnode->right = NULL;
      return newnode;
    }else{
      return NULL;
    }
  }
}


// função para remover um aluno da árvore
TNode *abpRemove(TNode *t, void* key, int (*cmp)(const void*, const void*),TNode *raiz){
  TNode *aux;
  void* data;
  int stat;
  TNode *node;
  if(t != NULL){
    stat = cmp(key, t->data);
    if(stat < 0){ // menor que o valor da raiz
      t->left = abpRemove(t->left, key, cmp,t);
    }
    if(stat > 0){ // maior que o valor a raiz
      t->right = abpRemove(t->right, key, cmp,t);
    }
    if(stat == 0){ // se encontrou
      if(t->left == NULL && t->right == NULL){
        if(t == raiz){ // igual a raiz principal
          return NULL;
        }
        free(t);
        return NULL;
      }
      if(t->left == NULL){ // se ele não tem filho esquerdo
        aux = t->right;
        data = t->data;
        if(t == raiz){
          t->data = aux->data;
          t->right = abpRemove(t->right, aux->data, cmp, t);
          return t;
        }
        free(t);
        return aux;
      }
      if(t->right == NULL){ // se ele não tem filho direito
        aux = t->left;
        data = t->data;
        if(t == raiz){
          t->data = aux->data;
          t->left = abpRemove(t->left, aux->data, cmp, t);
          return t;
        }
        free(t);
        return aux;
      }
      if(t->left != NULL && t->right != NULL){
        node = abpMenor(t->right); 
        t->data = node->data;
        t->right = abpRemove(t->right, node->data, cmp,t);
        return t;
      }
    }
  }
  return t;
}
  

// função para encontrar o nó com menor valor da subárvore direita
TNode* abpMenor(TNode *t){
   if(t == NULL){
    return NULL;
  }else{
    if(t->left == NULL){
      return t;
    }else{
      return abpMenor(t->left);
    }
  } 
}



// função para fazer a impressão do conteúdo de cada nó da árvore
// usando caminhamento simetrico
void simetrico(TNode *t, void(*visit)(void*)){
  if(t != NULL){
    simetrico(t->left, visit);
    visit(t->data);
    simetrico(t->right,visit);
  }
}

// destruir
int destroy(TNode *t){
  if(t == NULL){
    free(t);
    return TRUE;
  }
  return FALSE;
}




