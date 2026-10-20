#include <stdio.h>
#include <stdlib.h>

int soma(int *v, int N);

int main(void)
{
    int c, v[5];

    for (c = 0; c < 5; c++) {
        printf("Digite o %d valor: ", c + 1);
        if (scanf("%d", &v[c]) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            return 1;
        }
    }

    printf("Soma: %d\n", soma(v, 5));

    return 0;
}

int soma(int *v, int N)
{
    int c, total = 0;

    if (v == NULL || N < 0) {
        fprintf(stderr, "Vetor ou tamanho invalido.\n");
        return 0;
    }

    for (c = 0; c < N; c++)
        total += v[c];

    return total;
}
