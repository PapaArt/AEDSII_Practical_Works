#include "patricia.h"
#define ALPHABET_SIZE (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

struct Node
{
	char data;
	struct Node* children[ALPHABET_SIZE];	
	// True if this character is last character of one of the words
	unsigned isEndOfString: 1;

	struct Node *left, *eq, *right;
};

struct Node* newNode(char data);
void insertNode(struct Node **root, char *word);
void insert(struct Node** root, char *word);
void traverseTSTUtil(struct Node* root, char* buffer, int depth);
void traverseTST(struct Node* root);
int searchTST(struct Node *root, char *word);