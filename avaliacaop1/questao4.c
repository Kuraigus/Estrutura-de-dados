/*
Implemente um programa que possua uma função "remove_perfeitos". 
Essa função deve receber por parâmetro uma lista ligada e remover todos números perfeitos que estão dentro da lista. 
Na sua função principal leia do usuário N números e utilizando a função criada remova os números perfeito da lista de N números.
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
void remover_perfeitos(lista *l);

int main()
{
    lista *l1;
    int i, n, num;

    l1 = aloca_lista();

    printf("Informe quantos numeros voce quer inserir: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Informe 1 numero para inserir: ");
        scanf("%d", &num);

        incluir_no_final(l1, num);
    }

    mostrar_lista(l1);

    remover_perfeitos(l1);

    mostrar_lista(l1);

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

int checar_perfeito(int x)
{
    int i;
    int sum = 0;

    for (i = 1; i < x / 2; i++)
    {
        if (x % i == 0)
            sum += i;
    }
    if (sum == x)
        return 1;
    return 0;
}

void remover_perfeitos(lista *l)
{
    registro *aux;
    int num;

    aux = l->inicio;
    do
    {
        if (checar_perfeito(aux->valor))
        {
            num = aux->valor;
            if (aux->prox == NULL)
            {
                l->fim = aux->ant;
                remover_da_lista(l, aux->valor);
                aux = l->fim;
            }
            else if (aux->ant == NULL)
            {
                l->inicio = aux->prox;
                l->inicio->ant = NULL;
                aux = l->inicio;
                remover_da_lista(l, num);
            }
            else
            {
                aux->prox->ant = aux->ant;
                aux = aux->prox;
                remover_da_lista(l, num);
            }
        }
        else
            aux = aux->prox;
    } while (aux != NULL);
}
