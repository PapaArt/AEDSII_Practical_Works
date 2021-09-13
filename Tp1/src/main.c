#include "leituratxt.h"
#include "menu.h"

int main()
{
    //menu();
    tipoArvore teste = NULL;
    //leArquivo(1, 0, &teste);
    teste = insere("quem", &teste);
    teste = insere("casa", &teste);
    teste = insere("quer", &teste);
    teste = insere("porem", &teste);
    teste = insere("ninguem", &teste);
    teste = insere("tambem", &teste);
    teste = insere("apartamento", &teste);
    pesquisa("porem", teste);

    
    
    return 0;
}