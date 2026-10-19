Exercícios de LTP I — Fundamentos de C

Bem-vindo(a)! 👋

Este repositório reúne exercícios da disciplina de Linguagem e Técnicas de Programação I (LTP I), do IFRJ — Campus Pinheiral. O objetivo é ajudar estudantes iniciantes a compreender os fundamentos da linguagem C por meio de exemplos práticos, explicações detalhadas e analogias com situações do cotidiano.

Os exercícios trabalham principalmente com:

* Variáveis e tipos de dados;
* Funções e passagem de parâmetros;
* Ponteiros e passagem por referência;
* Vetores e posições de memória;
* Laços de repetição;
* Condicionais e operadores matemáticos;
* Organização e manipulação de dados.

A proposta não é apenas mostrar códigos que funcionam, mas ajudar você a entender o raciocínio por trás de cada instrução.

Como aproveitar este material

Leia cada exercício nesta ordem:

1. Objetivo: entenda o problema que o programa precisa resolver.
2. Conceitos necessários: conheça as ferramentas da linguagem utilizadas.
3. Código original: observe a implementação presente no repositório.
4. Explicação linha a linha: entenda o papel de cada instrução.
5. Analogia cotidiana: relacione o código a uma situação familiar.
6. Atenção: identifique erros ou limitações que serão corrigidos futuramente, quando existirem.

Importante: os códigos apresentados neste README são os trechos originais documentados no projeto. Alguns possuem problemas de implementação. Eles serão mantidos como estão nesta documentação, e as consequências desses problemas serão explicadas nas seções Atenção.

Organização do repositório

Os dez exercícios oficiais estão distribuídos em pastas independentes. Existe uma particularidade: os exercícios 4 e 5 estão em pastas com a numeração invertida em relação à lista oficial.


| Exercício oficial | Objetivo | Arquivo |
| :---: | :--- | :--- |
| 1 | Ordenar quatro valores | `exercicio1/main.c` |
| 2 | Trocar dois valores | `exercicio2/main.c` |
| 3 | Simplificar uma fração | `exercicio3/main.c` |
| 4 | Calcular a soma e o produto dos números de 1 a 100 | `exercicio5/main.c` |
| 5 | Preencher um vetor | `exercicio4/main.c` |
| 6 | Exibir um vetor | `exercicio6/main.c` |
| 7 | Exibir um vetor ao contrário | `exercicio7/main.c` |
| 8 | Somar os valores de um vetor | `exercicio8/main.c` |
| 9 | Contar os valores acima da média | `exercicio9/main.c` |
| 10 | Somar dois vetores | `exercicio10/main.c` |


Além dessas pastas, execVetor contém pequenos programas de prática, e CLTP contém um exercício adicional sobre números primos.

⸻

Exercício 1 — Ordenar quatro valores

Arquivo: exercicio1/main.c

1. Qual é o objetivo?

O programa recebe quatro números e organiza esses valores em ordem crescente, ou seja, do menor para o maior.

Imagine que quatro pessoas estejam em uma fila, mas estejam fora de ordem de altura. Você quer reorganizá-las para que a pessoa mais baixa fique no começo e a mais alta no final.

Uma maneira de fazer isso é comparar pessoas vizinhas e trocar suas posições quando necessário. O algoritmo utilizado neste exercício segue justamente essa ideia.

2. Conceitos necessários

* Vetor: conjunto de posições que armazenam valores.
* Função: bloco de código que realiza uma tarefa específica.
* Ponteiro: variável que permite trabalhar com um endereço de memória.
* Laços for: estruturas que repetem instruções.
* Condicional if: executa um bloco somente quando uma condição é verdadeira.
* Variável temporária: espaço utilizado para guardar provisoriamente um valor durante uma troca.

3. Código original

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

4. Explicação linha a linha

Linha 1 — int ordenar(int *v, int N)

Declara uma função chamada ordenar.

* int é o tipo de retorno declarado para a função.
* ordenar é o nome da função.
* int *v recebe o endereço de um vetor de inteiros.
* int N recebe a quantidade de elementos que devem ser considerados.

O asterisco em int *v indica que v é um ponteiro para inteiros. Isso permite que a função trabalhe diretamente com os elementos do vetor recebido.

Linha 2 — int c, temp, i, swaped;

Declara quatro variáveis inteiras:

* c: controla o laço externo.
* temp: guarda temporariamente um valor durante a troca.
* i: percorre as posições do vetor no laço interno.
* swaped: indica se ocorreu alguma troca durante uma passagem pelo vetor.

O nome swaped foi mantido como aparece no código original.

Linha 4 — for (c = 0; c < N; c++)

Inicia o laço externo.

