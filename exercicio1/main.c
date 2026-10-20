#include <stdio.h>

void ordenar(int *v, int N);

int main(void)
{
    int vet[4], c;

    for (c = 0; c < 4; c++) {
        printf("Digite um numero: ");
        if (scanf("%d", &vet[c]) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            return 1;
        }
    }

    ordenar(vet, 4);

    printf("[");
    for (c = 0; c < 4; c++)
        printf(" %d ", vet[c]);
    printf("]\n");

    return 0;
}

void ordenar(int *v, int N)
{
    int i, j, temp, swapped;

    for (i = 0; i < N - 1; i++) {
        swapped = 0;
        for (j = 0; j < N - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}
