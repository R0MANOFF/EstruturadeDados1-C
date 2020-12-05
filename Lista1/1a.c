#include <stdio.h>
#include <stdlib.h>

int CmpVectorMatrix (int n, int m, int p, float *vet, float **mat);

int main(void) {
  int n;
  int m; //linhas
  int p; // colunas
  float *vet;
  float **ma;

  printf("Tamanho do vetor:\n");
  scanf("%d", &n);
  vet = (float*)malloc(sizeof(float)*n);
  if(vet==NULL){
    printf("erro na alocacao da memoria:\n");
  }

  for(int i=0; i<n; i++){
    scanf("%f", &vet[i]);
  }

   for(int i=0; i<n; i++){
    printf("%f \n", vet[i]);
  }

  printf("numero de linhas da matriz:\n");
  scanf("%d", &m);
  printf("numero de colunas da matriz:\n");
  scanf("%d", &p);
 
 //isso aqui é para preencher a matriz
  ma = (float**)malloc(sizeof(float*)* m);
  if(ma != NULL){
    for (int i=0; i<m; i++){
      ma[i] = (float*)malloc(sizeof(float)*p);
        if(ma[i]==NULL){
          printf("erro de alocacao na memoria \n");
          break;
        }
    }
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<p; j++){
      printf("Digite o item [%d][%d] da matriz: ", i, j);
      scanf("%f", &ma[i][j]);
    }
  }

   for(int i=0; i<m; i++){
    for(int j=0; j<p; j++){
      printf("%f", ma[i][j]);
    }
    printf("\n");
  }

  CmpVectorMatrix(n, m, p, vet, ma);

  return 0;
}

int CmpVectorMatrix (int n, int m, int p, float *vet, float **mat){

  for(int i=0; i<m; i++){
    for(int j=0; j<p; j++){
      for(int k=0; k<n; k++){
        if(vet[k] == mat[i][j]){
          printf("o elemento %f está na linha %d e na coluna %d da matriz \n", vet[k], i, j);
        }
      }
    }
  }

  return 0;
}

/*
//encontrar elemento do vetor na matriz
    for(int i=0;i<3;i++){
      for(int j=0; j<3; j++ ){
        for(int k=0; k<5; k++)
        if(n[k] == m[i][j]){
          printf("o elemento %d está na linha %d e na coluna %d da matriz \n", n[k], i, j);
        }
      }
    }
  }
*/