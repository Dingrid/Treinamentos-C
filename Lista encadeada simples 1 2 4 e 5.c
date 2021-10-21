#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
          char data;
          struct nodo *link;
        } *ptr;

void create(ptr *lista) {
     // Coloque aqui seu código  
     *lista = NULL;
}

void push(ptr *lista, char elem) {
     // Coloque aqui seu código    
     ptr aux=malloc(sizeof(struct nodo));
     aux->data = elem;
     aux->link = *lista;
     *lista = aux;
}

char pop(ptr *lista) {
     // Coloque aqui seu código 
     ptr aux;
     aux = *lista;
     *lista = aux->link;
     char a= aux->data;
     free(aux);
     return a;
}

char top(ptr lista) {
     // Coloque aqui seu código   
     return lista->data;
}

void exibe(ptr lista) {
     // Coloque aqui seu código   
     while(lista !=NULL) {
     printf("%c",lista->data);
     lista =lista->link;}
}
 
 /* 1. Crie uma função que receba uma lista e retorne sua quantidade de elementos;*/
int qtd(ptr lista) {
     // Coloque aqui seu código 
     int i=0;
     while(lista !=NULL) {
     lista =lista->link;
         i++;
     }
     return i;
}

 
/* 2. Crie uma função que receba duas listas e concatene a segunda na primeira;*/
void concatena(ptr *lista,ptr lista1) {
     // Coloque aqui seu código 
     ptr aux=lista1;
     while(lista1->link !=NULL){
        lista1 =lista1->link;
     }
     lista1->link = *lista;
    *lista = aux;
}

/*4. Crie uma função que receba uma lista simples e transforme-a em uma lista circular.*/
void simplesCircular(ptr lista)
{
    if(lista ==NULL) return;
    ptr aux= lista;
    while(aux->link !=NULL)
        aux=aux->link;
    aux->link =lista;
}

/*5. Crie uma função que receba uma lista circular e retorne sua quantidade de elementos;*/
int qtdC(ptr lista)
{
    int i=0;
    if(lista ==NULL) return i;
    ptr aux=lista;
    do{
        i++;
        aux=aux->link;
    }while(aux!=lista);
    return i;
}

int main(void) {
    printf("\nTestando a pilha...\n");
    ptr p,p1;
    create(&p);
    create(&p1);
    
    
    printf("\npush E\n");
    push(&p,'E');
    printf("\npush T\n");
    push(&p,'T');
    printf("\npush S\n");
    push(&p,'S');
    printf("\npush E\n");
    push(&p,'E');
    printf("\npush T\n");
    push(&p,'T');
    printf("\nExibe Pilha\n");
    exibe(p);
    
    printf("\npush F\n");
    push(&p1,'F');
    printf("\npush F\n");
    push(&p1,'F');
    printf("\npush A\n");
    push(&p1,'A');
    printf("\nExibe Pilha1\n");
    exibe(p1);

    //teste exer1
    int i=qtd(p);
    printf("\nQuantidade: %d\n",i);
    
    /*teste exer2*/
    concatena(&p,p1);
    printf("\nExibe Pilha\n");
    exibe(p);
    
    //teste exer4
    simplesCircular(p);
    
    //teste exer5
    i=qtdC(p);
    printf("\nQuantidade: %d\n",i);

    return 0;
}  

