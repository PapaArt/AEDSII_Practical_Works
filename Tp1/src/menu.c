#include "menu.h"

void menu()
{
    int escolha[3];
    int qtd;
    char str[MAX];
    char *mat[MAX];
    char *plv;
    tipoArvore teste = NULL;

    print_menu1();
    scanf("%d", &escolha[0]);

    switch (escolha[0])
    {
    case 1:
        printf("Digite a quantidade de arquivos:\n");
        scanf("%d", &qtd);
        leArquivo(qtd, 0, teste);
        break;
    case 2:
        print_menu2();
        scanf("%d", &escolha[2]);
        break;
    case 3:

    case 4:
        print_menu2();
        scanf("%d", &escolha[1]);
        break;
    default:
        break;
    }
}

void print_menu2()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 56; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 53; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|        ");
    for (i = 0; i < 105; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|                                 ");
    for (i = 0; i < 15; i++)
    {
        fputs(" ", stdout);
    }
    printf("Escolha o que fazer:");
    for (i = 0; i < 45; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 6; i++)
    {
        fputs(" ", stdout);
    }
    printf("5 - Imprimir as palavras da TST  6 - Buscar por uma palavra na PATRICIA  7 - Abrir o GTK  8 - Sair");
    for (i = 0; i < 9; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("---------->");
    fflush(stdin);
}

void print_menu1()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 56; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 53; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|        ");
    for (i = 0; i < 105; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|                                 ");
    for (i = 0; i < 16; i++)
    {
        fputs(" ", stdout);
    }
    printf("Escolha o que fazer:");
    for (i = 0; i < 44; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|     ");
    fputs(" ", stdout);
    printf("1 - Construir indice invertido  2 - Inserir palavras do dicionario  3 - Imprimir o indice   4 - Outro");
    for (i = 0; i < 6; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("---------->");
    fflush(stdin);
}