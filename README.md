<div align="center">

# 📘 Exercícios de LTP I — Fundamentos de C

**Linguagem e Técnicas de Programação I · IFRJ — Campus Pinheiral**

![Linguagem](https://img.shields.io/badge/linguagem-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Exercícios](https://img.shields.io/badge/exerc%C3%ADcios-10-success?style=for-the-badge)
![Nível](https://img.shields.io/badge/n%C3%ADvel-iniciante-blue?style=for-the-badge)

</div>

---

## 👋 Bem-vindo(a)!

Este repositório reúne exercícios da disciplina de **Linguagem e Técnicas de Programação I (LTP I)**, do **IFRJ — Campus Pinheiral**. O objetivo é ajudar estudantes iniciantes a compreender os fundamentos da linguagem C por meio de exemplos práticos, explicações detalhadas e analogias com situações do cotidiano.

Os exercícios trabalham principalmente com:

- Variáveis e tipos de dados
- Funções e passagem de parâmetros
- Ponteiros e passagem por referência
- Vetores e posições de memória
- Laços de repetição
- Condicionais e operadores matemáticos
- Organização e manipulação de dados

> A proposta não é apenas mostrar códigos que funcionam, mas ajudar você a **entender o raciocínio por trás de cada instrução**.

---

## 🧭 Como aproveitar este material

Leia cada exercício nesta ordem:

| Etapa | Seção | O que fazer |
| :---: | :--- | :--- |
| 1 | **Objetivo** | Entenda o problema que o programa precisa resolver. |
| 2 | **Conceitos necessários** | Conheça as ferramentas da linguagem utilizadas. |
| 3 | **Código atualizado** | Observe a implementação corrigida presente no repositório. |
| 4 | **Explicação linha a linha** | Entenda o papel de cada instrução. |
| 5 | **Analogia cotidiana** | Relacione o código a uma situação familiar. |
| 6 | **Atenção** | Confira as validações e os limites que continuam dependendo de quem chama a função. |

> [!IMPORTANT]
> Os trechos de código deste README acompanham as correções aplicadas aos arquivos-fonte. As seções **Atenção** destacam os cuidados que ainda cabem a quem utiliza as funções, como informar corretamente o tamanho real de um vetor.

---

## 🗂️ Organização do repositório

Os dez exercícios oficiais estão distribuídos em pastas independentes.

| Exercício oficial | Objetivo | Arquivo |
| :---: | :--- | :--- |
| [1](#exercício-1--ordenar-quatro-valores) | Ordenar quatro valores | `exercicio1/main.c` |
| [2](#exercício-2--trocar-dois-valores-swap) | Trocar dois valores | `exercicio2/main.c` |
| [3](#exercício-3--simplificar-uma-fração) | Simplificar uma fração | `exercicio3/main.c` |
| [4](#exercício-4--soma-e-produto-dos-100-primeiros-positivos) | Calcular a soma e o produto dos números de 1 a 100 | `exercicio5/main.c` |
| [5](#exercício-5--preencher-um-vetor) | Preencher um vetor | `exercicio4/main.c` |
| [6](#exercício-6--exibir-um-vetor) | Exibir um vetor | `exercicio6/main.c` |
| [7](#exercício-7--exibir-um-vetor-ao-contrário) | Exibir um vetor ao contrário | `exercicio7/main.c` |
| [8](#exercício-8--somar-os-valores-de-um-vetor) | Somar os valores de um vetor | `exercicio8/main.c` |
| [9](#exercício-9--contar-valores-acima-da-média) | Contar os valores acima da média | `exercicio9/main.c` |
| [10](#exercício-10--somar-dois-vetores) | Somar dois vetores | `exercicio10/main.c` |

Além dessas pastas, `execVetor` contém pequenos programas de prática, e `CLTP` contém um exercício adicional sobre números primos.

---

## Exercício 1 — Ordenar quatro valores

📄 **Arquivo:** `exercicio1/main.c`

### 1. Qual é o objetivo?

O programa recebe quatro números e organiza esses valores em **ordem crescente**, ou seja, do menor para o maior.

Imagine que quatro pessoas estejam em uma fila, mas estejam fora de ordem de altura. Você quer reorganizá-las para que a pessoa mais baixa fique no começo e a mais alta no final.

Uma maneira de fazer isso é comparar pessoas vizinhas e trocar suas posições quando necessário. O algoritmo utilizado neste exercício segue justamente essa ideia.

### 2. Conceitos necessários

- **Vetor:** conjunto de posições que armazenam valores.
- **Função:** bloco de código que realiza uma tarefa específica.
- **Ponteiro:** variável que permite trabalhar com um endereço de memória.
- **Laços `for`:** estruturas que repetem instruções.
- **Condicional `if`:** executa um bloco somente quando uma condição é verdadeira.
- **Variável temporária:** espaço utilizado para guardar provisoriamente um valor durante uma troca.

### 3. Código atualizado

```c
void ordenar(int *v, int N) {
    int i, j, temp, swapped;

    for (i = 0; i < N - 1; i++) {
        swapped = 0;
        for (j = 0; j < N - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}
```

### 4. Explicação linha a linha

**Linha 1 — `void ordenar(int *v, int N)`**

Declara uma função chamada `ordenar`.

- `void` indica que a função não retorna um valor.
- `ordenar` é o nome da função.
- `int *v` recebe o endereço de um vetor de inteiros.
- `int N` recebe a quantidade de elementos que devem ser considerados.

O asterisco em `int *v` indica que `v` é um **ponteiro para inteiros**. Isso permite que a função trabalhe diretamente com os elementos do vetor recebido.

**Linha 2 — `int i, j, temp, swapped;`**

Declara os contadores dos laços, a variável temporária usada na troca e a marcação que indica se houve alguma troca.

**Linha 4 — `for (i = 0; i < N - 1; i++)`**

Controla as passagens pelo vetor. A cada passagem, o maior valor ainda não colocado em sua posição final avança para o fim.

**Linha 5 — `swapped = 0;`**

Começa cada passagem supondo que os elementos já estejam ordenados. Se alguma troca ocorrer, o programa altera essa marcação.

**Linha 6 — `for (j = 0; j < N - i - 1; j++)`**

Percorre os pares vizinhos. O limite diminui porque os maiores valores já foram colocados no final.

**Linha 7 — `if (v[j] > v[j + 1])`**

Compara dois elementos vizinhos. Se o da esquerda for maior, eles estão fora da ordem crescente.

**Linhas 8 a 11 — troca dos elementos**

`temp` guarda `v[j]` antes de substituí-lo por `v[j + 1]`; em seguida, o valor temporário vai para a posição seguinte. `swapped = 1` registra que a passagem precisou corrigir a ordem.

**Linhas 14 e 15 — encerramento antecipado**

Se nenhuma troca foi feita, `!swapped` é verdadeiro e `break` encerra o laço: o vetor já está ordenado.

Depois que `ordenar` termina, `main` percorre o vetor e o imprime uma vez. Assim, exibição e ordenação ficam em etapas separadas.

### 5. Entendendo os laços na prática

Existem dois níveis de repetição:

- **Laço externo:** organiza as passagens pelo vetor.
- **Laço interno:** compara os vizinhos e realiza as trocas necessárias.

Imagine organizar quatro pessoas por altura. Você compara a primeira com a segunda, depois a segunda com a terceira e assim por diante. Ao terminar uma passagem, o maior valor comparado fica no final. Você repete o processo até que nenhuma troca seja necessária.

Por exemplo, considere o vetor:

```text
[8, 3, 6, 2]
```

Na primeira passagem:

1. Compara `8` com `3`: troca.
2. Compara `8` com `6`: troca.
3. Compara `8` com `2`: troca.

O resultado da primeira passagem é:

```text
[3, 6, 2, 8]
```

O maior número chegou ao final. As passagens seguintes continuam organizando os elementos restantes.

### 6. 🧃 Analogia cotidiana: organizar uma fila

Imagine que você seja responsável por organizar uma fila de pessoas da mais baixa para a mais alta. Em vez de retirar todas as pessoas da fila e reorganizá-las de uma vez, você olha duas pessoas vizinhas.

Se a pessoa da esquerda for mais alta do que a da direita, você pede que elas troquem de lugar. Ao percorrer a fila várias vezes, as pessoas vão ficando progressivamente mais organizadas.

O algoritmo faz exatamente isso, mas compara números em vez de pessoas.

### 7. Atenção

> [!TIP]
> A função agora retorna `void`, usa contadores independentes e encerra a ordenação quando uma passagem não realiza trocas. A impressão acontece uma única vez no programa principal, depois da ordenação. O tamanho `N` ainda deve corresponder à quantidade real de elementos do vetor.

---

## Exercício 2 — Trocar dois valores (swap)

📄 **Arquivo:** `exercicio2/main.c`

### 1. Qual é o objetivo?

O programa recebe dois valores e troca seus conteúdos por meio de uma função.

Imagine dois copos: um contém suco de laranja e o outro contém água. Você quer que cada copo termine com o líquido que estava originalmente no outro.

Para trocar os conteúdos sem perder nenhum deles, você pode usar um **terceiro copo vazio** como recipiente temporário. É a mesma ideia utilizada para trocar os valores de duas variáveis.

### 2. Conceitos necessários

- Ponteiros.
- Operador `&`, utilizado para obter um endereço.
- Operador `*`, utilizado para acessar o valor apontado.
- Variável temporária.
- Funções e passagem por referência.

#### Entendendo `&` e `*`

Considere uma variável chamada `a` que armazena o número `10`.

- `a` representa o valor `10`.
- `&a` representa o **endereço de memória** onde `a` está armazenada.
- Se um ponteiro apontar para `a`, `*ponteiro` acessa o **valor** guardado nesse endereço.

Pense em uma casa: o número escrito na placa corresponde ao endereço, enquanto os objetos dentro da casa correspondem ao conteúdo armazenado.

### 3. Código atualizado

```c
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
```

### 4. Explicação linha a linha

**Linha 1 — `void swap(int *a, int *b)`**

Declara a função `swap`, que recebe dois ponteiros para inteiros. Os parâmetros `a` e `b` permitem que a função acesse as variáveis originais por meio de seus endereços.

**Linha 2 — `int tmp;`**

Cria uma variável temporária chamada `tmp`, que guardará um dos valores durante a troca.

**Linha 3 — `tmp = *a;`**

Lê o valor armazenado no endereço apontado por `a` e o copia para `tmp`. O asterisco indica que queremos o conteúdo do endereço, e não o próprio endereço.

**Linha 4 — `*a = *b;`**

Copia o valor apontado por `b` para a variável original apontada por `a`.

**Linha 5 — `*b = tmp;`**

Coloca em `b` o valor que estava originalmente em `a` e que foi preservado em `tmp`. A troca está concluída.

### 5. 🧃 Analogia cotidiana: trocar o conteúdo de dois copos

Imagine que o copo A contém suco e o copo B contém água.

1. Você transfere o suco do copo A para um copo auxiliar.
2. Passa a água do copo B para o copo A.
3. Transfere o suco do copo auxiliar para o copo B.

A variável `tmp` funciona como o copo auxiliar. Sem ela, o primeiro conteúdo poderia ser sobrescrito antes de ser transferido para o outro copo.

#### Exemplo de execução

Considere que `a = 10` e `b = 20`.

| Instrução | `a` | `b` | `tmp` |
| :--- | :---: | :---: | :---: |
| Estado inicial | 10 | 20 | — |
| `tmp = *a` | 10 | 20 | 10 |
| `*a = *b` | 20 | 20 | 10 |
| `*b = tmp` | 20 | 10 | 10 |

No final, os valores foram trocados.

### 6. Atenção

> [!TIP]
> A função agora tem retorno `void`, e o programa imprime endereços com `%p` e argumentos convertidos para `(void *)`. Como em qualquer função que recebe ponteiros, quem a chama deve passar endereços válidos de variáveis inteiras; o programa principal já faz isso passando `&a` e `&b`.

---

## Exercício 3 — Simplificar uma fração

📄 **Arquivo:** `exercicio3/main.c`

### 1. Qual é o objetivo?

O programa recebe o numerador e o denominador de uma fração e tenta simplificá-la, dividindo os dois valores por divisores comuns.

Por exemplo:

A simplificação resulta em ```4/10 = 2/5```
.

As duas frações representam a mesma quantidade, mas a segunda utiliza números menores.

### 2. Conceitos necessários

- Ponteiros.
- Operadores relacionais.
- Operador módulo `%`.
- Laço `for`.
- Condições com `&&`.
- Divisão inteira.

O operador `%` calcula o **resto** de uma divisão inteira. Por exemplo:

- `10 % 2` resulta em `0`, pois 10 é divisível por 2.
- `10 % 3` resulta em `1`, pois sobra 1.

Quando o resto é zero, o número é divisível pelo divisor testado.

### 3. Código atualizado

```c
int simplifica(int *numerador, int *denominador) {
    long long a, b, resto;

    if (numerador == NULL || denominador == NULL || *denominador == 0)
        return 0;

    a = *numerador;
    b = *denominador;
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    if (a == 0)
        return 0;
    *numerador /= a;
    *denominador /= a;
    return 1;
}
```

### 4. Explicação linha a linha

**Linha 1 — `int simplifica(int *numerador, int *denominador)`**

Declara uma função que modifica numerador e denominador por meio de ponteiros. Retorna `1` quando simplifica a fração e `0` para ponteiros inválidos ou denominador zero.

Os parâmetros agora usam os nomes usuais para os termos da fração: numerador e denominador.

**Linhas 2 a 4 — validação dos argumentos**

A função verifica se os ponteiros existem e se o denominador é diferente de zero. Se algum desses requisitos falhar, retorna `0` sem tentar dividir.

**Linhas 6 a 9 — preparação dos valores**

Os termos são copiados para variáveis `long long` temporárias. Isso permite obter o valor absoluto mesmo quando o termo de entrada é o menor inteiro representável.

**Linhas 11 a 15 — algoritmo de Euclides**

O laço usa o resto da divisão para encontrar o máximo divisor comum. A cada repetição, o segundo valor passa a ser o resto; quando o resto chega a zero, o outro valor é o divisor comum.

**Linhas 17 a 21 — simplificação**

A função divide numerador e denominador pelo divisor comum, altera as variáveis originais por meio dos ponteiros e retorna `1` para indicar sucesso.

### 5. 🧃 Analogia cotidiana: dividir duas coleções em grupos iguais

Imagine que você tenha 12 lápis e 18 cadernos e queira dividir ambos igualmente entre algumas pessoas, sem sobrar nenhum item.

Você procura um número que divida as duas quantidades. Por exemplo, 3 divide 12 e 18. Assim, pode dividir os lápis e os cadernos em três grupos iguais.

A simplificação de uma fração segue um raciocínio parecido: os dois valores são divididos pelo mesmo número, preservando a proporção.

### 6. Atenção

> [!TIP]
> O algoritmo de Euclides agora calcula primeiro o máximo divisor comum e só então altera os termos, evitando que a busca mude os valores usados nos cálculos. O programa aceita numeradores negativos e rejeita denominador zero. Quem chama `simplifica` deve garantir ponteiros válidos.

---

## Exercício 4 — Soma e produto dos 100 primeiros positivos

📄 **Arquivo:** `exercicio5/main.c`

> [!NOTE]
> **Atenção à organização:** embora este seja o exercício oficial número **4**, seu código está na pasta `exercicio5`.

### 1. Qual é o objetivo?

Calcular duas coisas:

- A **soma** dos números inteiros de 1 a 100.
- O **produto** dos mesmos números, isto é, $1 \times 2 \times 3 \times \cdots \times 100$.

O resultado da soma é:

$$
1 + 2 + \cdots + 100 = 5050
$$

O produto é conhecido como $100!$, ou **fatorial de 100**. É um número extremamente grande.

### 2. Conceitos necessários

- Funções.
- Ponteiros.
- Fórmula da soma de uma sequência.
- Laço `for`.
- Multiplicação acumulada.
- Tipos `int` e `long double`.

O tipo `int` é usado para a soma inteira. `long double` representa o produto em ponto flutuante, com grande faixa de magnitude e precisão finita.

### 3. Código atualizado

```c
void somaproduto(int *soma, long double *produto) {
    int c;
    long double p = 1.0L;

    *soma = 101 * 100 / 2;
    for (c = 100; c > 0; c--)
        p *= c;
    *produto = p;
}
```

### 4. Explicação linha a linha

**Linha 1 — `void somaproduto(int *soma, long double *produto)`**

Declara a função `somaproduto`.

- `void` indica que os resultados são entregues pelos parâmetros.
- `int *soma` recebe um ponteiro para inteiro.
- `long double *produto` recebe um ponteiro para o produto.

A função utiliza os ponteiros para disponibilizar os resultados nas variáveis recebidas.

**Linha 2 — `int c;`**

Declara o contador utilizado para percorrer os números de 100 até 1.

**Linha 3 — `long double p = 1.0L;`**

Cria o acumulador `p`, inicializado com `1`. Esse valor inicial é importante porque multiplicar qualquer número por zero resultaria em zero, destruindo o resultado do produto.

**Linha 5 — `*soma = 101 * 100 / 2;`**

Calcula a soma de 1 até 100 usando a fórmula:

$$
S = \frac{n(n+1)}{2}
$$

Para $n = 100$:

$$
S = \frac{100 \times 101}{2} = 5050
$$

O resultado é atribuído ao endereço apontado por `soma`.

**Linha 6 — `for (c = 100; c > 0; c--)`**

Como no [exercício 1](#exercício-1--ordenar-quatro-valores), o `for` controla as repetições. Neste caso, começa em `100` e continua enquanto `c > 0`.

O operador `c--` diminui o contador em uma unidade ao final de cada repetição. Assim, a sequência percorrida é 100, 99, 98, e assim por diante, até 1.

**Linha 7 — `p = p * c;`**

Multiplica o acumulador pelo valor atual de `c` e guarda o resultado em `p`. Cada repetição incorpora um novo fator ao produto.

**Linha 8 — `*produto = p;`**

Copia o produto calculado para a variável original apontada por `produto`.

### 5. 🧃 Analogia cotidiana: somar uma pilha de moedas e multiplicar fatores

Imagine que você tenha uma pilha com moedas numeradas de 1 a 100 e queira saber a soma de todos os valores. Em vez de somar uma por uma, pode usar uma fórmula matemática que chega ao mesmo resultado.

Para o produto, porém, você precisa multiplicar cada fator. O acumulador `p` funciona como uma calculadora que mantém o resultado parcial e o atualiza a cada etapa.

### 6. Atenção

> [!TIP]
> Os tipos agora correspondem entre a função e o programa principal: a soma é `int`, o produto é `long double`, o retorno da função é `void` e o produto é exibido com `%Le`. O produto de 1 a 100 é aproximado em ponto flutuante: sua magnitude pode ser representada, mas não todos os seus dígitos com exatidão.

---

## Exercício 5 — Preencher um vetor

📄 **Arquivo:** `exercicio4/main.c`

> [!NOTE]
> **Atenção à organização:** este é o exercício oficial número **5**, mas seu código está na pasta `exercicio4`.

### 1. Qual é o objetivo?

Criar uma função que receba um vetor e seu tamanho e preencha suas posições com números informados pelo usuário.

Um vetor é parecido com uma fileira de caixas numeradas. Cada caixa pode guardar um valor, e o número da caixa indica a posição em que esse valor está armazenado.

Em C, a primeira posição de um vetor é a posição **0**, não a posição 1. Por exemplo, em um vetor de cinco elementos, as posições são:

```text
0, 1, 2, 3, 4
```

### 2. Conceitos necessários

- Vetores.
- Ponteiros.
- Funções.
- Laço `for`.
- Entrada de dados com `scanf`.
- Endereços de memória.

### 3. Código atualizado

```c
int vetVal(int *v, int N) {
    int c;
    if (v == NULL || N <= 0) {
        fprintf(stderr, "Vetor ou tamanho invalido.\n");
        return 0;
    }
    for (c = 0; c < N; c++) {
        printf("Digite o %d valor: ", c + 1);
        if (scanf("%d", &v[c]) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            return 0;
        }
    }
    return 1;
}
```

### 4. Explicação linha a linha

**Linha 1 — `int vetVal(int *v, int N)`**

Declara a função `vetVal`.

- `int` indica que a função informa, por meio de `1` ou `0`, se conseguiu preencher o vetor.
- `int *v` recebe o endereço do primeiro elemento do vetor.
- `int N` informa quantos elementos devem ser preenchidos.

**Linha 2 — `int c;`**

Declara o contador que indica qual posição será preenchida.

**Linha 3 — `for (c = 0; c < N; c++)`**

Como no [exercício 1](#exercício-1--ordenar-quatro-valores), o laço `for` começa com `c = 0`, continua enquanto `c < N` e incrementa `c` a cada repetição. A diferença é que, aqui, cada repetição corresponde à leitura de um novo valor.

**Linha 4 — `printf("Digite o %d valor: ", c + 1);`**

Exibe uma mensagem solicitando o valor. O programa utiliza `c + 1` na mensagem para apresentar posições de maneira mais natural para o usuário: primeiro valor, segundo valor, terceiro valor etc. Isso não altera o índice real do vetor.

**Linha 5 — `scanf("%d", &v[c]);`**

Lê um número inteiro digitado pelo usuário e o armazena na posição atual.

- `%d` indica que será lido um inteiro.
- `v[c]` representa o elemento atual.
- `&v[c]` fornece o **endereço** da posição onde o valor deverá ser armazenado.

O `scanf` precisa desse endereço para modificar o conteúdo da variável ou posição correspondente.

### 5. 🧃 Analogia cotidiana: preencher caixas numeradas

Imagine uma prateleira com cinco caixas vazias. Você começa pela primeira, coloca um objeto nela e continua até preencher todas as caixas.

O vetor é a prateleira, os índices são os números das caixas e os valores digitados são os objetos armazenados. A função recebe a prateleira e a quantidade de caixas, e o laço percorre cada posição para preenchê-la.

### 6. Atenção

> [!TIP]
> A função agora rejeita ponteiro nulo e tamanho não positivo, verifica cada leitura e informa ao programa principal se conseguiu preencher o vetor. Em C, o ponteiro não carrega a capacidade do vetor: quem chama a função ainda precisa garantir que `N` não exceda o número de posições alocadas. Neste programa, o vetor tem cinco posições e a chamada usa `N = 5`.

---

## Exercício 6 — Exibir um vetor

📄 **Arquivo:** `exercicio6/main.c`

### 1. Qual é o objetivo?

Criar uma função que receba um vetor e exiba todos os seus valores na tela.

É como ler em voz alta os itens de uma lista, começando pelo primeiro e seguindo até o último.

### 2. Código atualizado

```c
void mostra(int *v, int N) {
    int c;
    if (v == NULL || N < 0) {
        fprintf(stderr, "Vetor ou tamanho invalido.\n");
        return;
    }
    printf("[");
    for (c = 0; c < N; c++)
        printf(" %d ", v[c]);
    printf("]");
}
```

### 3. Explicação linha a linha

**Linha 1 — `void mostra(int *v, int N)`**

Declara a função `mostra`, que recebe o vetor e seu tamanho. Como sua tarefa é apenas exibir valores, ela não precisa retornar um resultado.

**Linha 2 — `int c;`**

Declara o contador utilizado para percorrer as posições.

**Linha 3 — `printf("[");`**

Imprime o colchete de abertura para representar visualmente o início do vetor.

**Linha 4 — `for (c = 0; c < N; c++)`**

Como no [exercício 1](#exercício-1--ordenar-quatro-valores), o laço `for` percorre as posições do vetor do índice `0` até o índice `N - 1`.

**Linha 5 — `printf(" %d ", v[c]);`**

Imprime o elemento da posição atual. O formato `%d` representa um inteiro.

**Linha 6 — `printf("]");`**

Imprime o colchete de fechamento.

### 4. 🧃 Analogia cotidiana: ler uma lista de compras

Imagine uma lista com os itens arroz, feijão e leite. Para mostrar a lista a outra pessoa, você percorre cada item e o anuncia.

A função `mostra` faz a mesma coisa com números armazenados em um vetor: percorre cada posição e apresenta seu conteúdo.

### 5. Atenção

> [!NOTE]
> A chamada do programa usa um vetor de cinco posições e informa `N = 5`. Em C, a função não consegue descobrir a capacidade real a partir de um ponteiro; quem a chama deve passar um tamanho que corresponda ao vetor. Os espaços em torno de `%d` são apenas separadores visuais da saída.

---

## Exercício 7 — Exibir um vetor ao contrário

📄 **Arquivo:** `exercicio7/main.c`

### 1. Qual é o objetivo?

Exibir os elementos de um vetor na **ordem inversa**, sem modificar a ordem em que eles estão armazenados.

Se o vetor contém:

```text
[10, 20, 30, 40, 50]
```

A função deverá exibir:

```text
[50, 40, 30, 20, 10]
```

### 2. Código atualizado

```c
void mostrainverso(int *v, int N) {
    int c;
    if (v == NULL || N < 0) {
        fprintf(stderr, "Vetor ou tamanho invalido.\n");
        return;
    }
    printf("[");
    for (c = N - 1; c >= 0; c--)
        printf(" %d ", v[c]);
    printf("]");
}
```

### 3. Explicação linha a linha

**Linha 1 — `void mostrainverso(int *v, int N)`**

Declara a função `mostrainverso`, que recebe o vetor e a quantidade de elementos.

**Linha 2 — `int c;`**

Declara o contador utilizado para escolher a posição que será exibida.

**Linha 3 — `printf("[");`**

Imprime o colchete de abertura.

**Linha 4 — `for (c = N - 1; c >= 0; c--)`**

Como no [exercício 1](#exercício-1--ordenar-quatro-valores), o `for` controla o início, a condição e a atualização do contador. Aqui, a diferença é que ele começa no **último índice** e diminui até chegar a zero.

Em um vetor com cinco elementos, o último índice é `4`, porque a contagem começa em zero.

**Linha 5 — `printf(" %d ", v[c]);`**

Exibe o elemento da posição atual, começando pelo final do vetor.

**Linha 6 — `printf("]");`**

Imprime o colchete de fechamento.

### 4. 🧃 Analogia cotidiana: ler uma fila de trás para frente

Imagine uma fila de pessoas. Você não muda ninguém de lugar; apenas começa a observar pela última pessoa e segue até a primeira.

A função faz isso com o vetor. Ela muda a **ordem de exibição**, mas não altera os valores armazenados.

### 5. Atenção

> [!NOTE]
> Um tamanho zero exibe corretamente um vetor vazio (`[]`); tamanho negativo e ponteiro nulo são rejeitados. Em C, a função não consegue descobrir a capacidade real a partir de um ponteiro, então quem chama deve garantir que `N` corresponda ao vetor. O programa principal passa um vetor de cinco posições junto com `N = 5`.

---

## Exercício 8 — Somar os valores de um vetor

📄 **Arquivo:** `exercicio8/main.c`

### 1. Qual é o objetivo?

Somar todos os elementos de um vetor. Por exemplo, para o vetor:

```text
[5, 10, 15, 20, 25]
```

A soma é:

$$
5 + 10 + 15 + 20 + 25 = 75
$$

O objetivo oficial pede uma função que **retorne** a soma ao programa principal. A função corrigida calcula e retorna o resultado; o programa principal é responsável por exibi-lo.

### 2. Código atualizado

```c
int soma(int *v, int N) {
    int c, total = 0;
    if (v == NULL || N < 0)
        return 0;
    for (c = 0; c < N; c++)
        total += v[c];
    return total;
}
```

### 3. Explicação linha a linha

**Linha 1 — `int soma(int *v, int N)`**

Declara uma função chamada `soma`, que recebe o vetor e sua quantidade de elementos e retorna a soma calculada.

**Linha 2 — `int c, total = 0;`**

Declara duas variáveis:

- `c` controla a posição atual.
- `total` acumula o resultado, começando em zero.

O zero é um bom valor inicial para uma soma porque não altera o resultado quando um número é adicionado a ele.

**Linha 3 — `for (c = 0; c < N; c++)`**

Como no [exercício 1](#exercício-1--ordenar-quatro-valores), o laço percorre todas as posições do vetor, da primeira à última.

**Linha 4 — `total += v[c];`**

Adiciona o elemento atual ao acumulador. A expressão `total += v[c]` equivale a:

```c
total = total + v[c];
```

A cada repetição, o total é atualizado.

O programa principal exibe o valor retornado por `soma`, permitindo também reutilizá-lo em outros cálculos.

### 4. 🧃 Analogia cotidiana: somar o valor das compras

Imagine que você comprou três produtos que custam R$ 5, R$ 10 e R$ 15. Para descobrir o total, começa em zero e adiciona o preço de cada produto.

O acumulador `total` funciona como o total parcial no visor de uma calculadora. A cada item, ele recebe o valor anterior mais o novo preço.

### 5. Atenção

> [!NOTE]
> A função agora retorna a soma e rejeita um ponteiro nulo ou tamanho negativo. Um tamanho zero retorna `0`. Como C não registra a capacidade junto ao ponteiro, quem chama ainda precisa informar um tamanho que não ultrapasse o vetor; o programa usa cinco posições e passa `N = 5`.

---

## Exercício 9 — Contar valores acima da média

📄 **Arquivo:** `exercicio9/main.c`

### 1. Qual é o objetivo?

Calcular a média dos valores de um vetor e contar quantos elementos são **maiores** do que ela.

Imagine uma turma de estudantes. Primeiro, você calcula a média das notas da turma. Depois, conta quantos estudantes obtiveram notas acima dessa média. O programa segue esse mesmo raciocínio.

### 2. Conceitos necessários

- Acumuladores.
- Média aritmética.
- Laços `for`.
- Condicionais `if`.
- Comparação de valores.
- Números de ponto flutuante.

A média aritmética é calculada pela soma de todos os valores dividida pela quantidade de elementos:

$$
\text{média} = \frac{\text{soma dos valores}}{\text{quantidade de valores}}
$$

### 3. Código atualizado

```c
int mediaQtd(int *v, int N, double *media) {
    int c, quantidade = 0;
    long long soma = 0;

    if (v == NULL || media == NULL || N <= 0)
        return -1;

    for (c = 0; c < N; c++)
        soma += v[c];

    *media = (double)soma / N;

    for (c = 0; c < N; c++)
        if (v[c] > *media)
            quantidade++;

    return quantidade;
}
```

### 4. Explicação linha a linha

**Linha 1 — `int mediaQtd(int *v, int N, double *media)`**

Declara a função `mediaQtd`, que recebe um vetor, seu tamanho e o endereço onde será armazenada a média. Retorna a quantidade de elementos acima da média, ou `-1` se os argumentos ou o tamanho forem inválidos.

**Linha 2 — `int c, quantidade = 0; long long soma = 0;`**

Declara as variáveis necessárias:

- `c`: contador dos laços.
- `media`: é o parâmetro de saída para a média.
- `soma`: acumula os valores em um tipo capaz de guardar uma soma maior.
- `quantidade`: conta quantos elementos são maiores que a média.

Os acumuladores começam em zero.

**Linhas 4 e 5 — primeiro laço**

Como no [exercício 1](#exercício-1--ordenar-quatro-valores), o `for` percorre todas as posições do vetor. O bloco `soma += v[c]` adiciona cada elemento ao acumulador. Ao terminar o laço, `soma` contém o total de todos os valores.

**Linha 6 — `*media = (double)soma / N;`**

Divide a soma pela quantidade de elementos para calcular a média. A conversão para `double` preserva a parte decimal.

**Linhas 15 a 17 — segundo laço**

O segundo laço percorre novamente o vetor. A condição `v[c] > *media` verifica se o elemento atual é maior do que a média calculada. Quando a condição é verdadeira, `quantidade++` aumenta a contagem em uma unidade.

Esse segundo percurso é necessário porque o programa precisa conhecer a média **antes** de poder identificar quais valores estão acima dela.

O programa principal apresenta a média com duas casas decimais e exibe a quantidade devolvida pela função.

### 5. 🧃 Analogia cotidiana: notas de uma turma

Imagine cinco notas:

```text
[4, 6, 7, 8, 10]
```

A soma é `35` e a média é `7`. Agora você percorre as notas novamente e conta aquelas **estritamente maiores** que 7: `8` e `10`. O resultado é **2 valores** acima da média.

Observe que uma nota igual à média não entra na contagem, pois a condição é `>` e não `>=`.

### 6. Atenção

> [!TIP]
> A média agora usa `double`, a soma intermediária usa `long long` e a função rejeita vetor nulo, endereço de média nulo ou tamanho não positivo antes de dividir. Como C não armazena a capacidade junto ao ponteiro, o chamador ainda precisa garantir que `N` corresponda ao vetor; neste programa, são cinco posições.

---

## Exercício 10 — Somar dois vetores

📄 **Arquivo:** `exercicio10/main.c`

### 1. Qual é o objetivo?

Somar dois vetores de mesmo tamanho, **posição por posição**. Considere:

```text
Vetor A = [1, 2, 3, 4, 5]
Vetor B = [10, 20, 30, 40, 50]
```

A soma será:

```text
[11, 22, 33, 44, 55]
```

O primeiro elemento de A é somado ao primeiro elemento de B, o segundo ao segundo e assim por diante.

### 2. Código atualizado

```c
int somaVetor(const int *v1, const int *v2, int *resultado, int N) {
    int c;
    if (v1 == NULL || v2 == NULL || resultado == NULL || N <= 0)
        return 0;
    for (c = 0; c < N; c++)
        resultado[c] = v1[c] + v2[c];
    return 1;
}
```

### 3. Explicação linha a linha

**Linha 1 — `int somaVetor(const int *v1, const int *v2, int *resultado, int N)`**

Declara a função que recebe os dois vetores, o vetor de saída e a quantidade de elementos que será processada. Retorna `0` para argumentos ou tamanho inválidos e `1` quando conclui a soma.

- `v1` aponta para o primeiro vetor.
- `v2` aponta para o segundo vetor.
- `resultado` aponta para as posições onde serão guardadas as somas.
- `N` representa a quantidade de posições.

**Linha 2 — `int c;`**

Declara o contador. O vetor de resultados é criado no programa principal com capacidade conhecida; assim, a função não depende de um vetor de tamanho variável (VLA).

**Linha 4 — `for (c = 0; c < N; c++)`**

Como no [exercício 1](#exercício-1--ordenar-quatro-valores), o laço percorre todas as posições, da primeira à última.

**Linha 5 — `resultado[c] = v1[c] + v2[c];`**

Soma os valores da posição atual dos dois vetores e grava o resultado na posição correspondente do vetor de saída.

O programa principal imprime o vetor de resultados depois que a função calcula as somas. A função se concentra no cálculo e não cria nem imprime um vetor local.

### 4. 🧃 Analogia cotidiana: juntar quantidades de dois carrinhos

Imagine dois carrinhos de supermercado. Em ambos existem quantidades de determinados produtos.

Para saber a quantidade total de cada produto, você soma a quantidade do primeiro carrinho à quantidade do segundo. Faz isso para cada posição da lista e anota os resultados em uma terceira lista.

Os dois vetores de entrada são os carrinhos originais; o vetor `resultado` é a lista com as quantidades totais.

### 5. Atenção

> [!TIP]
> A função não cria mais um VLA: o vetor de resultados tem tamanho fixo no programa principal e é passado como parâmetro. A função também rejeita ponteiros nulos e tamanhos não positivos. Como C não consegue determinar a capacidade real de um ponteiro, o chamador deve garantir que os dois vetores de entrada e o vetor de saída tenham pelo menos `N` posições; neste programa, os três têm cinco.

---

## 🎓 Considerações finais

Aprender C é muito mais do que memorizar comandos. É entender como os dados são armazenados, como as instruções são executadas e como dividir um problema grande em tarefas menores.

Ao longo destes exercícios, você praticou ideias fundamentais:

| Conceito | Para que serve |
| :--- | :--- |
| **Funções** | Dividem um programa em tarefas específicas. |
| **Ponteiros** | Permitem acessar dados por meio de seus endereços de memória. |
| **Passagem por referência** | Possibilita modificar as variáveis originais. |
| **Vetores** | Organizam vários valores em uma sequência de posições. |
| **Laços de repetição** | Automatizam tarefas que precisam ser realizadas várias vezes. |
| **Condicionais** | Permitem tomar decisões com base em determinadas condições. |
| **Acumuladores** | Guardam resultados parciais durante cálculos. |

Não se preocupe se alguns conceitos parecerem complicados no início. Volte aos exemplos, altere os valores de entrada, desenhe os vetores em papel e acompanhe o que acontece a cada repetição.

> 💡 **Dica de estudo:** uma boa maneira de aprender é **prever o resultado antes de executar o programa** e, depois, comparar sua previsão com o resultado real.

Programar é aprender a transformar problemas em passos lógicos. Pratique, experimente e **bons estudos!**

---

<div align="center">

Feito com 💙 para estudantes de LTP I · IFRJ — Campus Pinheiral

</div>
