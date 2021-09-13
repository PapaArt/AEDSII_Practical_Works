//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   // 
//     3886 - Artur Papa        //

#include "leituratxt.h"

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

void leArquivo(int qtd, int contArq, tipoArvore *teste)
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
                fscanf(arquivo, "%s", linha);
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
                    *teste = insere(Str, teste);
                    Str = strtok(NULL, " ");
                }
            }
            fclose(arquivo);
            contArq++;
            printf("Arquivo lido!!!\n");
        }
        else
        {
            perror(nomeArq);
            exit(EXIT_FAILURE);
        }
    }
}