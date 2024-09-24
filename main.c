#include <stdio.h>

#include "fila.h"
#include "fila.c"

enum {
    OP_NAO_SELECIONADA = 0,
    OP_RETIRAR_SENHA,
    OP_ATENDER_FILA,
    OP_SAIR
};

int menu();

int main() {
    int opcao = OP_NAO_SELECIONADA;
    int numero = 0;

    while(opcao != OP_SAIR) {
        // Exibe o menu e obtém a opção do usuário
        opcao = menu();

        switch (opcao) {
            case OP_ATENDER_FILA:
                if(esvaziarFila(&numero)) {
                    printf("%d retirado da fila.\n", numero);
                    printf("\n");
                } else {
                    printf("Fila vazia!\n");
                    printf("\n");
                }
                break;
            case OP_RETIRAR_SENHA:
                gerarSenhaAleatoria();
                break;
            case OP_SAIR:
                break;
            default:
                printf("OPCAO INVALIDA!\n");
                printf("\n");
        }
    }

    return 0;
}

// Função para exibir o menu e obter a opção do usuário
int menu() {
    int op = OP_NAO_SELECIONADA;

    printf("***** Menu *****\n");
    printf("%d - Retirar senha\n", OP_RETIRAR_SENHA);
    printf("%d - Atender a fila\n", OP_ATENDER_FILA);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    printf("\n");

    return op;
}
