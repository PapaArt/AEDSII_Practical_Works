//  TRABALHO PRÁTICO 1          //
//  Grupo: Tree's é demais      //
//     3859 - Jhonata Miranda   //
//     3881 - Vinícius Mendes   //
//     3886 - Artur Papa        //

#include "patricia.h"

int diferenca(tipoChave k, tipoChave r)
{
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
    printf("%c\n", d);
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    p->conta[0] = 0;
    p->nt = interno;
    p->NO.NInterno.esq = *esq;
    p->NO.NInterno.dir = *dir;
    p->NO.NInterno.indice = i;
    p->NO.NInterno.desvio = d;
    printf("desvio: %c\n", d);
    return p;
}

tipoArvore
CriaNoExt(tipoChave k)
{
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoPatNo));
    //p->conta[nArquivo - 1] = 1;
    p->nt = externo;
    p->NO.chave = k;
    return p;
}

int pesquisa(tipoChave k, tipoArvore t)
{
    int qtdarquivo = 0;
    if (EExterno(t))
    {
        printf("Comp: %s %s\n", k, t->NO.chave);
        if (!strcmp(k, t->NO.chave))
        {
            printf("Elemento encontrado\n");
        }
        else
            printf("Elemento nao encontrado\n");
        return 0;
    }
    if (k[t->NO.NInterno.indice] <= t->NO.NInterno.desvio)
    {
        printf("%c %c\n", k[t->NO.NInterno.indice], t->NO.NInterno.desvio);
        pesquisa(k, t->NO.NInterno.esq);
    }
    else
    {
        printf("%c %c\n", k[t->NO.NInterno.indice], t->NO.NInterno.desvio);
        pesquisa(k, t->NO.NInterno.dir);
    }
}

tipoArvore insereEntre(tipoChave k, tipoArvore *t, int i, char d)
{
    tipoArvore p;
    int dif;
    if (EExterno(*t))
    {
        p = CriaNoExt(k);
        if (k[i] >= (*t)->NO.chave[i])
            return (CriaNoInt(i, t, &p, d));
        else
            return (CriaNoInt(i, &p, t, d));
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

tipoArvore insere(tipoChave k, tipoArvore *t)
{
    tipoArvore p;
    int i;
    char d;
    if (*t == NULL)
    {
        return (CriaNoExt(k));
    }
    else
    {
        p = *t;
        printf("p.no.chave: %s %s\n",p->NO.chave, k);
        while (!EExterno(p))
        {
            printf("%s %c\n", k, p->NO.NInterno.desvio);
            // Posicao do NInterno
            if (k[p->NO.NInterno.indice] > p->NO.NInterno.desvio)
            {
                p = p->NO.NInterno.dir;
            }
            else
            {
                p = p->NO.NInterno.esq;
            }
        }
        //printf("%s %s\n", k, p->NO.chave);
        i = strcmp(k, p->NO.chave);
        if (i == 0)
        {
            //p->conta[nArquivo - 1] += 1;
            return (*t);
        }
        else
        {
            i = diferenca(k, p->NO.chave);
            if (k[i] <= p->NO.chave[i])
                d = k[i];
            else
                d = p->NO.chave[i];
            return (insereEntre(k, t, i, d));
        }
    }
}