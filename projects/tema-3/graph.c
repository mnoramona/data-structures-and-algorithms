#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

#define INF 99999

matG *initGraph(int nr_nodes) {
    int i, j;
    if (nr_nodes <= 0) {
        fprintf(stdout, "Ceva nu convine.\n");
        return NULL;
    }

    matG *G = malloc(sizeof(matG));
    G->nr_nodes = nr_nodes;
    G->mat_adj = malloc(nr_nodes * sizeof(float*));

    for (i = 0; i < nr_nodes; i++) {
        G->mat_adj[i] = malloc(nr_nodes * sizeof(float));
        for(j = 0; j < nr_nodes; j++){
            G->mat_adj[i][j] = 0; 
        }
    }

    return G;
}

int isNeighbour(matG *G, int i, int j) {
    if (G == NULL) {
        fprintf(stdout, "Ceva nu convine.\n");
        return -1;
    }

    if (i >= G->nr_nodes || j >= G->nr_nodes) {
        fprintf(stdout, "Ceva nu convine.\n");
        return -1;
    }

    return G->mat_adj[i][j] != 0;
}

void addEdge(matG *G, int i, int j, float cost) {
    if (G == NULL) {
        fprintf(stdout, "Ceva nu convine.\n");
        return;
    }

    if (i >= G->nr_nodes || j >= G->nr_nodes) {
        fprintf(stdout, "Ceva nu convine.\n");
        return;
    }

    if (isNeighbour(G, i, i)) {
        fprintf(stdout, "Ceva nu convine.\n");
    }

    // Inserez noua muchie
    G->mat_adj[i][j] = cost;
}

void floydWarshall(matG *G, int **next, float **final){
    int i, j, k;
    // Am folosit ce am vazut pe wikipedia, doar ca am schimbat for-urile astfel incat la g1e1 sa fie ca-n raspunsuri
    for (i = 0; i < G->nr_nodes; i++){
        for (j = 0; j < G->nr_nodes; j++){
            if(isNeighbour(G, i, j)){
                final[i][j] = G->mat_adj[i][j];
                next[i][j] = j;
            }
        }
    }

    for (k = G->nr_nodes - 1; k >= 0; k--){
        for (i = G->nr_nodes - 1; i >= 0; i--){
            for (j = G->nr_nodes - 1; j >= 0; j--){
                if (final[i][k] + final[k][j] < final[i][j]){
                    final[i][j] = final[i][k] + final[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void drum(int **next, int i, int j){
    if(next[i][j] == -1){
        return;
    } 
    fprintf(stdout, "%d", i);
    while(i != j){
        fprintf(stdout, " ");
        i = next[i][j];
        fprintf(stdout, "%d", i);
    }
}

void free_graph_mat(matG *G){
    int i;
    for(i = 0; i < G->nr_nodes; i++)
        free(G->mat_adj[i]);
    free(G->mat_adj);
}

void sterg_depozite(matG *G, int *depozit, int d){
    int i, j;
    for(i = 0; i < G->nr_nodes; i++){
        for(j = 0; j < d; j++){
            G->mat_adj[i][depozit[j]] = 0;
            G->mat_adj[depozit[j]][i] = 0;
        }
    }
}

void graf(matG *G, int x, int *v1){
    int i;
    v1[x] = 1;
    for(i = 0 ; i < G->nr_nodes; i++)
        if(v1[i] == 0 && isNeighbour(G, x, i))
            graf(G, i, v1);
}

void graf_transpus(matG *G, int x, int *v2){
    int i;
    v2[x] = 1;
    for(i = 0 ; i < G->nr_nodes; i++)
        if(v2[i] == 0 && isNeighbour(G, i, x))
            graf_transpus(G, i, v2);
}

void PlusMinus(matG *G, int *ctc, int *nrc, int *v1, int *v2, int *depozit, int d){
    int i, j, k;
    int ok = 0;
    for(i = 0 ; i <  G->nr_nodes; i++){
        ok = 0;
        for(k = 0; k < d; k++){
            if(depozit[k] == i){
                ok = 1;
            }
        }
        if(ctc[i] == 0 && ok == 0){
            for(j = 0; j < G->nr_nodes; j++){
                v1[j] = v2[j] = 0;
            }

            (*nrc)++;

            graf(G, i, v1); 
            graf_transpus(G, i, v2);

            for(j = 0; j < G->nr_nodes; j++){
                if(v1[j] == 1 && v2[j] == 1){
                    for(k = 0; k < d; k++){
                        if(depozit[k] != j)
                            ctc[j] = *nrc;
                    }
                }
            }
        }
    }
}
