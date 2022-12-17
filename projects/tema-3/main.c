#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "graph.h"
#define INF 99999

int main(void){
    int i, j, k;
    // Prima linie va contine numerele naturale n, m si d ce reprezinta numarul de noduri, numarul
    // de arce si numarul de depozite din graf;
    
    int n; // nr. de noduri
    int m; // nr. de arce
    int d; // nr. de depozite din graf
    fscanf(stdin, "%d %d %d\n", &n, &m, &d);
    // m linii ce reprezinta arcele dintre noduri. Acestea vor avea formatul u v w, unde u si v sunt
    // ID-urile nodurilor si w este costul parcurgerii drumului dintre acestea;
    float cost;
    matG *matrice = initGraph(n);
    for(k = 0; k < m; k++){
        fscanf(stdin, "%d %d %f\n", &i, &j, &cost);
        addEdge(matrice, i, j, cost);
    }
    // O linie ce contine ID-urile nodurilor ce reprezinta depozite;
    int *depozit;
    depozit = malloc(d * sizeof(int));
    for(k = 0; k < d; k++){
        fscanf(stdin, "%d\n", &depozit[k]);
    }
    // O linie ce reprezinta numarul de cerinte ce trebuiesc rezolvate;
    int cerinte;
    fscanf(stdin, "%d\n", &cerinte);

    // Liniile ce vor urma sunt specifice fiecarei cerinte si vor incepe mereu cu ID-ul task-ului ce trebuie rezolvat.
    int z; 
    for(z = 0; z < cerinte; z++){
        char task[3];
        fscanf(stdin, "%s", task);

        if(strcmp(task, "e1")== 0){ // Cerinta 1.
            int s; // depozitul din care se incarca marfa
            fscanf(stdin, "%d\n", &s);

            int k; // nr. de magazine ce vor fi aprovizionate
            fscanf(stdin, "%d\n", &k);

            int *magazine;
            magazine = malloc(n * sizeof(int*));

            for(i = 0; i < k; i++){
                //ID-urile magazinelor ce vor fi aprovizionate in ordine crescatoare.
                fscanf(stdin, "%d\n", &magazine[i]);
            }
            
            float **matrice_dist;
            matrice_dist = malloc(n * sizeof(float*));

            int **ajutor_floyd;
            ajutor_floyd = malloc(n * sizeof(int*));

            for (i = 0; i < n; i++) {
                matrice_dist[i] = malloc(n * sizeof(float));
                ajutor_floyd[i] = malloc(n * sizeof(int));
            }
            for(i = 0; i < n; i++){
                for(j = 0; j < n; j++){
                    matrice_dist[i][j] = INF;
                    ajutor_floyd[i][j] = -1;
                }
                matrice_dist[i][i] = 0;
                ajutor_floyd[i][i] = i;
            }

            floydWarshall(matrice, ajutor_floyd, matrice_dist);

            float total = 0;
            for(i = 0; i < k; i++){
                fprintf(stdout, "%d\n", magazine[i]);
                fprintf(stdout, "%0.1f %0.1f\n", matrice_dist[s][magazine[i]], matrice_dist[magazine[i]][s]);
                drum(ajutor_floyd, s, magazine[i]);
                fprintf(stdout, " ");
                drum(ajutor_floyd, ajutor_floyd[magazine[i]][s], s);
                fprintf(stdout, "\n");
                total += matrice_dist[s][magazine[i]] + matrice_dist[magazine[i]][s];
            }
            fprintf(stdout, "%0.1f", total);
            free(magazine);
            int x;
            for(x = 0; x < n; x++){
                free(matrice_dist[x]);
                free(ajutor_floyd[x]);
            }
            free(matrice_dist);
            free(ajutor_floyd);
        }
        if(strcmp(task, "e2")== 0){ // Cerinta 2.
            sterg_depozite(matrice, depozit, d);
            int *componente;
            componente = calloc(n, sizeof(int));

            int contor = 0;

            int *vizitat1;
            vizitat1 = malloc(n * sizeof(int));

            int *vizitat2;
            vizitat2 = malloc(n * sizeof(int));

            PlusMinus(matrice, componente, &contor, vizitat1, vizitat2, depozit, d);

            fprintf(stdout, "%d\n", contor);
            int p;
            int ok = 0;
            int okok = 0;
            for(i = 1; i <= contor; i++){
                ok = 0;
                for(j = 0; j < n; j++){
                    if(componente[j] == i){
                        ok = 1;
                        okok = 0;
                        fprintf(stdout, "%d", j);
                        for(p = j + 1; p < n; p++){
                            if(componente[p] == i){
                                okok = 1;
                            }
                        }
                        if(okok){
                            fprintf(stdout, " ");
                        }
                    }
                }
                if(ok && i < contor){
                    fprintf(stdout, "\n");
                }
            }
            free(componente);
            free(vizitat1);
            free(vizitat2);
        }
        if(z != cerinte - 1){
            fprintf(stdout, "\n");
        }
    } 
    free_graph_mat(matrice); 
    free(matrice);
    free(depozit);
}