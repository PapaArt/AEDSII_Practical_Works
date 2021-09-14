//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   //
//     3886 - Artur Papa        //

#include "leituratxt.h"

void criaArquivos(tipoArvore *teste, char *nomeArq)
{

    FILE *arquivo;
    char linha[MAX];

    arquivo = fopen(nomeArq, "r");

    if (arquivo == NULL)
    {
        perror(nomeArq);
        exit(EXIT_FAILURE);
    }
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s", linha);
        for (int i = 0; i < strlen(linha); i++)
        {
            linha[i] = tolower(linha[i]);
        }
        *teste = insere(linha, teste);
    }
    fclose(arquivo);
}

void leArquivo(int qtd, int contArq, tipoArvore *teste)
{

    FILE *arquivo;
    char nomeArq[100];
    char linha[MAX], linha2[MAX];
    char *result;
    char *Str;
    int i = 0;

    //sprintf(nomeArq, "../data/arquivo%d.txt", i);

    arquivo = fopen("../data/arquivo1.txt", "rt");
    while (!feof(arquivo))
    {
        // Lê uma linha (inclusive com o '\n')
        fscanf(arquivo, "%s", linha);
        while (linha != NULL)
        {
            linha[i] = tolower(linha[i]);
            //linha[i] = strtok(NULL, " ");
            i++;
        }
        *teste = insere(linha, teste);
        printf("%s\n", linha);
    }
    contArq++;
    fclose(arquivo);
    printf("Arquivo lido!!!\n");
}
