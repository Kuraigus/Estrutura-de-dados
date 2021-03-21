/*
3 ) Em analogia a estrutura de lista ligada, faça um programa que insira números em uma lista duplamente ligada.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void incluir_inicio(lista *l, int x)
{
    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->inicio->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}

void incluir_fim(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->fim;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        l->fim = aux->prox;
    }
    l->qtd++;
}
void mostrar(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
        printf("Lista Vazia\n");
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

int main()
{
    lista *l;

    l = aloca_lista();

    incluir_fim(l, 10);
    incluir_fim(l, 15);
    incluir_fim(l, 20);

    incluir_inicio(l, 5);
    incluir_inicio(l, 1);

    mostrar(l);

    return 0;
}