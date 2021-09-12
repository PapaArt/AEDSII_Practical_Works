#include "tst.h"

struct Node *novoNo(char data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->fimDaPalavra = 0;
    temp->esq = temp->eq = temp->dir = NULL;
    return temp;
}

// Function to insert a new word in a Ternary Search Tree
void insert(struct Node **raiz, char *word)
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
void traverseTSTUtil(struct Node *raiz, char *buffer, int depth)
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
            printf("%s\n", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(raiz->eq, buffer, depth + 1);

        // Finally Traverse the dir subtree
        traverseTSTUtil(raiz->dir, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node *raiz)
{
    char buffer[MAX];
    traverseTSTUtil(raiz, buffer, 0);
}

// Function to search a given word in TST
int pesquisaTST(struct Node *raiz, char *word)
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
void insereDicio(char *word)
{
    struct Node *raiz = NULL;
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
            printf("%s", line);
            insert(&raiz, line);
        }
    }

    pesquisaTST(raiz, word) ? printf("\nFound\n") : printf("\nNot Found\n");
    fclose(archive);
}
