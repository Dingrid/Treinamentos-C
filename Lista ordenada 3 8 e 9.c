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

void push(ptr *L,char x) {
    if (*L == NULL || x <= (*L)->data) {
    ptr a = malloc(sizeof(struct nodo));
    a->data = x;
    a->link = *L;
    *L = a;
}
    else push(&(*L)->link,x);
}


int pop(char x, ptr *L) {
    if (*L == NULL || x < (*L)->data) return 0;
    if (x == (*L)->data) 
    {
        ptr a = *L;
        *L = a->link;
        free(a);
        return 1;
    }
    return pop(x, &(*L)->link);
}

void destroi_r(ptr *L) {
    if (*L == NULL) return;
    destroi_r(&(*L)->link);
    free(*L);
    *L = NULL;
}


void exibe(ptr L) {
    if (L == NULL) return;
    printf("%c ", L->data);
    exibe(L->link);
}

 
//8. Crie uma função que receba duas listas ordenadas e exiba a intercalação crescente de seus elementos
void ordena(ptr *lista,ptr lista1) {
     // Coloque aqui seu código 
     while(lista1 !=NULL){
        push(lista,lista1->data);
        lista1 =lista1->link;
     }
}


//9. Crie uma função que receba duas listas ordenadas e devolva uma nova lista com a intercalação crescente dos 
//elementos das duas primeiras
ptr ordenaC(ptr lista,ptr lista1) {
     // Coloque aqui seu código 
     ptr aux=NULL;
    do{ 
        push(&aux,lista1->data);
        lista1 =lista1->link;
     }while(lista1 !=NULL);
     do{ 
        push(&aux,lista->data);
        lista =lista->link;
     }while(lista !=NULL);
     return aux;
}

int main(void) {
    printf("\nTestando a lista...\n");
    ptr p,p1,p2;
    create(&p);
    create(&p1);
    
    printf("\npush A\n");
    push(&p,'A');
    printf("\npush B\n");
    push(&p,'B');
    printf("\npush C\n");
    push(&p,'C');
    printf("\npush E\n");
    push(&p,'E');
    printf("\npush H\n");
    push(&p,'H');
    printf("\nExibe Lista 1\n");
    exibe(p);
    
    printf("\npush F\n");
    push(&p1,'F');
    printf("\npush F\n");
    push(&p1,'F');
    printf("\npush A\n");
    push(&p1,'A');
    printf("\nExibe Lista 2\n");
    exibe(p1);
    
    printf("\nExibe Ordenação que gera outra lista\n");
    p2=ordenaC(p,p1);
    exibe(p2);
    
    printf("\nExibe Ordenação simples\n");
    ordena(&p,p1);
    exibe(p);

    return 0;
}  

