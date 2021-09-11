#include "tst.h"

Node novoNo(char data)
{
    Node temp = (Node)malloc(sizeof(tipoNo));
    temp->data = data;
    temp->fimDaPalavra = 0;
    temp->esq = temp->eq = temp->dir = NULL;
    return temp;
}

void insert(Node* raiz, char *word)
{
    if (!(*raiz))
        *raiz = novoNo(*word);
    
    if ((*word) < (*raiz)->data)
        insert((*raiz)->esq, word);
    else if ((*word) > (*raiz)->data)
        insert((*raiz)->dir, word);

    else
    {
        if (*(word+1))
            insert((*raiz)->eq, word+1);
        else
            (*raiz)->fimDaPalavra = 1;
    }
}

void traverseTSTUtil(Node raiz, char* buffer, int depth)
{
    if ((raiz))
    {
        traverseTSTUtil(raiz->esq, buffer, depth);

        buffer[depth] = raiz->data;
        if (raiz->fimDaPalavra)
        {
            buffer[depth+1] = '\0';
            printf("%s\n", buffer);
        }
        traverseTSTUtil(raiz->esq, buffer, depth+1);

        traverseTSTUtil(raiz->dir, buffer, depth);
    }
}

void traverseTST(Node raiz)
{
    char buffer[MAX];
    traverseTSTUtil(raiz, buffer, 0);
}

int pesquisaTST(Node raiz, char* word)
{
    if (!raiz)
        return 0;
    if (*word < raiz->data)
        return pesquisaTST(raiz->esq, word);
    else if (*word > raiz->data)
        return pesquisaTST(raiz->dir, word);
    
    else
    {
        if (*(word+1) == '\0')
            return raiz->fimDaPalavra;
        
        return pesquisaTST(raiz->eq, word+1);
    }
}