#include "testtst.h"

struct Node *newNode(char data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->isEndOfString = 0;
	temp->left = temp->eq = temp->right = NULL;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		temp->children[i] = NULL;
	return temp;
}
void insertNode(struct Node **root, char *word)
{
	struct Node **pCrawl = root;
	for (int level = 0; level < strlen(word); level++)
	{
		int index = CHAR_TO_INDEX(word[level]);
		if (!(*pCrawl)->children[index])
			(*pCrawl)->children[index] = newNode(*word);

		(*pCrawl) = (*pCrawl)->children[index];
	}

	// mark last node as leaf
	(*pCrawl)->isEndOfString = true;
}
// Function to insert a new word in a Ternary Search Tree
void insert(struct Node **root, char *word)
{
	struct Node **raiz;
	raiz=root;
	// Base Case: Tree is empty
	if (!(*root))
		*root = newNode(*word);

	// If current character of word is smaller than root's character,
	// then insert this word in left subtree of root
	if ((*word) < (*root)->data)
	{
		insert(&((*root)->left), word);
		insertNode(&((*raiz)->left), word);
	}

	// If current character of word is greate than root's character,
	// then insert this word in right subtree of root
	else if ((*word) > (*root)->data)
	{
		insert(&((*root)->right), word);
		//insertNode(&((*raiz)->right), word);
	}

	// If current character of word is same as root's character,
	else
	{
		if (*(word + 1))
		{
			insert(&((*root)->eq), word + 1);
			//insertNode(&((*raiz)->eq), word);
		}

		// the last character of the word
		else
			(*root)->isEndOfString = 1;
	}
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node *root, char *buffer, int depth)
{
	if (root)
	{
		// First traverse the left subtree
		traverseTSTUtil(root->left, buffer, depth);

		// Store the character of this node
		buffer[depth] = root->data;
		if (root->isEndOfString)
		{
			buffer[depth + 1] = '\0';
			printf("%s\n", buffer);
		}

		// Traverse the subtree using equal pointer (middle subtree)
		traverseTSTUtil(root->eq, buffer, depth + 1);

		// Finally Traverse the right subtree
		traverseTSTUtil(root->right, buffer, depth);
	}
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node *root)
{
	char buffer[MAX];
	traverseTSTUtil(root, buffer, 0);
}

// Function to search a given word in TST
int searchTST(struct Node *root, char *word)
{
	if (!root)
		return 0;

	if (*word < (root)->data)
		return searchTST(root->left, word);

	else if (*word > (root)->data)
		return searchTST(root->right, word);

	else
	{
		if (*(word + 1) == '\0')
			return root->isEndOfString;

		return searchTST(root->eq, word + 1);
	}
}

// Driver program to test above functions
int main()
{
	struct Node *root = NULL;

	insert(&root, "cat");
	insert(&root, "cats");
	insert(&root, "up");
	insert(&root, "bug");

	printf("Following is traversal of ternary search tree\n");
	traverseTST(root);

	printf("\nFollowing are search results for cats, bu and cat respectively\n");
	searchTST(root, "cats") ? printf("Found\n") : printf("Not Found\n");
	searchTST(root, "bu") ? printf("Found\n") : printf("Not Found\n");
	searchTST(root, "cat") ? printf("Found\n") : printf("Not Found\n");

	return 0;
}