A estrutura for possui três partes:

1. c = 0: inicializa o contador.
2. c < N: verifica se o contador ainda está dentro do limite.
3. c++: incrementa o contador ao final de cada repetição.

O símbolo ++ aumenta o valor da variável em uma unidade.

Como N representa o tamanho do vetor, o laço realiza passagens sucessivas para organizar os elementos.

Linha 5 — swaped = 0;

Marca o início de uma nova passagem pelo vetor.

O programa começa considerando que nenhuma troca aconteceu. Se encontrar dois valores fora de ordem, altera essa variável para 1.

Linha 6 — for (i = 0; i < N - c - 1; i++)

Inicia o laço interno, responsável por comparar os elementos vizinhos.

Como no laço anterior, i começa em zero e aumenta uma unidade a cada repetição.

A expressão N - c - 1 reduz o limite das comparações conforme as passagens acontecem. Isso ocorre porque, no algoritmo conhecido como Bubble Sort, os maiores valores vão sendo deslocados para o final do vetor.

O - 1 é necessário porque o programa acessa também a posição seguinte, i + 1.

Linha 7 — if (v[i] > v[i + 1])

Compara o elemento atual com o próximo.

* v[i] representa o elemento da posição atual.
* v[i + 1] representa o elemento seguinte.
* > significa “maior que”.

Se o elemento atual for maior que o próximo, os dois estão fora de ordem crescente e precisam ser trocados.

Linha 8 — temp = v[i];

Guarda o valor atual em temp.

Essa etapa é necessária para que o valor não seja perdido durante a troca.

Linha 9 — v[i] = v[i + 1];

Copia o valor do próximo elemento para a posição atual.

O valor anterior dessa posição continua guardado em temp.

Linha 10 — v[i + 1] = temp;

Coloca o valor guardado em temp na posição seguinte. Assim, a troca é concluída.

Linha 11 — swaped = 1;

Registra que pelo menos uma troca aconteceu nessa passagem.

Linhas 15 a 19 — impressão do vetor

Quando swaped == 0, o programa entende que não houve trocas durante a passagem e tenta exibir o vetor:

* printf("["); imprime o colchete de abertura.
* O for percorre as posições e imprime cada inteiro com %d.
* printf("]"); imprime o colchete de fechamento.

A formatação %d é utilizada para exibir valores do tipo int.

5. Entendendo os laços na prática

Existem dois níveis de repetição:

* Laço externo: organiza as passagens pelo vetor.
* Laço interno: compara os vizinhos e realiza as trocas necessárias.

Imagine organizar quatro pessoas por altura. Você compara a primeira com a segunda, depois a segunda com a terceira e assim por diante. Ao terminar uma passagem, o maior valor comparado fica no final. Você repete o processo até que nenhuma troca seja necessária.

Por exemplo, considere o vetor:

[8, 3, 6, 2]

Na primeira passagem:

1. Compara 8 com 3: troca.
2. Compara 8 com 6: troca.
3. Compara 8 com 2: troca.

O resultado da primeira passagem é:

[3, 6, 2, 8]

O maior número chegou ao final. As passagens seguintes continuam organizando os elementos restantes.

6. Analogia cotidiana: organizar uma fila

Imagine que você seja responsável por organizar uma fila de pessoas da mais baixa para a mais alta. Em vez de retirar todas as pessoas da fila e reorganizá-las de uma vez, você olha duas pessoas vizinhas.

Se a pessoa da esquerda for mais alta do que a da direita, você pede que elas troquem de lugar. Ao percorrer a fila várias vezes, as pessoas vão ficando progressivamente mais organizadas.

O algoritmo faz exatamente isso, mas compara números em vez de pessoas.

7. Atenção

* Tipo de retorno inadequado: a função foi declarada como int, mas não retorna um valor. Como sua finalidade é reorganizar o vetor, o tipo void seria mais apropriado. A ausência de um retorno válido pode causar comportamento indefinido caso o valor de retorno seja utilizado.
* Uso da variável c em dois laços: o for de impressão reutiliza c, que também controla o laço externo. Isso modifica o contador externo e pode fazer com que a ordenação seja interrompida antes de terminar. O programa será corrigido para usar um contador independente na impressão.
* Impressão durante a ordenação: a impressão acontece quando não ocorre troca, mas está dentro do laço externo. Isso pode gerar saídas repetidas ou interromper o processamento de forma inesperada. A exibição final deverá acontecer depois da ordenação.
* Nome da variável: swaped será renomeada futuramente para swapped, tornando o código mais claro, sem alterar seu funcionamento.

⸻

Exercício 2 — Trocar dois valores (swap)

Arquivo: exercicio2/main.c

