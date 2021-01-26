#include "listaUtentes.h"
#include <stdio.h>

void acrescentaUtente(ListaUtentes *lu, Utente u)
{
    lu->utentes[lu->numeroUtentes++] = u;
}

void gravarDadosListaUtentes(ListaUtentes lu)
{
    FILE *file = fopen("listaUtentes.dat", "wb");
    rewind(file);
    fwrite(&lu, sizeof(ListaUtentes), 1, file);
    fclose(file);
}

void carregarDadosListaUtentes(ListaUtentes *lu)
{
    FILE *file;
    file = fopen("listaUtentes.dat", "rb");

    if (file == NULL)
        return;

    fread(lu, sizeof(ListaUtentes), 1, file);

    fclose(file);
}