#include <stdio.h>
#include "JogadorTeclado.h"

void jogaTeclado(JogadorTeclado *jogador, Tabuleiro *tabuleiro) {
    int linha, coluna;
    int jogadaValida = 0;

    char simbolo = (jogador->tipo == 1) ? 'O' : 'X';

    while (jogadaValida == 0) {
        printf("Turno do Jogador [%c]\n", simbolo);
        printf("Digite a linha (0, 1 ou 2): ");
        scanf("%d", &linha);
        printf("Digite a coluna (0, 1 ou 2): ");
        scanf("%d", &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Posicao invalida! Tente valores entre 0 e 2.\n");
        } 
        else if (tabuleiro->M[linha][coluna] != 0) {
            printf("Essa casa ja esta ocupada! Escolha outra.\n");
        } 
        else {
            marcaJogada(tabuleiro, linha, coluna, jogador->tipo);
            jogadaValida = 1;
        }
    }
}
