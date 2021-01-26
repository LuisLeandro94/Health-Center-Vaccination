#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaUtentes.h"
#include "listaVacinas.h"
#include "listaCentros.h"

void menuUtente(ListaUtentes *lu, ListaCentros lc, ListaVacinas lv)
{
    Utente u = criarUtente();
    printf("Introduza o centro:\n");
    u.centroID = listarCentros(lc);
    printf("Introduza a vacina:\n");
    u.vacinaID = listarVacinas(lv);
    acrescentaUtente(lu, u);
}

void menuUtentes(ListaUtentes lu, ListaCentros lc, ListaVacinas lv)
{
    int opcao;

    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#            MENU DE UTENTES            #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#\t 1 - CRIAR NOVO UTENTE          #\n");
    printf("#                                       #\n");
    printf("#\t 2 - EDITAR UTENTE              #\n");
    printf("#                                       #\n");
    printf("#\t 3 - REMOVER UTENTE             #\n");
    printf("#                                       #\n");
    printf("#\t 0 - SAIR                       #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf(">\t Digite a sua opcao -> ");
    scanf("%d", &opcao);
    system("clear");

    switch (opcao)
    {
    case 1:
        menuUtente(&lu, lc, lv);
        gravarDadosListaUtentes(lu);
        break;
    case 2:
        //editarUtente(&lu, lc, lv);
        break;
    case 3:
        //removerUtente(&lu, lc, lv);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

void menuInicial(ListaCentros lc, ListaUtentes lu, ListaVacinas lv)
{
    int opcao;

    printf("########################################\n");
    printf("#                                      #\n");
    printf("#             MENU INICIAL             #\n");
    printf("#                                      #\n");
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#\t 1 - CENTROS DE VACINACAO      #\n");
    printf("#                                      #\n");
    printf("#\t 2 - UTENTES                   #\n");
    printf("#                                      #\n");
    printf("#\t 3 - VACINAS                   #\n");
    printf("#                                      #\n");
    printf("#\t 0 - SAIR                      #\n");
    printf("#                                      #\n");
    printf("########################################\n");
    printf(">\t Digite a sua opcao -> ");
    scanf("%d", &opcao);
    system("cls");

    switch (opcao)
    {
    case 1:
        menuCentro(lc);
        break;
    case 2:
        menuUtentes(lu, lc, lv);
        break;
    case 3:
        menuVacina(lv);
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

int main(int argc, char const *argv[])
{
    //Definicao de SNS
    ListaUtentes lu;
    ListaCentros lc;
    ListaVacinas lv;

    carregarDadosListaCentros(&lc);
    carregarDadosListaUtentes(&lu);
    carregarDadosListaVacinas(&lv);

    int opcao = -1;

    while (opcao != 0)
    {
        menuInicial(lc, lu, lv);
    }
}