#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void enqueue(queue_t *queue, int value) {
    /* TODO
     *      Adauga un nou element in coada
     *      - Daca nu exista elemente in coada se seteaza atat 'head', cat si 'tail' ca fiind noul nod
     *      - Altfel, se introduce noul element la inceput de lista */
    node_t *nodulmeu = initNode(value);
    if(queue->len == 0){ //lista vida
        queue->head = nodulmeu;
        queue->tail = nodulmeu;
        queue->head->prev = NULL;
        queue->tail->next = NULL;
        queue->len = 1;
    }
    else{
        nodulmeu->next = queue->head;
        queue->head->prev = nodulmeu;
        queue->head = nodulmeu;
        queue->len++;
    }  
}

int dequeue(queue_t *queue, int *status) {
    /* TODO
     *      Elimina elementul de la sfarsitul cozii
     *      - Daca nu exista elemente in coada:
     *          - Se seteaza statusul pe valoarea STATUS_ERR (1)
     *          - Se returneaza orice valoare
     *      - Altfel:
     *          - Se copiaza valoarea nodului
     *          - Se seteaza statsul pe valoarea STATUS_OK (0)
     *          - Se returneaza valoarea nodului*/
    int value;
    if(queue->len == 0){
        *status = STATUS_ERR;
        return -1;
    }
    else if(queue->len == 1){
        node_t *nunodul;
        value = queue->head->data;
        free(nunodul);
        queue->tail = NULL;
        queue->head = NULL;
        queue->len--;
        *status = STATUS_OK;
    }
    else{
        node_t *nunodul;
        value = queue->head->data;
        nunodul = queue->head;
        queue->head = nunodul->next;
        queue->head->prev = NULL;
        queue->len--;
        free(nunodul);
        *status = STATUS_OK;
    }
    return value;
}

int peek(queue_t *queue, int *status) {
    /* TODO
     *      Afiseaza valoarea elementului de la sfarsitul cozii
     *      - Daca nu exista elemente in coada:
     *          - Se seteaza status pe valoarea STATUS_ERR (1)
     *          - Se returneaza orice
     *      - Altfel:
     *          - Se seteaza statusul pe valoarea STATUS_OK (0)
     *          - Se returneaza campul 'data' al ultimului nod din coada */
    if(queue->len == 0){
        *status = STATUS_ERR;
        return -1;
    } 
    else *status = STATUS_OK;
    return queue->tail->data;
}
