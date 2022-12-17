#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct.h"
#include "taskuri.h"

#define RGB_COMPONENT 256


// argumentele in linia de comanda:
// ./quadtree [-c factor / -d / -m type] [fisier_intrare1] [fisier_iesire]

int bin_to_dec(char *s){ // functia primeste un numar in baza 2 ca sir de caractere si intoarce valoarea in baza 10
    int i, k = 0, p = 1;
    for(i = 7; i >= 0; i--){
        if(s[i] == '1'){
            k += p;
        }
        p *= 2;
    }
    return k;
}


int main(int argc, char *argv[]){
    // argv[0] -> ./quadtree
    // argv[1] -> -c/ -d/ -m
    // etc.
    int ok;
    int width, height;
    char antet[10];
    int maximum = 0;
    uint32_t culori;
    uint32_t noduri;
    if(strcmp(argv[1], "-c") == 0){ // cerinta 1: compresia unei imagini
        // factor = pragul impus pentru compresie
        ok = 0;
    }
    else if(strcmp(argv[1], "-d") == 0){ // cerinta 2: formarea imaginii pe baza arborelui
        ok = 1;
    }
    else if(strcmp(argv[1], "-m") == 0){ // cerinta 3: oglindire pe verticală
        // type = tipul oglindirii şi poate lua una din valorile: h - orizontală sau v - verticală)
        ok = 0;
    }
    FILE *open_fisier_intrare1;
    if(ok == 0){
        open_fisier_intrare1 = fopen(argv[3], "rb");
        if(open_fisier_intrare1 == NULL){
            printf("Nu deschide fisierul '%s'\n, argv[3]");
            return NULL;
        }
    }
    else if(ok == 1){
        open_fisier_intrare1 = fopen(argv[2], "rb");
        if(open_fisier_intrare1 == NULL){
            printf("Nu deschide fisierul '%s'\n", argv[2]);
            return NULL;
        }
    }
    /*
    Fişierul PPM
    Un fişier în format PPM conţine un antet, în format text, care conţine: 
    pe prima linie tipul fişierului (în cazul imaginilor folosite în test, o să fie tipul P6),
    pe a doua linie două numere naturale (width şi height), separate prin spaţiu, care descriu dimensiunile imaginii, 
    iar a treia linie va conţine un număr natural reprezentând valoarea maximă pe care o poate lua o culoare (în cazul testelor folosite, valoarea este 256);
    şi imaginea propriu-zisă, în format binar.
    */
    fscanf(open_fisier_intrare1, "%9s", antet);
    if(antet[0] != 'P' || antet[1] != '6'){
        printf("Eroare la tipul fisierului");
            return NULL;
    }
    fscanf(open_fisier_intrare1, "%d %d\n", &width, &height);
    fscanf(open_fisier_intrare1, "%d\n", &maximum);
    
    //int size = width * height;

    unsigned char **pixels;
    pixels = malloc (height * sizeof(*pixels) * 3);
    pixels[0] = malloc(height * sizeof(unsigned char) * 3 * width);
    int i;
    for(i = 0; i < height * 3; i++){
        pixels[i] = &pixels[0][i*width];
    }
    fread(pixels, sizeof(int), 128, open_fisier_intrare1);
    fclose(open_fisier_intrare1);
    


    return 0;
}