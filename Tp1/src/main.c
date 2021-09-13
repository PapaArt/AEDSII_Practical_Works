#include "leituratxt.h"
#include "menu.h"

int main()
{
    //menu();
    tipoArvore teste = NULL;
    teste = insere("quem", &teste);
    teste = insere("casa", &teste);
    teste = insere("quer", &teste);
    teste = insere("porem", &teste);
    teste = insere("ninguem", &teste);
    teste = insere("tambem", &teste);
    teste = insere("apartamento", &teste);

    pesquisa("casa",teste);

    
    
    return 0;
}