#include <stdio.h>
#include <stdlib.h>

void vetVal(int *v, int N);

int main()
{
    int c, vet[5];

    vetVal(vet, 5);

    printf("[");
    for(c=0;c<5;c++){
        printf(" %d ", vet[c]);
    }
    printf("]\n");

    return 0;
}

void vetVal(int *v, int N){
    int c;

    for(c=0;c<N;c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &v[c]);
    }
}
