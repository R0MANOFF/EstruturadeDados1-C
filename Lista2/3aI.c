#include <stdio.h>
#include <stdlib.h>

int TipodeMatriz(int *va, int n, int m); 

int main() {
  int *va; 
  int n = 4;
  int m = 4;
 
 /*
  printf("linhas da matriz: \n");
  scanf("%d", &n);
  printf("linhas da matriz: \n");
  scanf("%d", &m);
*/

  va = (int*)malloc(sizeof(int)*(n*m));
  if(va==NULL){
    printf("erro na alocacao de memoria");
  }

  for(int i=0;i<(n*m);i++){
    printf("posicao %d\n", i);
    scanf("%d", &va[i]);
  }



    int mat = TipodeMatriz(va, n, m);
  

  return 0;
}

int TipodeMatriz(int *va, int n, int m){
  int simetrica=0;
  int diagonal=0;

  //matriz só é simétrica de for quadrada
  if(n==m){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          printf("os elementos comparados são %d e %d\n",va[i*m+j], va[(n-i)*m+(m-j)]);
        if(va[i*m+j] == va[(n-i)*m-(m-j)] ){

        }
      }
      printf("\n");
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          printf("%d  ", va[i*m+j]);
      }
      printf("\n");
    }


/*
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(i!=j){
          if(va[i*m+j] == 0){
            printf("eh diagonal\n");
          }
        }
        else{
          printf("n eh diagonal n mo\n");
        }
      }
    }*/


  }

return 0;
}