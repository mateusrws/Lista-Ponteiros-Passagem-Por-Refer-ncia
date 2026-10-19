#include <stdio.h>
#include <stdlib.h>

void mediaQtd(int *v, int N);

int main()
{

    int c, v[5];

    for(c=0;c<5;c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &v[c]);
    }

    mediaQtd(v,5);

    return 0;
}

void mediaQtd(int *v, int N){
    int c, media=0, soma=0,qtd=0;

    for(c=0;c<N;c++){
        soma += v[c];
    }

    media = soma/N;

    for(c=0;c<N;c++){
        if(v[c] > media){
            qtd++;
        }
    }

    printf("Média: %d\n", media);
    printf("%d valores sao maiores que a media de todos", qtd);
}
