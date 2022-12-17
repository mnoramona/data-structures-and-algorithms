#include <stdio.h>

int fibonacci(int k){
  if(k <= 2) 
    return 1;
  else 
    return fibonacci(k - 1) + fibonacci(k - 2);
}
int main(){
    int k;
    scanf("%d", &k);
    printf("%d", fibonacci(k));
    return 0;
}
