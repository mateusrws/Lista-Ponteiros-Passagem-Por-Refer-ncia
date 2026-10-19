# Exercícios de LTP I — Fundamentos de C

Bem-vindo(a)! Este repositório tem como objetivo principal ajudar os estudantes do **IFRJ (Campus Pinheiral)** com uma lista de exercícios da disciplina de **Linguagem e Técnicas de Programação I (LTP I)**, com foco especial em **ponteiros e passagem por referência**, além de funções, parâmetros, vetores, laços de repetição e operações matemáticas.

Os programas foram escritos em **C**. Cada pasta `exercicioN` contém um projeto independente; a pasta `execVetor` reúne outros pequenos programas de prática com vetores, e `CLTP` contém um exercício adicional sobre números primos.

> **Nota sobre a organização:** os fontes das pastas `exercicio4` e `exercicio5` não correspondem à numeração da lista oficial: `exercicio4/main.c` preenche um vetor (objetivo 5) e `exercicio5/main.c` calcula soma e produto (objetivo 4). As seções abaixo seguem a numeração e os objetivos oficiais, indicando onde está cada fonte.

## Sumário

- [Exercício 1 — Ordenar quatro valores](#exercício-1--ordenar-quatro-valores)
- [Exercício 2 — Trocar dois valores (swap)](#exercício-2--trocar-dois-valores-swap)
- [Exercício 3 — Simplificar uma fração](#exercício-3--simplificar-uma-fração)
- [Exercício 4 — Soma e produto dos 100 primeiros positivos](#exercício-4--soma-e-produto-dos-100-primeiros-positivos)
- [Exercício 5 — Preencher um vetor](#exercício-5--preencher-um-vetor)
- [Exercício 6 — Exibir um vetor](#exercício-6--exibir-um-vetor)
- [Exercício 7 — Exibir um vetor ao contrário](#exercício-7--exibir-um-vetor-ao-contrário)
- [Exercício 8 — Somar os valores de um vetor](#exercício-8--somar-os-valores-de-um-vetor)
- [Exercício 9 — Contar valores acima da média](#exercício-9--contar-valores-acima-da-média)
- [Exercício 10 — Somar dois vetores](#exercício-10--somar-dois-vetores)
- [Outros programas do repositório](#outros-programas-do-repositório)
- [Considerações finais](#considerações-finais)

## Exercício 1 — Ordenar quatro valores

**Objetivo:** receber quatro valores e chamar um módulo que os coloque em ordem crescente. Fonte: [`exercicio1/main.c`](./exercicio1/main.c).

**Trecho principal:**

```c
int ordenar(int *v, int N) {
    int c, temp, i, swaped;

    for (c = 0; c < N; c++) {
        swaped = 0;
        for (i = 0; i < N - c - 1; i++) {
            if (v[i] > v[i + 1]) {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swaped = 1;
            }
        }
        if (swaped == 0) {
            printf("[");
            for (c = 0; c < N; c++)
                printf(" %d ", v[c]);
            printf("]");
        }
    }
}
```

O programa lê quatro números em um vetor e chama `ordenar(vet, 4)`. O módulo compara vizinhos e troca aqueles que estão fora de ordem. É como organizar uma fila conferindo duas pessoas lado a lado e trocando-as quando a mais alta está antes da mais baixa; repetindo a conferência, os valores menores vão para o começo.

**Como executar:** no terminal, entre em `exercicio1` e compile e execute:

```sh
gcc main.c -o exercicio1
./exercicio1
```

No Windows, o executável gerado pode ser iniciado com `.\exercicio1.exe`.

> **Observação:** o módulo está declarado como `int`, mas não retorna um valor. Como ele altera o vetor e não devolve um resultado, `void` seria um tipo de retorno mais adequado.

## Exercício 2 — Trocar dois valores (swap)

**Objetivo:** criar um módulo que troque os valores de duas variáveis. Fonte: [`exercicio2/main.c`](./exercicio2/main.c).

**Trecho principal:**

```c
int swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
```

O `main` lê `a` e `b`, chama `swap(&a, &b)` e exibe os valores antes e depois. Os endereços (`&a` e `&b`) permitem ao módulo alterar as variáveis originais; o asterisco (`*`) acessa o valor guardado em cada endereço. Pense em dois copos: para trocar o conteúdo, despeje o primeiro em um copo auxiliar, passe o conteúdo do segundo para o primeiro e, por fim, coloque o conteúdo auxiliar no segundo.

**Como executar:** compile e execute dentro de `exercicio2`, usando os mesmos comandos do exercício anterior e o nome `exercicio2`.

> **Observação:** o fonte imprime os endereços das variáveis usando `%d`, especificador destinado a inteiros; essa formatação não é adequada para ponteiros. Para evitar comportamento indefinido, use `%p` e converta o endereço para `(void *)`.
>
> Assim como no exercício anterior, `swap` está declarado como `int`, mas não retorna um valor; como sua finalidade é alterar os parâmetros, `void` seria mais adequado.

## Exercício 3 — Simplificar uma fração

**Objetivo:** receber o divisor e o dividendo de uma fração e substituir ambos pelos valores simplificados. Por exemplo, `4/10` torna-se `2/5`. Fonte: [`exercicio3/main.c`](./exercicio3/main.c).

**Trecho principal:**

```c
void simplifica(int *divisor, int *dividendo) {
    int c, menor;
    if (*divisor < *dividendo)
        menor = *divisor;
    else
        menor = *dividendo;

    for (c = 1; c <= menor; c++) {
        if (*divisor % c == 0 && *dividendo % c == 0) {
            *divisor = *divisor / c;
            *dividendo = *dividendo / c;
        }
    }
}
```

O módulo procura divisores comuns e modifica os dois valores por meio de ponteiros. É parecido com dividir igualmente dois grupos de objetos pelo maior tamanho de pacote que serve para ambos. O programa mostra os valores antes e depois da chamada.

**Como executar:** compile e execute `main.c` dentro de `exercicio3` (por exemplo, `gcc main.c -o exercicio3` e `./exercicio3`).

> **Para estudar:** a busca altera os valores enquanto percorre os possíveis divisores; por isso, alguns casos podem não ser simplificados corretamente. Uma abordagem mais segura é calcular primeiro o máximo divisor comum e só depois dividir os dois valores por ele. O programa também pressupõe valores positivos diferentes de zero.

## Exercício 4 — Soma e produto dos 100 primeiros positivos

**Objetivo:** calcular a soma e o produto dos inteiros positivos de 1 a 100 e disponibilizá-los ao programa principal. O código correspondente está em [`exercicio5/main.c`](./exercicio5/main.c), apesar do nome da pasta.

**Trecho principal do módulo:**

```c
double somaproduto(int *soma, double *produto) {
    int c;
    double p = 1;

    *soma = 101 * 100 / 2;
    for (c = 100; c > 0; c--)
        p = p * c;
    *produto = p;
}
```

A soma usa a fórmula para somar uma sequência de 1 a 100; o produto multiplica os números em um laço. É como calcular o total de 100 moedas usando uma fórmula de sequência e, separadamente, multiplicar cada fator de uma receita. O valor do produto é muito grande, então o código o guarda em `double` e tenta imprimi-lo em notação científica.

**Como executar:** compile `main.c` dentro de `exercicio5` (por exemplo, `gcc main.c -o exercicio4` e `./exercicio4`).

> **Atenção:** há incompatibilidade de tipos no fonte: `somaproduto` recebe `int *soma`, mas o programa principal declara `soma` como `double`; além disso, a impressão usa `%d` para esse `double`. A função também está declarada como `double`, mas não retorna um valor. Assim, o resultado da soma não é confiável. Corrija os tipos e o retorno antes de usar o programa como uma implementação funcional do objetivo.

## Exercício 5 — Preencher um vetor

**Objetivo:** criar um módulo que receba um vetor e seu tamanho e preencha suas posições com valores informados pelo usuário. O código correspondente está em [`exercicio4/main.c`](./exercicio4/main.c).

**Trecho principal:**

```c
void vetVal(int *v, int N) {
    int c;
    for (c = 0; c < N; c++) {
        printf("Digite o %d valor: ", c + 1);
        scanf("%d", &v[c]);
    }
}
```

O vetor e o tamanho são passados ao módulo, que pergunta cada valor e o guarda na posição correspondente. Imagine preencher uma fileira de cinco caixas numeradas: a cada pergunta, uma caixa recebe o item informado.

**Como executar:** compile e execute `main.c` dentro de `exercicio4` (por exemplo, `gcc main.c -o exercicio5` e `./exercicio5`).

## Exercício 6 — Exibir um vetor

**Objetivo:** criar um módulo que mostre na tela os valores de um vetor recebido como parâmetro. Fonte: [`exercicio6/main.c`](./exercicio6/main.c).

**Trecho principal:**

```c
void mostra(int *v, int N) {
    int c;
    printf("[");
    for (c = 0; c < N; c++)
        printf(" %d ", v[c]);
    printf("]");
}
```

O `main` lê cinco valores e passa o vetor e seu tamanho para `mostra`. O módulo percorre as posições da primeira à última, como ler em voz alta os itens de uma lista na ordem em que foram anotados.

**Como executar:** compile e execute `main.c` dentro de `exercicio6` (por exemplo, `gcc main.c -o exercicio6` e `./exercicio6`).

## Exercício 7 — Exibir um vetor ao contrário

**Objetivo:** mostrar os valores de um vetor na ordem inversa àquela em que foram armazenados. Fonte: [`exercicio7/main.c`](./exercicio7/main.c).

**Trecho principal:**

```c
void mostrainverso(int *v, int N) {
    int c;
    printf("[");
    for (c = N - 1; c >= 0; c--)
        printf(" %d ", v[c]);
    printf("]");
}
```

A função começa na última posição (`N - 1`) e caminha até a primeira (`0`). É como olhar uma fila começando pela última pessoa e seguindo de trás para frente. O vetor original não é alterado; apenas a ordem de exibição muda.

**Como executar:** compile e execute `main.c` dentro de `exercicio7` (por exemplo, `gcc main.c -o exercicio7` e `./exercicio7`).

## Exercício 8 — Somar os valores de um vetor

**Objetivo:** criar uma função que retorne a soma dos valores de um vetor. Fonte: [`exercicio8/main.c`](./exercicio8/main.c).

**Trecho existente:**

```c
void soma(int *v, int N) {
    int c, soma = 0;
    for (c = 0; c < N; c++)
        soma += v[c];
    printf("Soma: %d", soma);
}
```

O acumulador começa em zero e recebe cada valor do vetor, um por vez — como somar os preços dos itens de uma cesta. O programa lê cinco valores antes de chamar o módulo.

**Como executar:** compile e execute `main.c` dentro de `exercicio8` (por exemplo, `gcc main.c -o exercicio8` e `./exercicio8`).

> **Diferença em relação ao objetivo:** o código atual imprime o resultado e tem retorno `void`; ele não retorna a soma ao programa principal. Para cumprir o objetivo integralmente, o módulo precisaria devolver um valor, por exemplo, usando `int soma(...)` e `return total;`.

## Exercício 9 — Contar valores acima da média

**Objetivo:** contar quantos valores de um vetor são maiores do que a média desse mesmo vetor. Fonte: [`exercicio9/main.c`](./exercicio9/main.c).

**Trecho principal:**

```c
void mediaQtd(int *v, int N) {
    int c, media = 0, soma = 0, qtd = 0;

    for (c = 0; c < N; c++)
        soma += v[c];
    media = soma / N;

    for (c = 0; c < N; c++)
        if (v[c] > media)
            qtd++;

    printf("Média: %d\n", media);
    printf("%d valores sao maiores que a media de todos", qtd);
}
```

Primeiro o programa soma os valores e calcula a média; depois conta os que ficam acima dela. É como encontrar a nota média da turma e contar quantas pessoas tiraram uma nota maior. O `main` preenche um vetor de cinco posições.

**Como executar:** compile e execute `main.c` dentro de `exercicio9` (por exemplo, `gcc main.c -o exercicio9` e `./exercicio9`).

> **Observação:** como `media` é um inteiro, a divisão descarta a parte decimal. Para uma média mais precisa, use um tipo real, como `double`.

## Exercício 10 — Somar dois vetores

**Objetivo:** somar, posição a posição, dois vetores de mesmo tamanho. Fonte: [`exercicio10/main.c`](./exercicio10/main.c).

**Trecho principal:**

```c
void somaVetor(int *v1, int N, int *v2) {
    int c, v[N], valor1, valor2;

    for (c = 0; c < N; c++) {
        valor1 = v1[c];
        valor2 = v2[c];
        v[c] = valor1 + valor2;
    }

    printf("Soma\n[");
    for (c = 0; c < N; c++)
        printf(" %d ", v[c]);
    printf("]");
}
```

O programa lê dois vetores de cinco elementos e soma os valores que ocupam a mesma posição. Pense em dois carrinhos de supermercado: para cada tipo de produto, some a quantidade do primeiro carrinho à quantidade do segundo.

**Como executar:** compile e execute `main.c` dentro de `exercicio10` (por exemplo, `gcc main.c -o exercicio10` e `./exercicio10`).

## Outros programas do repositório

Além dos dez exercícios oficiais, `execVetor` contém programas independentes para praticar operações e percursos de vetores:

| Pasta/arquivo | O que pratica |
|---|---|
| `calcularmodulo/calcularmodulo.c` | Soma de quadrados e cálculo da raiz para obter o módulo de um vetor. |
| `gabaritoeresposta/gaberesp.c` | Comparação de respostas com um gabarito e contagem de acertos e erros. |
| `idadealtura/idadealtura.c` | Lê cinco valores, soma seus quadrados e calcula a raiz quadrada do resultado (módulo). |
| `intbin/intbin.c` | Conversão de um inteiro para uma representação binária de 16 posições. |
| `intercalavalores/intercalavalores.c` | Intercala elementos de dois vetores em um terceiro. |
| `maiorelemento/maiorelemento.c` | Busca do maior valor de um vetor. |
| `produtovetor/produtovetor.c` | Multiplicação de valores correspondentes de dois vetores. |
| `recebemostra/recebemostra.c` | Leitura de valores e exibição dos valores pares. |
| `vetorfibonnacci/vetorfibonnaci.c` | Geração de valores da sequência de Fibonacci em um vetor. |

Também há `CLTP/main.c`, um exercício separado de verificação de primalidade. Alguns desses arquivos são rascunhos ou têm limitações (por exemplo, `intbin.c` está incompleto); eles são mantidos como material de prática e não fazem parte da lista oficial de dez exercícios.

Para compilar um desses programas, entre na pasta que contém o `.c` e use o nome do arquivo:

```sh
gcc calcularmodulo.c -o calcularmodulo
./calcularmodulo
```

No Windows, execute o arquivo gerado com `.\calcularmodulo.exe`. Se o programa usar funções matemáticas como `sqrt`, talvez seja necessário adicionar `-lm` ao comando em alguns ambientes, por exemplo: `gcc calcularmodulo.c -o calcularmodulo -lm`.

## Considerações finais

Cada exercício é uma oportunidade para praticar uma ideia de cada vez: guardar valores, percorrer listas, dividir tarefas em módulos e observar como os dados mudam. Não se preocupe se algum conceito parecer novo no início — experimente os programas, altere os valores de entrada e acompanhe o que acontece. **Programar fica mais natural a cada tentativa. Bons estudos!**
