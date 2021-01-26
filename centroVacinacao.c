#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "centroVacinacao.h"

CentroVacinacao criarCentro(int centroID)
{
    CentroVacinacao c;
    char temp[20];

    printf("Nome do Centro: ");
    while (getchar() != '\n')
        ;
    fgets(c.nomeCentro, NOME, stdin);
    printf("Codigo do Centro: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &c.codigoCentro);
    printf("Morada do Centro: ");
    fgets(c.morada, MORADA, stdin);
    return c;
}