/*
2) Faça um programa que receba do usuário dois números N e M positivos inteiros do usuário. Aloque um vetor de N números inteiros, 
preencha os N números. Para cada um dos N números mostre a diferença em relação a M:
Ex:
    N = 5
    m = 5

    Vetor de N números:
    1, 2, 3,4,5

    Resultado:
    4, 3, 2, 1, 0;

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    int *vetor;
    int i;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    printf("Informe o numero para fazer a diferenca: ");
    scanf("%d", &m);

    vetor = (int *)malloc(sizeof(int) * n);

    printf("Informe %d numero(s) para preencher o vetor: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    printf("Resultado: \n");
    for (i = 0; i < n; i++)
    {
        if (vetor[i] > m)
            printf("%d ", vetor[i] - m);
        else
            printf("%d ", m - vetor[i]);
    }
    printf("\n");

    return 0;
}