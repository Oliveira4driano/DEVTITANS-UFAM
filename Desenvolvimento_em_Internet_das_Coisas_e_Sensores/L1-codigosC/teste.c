#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define retornar_failure_caso_null(expr)             \
    if ((expr) == NULL)                              \
    {                                                \
        fprintf(stderr, "Falha ao alocar memória!"); \
        return EXIT_FAILURE;                         \
    }

typedef struct no
{
    int info;
    struct no *prox;
} no;

no *cria_no(void)
{
    return NULL;
}

no *inserir(no *lst, int v)
{
    no *novo = malloc(sizeof(no));

    if (novo == NULL)
    {
        return NULL;
    }

    novo->info = v;
    novo->prox = lst;

    return novo;
}

bool comparar(no *lista1, no *lista2)
{
    no *atual1 = lista1;
    no *atual2 = lista2;

    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1->info != atual2->info)
        {
            return false;
        }

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    return atual1 == NULL && atual2 == NULL;
}

void liberar_memoria(no *lista)
{
    no *atual = lista;

    while (atual != NULL)
    {
        no *proximo = atual->prox;

        free(atual);

        atual = proximo;
    }
}

int main(void)
{
    no* lista1 = cria_no();

    retornar_failure_caso_null(lista1 = inserir(lista1, 21));
    retornar_failure_caso_null(lista1 = inserir(lista1, 45));
    retornar_failure_caso_null(lista1 = inserir(lista1, 10));

    no* lista2 = cria_no();

    retornar_failure_caso_null(lista2 = inserir(lista2, 21));
    retornar_failure_caso_null(lista2 = inserir(lista2, 45));
    retornar_failure_caso_null(lista2 = inserir(lista2, 5));

    if (comparar(lista1, lista2))
    {
        puts("São iguais");
    }
    else
    {
        puts("São diferentes");
    }

    liberar_memoria(lista1);
    liberar_memoria(lista2);

    return EXIT_SUCCESS;
}
