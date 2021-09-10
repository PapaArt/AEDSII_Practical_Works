#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int contArq = 0;

void criaArquivos(int numArq) {

    for (int i = 1; i <= numArq; i++) {
        FILE *arquivo;
        char nomeArq[100];

        sprintf(nomeArq, "../data/arquivo%d.txt", i);

        arquivo = fopen(nomeArq, "w");

        if (arquivo != NULL) {
            fclose(arquivo);
            printf("Arquivo criado!!!\n");
            contArq++;
        } else {
            perror(nomeArq);
            exit(EXIT_FAILURE);
        }
    }
}

int main()
{
    criaArquivos(5);
    return 0;
}