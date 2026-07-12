#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA DO NÓ
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// FUNÇÃO PARA CRIAR UM NOVO NÓ
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// INSERÇÃO RECURSIVA
No* inserirRecursivo(No* raiz, int valor) {
    // Caso Base: achou a vaga vazia, cria e retorna o nó
    if (raiz == NULL) {
        return criarNo(valor);
    }
    
    // Passo Recursivo: navega para a esquerda ou direita
    if (valor < raiz->valor) {
        raiz->esquerda = inserirRecursivo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserirRecursivo(raiz->direita, valor);
    }
    
    return raiz; 
}

// INSERÇÃO ITERATIVA
No* inserirIterativo(No* raiz, int valor) {
    No* atual = raiz;
    No* pai = NULL;

    // Navega com o laço while até achar o espaço NULL
    while (atual != NULL) {
        pai = atual; // Guarda a referência do pai antes de descer
        if (valor < atual->valor) {
            atual = atual->esquerda;
        } else if (valor > atual->valor) {
            atual = atual->direita;
        } else {
            return raiz; // Valor já existe na árvore, não faz nada
        }
    }

    // Cria o nó e o conecta no pai correto
    No* novoNo = criarNo(valor);
    if (pai == NULL) {
        return novoNo; // A árvore estava vazia, o novo nó se torna a raiz
    }

    if (valor < pai->valor) {
        pai->esquerda = novoNo;
    } else {
        pai->direita = novoNo;
    }

    return raiz;
}

// FUNÇÃO DE IMPRESSÃO
// Em-Ordem: Esquerda -> Raiz -> Direita (Imprime os números ordenados)
void exibirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->direita);
    }
}

// FUNÇÃO PARA LIMPAR A ÁRVORE 
void limparArvore(No* raiz) {
    if (raiz == NULL) return;

    // Primeiro, limpa de forma recursiva as subárvores
    limparArvore(raiz->esquerda);
    limparArvore(raiz->direita);
    
    printf("Deletando nó: %d\n", raiz->valor); //apenas para demonstrar o free rodando
    free(raiz);
}


int main() {
    No* raiz = NULL;

    printf("Inserindo elementos na Árvore...\n");

    raiz = inserirRecursivo(raiz, 50);
    raiz = inserirRecursivo(raiz, 30);
    raiz = inserirRecursivo(raiz, 70);
    
    raiz = inserirIterativo(raiz, 20);
    raiz = inserirIterativo(raiz, 40);

    printf("\nExibindo os elementos da Árvore em ordem crescente:\n");
    exibirEmOrdem(raiz);
    printf("\n\n");

    printf("Limpando a memória da Árvore: \n");
    limparArvore(raiz);
    raiz = NULL; 

    printf("\nÁrvore limpa com sucesso!\n");
    return 0;
}
