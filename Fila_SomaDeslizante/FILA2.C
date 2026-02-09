#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    long long valor;
    struct no *prox;
} No;

typedef struct
{
    No *ini;
    No *fim;
    int tamanho;
    long long soma;
} Fila;

void inicializa(Fila *f)
{
    f->ini = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    f->soma = 0;
}

void insere(Fila *f, long long x)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        exit(1);

    novo->valor = x;
    novo->prox = NULL;

    if (f->fim == NULL)
    {
        f->ini = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->tamanho++;
    f->soma += x;
}

void remove_inicio(Fila *f)
{
    No *aux;
    if (f->ini == NULL)
        return;

    aux = f->ini;
    f->soma -= aux->valor;

    f->ini = aux->prox;
    if (f->ini == NULL)
        f->fim = NULL;

    free(aux);
    f->tamanho--;
}

int main()
{
    int n, k, i;
    long long x;
    Fila f;

    if (scanf("%d %d", &n, &k) != 2)
        return 0;

    inicializa(&f);

    for (i = 0; i < n; i++)
    {
        scanf("%lld", &x);

        insere(&f, x);

        if (f.tamanho > k)
            remove_inicio(&f);

        printf("%lld\n", f.soma);
    }

    return 0;
}
