#include <stdio.h>
#include <stdlib.h>

void mostra(int *v, int N);

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

    mostra(v, 5);

    return 0;
}

void mostra(int *v, int N)
{
    int c;

    if (v == NULL || N < 0) {
        fprintf(stderr, "Vetor ou tamanho invalido.\n");
        return;
    }

    printf("[");
    for (c = 0; c < N; c++) {
        printf(" %d ", v[c]);
    }
    printf("]");
}
