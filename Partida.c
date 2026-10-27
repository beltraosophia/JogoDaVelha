#include <stdio.h>
#include "Partida.h"

void configuraJogadores(Partida *partida) {
    inicializaTabuleiro(&partida->tabuleiro);

    printf("=== JOGO DA VELHA ===\n");
    printf("1 - Humano vs Humano\n");
    printf("2 - Humano vs Computador (IA)\n");
    printf("Escolha o modo: ");
    scanf("%d", &partida->modoJogo);

    partida->jogador1.tipo = 4;

    if (partida->modoJogo == 1) {
        partida->jogador2.tipo = 1;
    } else {
        partida->ia.tipo = 1;
    }
}

void inicia(Partida *partida) {
    int resultado = -1;
    int turno = 1;

    while (resultado == -1) {
        desenha(&partida->tabuleiro);

        if (turno == 1) {
            jogaTeclado(&partida->jogador1, &partida->tabuleiro);
            turno = 2;
        } else {
            if (partida->modoJogo == 1) {
                jogaTeclado(&partida->jogador2, &partida->tabuleiro);
            } else {
                jogaIA(&partida->ia, &partida->tabuleiro);
            }
            turno = 1;
        }

        resultado = temVencedor(&partida->tabuleiro);
    }

    desenha(&partida->tabuleiro);

    if (resultado == 4) {
        printf("Fim de jogo: Jogador X venceu!\n");
    } else if (resultado == 1) {
        if (partida->modoJogo == 2) {
            printf("Fim de jogo: Computador (O) venceu!\n");
        } else {
            printf("Fim de jogo: Jogador O venceu!\n");
        }
    } else if (resultado == 0) {
        printf("Fim de jogo: Empate!\n");
    }
}
