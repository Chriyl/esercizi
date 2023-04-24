#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 100
/*
 All’interno di una tabella sono memorizzate le informazioni relative al codice fornitore e all’importo lordo dovuto relative ai vari fornitori di una ditta.
 Le informazioni devono essere memorizzate in ordine di codice,
 con possibilità di ripetizione.
 Realizzare un programma che consenta, per ogni fornitore, di conoscere
 l’importo medio e, alla fine, il fornitore caratterizzato da un importo medio più alto e più basso.
*/

typedef struct {
    char codice_fornitore[20];
    int importo;
    int media;

}fornitori;

int stampa_menu(int);
int inserici_fornitore(fornitori*, int);
void insertion_sort(fornitori* , int );
void media_fornitori(fornitori*, int);
int max(fornitori* , int );
int min(fornitori*, int  );
int main() {
    fornitori fornitore[N];
    int check = 0, check_2 = 0, media[N], index_min = 0, index_max = 0;
        do {
            check = stampa_menu(check);
            switch (check) {
                case 1:
                    if(check_2 < N ) {
                       check_2 =  inserici_fornitore(&fornitore[check_2], check_2);
                    }else {
                        printf("array pieno :(\n");
                    }
                    break;
                case 2:
                    insertion_sort(fornitore,check_2);
                    media_fornitori(fornitore,  check_2 );
                    break;
                case 3:
                    index_max = max(fornitore, check_2);
                    index_min = min(fornitore, check_2);

                    printf("il fornitore con la media piu bassa e %s con %d di media ", fornitore[index_min].codice_fornitore , fornitore[index_min].media);
                    printf("il fornitore con la media piu alta e %s con %d di media ", fornitore[index_max].codice_fornitore , fornitore[index_max].media);
                    break;
                case 4:
                    printf("arrivederci!");
                    break;
                default:
                    printf("numero non valido!\n");
            }
        } while (check != 5);




    return 0;
}


int stampa_menu(int count) {
    printf("cosa vuoi fare?\n");
    printf("inserire un fornitore? (1)\n");
    printf("vedere le medie di tutti i fornitori (2)\n");
    printf("vedere importo piu basso e importo piu alto (3)\n");
    printf("uscire dal programma (4)\n");
    scanf("%d", &count);

    return count;
}

int inserici_fornitore(fornitori* fornitore, int count) {
    printf("qual e il codice fornitore?\n");
    getchar();
    gets(fornitore -> codice_fornitore);

    printf("qual e l'importo?\n");
    getchar();
    scanf("%d", &fornitore -> importo);

    count++;

    return count;
}

void insertion_sort(fornitori* arr, int n) {
    int i, j;
    fornitori temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j].codice_fornitore, temp.codice_fornitore) > 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void media_fornitori(fornitori* fornitore, int count ) {
    for (int i = 0; i < count; i++) {
        int check = 0;
        int media = fornitore[i].importo;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(fornitore[i].codice_fornitore, fornitore[j].codice_fornitore) == 0) {
                media += fornitore[j].importo;
                check++;
            }
        }
        if (check > 0) {
            media /= (check + 1);
        }
        printf("La media del fornitore %s e: %d\n", fornitore[i].codice_fornitore, media);
    }
}

int max(fornitori* fornitore, int count) {
    int max = INT_MIN;
    int check = 0;

    for(int i = 0; i < count; i++) {
        if(fornitore[i].media > max) {
            max = fornitore[i].media;
            check++;

        }
    }
    return check;
}

int min(fornitori* fornitore, int count ) {
    int min = INT_MAX;
    int check = 0;

    for(int i = 0; i < count; i++) {
        if(fornitore[i].media < min) {
            min = fornitore[i].media;
            check++;
        }
    }
    return check;
}