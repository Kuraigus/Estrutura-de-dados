/*
Faça um programa que receba do usuário um número N inteiro positivo e aloque um vetor de cachorros.
Cada cachorro posssui: Nome, Idade, raça, cor, peso e altura.
Solicite ao usuário que preencha os dados dos N cachorros e mostre na tela:
A) Quais cachorros tem o nome iniciado pela letra M.
B) Qual o peso médio dos cachorros
C) Qual é o cachorro mais alto
D) Qual o cachorro mais velho.
E) Quantos cachorros são maiores do que 30 cm.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cachorro
{
    char nome[30];
    char raca[30];
    char cor[30];
    int idade;
    float peso;
    float altura;
} cachorro;

int main()
{
    int quantidade;
    int i;
    int mais_velho = 0;
    int mais_alto = 0;
    float media_peso = 0;
    int quantidade_maiores_que_30 = 0;

    cachorro *dados;

    printf("Informe a quantidade de cachorros: ");
    scanf("%d", &quantidade);

    while (quantidade < 0)
    {
        printf("Quantidade informada invalida. Quantidade tem que ser maior que 0. Tente novamente: ");
        scanf("%d", &quantidade);
    }

    dados = (cachorro *)malloc(sizeof(cachorro) * quantidade);

    for (i = 0; i < quantidade; i++)
    {
        printf("Informe o nome do cachorro numero %d: ", i + 1);
        scanf("%s", dados[i].nome);
        printf("Informe a raca do cachorro numero %d: ", i + 1);
        scanf("%s", dados[i].raca);
        printf("Informe a cor do cachorro numero %d: ", i + 1);
        scanf("%s", dados[i].cor);
        printf("Informe a idade do cachorro numero %d: ", i + 1);
        scanf("%d", &dados[i].idade);
        printf("Informe o peso do cachorro numero %d: ", i + 1);
        scanf("%f", &dados[i].peso);
        printf("Informe a altura do cachorro numero em cm %d: ", i + 1);
        scanf("%f", &dados[i].altura);
    }

    printf("Cachorros que comecam com a letra M: \n");
    for (i = 0; i < quantidade; i++)
    {
        if (dados[i].nome[0] == 'm' || dados[i].nome[0] == 'M')
        {
            printf("%s\n", dados[i].nome);
        }
        media_peso += dados[i].peso;
        if (dados[i].altura > mais_alto)
            mais_alto = i;
        if (dados[i].idade > mais_velho)
            mais_velho = i;
        if (dados[i].altura > 30)
            quantidade_maiores_que_30++;
    }

    media_peso /= quantidade;
    printf("O peso medio dos cachorros eh: %f\n", media_peso);
    printf("O cachorro mais alto eh o %d com nome de %s\n", mais_alto + 1, dados[mais_alto].nome);
    printf("O cachorro mais velho eh o %d com nome de %s\n", mais_velho + 1, dados[mais_velho].nome);
    printf("Quantidade de cachorros maiores que 30cm foi: %d\n", quantidade_maiores_que_30);

    return 0;
}