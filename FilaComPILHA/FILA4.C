#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int v;
    struct no *nxt;
} no;

struct fila
{
    no *inicio;
    no *fim;
    int tam;
};

void inicializa(struct fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->tam = 0;
}

void insere(struct fila *f, int x)
{
    no *novo = (no *)malloc(sizeof(no));
    if (!novo)
        exit(1);

    novo->v = x;
    novo->nxt = NULL;

    if (f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->nxt = novo;
        f->fim = novo;
    }

    f->tam++;
}

int deleta(struct fila *f)
{
    if (f->inicio == NULL)
        return -1;

    no *aux = f->inicio;
    int v = aux->v;

    f->inicio = aux->nxt;
    if (f->inicio == NULL)
        f->fim = NULL;

    free(aux);

    f->tam--;
    return v;
}

void limpa(struct fila *f)
{
    no *atual = f->inicio;
    while (atual != NULL)
    {
        no *prox = atual->nxt;
        free(atual);
        atual = prox;
    }
    inicializa(f);
}

void empilha(struct fila *f, int x)
{
    int i, v, n_rot;

    insere(f, x);
    n_rot = f->tam - 1;

    for (i = 0; i < n_rot; i++)
    {
        v = deleta(f);
        if (v != -1)
            insere(f, v);
    }
}

int desempilha(struct fila *f)
{
    return deleta(f);
}

int topo(struct fila *f)
{
    if (f->inicio == NULL)
        return -1;
    return f->inicio->v;
}

int tamanho(struct fila *f)
{
    return f->tam;
}

void limparPilha(struct fila *f)
{
    limpa(f);
}

int main()
{
    struct fila p;
    int q;

        inicializa(&p);

    if (scanf("%d", &q) != 1)
        return 1;

    while (q--)
    {
        char c;
        int x, result;

        if (scanf(" %c", &c) != 1)
            break;

        if (c == 'P')
        {
            scanf("%d", &x);
            empilha(&p, x);
        }
        else if (c == 'O')
        {
            result = desempilha(&p);
            printf("%d\n", result);
        }
        else if (c == 'T')
        {
            result = topo(&p);
            printf("%d\n", result);
        }
        else if (c == 'S')
        {
            printf("%d\n", tamanho(&p));
        }
        else if (c == 'C')
        {
            limparPilha(&p);
        }
    }

    limpa(&p);
    return 0;
}
