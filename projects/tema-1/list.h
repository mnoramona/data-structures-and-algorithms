#ifndef aicifaclista
#define aicifaclista
typedef struct node {
    double data;
    int timestamp;
    struct node *next;
    struct node *prev;
} Tnode;
 
typedef struct liste {
    Tnode *head;
    Tnode *tail;
    int len;
} Tlist;
 
// Initaializeaza un nod din lista
Tnode * initializez_nod(int timestamp, double value);
 
// Initializeaza o lista vida
Tlist *initializez_lista();
 
// Elibereaza memoria ocupata de un nod
void eliberez_nod(Tnode *nodu);
 
// Elibereaza zona de memorie ocupata de o lista
void distrug_lista(Tlist *lista);
 
// Afiseaza lista primita ca parametru
void printez_lista(Tlist *lista);

// Insereaza un nod in lista respectiva
int inserez_nod(Tlist *lista, double value, int timestamp, int position);

// Functie pentru a sorta crescator lista primita ca parametru
Tlist *crescator(Tlist *lista, double value, int timestamp);

#endif