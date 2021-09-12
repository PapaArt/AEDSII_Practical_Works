#include "patricia.h"

struct Node
{
	char data;

	// True if this character is last character of one of the words
	unsigned fimDaPalavra : 1;

	struct Node *esq, *eq, *dir;
};

struct Node *novoNo(char data);
void insert(struct Node **raiz, char *word);
void traverseTSTUtil(struct Node *raiz, char *buffer, int depth);
void traverseTST(struct Node *raiz);
int pesquisaTST(struct Node *raiz, char *word);
void insereDicio(char *word, int choice);