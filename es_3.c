#include <stdio.h>
#include <stdlib.h>
#define N 100

/*
 Scrivere un programma che permetta la gestione di un insieme di persone.
I dati da memorizzare sono: nome, cognome, codice fiscale e comune di residenza.
Il programma tramite un opportuno menù permette di effettuare le seguenti operazioni:
aggiungere una persona: non deve essere possibile aggiungere persone con lo stesso nome, cognome e codice fiscale;
stampare tutte le persone che vivono in un determinato comune;
stampare i codici fiscali delle persone di cui viene fornito nome e cognome;
stampare i dati in ordine alfabetico (cognome e nome).
*/

typedef struct {
    char nome[20];
    char cognome[20];
    char codice_fiscale[20];
} persona;

int stampa_menu(int);
void aggiungi_persona(persona*);

int main() {
    int check = 0, check_2 = 0;
    persona persone[N];

    do {
        check = stampa_menu(check);-

        switch (check) {

            case 1:
                if(check_2 < N) {
                    aggiungi_persona(&persone[check_2]);
                    check_2++;
                }else{
                    printf("array pieno :(");
                }

                break;
        }
    }while(check != 5);


    return 0;
}


int stampa_menu (int check) {
    printf("cosa vuoi fare?\n");
    printf("inserisci persona (1)\n");
    printf("stampare tutte le persone che vivono nello stesso comune (2)\n");
    printf("stampare il codice fiscale delle persone di cui viene fornito nome e cognome (3)\n");
    printf("stampare nomi e cognomi in ordine alfabetico (4)\n");
    printf("uscire dal programma (5)\n");
    scanf("%d", &check);

    return check;
}

void aggiungi_persona(persona* persone) {
    printf("come si chiama la persona che devi aggiungere?\n");
    getchar();
    gets(persone -> nome);

    printf("qual e il cognome della persona che vuoi aggiungere?\n");
    getchar();
    gets(persone -> cognome);

    printf("qual e il codice fiscale della persona che devi aggiunger?\n");
    getchar();
    gets(persone -> codice_fiscale);
}