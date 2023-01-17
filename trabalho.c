#include <stdio.h>
#include <stdlib.h>

struct Node{
  int codigo, ano;
  char titulo[30], produtora[30], diretora[30];
  struct Node *prox;
};
typedef struct Node node;

int tam;

int menu(void);
void opcao(node* FILA_1990, node* FILA_2000, node* FILA_2010, node* FILA_2020, int op);
void inicia(node* FILA);
int vazia(node* FILA_1990);
int vazia(node* FILA_2000);
int vazia(node* FILA_2010);
int vazia(node* FILA_2020);
node *aloca();
void insere(node* FILA_1990, node* FILA_2000, node* FILA_2010, node *FILA_2020, int escolha);
node retira(node FILA_1990, node* FILA_2000, node* FILA_2010, node* FILA_2020, int escolha);
void exibe(node* FILA_1990, node* FILA_2000, node* FILA_2010, node* FILA_2020, int escolha);
void libera(node* FILA_1990, node* FILA_2000, node* FILA_2010, node* FILA_2020);


int main(void){
  node *FILA_1990 = (node *) malloc(sizeof(node));
  node *FILA_2000 = (node *) malloc(sizeof(node));
  node *FILA_2010 = (node *) malloc(sizeof(node));
  node *FILA_2020 = (node *) malloc(sizeof(node));
  
  if(!FILA_1990 || !FILA_2000 || !FILA_2010 || !FILA_2020){
    printf("Sem memoria disponivel!\n");
    exit(1);
    }
  else{
   inicia(FILA_1990);
   inicia(FILA_2000);
   inicia(FILA_2010);
   inicia(FILA_2020);
   int opt;

  do{
    opt=menu();
    opcao(FILA_1990, FILA_2000, FILA_2010, FILA_2020, opt);
  }
  while(opt);

  free(FILA_1990);
  free(FILA_2000);
  free(FILA_2010);
  free(FILA_2020);
  return 0;
  }
}


int menu(void){
  int opt;

  printf("\n-=-=-=-= Escolha a opção -=-=-=-=\n");
  printf("0. Sair\n");
  printf("1. Zerar fila\n");
  printf("2. Exibir fila\n");
  printf("3. Adicionar Elemento na Fila\n");
  printf("4. Retirar Elemento da Fila\n");
  printf("Opção: "); 
  scanf("%d", &opt);

 return opt;
}

void opcao(node *FILA, node *FILA_2, node *FILA_3, node *FILA_4, int op) { 
  int escolha;
  node *tmp;
  node *tmp_2;
  node *tmp_3;
  node *tmp_4;
  switch(op){
    case 0:
     libera(FILA, FILA_2, FILA_3, FILA_4);
     break;
  
    case 1:
     libera(FILA, FILA_2, FILA_3, FILA_4);
     inicia(FILA);
     inicia(FILA_2);
     inicia(FILA_3);
     inicia(FILA_4);
     break;
  
    case 2:
      printf("Escolha a década que deseja exibir 1990/2000/2010/2020:\n");
      scanf("%d", &escolha);
      exibe(FILA, FILA_2, FILA_3, FILA_4, escolha);
     break;
  
    case 3:
      printf("Escolha a década em que deseja adicionar o disco 1990/2000/2010/2020:\n");
      scanf("%d", &escolha);
      insere(FILA, FILA_2, FILA_3, FILA_4, escolha);
      break;
    case 4:
      printf("Escolha a década em que deseja remover o disco 1990/2000/2010/2020:\n");
      scanf("%d", &escolha);
      tmp= retira(FILA, FILA_2, FILA_3, FILA_4, escolha);
        if(tmp != NULL){
          printf("Retirado: %s\n\n", tmp->titulo);
          free(tmp);
        } 
      break;
    }
  }


 

void inicia(node *FILA){
  FILA->prox = NULL;
  tam=0;
  }

