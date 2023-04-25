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
    int quantita;
    float prezzo_unitario;
    float iva;
    float prezzo_totale;
} partita_iva;


int stampa_menu();
void aggiungi_iva(partita_iva*);
void stampa_dichiarazione(partita_iva*, int);

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
                stampa_dichiarazione(dichiarazione, check_2);
                break;
            case 3:
                printf("arrivederci!");
                break;
            default:
                printf("errore");
        }
    } while (check !=3);
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

    printf("qual e il prezzo unitario ?\n");
    scanf("%f", &part_iva->prezzo_unitario);

    printf("quanto e la quantita del prodotto?\n");
    scanf("%d", &part_iva->quantita);

    printf("quanto e l'iva del prodotto?\n");
    scanf("%f", &part_iva->iva);
}

void stampa_dichiarazione(partita_iva* dichiarazione, int count) {
    char nome[20];
    int found = 0;
    int index = 0;


    printf("come si chiama la persone di cui vuoi vedere la dichiarazione?\n");
    getchar();
    gets(nome);

    for(int i = 0; i<count && found == 0; i++) {
        if(strcmp(nome, dichiarazione[i].nome) == 0) {
            index = i;
            found++;
        }
    }

    dichiarazione[index].prezzo_totale = dichiarazione[index].quantita * dichiarazione[index].prezzo_unitario * (1 + dichiarazione[index].iva / 100);


    printf("\n\n");

    printf("nome: %s \n", dichiarazione[index].nome);
    printf("citta: %s \n", dichiarazione[index].citta);
    printf("la quantita e: %d \n", dichiarazione[index].quantita);
    printf("prezzo unitario: %.2f \n", dichiarazione[index].prezzo_unitario);
    printf("l iva e: %.2f \n", dichiarazione[index].iva);
    printf("prezzo totale: %.2f \n\n", dichiarazione[index].prezzo_totale);

}