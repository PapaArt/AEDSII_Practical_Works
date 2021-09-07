#include "tadpat.h"

int diferenca(tipoChave k, tipoChave r)
{
    // Exemplo 'quem' e 'que'
    int count = 0;
    while (k[count] != '\0' || r[count] != '\0')
    {
        if (k[count] != r[count])
            return count;
        else count++;
    }
    return count;
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

tipoArvore 
CriaNoExt(tipoChave k)
{
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    p->nt = externo; p->NO.chave = k; return p;
}

void pesquisa(tipoChave k, tipoArvore t)
{
    if (EExterno(t))
    {
        // printf("%s\n%s\n", k, t->NO.chave);
        // printf("%d\n", strcmp(k,t->NO.chave)); 
        if (!strcmp(k,t->NO.chave))
        printf("Elemento encontrado\n");
        else printf("Elemento nao encontrado\n");
        return;
    }   
    if (k < )
    pesquisa(k, t->NO.NInterno.esq);
    else pesquisa(k, t->NO.NInterno.dir);
}

tipoArvore insereEntre(tipoChave k, tipoArvore* t, int i)
{
    tipoArvore p;
    if (EExterno(*t) || i < (*t)->NO.NInterno.indice)
    {
        p = CriaNoExt(k);
        //printf("Chave t: %s\n", (*t)->NO.chave);
        if (k[i] >= 110)
        return (CriaNoInt(i, t, &p));
        else return (CriaNoInt(i, &p, t)); 
    }
    else
    {
        if (k[(*t)->NO.NInterno.indice] >= 110)
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
            // Posicao do NInterno
            if (k[p->NO.NInterno.indice] >= 110)
            p = p->NO.NInterno.dir;
            else p = p->NO.NInterno.esq;
        }
        i = diferenca(k, p->NO.chave);
        if (i == strlen(k))
        {printf("Erro: chave ja esta na arvore\n"); return (*t);}
        else return (insereEntre(k, t, i));
        i++;
    }
}