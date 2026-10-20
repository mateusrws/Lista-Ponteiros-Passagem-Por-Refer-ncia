#include <stdio.h>
#include <stdlib.h>

int somaVetor(const int *v1, const int *v2, int *resultado, int N);

int main(void)
{
    int c, v1[5], v2[5];
    int resultado[5];

    for (c = 0; c < 5; c++) {
        printf("Digite o %d valor do primeiro vetor: ", c + 1);
        if (scanf("%d", &v1[c]) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            return 1;
        }
    }

    printf("\nAGORA OUTRO VETOR\n\n");

    for (c = 0; c < 5; c++) {
        printf("Digite o %d valor do segundo vetor: ", c + 1);
        if (scanf("%d", &v2[c]) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            return 1;
        }
    }

    if (!somaVetor(v1, v2, resultado, 5)) {
        fprintf(stderr, "Vetores ou tamanho invalidos.\n");
        return 1;
    }

    printf("Soma\n[");
    for (c = 0; c < 5; c++)
        printf(" %d ", resultado[c]);
    printf("]\n");

    return 0;
}

int somaVetor(const int *v1, const int *v2, int *resultado, int N)
{
    int c;

    if (v1 == NULL || v2 == NULL || resultado == NULL || N <= 0)
        return 0;

    for (c = 0; c < N; c++)
        resultado[c] = v1[c] + v2[c];

    return 1;
}