1. Qual é o objetivo?

O programa recebe dois valores e troca seus conteúdos por meio de uma função.

Imagine dois copos: um contém suco de laranja e o outro contém água. Você quer que cada copo termine com o líquido que estava originalmente no outro.

Para trocar os conteúdos sem perder nenhum deles, você pode usar um terceiro copo vazio como recipiente temporário.

É a mesma ideia utilizada para trocar os valores de duas variáveis.

2. Conceitos necessários

* Ponteiros.
* Operador &, utilizado para obter um endereço.
* Operador *, utilizado para acessar o valor apontado.
* Variável temporária.
* Funções e passagem por referência.

Entendendo & e *

Considere uma variável chamada a que armazena o número 10.

* a representa o valor 10.
* &a representa o endereço de memória onde a está armazenada.
* Se um ponteiro apontar para a, *ponteiro acessa o valor guardado nesse endereço.

Pense em uma casa: o número escrito na placa corresponde ao endereço, enquanto os objetos dentro da casa correspondem ao conteúdo armazenado.

3. Código original

int swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

4. Explicação linha a linha

Linha 1 — int swap(int *a, int *b)

Declara a função swap, que recebe dois ponteiros para inteiros.

Os parâmetros a e b permitem que a função acesse as variáveis originais por meio de seus endereços.

Linha 2 — int tmp;

Cria uma variável temporária chamada tmp, que guardará um dos valores durante a troca.

Linha 3 — tmp = *a;

Lê o valor armazenado no endereço apontado por a e o copia para tmp.

O asterisco indica que queremos o conteúdo do endereço, e não o próprio endereço.

Linha 4 — *a = *b;

Copia o valor apontado por b para a variável original apontada por a.

Linha 5 — *b = tmp;

Coloca em b o valor que estava originalmente em a e que foi preservado em tmp.

A troca está concluída.

5. Analogia cotidiana: trocar o conteúdo de dois copos

Imagine que o copo A contém suco e o copo B contém água.

1. Você transfere o suco do copo A para um copo auxiliar.
2. Passa a água do copo B para o copo A.
3. Transfere o suco do copo auxiliar para o copo B.

A variável tmp funciona como o copo auxiliar. Sem ela, o primeiro conteúdo poderia ser sobrescrito antes de ser transferido para o outro copo.

Exemplo de execução

Considere que a = 10 e b = 20.

Instrução	a	b	tmp
Estado inicial	10	20	—
tmp = *a	10	20	10
*a = *b	20	20	10
*b = tmp	20	10	10

No final, os valores foram trocados.

6. Atenção

* Tipo de retorno inadequado: a função está declarada como int, mas não retorna um inteiro. Como a finalidade é modificar as variáveis originais, void seria mais adequado. Utilizar um retorno inexistente pode causar comportamento indefinido.
* Impressão de endereços: o programa principal utiliza %d para imprimir endereços de memória. Esse especificador é destinado a inteiros, não a ponteiros. A consequência pode ser uma saída incorreta e comportamento indefinido. A correção utilizará %p, com o endereço convertido para (void *).
* Passagem de endereços: a função depende de receber endereços válidos. Se receber ponteiros inválidos ou nulos e tentar acessá-los, o programa poderá falhar.

O código original será mantido nesta documentação; essas correções serão feitas posteriormente no programa.

⸻

Exercício 3 — Simplificar uma fração

Arquivo: exercicio3/main.c

1. Qual é o objetivo?

O programa recebe o numerador e o denominador de uma fração e tenta simplificá-la, dividindo os dois valores por divisores comuns.

Por exemplo:

[
\frac{4}{10}=\frac{2}{5}
]

As duas frações representam a mesma quantidade, mas a segunda utiliza números menores.

2. Conceitos necessários

* Ponteiros.
* Operadores relacionais.
* Operador módulo %.
* Laço for.
* Condições com &&.
* Divisão inteira.

O operador % calcula o resto de uma divisão inteira.

Por exemplo:

* 10 % 2 resulta em 0, pois 10 é divisível por 2.
* 10 % 3 resulta em 1, pois sobra 1.

Quando o resto é zero, o número é divisível pelo divisor testado.

3. Código original

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

4. Explicação linha a linha

Linha 1 — void simplifica(int *divisor, int *dividendo)

Declara uma função que não retorna um valor, mas modifica os números recebidos por meio de ponteiros.

Os nomes divisor e dividendo foram mantidos conforme o código original. Em uma fração convencional, os termos normalmente são chamados de denominador e numerador, respectivamente.

Linha 2 — int c, menor;

Declara duas variáveis:

* c: representa o divisor que será testado.
* menor: armazena o menor dos dois valores recebidos.

