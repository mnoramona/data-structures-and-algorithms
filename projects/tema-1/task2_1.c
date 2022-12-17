#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "list.h"
#include "taskuri.h"
 
Tlist *exceptii(Tlist *lista){
    double value;
    int timestamp;
    int k = 5;
    int i, j;
    int n;
    double suma1, suma2;
    double media, sigma;
    Tlist *buna = initializez_lista(); // lista finala cu valorile bune
    Tnode *nodu = lista->head->next->next; //sar peste primele k/2 elemente pentru calcularea mediei si deviatiei
    inserez_nod(buna, lista->head->data,  lista->head->timestamp, buna->len);
    inserez_nod(buna, lista->head->next->data,  lista->head->next->timestamp, buna->len);
    while(nodu->next->next != NULL){
        media = 0, suma1 = 0, sigma = 0, suma2 = 0;
        double elem1 = nodu->prev->prev->data;
        double elem2 = nodu->prev->data;
        double elem3 = nodu->data;
        double elem4 = nodu->next->data;
        double elem5 = nodu->next->next->data;
        suma1 = elem1 + elem2 + elem3 + elem4 + elem5;
        media = suma1/k;  // Media valorilor numerice din fereastra
        suma2 = (elem1 - media)*(elem1 - media) + (elem2 - media)*(elem2 - media) + (elem3 - media)*(elem3 - media) + (elem4 - media)*(elem4 - media) + (elem5 - media)*(elem5 - media);
        sigma = sqrt(suma2/k);  // Deviatia standard a valorilor din fereastra
        if( nodu->data >= media - sigma && nodu->data <= media + sigma ) {
            inserez_nod(buna, nodu->data,  nodu->timestamp, buna->len);
        }
        nodu = nodu->next;
    }
    inserez_nod(buna, lista->tail->prev->data,  lista->tail->prev->timestamp, buna->len);
    inserez_nod(buna, lista->tail->data,  lista->tail->timestamp, buna->len);
    distrug_lista(lista);
    return buna;
}