#include "compressed.h"

int main()
{
    tipoArvore teste = NULL;
    teste = insere("facebook",&teste);
    teste = insere("casa",&teste);
    // insert(teste, "face");
    // insert(teste, "book");
    // insert(teste, "pipa");
    // insert(teste, "legal");

    // printf("%d\n", search(teste, "face"));
    pesquisa("facebook",teste);
    pesquisa("casa",teste);
    // printf("%d\n", search(teste, "book"));
    // printf("%d\n", search(teste, "nada"));
    // printf("%d\n", search(teste, "legalizar"));

    return 0;
}