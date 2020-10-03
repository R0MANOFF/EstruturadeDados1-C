/*Faça um programa para:
- ler a opção ( 1- Inteiro, 2 - Real)
- ler um numero n;
- alocar um vetor de n posições de números de acordo com a opçao do usuario;
- ler os n numeros e guardar no vetor alocado;
- usar a funcao qsort do C para ordenar esses dados;
- imprimir os dados ordenados*/


#include <stdio.h>
#include <stdlib.h>

int ordenacaoInt(const void *a, const void *b){
  if(*(int*)a == *(int*)b){
    return 0;
  }
  else
    if(*(int*)a < *(int*)b){
    return -1;
    }
    else{
      return 1;
    }
}

int ordenacaofloat(const void *a, const void *b){
    if(*(const float*)a < *(const float*)b)
        return -1;
    return *(const float*)a > *(const float*)b;
}


int main(void) {
  int tipo;
  int ni, *veti, nf;
  float *vetf;

  printf("1- Inteiro, 2- Real\n");
  scanf("%d", &tipo);

 switch(tipo){
   case 1:
    printf("Digite o numero inteiro n:\n");
    scanf("%d", &ni);

    veti = (int*)malloc(sizeof(int)*ni);
    if(veti == NULL){
      printf("Erro na alocação de memoria\n");
      return 0;
    }
    for(int i=0; i<ni; i++){
      printf("insira o elemento da posição %d do vator:\n", i+1);
      scanf("%d", &veti[i]);
    }

    qsort(veti, ni, sizeof(int), ordenacaoInt);

    for(int i=0; i<ni; i++){
      printf("%d ", veti[i]);
    }
    
    break;
    case 2:
    printf("Digite o numero real n:\n");
    scanf("%d", &nf);

    vetf = (float*)malloc(sizeof(float)*nf);
    if(vetf == NULL){
      printf("Erro na alocação de memoria\n");
      return 0;
    }
    for(int i=0; i<nf; i++){
      printf("insira o elemento da posição %d do vator:\n", i+1);
      scanf("%f", &vetf[i]);
    }

  qsort(vetf, nf, sizeof(float), ordenacaofloat);

    for(int i=0; i<nf; i++){
      printf("%.2f ", vetf[i]);
    }      
 }

  return 0;
}