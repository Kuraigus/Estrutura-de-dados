// 1) utilizando como base a solucao_lista2_exercicio3.c construa as seguintes funções para uma lista duplamente ligada:
//     1 - Remover Primos
//     2 - Remover numeros iguais
//     3 - Buscar por numero
//     4 - Comparar 2 listas ( falar os numeros iguais e quais sao diferentes)
//     5 - incluir de forma ordenada

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
};

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
};

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
};

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
};

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
};

void remover(lista *l, int x)
{
    if (l->inicio == NULL)
    {
        return;
    }

    registro *aux = NULL;

    printf("\n\nENTROU NA FUNCAO DE REMOVER\n\n");

    aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        if (aux->valor == x)
        {
            if (aux->ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                aux->ant->prox = aux->prox;
            }
            l->qtd--;
            printf("\n\nREMOVEU O %d\n\n", aux->valor);
            free(aux);
            return;
        };
        aux = aux->prox;
    }
};

int checa_primo(int x)
{
    int i;

    if (x == 0)
        return 0;

    for (i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
            return 0;
    };
    return 1;
};

void procurar_remover_primos(lista *l)
{
    if (l->inicio == NULL)
        return;

    registro *aux = l->inicio;

    printf("\n\nFUNCAO DE PROCURAR PRIMOS\n\n");

    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        if (checa_primo(aux->valor))
        {
            remover(l, aux->valor);
            mostrar(l);
            if (aux->ant == NULL)
            {
                aux = l->inicio->prox;
            }
            else
            {
                aux = aux->ant->prox;
            }
        }
        else
            aux = aux->prox;
    }

    printf("\n\nFIM DA FUNCAO DE PROCURAR PRIMOS\n\n");
};

int main()
{
    lista *l;

    l = aloca_lista();

    incluir_fim(l, 7);
    incluir_fim(l, 10);
    incluir_fim(l, 11);
    incluir_fim(l, 17);
    incluir_fim(l, 30);
    incluir_fim(l, 45);

    mostrar(l);

    procurar_remover_primos(l);

    mostrar(l);

    return 0;
}