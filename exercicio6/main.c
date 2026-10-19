#include <stdio.h>
#include <stdlib.h>

void mostra(int *v, int N);

int main()
{

    int c, v[5];

    for(c=0;c<5;c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &v[c]);
    }

    mostra(v,5);

    return 0;
}

void mostra(int *v, int N){
    int c;
    printf("[");
    for(c=0;c<N;c++){
        printf(" %d ", v[c]);
    }
    printf("]");
}
