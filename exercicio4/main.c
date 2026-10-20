#include <stdio.h>
#include <stdlib.h>

int vetVal(int *v, int N);

int main(void)
{
    int c, vet[5];

    if (!vetVal(vet, 5))
        return 1;

    printf("[");
    for (c = 0; c < 5; c++) {
        printf(" %d ", vet[c]);
    }
    printf("]\n");

    return 0;
}

int vetVal(int *v, int N)
{
    int c;

    if (v == NULL || N <= 0) {
        fprintf(stderr, "Vetor ou tamanho invalido.\n");
        return 0;
    }

    for (c = 0; c < N; c++) {
        printf("Digite o %d valor: ", c + 1);
        if (scanf("%d", &v[c]) != 1) {
            fprintf(stderr, "Entrada invalida; informe um numero inteiro.\n");
            return 0;
        }
    }

    return 1;
}
