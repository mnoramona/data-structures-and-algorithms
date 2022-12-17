#include <stdio.h>
int afisare(int *v, int dif){
    int i;
    for(i = 1; i < dif; i++)
      printf ("%d ", v[i]);
    printf("\n");
}
int adunare(int *v, int dif){
    int i = 0, suma = 0;
    for(i = 0; i < dif; i++) 
      suma += v[i];
    return suma;
}
int back(int *v, int dif, int n){
    int i;
    if (adunare(v, dif) == n) 
      afisare(v,dif);
    else 
      for(i = 1; i <= n; i++){ 
      v[dif] = i;
      if (adunare(v, dif) <= n && v[dif] >= v[dif - 1]) 
        back(v, dif+1, n);
    }
}
int main(){
    int i , n, v[101] = {0};
    scanf("%d", &n);
    back(v, 1, n);
    return 0;
}
