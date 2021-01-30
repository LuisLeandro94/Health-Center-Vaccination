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
    int dosesAdministradas;
    int diaUltimaDose;
    int mesUltimaDose;
    int anoUltimaDose;
    int utenteID;
} Utente;

Utente criarUtente();