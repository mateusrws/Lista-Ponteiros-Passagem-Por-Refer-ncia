#include <stdio.h>
#include <stdlib.h>

int mediaQtd(int *v, int N, double *media);

int main(void)
{
    int c, v[5];
    int quantidade;
    double media;

    for (c = 0; c < 5; c++) {
        printf("Digite o %d valor: ", c + 1);
        if (scanf("%d", &v[c]) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            return 1;
        }
    }

    quantidade = mediaQtd(v, 5, &media);
    if (quantidade < 0) {
        fprintf(stderr, "Vetor ou tamanho invalido.\n");
        return 1;
    }

    printf("Media: %.2f\n", media);
    printf("%d valores sao maiores que a media.\n", quantidade);

    return 0;
}

int mediaQtd(int *v, int N, double *media)
{
    int c, quantidade = 0;
    long long soma = 0;

    if (v == NULL || media == NULL || N <= 0)
        return -1;

    for (c = 0; c < N; c++)
        soma += v[c];

    *media = (double)soma / N;

    for (c = 0; c < N; c++)
        if (v[c] > *media)
            quantidade++;

    return quantidade;
}
