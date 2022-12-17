#include <stdio.h>
#include <string.h>

/*Sa se implementeze o functie recursiva care determina daca un sir de caractere s este palindrom.
Un polindrom este un sir de caractere care citit de la stanga la dreapta sau de la dreapta la stanga
ramane neschimbat (wikipedia). Exemple de astfel de siruri sunt: alabala, 110011.
*/
int rec(char sir[101], int s, int d){
     if (s > d) 
      return 1;
     if (sir[s] == sir[d]) 
       return rec(sir, s + 1, d - 1);
     else 
       return 0;
}
int main(){
    char sir[101];
    scanf("%s", sir);
    int s = 0, d = strlen(sir) - 1;
    if (rec(sir, s, d) == 1) printf("E palindrom");
    else printf("Nu e palindrom");
    return 0;
}
