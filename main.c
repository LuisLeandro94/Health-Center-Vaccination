#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaUtentes.h"
#include "listaVacinas.h"
#include "listaCentros.h"

void menuUtente(ListaUtentes *lu, ListaCentros lc, ListaVacinas lv)
{
    Utente u = criarUtente(lu->utentes[lu->numeroUtentes - 1].utenteID + 1);
    printf("Introduza o centro:\n");
    u.centroID = listarCentros(lc);
    printf("Introduza a vacina:\n");
    u.vacinaID = listarVacinas(lv);
    acrescentaUtente(lu, u);
}

void removerUtente(ListaUtentes *lu, int numUtente)
{
    Utente u;
    listarUtentes(*lu);
    printf("Escolha o utente a remover: ");
    scanf("%d", &numUtente);
    if (numUtente >= lu->numeroUtentes + 1)
    {
        printf("Impossivel apagar. Utente inexistente.");
    }
    else
    {
        int i;
        for (i = 0; i < lu->numeroUtentes; i++)
        {
            if (lu->utentes[i].utenteID == numUtente)
                break;
        }
        for (int j = i + 1; j < lu->numeroUtentes; j++)
        {
            lu->utentes[j - 1] = lu->utentes[j];
        }
        lu->numeroUtentes = lu->numeroUtentes - 1;
    }
}

void dashboard()
{
    ListaUtentes lu;
    ListaVacinas lv;
    ListaCentros lc;

    float media = mediaIdades(lu);

    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#               DASHBOARD               #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("\n");
    printf("Quantidade vacinas administradas: %d\n", lv.numeroVacinas);
    printf("Média de idades dos utentes vacinados: %.2f\n", media);
    printf("Quantidade de utentes vacinados por vacina:\n");
}
void menuUtentes(ListaUtentes *lu, ListaVacinas *lv, ListaCentros *lc)
{
    int opcao;
    int numUtente;

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
    printf("#\t 4 - LISTAR UTENTES             #\n");
    printf("#                                       #\n");
    printf("#\t 0 - SAIR                       #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf(">\t Digite a sua opcao -> ");
    scanf("%d", &opcao);
    system("cls");

    switch (opcao)
    {
    case 1:
        menuUtente(lu, *lc, *lv);
        gravarDadosListaUtentes(*lu);
        system("cls");
        break;
    case 2:
        editaUtente(lu, numUtente);
        gravarDadosListaUtentes(*lu);
        system("cls");
        break;
    case 3:
        removerUtente(lu, numUtente);
        gravarDadosListaUtentes(*lu);
        system("cls");
        break;
    case 4:
        listarUtentes(*lu);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

void menuInicial(ListaCentros *lc, ListaUtentes *lu, ListaVacinas *lv)
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
        menuUtentes(lu, lv, lc);
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

    ListaCentros lc;
    ListaVacinas lv;
    ListaUtentes lu;

    lc.numeroCentros = 0;
    lv.numeroVacinas = 0;
    lu.numeroUtentes = 0;

    carregarDadosListaCentros(&lc);
    carregarDadosListaUtentes(&lu);
    carregarDadosListaVacinas(&lv);
    int opcao = -1;

    //dashboard();
    while (opcao != 0)
    {
        menuInicial(&lc, &lu, &lv);
    }
}