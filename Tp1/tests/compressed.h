#include "tadpat.h"
#ifndef COMPRESSED_H
#define COMPRESSED_H

typedef struct compressedNode* treeType;
typedef struct compressedNode{
    int bitNumber;
    char data[MAX];
    treeType filhoesq, filhodir;
}compressedNode;

int criaNo(compressedNode* raiz);
int estaVazio(compressedNode* raiz);
void fazVazio(compressedNode* raiz);
int search(compressedNode* raiz, char k[MAX]);
treeType insert(compressedNode* t, char palavra[MAX]);


#endif