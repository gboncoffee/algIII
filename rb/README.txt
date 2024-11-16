Implementação de Rubro-Negra
====================

Nome da equipe: Sim
Membros:
- Gabriel Gioia de Brito

O objetivo do trabalho é implementar uma árvore Rubro-Negra cujos elementos são
números inteiros que passe nos casos de teste, demonstrando o conhecimento
acerca do assunto.

A implementação se inspira bastante na implementação do livro Introduction to
Algorithms de Cormen. É uma árvore com cabeça e nulos como sentinela.

A estrutura é implementada como biblioteca nos arquivos `rb.h` e `rb.c`. O
arquivo `main.c` apenas lê o input dos casos de teste e chama as funções da
biblioteca.

A interface pública da biblioteca possui os tipos Node e RBTree. RBTree
representa a árvore em si, e Node são seus nodos.

As seguintes funções são parte da interface pública da biblioteca:

```
void InitRBTree(RBTree* tree);
void Insert(RBTree* tree, int key);
void Delete(RBTree* tree, int key);
void PrintTree(RBTree* tree);
void DeleteTree(RBTree* tree);
```

A função PrintTree imprime a saída esperada, e a função DeleteTree libera a
memória utilizada pela árvore recursivamente.

Em conclusão, o objetivo do trabalho foi alcançado.