Linhas 3 a 6 — escolha do menor valor

A condição compara os valores apontados por divisor e dividendo.

Se o primeiro for menor, ele é armazenado em menor. Caso contrário, o segundo é utilizado.

A ideia é limitar a busca aos números que poderiam dividir ambos os valores.

Linha 8 — for (c = 1; c <= menor; c++)

Como no exercício 1, o for inicializa um contador, verifica uma condição e incrementa o contador ao final de cada repetição.

Aqui, o contador começa em 1 e percorre os valores até menor, inclusive.

Cada número testado é um possível divisor comum.

Linha 9 — if (*divisor % c == 0 && *dividendo % c == 0)

Verifica se os dois valores são divisíveis por c.

* % c == 0 significa que a divisão por c não deixa resto.
* && significa “e”: as duas condições precisam ser verdadeiras.

Se apenas um dos valores for divisível por c, o bloco não será executado.

Linha 10 — *divisor = *divisor / c;

Divide o primeiro valor por c e armazena o resultado na própria variável original.

Linha 11 — *dividendo = *dividendo / c;

Faz o mesmo com o segundo valor.

Como a função recebe ponteiros, as alterações são refletidas nas variáveis do programa principal.

5. Analogia cotidiana: dividir duas coleções em grupos iguais

Imagine que você tenha 12 lápis e 18 cadernos e queira dividir ambos igualmente entre algumas pessoas, sem sobrar nenhum item.

Você procura um número que divida as duas quantidades. Por exemplo, 3 divide 12 e 18. Assim, pode dividir os lápis e os cadernos em três grupos iguais.

A simplificação de uma fração segue um raciocínio parecido: os dois valores são divididos pelo mesmo número, preservando a proporção.

6. Atenção

* Os valores são alterados durante a busca: o programa modifica os dois números dentro do laço. Isso significa que os próximos testes não são realizados necessariamente com os valores originais. Como consequência, alguns casos podem terminar sem a simplificação correta.
* Busca pelo divisor comum: o objetivo é dividir os dois valores pelo maior divisor comum. A implementação atual não calcula esse divisor separadamente. Uma futura correção poderá utilizar o algoritmo de Euclides para encontrar o máximo divisor comum antes de realizar as divisões.
* Entradas esperadas: o programa pressupõe valores positivos e diferentes de zero. Entradas negativas ou zero podem produzir resultados incorretos ou situações não previstas pela lógica atual.

⸻

Exercício 4 — Soma e produto dos 100 primeiros positivos

Arquivo: exercicio5/main.c

Atenção à organização: embora este seja o exercício oficial número 4, seu código está na pasta exercicio5.

1. Qual é o objetivo?

Calcular duas coisas:

* A soma dos números inteiros de 1 a 100.
* O produto dos mesmos números, isto é, (1 \times 2 \times 3 \times \cdots \times 100).

O resultado da soma é:

[
1+2+\cdots+100=5050
]

O produto é conhecido como (100!), ou fatorial de 100. É um número extremamente grande.

2. Conceitos necessários

* Funções.
* Ponteiros.
* Fórmula da soma de uma sequência.
* Laço for.
* Multiplicação acumulada.
* Tipos int e double.

O tipo int é usado para números inteiros. Já double representa números de ponto flutuante, permitindo valores muito maiores em magnitude, embora com precisão limitada.

3. Código original

double somaproduto(int *soma, double *produto) {
    int c;
    double p = 1;
    *soma = 101 * 100 / 2;
    for (c = 100; c > 0; c--)
        p = p * c;
    *produto = p;
}

4. Explicação linha a linha

Linha 1 — double somaproduto(int *soma, double *produto)

Declara a função somaproduto.

* double é o tipo de retorno declarado.
* int *soma recebe um ponteiro para inteiro.
* double *produto recebe um ponteiro para double.

A função utiliza os ponteiros para disponibilizar os resultados nas variáveis recebidas.

Linha 2 — int c;

Declara o contador utilizado para percorrer os números de 100 até 1.

Linha 3 — double p = 1;

Cria o acumulador p, inicializado com 1.

Esse valor inicial é importante porque multiplicar qualquer número por zero resultaria em zero, destruindo o resultado do produto.

Linha 5 — *soma = 101 * 100 / 2;

Calcula a soma de 1 até 100 usando a fórmula:

[
S=\frac{n(n+1)}{2}
]

Para (n=100):

[
S=\frac{100\times101}{2}=5050
]

O resultado é atribuído ao endereço apontado por soma.

Linha 6 — for (c = 100; c > 0; c--)

Como no exercício 1, o for controla as repetições. Neste caso, começa em 100 e continua enquanto c > 0.

