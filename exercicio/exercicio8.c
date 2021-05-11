
/*
1 - Implemente o algoritmo Quicksort e calcule seu tempo de execução para diversos tamanhos de vetores.
Monte um gráfico demonstrando a curva de aumento de tempo em relação ao aumento de N ( tamanho do vetor.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *aloca_vetor(long long int x);
void mostrar(long long int *vet, long long int tam);
void quicksort(long long int *vetor, int long esquerda, int long direita);

int main()
{
    double t1, t2;
    srand(time(NULL));
    long long int tam;
    long long int *vet;

    FILE *arq;

    arq = fopen("tempos.csv", "w");

    if (arq == NULL)
    {
        printf("\n Problemas com arquivo");
        return 0;
    }

    for (tam = 2000000; tam <= 10000000; tam = tam + 100000)
    {
        vet = aloca_vetor(tam);
        // printf("\n Desordenado: ");
        // mostrar(vet, tam);
        t1 = omp_get_wtime();
        quicksort(vet, 0, tam - 1);
        t2 = omp_get_wtime();
        // printf("\n Ordenado: ");
        // mostrar(vet, tam);
        printf("\n  Tamanho %lld Tempo gasto: %f", tam, t2 - t1);
        fprintf(arq, "%lld;%f\n", tam, t2 - t1);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}

long long int *aloca_vetor(long long int x)
{
    long long int *vetor;
    vetor = (long long int *)calloc(x, sizeof(long long int));
    long long int i, sorteado, aux;

    for (i = 0; i < x; i++)
    {
        vetor[i] = i + 1;
    }

    for (i = 0; i < x; i++)
    {
        sorteado = rand() % x;
        aux = vetor[i];
        vetor[i] = vetor[sorteado];
        vetor[sorteado] = aux;
    }
    return vetor;
}

void mostrar(long long int *vet, long long int tam)
{
    int i;

    printf("\n Vetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void quicksort(long long int *vetor, int long esquerda, int long direita)
{
    int long i, j, pivot, aux;

    i = esquerda;
    j = direita;
    pivot = vetor[(direita + esquerda) / 2];

    while (i <= j)
    {
        while (vetor[i] < pivot && i < direita)
        {
            i++;
        }
        while (vetor[j] > pivot && j > esquerda)
        {
            j--;
        }

        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }

    if (j > esquerda)
    {
        quicksort(vetor, esquerda, j);
    }
    if (i < direita)
    {
        quicksort(vetor, i, direita);
    }
}