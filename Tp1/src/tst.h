#include "patricia.h"

typedef struct tipoNo* Node;
typedef struct tipoNo
{
    char data;
    unsigned fimDaPalavra: 1;
    Node *esq, *dir, *eq;
}tipoNo;

Node novoNo(char data);
void insert(Node* raiz, char *word);
void traverseTSTUtil(Node raiz, char* buffer, int depth);
void traverseTST(Node raiz);
int pesquisaTST(Node raiz, char* word);