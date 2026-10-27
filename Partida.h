#ifndef PARTIDA_H
#define PARTIDA_H

#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "JogadorIA.h"

typedef struct {
    Tabuleiro tabuleiro;
    JogadorTeclado jogador1;
    JogadorTeclado jogador2;
    JogadorIA ia;
    int modoJogo;
} Partida;

void configuraJogadores(Partida *partida);
void inicia(Partida *partida);

#endif
