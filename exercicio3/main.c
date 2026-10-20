#include <stdio.h>

int simplifica(int *numerador, int *denominador);

int main(void)
{
    int numerador, denominador;

    printf("Digite o numerador: ");
    if (scanf("%d", &numerador) != 1) {
        fprintf(stderr, "Entrada invalida.\n");
        return 1;
    }

    printf("Digite o denominador (diferente de zero): ");
    if (scanf("%d", &denominador) != 1 || denominador == 0) {
        fprintf(stderr, "Denominador invalido.\n");
        return 1;
    }

    printf("\n\n\t=====ANTES=====\n");
    printf("Numerador: %d\tDenominador: %d\n", numerador, denominador);
    if (!simplifica(&numerador, &denominador)) {
        fprintf(stderr, "Nao foi possivel simplificar a fracao.\n");
        return 1;
    }

    printf("\n\t=====DEPOIS=====\n");
    printf("Numerador: %d\tDenominador: %d\n\n", numerador, denominador);

    return 0;
}

int simplifica(int *numerador, int *denominador)
{
    long long a, b, resto;
    long long divisorComum;

    if (numerador == NULL || denominador == NULL || *denominador == 0)
        return 0;

    a = *numerador;
    b = *denominador;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    divisorComum = a;

    if (divisorComum == 0)
        return 0;

    *numerador /= divisorComum;
    *denominador /= divisorComum;
    return 1;
}
