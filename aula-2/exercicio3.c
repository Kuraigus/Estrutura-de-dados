/*
    3) Faça um programa que leia do usuário um número N inteiro positivo e solicite ao usuário N números para serem armazenados.
        a primeira metade dos N números, deverá ser armazenada em uma lista ligada e a segunda metade dos N números deverá ser 
        armazenado em uma segunda lista.
        Mostre na tela quais valores são comuns entre as 2 listas ligadas.
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
int comparar_listas(lista *l1, lista *l2);

int main()
{
    lista *l1;
    lista *l2;

    int tamanho;
    int numero;
    int i;
    int res;
    int numero_impar;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("Informe o tamanho total: ");
    scanf("%d", &tamanho);

    if (tamanho % 2 != 0)
    {
        printf("Numero informado eh impar, o tamanho tem que aumentar 1, ou diminuir 1, o que voce deseja?\ndigite 1 para aumentar\ndigite 2 para diminuir\n");
        scanf("%d", &numero_impar);

        while (numero_impar != 1 && numero_impar != 2)
        {
            printf("Numero informado eh impar, o tamanho tem que aumentar 1, ou diminuir 1, o que voce deseja?\ndigite 1 para aumentar\ndigite 2 para diminuir\n");
            scanf("%d", &numero_impar);
        }

        switch (numero_impar)
        {
        case 1:
            tamanho++;
            break;
        case 2:
            tamanho--;
            break;
        default:
            break;
        };
    }

    for (i = tamanho / 2; i > 0; i--)
    {
        printf("Informe o numero para incluir na lista: ");
        scanf("%d", &numero);
        incluir_no_final(l1, numero);
    };

    for (i = tamanho / 2; i > 0; i--)
    {
        printf("Informe o numero para incluir na lista: ");
        scanf("%d", &numero);
        incluir_no_final(l2, numero);
    };

    res = comparar_listas(l1, l2);

    if (!res)
        printf("Nao foi encontrado nenhum numero igual entre as duas lista! \n");

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

int comparar_listas(lista *l1, lista *l2)
{
    registro *aux, *aux2;
    aux = l1->inicio;
    int ret = 0;

    while (aux != NULL)
    {
        aux2 = l2->inicio;
        while (aux2 != NULL)
        {
            if (aux->valor == aux2->valor)
            {
                printf("Valor igual encontrado: %d\n", aux->valor);
                if (ret != 1)
                    ret = 1;
            }
            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }

    return ret;
}