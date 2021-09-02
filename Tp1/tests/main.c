#include "compressed.h"

int main()
{
    compressedNode* teste;
    
    criaNo(teste);
    insert(teste, "facebook");
    insert(teste, "face");
    insert(teste, "book");
    insert(teste, "pipa");
    insert(teste, "legal");

    printf("%d\n", search(teste, "face"));
    printf("%d\n", search(teste, "facebook"));
    printf("%d\n", search(teste, "book"));
    printf("%d\n", search(teste, "nada"));
    printf("%d\n", search(teste, "legalizar"));

    return 0;
}