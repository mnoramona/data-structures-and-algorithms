#include <stdlib.h>
#include "stack.h"

void push(stack_t *stack, int value) {
    /* TODO
     *      Se adauga un nou nod cu valoarea data
     *      ca parametru la inceputul listei */
    node_t *nodulmeu = initNode(value);
    if(stack->len == 0){ //lista vida
        stack->head = nodulmeu;
        stack->tail = nodulmeu;
        stack->head->prev = NULL;
        stack->tail->next = NULL;
        stack->len = 1;
    }
    else{
        nodulmeu->next = stack->head;
        stack->head->prev = nodulmeu;
        stack->head = nodulmeu;
        stack->len++;
    }   
}

int pop(stack_t *stack, int *status) {
    /* TODO
     *      Se elimina nodul din varful stivei si i se returneaza valoarea
     *          - Daca stiva este goala, se seteaza parametrul 'status' la valoarea STATUS_ERR (1)
     *          - Altfel, se seteaza parametrul 'status' la valoarea STATUS_OK (0) */
    int value;
    if(stack->len == 0){
    *status = STATUS_ERR;
    return -1;
    }
    else if(stack->len == 1){
        node_t *nunodul;
        value = stack->head->data;
        free(nunodul);
        stack->tail = NULL;
        stack->head = NULL;
        stack->len--;
        *status = STATUS_OK;
    }
    else{
        node_t *nunodul;
        value = stack->head->data;
        nunodul = stack->tail;
        stack->tail = nunodul->prev;
        stack->tail->next = NULL;
        stack->len--;
        free(nunodul);
        *status = STATUS_OK;
    }
    return value;
}

int top(stack_t *stack, int *status) {
    /* TODO
     *      Se returneaza valoarea nodul din varful stivei
     *          - Daca stiva este goala, se seteaza parametrul 'status' la valoarea STATUS_ERR (1)
     *          - Altfel, se seteaza parametrul 'status' la valoarea STATUS_OK (0) */
    if(stack->len == 0){
        *status = STATUS_ERR;
        return -1;
    } 
    else *status = STATUS_OK;
    return stack->head->data;
}
