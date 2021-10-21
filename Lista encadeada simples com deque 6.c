#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    int data;
    struct NO* prox;
}NO;

typedef struct lista{
    NO* ini;
    NO* fim;
}lista;


/*6. Crie as funções de um deque (inclusões e remoções pelas extremidades) com uma lista simples;*/

void insereNoInicio(lista *l,int x){
    NO *ptr = (NO*) malloc(sizeof(NO));
    ptr->data=x;
    ptr->prox=NULL;
    
    if(l->ini==NULL){
        l->fim=ptr;
    }else{
        ptr->prox=l->ini;
            }
    l->ini=ptr;
}

void insereNoFim(lista *l,int x){
    NO *ptr = (NO*) malloc(sizeof(NO));
    ptr->data=x;
    ptr->prox=NULL;

    if(l->ini==NULL){
        l->ini=ptr;
    }else{
        l->fim->prox = ptr;    
        }
    l->fim = ptr;
}

void exibe(lista *l){
    NO* ptr=l->ini;
    while(ptr !=NULL){
        printf("%d",ptr->data);
        ptr=ptr->prox;
    }
}

void retira(lista *l, int lado) {
  // coloque aqui seu código
    if(lado==2) //retira no fim
    {
        NO* aux=l->ini;
        int i=0;
        while(aux->prox!=NULL){
          aux=aux->prox;
          i++;
        }
        free(l->fim);
        aux=l->ini;
        for(int j=1;j<i;j++){
          aux=aux->prox;
        }
        l->fim=aux;
        l->fim->prox = NULL;
    }
   if(lado==1) //retira no inicio
    {
        NO* aux=l->ini;
        aux=aux->prox;
        free(l->ini);
        l->ini=aux;
    }
}

int main(){
    lista l;
    l.ini=NULL;
    l.fim=NULL;

    insereNoInicio(&l,3);
    insereNoInicio(&l,1);
    insereNoFim(&l,3);
    insereNoFim(&l,4);
    exibe(&l);
    
    retira(&l,2);
    printf("\n Exibe depois de retirar do fim\n");
    exibe(&l);
    
    retira(&l,1);
    printf("\n Exibe depois de retirar do inicio\n");
    exibe(&l);
}