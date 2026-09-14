## Lista Encadeada em C

Implementação de uma lista encadeada simples de números inteiros em C, com um menu interativo, gerenciamento manual de memória e separação do código em múltiplos arquivos.

### Funcionalidades

* Inserir número no início da lista
* Inserir número no final da lista
* Remover número da lista (buscando pelo valor)
* Listar todos os números armazenados
* Encontrar o maior número
* Encontrar o menor número
* Contar quantos elementos existem na lista

### Conceitos praticados

* Structs auto-referenciadas (`struct No` contendo um ponteiro para `struct No`)
* Ponteiro para ponteiro (`No **inicio`), para permitir que funções alterem o início da lista
* Alocação dinâmica de memória nó a nó (`malloc`/`free`), sem bloco contíguo
* Percurso de estrutura de dados através de ponteiros (`atual = atual->proximo`), sem uso de índices
* Tratamento de casos de borda: lista vazia, remoção do primeiro nó, remoção de nó do meio/fim, valor não encontrado
* Validação de entrada do usuário (`scanf`) e limpeza de buffer

### Estrutura do projeto

```
├── main.c
├── lista.c
├── lista.h
└── README.md
```

* `main.c` — menu interativo com todas as operações disponíveis.
* `lista.c` — implementação das funções que manipulam a lista.
* `lista.h` — definição da struct `No` e declaração das funções.

### Como compilar

**Utilizando o GCC:**
```
gcc main.c lista.c -o lista
```

**Depois, execute o programa:**
```
./lista
```

**No Windows, o executável gerado pode ser executado como:**
```
lista.exe
```

### Lista encadeada vs. array dinâmico

Diferente de um array dinâmico (onde os elementos ficam em um bloco contíguo de memória e crescem via `realloc`), na lista encadeada cada elemento (nó) é alocado individualmente e mantém, além do valor, um ponteiro para o próximo nó. Isso torna a inserção e remoção mais simples em termos de deslocamento de dados (não é necessário mover elementos), ao custo de não permitir acesso direto por índice — para chegar a um elemento, é preciso percorrer a lista a partir do início.

### Sobre o projeto

Este projeto foi desenvolvido como parte dos meus estudos de estruturas de dados em C, com foco em ponteiros, structs auto-referenciadas e gerenciamento manual de memória em uma estrutura dinâmica não contígua.
