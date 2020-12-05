#include "stack.h"


Stack *stkCreate(int maxItens){
  Stack* s;
  if(maxItens > 0){  
    s = (Stack *) malloc(sizeof(Stack)); 
    if(s != NULL){ 
      s->itens = (void* *) malloc(sizeof(void*)*maxItens); 
      if(s->itens != NULL){
        s->top = -1;
        s-> maxItens = maxItens;
        return s; 
      }
      else{
        free(s);
      }
    }
  }
  return NULL;
}

int stkDestroy (Stack *s){
  if(s!=NULL){
    if(s->itens != NULL){
      if(s->top >= 0){
        free(s->itens);
        free(s);
        return TRUE;
      }
    }
  }
  return FALSE;
}

int stkPush( Stack *s, void *item ){
  if(s!=NULL){
    if(s->itens != NULL){
      if(s->top < s->maxItens){
        s->top++;
        s->itens[s->top] = item;
        
        return TRUE;
      }
    }
  }
  return FALSE;
}

void *stkPop( Stack *s ){
  void *top;
    if(s != NULL){
        if(s->top >= 0){
            top = s->itens[s->top];
            s->itens[s->top]=NULL;
            s->top--;
            return top;
        }
    }
    return NULL;
}

int stkIsEmpty( Stack *s ){
  if(s!=NULL){
    if(s->itens != NULL){
      if(s->top < 0){
        return TRUE;
      }
    }
  }
  return FALSE;
}

