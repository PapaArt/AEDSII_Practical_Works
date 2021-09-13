//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   //
//     3886 - Artur Papa        //

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 100
#define WORD_SIZE 25 
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
    int conta[10];
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
int pesquisa(tipoChave k, tipoArvore t);
tipoArvore insereEntre(tipoChave k, tipoArvore *t, int i, char d, int nArquivo);
tipoArvore insere(tipoChave k, tipoArvore *t,int nArquivo);
int diferenca(tipoChave k, tipoChave r);

#endif