O operador c-- diminui o contador em uma unidade ao final de cada repetição.

Assim, a sequência percorrida é 100, 99, 98, e assim por diante, até 1.

Linha 7 — p = p * c;

Multiplica o acumulador pelo valor atual de c e guarda o resultado em p.

Cada repetição incorpora um novo fator ao produto.

Linha 8 — *produto = p;

Copia o produto calculado para a variável original apontada por produto.

5. Analogia cotidiana: somar uma pilha de moedas e multiplicar fatores

Imagine que você tenha uma pilha com moedas numeradas de 1 a 100 e queira saber a soma de todos os valores. Em vez de somar uma por uma, pode usar uma fórmula matemática que chega ao mesmo resultado.

Para o produto, porém, você precisa multiplicar cada fator. O acumulador p funciona como uma calculadora que mantém o resultado parcial e o atualiza a cada etapa.

6. Atenção

* Incompatibilidade entre ponteiros e variáveis: a função recebe int *soma, mas o programa principal declara soma como double. Passar um ponteiro para double onde se espera um ponteiro para int é incompatível. Isso pode gerar avisos de compilação e, se executado, comportamento indefinido ao acessar a memória com o tipo errado.
* Especificador de impressão incorreto: o programa principal utiliza %d para imprimir uma variável double. Como %d espera um inteiro, essa incompatibilidade pode produzir resultados sem sentido ou comportamento indefinido.
* Tipo de retorno: a função foi declarada como double, mas não retorna um valor. O resultado calculado é comunicado por meio dos ponteiros, então um tipo de retorno void seria mais apropriado.
* Limitações do double: embora possa representar números de magnitude muito elevada, double não armazena todos os inteiros com precisão ilimitada. O fatorial de 100 pode ser representado em magnitude, mas não com todos os seus dígitos exatos.

Esses pontos serão corrigidos na implementação futura, mantendo o objetivo original do exercício.

⸻

Exercício 5 — Preencher um vetor

Arquivo: exercicio4/main.c

Atenção à organização: este é o exercício oficial número 5, mas seu código está na pasta exercicio4.

1. Qual é o objetivo?

Criar uma função que receba um vetor e seu tamanho e preencha suas posições com números informados pelo usuário.

Um vetor é parecido com uma fileira de caixas numeradas. Cada caixa pode guardar um valor, e o número da caixa indica a posição em que esse valor está armazenado.

Em C, a primeira posição de um vetor é a posição 0, não a posição 1.

Por exemplo, em um vetor de cinco elementos, as posições são:

0, 1, 2, 3, 4

2. Conceitos necessários

* Vetores.
* Ponteiros.
* Funções.
* Laço for.
* Entrada de dados com scanf.
* Endereços de memória.

3. Código original

void vetVal(int *v, int N) {
    int c;
    for (c = 0; c < N; c++) {
        printf("Digite o %d valor: ", c + 1);
        scanf("%d", &v[c]);
    }
}

4. Explicação linha a linha

Linha 1 — void vetVal(int *v, int N)

Declara a função vetVal.

* void indica que a função não retorna um valor.
* int *v recebe o endereço do primeiro elemento do vetor.
* int N informa quantos elementos devem ser preenchidos.

Linha 2 — int c;

Declara o contador que indica qual posição será preenchida.

Linha 3 — for (c = 0; c < N; c++)

Como no exercício 1, o laço for começa com c = 0, continua enquanto c < N e incrementa c a cada repetição.

A diferença é que, aqui, cada repetição corresponde à leitura de um novo valor.

Linha 4 — printf("Digite o %d valor: ", c + 1);

Exibe uma mensagem solicitando o valor.

O programa utiliza c + 1 na mensagem para apresentar posições de maneira mais natural para o usuário: primeiro valor, segundo valor, terceiro valor etc.

Isso não altera o índice real do vetor.

Linha 5 — scanf("%d", &v[c]);

Lê um número inteiro digitado pelo usuário e o armazena na posição atual.

* %d indica que será lido um inteiro.
* v[c] representa o elemento atual.
* &v[c] fornece o endereço da posição onde o valor deverá ser armazenado.

O scanf precisa desse endereço para modificar o conteúdo da variável ou posição correspondente.

5. Analogia cotidiana: preencher caixas numeradas

Imagine uma prateleira com cinco caixas vazias. Você começa pela primeira, coloca um objeto nela e continua até preencher todas as caixas.

O vetor é a prateleira, os índices são os números das caixas e os valores digitados são os objetos armazenados.

A função recebe a prateleira e a quantidade de caixas, e o laço percorre cada posição para preenchê-la.

6. Atenção

