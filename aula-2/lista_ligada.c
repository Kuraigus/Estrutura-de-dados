#include <stdlib.h>
#include <stdio.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

registro *aloca_registro();
lista *aloca_lista();
void incluir_no_final(lista *l, int x);

int main()
{
    lista *l1;

    l1 = aloca_lista();

    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
        l->inicio = novo;
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }

    l->qtd++;
}

void incluir_no_inicio(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
        l->inicio = novo;
    else
    {
        aux = l->inicio;
        novo->prox = aux->prox;
        l->inicio = novo;
    }

    l->qtd++;
}

void mostrar(lista *l)
{
    registro *aux;
    if (l->inicio == NULL)
        prinf("Lista Vazia\n");
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            prinf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }
}