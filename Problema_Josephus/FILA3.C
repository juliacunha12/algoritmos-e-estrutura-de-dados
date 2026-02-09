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
    f->inicio = f->fim = NULL;
    f->tam = 0;
}

void insere(struct fila *f, int x)
{
    no *novo = (no *)malloc(sizeof(no));
    if (novo == NULL)
        return;

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
    f->inicio = f->inicio->nxt;

    if (f->inicio == NULL)
        f->fim = NULL;

    int v = aux->v;
    free(aux);
    f->tam--;
    return v;
}

void limpa(struct fila *f)
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

void rotaciona(struct fila *f, int k)
{

    if (f->tam <= 1)
    {
        return;
    }

    long long n_rot = (long long)(k - 1) % f->tam;

    for (int i = 0; i < n_rot; i++)
    {

        int v = deleta(f);

        if (v != -1)
        {
            insere(f, v);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    struct fila f;
    inicializa(&f);
    int n, k;

    if (scanf("%d %d", &n, &k) != 2)
        return 1;

    for (int i = 1; i <= n; i++)
    {
        insere(&f, i);
    }

    int primeiro_eliminado = 1;

    while (f.tam > 1)
    {

        rotaciona(&f, k);

        int eliminado = deleta(&f);

        if (eliminado != -1)
        {
            if (!primeiro_eliminado)
                printf(" ");
            printf("%d", eliminado);
            primeiro_eliminado = 0;
        }
    }

    printf("\n");

    if (f.tam == 1)
    {
        printf("%d\n", deleta(&f));
    }
    else
    {
        printf("\n");
    }

    limpa(&f);

    return 0;
}