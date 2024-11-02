Implementação de Tabela Hash de Endereçamento Aberto
====================================================

Nome da Equipe: Sim
Membros:
- Gabriel Gioia de Brito

O objetivo do trabalho é implementar uma tabela hash de endereçamento aberto
semelhante à Cuckoo Hash que passe nos casos de teste, demonstrando o
conhecimento acerca do assunto.

A implementação possui duas tabelas de 11 posições (m = 11), onde as respectivas
funções hash são:

  h1(k) = k mod m
  h2(k) = piso(m * (k * 0.9 - piso(k * 0.9)))

A estrutura é implementada como biblioteca nos arquivos `ht.h` e `ht.c`. O
arquivo `main.c` apenas consome as funções da biblioteca conforme lê o input de
teste.

A interface pública possui os tipos HashMap, HashEntry e EntryState. EntryState
é um enumerador que pode assumir os valores Empty, Occupied e Excluded.
HashEntry possui um valor inteiro e um valor EntryState. HashMap consiste de
dois vetores de m posições de HashEntry.

As seguintes funções são parte da interface pública da biblioteca:

```
void InitMap(HashMap* map);
void Insert(HashMap* map, int key);
void Remove(HashMap* map, int key);
int* Search(HashMap* map, int key);
void PrintTables(HashMap* map);
```

Search não é utilizada no trabalho, tendo sido implementada por questão de
completude.

A função InitMap deve ser chamada antes da utilização da estrutura (ela apenas
zera os valores para garantir que todas as entradas sejam "Empty"). A função
PrintTables imprime a saída esperada.
