#include <stdio.h>
#include <math.h>

float lol(float st, float dr, float n){
    float mid = (st + dr)/2;
    if(n < 1) 
      return lol(st, dr, 1/n); 
    else if(n > pow(2, mid)) 
      return lol(mid, dr, n);
    else if(n < pow(2, mid)) 
      return lol(st, dr, n);
}

int main(){
    // ...
    return 0;
}
