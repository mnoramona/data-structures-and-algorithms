#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "list.h"
#include "taskuri.h"

Tlist *filtraremediana(Tlist *lista){
    int i;
    Tlist *buna = initializez_lista(); // lista finala cu valorile bune
    Tnode *nodu = lista->head->next->next;
    while(nodu->next->next != NULL){
        Tlist *pentrusortat = initializez_lista();
        crescator(pentrusortat, nodu->prev->prev->data, nodu->prev->prev->timestamp);
        crescator(pentrusortat, nodu->prev->data, nodu->prev->timestamp);
        crescator(pentrusortat, nodu->data, nodu->timestamp);
        crescator(pentrusortat, nodu->next->data, nodu->next->timestamp);
        crescator(pentrusortat, nodu->next->next->data, nodu->next->next->timestamp);
        inserez_nod(buna, pentrusortat->head->next->next->data, nodu->timestamp, buna->len);
        distrug_lista(pentrusortat);
        nodu = nodu->next;
    }
    distrug_lista(lista);
    return buna;
}

Tlist *filtrarearitmetica(Tlist *lista){
    int i, k = 5;
    double media, suma;
    Tlist *buna = initializez_lista(); // lista finala cu valorile bune
    Tnode *nodu = lista->head->next->next;
    while(nodu->next->next != NULL){
        media = 0, suma = 0;
        double elem1 = nodu->prev->prev->data;
        double elem2 = nodu->prev->data;
        double elem3 = nodu->data;
        double elem4 = nodu->next->data;
        double elem5 = nodu->next->next->data;
        suma = elem1 + elem2 + elem3 + elem4 + elem5;
        media = suma/k;  // Media valorilor numerice din fereastra
        inserez_nod(buna, media, nodu->timestamp, buna->len);
        nodu = nodu->next;
    }
    distrug_lista(lista);
    return buna;
}


