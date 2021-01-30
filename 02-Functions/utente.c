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
    do
    {
        fgets(u.nomeUtente, NOME, stdin);
    } while (u.nomeUtente[0] == '\n' && u.nomeUtente[1] == '\0');
    u.nomeUtente[strlen(u.nomeUtente) - 1] = '\0';
    printf("Numero do Utente: ");

    printf("Idade do Utente: ");
    fgets(temp, sizeof(temp), stdin);
    do
    {
        fgets(temp, sizeof(temp), stdin);
    } while (!(u.numeroUtente >= 0));
    sscanf(temp, "%d", &u.idade);
    printf("Contacto do Utente: ");
    do
    {
        fgets(u.contacto, CONTACTO, stdin);
    } while (strlen(u.contacto) != 10);
    u.contacto[strlen(u.contacto) - 1] = '\0';
    u.utenteID = utenteID;
    return u;
}