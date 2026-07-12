# Árvore Binária de Busca (BST) em C

Implementação de uma **Árvore Binária de Busca** em C, com inserção feita das duas formas possíveis — recursiva e iterativa —, percurso em ordem e liberação correta da memória alocada.

## Sobre o projeto

O programa monta uma árvore binária de busca inserindo alguns valores, exibe o resultado em ordem crescente e depois desaloca toda a estrutura, demonstrando o ciclo completo de vida da árvore: criação, inserção, percurso e limpeza.

## Conceitos aplicados

- **Alocação dinâmica de memória**: cada nó é criado com `malloc`, com verificação de falha na alocação (`if (novoNo == NULL)`)
- **Ponteiros e structs recursivas**: `No` se referencia a si mesmo através dos ponteiros `esquerda` e `direita`, formando a estrutura da árvore
- **Recursão**: `inserirRecursivo` desce a árvore chamando a si mesma até encontrar a posição vazia (`NULL`), que é o caso base
- **Iteração como alternativa à recursão**: `inserirIterativo` resolve o mesmo problema com um laço `while`, guardando manualmente o ponteiro `pai` para conectar o novo nó — útil para comparar as duas abordagens e discutir o custo de pilha de chamadas
- **Propriedade da BST**: valores menores que o nó vão para a esquerda, maiores vão para a direita, e valores repetidos são ignorados (na versão iterativa)
- **Percurso em-ordem (in-order traversal)**: visita esquerda → raiz → direita, o que naturalmente imprime os valores em ordem crescente — propriedade clássica de BSTs
- **Liberação de memória (`free`) em pós-ordem**: `limparArvore` desce até as folhas antes de liberar cada nó (esquerda → direita → nó atual), evitando acessar memória já liberada

## Como compilar e executar

```bash
gcc arvore_binaria.c -o arvore_binaria
./arvore_binaria
```

Saída esperada: os valores inseridos (`50, 30, 70, 20, 40`) impressos em ordem crescente, seguidos do processo de remoção de cada nó durante a limpeza da árvore.

## Autor

Marco Antônio — Sistemas de Informação, UFPI.
