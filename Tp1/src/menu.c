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
    char searchForWord[WORD_SIZE];
    char buffer[MAX];
    char word[WORD_SIZE];
    char buscaDicio[100];
    char espaco[] = "\n";
    int choice = 0;
    tipoArvore teste = NULL;
    trie_t trie;       //Instantiate new Trie ADT
    initialize(&trie); //Initialize the Trie
    FILE *file = fopen("../data/palavras.txt", "r");

LOOP:
    print_menu1();
    scanf("%d", &escolha[0]);

    switch (escolha[0])
    {
    case 1:
        print_menu2();
        scanf("%d", &escolha[1]);
        break;
    case 2:
        // Inserir palavras do dicionario (TST - FEITO)
        while (fscanf(file, "%s", word) != EOF)
        {
            for(int i=0;i<strlen(word);i++){
                word[i]=tolower(word[i]);
            }                  //Read words into variable "word"
            insert(&trie, word); //insert words into trie
        }
        goto LOOP;
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
        // Imprime palavra TST (TST - FEITO)
        imprimeTST(trie);
        break;
    case 2:
        //Busca uma plv (PATRICIA - NAO FEITO)
        break;
    case 3:
        // GTK (AMBOS - NAO FEITO)
        printf("ENTER A WORD TO SEARCH FOR: (CTRL-D to end)\n");

        while (scanf("%s", searchForWord) != EOF)
        { //Checks CTRL-D
            int i;
            int isValid = 1;
            for (i = 0; i < strlen(searchForWord); i++)
            {
                //loop through word and check validity
                char c = searchForWord[i];
                if (!isalpha(c))
                {                //if found any characters non-alpha
                    isValid = 0; //invalid
                }
            }
            if (!isValid)
                printf("Invalid input! Letters only!\n");
            if (isValid)
                traverse(&trie, searchForWord); //word is valid:traverse
            printf("ENTER A WORD TO SEARCH FOR: (CTRL-D to end)\n");
        }
        break;
    case 4: // FORMULAS
        printf("Digite a quantidade de arquivos:\n");
        scanf("%d", &qtd);
        //leArquivo(qtd, 0, &teste);
        printf("Digite o termo para consulta: ");
        scanf("%s", termo);
        printf("%s\n", termo);
        //N = qtd;
        //dj = pesquisa(termo, teste);
        //fji = pesquisa(termo, teste);
        //printf("%d", dj);
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