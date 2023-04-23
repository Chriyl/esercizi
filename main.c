#include <stdio.h>
#include <string.h>
#define N 100

/*
Scrivere un programma che permetta la gestione di una rubrica telefonica all’interno della quale sono presenti nomi,
cognomi e numeri di telefono.
Il programma tramite un opportuno menù permette di effettuare le seguenti operazioni:
aggiungere un numero;
visualizzare i contatti;
visualizzare i contatti in ordine di nome crescente;
visualizzare i contatti in ordine di cognome decrescente;
terminare il programma.
*/

typedef struct {
    char numero[11];
    char nome[20];
    char cognome[20];
} rubrica_gen;

int stampa_menu(int);
void aggiungi_numero(rubrica_gen*);
void stampa_contatti(rubrica_gen*, int);
void sorting_nomi(int, rubrica_gen*);
void stampa_nomi(int, rubrica_gen*);
void sorting_cognomi(rubrica_gen*, int);
void stampa_cognomi(rubrica_gen*, int );


int main() {
    int check = 0, check_2 = 0;
    rubrica_gen rubrica[N];

    do{
        check  = stampa_menu(check);

        switch (check){
            case 1:
                // aggiungere numeri
                if(check_2 < N){
                    aggiungi_numero(&rubrica[check_2]);
                    check_2++;
                } else{
                    printf("array pieno :(");
                }
                break;
            case 2:
                stampa_contatti(rubrica, check);
                break;
            case 3:
                // stampa nomi in ordine crescente
                sorting_nomi(check, &rubrica[0]);
                stampa_nomi(check, rubrica);
                break;
            case 4:
                sorting_cognomi(&rubrica[0], check );
                stampa_cognomi(&rubrica[0], check );
                break;
            case 5:
                printf("arrivederci!!");
                break;
            default:
                printf("numero non conforme");
                break;

        }

    }while(check != 5);

    return 0;
}


int stampa_menu(int check){
    printf("cosa vuoi fare?\n");
    printf("aggiungere un numero (1)\n");
    printf("visualizzare i contatti (2)\n");
    printf("visualizzare i nomi in ordine alfabetico (3)\n");
    printf("visualizzare i cognomi in ordine alfabetico contrario (4)\n");
    printf("terminare il programma (5)\n");
    scanf("%d",  &check);

    return check;

}

void aggiungi_numero(rubrica_gen* rubrica){
    printf("come si chiama la persona che vuoi aggiunere?\n");
    getchar();
    gets(rubrica -> nome);

    printf("qual e il cognome della persona che vuoi aggiunere?\n");
    getchar();
    gets(rubrica -> cognome);

    printf("qual e il numero della persona che vuoi aggiunere?\n");
    getchar();
    gets(rubrica -> numero);
}

void stampa_contatti(rubrica_gen* rubrica, int count){
    for(int i = 0; i <= count; i++){
        printf("il contatto numero %d e: \n", i + 1 );
        printf("nome: %s\n", rubrica[i].nome);
        printf("cognome: %s\n", rubrica[i].cognome);
        printf("numero: %s\n", rubrica[i].numero);
        printf("---------------------------------------\n");
    }
}

void sorting_nomi(int count, rubrica_gen* rubrica){

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (strcmp(rubrica[j].nome, rubrica[j+1].nome) > 0) {
                // scambia i due elementi
                rubrica_gen temp = rubrica[j];
                rubrica[j] = rubrica[j+1];
                rubrica[j+1] = temp;
            }
        }
    }
}

void stampa_nomi(int count, rubrica_gen* rubrica){

    for(int i = 0; i<count; i++){
        printf("il nome e: %s , ", rubrica[i].nome);
    }
    printf("\n");
}

void sorting_cognomi(rubrica_gen* rubrica, int count){
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (strcmp(rubrica[j].cognome, rubrica[j+1].cognome) < 0) {
                // scambia i due elementi
                rubrica_gen temp = rubrica[j];
                rubrica[j] = rubrica[j+1];
                rubrica[j+1] = temp;
            }
        }
    }
}

void stampa_cognomi(rubrica_gen* rubrica, int count){
    for(int i =0; i<count -1 ; i++){
        printf("il cognome e: %s\n", rubrica[i].cognome);
    }

}