//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   // 
//     3886 - Artur Papa        //

#include "menu.h"

void menu()
{
    int escolha[3];
    int qtd;
    int resultadowij, fji, N, dj;
    char str[MAX];
    char *mat[MAX];
    char *plv;
    char termo[MAX];
    char busca[MAX];
    char searchForWord[WORD_SIZE];
    char buffer[MAX];
    char word[WORD_SIZE];
    char buscaDicio[100];
    char espaco[] = "\n";
    int choice = 0;
    tipoArvore teste = NULL;
    trie_t trie;       //Declara nova  Trie ADT
    initialize(&trie); //Inicializa a Trie
    FILE *file = fopen("../data/palavras.txt", "r");

LOOP:
    print_menu1();
    scanf("%d", &escolha[0]);

    switch (escolha[0])
    {
    case 1:
        printf("Digite a quantidade de arquivos:\n");
        scanf("%d", &qtd);
        printf("Lista de palavras inseridas:\n");
        leArquivo(qtd, 0, &teste);
        goto LOOP;
        break;
    case 2:
        // Inserir palavras do dicionario (TST - FEITO)
        while (fscanf(file, "%s", word) != EOF)
        {
            for(int i=0;i<strlen(word);i++){
                word[i]=tolower(word[i]);
            }                  //Ler palavras para dentro da variavel "word"
            insert(&trie, word); //inserir palavra na trie
        }
        printf("Dicionario inserido com sucesso!!!\n");
        goto LOOP;
        break;
    case 3:
        goto LOOP;
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
    case 5:
        // Imprime palavra TST
        imprimeTST(trie);
        break;
    case 6:
        //Busca uma palavra 
        printf("Digite a palavra a ser buscada:");
        scanf("%s",busca);
        pesquisa(busca,teste);
        break;
    case 7:
        // Autopreenchimento
        printf("Digite a palavra a ser buscada: \n");

        while (scanf("%s", searchForWord) != EOF)
        { 
            int i;
            int isValid = 1;
            for (i = 0; i < strlen(searchForWord); i++)
            {
                //loop pela palavra e checar a validade
                char c = searchForWord[i];
                if (!isalpha(c))
                {                //if encontra algum caractere fora do alfabeto
                    isValid = 0; //invalida
                }
            }
            if (!isValid){
                printf("Entrada invalida!\n");
                break;
            }
            if (isValid)
                traverse(&trie, searchForWord); //palavra valida: imprime
            printf("Digite a palavra a ser buscada: \n");
        }
        break;
    case 8: // SAIR
        exit(1);
        break;
    default:
        break;
    }
    fclose(file);
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
    printf("5 - Imprimir as palavras da TST  6 - Buscar por uma palavra na PATRICIA  7 - Autopreenchimento  8 - Sair");
    for (i = 0; i < 3; i++)
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