#include "listaCentros.h"
#include <stdio.h>
#include <stdlib.h>

int listarCentros(ListaCentros lc)
{
    int centroId;
    for (int i = 0; i < lc.numeroCentros; i++)
    {
        printf("%d -> %s \n", lc.listaCentros[i].centroID, lc.listaCentros[i].nomeCentro);
    }
    scanf("%d", &centroId);

    return centroId;
}

void adicionarCentro(ListaCentros *lc)
{
    CentroVacinacao c = criarCentro(lc->numeroCentros);
    lc->listaCentros[lc->numeroCentros] = c;
    lc->numeroCentros++;
}

void carregarDadosListaCentros(ListaCentros *lc)
{
    FILE *file;
    file = fopen("listaCentros.dat", "rb");

    if (file == NULL)
        return;

    fread(lc, sizeof(ListaCentros), 1, file);

    fclose(file);
}

void gravarDadosListaCentros(ListaCentros lc)
{
    FILE *file = fopen("listaCentros.dat", "wb");
    rewind(file);
    fwrite(&lc, sizeof(ListaCentros), 1, file);
    fclose(file);
}

void getCentroById(int centroID, ListaCentros lc)
{
    for (int i = 0; i < lc.numeroCentros; i++)
    {
        if (lc.listaCentros[i].centroID == centroID)
        {
            printf("Codigo : %d\n", lc.listaCentros[i].codigoCentro);
            printf("Nome : %s\n", lc.listaCentros[i].nomeCentro);
            printf("Morada : %s\n", lc.listaCentros[i].morada);
        }
    }
}

void menuCentro()
{
    ListaCentros lc;
    int opcao;

    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#            MENU DE CENTROS´           #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#\t 1 - CRIAR CENTRO               #\n");
    printf("#                                       #\n");
    printf("#\t 2 - EDITAR CENTRO              #\n");
    printf("#                                       #\n");
    printf("#\t 3 - INATIVAR CENTRO            #\n");
    printf("#                                       #\n");
    printf("#\t 4 - LISTAR CENTROS             #\n");
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
        adicionarCentro(&lc);
        gravarDadosListaCentros(lc);
        break;
    case 2:
        //editarVacina();
        break;
    case 3:
        //inativarVacina();
        break;
    case 4:
        listarCentros(lc);
        break;
    case 0:
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}