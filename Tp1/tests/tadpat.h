#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
#ifndef TADPAT_H
#define TADPAT_H

typedef unsigned char* tipoChave;
// typedef unsigned char tipoChave2[MAX];
typedef unsigned int tipoIndexAmp;
typedef unsigned char tipoDib;

typedef enum{
    interno, externo
}tipoNo;

typedef struct tipoPatNo* tipoArvore;
typedef struct tipoPatNo{
    tipoNo nt;
    union
    {
        struct
        {
            tipoIndexAmp indice;
            tipoArvore esq, dir;
        }NInterno;
        tipoChave chave;
    }NO;
}tipoPatNo;

tipoDib bit(tipoIndexAmp i, tipoChave k);
tipoArvore CriaNoInt(int x, tipoArvore* esq, tipoArvore* dir);
tipoArvore CriaNoExt(tipoChave k);
short EExterno(tipoArvore p);
void pesquisa(tipoChave k, tipoArvore t);
tipoArvore insereEntre(tipoChave k, tipoArvore *t, int i);
tipoArvore insere(tipoChave k, tipoArvore* t);
int diferenca(tipoChave k, tipoChave r);

#endif