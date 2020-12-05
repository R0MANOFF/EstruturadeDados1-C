#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colecao.h"

int cpm(const void* elm, const void* nome);

int main(){
  long int matricula;
  float CR;
  Colecao *c = NULL;
  Aluno *aluno = NULL, **resulN = NULL, **remocao = NULL, **printado, **rev;
  Aluno* *enviaAluno = NULL; //pq isso é so tipo aluno*
  void* buscaNome; 
  void* remov;
  int aux, dest;
  char *nomeAluno;
  int opc, tamColecao, excluir, coldest;
  void* removido; // essa aqui nós estamos usando?
  void *print;
 
  
  do{
    printf("\n----------------- MENU ----------------\n");
            printf("\t[1] - Criar uma colecao\n");
            printf("\t[2] - Inserir Alunos nas Coleção\n");
            printf("\t[3] - Remover Alunos da Coleção\n");
            printf("\t[4] - Consultar um Aluno\n");
            printf("\t[5] - Listar todos os Alunos da colecao\n");
            printf("\t[6] - Destruir colecao\n");
            printf("\t[0] - sair do programa\n");
           printf("\n-----------------------------------------\n");
           printf("Digite a opcao desejada: ");
            scanf("%d",&opc);
    
    switch(opc){
      case 1: 
        printf("\n\tQual o tamanho da coleção que deseja inserir: ");
        scanf("%d", &tamColecao);
        if(tamColecao > 0 && (c == NULL) ){
          c = colCriar(tamColecao);
          if(c!=NULL){
            printf("\nA colecao foi criada com sucesso.\n");
          }
          else{
            printf("\nSinto Muito!Não foi possível criar a sua colecao.\n");
          }
        }
        else{
          printf("\nA colecao não pode ser criada\n");
        } 
      break;
      case 2:
        if(c!=NULL){
          aluno = (Aluno*)malloc(sizeof(Aluno));
          aluno->nomeAluno = (char*) malloc(sizeof(char)*50);
          if(aluno != NULL){
            if(aluno->nomeAluno != NULL){
              printf("\nInsira o nome: ");
              scanf("%s", aluno->nomeAluno);
              fflush(stdin);
              printf("\nInsira o numero de matricula do aluno: ");
              scanf("%ld", &aluno->matricula);
              fflush(stdin);
              printf("\nInsira o CR: ");
              scanf("%f", &aluno->CR);
              fflush(stdin);
            }
            enviaAluno = (Aluno**) malloc(sizeof(Aluno*));

            if(enviaAluno != NULL){
              *enviaAluno = aluno;
              aux = colInserir(c,(void*)enviaAluno);
              if(aux==TRUE){
                printf("\nAluno cadastrado com sucesso\n");
              }
              else{
                printf("\nFalha no cadastro, repita a operação\n");
              }
            }
            ///////////////////////////////////////
          }
        }
        else{
          printf("\nPrimeiro você deve criar a coleção\n");
        }
        break;
      case 3: //Remover
        if(c!= NULL && c->numItens>=0){
          nomeAluno = (char*) malloc(sizeof(char*)*50);
          printf("\nDigite o nome do aluno que será removido: ");
          scanf("%s",nomeAluno);
          fflush(stdin);
          if(c->numItens >= 0){
            remov = colRemover(c,(void*)nomeAluno,cpm);
            if(remov == NULL){
                printf("\nO aluno não foi encontrado sendo assim não pode ser retirado\n");
              }else{
                printf("\nAluno removido\n");
              }
          }else{
            printf("\nEstá colecao nao possui alunos ainda\n");
          }
        }else{
          printf("\nSua colecao ainda nao foi criada\n");
        }
        break;
      case 4:
        if(c!= NULL && c->numItens>=0){
          nomeAluno = (char*) malloc(sizeof(char*)*50);
          printf("\nDigite o nome do aluno que será buscado: ");
          scanf("%s",nomeAluno);
          fflush(stdin);
          if(c->numItens >= 0){
            buscaNome = colBuscar(c, (void*)nomeAluno,cpm);
            if(buscaNome == NULL){
              printf("\nO aluno não foi encontrado\n");
            }else{
                printf("\nAluno encontrado\n");
              } 
            fflush(stdin);
          }else{
            printf("\nEstá colecao nao possui alunos ainda\n");
          }
        }else{
          printf("\nSua colecao ainda nao foi criada\n");
        }
        break;
      case 5: 
        if (c!=NULL && c->numItens >= 0){
          printf("\n------------ Colecao ---------------\n");
          for(int i = 0; i <= c->numItens; i++){
            print = imprimirColecao(c, i);
            printado = (Aluno*) print; 
            printf("\n Aluno - nome:%s\tmatricula:%lu\tcr:%.2f", (char*)(*printado)->nomeAluno, (long int)(*printado)->matricula, (float)(*printado)->CR);
          }
          printf("\n------------------------------------\n");
        }
        else{
          printf("\nPrimeiro voce deve criar uma colecao e inserir algum aluno\n");
        }  
        break;
      case 6:
        printf("\nDeseja excluir colecao? (0-Nao 1-Sim): ");
        scanf("%d", &excluir);
        if(excluir == 0){
          break;
        }
        else{ 
          if(excluir == 1){
            if(c!=NULL){
              coldest = coldestruir(c);
              if(coldest == TRUE){
                printf("\nColecao destruida\n");
              }
              else{
                printf("\nFalha na destruicao da colecao\n");
              }
            } 
            else{
              printf("\nPrimeiro voce deve criar uma colecao\n");
            }
          }
        }
      break;
    }
  }while(opc!=0);
  
  printf("\nObrigada por usar nosso sistema\n");

    
}


// verifica se o nome do aluno está na colecao
int cpm(const void* elm, const void* nome){ 
  int i=0, count=0;
  Colecao *col;
  Aluno **a;
  col = (Colecao*) elm;
  a = (Aluno*)col;
  char *alu = (char*) (*a)->nomeAluno;
  char *nom = (char*)nome ;
  for(i=0; i < strlen(alu); i++){
    if(alu[i] == nom[i]){
      count++;
    }
  }
  if(count == strlen(alu)){
    return TRUE;
  }else{
    return FALSE;
  }
}


