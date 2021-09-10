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
