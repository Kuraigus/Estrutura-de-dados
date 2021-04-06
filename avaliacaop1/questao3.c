/*
Implemente um programa que possua uma função de nome "inverter_listas". Essa função recebe por parâmetro 
duas listas duplamente ligadas (lista_a, lista_b) e troque os valores da lista_a pelos valores invertidos 
da lista_b e os valores da lista_b pelos valores invertidos da lista_a. 

Ex: Lista_a: 1,2,3 , Lista_b: 4,5,6. Resultado: Lista_a: 6,5,4 Lista_B: 3,2,1.

Na sua função principal leia 2 números N e M que correspondem a quantidade de elementos da lista_a e lista_b respectivamente. 
Leia N + M números, atribua-os a suas respectivas listas e utilizando a função criada, mostre seus valores invertidos.
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

lista *aloca_lista();
registro *novo_registro();
void incluir_no_final(lista *l1, int x);
void incluir_no_inicio(lista *l1, int x);
void mostrar_lista(lista *l1);
void remover_da_lista(lista *l1, int x);
void inverter_lista(lista *l);
void trocar_listas(lista *l1, lista *l2);

int main()
{
    lista *l1, *l2;
    int n, m;
    int num, i;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("Informe o tamanho da primeira lista: ");
    scanf("%d", &n);
    printf("Informe o tamanho da segunda lista: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
    {
        printf("Informe o numero para entrar na primeira lista: ");
        scanf("%d", &num);
        incluir_no_final(l1, num);
    }
    for (i = 0; i < m; i++)
    {
        printf("Informe o numero para entrar na segunda lista: ");
        scanf("%d", &num);
        incluir_no_final(l2, num);
    }

    trocar_listas(l1, l2);

    return 0;
}

lista *aloca_lista()
{
    lista *l1;

    l1 = (lista *)malloc(sizeof(lista));
    l1->inicio = NULL;
    l1->fim = NULL;
    l1->qtd = 0;
    return l1;
}

registro *novo_registro()
{
    registro *aux;

    aux = (registro *)malloc(sizeof(registro));
    aux->valor = 0;
    aux->prox = NULL;
    aux->ant = NULL;

    return aux;
}

void incluir_no_final(lista *l1, int x)
{
    registro *novo;
    novo = novo_registro();
    novo->valor = x;

    if (l1->inicio == NULL)
    {
        l1->inicio = novo;
        l1->fim = novo;
    }
    else
    {
        l1->fim->prox = novo;
        novo->ant = l1->fim;
        l1->fim = novo;
    }

    l1->qtd++;
}

void incluir_no_inicio(lista *l1, int x)
{
    registro *novo;
    novo = novo_registro();
    novo->valor = x;

    if (l1->inicio == NULL)
    {
        l1->inicio = novo;
    }
    else
    {
        l1->inicio->ant = novo;
        novo->prox = l1->inicio;
        l1->inicio = novo;
    }

    l1->qtd++;
}

void mostrar_lista(lista *l1)
{
    registro *aux;

    if (l1->inicio == NULL)
        printf("Lista vazia!\n");
    else
    {
        aux = l1->inicio;
        printf("lista: ");
        while (aux != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void remover_da_lista(lista *l1, int x)
{
    registro *aux;

    aux = l1->inicio;
    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (aux->ant == NULL)
            {
                l1->inicio = aux->prox;
            }
            else
            {
                if (aux->prox == NULL)
                {
                    aux->ant->prox = aux->prox;
                    l1->fim = aux->ant;
                }
                else
                {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                }
            }
            l1->qtd--;
            free(aux);
            return;
        }
        aux = aux->prox;
    }
    printf("\n");
}

void inverter_lista(lista *l)
{
    registro *aux;
    int num, confirm;

    aux = l->inicio;
    do
    {
        confirm = 0;
        num = aux->valor;
        if (aux->prox == NULL)
        {
            l->fim = aux->ant;
            l->fim->prox = NULL;
            aux = l->fim;
            remover_da_lista(l, num);
        }
        else if (aux->ant == NULL)
        {
            l->inicio = aux->prox;
            l->inicio->ant = NULL;
            aux = l->inicio;
            remover_da_lista(l, num);
            confirm = 1;
        }
        else
        {
            aux->prox->ant = aux->ant;
            aux = aux->prox;
            remover_da_lista(l, num);
            confirm = 1;
        }
        incluir_no_inicio(l, num);
        if (!confirm)
            aux = aux->prox;
    } while (aux != NULL);
}

void trocar_listas(lista *l1, lista *l2)
{
    lista *laux;

    laux = aloca_lista();

    inverter_lista(l1);
    inverter_lista(l2);

    *laux = *l1;
    *l1 = *l2;
    *l2 = *laux;

    mostrar_lista(l1);
    mostrar_lista(l2);
}