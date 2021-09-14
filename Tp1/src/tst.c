//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   // 
//     3886 - Artur Papa        //

#include "tst.h"
#define WORD_SIZE 25
// Cria um nó,
// define todos os elementos do sub-vetor "children" para NULL.
trie_node_t *makeNode(void)
{
  trie_node_t *node = NULL;
  node = (trie_node_t *)malloc(sizeof(trie_node_t)); //Alocação dinâmica de memória para a TST.
  if (node)
  { //Se a memória foi alocada com sucesso...
    int i;
    node->isWord = false;
    for (i = 0; i < ALPHABET_SIZE; i++)
    { //Define todos os itens do sub-vetor como NULL.
      node->children[i] = NULL;
    }
  }
  return node;
}

//Inicia um novo nó, com a raiz sendo um novo nó e a contagem sendo 0.
// Root é um nó de buffer;
// A contagem representa o nível (altura) da árvore.
void initialize(trie_t *pTrie)
{
  pTrie->root = makeNode();
  pTrie->count = 0;
}
///////////////////////////////////insert////////////////////////////////////////
// Insere cada letra de uma palavra em um teste
// Se a letra não estiver contida no teste, ele cria um novo nó.
void insert(trie_t *pTrie, char key[])
{
  int level;
  int length = strlen(key);
  int index;
  char x;
  trie_node_t *temp;  //Novo nó.
  pTrie->count++;     //Aumenta a contagem do teste, pois uma palavra está sendo adicionada.
  temp = pTrie->root; //Defina o nó temporário para a raiz pTrie, a fim de não modificar o pTrie.
  for (level = 0; level < length; level++)
  {                                    //Para cada letra da chave
    index = alphabetIndex(key[level]); //Converte essa letra em um número (índice).
    x = key[level];                    //Guarde a carta para depois.
    if (!temp->children[index])
    {                                     //Se a posiçã do vetor é uma nova letra ...
      temp->children[index] = makeNode(); //Faz um novo nó no índice.
      temp->children[index]->letter = x;  //Define a letra do nó como x.
    }
    temp = temp->children[index]; //Passa para a próxima letra / índice.
  }
  temp->isWord = true; //Marca o último nó como palavra.
}
int traverse(trie_t *pTrie, char key[])
{
  int level;
  int length = strlen(key);
  int index;
  trie_node_t *temp;
  temp = pTrie->root; 
  printf("TRAVERSING TRIE FOR %s\n", key);
  for (level = 0; level < length; level++)
  {                                    //From 0 to the end of the key...
    index = alphabetIndex(key[level]); //Take the letter at i and turn it into an index.
    if (!temp->children[index])
    { //If the child's index is NULL, then obviously the word is not found
      printf("WORD NOT FOUND!\n");
      return 0; //Thus we may exit the function.
    }
    temp = temp->children[index]; //Keep moving deeper to the found node.
  }
  /**At this point, the "temp" node should be right at the end of the "key".
  *  If we imagine "key" as a prefix (for example "ab"), then every ending of
  *  the prefix "ab" should be a subtree of the node "temp"(abalone, aback, abacus...).
  *  Thus, it is safe to assume we can print the entire subtree of "temp" because we
  *  KNOW it suffixes the key ("ab"). Thus we send "temp" into autocomplete, as well as "key".
  */
  autocomplete(temp, key);
  printf("---FIM DA TST---\n");
  return (0 != temp && temp->isWord); //returns, if "temp" is not NULL and "temp" was a word
}
////////////////////////////////////autocomplete///////////////////////////////////////
// Takes a node, and prints out all the subtries of that node.
// Essentially, it works as an autocomplete function, given a string "word",
// it can print out all the words that have "word" as a prefix.
void autocomplete(trie_node_t *subTrie, char word[])
{
  if (subTrie != NULL)
  { //Base case: the subTrie is NULL
    int i;
    //If subtrie is a word, print the word
    if (subTrie->isWord == true)
    {
      printf("%s\n", word);
    }
    for (i = 0; i < ALPHABET_SIZE; i++)
    { //For every single index in the children[] array...
      //If the children[] array has any nodes that represents letters...
      if (subTrie->children[i] != NULL)
      {                                                      //If those nodes are not NULL...
        char *append;                                        //Create a new string.
        append = (char *)malloc(strlen(word) + 1);           //DynMemAlloc for that char[] array pointer.
        strcpy(append, word);                                //Take the current built string of letters, and set it equal to the ptr.
        append[strlen(word)] = subTrie->children[i]->letter; //Append the letter at children[i] to the ptr.
        autocomplete(subTrie->children[i], append);          //Recursive Case: recurse the child at i, and the new ptr.
      }
    }
  }
}
////////////////////////////////////alphabetIndex///////////////////////////////////////
// Takes a char and returns an index of where it should go in an array.
// Accepts A-Z, a-z, ' (apostrophe), and terminal characters.
int alphabetIndex(char c)
{
  int value;
  if (c >= 65 && c <= 90)
  { //If the character is capital A-Z
    value = c - 65;
    return value;
  }
  else if (c >= 97 && c <= 122)
  { //If the character is lowercase a-z
    value = c - 97;
    return value + 26;
  }
  else if (c == 39)
  { //If the character is an apostrophe '
    return 52;
  }
  else
  {
    return 0;
  }
}
/////////////////////////////////////indexAlphabet//////////////////////////////////////
// takes an integer (index) and converts it into a character
// can accept values from 1-53, returning A-Z, a-z, or '
char indexAlphabet(int i)
{
  if (i >= 0 && i <= 25)
  { //If the character is capital A-Z
    char c = i + 65;
    return c;
  }
  if (i >= 26 && i <= 51)
  { //If the character is lowercase a-z
    char c = i + 71;
    return c;
  }
  if (i == 52)
  { //If the character is an apostrophe '
    char c = 39;
    return c;
  }
  return 0;
}

void imprimeTST(trie_t pTrie)
{
  char searchForWord[1];
  int contagem = 0;
  int caractere;
  FILE *arq = fopen("../data/alfabeto.txt", "r");
  do
  {
    caractere = fgetc(arq);
    contagem++;
    if (caractere == '\n')
    {
      contagem++;
    }
    else
    {
      searchForWord[0] = (int)(caractere);
      if (searchForWord[0] > 90 || searchForWord[0] < 65)
      {
        break;
      }
      int isValid = 1;
      //loop through word and check validity
      printf("%c\n", searchForWord[0]);
      char c = searchForWord[0];
      if (!isalpha(c))
      {              //if found any characters non-alpha
        isValid = 0; //invalid
      }
      if (!isValid)
        printf("Invalid input! Letters only!\n");
      if (isValid)
        traverse(&pTrie, searchForWord); //word is valid:traverse
    }
  } while (caractere != EOF);
  fclose(arq);
}
