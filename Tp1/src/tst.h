#include "patricia.h"

struct Node
{
	char data;

	// True if this character is last character of one of the words
	unsigned isEndOfString: 1;

	struct Node *left, *eq, *right;
};

struct Node* newNode(char data);
void insert(struct Node** root, char *word);
void traverseTSTUtil(struct Node* root, char* buffer, int depth);
void traverseTST(struct Node* root);
int searchTST(struct Node *root, char *word);
