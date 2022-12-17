#include <stdio.h>

int divide(int *v, int li,int ls)
{
    int st = li;
    int dr = ls;
    int pr = v[li];
    while (st < dr){
        while (st < dr && v[dr] >= pr)
            dr--;
        v[st] = v[dr];
        while (st < dr && v[st] <= pr)
            st++;
        v[dr] = v[st];
    }
    v[st] = pr;
    return st;
}
void qsort(int *v, int li,int ls){     
  int m = divide (v, li, ls);
  if (m - 1 > li)
    qsort(v, li, m - 1);
  if (ls > m+1)
    qsort(v, m + 1, ls);
}

int main()
{
    int v[101], dimensiune, i;
    scanf("%d", &dimensiune);
    for(i = 0; i < dimensiune; i++) 
      scanf("%d", &v[i]);
    qsort (v, 0, dimensiune);
    for(i = 1; i < dimensiune +1; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
