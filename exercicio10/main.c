#include <stdio.h>
#include <stdlib.h>

void somaVetor(int *v1, int N, int *v2);

int main()
{

    int c, v1[5], v2[5];

    // OS DOIS VETORES TEM QUE TER A MESMA QUANTIDADE DE VALORES

    for(c=0;c<5;c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &v1[c]);
    }

    printf("\nAGORA OUTRO VETOR\n\n");

    for(c=0;c<5;c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &v2[c]);
    }

    somaVetor(v1,5,v2);

    return 0;
}

void somaVetor(int *v1, int N, int *v2){
    int c, v[N], valor1, valor2;

    for(c=0;c<N;c++){
        valor1 = v1[c];
        valor2 = v2[c];
        v[c] = valor1 + valor2;
    }

    printf("Soma\n");
    printf("[");
    for(c=0;c<N;c++){
        printf(" %d ", v[c]);
    }
    printf("]");
}
