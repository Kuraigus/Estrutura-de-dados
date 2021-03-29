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
    if (l == NULL)
    {
        printf("\n lista nao alocada");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
};

void incluir_fim(lista *l, int x)
{
    if (l == NULL)
    {
        printf("\n lista nao alocada");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
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

    aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (aux->ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            l->qtd--;

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

    printf("\nx=%d\n", x);
    for (i = 1; i <= x / 2; i++)
    {
        if (x % i == 0 && i != 1)
            return 0;
    };
    return 1;
};

void procurar_remover_primos(lista *l)
{
    if (l->inicio == NULL)
        return;

    registro *aux = l->inicio;

    while (aux != NULL)
    {
        if (checa_primo(aux->valor))
        {
            remover(l, aux->valor);
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
};

void procurar_remover_iguais(lista *l)
{
    if (l->inicio == NULL)
        return;

    registro *aux = l->inicio;

    while (aux != NULL)
    {
        if (checa_primo(aux->valor))
        {
            remover(l, aux->valor);
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
};

int main()
{
    lista *l;

    l = aloca_lista();

    incluir_fim(l, 1);
    incluir_fim(l, 3);
    incluir_fim(l, 4);
    incluir_fim(l, 2);
    incluir_fim(l, 5);
    incluir_fim(l, 6);

    mostrar(l);

    procurar_remover_primos(l);

    printf("\n");

    mostrar(l);

    return 0;
}