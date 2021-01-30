#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../01-Data/centroVacinacao.h"

CentroVacinacao criarCentro(int centroID)
{
    CentroVacinacao c;
    char temp[20];
    int status;

    printf("Nome do Centro: ");
    do
    {
        while (getchar() != '\n')
        ;
        fgets(c.nomeCentro, NOME, stdin);
    } while (!((c.nomeCentro[0] >= 'a' && c.nomeCentro[0] <= 'z')||(c.nomeCentro[0] >= 'A' && c.nomeCentro[0] <= 'Z')||(c.nomeCentro[0] == ' ')));
    c.nomeCentro[strlen(c.nomeCentro) - 1] = '\0';
    printf("Codigo do Centro: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &c.codigoCentro);
    printf("Morada do Centro: ");
    fgets(c.morada, MORADA, stdin);
    c.activo = 1;
    c.centroID = centroID;

    return c;
}