#include "listaVacinas.h"
#include <stdio.h>
#include <stdlib.h>

int listarVacinas(ListaVacinas lv)
{
    int vacinaId;
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        printf("%d -> %s \n", lv.listaVacinas[i].vacinaID, lv.listaVacinas[i].designacaoVacina);
    }
    scanf("%d", &vacinaId);

    //falta controlar a opção inserida se existe ou nao
    return vacinaId;
}

void adicionarVacina(ListaVacinas *lv)
{
    Vacina v = criarVacina(lv->numeroVacinas);
    lv->listaVacinas[lv->numeroVacinas++] = v;
}

void carregarDadosListaVacinas(ListaVacinas *lv)
{
    FILE *file;
    file = fopen("listaVacinas.dat", "rb");

    if (file == NULL)
        return;

    fread(lv, sizeof(ListaVacinas), 1, file);

    fclose(file);
}

void gravarDadosListaVacinas(ListaVacinas lv)
{
    FILE *file = fopen("listaVacinas.dat", "wb");
    rewind(file);
    fwrite(&lv, sizeof(ListaVacinas), 1, file);
    fclose(file);
}

void getVacinaByID(int vacinaID, ListaVacinas lv)
{
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        if (lv.listaVacinas[i].vacinaID == vacinaID)
        {
            printf("Codigo : %d\n", lv.listaVacinas[i].codigoVacina);
            printf("Designacao : %s\n", lv.listaVacinas[i].designacaoVacina);
            printf("Numero Doses : %d\n", lv.listaVacinas[i].numDoses);
            printf("Tempo entre Doses : %d meses\n", lv.listaVacinas[i].mesesEntreDoses);
        }
    }
}

void menuVacina()
{
    ListaVacinas lv;
    int opcao;

    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#            MENU DE VACINAS            #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#\t 1 - CRIAR VACINA               #\n");
    printf("#                                       #\n");
    printf("#\t 2 - EDITAR VACINA              #\n");
    printf("#                                       #\n");
    printf("#\t 3 - INATIVAR VACINA            #\n");
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
        adicionarVacina(&lv);
        gravarDadosListaVacinas(lv);
        break;
    case 2:
        //editarVacina();
        break;
    case 3:
        //inativarVacina();
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}