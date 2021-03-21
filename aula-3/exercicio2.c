/* 
2 ) Faça um programa que leia do usuário um número N positivo e construa uma lista ligada de alunos. Cada aluno possui
    nome, matricula e media final. Disponibilize ao usuários as seguintes opções:
    a) Inserir aluno na lista
    b) Mostrar alunos aprovados
    c) Mostrar alunos reprovados
    d) Remover aluno da lista.
    Obs. É considerado um aluno aprovado aquele que conter média final >=5.0;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    char nome[30];
    int matricula;
    float media_final;
    struct registro *prox;
} registro;

void menu_opcoes()
{
    printf("Informe uma das seguintes opcoes: \n");
    printf(" ------------------------------\n");
    printf("|   1_Inserir aluno na lista   |\n");
    printf("|   2_Mostrar aprovados        |\n");
    printf("|   3_Mostrar reprovados       |\n");
    printf("|   4_Remover Aluno            |\n");
    printf("|   5_sair do programa         |\n");
    printf(" ------------------------------\n");
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
    strcpy(novo->nome, " ");
    novo->matricula = 0;
    novo->media_final = 0;
    novo->prox = NULL;
    return novo;
}

void incluir_no_final(lista *l, char *nome, int matricula, float media_final)
{
    registro *novo, *aux;
    novo = aloca_registro();
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->media_final = media_final;

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

void mostrar_aprovados(lista *l)
{
    registro *aux;

    int qtd = 0;

    printf("\n");
    if (l->inicio == NULL)
        printf("Lista Vazia\n");
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->media_final >= 5)
            {
                printf("Nome: %s\n", aux->nome);
                printf("Matricula: %d\n", aux->matricula);
                printf("Media Final: %.2f\n", aux->media_final);
                printf("------------------------------------\n");
                qtd++;
            }
            aux = aux->prox;
        }
    }
    if (qtd == 0)
        printf("Nenhuma aluno Aprovado!");
    printf("\n");
}

void mostrar_reprovados(lista *l)
{
    registro *aux;

    int qtd = 0;

    printf("\n");
    if (l->inicio == NULL)
        printf("Lista Vazia\n");
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->media_final < 5)
            {
                printf("Nome: %s\n", aux->nome);
                printf("Matricula: %d\n", aux->matricula);
                printf("Media Final: %.2f\n", aux->media_final);
                printf("------------------------------------\n");
                qtd++;
            }
            aux = aux->prox;
        }
    }
    if (qtd == 0)
        printf("Nenhuma aluno Reprovado!");
    printf("\n");
}

int remover(lista *l, int matricula)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {

        if (aux->matricula == matricula)
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

int main()
{
    lista *l1;
    int opcao = 0;
    int matricula;
    char nome[30];
    float media;

    l1 = aloca_lista();

    while (opcao < 5 && opcao >= 0)
    {
        switch (opcao)
        {
        case 1:
            printf("Informe o nome do aluno: ");
            __fpurge(stdin);
            fgets(nome, 30, stdin);
            printf("Informe a matricula final do aluno: ");
            scanf("%d", &matricula);
            printf("Informe a media final do aluno: ");
            scanf("%f", &media);
            incluir_no_final(l1, nome, matricula, media);
            break;
        case 2:
            mostrar_aprovados(l1);
            break;
        case 3:
            mostrar_reprovados(l1);
            break;
        case 4:
            printf("Informe a matricula do aluno que vai ser removido: ");
            scanf("%d", &matricula);
            remover(l1, matricula);
            printf("\nAluno removido!\n");
            break;
        default:
            break;
        }

        menu_opcoes();
        scanf("%d", &opcao);
    }

    return 0;
}