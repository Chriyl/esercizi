#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void sorting_nomi(studenti*, int);
void stampa_studenti_nome(studenti*, int);
void sorting_conomi(studenti* , int );
void stampa_studenti_cognome(studenti* , int );
void sorting_assenze (studenti* , int );
void stampa_studenti_assenze(studenti* , int );
void sorting_matricola(studenti* , int );
void stampa_studenti_matricola(studenti*, int);


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
            case 2:
                sorting_nomi(studente, check_2);
                stampa_studenti_nome(studente, check_2);
                break;
            case 3:
                sorting_conomi(studente, check_2);
                stampa_studenti_cognome(studente, check_2);
                break;
            case 4:
                sorting_assenze(studente, check_2);
                stampa_studenti_assenze(studente, check_2);
                break;
            case 5:
                sorting_matricola(studente, check_2);
                stampa_studenti_matricola(studente, check_2);
                break;
            case 6:
                printf("arrivederci");
                break;
            default:
                printf("errore!");
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

void sorting_nomi(studenti* studente, int count){

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (strcmp(studente[j].nome, studente[j+1].nome) > 0) {
                // scambia i due elementi
                studenti temp = studente[j];
                studente[j] = studente[j+1];
                studente[j+1] = temp;
            }
        }
    }
}

void stampa_studenti_nome(studenti* studente, int count) {
    for(int i = 0; i < count; i++){
        printf("gli studenti ordinati per nome sono: %s \n", studente[i].nome);
    }
}

void sorting_conomi(studenti* studente, int count){

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (strcmp(studente[j].cognome, studente[j+1].cognome) > 0) {
                // scambia i due elementi
                studenti temp = studente[j];
                studente[j] = studente[j+1];
                studente[j+1] = temp;
            }
        }
    }
}

void stampa_studenti_cognome(studenti* studente, int count) {
    for(int i = 0; i < count; i++){
        printf("gli studenti ordinati per cognome sono: %s \n", studente[i].cognome);
    }
}

void sorting_assenze (studenti* studente  , int count ) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (studente[j].cognome > studente[j+1].cognome)  {
                // scambia i due elementi
                studenti temp = studente[j];
                studente[j] = studente[j+1];
                studente[j+1] = temp;
            }
        }
    }
}

void stampa_studenti_assenze(studenti* studente , int count ) {
    for(int i = 0; i < count; i++){
        printf("gli studenti ordinati per assenze sono: %s assenze: %d \n", studente[i].nome, studente[i].assenze);
    }
}

void sorting_matricola(studenti* studente , int count ) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (strcmp(studente[j].matricola, studente[j+1].matricola) > 0) {
                // scambia i due elementi
                studenti temp = studente[j];
                studente[j] = studente[j+1];
                studente[j+1] = temp;
            }
        }
    }
}

void stampa_studenti_matricola(studenti* studente , int count ) {
    for(int i = 0; i < count; i++){
        printf("gli studenti ordinati per assenze sono: %s assenze: %d \n", studente[i].nome, studente[i].assenze);
    }
}