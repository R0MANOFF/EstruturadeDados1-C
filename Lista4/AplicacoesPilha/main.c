/*
1 - Escreva um algoritmo para determinar se uma string de caracteres de entrada é da forma: xCy,  onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso de x (isto é, se x = "ABABBA", y deve equivaler a "ABBABA"). Em cada ponto, você só poderá ler o próximo caractere da string.
2 - Faca um algoritmo que recebe uma string e retorna verdadeiro se ela for um palindromo ou falso caso contrario.
3 - Faça a função qDestroy
*/

#include "stack.h"

int main(void){
  Stack *s = NULL;
  //int maxItens;
  int op;
  char *string = (char*)malloc(sizeof(char)*50);
  if(string == NULL){
    printf("string não alocada correntamente\n");
  }

  printf("\n-------------- Opçoes ------------\n");
  printf("\t\t [1] Verificar se eh palindromo\n");
  printf("\t\t [2] Verificar se eh do formato xCy");
  printf("\n-----------------------------------\n");

  scanf("%d", &op);

  switch(op){
    case 1:
      printf("\n\t------- Teste Palindromo -------\n");
      printf("\nInsira uma palvra: ");
      getchar();
      gets(string);
      //printf("STRLEN %d\n", strlen(string));


      s = stkCreate(strlen(string));

      if(testePalindromo(string)==TRUE){
        printf("Eh um palindromo\n");
      }
      else{
        printf("Nao eh um palindromo\n");
      }


      break;
    case 2:
      printf("\n\t------- Teste xCy -------\n");
      printf("\nInsira uma palvra: ");
      scanf("%s", string);
      //printf("%s\n", string);

      if(testeXCY(string)==TRUE){
        printf("Eh da forma xCy\n");
      }
      else{
        printf("Nao eh da forma xCy\n");
      }
      stkDestroy (s);
      break;
    default:
      printf("Digite uma opção válida");

      break;
  }
  free(string);
  


}

int testeXCY(char str[]){
  Stack *s = NULL;
  char *pal = NULL;
  
  s = stkCreate(strlen(str)/2);

  int push = TRUE;
  int diferente = FALSE;
  int qntdPush = 0;
  int qntdPop = 0;

  for (int i=0; i<strlen(str); i++){
    if(str[i] == 'C'){
      push = FALSE;
      i++;
    }
   
    if(push){
      pal = (char*)malloc(sizeof(char));
      if(pal != NULL){
        *pal = str[i];
        //printf("pal: %s\n", pal);
        stkPush(s,pal);
        qntdPush++;
      }
    }
    else{
      qntdPop++;
      pal = stkPop(s);
      if(!stkIsEmpty(s) && *(char*)pal != str[i]){
        diferente = TRUE;
      }
      free(pal);
    }
  }

  stkDestroy(s);

    if (qntdPush == qntdPop && diferente == FALSE)
    {
        return TRUE;
    }

    return FALSE;

}

int testePalindromo(char str[]){
  Stack *s = NULL;
  char *palReverse;
  int aux;
  int compare = 0;
  char *x;

  s = stkCreate(strlen(str));

  for(int i=0; i<strlen(str); i++){
    printf("%s\n", str[i]);
    stkPush(s,str[i]);
  }
  
  for(int i=0;i<strlen(str);i++){
    x=(char *)stkPop(s);

    if(str[i]==x){
        aux++;
    }
  }


  return FALSE;
}

