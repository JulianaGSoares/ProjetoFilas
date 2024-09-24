#ifndef FILA_FILA_H
#define FILA_FILA_H

#include <stdio.h>
#include <stdbool.h>

// Definição do tamanho máximo da fila
enum {
    TAMANHO = 5,
};

// Declaração da fila, seu início, fim e estado de vazia
extern int fila[TAMANHO]; // Array para armazenar os elementos da fila
extern int inicio;
extern int fim;
extern bool vazia;

bool adicionar(int valor);
void gerarSenhaAleatoria();
bool esvaziarFila(int *valor);

#endif 