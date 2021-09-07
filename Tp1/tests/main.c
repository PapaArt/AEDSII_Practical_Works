#include "compressed.h"

int main()
{
    tipoArvore teste = NULL;
    teste = insere("quem",&teste);
    teste = insere("casa",&teste);
    teste = insere("ninguem",&teste);

    pesquisa("quem",teste);
    pesquisa("casa",teste);
    pesquisa("ninguem",teste);
    return 0;
}