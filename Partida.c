#include <stdio.h>
#include "Partida.h"

void configuraJogadores(Partida *partida) {
    inicializaTabuleiro(&partida->tabuleiro);
    partida->jogador1.tipo = 4;
    partida->jogador2.tipo = 1;
}

void inicia(Partida *partida) {
    int resultado = -1;
    int turno = 1;

    while (resultado == -1) {
        desenha(&partida->tabuleiro);

        if (turno == 1) {
            joga(&partida->jogador1, &partida->tabuleiro);
            turno = 2;
        } else {
            joga(&partida->jogador2, &partida->tabuleiro);
            turno = 1;
        }

        resultado = temVencedor(&partida->tabuleiro);
    }

    desenha(&partida->tabuleiro);

    if (resultado == 4) {
        printf("Jogador X venceu!\n");
    } else if (resultado == 1) {
        printf("Jogador O venceu!\n");
    } else if (resultado == 0) {
        printf("Empate!\n");
    }
}
