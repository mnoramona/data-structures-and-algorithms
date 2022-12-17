#include <stdio.h>
/* Sa se implementeze o functie care, folosind paradigma Divide-et-Impera, calculeaza suma elementelor de pe pozitiile pare ale unui vector
 ce contine numere naturale. De exemplu, pentru vectorul v = {1, 2, 3, 4, 5}, dat fiind ca indexarea se face ıncepand cu pozitia 0, functia va
calcula foo(v) = 1 + 0 + 3 + 0 + 5 = 9.
*/
int foo(int st, int dr, int *v){ //calculam suma
    int mid, suma1, suma2;
    if (st == dr) if (st % 2 == 0) 
      return v[st]; //daca pe pozitie para ramane nr
    else 
      return 0; // daca nu transform in 0
    else {
        mid = (st + dr)/2; //mijlocul
        suma1 = foo(st, mid, v);
        suma2 = foo(mid + 1, dr, v);
        return suma1 + suma2;
    } 
}
int main(){
    int v[101], dimensiune, st, dr, i;
    scanf("%d", &dimensiune);
    for(i = 0; i < dimensiune; i++){
        scanf("%d", &v[i]);
    }
    st = 0;
    dr = dimensiune - 1;
    printf("%d", foo(st, dr, v));
    return 0;
}
