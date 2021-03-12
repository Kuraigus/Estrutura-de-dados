/*
    2) Faça um programa que leia do usuário 10 números inteiros e armazene os números pares em uma lista ligada
    e os números ímpares em uma segunda lista ligada. Mostre o conteúdo das 2 listas;
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

registro *aloca_registro();
lista *aloca_lista();
void incluir_no_final(lista *l, int x);
void mostrar(lista *l);

int main()
{
    lista *pares;
    lista *impares;

    int i;
    int numero_para_incluir;

    pares = aloca_lista();
    impares = aloca_lista();

    for (i = 0; i < 10; i++)
    {
        printf("Informe o numero para colocar na lista: ");
        scanf("%d", &numero_para_incluir);

        if (numero_para_incluir % 2 == 0)
            incluir_no_final(pares, numero_para_incluir);
        else
            incluir_no_final(impares, numero_para_incluir);
    };

    printf("Lista de pares: \n");
    mostrar(pares);

    printf("Lista de impares: \n");
    mostrar(impares);

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

void mostrar(lista *l)
{
    registro *aux;
    if (l->inicio == NULL)
        printf("Lista Vazia\n");
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            printf("%d  ", aux->valor);
            aux = aux->prox;
        }
    }
    printf("\n");
}