/*
1 ) Faça um programa que receba do usuário um número N e preencha 2 listas ligadas com N números aleatórios.
    Depois de preenchida as 2 listas, remova os números em comum das 2 listas

*/

#include <stdlib.h>
#include <stdio.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

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

void mostrar_lista(lista *l)
{
    registro *aux;
    if (l->inicio == NULL)
        printf("Lista Vazia\n");
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void ordenar_lista(lista *l)
{
    registro *aux1, *aux2;
    int guarda_valor = 0;
    aux1 = l->inicio;

    while (aux1 != NULL)
    {
        aux2 = aux1->prox;
        while (aux2 != NULL)
        {
            if (aux1->valor > aux2->valor)
            {
                guarda_valor = aux1->valor;
                aux1->valor = aux2->valor;
                aux2->valor = guarda_valor;
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
}

int remover(lista *l, int x)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            l->qtd--;
            free(aux);
            return 1;
        }
        ant = aux;
        aux = aux->prox;
    }

    return 0;
}

void comparar_lista(lista *l, lista *l2)
{
    registro *aux1, *aux2;
    registro *guarda1, *guarda2;
    int qtd = 0;

    aux1 = l->inicio;
    aux2 = l2->inicio;

    while (aux1 != NULL && aux2 != NULL)
    {
        printf("\nl1:%d l2:%d\n", aux1->valor, aux2->valor);

        if (aux1->valor == aux2->valor)
        {
            guarda1 = aux1->prox;
            guarda2 = aux2->prox;
            remover(l, aux1->valor);
            remover(l2, aux2->valor);
            aux2 = guarda2;
            aux1 = guarda1;
        }
        else if (aux1->valor > aux2->valor)
            aux2 = aux2->prox;
        else
            aux1 = aux1->prox;
    }
}

int main()
{
    lista *l1, *l2;
    int i;
    int numero_para_incluir;

    l1 = aloca_lista();
    l2 = aloca_lista();

    for (i = 0; i < 5; i++)
    {
        printf("Informe o numero para colocar na lista: ");
        scanf("%d", &numero_para_incluir);
        incluir_no_final(l1, numero_para_incluir);
    };
    for (i = 0; i < 5; i++)
    {
        printf("Informe o numero para colocar na lista: ");
        scanf("%d", &numero_para_incluir);
        incluir_no_final(l2, numero_para_incluir);
    };

    ordenar_lista(l1);
    ordenar_lista(l2);

    comparar_lista(l1, l2);
    mostrar_lista(l1);
    mostrar_lista(l2);

    return 0;
}