* Tamanho do vetor: a função pressupõe que o vetor recebido tenha pelo menos N posições. Se N for maior do que a capacidade real do vetor, o programa poderá acessar memória fora dos limites, causando comportamento indefinido.
* Entrada inválida: o código não verifica o retorno de scanf. Se o usuário digitar algo que não seja um inteiro válido, a leitura poderá falhar e deixar posições sem o valor esperado. Uma futura correção poderá validar cada entrada.

⸻

Exercício 6 — Exibir um vetor

Arquivo: exercicio6/main.c

1. Qual é o objetivo?

Criar uma função que receba um vetor e exiba todos os seus valores na tela.

É como ler em voz alta os itens de uma lista, começando pelo primeiro e seguindo até o último.

2. Código original

void mostra(int *v, int N) {
    int c;
    printf("[");
    for (c = 0; c < N; c++)
        printf(" %d ", v[c]);
    printf("]");
}

3. Explicação linha a linha

Linha 1 — void mostra(int *v, int N)

Declara a função mostra, que recebe o vetor e seu tamanho.

Como sua tarefa é apenas exibir valores, ela não precisa retornar um resultado.

Linha 2 — int c;

Declara o contador utilizado para percorrer as posições.

Linha 3 — printf("[");

Imprime o colchete de abertura para representar visualmente o início do vetor.

Linha 4 — for (c = 0; c < N; c++)

Como no exercício 1, o laço for percorre as posições do vetor do índice 0 até o índice N - 1.

Linha 5 — printf(" %d ", v[c]);

Imprime o elemento da posição atual. O formato %d representa um inteiro.

Linha 6 — printf("]");

Imprime o colchete de fechamento.

4. Analogia cotidiana: ler uma lista de compras

Imagine uma lista com os itens arroz, feijão e leite. Para mostrar a lista a outra pessoa, você percorre cada item e o anuncia.

A função mostra faz a mesma coisa com números armazenados em um vetor: percorre cada posição e apresenta seu conteúdo.

5. Atenção

* Capacidade do vetor: a função deve receber um tamanho que corresponda à quantidade de elementos disponíveis. Um tamanho maior do que a capacidade real poderá provocar acesso indevido à memória.
* Formatação: os espaços antes e depois de %d ajudam a separar os valores na saída, mas não representam parte dos números armazenados.

⸻

Exercício 7 — Exibir um vetor ao contrário

Arquivo: exercicio7/main.c

1. Qual é o objetivo?

Exibir os elementos de um vetor na ordem inversa, sem modificar a ordem em que eles estão armazenados.

Se o vetor contém:

[10, 20, 30, 40, 50]

A função deverá exibir:

[50, 40, 30, 20, 10]

2. Código original

void mostrainverso(int *v, int N) {
    int c;
    printf("[");
    for (c = N - 1; c >= 0; c--)
        printf(" %d ", v[c]);
    printf("]");
}

3. Explicação linha a linha

Linha 1 — void mostrainverso(int *v, int N)

Declara a função mostrainverso, que recebe o vetor e a quantidade de elementos.

Linha 2 — int c;

Declara o contador utilizado para escolher a posição que será exibida.

Linha 3 — printf("[");

Imprime o colchete de abertura.

Linha 4 — for (c = N - 1; c >= 0; c--)

Como no exercício 1, o for controla o início, a condição e a atualização do contador. Aqui, a diferença é que ele começa no último índice e diminui até chegar a zero.

Em um vetor com cinco elementos, o último índice é 4, porque a contagem começa em zero.

Linha 5 — printf(" %d ", v[c]);

Exibe o elemento da posição atual, começando pelo final do vetor.

Linha 6 — printf("]");

Imprime o colchete de fechamento.

4. Analogia cotidiana: ler uma fila de trás para frente

Imagine uma fila de pessoas. Você não muda ninguém de lugar; apenas começa a observar pela última pessoa e segue até a primeira.

A função faz isso com o vetor. Ela muda a ordem de exibição, mas não altera os valores armazenados.

5. Atenção

* Vetor vazio: se N for zero, o contador começa em -1 e a condição c >= 0 é falsa. O laço não executará nenhuma repetição, e apenas os colchetes serão impressos. Esse comportamento é válido para uma exibição vazia.
* Tamanho inválido: se o tamanho recebido não corresponder à capacidade real do vetor, o acesso aos elementos poderá resultar em comportamento indefinido.

⸻

Exercício 8 — Somar os valores de um vetor

Arquivo: exercicio8/main.c

1. Qual é o objetivo?

Somar todos os elementos de um vetor.

Por exemplo, para o vetor:

[5, 10, 15, 20, 25]

A soma é:

[
5+10+15+20+25=75
]

