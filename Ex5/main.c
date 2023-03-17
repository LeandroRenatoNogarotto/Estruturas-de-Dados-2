#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um nó da árvore binária de busca
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para inserir um valor na árvore binária de busca
No* inserir(No* raiz, int valor) {
    // Caso base: se a árvore estiver vazia, cria um novo nó com o valor
    if (raiz == NULL) {
        No* novoNo = (No*) malloc(sizeof(No));
        novoNo->valor = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }
    // Caso contrário, insere o valor na subárvore esquerda ou direita, de acordo com sua relação com a raiz
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Função para realizar uma busca na árvore binária de busca
No* buscar(No* raiz, int valor) {
    // Caso base: se a raiz for nula, o valor não existe na árvore
    if (raiz == NULL) {
        return NULL;
    }
    // Se o valor for igual ao valor da raiz, retorna a raiz
    if (valor == raiz->valor) {
        return raiz;
    }
    // Caso contrário, realiza a busca na subárvore esquerda ou direita, de acordo com a relação do valor com a raiz
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

int main() {
    int i;

    // Cria uma árvore binária de busca e insere os números de 0 a 99999 em ordem
    No* raiz = NULL;
    for (i = 0; i < 100000; i++) {
        raiz = inserir(raiz, i);
    }

    // Faz a busca pelo número 100000, que não existe na árvore
    int valorBuscado = 100000;
    clock_t inicio = clock();
    No* noEncontrado = buscar(raiz, valorBuscado);
    clock_t fim = clock();

    // Verifica se o valor foi encontrado e exibe o tempo de busca em segundos
    if (noEncontrado == NULL) {
        printf("O valor %d não foi encontrado na árvore.\n", valorBuscado);
    } else {
        printf("O valor %d foi encontrado na árvore.\n", valorBuscado);
    }
    printf("Tempo de busca: %.2f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}
