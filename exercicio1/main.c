#include <stdio.h>
#include <stdlib.h>

int ordenar(int *v, int N);

int main()
{
    int vet[4], c;

    for(c=0;c<4;c++){

        printf("Digite um numero: ");

        scanf("%d", &vet[c]);

    }
    ordenar(vet,4);

    return 0;
}

int ordenar(int *v, int N){
    int c, temp, i, swaped;

    for(c=0; c<N;c++){

        swaped = 0;

        for(i=0; i<N-c-1; i++){

            if(v[i] > v[i+1]){

                temp = v[i];

                v[i] = v[i+1];

                v[i+1] = temp;

                swaped = 1;
            }
        }

        if(swaped == 0){
            printf("[");
            for(c=0;c<N;c++){

                printf(" %d ", v[c]);

            }

            printf("]");
        }
    }

}
