#include "leituratxt.h"

char* learqv()
{
    FILE *arq;
    char *Linha;
    char *result;
    char *Str;

    arq = fopen("../data/arquivo1.txt", "rt");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    }
    while (!feof(arq))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 100, arq);
        for(int k = 0; k<= strlen(Linha); k++){
            if(ispunct(Linha[k])){
                Linha[k] = Linha[k+1];
            }
        }
        Str = strtok(Linha, " ");
        while (Str != NULL)
        {
            Str[0]= tolower(Str[0]);
            return Str;
            Str = strtok(NULL," ");
        }
    }
    fclose(arq);
}
