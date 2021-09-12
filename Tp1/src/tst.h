#include "patricia.h"
typedef struct Node* TSTnode;

struct Node
{
	char data;

	// True if this character is last character of one of the words
	unsigned fimDaPalavra : 1;

	TSTnode esq, eq, dir;
};

TSTnode novoNo(char data);
void insert(TSTnode *raiz, char *word);
void traverseTSTUtil(TSTnode raiz, char *buffer, int depth);
void traverseTST(TSTnode raiz);
int pesquisaTST(TSTnode raiz, char *word);
void insereDicio(TSTnode*raiz, char *word, int choice);
void imprimeTST(TSTnode raiz);