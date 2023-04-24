#include <stdio.h>
#include <stdlib.h>
#define N 100

/*
 Realizzare un array di record contenente un elenco degli studenti di un corso di studi del tuo istituto
 riportante il numero di matrico,
 il cognome, il nome e il numero di giorni di assenza.
 Scrivere un programma che permetta di ordinare tale elenco su un campo richiesto in input.
*/

typedef struct {
    char nome[20];
    char cognome[20];
    char matricola[20];
    int assenze;

} studenti;

int stampa_menu();
void inserisci_studente(studenti*);

int main() {
    studenti studente[N];
    int check = 0, check_2 = 0;

    do {
        check = stampa_menu();

        switch (check) {
            case 1:
                if(check_2 < N) {
                    inserisci_studente(&studente[check_2]);
                    check_2++;
                }else{
                    printf("array pieno :(");
                }
                break;
        }
    }while(check !=6);

    return 0;
}

int stampa_menu() {
    int check = 0;
    printf("cosa vuoi fare?\n");
    printf("inserire uno studente (1)\n");
    printf("ordinare per nome (2)\n");
    printf("ordinare per cognome (3)\n");
    printf("ordinare per numero di assenze (4)\n");
    printf("ordinare per numero di matricola (5)\n");
    printf("uscire dal programma (6)\n");
    scanf("%d", &check);

    return check;
}

void inserisci_studente(studenti* studente) {
    printf("come si chiama lo studente che vuoi inserire?\n");
    getchar();
    gets(studente -> nome);

    printf("qual e il cognome dello studente che vuoi inserire?\n");
    getchar();
    gets(studente -> cognome);

    printf("qual e il numero di assenze dello studente che vuoi inserire?\n");
    scanf("%d", &studente -> assenze);

    printf("qual e il numero di matricola dello studente che vuoi inserire?\n");
    getchar();
    gets(studente -> matricola);

}