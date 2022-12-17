#include <stdio.h>
int binarysearch(int v[101], int x, int left, int right){
    int mid;
    mid = (left + right)/2;
    if ( left > right) return 0;
    if (x == v[mid]) return 1;
    if(x < v[mid]) return binarysearch(v, x, left, mid -1);
    if(x > v[mid]) return binarysearch(v, x, mid + 1 , right);

}
int main(){
    int v[101], n, i, x, left = 0, right = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d ", &v[i]);
    }
    scanf("%d", &x);
    right = n - 1;
    if (binarysearch(v, x, left, right) == 1) 
      printf("Gasit");
    else 
      printf("Negasit");
    return 0;
}
