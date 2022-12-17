#ifndef aicimaajutlagrafuri
#define aicimaajutlagrafuri

// asta am invatat de la baieti
#define TRUE 1
#define FALSE 0

typedef struct MatGraph{
    int nr_nodes;
    int **mat_adj;
}matG;

typedef struct NodeGraph{
    struct graphNode *next;
    int ID_node;
}nodeG;

typedef struct ListGraph{
    nodeG **adj_list;
    int nr_nodes;
}listG;

matG init_graph_mat(int nr_nodes);
nodeG* init_node(int j);
listG init_graph_list(int nr_nodes);
void add_edge_mat(matG *G, int i, int j);
void delete_edge_mat(matG *G, int i, int j);
int get_grad(matG G, int i);
void free_graph_mat(matG *G);
void print_matr_adj(matG G);

void add_edge_list(listG *G, int i, int j);
void delete_edge_list(listG *G, int i, int j);
void print_list(listG G);
int get_grad_list(listG G, int i);
void free_graph_list(listG *G);

void set_zeros(int **v, int n);

void dfs(matG G, int i, int **vis);
void bfs(matG G, int i, int **vis);

int dfs_cycle(matG G, int i, int **vis, int parent);
int has_cycle(matG G, int **vis);

#endif