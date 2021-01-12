#include "vacina.h"
#include "data.h"

typedef struct sUtentes
{
    int numeroUtente[10];
    char firstName[20];
    char lastName[20];
    int idade;
    int contactoTelefonico[9];
    Vacina vacinaUsada;
    short quantidadeDoses;
    Data dataUltimaDose;
} Utentes;