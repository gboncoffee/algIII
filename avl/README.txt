Implementação de AVL
====================

Nome da equipe: Sim
Membros:
- Gabriel Gioia de Brito

O objetivo do trabalho é implementar uma árvore AVL cujos elementos são números
inteiros que passe nos casos de teste, demonstrando o conhecimento acerca do
assunto.

A implementação é uma árvore AVL com nodos sem ponteiro para o pai, e a remoção
substitui o nodo pelo sucessor caso o nodo removido tenha filho direito, e o
antecessor caso contrário.

A estrutura é implementada como biblioteca nos arquivos `avl.h` e `avl.c`. O
arquivo `main.c` apenas lê o input dos casos de teste e chama as funções da
biblioteca.

A interface pública da biblioteca possui o tipo Node. Ponteiros para Node são
utilizados para manipular a árvore.

As seguintes funções são parte da interface pública da biblioteca:

```
Node* Insert(Node* tree, int key);
Node* Remove(Node* tree, int key);
void  PrintInOrderWithHeights(Node* tree, int height);
void  DeleteTree(Node* tree);
```

As funções `Insert` e `Remove` retornam a nova raíz da árvore. Perceba que uma
árvore vazia é o ponteiro nulo, portanto para criar o primeiro nodo, basta
chamar `Node *node = Insert(NULL, x);`.

A função PrintInOrderWithHeights imprime a saída esperada, e a função DeleteTree
libera a memória utilizada pela árvore recursivamente.

