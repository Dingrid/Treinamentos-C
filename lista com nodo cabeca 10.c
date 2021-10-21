#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char data;
    struct no* prox;
    } ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT cabeca;
    } LISTA;

void inicializarLista(LISTA* l) {
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
}

void push(LISTA* lista, char elem) {
  PONT aux =(PONT) malloc(sizeof(ELEMENTO));
  aux->data = elem;
  aux->prox = lista->cabeca->prox;
  lista->cabeca->prox=aux;
}

void exibirLista(LISTA* l) {
    PONT end = l->cabeca->prox;
    while (end != l->cabeca) {
      printf("%c ", end->data);
      end = end->prox;
    }
}

void pop(LISTA *l) {
    PONT end = l->cabeca->prox;
    PONT endA = l->cabeca->prox;
    int i=0;
    endA = endA->prox;
    while (endA->prox != l->cabeca) {
      end = end->prox;
      endA = endA->prox;
      i++;
    }
    end->prox=l->cabeca;
    endA->prox=NULL;
    free(endA->prox);      
}


int main() {
   LISTA a;
   inicializarLista(&a);
   push(&a,'a');
   push(&a,'b');
   push(&a,'c');
   printf("Exibindo lista\n");
   exibirLista(&a);
   pop(&a);
   
   printf("\nExibindo lista remoção\n");
   exibirLista(&a);
}

/*Não achei nada sobre nodo cabeça nos slides, logo procurei referências http://www.each.usp.br/digiampietri/ed/aula07.pdf 
*/