#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab05.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

#define NUM_QUEUES 10

int checkBalancedBrackets(char *exp) {
    stack_t *stack = initList();
	int i;
	for(i = 0; i < strlen(exp); i++) {
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
			push(stack, exp[i]);
		} else {
			int status, value = top(stack, &status);
			if(exp[i] == ')' && status == STATUS_OK && value == '(')
				pop(stack, &status);
			else if(exp[i] == ']' && status == STATUS_OK && value == '[')
				pop(stack, &status);
			else if(exp[i] == '}' && status == STATUS_OK && value == '{')
				pop(stack, &status);
		}
	}
	if(stack->len == 0)
		return 1;

    return 0;
}

void radixSort(int *v, int n) {
    int max = -1;
	int i;
    for(i = 0; i < n; i++)
    	if(max < v[i])
    		max = v[i];

	queue_t *queue[10];
	for(i = 0; i < 10; i++)
		queue[i] = initList();
	int p;
	for(p = 1; max / p > 0; p*=10){
		for(i = 0; i < n; i++) {
			int cop = v[i];
			int x = (cop / p) % 10;
			
			enqueue(queue[x], v[i]);
		}

		int status, k = 0;
		for(i = 0; i < 10; i++){
			while(queue[i]->len > 0) 
				v[k++] = dequeue(queue[i], &status);
		}
	}
}
