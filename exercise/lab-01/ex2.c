#include <stdio.h>
/*Sa se implementeze o functie recursiva care determina cate cifre c ale unui numar natural n sunt
mai mici decat o valoare data x ∈ {0, 1, · · · , 9}. Pentru a extrage ultima cifra c a unui numar
natural se foloseste ecuatia c = x mod 10.
*/
int cifra(int x, int n){
    if (n == 0) return 0;
    if (x > n % 10) return 1 + cifra(x, n/10);
    return cifra(x,n/10);
}
int main(){
    int x, n;
    scanf("%d", &n);
    scanf("%d", &x);
    printf("%d", cifra(x, n));
    return 0;
}
