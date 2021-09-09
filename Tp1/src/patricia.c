#include "patricia.h"

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

tipoArvore CriaNoInt(int i, tipoArvore* esq, tipoArvore* dir,char d)
{
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    p->nt = interno; p->NO.NInterno.esq = *esq;
    p->NO.NInterno.dir = *dir; p->NO.NInterno.indice = i; p->NO.NInterno.desvio=d; return p;
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
        if (!strcmp(k,t->NO.chave))
        printf("Elemento encontrado\n");
        else printf("Elemento nao encontrado\n");
        return;
    } 
    if (k[t->NO.NInterno.indice] <=  t->NO.NInterno.desvio){
       pesquisa(k, t->NO.NInterno.esq);
    }
    else {
        pesquisa(k, t->NO.NInterno.dir);
    }
}

tipoArvore insereEntre(tipoChave k, tipoArvore* t, int i,char d)
{
    tipoArvore p;
    int dif;
    if (EExterno(*t))
    {
        p = CriaNoExt(k);
        if (k[i] >= (*t)->NO.chave[i])
        return (CriaNoInt(i, t, &p,d));
        else return (CriaNoInt(i, &p, t,d)); 
    }
    else
    {
        if (k[(*t)->NO.NInterno.indice] > (*t)->NO.NInterno.desvio)
        (*t)->NO.NInterno.dir = insereEntre(k, &(*t)->NO.NInterno.dir, i, d);
        else
        (*t)->NO.NInterno.esq = insereEntre(k, &(*t)->NO.NInterno.esq, i, d);
        return (*t);
    }
}

tipoArvore insere(tipoChave k, tipoArvore* t)
{
    tipoArvore p;
    int i;
    char d;
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
        if (k[i]<= p->NO.chave[i]) d = k[i];
        else d = p->NO.chave[i];
        if (i == strlen(k))
        {printf("Erro: chave ja esta na arvore\n"); return (*t);}
        else return (insereEntre(k, t, i,d));
        i++;
    }
}