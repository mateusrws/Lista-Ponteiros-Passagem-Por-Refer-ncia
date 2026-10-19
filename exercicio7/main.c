#include <stdio.h>
#include <stdlib.h>

void mostrainverso(int *v, int N);

int main()
{

    int c, v[5];

    for(c=0;c<5;c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &v[c]);
    }

    mostrainverso(v,5);

    return 0;
}

void mostrainverso(int *v, int N){
    int c;
    printf("[");
    for(c = N-1 ; c>=0 ; c-- ){
        printf(" %d ", v[c]);
    }
    printf("]");
}
