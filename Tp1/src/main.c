#include "leituratxt.h"

int main()
{
    char str[MAX];
    char *mat[MAX];
    char *plv;
    tipoArvore teste = NULL;

    learqv(str);
    for (int k = 0; k <= strlen(str); k++)
    {
        if (ispunct(str[k]))
        {
            str[k] = str[k + 1];
        }
    }
    plv = strtok(str, " ");
    while (plv != NULL)
    {
        plv[0] = tolower(plv[0]);
        teste = insere(plv, &teste);
        plv = strtok(NULL, " ");
    }

    // teste = insere("quem", &teste);
    // teste = insere("casa", &teste);
    // teste = insere("quer", &teste);
    // teste = insere("porem", &teste);
    // teste = insere("ninguem", &teste);
    // teste = insere("tambem", &teste);
    // teste = insere("apartamento", &teste);

    pesquisa("quem", teste);
    pesquisa("casa", teste);
    pesquisa("quer", teste);
    pesquisa("porem", teste);
    pesquisa("ninguem", teste);
    pesquisa("tambem", teste);
    pesquisa("apartamento", teste);
    return 0;
}