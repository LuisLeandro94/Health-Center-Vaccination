#define DESIGNACAO 25

typedef struct sVacina
{
    int codigoVacina;
    char designacaoVacina[DESIGNACAO];
    int numDoses;
    int mesesEntreDoses;
    int vacinaID;
} Vacina;

Vacina criarVacina(int vacinID);