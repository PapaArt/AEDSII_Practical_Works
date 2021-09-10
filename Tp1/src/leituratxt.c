#include "leituratxt.h"

void learqv(char *palavra, int qtd)
{
    FILE *arq;
    FILE *arq2;
    char Linha[MAX], Linha2[25];
    char *result;
    char *Str;
    char *nomes;

    arq = fopen("../data/nomes.txt", "rt");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    }

    for (int i = 0; i < qtd; i++)
    {
        nomes = fgets(Linha2, 25, arq);
        arq2 = fopen(nomes, "rt");
        if (arq2 == NULL)
        {
            printf("Problemas na CRIACAO do arquivo\n");
        }
        while (!feof(arq2))
        {
            // Lê uma linha (inclusive com o '\n')
            result = fgets(Linha, MAX, arq2);
            strcpy(palavra, Linha);
        }
    }

    fclose(arq2);
    fclose(arq);
}

void criaArquivos(int qtd, int contArq)
{

    for (int i = 1; i <= qtd; i++)
    {
        FILE *arquivo;
        char nomeArq[100];

        sprintf(nomeArq, "../data/arquivo%d.txt", i);

        arquivo = fopen(nomeArq, "w");

        if (arquivo != NULL)
        {
            fclose(arquivo);
            printf("Arquivo criado!!!\n");
            contArq++;
        }
        else
        {
            perror(nomeArq);
            exit(EXIT_FAILURE);
        }
    }
}

void leArquivo(int qtd, int contArq)
{

    for (int i = 1; i <= qtd; i++)
    {
        FILE *arquivo;
        char nomeArq[100];
        char linha[MAX], linha2[MAX];
        char *result;
        char *Str;

        sprintf(nomeArq, "../data/arquivo%d.txt", i);

        arquivo = fopen(nomeArq, "rt");

        if (arquivo != NULL)
        {
            while (!feof(arquivo))
            {
                // Lê uma linha (inclusive com o '\n')
                result = fgets(linha, MAX, arquivo);
                for (int k = 0; k <= strlen(linha); k++)
                {
                    if (ispunct(linha[k]))
                    {
                        linha[k] = linha[k + 1];
                    }
                }
                Str = strtok(linha, " ");
                while (Str != NULL)
                {
                    Str[0] = tolower(Str[0]);
                    printf("%s\n", Str);
                    Str = strtok(NULL, " ");
                }
            }
            printf("Arquivo lido!!!\n");
            fclose(arquivo);
            contArq++;
        }
        else
        {
            perror(nomeArq);
            exit(EXIT_FAILURE);
        }
    }
}