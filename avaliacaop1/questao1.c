/*
Implemente uma lista ligada de caracteres em C, ou seja, cada registro da lista deve possui apenas 1 caractere. 
Construa uma função chamada "separa_vogais_consoantes". Essa função irá receber 3 listas (lista_a, lista_b, lista_c) 
e deverá incluir na lista_b todas as vogais contidas na lista_a e incluir na lista_c todas as consoantes contidas na lista_a. 
Na sua função principal, solicite um texto ao usuário e mostre a lista de vogais e consoantes utilizando a função criada.
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
    char valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *novo_registro();
void incluir_no_final(lista *l1, char x);
void mostrar_lista(lista *l1);
int checar_vogal(char x);
int checar_consoante(char x);
void listas_consoantes_vogais(lista *la, lista *lb, lista *lc);

int main()
{
    lista *l1, *l2, *l3;
    char texto[200];
    int i = 0;

    l1 = aloca_lista();
    l2 = aloca_lista();
    l3 = aloca_lista();
    printf("%c\n\n\n", 115);

    printf("Escreva 1 texto: ");
    fgets(texto, 200, stdin);

    while (texto[i] != '\n')
    {
        incluir_no_final(l1, texto[i]);
        i++;
    }

    listas_consoantes_vogais(l1, l2, l3);

    mostrar_lista(l1);
    mostrar_lista(l2);
    mostrar_lista(l3);

    return 0;
}

lista *aloca_lista()
{
    lista *l1;

    l1 = (lista *)malloc(sizeof(lista));
    l1->inicio = NULL;
    l1->qtd = 0;
    return l1;
}

registro *novo_registro()
{
    registro *aux;

    aux = (registro *)malloc(sizeof(registro));
    aux->valor = ' ';
    aux->prox = NULL;

    return aux;
}

void incluir_no_final(lista *l1, char x)
{
    registro *aux;
    registro *novo;
    novo = novo_registro();
    novo->valor = x;

    if (l1->inicio == NULL)
    {
        l1->inicio = novo;
    }
    else
    {
        aux = l1->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
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
            printf("%c ", aux->valor);
            aux = aux->prox;
        }
    }
    printf("\n");
}

int checar_vogal(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return 1;
    return 0;
}

int checar_consoante(char x)
{
    if (x > 97 && x < 122 || x > 65 && x < 90)
        return 1;
    return 0;
}

void listas_consoantes_vogais(lista *la, lista *lb, lista *lc)
{
    registro *aux;
    if (la->inicio == NULL)
        printf("Lista vazia!\n");
    else
    {
        aux = la->inicio;
        while (aux != NULL)
        {
            if (checar_vogal(aux->valor))
                incluir_no_final(lb, aux->valor);
            else
            {
                if (checar_consoante(aux->valor))
                    incluir_no_final(lc, aux->valor);
            }
            aux = aux->prox;
        }
    }
}