//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   // 
//     3886 - Artur Papa        //

#include "patricia.h"
#define ALPHABET_SIZE (54) //26 para A-Z, 26 para a-z, 1 para apóstrofo, 1 para / 0 e outro
#define MAX 100
#include <stdlib.h>
typedef int booleano;
#define true 1
#define false 0

// Implementação do nó trie
typedef struct trie_node trie_node_t;
struct trie_node
{
        char letter;  
        bool isWord;  
        trie_node_t *children[ALPHABET_SIZE];  
};

// Struct da trie
typedef struct trie trie_t;
struct trie
{
        trie_node_t *root;  
        int count;  
};

//      Instancia um nó e seus membros.
// Os membros incluem "letter" e "isWord".
// (consulte> struct trie_node)

trie_node_t *makeNode(void);

void initialize(trie_t *pTrie);

// Insere uma chave (palavra) no Trie.

void insert(trie_t *pTrie, char key[]);
// Dada uma chave (assumindo que ela está localizada dentro do trie), o traverse irá
// localizar a ÚLTIMA letra da chave. Neste ponto, será impresso
// todas as subtries desta última letra.
int traverse(trie_t *pTrie, char key[]);
// Imprime todos os subnós / subtries de um nó.

void autocomplete(trie_node_t *subTrie, char word[]);

// Converte um caractere C em um índice. Isso é útil para localizar qual índice

int alphabetIndex(char c);

// Quando um nó é encontrado em uma matriz, o INDEX do nó na matriz
// representa a letra deste nó. Assim, este método converte um índice
// para letra / alfabeto.

char indexAlphabet(int i);
void imprimeTST(trie_t pTrie);
