#include <stdio.h>
#include <stdlib.h>
 
#include "list.h"
 
Tnode *initializez_nod(int timestamp, double value) {
    Tnode *nodu = malloc(sizeof(Tnode));
    nodu->timestamp = timestamp;
    nodu->data = value;
    nodu->next = NULL;
    nodu->prev = NULL;
    return nodu;
}
 
Tlist *initializez_lista() {
    Tlist *lista = malloc(sizeof(Tlist));
    lista->head = NULL;
    lista->tail = NULL;
    lista->len = 0;
    return lista;
}
 
void eliberez_nod(Tnode *nodu)
{
    free(nodu);
}
 
void distrug_lista(Tlist *lista) {
    Tnode *nodu;
    // Sterg toate nodurile din lista
    while (lista->len > 0) {
        nodu = lista->tail;
        lista->tail = lista->tail->prev;
        eliberez_nod(nodu);
        lista->len--;                        
    }
    //Eliberez memoria ocupata de lista
    free(lista);
}
 
void printez_lista(Tlist *lista) {
    Tnode *nodu = lista->head;
    if (nodu == NULL) {           // Lista vida
        printf("NULL\n");
        return;
    }
    printf("%d\n", lista->len);
    while (nodu!= NULL) {
        printf("%d ", nodu->timestamp);
        printf("%.2lf\n", nodu->data);
        nodu = nodu->next;
    }
}

int inserez_nod(Tlist *lista, double value, int timestamp, int position) {
    if(position < 0 || position > lista->len)
        return -1;
    if(lista->head == NULL){
        Tnode *nodu = initializez_nod(timestamp, value);
        lista->head = nodu;
        lista->tail = nodu;
        lista->len = 1;
    }
    else if(position == 0){
        Tnode *nodu = initializez_nod(timestamp, value);
        nodu->next = lista->head;
        lista->head->prev = nodu;
        lista->head = nodu;
        lista->len++;
    }
    else if(position == lista->len){
        Tnode *nodu = initializez_nod(timestamp, value);
        nodu->prev = lista->tail;
        lista->tail->next = nodu;
        lista->tail = nodu;
        lista->len++;
    }
    else{
        if(position <= lista->len/2){
            Tnode *aux = lista->head;
            for(int i = 0; i < position - 1; i++)
                aux = aux->next;
            Tnode *nodu = initializez_nod(timestamp, value);
            nodu->next = aux->next;
            aux->next->prev = nodu;
            nodu->prev = aux;
            aux->next = nodu;
            lista->len++;
        }
        else{
            Tnode *aux = lista->tail;
            for(int i = lista->len - 1; i > position; i--)
                aux = aux->prev;
            Tnode *nodu = initializez_nod(timestamp, value);
            nodu->prev = aux->prev;
            aux->prev->next = nodu;
            nodu->next = aux;
            aux->prev = nodu;
            lista->len++;
        }
    }
    return 0;
}

Tlist *crescator(Tlist *lista, double value, int timestamp){ 
    if(lista->head == NULL){
        inserez_nod(lista, value, timestamp, 0);
    }
    else{
        Tnode *nodu = lista->head;
        int i = 0;
        while(nodu != NULL && nodu->data < value){
            nodu = nodu->next;
            i++;
        }
        inserez_nod(lista, value, timestamp, i);
    }
    return lista;
}