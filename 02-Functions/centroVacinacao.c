#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../01-Data/centroVacinacao.h"

CentroVacinacao criarCentro(int centroID)
{
    CentroVacinacao c;
    char temp[20];

    printf("Nome do Centro: ");
    while (getchar() != '\n')
        ;
    fgets(c.nomeCentro, NOME, stdin);
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