O objetivo oficial pede uma função que retorne a soma ao programa principal. O código existente, entretanto, calcula e imprime o resultado dentro da própria função.

2. Código original

void soma(int *v, int N) {
    int c, soma = 0;
    for (c = 0; c < N; c++)
        soma += v[c];
    printf("Soma: %d", soma);
}

3. Explicação linha a linha

Linha 1 — void soma(int *v, int N)

Declara uma função chamada soma, que recebe o vetor e sua quantidade de elementos.

Linha 2 — int c, soma = 0;

Declara duas variáveis:

* c controla a posição atual.
* soma acumula o resultado, começando em zero.

O zero é um bom valor inicial para uma soma porque não altera o resultado quando um número é adicionado a ele.

Linha 3 — for (c = 0; c < N; c++)

Como no exercício 1, o laço percorre todas as posições do vetor, da primeira à última.

Linha 4 — soma += v[c];

Adiciona o elemento atual ao acumulador.

A expressão soma += v[c] equivale a:

soma = soma + v[c];

A cada repetição, o total é atualizado.

Linha 5 — printf("Soma: %d", soma);

Exibe o resultado final na tela.

4. Analogia cotidiana: somar o valor das compras

Imagine que você comprou três produtos que custam R$ 5, R$ 10 e R$ 15. Para descobrir o total, começa em zero e adiciona o preço de cada produto.

O acumulador soma funciona como o total parcial no visor de uma calculadora. A cada item, ele recebe o valor anterior mais o novo preço.

5. Atenção

* O resultado não é retornado: o objetivo oficial exige que a função devolva a soma, mas ela foi declarada como void e apenas imprime o resultado. Isso impede que o programa principal utilize diretamente o valor calculado em outras operações. A implementação futura deverá retornar um int e utilizar return.
* Tamanho do vetor: a função depende de receber um tamanho válido. Um tamanho incorreto pode causar leituras fora dos limites do vetor.

⸻

Exercício 9 — Contar valores acima da média

Arquivo: exercicio9/main.c

1. Qual é o objetivo?

Calcular a média dos valores de um vetor e contar quantos elementos são maiores do que ela.

Imagine uma turma de estudantes. Primeiro, você calcula a média das notas da turma. Depois, conta quantos estudantes obtiveram notas acima dessa média.

O programa segue esse mesmo raciocínio.

2. Conceitos necessários

* Acumuladores.
* Média aritmética.
* Laços for.
* Condicionais if.
* Comparação de valores.
* Divisão inteira e números de ponto flutuante.

A média aritmética é calculada pela soma de todos os valores dividida pela quantidade de elementos:

[
\text{média}=\frac{\text{soma dos valores}}{\text{quantidade de valores}}
]

3. Código original

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

4. Explicação linha a linha

Linha 1 — void mediaQtd(int *v, int N)

Declara a função mediaQtd, que recebe um vetor e seu tamanho.

Linha 2 — int c, media = 0, soma = 0, qtd = 0;

Declara as variáveis necessárias:

* c: contador dos laços.
* media: armazena a média calculada.
* soma: acumula os valores do vetor.
* qtd: conta quantos elementos são maiores que a média.

Os acumuladores começam em zero.

Linhas 4 e 5 — primeiro laço

Como no exercício 1, o for percorre todas as posições do vetor. O bloco soma += v[c] adiciona cada elemento ao acumulador.

Ao terminar o laço, soma contém o total de todos os valores.

Linha 6 — media = soma / N;

Divide a soma pela quantidade de elementos para calcular a média.

Como soma, N e media são inteiros, a divisão inteira descarta a parte decimal do resultado.

Linhas 8 a 10 — segundo laço

O segundo laço percorre novamente o vetor. A condição v[c] > media verifica se o elemento atual é maior do que a média calculada.

Quando a condição é verdadeira, qtd++ aumenta a contagem em uma unidade.

Esse segundo percurso é necessário porque o programa precisa conhecer a média antes de poder identificar quais valores estão acima dela.

Linhas 12 e 13 — exibição

A primeira instrução apresenta a média; a segunda mostra a quantidade de elementos que ficaram acima dela.

O \n na primeira mensagem representa uma quebra de linha.

5. Analogia cotidiana: notas de uma turma

Imagine cinco notas:

[4, 6, 7, 8, 10]

A soma é 35 e a média é 7.

Agora você percorre as notas novamente e conta aquelas estritamente maiores que 7: 8 e 10.

O resultado é 2 valores acima da média.

Observe que uma nota igual à média não entra na contagem, pois a condição é > e não >=.

6. Atenção

