#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int v;
    struct no *nxt;
} no;

typedef struct fila
{
    no *inicio;
    no *fim_fila;
    int tam;
} fila;

void inicializa(fila *f)
{
    f->inicio = f->fim_fila = NULL;
    f->tam = 0;
}

void insere(fila *f, int x)
{
    no *novo = (no *)malloc(sizeof(no));
    if (novo == NULL)
        return;

    novo->v = x;
    novo->nxt = NULL;

    if (f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim_fila = novo;
    }
    else
    {
        f->fim_fila->nxt = novo;
        f->fim_fila = novo;
    }
    f->tam++;
}

int deleta(fila *f)
{
    if (f->inicio == NULL)
        return -1;

    no *aux = f->inicio;
    f->inicio = f->inicio->nxt;

    if (f->inicio == NULL)
        f->fim_fila = NULL;

    int v = aux->v;
    free(aux);
    f->tam--;
    return v;
}

int frente(fila *f)
{
    if (f->inicio == NULL)
        return -1;
    return f->inicio->v;
}

int fim(fila *f)
{
    if (f->fim_fila == NULL)
        return -1;
    return f->fim_fila->v;
}

int tamanho(fila *f)
{
    return f->tam;
}

void limpa(fila *f)
{
    no *atual = f->inicio;
    no *proximo;
    while (atual != NULL)
    {
        proximo = atual->nxt;
        free(atual);
        atual = proximo;
    }
    inicializa(f);
}

void imprime(fila *f)
{
    no *atual = f->inicio;
    if (atual == NULL)
    {
        printf("\n");
        return;
    }
    while (atual != NULL)
    {
        printf("%d", atual->v);
        atual = atual->nxt;
        if (atual != NULL)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    fila f;
    inicializa(&f);
    int q;

    if (scanf("%d", &q) != 1)
        return 1;

    while (q--)
    {
        char c;
        if (scanf(" %c", &c) != 1)
            break;

        if (c == 'I')
        {
            int x;
            if (scanf("%d", &x) != 1)
                break;
            insere(&f, x);
        }
        else if (c == 'R')
        {
            printf("%d\n", deleta(&f));
        }
        else if (c == 'F')
        {
            printf("%d\n", frente(&f));
        }
        else if (c == 'B')
        {
            printf("%d\n", fim(&f));
        }
        else if (c == 'S')
        {
            printf("%d\n", tamanho(&f));
        }
        else if (c == 'C')
        {
            limpa(&f);
        }
        else if (c == 'P')
        {
            imprime(&f);
        }
    }
    limpa(&f);
    return 0;
}