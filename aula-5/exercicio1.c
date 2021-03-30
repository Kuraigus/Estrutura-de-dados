/*

1) Dada uma pilha P, construir uma função que inverte a ordem dos elementos dessa pilha, utilizando apenas uma estrutura auxiliar. Deinir
adequadamente a estrutura auxiliar e prever a possibilidade da pilha
estar vazia. 

*/

#include <stdio.h>
#include <stdlib.h>

void push(int valor);
int pop();
int popstack();
int empty();
void menu();
void inverte_pilha();

int pilha[10];
int pos = 0;

int main()
{

    menu();

    return 0;
}

void push(int valor)
{
    if (pos < 10)
    {
        pilha[pos] = valor;
        pos++;
    }
    else
        printf("Pilha esta cheia! \n");
}

int pop()
{
    if (pos == 0)
    {
        printf("Pilha vazia\n");
        return -1;
    }
    else
    {
        pos--;
        return pilha[pos];
    }
}

int popstack()
{
    if (pos == 0)
    {
        printf("Pilha vazia\n");
        return -1;
    }
    else
    {
        return pilha[pos - 1];
    }
}

int empty()
{
    if (pos == 0)
        return 1;
    else
        return 0;
}

void inverte_pilha()
{
    if (!empty())
    {
        int pilha_aux[10];
        int i;

        for (i = 0; i < 10; i++)
        {
            pilha_aux[i] = pilha[pos - 1];
            pop();
        }

        for (i = 0; i < 10; i++)
        {
            push(pilha_aux[i]);
        }
    }
    else
    {
        printf("Pilha esta vazia!\n");
    }
}

void menu()
{
    int opcao = 0;
    int valor = 0;

    printf(" ------------------------------------\n");
    printf("|     1 _ Colocar numero na pilha    |\n");
    printf(" ------------------------------------\n");
    printf("|     2 _ Tirar topo da pilha        |\n");
    printf(" ------------------------------------\n");
    printf("|     3 _ Ver o topo da pilha        |\n");
    printf(" ------------------------------------\n");
    printf("|     4 _ Verificar pilha vazia      |\n");
    printf(" ------------------------------------\n");
    printf("|     5 _ Inverter pilha             |\n");
    printf(" ------------------------------------\n");
    printf("|     6 _ Sair do programa           |\n");
    printf(" ------------------------------------\n");

    do
    {
        switch (opcao)
        {
        case 1:
            printf("Informe o valor a ser colocado na pilha: ");
            scanf("%d", &valor);
            push(valor);
            break;
        case 2:
            if (!empty())
            {
                valor = pop();
                printf("Valor retirada da pilha: %d\n", valor);
            }
            else
                printf("Pilha esta vazia\n");
            break;
        case 3:
            valor = popstack();
            printf("Valor do topo da pilha: %d\n", valor);
            break;
        case 4:
            if (!empty)
                printf("Pilha nao esta vazia\n");
            else
                printf("Pilha esta vazia\n");
            break;
        case 5:
            inverte_pilha();
            break;
        default:
            break;
        }
        scanf("%d", &opcao);
    } while (opcao != 6);
}