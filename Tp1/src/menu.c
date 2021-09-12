#include "menu.h"

void menu()
{
    int escolha[3];
    int qtd;
    int resultadowij,fji,N,dj;
    char str[MAX];
    char *mat[MAX];
    char *plv;
    char *termo;
    tipoArvore teste = NULL;
    LOOP:
        print_menu1();
        scanf("%d", &escolha[0]);
    
        switch (escolha[0])
        {
        case 1:
            printf("Digite a quantidade de arquivos:\n");
            scanf("%d", &qtd);
            leArquivo(qtd, 0, &teste);
            print_menu2();
            scanf("%d", &escolha[1]);
        case 2:
            // Inserir palavras do dicionario (TST - FEITO)
            break;
        case 3:
            // Imprimir o indice invertido (PATRICIA - NAO FEITO)
            break;
        case 4:
            print_menu2();
            scanf("%d", &escolha[1]);
            break;
        default:
            break;
        }

        switch (escolha[1])
        {
        case 1:
            // Imprime palavra TST (TST - NAO FEITO)
            break;
        case 2:
            //Busca uma plv (PATRICIA - NAO FEITO)
            break;
        case 3:
            // GTK (AMBOS - NAO FEITO)
            break;
        case 4: // FORMULAS
            printf("Digite o termo para consulta: ");
            scanf("%s",termo);
            N=qtd;
            dj = pesquisa(termo,teste,1);
            fji = pesquisa(termo,teste,2);
            printf("%d",dj);
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
    printf("1 - Imprimir as palavras da TST  2 - Buscar por uma palavra na PATRICIA  3 - Abrir o GTK  4 - Sair");
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