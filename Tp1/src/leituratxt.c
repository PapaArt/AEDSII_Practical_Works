//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   //
//     3886 - Artur Papa        //

#include "leituratxt.h"

void leArquivo(int qtd, int contArq, tipoArvore *teste)
{

    for (int i = 1; i <= qtd; i++)
    {
        FILE *arquivo;
        char nomeArq[100];
        char linha[MAX];
        char *result;
        char *Str;

        sprintf(nomeArq, "../data/arquivo%d.txt", i);

        arquivo = fopen(nomeArq, "rt");

        if (arquivo != NULL)
        {
            while (!feof(arquivo))
            {
                // Lê uma linha (inclusive com o '\n')
                fflush(arquivo);
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
                    (*teste) = insere(Str, teste);
                    Str = strtok(NULL, " ");
                }
            }
            fclose(arquivo);
            contArq++;
        }
        else
        {
            perror(nomeArq);
            exit(EXIT_FAILURE);
        }
}
