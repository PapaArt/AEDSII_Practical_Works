#include "tadpat.h"

tipoDib bit(tipoIndexAmp i, tipoChave k)
{
    int c, j;
    if (i == 0)
    return 0;
    else
    {
        c = k;
        for (j = 0; j < 8 - i; j++) c /= 2;
        return (c & 1);
    }
}

short EExterno(tipoArvore p)
{
    return (p->nt == externo);
}

tipoArvore CriaNoInt(int i, tipoArvore* esq, tipoArvore* dir)
{
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    p->nt = interno; p->NO.NInterno.esq = *esq;
    p->NO.NInterno.dir = *dir; p->NO.NInterno.indice = i; return p;
}

tipoArvore CriaNoExt(tipoChave k)
{
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    p->nt = externo; p->NO.chave = k; return p;
}

void pesquisa(tipoChave k, tipoArvore t)
{
    if (EExterno(t))
    {
        if (k == t->NO.chave)
        printf("Elemento encontrado\n");
        else printf("Elemento nao encontrado\n");
        return;
    }
    if (bit(t->NO.NInterno.indice, k) == 0)
    pesquisa(k, t->NO.NInterno.esq);
    else pesquisa(k, t->NO.NInterno.dir);
}

tipoArvore insereEntre(tipoChave k, tipoArvore* t, int i)
{
    tipoArvore p;
    if (EExterno(*t) || i < (*t)->NO.NInterno.indice)
    {
        p = CriaNoExt(k);
        if (bit(i, k) == 1)
        return (CriaNoInt(i, t, &p));
        else return (CriaNoInt(i, &p, t)); 
    }
    else
    {
        if (bit((*t)->NO.NInterno.indice, k) == 1)
        (*t)->NO.NInterno.dir = insereEntre(k, &(*t)->NO.NInterno.dir, i);
        else
        (*t)->NO.NInterno.esq = insereEntre(k, &(*t)->NO.NInterno.esq, i);
        return (*t);
    }
}

tipoArvore insere(tipoChave k, tipoArvore* t)
{
    tipoArvore p;
    int i;
    if (*t == NULL)
    return (CriaNoExt(k));
    else
    {
        p = *t;
        while (!EExterno(p))
        {
            if (bit(p->NO.NInterno.indice, k) == 1)
            p = p->NO.NInterno.dir;
            else p = p->NO.NInterno.esq;
        }
        i = 1;
        while ((i <= 8) & (bit((int)i, k) == bit((int)i, p->NO.chave)))
            i++;
        if (i > 8)
        { printf("Erro: chave ja esta na arvore\n"); return (*t);}
        else return (insereEntre(k, t, i));
    }
}