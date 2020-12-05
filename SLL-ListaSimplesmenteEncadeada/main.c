
#include "sllist.h"



int cpm(const void* nome1, const void* nome2);

int main(void) {

  int inseriu, aux, n, a,opc, tamList;
  char nomeBusca[30], *Nome;
  SLList *lista = NULL;
  Aluno *aluno = NULL, **enviaAluno, **impAluno;
  void* busca;
  void* imprime;
  int Matricula;
  float CR;
  
  do{
      printf("\n------------------MENU-----------------\n");
      printf("1 - Criar uma lista\n");
      printf("2 - Inserir\n");
      printf("3 - Buscar\n");
      printf("4 - Remover\n");
      printf("5 - Destruir\n");
      printf("6 - Listar\n");
      printf("0 - Sair\n");
      scanf("%d",&opc);
      switch(opc){
        case 1:
          if(lista == NULL){
            lista = SLCreate();
            if(lista != NULL){
            
            }else{
              printf("Problemas na criação da lista");
              opc = 0;
            }
          }else{
            printf("\nOutra lista não pode ser criada\n");
          }  
        break;
        case 2:
          if(lista != NULL){
            aluno = (Aluno*)malloc(sizeof(Aluno));
            if(aluno != NULL){ 
              printf("\nInsira o nome: ");
              scanf("%s", aluno->nomeAluno);
              fflush(stdin);
              printf("\nInsira o numero de matricula do aluno: ");
              scanf("%d", &aluno->matricula);
              fflush(stdin);
              printf("\nInsira o CR:");
              scanf("%f", &aluno->CR);
              fflush(stdin);
              enviaAluno = (Aluno**) malloc(sizeof(Aluno*));
              if(enviaAluno != NULL){
                *enviaAluno = aluno;
                aux = slInsertFirst(lista,(void*)enviaAluno);
                if(aux==TRUE){
                  printf("\nAluno cadastrado com sucesso\n");
                }
                else{
                  printf("\nErro no cadastro do Aluno\n");
                }
              }
            }
          }else{
            printf("\nA lista não existe\n");
          }
        break;
        case 3:
          if(lista != NULL){
            printf("\nDigite o nome do aluno que deseja buscar:\n");
            scanf("%s",nomeBusca);
            busca = sllQuery(lista, (void*)nomeBusca, cpm);
            if(busca != NULL){
              printf("\nAluno encontrado\n");
            }
            else{
              printf("\nAluno não encontrado\n");
            }
          }else{
            printf("\nA lista não existe\n");
          }
          break;
          case 4:
            if(lista != NULL){
              printf("\nDigite o nome do aluno que deseja remover:\n");
              scanf("%s",nomeBusca);
              busca = sllRemoveQuery (lista, (void*)nomeBusca, cpm);
              if(busca != NULL){
                printf("\nAluno removido com sucesso!\n");
              }
              else{
                printf("\nFalha na remoção do aluno\n");
              }
            }else{
              printf("\nA lista não existe\n");
            }
          break;
          case 5:
            if(lista != NULL){
              a = sllDestroy(lista);
              if(a == 1){
                printf("\nLista Destruida\n");
                lista = NULL;
              }
              else{
                printf("\nHouve uma falha na destruição da lista\n");
              }
            }else{
              printf("\nA lista não existe\n");
            }
        break;
        case 6:
          if(lista != NULL){
            tamList = sllGetNumElms(lista);
            if(tamList > 0){
              printf("\n--------- Alunos ------------\n");
              for(int i = 0; i < tamList; i++){
                imprime = imprimir(lista, i);
                impAluno = (Aluno**)imprime;
                Nome = (char*) (*impAluno)->nomeAluno;
                Matricula = (int) (*impAluno)->matricula;
                CR  = (float) (*impAluno)->CR ;
                printf("\nNome: %s\nCR: %.2f\nMatricula: %d\n\n", Nome, CR, Matricula);
              }
              printf("\n----------------------------\n");
            }else{
              printf("\nFalha!!\nAlunos nao podem ser impressos\n");
            }
          }else{
            printf("\nA lista não existe\n");
          }
        break;
      }
  }while(opc != 0);
}

 

// verifica se o nome do aluno está na colecao
int cpm(const void* nome1, const void* nome2){ 
  int i=0, count=0;
  Aluno **aluno; 
  char *dataNome;
  aluno = (Aluno**)nome1;
  dataNome = (char*) (*aluno)->nomeAluno;
  char *nom = (char*)nome2 ;
  if(strcmp(nom, dataNome) == 0){
    return TRUE;
  }else{
    return FALSE;
  }
}


























  
