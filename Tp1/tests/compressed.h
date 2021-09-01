#include "tadpat.h"
#ifndef COMPRESSED_H
#define COMPRESSED_H

typedef struct compressedNode* treeType;
typedef struct compressedNode{
    int bitNumber;
    int data;
    treeType filhoesq, filhodir;
}compressedNode;

int criaNo(compressedNode* raiz);
int estaVazio(compressedNode* raiz);
void fazVazio(compressedNode* raiz);
int search(compressedNode* raiz, int k);
treeType insert(compressedNode* t, int palavra);

#endif