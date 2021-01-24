#define NOME 100
#define CONTACTO 11
#define DATA 10

typedef struct sUtente
{
    int numeroUtente;
    char nomeUtente[NOME];
    int idade;
    char contacto[CONTACTO];
    int vacinaID;
    int centroID;
    int activo;
    int dosesAdministradas;
    char dataUltimaDose[DATA];
} Utente;

Utente criarUtente();