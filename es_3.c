#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
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
    char comune_residenza[20];
} persona;

int stampa_menu(int);
void aggiungi_persona(persona* );
bool check_codice(persona*, int );
void stampa_comune(persona*, int, char*);
void stampa_codice(persona*, int, char*, char*);

int main() {
    int check = 0, check_2 = 0;
    char comune[20], nome[20], cognome[20];
    persona persone[N];

    do {
        check = stampa_menu(check);

        switch (check) {

            case 1:
                if(check_2 < N) {
                    aggiungi_persona(&persone[check_2]);
                    check_2++;
                }else{
                    printf("array pieno :(");
                }

                if(check_codice(persone,check_2)){
                    check_2--;
                }

                break;
            case 2:
                printf("che persone di che comune vuoi stampare?");
                scanf("%s", comune);
                stampa_comune(persone, check_2, comune);
                break;
            case 3:
                printf("inserisci il nome delle persone di cui vuoi avere il codice fiscale\n");
                getchar();
                gets(nome);

                printf("inserisci il cognome delle persone di cui vuoi avere il codice fiscale\n");
                getchar();
                gets(nome);
                stampa_codice(persone, check_2, nome, cognome);
                break;
            default:
                printf("errore");
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

    printf("qual e il comnune di residenza della persona che devi aggiunger?\n");
    getchar();
    gets(persone -> comune_residenza);

}

bool check_codice(persona* persone, int count) {
    for(int i = 0; i < count; i++) {
        for(int j = i + 1; j<count; j++){

            if(strcmp(persone[i].codice_fiscale, persone[j].codice_fiscale) == 0 ) {
                printf("ci sono dei duplicati!\n");
                return true;
            }
        }
    }
    return false;
}

void stampa_comune(persona* persone , int count, char* comune) {
    for(int i = 0; i < count; i++) {
        if(strcmp(comune, persone[i].comune_residenza) ){
            printf("%s/%s \n", persone[i].nome, persone[i].cognome);
        }
    }
}

void stampa_codice(persona* persone, int count, char* nome, char* cognome) {
    for(int i = 0;i < count; i++) {
        if(strcmp(nome, persone[i].nome) || strcmp(cognome, persone[i].cognome)) {
            printf("il codice fiscale e: %s\n", persone[i].codice_fiscale);
        }
    }
}