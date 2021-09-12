#include "patricia.h"
#define ALPHABET_SIZE (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
typedef struct Node* TSTnode;

struct Node
{
	char data;
	TSTnode children[ALPHABET_SIZE]; 
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
bool isLastNode(TSTnode root);
void suggestionsRec(TSTnode root, char currPrefix[]);
int printAutoSuggestions(TSTnode root, const char query[]);