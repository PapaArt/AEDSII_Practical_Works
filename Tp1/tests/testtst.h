#include "patricia.h"

typedef struct TSTNode* tipoTST;
typedef struct TSTNode{
    bool end_of_string;
    tipoTST *left, *right, *middle;
    char value;
}TSTNode;

TSTNode init(tipoTST* raiz);
TSTNode *insert(TSTNode *head, char* str, int idx);
bool search(tipoTST* raiz, char* str);
char* bfs(char* str);
char* AutoComplete(char* str);