#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "list.h"
#include "taskuri.h"

Tlist *uniformizare(Tlist *lista){
    double value;
    int timestamp;
    int k = 5;
    int i, j;
    int n;
    Tnode *nodu = lista->head->next; //sar peste primele k/2 elemente pentru calcularea mediei si deviatiei
    while(nodu != NULL){
        if(nodu->timestamp - nodu->prev->timestamp >= 100 && nodu->timestamp - nodu->prev->timestamp <= 1000){
            value = (nodu->prev->data + nodu->data)/2;
            timestamp = (nodu->prev->timestamp + nodu->timestamp)/2;
            nodu->data = value;
            nodu->timestamp = timestamp;
        }
        nodu = nodu->next;
    }
    return lista;
}