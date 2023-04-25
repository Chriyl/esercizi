#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

/*
Data una tabella con record costituito dai campi codice,
 nominativo,
 città,
 quantità,
 prezzo unitario e
 iva
 fornire una stampa del totale fatturato da ogni cliente in base all’esempio riportato di seguito:
 */

typedef struct {
    char nome[20];
    char citta[20];
    int quanita;
    float prezzo_unitario;
    float iva;
    float prezzo_totale;
}partita_iva;

int stampa_menu();
void aggiungi_iva(partita_iva*);
void

int main() {
    int check = 0, check_2 = 0;
    partita_iva dichiarazione[N];

    do {
        check = stampa_menu();

        switch (check) {
            case 1:
                if(check_2 < N) {
                    aggiungi_iva(&dichiarazione[check_2]);
                    check_2++;
                }else {
                    printf("array pieno :(");
                }
                break;
            case 2:

                break;
            case 3:
                break;
            default:
                printf("errore");
        }
    } while (check_2 !=3);
}

int stampa_menu() {
    int check = 0;
    printf("cosa vuoi fare?\n");
    printf("inserire una partita iva (1)\n");
    printf("stampare la scheda di una partiva iva (2)\n");
    printf("uscire dal programma (3)\n");

    scanf("%d", &check);

    return check;
}

void aggiungi_iva(partita_iva* part_iva) {
    printf("come si chiama la persona che vuoi aggiungere?\n");
    getchar();
    gets(part_iva->nome);

    printf("dove vive la persona?\n");
    getchar();
    gets(part_iva->citta);

    printf("qual e il prezzo unitario iva?\n");
    getchar();
    scanf("%f", &part_iva->prezzo_unitario);

    printf("quanto e la quantita del prodotto?\n");
    getchar();
    scanf("%d", &part_iva->quanita);

    printf("quanto e l'iva del prodotto?\n");
    getchar();
    scanf("%f", &part_iva->iva);
}