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

int stampaMenu();
void aggiungi_film(films* );
int main() {
    int check  = 0 , check_2 = 0;
    films film[N];

    do {

        check = stampaMenu();
        switch (check) {
            case 1:
                if(check_2 < N) {
                    aggiungi_film(&film[check_2]);
                    check_2++;
                }else {
                    printf("array pieno");
                }
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

int stampaMenu( ) {
    int count = 0;
    printf("cosa vuoi fare?\n");
    printf("inserisci un film (1)\n");
    printf("cambiare i dati di un film (2)\n");
    printf("vedere un film (3)\n");
    printf("uscire dal programma (4)\n");
    scanf("%d", &count);
    return count;

}

void aggiungi_film(films* film ) {
    printf("come si chiama il film che vuoi inserire?\n");
    getchar();
    gets(film -> nome);

    printf("come si chiama il protagonista del film che vuoi inserire?\n");
    getchar();
    gets(film -> protagonista);

    printf("come si chiama il regista del film che vuoi inserire?\n");
    getchar();
    gets(film -> regista);

    printf("qual e il genere film che vuoi inserire?\n");
    getchar();
    gets(film -> genere);

    printf("qual e  il codice del film che vuoi inserire?\n");
    getchar();
    gets(film -> codice);

    printf("qual e il genere del film che vuoi inserire?\n");
    getchar();
    gets(film -> genere);

    printf("qual e l'anno di uscita del film che vuoi inserire?\n");
    getchar();
    scanf("%" , &film -> anno);

}