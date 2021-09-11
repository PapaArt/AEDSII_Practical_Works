#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAX 100
#ifndef PATRICIA_H
#define PATRICIA_H

typedef unsigned char *tipoChave;
// typedef unsigned char tipoChave2[MAX];
typedef unsigned int tipoIndexAmp;
typedef unsigned char tipoDib;

typedef enum
{
    interno,
    externo
} tipoNo;

typedef struct tipoPatNo *tipoArvore;
typedef struct tipoPatNo
{
    tipoNo nt;
    int conta[2];
    union
    {
        struct
        {
            tipoIndexAmp indice;
            tipoArvore esq, dir;
            tipoDib desvio;
        } NInterno;
        int id;
        tipoChave chave;
    } NO;
} tipoPatNo;

tipoArvore CriaNoInt(int x, tipoArvore *esq, tipoArvore *dir, char d);
tipoArvore CriaNoExt(tipoChave k,int nArquivo);
short EExterno(tipoArvore p);
void pesquisa(tipoChave k, tipoArvore t);
tipoArvore insereEntre(tipoChave k, tipoArvore *t, int i, char d, int nArquivo);
tipoArvore insere(tipoChave k, tipoArvore *t,int nArquivo);
int diferenca(tipoChave k, tipoChave r);

#endif