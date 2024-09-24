#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "fila.h"

int fila[TAMANHO];
int inicio = 0;
int fim = 0;
bool vazia = true;

// Função para adicionar um elemento à fila
bool adicionar(int valor) {
    // Verifica se a fila está cheia
    if ((fim + 1) % TAMANHO == inicio) {
        return false; // Fila cheia
    }

    // Adiciona o valor à fila e atualiza o fim
    fila[fim] = valor;
    fim = (fim + 1) % TAMANHO;
    vazia = false; // Atualiza o estado da fila para não vazia
    return true; // Retorna verdadeiro para indicar sucesso na adição
}

void gerarSenhaAleatoria() {
    // Inicializa a semente do gerador de números aleatórios com o tempo atual
    srand((unsigned int)time(NULL));

    int senha = rand() % 100;

    // Verifica se a senha gerada já está na fila
    bool senhaJaNaFila = false;
    for (int i = inicio; i != fim; i = (i + 1) % TAMANHO) {
        if (fila[i] == senha) {
            senhaJaNaFila = true;
            break;
        }
    }

    // Se a senha já estiver na fila, gera outra senha recursivamente
    if (senhaJaNaFila) {
        gerarSenhaAleatoria();
    } else {
        // Adiciona a senha à fila e exibe mensagem de sucesso ou falha
        if (!adicionar(senha)) {
            printf("Fila cheia! Nao foi possivel adicionar a senha gerada.\n");
            printf("Atenda a fila para liberar uma nova senha.\n");
            printf("\n");
        } else {
            printf("Senha gerada com sucesso: %d\n", senha);
            printf("\n");
        }
    }
}

// Função para retirar o primeiro elemento da fila
bool esvaziarFila(int *valor) {
    if(vazia) {
        return false; // Fila vazia
    }
    // Retorna o valor do primeiro elemento da fila e atualiza o início
    *valor = fila[inicio];
    inicio = (inicio + 1) % TAMANHO;
    // Verifica se a fila ficou vazia após a retirada
    if(inicio == fim) {
        vazia = true;
    }

    return true;
}