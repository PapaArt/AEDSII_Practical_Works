#include "leituratxt.h"

void learqv(char *palavra)
{
    FILE *arq;
    char Linha[MAX];
    char *result;
    char* Str;
    arq = fopen("../data/arquivo2.txt", "rt");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    }
    while (!feof(arq))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, MAX, arq);
        strcpy(palavra, Linha);
    }
    fclose(arq);
}
