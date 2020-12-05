#include <stdio.h>
#include <stdlib.h>

int main() {
  int *va; 
  int n = 3;
  int m = 3;
  int p;

  va = (int*)malloc(sizeof(int)*(n*m));
  if(va==NULL){
    printf("erro na alocacao de memoria");
  }

  for(int i=0;i<(n*m);i++){
    printf("posicao %d\n", i);
    scanf("%d", &va[i]);
  }
  
  printf("que coluna?\n");
  scanf("%d", &p);

  colunadaMatriz(va, n, m, p)

  return 0;
}


int* colunadaMatriz(int *va, int n, int m, int p){
    int cm = alocaVetor(n);
    if(cm == NULL){
        return NULL;
    }
    for(int j = 0; j < m; j++){
        cm[j] = va[j*m+p];
    }
    return cm;
}