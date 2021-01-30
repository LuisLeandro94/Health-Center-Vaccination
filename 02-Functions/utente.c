#include <stdio.h>
#include <string.h>
#include "../01-Data/utente.h"

Utente criarUtente(int utenteID)
{
    Utente u;
    int centro;
    int vacina;
    char temp[20];

    printf("Nome do Utente: ");
    while (getchar() != '\n')
        ;
    fgets(u.nomeUtente, NOME, stdin);
    u.nomeUtente[strlen(u.nomeUtente) - 1] = '\0';
    printf("Numero do Utente: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &u.numeroUtente);
    printf("Idade do Utente: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &u.idade);
    printf("Contacto do Utente: ");
    fgets(u.contacto, CONTACTO, stdin);
    u.contacto[strlen(u.contacto) - 1] = '\0';
    u.utenteID = utenteID;
    return u;
}