* Perda da parte decimal: a média é armazenada em int. Se a média real for, por exemplo, 6,8, o programa armazenará 6. Isso pode fazer com que valores maiores que 6, mas menores que 6,8, sejam contados incorretamente como acima da média. Uma futura correção utilizará double para representar a média.
* Vetor vazio: se N for zero, a instrução media = soma / N realiza uma divisão por zero. Isso pode causar comportamento indefinido. A função deverá validar o tamanho antes de calcular a média.
* Tamanho do vetor: como nos exercícios anteriores, o tamanho informado precisa corresponder à capacidade disponível.

⸻

Exercício 10 — Somar dois vetores

Arquivo: exercicio10/main.c

1. Qual é o objetivo?

Somar dois vetores de mesmo tamanho, posição por posição.

Considere:

Vetor A = [1, 2, 3, 4, 5]

Vetor B = [10, 20, 30, 40, 50]

A soma será:

[11, 22, 33, 44, 55]

O primeiro elemento de A é somado ao primeiro elemento de B, o segundo ao segundo e assim por diante.

2. Código original

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

3. Explicação linha a linha

Linha 1 — void somaVetor(int *v1, int N, int *v2)

Declara a função que recebe dois vetores e a quantidade de elementos que será processada.

* v1 aponta para o primeiro vetor.
* N representa a quantidade de posições.
* v2 aponta para o segundo vetor.

Linha 2 — int c, v[N], valor1, valor2;

Declara:

* c: contador dos laços.
* v[N]: vetor local que armazenará os resultados.
* valor1: recebe temporariamente um elemento de v1.
* valor2: recebe temporariamente um elemento de v2.

O tamanho N é utilizado para criar o vetor de resultados.

Linha 4 — for (c = 0; c < N; c++)

Como no exercício 1, o laço percorre todas as posições, da primeira à última.

Linha 5 — valor1 = v1[c];

Copia o elemento atual do primeiro vetor para valor1.

Linha 6 — valor2 = v2[c];

Copia o elemento da mesma posição do segundo vetor para valor2.

Linha 7 — v[c] = valor1 + valor2;

Soma os dois valores temporários e armazena o resultado na posição correspondente do vetor de saída.

Linha 10 — printf("Soma\n[");

Imprime o título Soma e, em seguida, uma quebra de linha e o colchete de abertura.

Linhas 11 e 12 — segundo laço

Como no exercício 1, o for percorre o vetor. Neste caso, o bloco imprime os valores calculados anteriormente, em vez de realizar novas somas.

Linha 13 — printf("]");

Imprime o colchete de fechamento.

4. Analogia cotidiana: juntar quantidades de dois carrinhos

Imagine dois carrinhos de supermercado. Em ambos existem quantidades de determinados produtos.

Para saber a quantidade total de cada produto, você soma a quantidade do primeiro carrinho à quantidade do segundo. Faz isso para cada posição da lista e anota os resultados em uma terceira lista.

Os dois vetores de entrada são os carrinhos originais; o vetor v é a lista com as quantidades totais.

5. Atenção

* Tamanhos incompatíveis: a função pressupõe que os dois vetores tenham pelo menos N elementos. Se um deles for menor, o acesso às posições inexistentes poderá provocar comportamento indefinido.
* Vetor de tamanho variável: int v[N] declara um vetor de tamanho variável, recurso disponível em determinadas versões e implementações de C, mas não aceito por todos os compiladores e padrões da linguagem. Uma futura correção poderá adaptar a declaração conforme o ambiente de compilação.
* Tamanho inválido: criar um vetor com tamanho zero ou negativo não é uma utilização válida desse recurso. A função deverá validar N antes de criar ou acessar o vetor.

⸻

Considerações finais

Aprender C é muito mais do que memorizar comandos. É entender como os dados são armazenados, como as instruções são executadas e como dividir um problema grande em tarefas menores.

Ao longo destes exercícios, você praticou ideias fundamentais:

* Funções: dividem um programa em tarefas específicas.
* Ponteiros: permitem acessar dados por meio de seus endereços de memória.
* Passagem por referência: possibilita modificar as variáveis originais.
* Vetores: organizam vários valores em uma sequência de posições.
* Laços de repetição: automatizam tarefas que precisam ser realizadas várias vezes.
* Condicionais: permitem tomar decisões com base em determinadas condições.
* Acumuladores: guardam resultados parciais durante cálculos.

Não se preocupe se alguns conceitos parecerem complicados no início. Volte aos exemplos, altere os valores de entrada, desenhe os vetores em papel e acompanhe o que acontece a cada repetição.

Uma boa maneira de aprender é prever o resultado antes de executar o programa e, depois, comparar sua previsão com o resultado real.

Programar é aprender a transformar problemas em passos lógicos. Pratique, experimente e bons estudos!