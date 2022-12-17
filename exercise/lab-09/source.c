#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    int i, j;
    int n_nodes, n_edges;
    fscanf(stdin, "%d%d", &n_nodes, &n_edges);
    matG GMat = init_graph_mat(n_nodes);
    listG GList = init_graph_list(n_nodes);
    for(i = 0; i < n_edges; i++){
        int u, v;
        fscanf(stdin, "%d%d", &u, &v);
        add_edge_mat(&GMat, u, v);
        add_edge_list(&GList, u, v);
    }
    printf("Matrice:\n");
    print_matr_adj(GMat);
    printf("\n");
    printf("%d\n", get_grad(GMat, 2));
    delete_edge_mat(&GMat, 2, 4);
    printf("%d\n", get_grad(GMat, 2));
    printf("\n");
    print_matr_adj(GMat);
    printf("\n");
    printf("Liste:\n");
    print_list(GList);
    printf("\n");
    printf("%d\n", get_grad_list(GList, 2));
    delete_edge_list(&GList, 2, 4);
    printf("%d\n", get_grad_list(GList, 2));
    printf("\n");
    print_list(GList);
    add_edge_mat(&GMat, 2, 4);

    int *visited;
    visited = calloc(n_nodes, sizeof(int));
    set_zeros(&visited, n_nodes);
    dfs(GMat, 3, &visited);
    printf("\n");
    set_zeros(&visited, n_nodes);
    bfs(GMat, 3, &visited);
    printf("\n");
    set_zeros(&visited, n_nodes);

    //printf("%s", has_cycle(GMat, &visited));

}