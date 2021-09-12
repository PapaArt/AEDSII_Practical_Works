#include "patricia.h"

struct Node
{
	char data;

	// True if this character is last character of one of the words
	unsigned fimDaPalavra: 1;

	struct Node *esq, *eq, *dir;
};

struct Node* novoNo(char data);
void insert(struct Node** raiz, char *word);
void traverseTSTUtil(struct Node* raiz, char* buffer, int depth);
void traverseTST(struct Node* raiz);
int pesquisaTST(struct Node *raiz, char *word);
char* removerAcentos(char* texto);

// C program to search and replace
// all occurrences of a word with
// other word.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to replace a string with another
// string


// Driver Program
int main()
{
	char str[] = "xxforxx xx for xx";
	char c[] = "xx";
	char d[] = "Geeks";

	char* result = NULL;

	// oldW string
	printf("Old string: %s\n", str);

	result = replaceWord(str, c, d);
	printf("New String: %s\n", result);

	free(result);
	return 0;
}
