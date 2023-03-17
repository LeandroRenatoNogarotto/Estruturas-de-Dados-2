#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um n� da �rvore bin�ria de busca
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Fun��o para inserir um valor na �rvore bin�ria de busca
No* inserir(No* raiz, int valor) {
    // Caso base: se a �rvore estiver vazia, cria um novo n� com o valor
    if (raiz == NULL) {
        No* novoNo = (No*) malloc(sizeof(No));
        novoNo->valor = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }
    // Caso contr�rio, insere o valor na sub�rvore esquerda ou direita, de acordo com sua rela��o com a raiz
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Fun��o para realizar uma busca na �rvore bin�ria de busca
No* buscar(No* raiz, int valor) {
    // Caso base: se a raiz for nula, o valor n�o existe na �rvore
    if (raiz == NULL) {
        return NULL;
    }
    // Se o valor for igual ao valor da raiz, retorna a raiz
    if (valor == raiz->valor) {
        return raiz;
    }
    // Caso contr�rio, realiza a busca na sub�rvore esquerda ou direita, de acordo com a rela��o do valor com a raiz
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

int main() {
    int i;

    // Cria uma �rvore bin�ria de busca e insere os n�meros de 0 a 99999 em ordem
    No* raiz = NULL;
    for (i = 0; i < 100000; i++) {
        raiz = inserir(raiz, i);
    }

    // Faz a busca pelo n�mero 100000, que n�o existe na �rvore
    int valorBuscado = 100000;
    clock_t inicio = clock();
    No* noEncontrado = buscar(raiz, valorBuscado);
    clock_t fim = clock();

    // Verifica se o valor foi encontrado e exibe o tempo de busca em segundos
    if (noEncontrado == NULL) {
        printf("O valor %d n�o foi encontrado na �rvore.\n", valorBuscado);
    } else {
        printf("O valor %d foi encontrado na �rvore.\n", valorBuscado);
    }
    printf("Tempo de busca: %.2f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}
