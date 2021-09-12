#include "tst.h"

TSTnode novoNo(char data)
{
    TSTnode temp = (TSTnode)malloc(sizeof(struct Node));
    temp->data = data;
    temp->fimDaPalavra = 0;
    temp->esq = temp->eq = temp->dir = NULL;
    return temp;
}

// Function to insert a new word in a Ternary Search Tree
void insert(TSTnode *raiz, char *word)
{
    // Base Case: Tree is empty
    if (!(*raiz))
        *raiz = novoNo(*word);

    // If current character of word is smaller than raiz's character,
    // then insert this word in left subtree of raiz
    if ((*word) < (*raiz)->data)
        insert(&((*raiz)->esq), word);

    // If current character of word is greate than raiz's character,
    // then insert this word in right subtree of raiz
    else if ((*word) > (*raiz)->data)
        insert(&((*raiz)->dir), word);

    // If current character of word is same as raiz's character,
    else
    {
        if (*(word + 1))
            insert(&((*raiz)->eq), word + 1);

        // the last character of the word
        else
            (*raiz)->fimDaPalavra = 1;
    }
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(TSTnode raiz, char *buffer, int depth)
{
    if (raiz)
    {
        // First traverse the esq subtree
        traverseTSTUtil(raiz->esq, buffer, depth);

        // Store the character of this node
        buffer[depth] = raiz->data;
        if (raiz->fimDaPalavra)
        {
            buffer[depth + 1] = '\0';
            printf("%s", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(raiz->eq, buffer, depth + 1);

        // Finally Traverse the dir subtree
        traverseTSTUtil(raiz->dir, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(TSTnode raiz)
{
    char buffer[MAX];
    traverseTSTUtil(raiz, buffer, 0);
}

// Function to search a given word in TST
int pesquisaTST(TSTnode raiz, char *word)
{
    if (!raiz)
        return 0;

    if (*word < (raiz)->data)
        return pesquisaTST(raiz->esq, word);

    else if (*word > (raiz)->data)
        return pesquisaTST(raiz->dir, word);
    else
    {
        if (*(word + 1) == '\0')
            return raiz->fimDaPalavra;

        return pesquisaTST(raiz->eq, word + 1);
    }
}

// Driver program to test above functions
void insereDicio(TSTnode *raiz, char *word, int choice)
{
    FILE *archive;
    char line[MAX];
    char *result;

    archive = fopen("../data/palavras.txt", "rt");

    if (archive != NULL)
    {
        while (!feof(archive))
        {
            result = fgets(line, MAX, archive);
            for (int k = 0; k <= strlen(line); k++)
            {
                if (ispunct(line[k]))
                {
                    line[k] = line[k + 1];
                }
                line[k] = tolower(line[k]);
            }
            //printf("%s", line);
            insert((raiz), line);
        }
    }
    if (choice == 1)
    {
        pesquisaTST((*raiz), word) ? printf("\nFound\n") : printf("\nNot Found\n");
    }

    fclose(archive);
}

void imprimeTST(TSTnode raiz)
{
    if (!raiz)
        printf("A arvore esta vazia.\n");
    if (raiz->esq != NULL)
    {
        printf("%c", raiz->data);
        // if (raiz->fimDaPalavra == 0)
        // {
        imprimeTST(raiz->esq);
        // }
    }
    if (raiz->eq != NULL)
    {
        printf("%c", raiz->data);
        // if (raiz->fimDaPalavra == 0)
        // {
        imprimeTST(raiz->eq);
        // }
    }
    if (raiz->dir != NULL)
    {
        printf("%c", raiz->data);
        // if (raiz->fimDaPalavra == 0)
        // {
        imprimeTST(raiz->dir);
        // }
    }
    else
    {
        printf("%c", raiz->data);
    }
}
bool isLastNode(TSTnode root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}

void suggestionsRec(TSTnode root, char currPrefix[])
{
    // found a string in Trie with the given prefix
	if (root->fimDaPalavra)
	{
		//printf("\n\n");
		puts(currPrefix);
		//printf("*****Match Found*****\n\n");

		//cout << currPrefix;
		//cout << endl;
	}

	// All children struct node pointers are NULL
	if (isLastNode(root))
	{
		//int len=strlen(currPrefix);
		//currPrefix[len-1]='\0';
		return;
	}
	int k = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		k = 0;
		if (root->children[i])
		{
			// append current character to currPrefix string
			//currPrefix.push_back(97 + i);
			int p = 97 + i;
			char c = (char)p;
			strncat(currPrefix, &c, 1);

			// recur over the rest
			suggestionsRec(root->children[i], currPrefix);
			int len = strlen(currPrefix);
			currPrefix[len - 1] = '\0';
		}
	}
}

int printAutoSuggestions(TSTnode root, const char query[])
{
    TSTnode pCrawl = root;

    // Check if prefix is present and find the
    // the node (of last level) with last character
    // of given string.
    int level;
    int n = strlen(query);
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);

        // no string in the Trie has this prefix
        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }

    // If prefix is present as a word.
    bool isWord = (pCrawl->fimDaPalavra == 1);

    // If prefix is last node of tree (has no
    // children)
    bool isLast = isLastNode(pCrawl);

    // If prefix is present as a word, but
    // there is no subtree below the last
    // matching node.
    if (isWord && isLast)
    {
        printf("\n \n");
        puts(query);
        printf("*****Match Found*****\n\n");
        return -1;
    }

    // If there are are nodes below last
    // matching character.
    if (!isLast)
    {
        char prefix[30];
        strcpy(prefix, query);
        printf("\n\nMatch Found With Auto Complete:-\n");
        suggestionsRec(pCrawl, prefix);
        return 1;
    }
    return 1;
}
