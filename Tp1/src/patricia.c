#include "patricia.h"

int diferenca(tipoChave k, tipoChave r)
{
    // Exemplo 'quem' e 'que'
    int count = 0;
    while (k[count] != '\0' || r[count] != '\0')
    {
        if (k[count] != r[count])
            return count;
        else
            count++;
    }
    return count;
}

short EExterno(tipoArvore p)
{
    return (p->nt == externo);
}

tipoArvore CriaNoInt(int i, tipoArvore *esq, tipoArvore *dir, char d)
{
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    p->conta[0] = 0;
    p->nt = interno;
    p->NO.NInterno.esq = *esq;
    p->NO.NInterno.dir = *dir;
    p->NO.NInterno.indice = i;
    p->NO.NInterno.desvio = d;
    return p;
}

tipoArvore
CriaNoExt(tipoChave k, int nArquivo)
{
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    p->conta[nArquivo - 1] = 1;
    p->nt = externo;
    p->NO.chave = k;
    return p;
}

int pesquisa(tipoChave k, tipoArvore t, int flag)
{
    int qtdarquivo = 0;
    if (EExterno(t))
    {
        if (!strcmp(k, t->NO.chave))
        {
            // printf("Palavra e indice invertido: %s <%d,%d>\n", t->NO.chave,t->conta[0],t->conta[1]);
            // printf("Elemento encontrado\n");
            if (flag == 1)
            {
                for (int i = 0; i < 10; i++)
                {
                    if (t->conta[i] > 0)
                        qtdarquivo++;
                }
                return qtdarquivo;
            }
            //     else if(flag == 2){
            //         return
            //     }
        }
        else
            printf("Elemento nao encontrado\n");
        return 0;
    }
    if (k[t->NO.NInterno.indice] <= t->NO.NInterno.desvio)
    {
        pesquisa(k, t->NO.NInterno.esq, flag);
    }
    else
    {
        pesquisa(k, t->NO.NInterno.dir, flag);
    }
}

tipoArvore insereEntre(tipoChave k, tipoArvore *t, int i, char d, int nArquivo)
{
    tipoArvore p;
    int dif;
    if (EExterno(*t))
    {
        p = CriaNoExt(k, nArquivo);
        if (k[i] >= (*t)->NO.chave[i])
            return (CriaNoInt(i, t, &p, d));
        else
            return (CriaNoInt(i, &p, t, d));
    }
    else
    {
        if (k[(*t)->NO.NInterno.indice] > (*t)->NO.NInterno.desvio)
            (*t)->NO.NInterno.dir = insereEntre(k, &(*t)->NO.NInterno.dir, i, d, nArquivo);
        else
            (*t)->NO.NInterno.esq = insereEntre(k, &(*t)->NO.NInterno.esq, i, d, nArquivo);
        return (*t);
    }
}

tipoArvore insere(tipoChave k, tipoArvore *t, int nArquivo)
{
    tipoArvore p;
    int i;
    char d;
    if (*t == NULL)
        return (CriaNoExt(k, nArquivo));
    else
    {
        p = *t;
        while (!EExterno(p))
        {
            // Posicao do NInterno
            if (k[p->NO.NInterno.indice] > p->NO.NInterno.desvio)
                p = p->NO.NInterno.dir;
            else
                p = p->NO.NInterno.esq;
        }
        i = strcmp(k, p->NO.chave);
        if (i == 0)
        {
            p->conta[nArquivo - 1] += 1;
            return (*t);
        }
        else
        {
            i = diferenca(k, p->NO.chave);
            if (k[i] <= p->NO.chave[i])
                d = k[i];
            else
                d = p->NO.chave[i];
            return (insereEntre(k, t, i, d, nArquivo));
        }
    }
}