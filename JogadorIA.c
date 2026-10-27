#include <stdio.h>
#include "JogadorIA.h"
#include "Regra.h"

void jogaIA(JogadorIA *ia, Tabuleiro *tabuleiro) {
    printf("Computador pensando...\n");

    if (aplicaRegra1(tabuleiro, ia->tipo)) return;
    if (aplicaRegra2(tabuleiro, ia->tipo)) return;
    if (aplicaRegra3(tabuleiro, ia->tipo)) return;
    if (aplicaRegra4(tabuleiro, ia->tipo)) return;
    if (aplicaRegra5(tabuleiro, ia->tipo)) return;
    aplicaRegra6(tabuleiro, ia->tipo);
}

