#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int a, b;

    printf("Digite o valor da variavel A: ");
    if (scanf("%d", &a) != 1) {
        fprintf(stderr, "Entrada invalida.\n");
        return 1;
    }

    printf("Digite o valor da variavel B: ");
    if (scanf("%d", &b) != 1) {
        fprintf(stderr, "Entrada invalida.\n");
        return 1;
    }

    printf("\t=====ANTES=====\n");

    printf("A | Endereco: %p\tValor: %d\nB | Endereco: %p\tValor: %d\n",
           (void *)&a, a, (void *)&b, b);
    swap(&a, &b);

    printf("\t=====DEPOIS=====\n");

    printf("A | Endereco: %p\tValor: %d\nB | Endereco: %p\tValor: %d\n",
           (void *)&a, a, (void *)&b, b);
    return 0;
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
