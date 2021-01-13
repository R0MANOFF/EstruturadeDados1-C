#include "tree.h"

int cmp(const void* nome1, const void* nome2);
void visit(void* data);

int main(void) {
  TNode *t, *raiz;
  Aluno *aluno;
  int matricula;
  TNode *remove = NULL, *query;
  int opc, dest, createIndicator = FALSE, count = 0;

  do{
    printf("\n------------------MENU-----------------\n");
    printf("1 - Criar uma arvore\n");
    printf("2 - Inserir\n");
    printf("3 - Buscar\n");
    printf("4 - Remover\n");
    printf("5 - Destruir\n");
    printf("6 - Listar\n");
    printf("0 - Sair\n");
    scanf("%d",&opc);

    switch(opc){
      case 1: // criar
        if(createIndicator == FALSE){
          raiz = abpCreate();
          createIndicator = TRUE;
          count = 0;
          printf("\narvore criada!\n");
        }else{
          printf("\nUma nova arvore nao pode ser criada!\n");
        }
        
      break;
      case 2: // inserir
        if(createIndicator == TRUE){
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
            if(count == 0){ // primeira inserção
              raiz = abpInsert(raiz, (void*)aluno, cmp);
              remove = raiz;
              if(raiz != NULL){
                printf("\nAluno inserido com sucesso!\n");
                count++;
              }else{
                printf("\nErro ao tentar inserir o aluno\n");
              }
            }else{ // outras inserções
              query = abpQuery(raiz, (void*)aluno, cmp);
              if(query != NULL){
                printf("\nO aluno ja foi inserido anteriormente\n");
              }else{
                t = abpInsert(raiz, (void*)aluno, cmp);
                if(t != NULL){
                  printf("\nAluno inserido com sucesso!\n");
                  count++;
                }else{
                  printf("\nErro ao tentar inserir o aluno\n");
                }
              }   
            }
             
          }
        }
        else{
          printf("\nArvore nao encontrada\n");
        }
      break;
      case 3: // buscar
        if(count > 0 && createIndicator == TRUE){
          aluno = (Aluno*)malloc(sizeof(aluno));
          if(aluno != NULL){
            printf("\nDigite a matricula do aluno que deseja buscar:\n");
            scanf("%d",&aluno->matricula);
          }
          query = abpQuery(raiz, (void*)aluno, cmp);
          if(query != NULL){
            printf("\nAluno encontrado!\n");
          }else{
            printf("\nAluno nao encontrado!\n");
          }
        }else{
          printf("\nCrie uma arvore ou coloque alunos!\n");
        }
      break;
      case 4: // Remover
        if(count > 0 && createIndicator == TRUE){
          aluno = (Aluno*)malloc(sizeof(aluno));
          if(aluno != NULL){
            printf("\nDigite a matricula do aluno que deseja remover:\n");
            scanf("%d",&aluno->matricula);
          }
          query = abpQuery(raiz, (void*)aluno, cmp);
          if(query != NULL){
            raiz = abpRemove(raiz, (void*)aluno, cmp,raiz);
            remove = raiz;
            if(remove != NULL){
              printf("\nAluno removido com sucesso!\n");
            }else{
              printf("\nO ultimo aluno foi removido\n");
              count = 0;
            }
          }else{
            printf("\nAluno nao encontrado portanto nao removido!\n");
          }
        }else{
          printf("\nCrie uma arvore ou coloque alunos!\n");
        }
      break;
      case 5: // Destruir
        if(createIndicator == TRUE){
          dest = destroy(raiz);
          if(dest == TRUE){
            printf("\nA arvore foi destruida\n");
            createIndicator = FALSE;
            count = 0;
          }else{
            printf("\nErro ao tentar destruir a arvore\n");
          }
        }else{
          printf("\nCrie uma arvore primeiro\n");
        }
        
      break;
      case 6: // Listar os alunos
        if(count > 0){
          printf("\n------------------------Alunos--------------------------");
          simetrico(raiz, visit);
          printf("\n--------------------------------------------------------\n");
        }else{
          printf("\nNao ha alunos!");
        }
      break;
      case 0:
        printf("\nObrigada\n");
      break;
    }

  }while(opc != 0);
}

// verifica se o nome do aluno está na árvore 
int cmp(const void* key, const void* data){ 
  Aluno *aluno1, *aluno2; 
  aluno1 = (Aluno*)data;
  aluno2 = (Aluno*)key;

  int matricula;
  matricula = (int)aluno1->matricula;
  int elm;
  elm = (int)aluno2->matricula;
  if(elm > matricula){
    return 1;
  }else{
    if(elm < matricula){
      return -1;
    }
    return 0;
  }
  
}

// função que imprime o conteúdo de cada nó da árvore
void visit(void* data){
  Aluno *aluno;
  aluno = (Aluno*)data;
  int matricula;
  float CR;
  char *nome;
  matricula = (int)aluno->matricula;
  CR = (int)aluno->CR;
  nome = (char*)malloc(sizeof(char)*30);
  printf("\n");
  if(nome != NULL){
    nome = aluno->nomeAluno;
    printf("\n\tNome: %s \t Matricula: %d \t CR: %.2f", nome, matricula, CR);
  } 
  printf("\n");
}


