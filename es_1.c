#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 100

/*
 Scrivere un programma che permetta la gestione di una mediateca. Ogni film è caratterizzato da
 un codice,
 un titolo,
 il nome del regista,
 il nome dell’attore principale,
 l’anno di produzione
 e dal genere. Il programma tramite un opportuno menù permette di effettuare le seguenti operazioni:
aggiungere un film;
aggiornare i dati:
il programma provvederà a chiudere in input il codice del DVD e nel caso in cui il DVD richiesto
sia stato effettivamente memorizzato visualizza i dati registrati e provvederà a richiedere in input le variazioni da apportare;
visualizzare i film;
terminare il programma.
*/

typedef struct {
    char nome[20];
    char codice[20];
    char protagonista[20];
    char regista[20];
    char genere[20];
    int anno;

}films;

int main() {
    int check  = 0 , check_2 = 0;

    do {
        switch (check) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("errore");
        }
    } while (check !=5);

    return 0;
}