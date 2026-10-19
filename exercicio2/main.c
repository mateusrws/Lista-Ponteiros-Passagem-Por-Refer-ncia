#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b);

int main()
{
    int a, b;

    printf("Digite o valor da variavel A: ");
    scanf("%d", &a);

    printf("Digite o valor da variavel B: ");
    scanf("%d", &b);

    printf("\t=====ANTES=====\n");

    printf("A | Endereco: %d\tValor: %d\nB | Endereco: %d\tValor: %d\n", &a, a, &b, b);
    swap(&a,&b);

    printf("\t=====DEPOIS=====\n");

    printf("A | Endereco: %d\tValor: %d\nB | Endereco: %d\tValor: %d", &a, a, &b, b);
    return 0;
}

int swap(int *a, int *b){
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
