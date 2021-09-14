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
///////////////////////////////////traverse///////////////////////////////////////
// atravessa uma árvore dada uma chave
// a função irá percorrer até a letra final da chave, onde irá
// então envie um nó para a função de preenchimento automático e imprima todos os
// subtries desse nó.

int traverse(trie_t *pTrie, char key[])
{
  int level;
  int length = strlen(key);
  int index;
  trie_node_t *temp;
  temp = pTrie->root; 
  printf("Completando a palavra... %s\n", key);
  for (level = 0; level < length; level++)
  {                                    //De 0 ao fim da chave ...
    index = alphabetIndex(key[level]); //Pegua a letra i e transforme-a em um índice.
    if (!temp->children[index])
    { //Se o índice do vetor for NULL, obviamente a palavra não foi encontrada
      printf("Palavra nao encontrada!\n");
      return 0; 
    }
    temp = temp->children[index]; //Continua avançando até o nó encontrado.
  }
  autocomplete(temp, key);
  printf("---FIM DA TST---\n");
  return (0 != temp && temp->isWord); //retorna, se "temp" não for NULL e "temp" for uma palavra
}
////////////////////////////////////autocomplete///////////////////////////////////////
// Pega um nó e imprime todas as subtries desse nó.
// Essencialmente, funciona como uma função de preenchimento automático, dada uma string "palavra",
// pode imprimir todas as palavras que têm "palavra" como prefixo.
void autocomplete(trie_node_t *subTrie, char word[])
{
  if (subTrie != NULL)
  { //Caso base: o subTrie é NULL
    int i;
    //Se subtrie for uma palavra, imprima a palavra
    if (subTrie->isWord == true)
    {
      printf("%s\n", word);
    }
    for (i = 0; i < ALPHABET_SIZE; i++)
    { // Para cada índice na matriz filhos [] ...
       // Se o array children [] tiver qualquer nó que represente letras ...
      if (subTrie->children[i] != NULL)
      {                                                      // Se esses nós não forem NULL ...
        char *append;                                        // Crie uma nova string.
        append = (char *)malloc(strlen(word) + 1);           // Alocação dinamica do array de char.
        strcpy(append, word);                                //Pegua a cadeia de letras construída atual e defina-a igual a ptr.
        append[strlen(word)] = subTrie->children[i]->letter; //Anexe a letra em children [i] ao ptr.
        autocomplete(subTrie->children[i], append);          
      }
    }
  }
}
////////////////////////////////////alphabetIndex///////////////////////////////////////
// Pega um char e retorna um índice de onde ele deve ir em uma matriz.
// Aceita A-Z, a-z, '(apóstrofo) e caracteres terminais.
int alphabetIndex(char c)
{
  int value;
  if (c >= 65 && c <= 90)
  { // Se o caractere é A-Z maiúsculo
    value = c - 65;
    return value;
  }
  else if (c >= 97 && c <= 122)
  { // Se o caractere for a-z minúsculo
    value = c - 97;
    return value + 26;
  }
  else if (c == 39)
  { // Se o caractere for um apóstrofo '
    return 52;
  }
  else
  {
    return 0;
  }
}
/////////////////////////////////////indexAlphabet//////////////////////////////////////
// pega um inteiro (índice) e o converte em um caractere
// pode aceitar valores de 1 a 53, retornando A-Z, a-z ou '
char indexAlphabet(int i)
{
  if (i >= 0 && i <= 25)
  { 
    char c = i + 65;
    return c;
  }
  if (i >= 26 && i <= 51)
  { 
    char c = i + 71;
    return c;
  }
  if (i == 52)
  { 
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
      searchForWord[0] = tolower(searchForWord[0]);
      if (searchForWord[0] > 122 || searchForWord[0] < 97)
      {
        break;
      }
      int isValid = 1;
      // percorre a palavra e verifica a validade
      printf("%c\n", searchForWord[0]);
      char c = searchForWord[0];
      if (!isalpha(c))
      {              // se for encontrado algum caractere diferente do alfa
        isValid = 0; //invalido
      }
      if (!isValid)
        printf("Invalid input! Letters only!\n");
      if (isValid)
        traverse(&pTrie, searchForWord); //palavra é valida : traverse
    }
  } while (caractere != EOF);
  fclose(arq);
}
