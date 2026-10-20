#include <stdio.h>

void somaproduto(int *soma, long double *produto);

int main(void)
{
    int soma;
    long double produto;

    somaproduto(&soma, &produto);

    printf("Soma: %d", soma);
    printf("\n\nProduto: %.5Le\n\n", produto);
    return 0;
}

void somaproduto(int *soma, long double *produto)
{
    int c;
    long double p = 1.0L;

    *soma = 101 * 100 / 2;
    for (c = 100; c > 0; c--)
        p *= c;
    *produto = p;
}
