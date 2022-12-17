#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "list.h"
#include "taskuri.h"

void statistici(Tlist *lista, int lungime){
    int contor = 0, i;
    double ajutordeinterval;
    Tnode *nodu = lista->head;
    Tlist *pentrusortat = initializez_lista();
    while(nodu != NULL){
        crescator(pentrusortat, nodu->data, nodu->timestamp);
        nodu = nodu->next;
    }
    nodu = pentrusortat->head;
    ajutordeinterval = floor(pentrusortat->head->data);
    while(nodu != NULL){
        if(nodu->data >= ajutordeinterval && nodu->data <= (ajutordeinterval + lungime)){
            contor++;
        }
        else{
            printf("[%0.0lf, %0.0lf] %d\n", ajutordeinterval, ajutordeinterval + lungime, contor);
            contor = 1;
            while(nodu->data > ajutordeinterval + lungime){
                ajutordeinterval = ajutordeinterval + lungime;
            }
        }
        nodu = nodu->next;
    }
    if(contor > 0) printf("[%0.0lf, %0.0lf] %d\n", ajutordeinterval, ajutordeinterval + lungime, contor);
    distrug_lista(pentrusortat);
}