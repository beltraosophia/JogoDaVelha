#include <stdio.h>
#include "Tabuleiro.h"

void inicializaTabuleiro(Tabuleiro *tabuleiro) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            tabuleiro->M[linha][coluna] = 0;
        }
    }
}

void desenha(Tabuleiro *tabuleiro) {
    printf("\033[2J\033[H");

    printf("\n      0   1   2  (colunas)\n");
    printf("    -------------\n");
    for (int linha = 0; linha < 3; linha++) {
        printf(" %d  |", linha);
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro->M[linha][coluna] == 1) {
                printf(" O |");
            } else if (tabuleiro->M[linha][coluna] == 4) {
                printf(" X |");
            } else {
                printf("   |");
            }
        }
        printf("\n    -------------\n");
    }
    printf("\n");
}

void marcaJogada(Tabuleiro *tabuleiro, int x, int y, int tipo) {
    tabuleiro->M[x][y] = tipo;
}

int temVencedor(Tabuleiro *tabuleiro) {
    int soma;

    for (int i = 0; i < 3; i++) {
        soma = tabuleiro->M[i][0] + tabuleiro->M[i][1] + tabuleiro->M[i][2];
        if (soma == 3) return 1;
        if (soma == 12) return 4;
    }

    for (int j = 0; j < 3; j++) {
        soma = tabuleiro->M[0][j] + tabuleiro->M[1][j] + tabuleiro->M[2][j];
        if (soma == 3) return 1;
        if (soma == 12) return 4;
    }

    soma = tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2];
    if (soma == 3) return 1;
    if (soma == 12) return 4;

    soma = tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0];
    if (soma == 3) return 1;
    if (soma == 12) return 4;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[i][j] == 0) {
                return -1;
            }
        }
    }

    return 0;
}