int vazia(node *FILA){
 if(FILA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca(){
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }
 else{
  printf("-=-=-=-= Preencha as informções sobre o livro =-=-=-=-\n");
  printf("Código do disco:\n");
  scanf("%d", &novo->codigo);
  printf("Título:\n");
  scanf("%29s", novo->titulo);
  printf("Diretora:\n");
  scanf("%29s", novo->diretora);
  printf("Produtora:\n");
  scanf("%29s", novo->produtora);
  printf("Ano de produção:\n");
  scanf("%d", &novo->ano);
  return novo;
 }
}

void insere(node *FILA, node *FILA_2, node *FILA_3, node *FILA_4, int escolha){
  node* novo = aloca();
  node *tmp;
  novo->prox = NULL;
  switch(escolha){
    case(1990):
      if (novo->ano >= 1990 && novo->ano < 2000){
        if(vazia(FILA))
          FILA->prox=novo;
        else{
          tmp = FILA->prox;
          while(tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
        }
      }
      else
        printf("Década incompartivel!");
      break;
    case(2000):
      if (novo->ano >= 2000 && novo->ano < 2010){
        if(vazia(FILA_2))
          FILA_2->prox=novo;
        else{
          tmp = FILA_2->prox;
          while(tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
        }
      }
      else
        printf("Década incompartivel!");
      break;
    case(2010):
      if (novo->ano >= 2010 && novo->ano < 2020){
        if(vazia(FILA_3))
          FILA_3->prox=novo;
        else{
          tmp = FILA_3->prox;
          while(tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
        }
      }
      else
        printf("Década incompartivel!");
      break;
    case(2020):
      if (novo->ano >= 2020 && novo->ano < 2023){
        if(vazia(FILA))
          FILA_4->prox=novo;
        else{
          tmp = FILA_4->prox;
          while(tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
        }
      }
      else
        printf("Década incompartivel!");
      break;
    default:
      printf("Comando inválido! Digite corretamente!");
  }
}


node* retira(node *FILA, node *FILA_2, node *FILA_3, node *FILA_4, int escolha){
  node* tmp;
  switch(escolha){
    case(1990):
      if(FILA->prox == NULL){
        printf("Fila já esta vazia!\n");
        return NULL;
      } 
      else{
        tmp = FILA->prox;
        FILA->prox = tmp->prox;
        //tam--;
        return tmp;
        }
      break;
    case(2000):
      if(FILA_2->prox == NULL){
        printf("Fila já esta vazia!\n");
        return NULL;
      } 
      else{
        tmp = FILA_2->prox;
        FILA_2->prox = tmp->prox;
        return tmp;
        }
      break;
    case(2010):
      if(FILA_3->prox == NULL){
        printf("Fila já esta vazia!\n");
        return NULL;
        } 
      else{
        tmp = FILA_3->prox;
        FILA_3->prox = tmp->prox;
        return tmp;
        }
      break;
    case(2020):
      if(FILA_4->prox == NULL){
        printf("Fila já esta vazia!\n");
        return NULL;
        } 
      else{
        tmp = FILA_4->prox;
        FILA_4->prox = tmp->prox;
        return tmp;
        }
      break;
    default:
      printf("Comando inválido! Digite corretamente!");
  }
}


void exibe(node *FILA, node *FILA_2, node *FILA_3, node *FILA_4, int escolha){
  int c = 1;
  node* tmp;
  switch(escolha){
    case(1990):
      if(vazia(FILA)){
        printf("Fila vazia!\n\n");
        return;
      }
      
      tmp = FILA->prox;
      while( tmp != NULL){
        printf("-=-=-=-=-= Informações do disco %d: -=-=-=-=-=\n", c);
        printf("%d\n", tmp->codigo);
        printf("%s\n", tmp->titulo);
        printf("%s\n", tmp->diretora);
        printf("%s\n", tmp->produtora);
        printf("%d\n", tmp->ano);
        c++;
        tmp = tmp->prox;
        }
      break;
      case(2000):
        if(vazia(FILA_2)){
          printf("Fila vazia!\n\n");
          return;
        }
        tmp = FILA_2->prox;
        
        while( tmp != NULL){
          printf("-=-=-=-=-= Informações do disco %d: -=-=-=-=-=\n", c);
          printf("%d\n", tmp->codigo);
          printf("%s\n", tmp->titulo);
          printf("%s\n", tmp->diretora);
          printf("%s\n", tmp->produtora);
          printf("%d\n", tmp->ano);
          c++;
          tmp = tmp->prox;
        }
        break;
    case(2010):
      if(vazia(FILA_3)){
          printf("Fila vazia!\n\n");
          return;
        }
        tmp = FILA_3->prox;
        
        while( tmp != NULL){
          printf("-=-=-=-=-= Informações do disco %d: -=-=-=-=-=\n", c);
          printf("%d\n", tmp->codigo);
          printf("%s\n", tmp->titulo);
          printf("%s\n", tmp->diretora);
          printf("%s\n", tmp->produtora);
          printf("%d\n", tmp->ano);
          c++;
          tmp = tmp->prox;
        }
      break;
    case(2020):
      if(vazia(FILA_4)){
          printf("Fila vazia!\n\n");
          return;
        }
        tmp = FILA_4->prox;
        while( tmp != NULL){
          printf("-=-=-=-=-= Informações do disco %d: -=-=-=-=-=\n", c);
          printf("%d\n", tmp->codigo);
          printf("%s\n", tmp->titulo);
          printf("%s\n", tmp->diretora);
          printf("%s\n", tmp->produtora);
          printf("%d\n", tmp->ano);
          c++;
          tmp = tmp->prox;
        }
      break;
    default:
      printf("Comando inválido! Digite corretamente!");
  }
}

void libera(node *FILA, node *FILA_2, node *FILA_3, node *FILA_4){
  if(!vazia(FILA)){
    node *proxNode, *atual;
    atual = FILA->prox;
  while(atual != NULL){
     proxNode = atual->prox;
     free(atual);
     atual = proxNode;
      }
    }
  if(!vazia(FILA_2)){
    node *proxNode, *atual;
    atual = FILA->prox;
  while(atual != NULL){
     proxNode = atual->prox;
     free(atual);
     atual = proxNode;
    }
  }
  if(!vazia(FILA_3)){
    node *proxNode, *atual;
    atual = FILA->prox;
  while(atual != NULL){
     proxNode = atual->prox;
     free(atual);
     atual = proxNode;
    }
  }
  if(!vazia(FILA_4)){
    node *proxNode, *atual;
    atual = FILA->prox;
  while(atual != NULL){
     proxNode = atual->prox;
     free(atual);
     atual = proxNode;
    }
  }
}