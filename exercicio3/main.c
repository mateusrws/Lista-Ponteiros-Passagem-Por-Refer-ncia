#include <stdio.h>
#include <stdlib.h>

void simplifica(int *divisor, int *dividendo);

int main()
{
    int divisor, dividendo;

    printf("Digite o valor do divisor: ");
    scanf("%d", &divisor);

    printf("Digite o valor do dividendo: ");
    scanf("%d", &dividendo);

    printf("\n\n\t=====ANTES=====\n");
    printf("Divisor | Endereco: %d\tValor: %d\nDividendo | Endereco: %d\tValor: %d\n", &divisor, divisor, &dividendo, dividendo);
    simplifica(&divisor, &dividendo);

    printf("\n\t=====DEPOIS=====\n");
    printf("Divisor | Endereco: %d\tValor: %d\nDividendo | Endereco: %d\tValor: %d\n\n", &divisor, divisor, &dividendo, dividendo);

    return 0;
}

void simplifica(int *divisor, int *dividendo){
    int c, menor;

    if(*divisor<*dividendo){
        menor = *divisor;
    }else{
        menor = *dividendo;
    }

    for(c=1;c<=menor;c++){
        if((*divisor%c==0) && (*dividendo%c == 0)){
            *divisor = *divisor/c;
            *dividendo = *dividendo/c;
        }
    }
}
