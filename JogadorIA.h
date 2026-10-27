#ifndef JOGADORIA_H
#define JOGADORIA_H

#include "Tabuleiro.h"

typedef struct {
    int tipo;
} JogadorIA;

void jogaIA(JogadorIA *ia, Tabuleiro *tabuleiro);

#endif

