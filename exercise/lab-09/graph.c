#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

matG init_graph_mat(int nr_nodes){
    matG G;
    int i;
    G.nr_nodes = nr_nodes;
    G.mat_adj = calloc(nr_nodes, sizeof(int*));
    for(i = 0; i < nr_nodes; i++)
        G.mat_adj[i] = calloc(nr_nodes, sizeof(int));
    return G;
}

nodeG* init_node(int j){
    nodeG *node;
    node = calloc(1, sizeof(nodeG));
    node->ID_node = j;
    node->next = NULL;
    return node;
}

listG init_graph_list(int nr_nodes){
    listG G;
    G.nr_nodes = nr_nodes;
    G.adj_list = calloc(nr_nodes, sizeof(nodeG*));
    return G;
}

void add_edge_mat(matG *G, int i, int j){
    G->mat_adj[i][j] = 1;
    G->mat_adj[j][i] = 1;
}

void delete_edge_mat(matG *G, int i, int j){
    G->mat_adj[i][j] = 0;
    G->mat_adj[j][i] = 0;
}

int get_grad(matG G, int i){
    int grad = 0;
    int j;
    for(j = 0; j < G.nr_nodes; j++)
        grad += G.mat_adj[i][j];
    return grad;
}

void free_graph_mat(matG *G){
    int i;
    for(i = 0; i < G->nr_nodes; i++)
        free(G->mat_adj[i]);
    free(G->mat_adj);
}

void print_matr_adj(matG G){
    int i, j;
    for(i = 0; i < G.nr_nodes; i++){
        for(j = 0; j < G.nr_nodes; j++)
            printf("%d ", G.mat_adj[i][j]);
        printf("\n");
    }
}

void add_edge_list(listG *G, int i, int j){
    nodeG *nod;
    if(G->adj_list[i] == NULL){
        G->adj_list[i] = init_node(j);
    }
    else{
        for(nod = G->adj_list[i]; nod->next != NULL; nod = nod->next);
        nod->next = init_node(j); 
    }
    
    if(G->adj_list[j] == NULL){
        G->adj_list[j] = init_node(i);
    }
    else{
        for(nod = G->adj_list[j]; nod->next != NULL; nod = nod->next);
        nod->next = init_node(i); 
    }
}

void delete_edge_list(listG *G, int i, int j){
    if(G->adj_list[i] == NULL)
        return;
    nodeG *nod;
    if(G->adj_list[i]->next == NULL && G->adj_list[i]->ID_node == j)
        G->adj_list[i] = NULL;
    else{
        nod = G->adj_list[i];
        if(nod->ID_node != j){
            while(nod->next != NULL){
                if(nod->next->ID_node == j)
                    break;
                nod = nod->next;
            }
            if(nod != NULL){
                nodeG *aux = nod->next;
                nod->next = aux->next;
                aux->next = NULL;
                free(aux);
            }
        }
        else{
            nodeG *aux = G->adj_list[j];
            G->adj_list[j] = G->adj_list[j]->next;
            free(aux);
        }
    }
    if(G->adj_list[j]->next == NULL && G->adj_list[j]->ID_node == i)
        G->adj_list[j] = NULL;
    else{
        nod = G->adj_list[j];
        if(nod->ID_node != i){
                while(nod->next != NULL){
                    if(nod->next->ID_node == i)
                        break;
                    nod = nod->next;
            }
            if(nod != NULL){
                nodeG *aux = nod->next;
                nod->next = aux->next;
                aux->next = NULL;
                free(aux);
            }
        
        }
        else{
            nodeG *aux = G->adj_list[j];
            G->adj_list[j] = G->adj_list[j]->next;
            free(aux);
        }
    }
}

void print_list(listG G){
    int i, j;
    for(i = 0; i < G.nr_nodes; i++){
        printf("%d: ", i);
        nodeG *nod;
        for(nod = G.adj_list[i]; nod != NULL; nod = nod->next)
            printf("%d ", nod->ID_node);
        printf("\n");
    }
}

void free_graph_list(listG *G){
    int i,j;
    for(i = 0; i < G->nr_nodes; i++){
        nodeG *nod = G->adj_list[i];
        while(nod != NULL){
            nodeG *aux = nod;
            nod = nod->next;
            aux->next = NULL;
            free(aux);
        }
    }
}

int get_grad_list(listG G, int i){
    int c = 0;
    nodeG *aux = G.adj_list[i];
    while(aux != NULL){
        ++c;
        aux = aux->next;
    }
    return c;
}

void set_zeros(int **v, int n){
    int i;
    for(i = 0; i < n; i++)
        (*v)[i] = 0;
}


void dfs(matG G, int i, int **vis){
    int i, j;
    (*vis)[i] = 1;
    printf("%d ", i);
    for(j = 0; j < G.nr_nodes; j++)
        if(G.mat_adj[i][j] && !(*vis)[j])
            dfs(G, j, vis);
}

void bfs(matG G, int i, int **vis){
    int i, j;
    int *queue;
    queue = calloc(10 * G.nr_nodes, sizeof(int));
    set_zeros(&queue, G.nr_nodes);
    int p = 0, u = 0;
    queue[p] = i;
    u++;
    (*vis)[i] = 1;
    while(p < u){
        printf("%d ", queue[p]);
        for(j = 0; j < G.nr_nodes; j++)
            if(G.mat_adj[queue[p]][j] && (*vis)[j] == 0){
                queue[u++] = j;
                (*vis)[j] = 1;
            }
        p++;
    }
}

int dfs_cycle(matG G, int i, int **vis, int parent){
    int i, j;
    (*vis)[i] = 1;
    for(j = 0; j < G.nr_nodes; j++)
        if(G.mat_adj[i][j]){
        if((*vis)[j] == 0){
            if(dfs_cycle(G, j, vis, i))
                return TRUE;
            }
        else if(j != parent)
            return TRUE;
        }
    return FALSE;
}

int has_cycle(matG G, int **vis){
    int i, j;
    for(i = 0; i < G.nr_nodes; i++)
        if(!(*vis)[i])
            if(dfs_cycle(G, i, vis, -1)){
                return TRUE;
            }
    return FALSE;
}
