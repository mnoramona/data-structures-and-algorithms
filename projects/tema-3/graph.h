#ifndef aicifacfunctiiptgrafuri
#define aicifacfunctiiptgrafuri

typedef struct MatGraph{
    int nr_nodes;
    float **mat_adj;
}matG;

matG *initGraph(int nr_nodes);
int isNeighbour(matG *G, int i, int j);
void addEdge(matG *G, int i, int j, float cost);
void free_graph_mat(matG *G);

// Functii folosite pentru task-ul 1:
void floydWarshall(matG *G, int **next, float **final);
void drum(int **next, int i, int j);

// Functii folosite pentru task-ul 2:
void sterg_depozite(matG *G, int *depozit, int d);
void graf(matG *G, int x, int *v1);
void graf_transpus(matG *G, int x, int *v2);
void PlusMinus(matG *G, int *ctc, int *nrc, int *v1, int *v2, int *depozit, int d);
#endif