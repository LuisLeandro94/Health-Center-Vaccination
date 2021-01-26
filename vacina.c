#include "vacina.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Vacina criarVacina(int vacinID)
{
    Vacina v;
    char temp[20];

    printf("Nome : ");
    while (getchar() != '\n')
        ;
    fgets(v.designacaoVacina, DESIGNACAO, stdin);
    printf("Codigo : ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &v.codigoVacina);
    printf("Numero de Doses a tomar por paciente: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &v.numDoses);
    printf("Meses entre doses: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &v.mesesEntreDoses);
    return v;
}
