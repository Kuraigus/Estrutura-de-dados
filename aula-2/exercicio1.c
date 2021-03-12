/*
1) Utilizando como base o programa lista_ligada.c, construa um programa que disponibilize ao usuario as seguintes opcoes
    a) Incluir na lista: O usuário irá informar um número que será incluído na lista
    b) Mostrar lista: deverá ser mostrado na tela a lista completa.
    c) Mostrar pares da lista: deverá ser mostrado na tela apenas os números pares    
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
void mostrar_par(lista *l);
void mostra_opcoes();

int main()
{
    lista *l1;

    int opcao = 0;
    int numero_para_lista;

    l1 = aloca_lista();

    system("clear");

    while (opcao < 4 && opcao >= 0)
    {
        switch (opcao)
        {
        case 1:
            printf("Informe o numero que voce quer incluir: ");
            scanf("%d", &numero_para_lista);
            incluir_no_final(l1, numero_para_lista);
            break;
        case 2:
            mostrar(l1);
            break;
        case 3:
            mostrar_par(l1);
            break;
        default:
            break;
        }

        mostra_opcoes();
        scanf("%d", &opcao);
    }

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
        printf("\n");
        printf("\n");
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void mostrar_par(lista *l)
{
    registro *aux;
    if (l->inicio == NULL)
        printf("Lista Vazia\n");
    else
    {
        printf("\n");
        printf("\n");
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            if (aux->valor % 2 == 0)
                printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void mostra_opcoes()
{
    printf("Informe uma das seguintes opcoes: \n");
    printf("---------------------------\n");
    printf("1_Incluir na lista         |\n");
    printf("2_Mostrar a lista completa |\n");
    printf("3_mostrar pares da lista   |\n");
    printf("4_sair do programa         |\n");
    printf("---------------------------\n");
}