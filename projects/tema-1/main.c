#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
#include "list.h"
#include "taskuri.h"

int main(int argc, char *argv[]){
    int i, timestamp, numarperechi;
    double value;
    int lungime;
    Tlist *lista = initializez_lista();
    scanf("%d", &numarperechi);
    for(i = 0; i < numarperechi; i++){
            scanf("%d %lf",&timestamp, &value);
            inserez_nod(lista, value, timestamp, lista->len);
    }
    for(i = 0; i < argc; i++){
        if(strcmp(argv[i], "--e1") == 0){
            lista = exceptii(lista);
        }
        else if(strcmp(argv[i], "--e2") == 0){
            lista = filtraremediana(lista);
            
        }
        else if(strcmp(argv[i], "--e3") == 0){
            lista = filtrarearitmetica(lista);
        }
        else if(strcmp(argv[i], "--u") == 0){
            lista = uniformizare(lista);
        }
        else if(strcmp(argv[i], "--c") == 0){
            lista = completare(lista);
        }
        else if(strstr(argv[i], "--st") != NULL ){
            char *nr = argv[i] + 4;
            int delta = 0;
            int j;
            for(j = 0; j < strlen(nr); j++){
                delta = delta*10 + nr[j] - '0';
            }
            statistici(lista, delta);
            distrug_lista(lista);
            return 0;
        }
    }
    printez_lista(lista);
    distrug_lista(lista);
    return 0;
}
