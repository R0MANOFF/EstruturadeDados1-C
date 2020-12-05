#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Faça um algoritmo que recebe os inteiros n, m, p e q, e duas matrizes ma e mb e retorna o produto entre as duas matrizes //

int MultMatrix ( int n, int m, int p, int q, float **ma, float **mb); 

int main() {
  int n; //linhas ma
  int m; //colunas ma
  int p; // linhas mb
  int q; // colunas mb
  float **ma;
  float **mb;


  //preenchimento matriz a
  printf("numero de linhas da matriz a:\n");
  scanf("%d", &n);
  printf("numero de colunas da matriz a:\n");
  scanf("%d", &m);
 

  ma = (float**)malloc(sizeof(float*)* n);
  if(ma != NULL){
    for (int i=0; i<m; i++){
      ma[i] = (float*)malloc(sizeof(float)*m);{
        if(ma[i]==NULL){
          printf("erro de alocacao na memoria \n");
          break;
        }
      }
    }
  }

  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("Digite o item [%d][%d] da matriz: ", i, j);
      scanf("%f", &ma[i][j]);
    }
  }


  //preenchimento matriz b 
  printf("numero de linhas da matriz b:\n");
  scanf("%d", &p);
  printf("numero de colunas da matriz b:\n");
  scanf("%d", &q);
 

  mb = (float**)malloc(sizeof(float*)*p);
  if(mb != NULL){
    for (int i=0; i<m; i++){
      mb[i] = (float*)malloc(sizeof(float)*q);{
        if(mb[i]==NULL){
          printf("erro de alocacao na memoria da matriz b \n");
          break;
        }
      }
    }
  }
  
  for(int i=0; i<p; i++){
    for(int j=0; j<q; j++){
      printf("Digite o item [%d][%d] da matriz: ", i, j);
      scanf("%f", &mb[i][j]);
    }
  }


if(m==p){
 MultMatrix (n, m, p, q, ma, mb);
}
else{
  printf("Impossivel calcular o produto entre as matrizes");
}
  return 0;
}

int MultMatrix ( int n, int m, int p, int q, float **ma, float **mb){
  int mc[n][q];
   
    int aux=0;
     for (int i = 0; i < n; i++){
      for (int j = 0; j < q; j++){
          mc[i][j] = 0;
			      for(int k = 0; k < m; k++) {
				    aux +=  ma[i][k] * mb[k][j];
			      }
          mc[i][j] = aux;
          aux=0;
      }
    }
 

  for(int i=0; i<n; i++){
    for(int j=0; j<q; j++){
      printf("%d ", mc[i][j]);
    }
    printf("\n");
  }

  return 0;
}