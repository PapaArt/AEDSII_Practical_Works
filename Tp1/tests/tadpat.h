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
            tipoDib desvio;
        }NInterno;
        tipoChave chave;
        int cont;
    }NO;
}tipoPatNo;

tipoArvore CriaNoInt(int x, tipoArvore* esq, tipoArvore* dir, char d);
tipoArvore CriaNoExt(tipoChave k);
short EExterno(tipoArvore p);
void pesquisa(tipoChave k, tipoArvore t);
tipoArvore insereEntre(tipoChave k, tipoArvore *t, int i,char d);
tipoArvore insere(tipoChave k, tipoArvore* t);
int diferenca(tipoChave k, tipoChave r);
int comp();

#endif