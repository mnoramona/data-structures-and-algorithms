#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "list.h"
#include "taskuri.h"
#include "ajutor.h"

double coeficient(int n, int k){
    double numitor = 0;
    int i;
    for(i = 0; i < k; i++){
        numitor += ((double)i/(k - 1)) * ((double)i/(k - 1)) * 0.9 + 0.1;
    }
    double numarator;
    numarator = ((double)n/(k - 1)) * ((double)n/(k - 1)) * 0.9 + 0.1;
    return numarator / numitor;
}

double valoare(Tlist *left, Tlist *right, int timestamp){
    double scalar, value;
    int i;
    double sumaleft = 0, sumaright = 0;
    Tnode *aux1 = left->head;
    Tnode *aux2 = right->head;
    int k = left->len;
    for(i = 0; i < k; i++){
        sumaleft += aux1->data * coeficient(i, k);
        aux1 = aux1->next;
        sumaright += aux2->data * coeficient(i, k);
        aux2 = aux2->next;
    }

    scalar = (double)(timestamp - left->tail->timestamp) / (right->tail->timestamp - left->tail->timestamp);
    value = (1 - scalar) * sumaleft + scalar * sumaright;
    return value;
}

Tlist *completare(Tlist *lista){
    Tnode *nodu = lista->head->next->next->next; // sa n-am prev = NULL
    int k = 3;
    int pas = 200;
    int timestamp;
    int contor = 3; // pozitia 4
    while(nodu != NULL){
        if(nodu->timestamp - nodu->prev->timestamp >= 1000){
            Tlist *left = initializez_lista();
            Tlist *right = initializez_lista();
            inserez_nod(left, nodu->prev->prev->prev->data, nodu->prev->prev->prev->timestamp, left->len); // left[0]
            inserez_nod(left, nodu->prev->prev->data, nodu->prev->prev->timestamp, left->len); // left[1]
            inserez_nod(left, nodu->prev->data, nodu->prev->timestamp, left->len); // left[2]

            inserez_nod(right, nodu->next->next->data, nodu->next->next->timestamp, right->len); // right[0]
            inserez_nod(right, nodu->next->data, nodu->next->timestamp, right->len); // right[1]
            inserez_nod(right, nodu->data, nodu->timestamp, right->len); // right[2]
            
            timestamp = nodu->prev->timestamp + pas;
            while(nodu->timestamp > timestamp){
                inserez_nod(lista, valoare(left, right, timestamp), timestamp, contor);
                contor++;
                timestamp = timestamp + pas;
            }
            distrug_lista(left);
            distrug_lista(right);
        }
        nodu = nodu->next;
        contor++;
    }
    return lista;
}