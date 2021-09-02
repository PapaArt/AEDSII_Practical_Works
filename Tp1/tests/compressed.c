#include "compressed.h"

int criaNo(compressedNode *raiz)
{
    raiz = NULL;
}

int estaVazio(compressedNode *raiz)
{
    return raiz == NULL;
}

void fazVazio(compressedNode *raiz)
{
    raiz = NULL;
}

int search(compressedNode *raiz, char k[MAX])
{
    int numeroBits = (int)(log10(k[MAX]) / log10(2)) + 1;
    if (numeroBits > 10)
    {
        printf("Erro: numero muito grande");
        return 1; // Retorna falso
    }
    compressedNode *nodepesquisa;

    search(raiz, k);

    if (nodepesquisa->data == k)
        return 0; //Retorna verdadeiro
    else
        return 1; //Retorna falso
}

treeType insert(compressedNode *t, char palavra[MAX])
{
    compressedNode *atual, *pai;
    compressedNode *ultimoNo;
    compressedNode *novoNo;
    tipoChave palavraC;
    int i;
    novoNo = (treeType) malloc (sizeof(compressedNode));
    // Se o no esta vazio
    if (t == NULL)
    {
        criaNo(t);
        t->bitNumber = 0;
        strcpy(t->data,palavra);
        t->filhoesq = t;
        t->filhodir = NULL;
        return t;
    }
    // Pesquisa pela palavra
    search(t, palavra);

    // Se a chave já estiver presente
    if (palavra == ultimoNo->data)
    {
        printf("Erro: chave já esta presente\n");
        return t;
    }
    strcpy(palavraC,palavra);
    for (i = 1; bit(i, palavraC) == bit(i, ultimoNo->data); i++)

        atual = t->filhoesq;
    pai = t;
    while (atual->bitNumber > pai->bitNumber && atual->bitNumber < i)
    {
        pai = atual;
        atual = (bit(atual->bitNumber, palavra)) ? atual->filhodir : atual->filhoesq;
    }

    criaNo(novoNo);
    novoNo->bitNumber = i;
    strcpy(palavra, t->data);
    novoNo->filhoesq = bit(i, palavra) ? atual : novoNo;
    novoNo->filhodir = bit(i, palavra) ? novoNo : atual;

    if (atual == pai->filhoesq)
        pai->filhoesq = novoNo;
    else
        pai->filhodir = novoNo;

    return t;
}
