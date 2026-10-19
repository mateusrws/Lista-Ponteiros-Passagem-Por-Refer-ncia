#include <stdio.h>
#include <stdlib.h>

double somaproduto(int *soma, double *produto);

int main()
{
    double soma, produto;

    somaproduto(&soma, &produto);

    printf("Soma: %d", soma);
    printf("\n\nProduto: %.2e\n\n", produto); // o %.2e vai mostrar o valor em notação científica para assim poder mostrar um valor acima do teto de 32 bits e limitado a duas casas decimais
    return 0;
}

double somaproduto(int *soma, double *produto){
    int c;
    double p=1;

    *soma = 101*100/2; // Formula soma PA

    // Não da pra utilizar a formual de produto de PA pois causa estouro de limite de memoria
    //*produto = sqrt(pow(100,100)); isso é equivalente a 100^50 ~ 100!
    // Então temos que fazer pelo metodo do loop que da mais precisão

    for(c = 100; c > 0; c--){
        p = p * c;
    }
    *produto = p;

}
