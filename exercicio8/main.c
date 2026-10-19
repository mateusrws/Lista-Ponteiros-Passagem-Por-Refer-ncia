#include <stdio.h>
#include <stdlib.h>

void soma(int *v, int N);

int main()
{

    int c, v[5];

    for(c=0;c<5;c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &v[c]);
    }

    soma(v,5);

    return 0;
}

void soma(int *v, int N){
    int c, soma=0;

    for(c=0;c<N;c++){
        soma += v[c];
    }

    printf("Soma: %d", soma);
}
