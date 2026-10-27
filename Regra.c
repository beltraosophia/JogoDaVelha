#include "Regra.h"

int aplicaRegra1(Tabuleiro *tabuleiro, int meuTipo) {
    int oponente = (meuTipo == 1) ? 4 : 1;
    int alvos[2];
    
    alvos[0] = (meuTipo == 1) ? 2 : 8;
    alvos[1] = (oponente == 1) ? 2 : 8;

    for (int k = 0; k < 2; k++) {
        int somaDesejada = alvos[k];

        for (int i = 0; i < 3; i++) {
            if (tabuleiro->M[i][0] + tabuleiro->M[i][1] + tabuleiro->M[i][2] == somaDesejada) {
                for (int j = 0; j < 3; j++) {
                    if (tabuleiro->M[i][j] == 0) {
                        marcaJogada(tabuleiro, i, j, meuTipo);
                        return 1;
                    }
                }
            }
        }

        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[0][j] + tabuleiro->M[1][j] + tabuleiro->M[2][j] == somaDesejada) {
                for (int i = 0; i < 3; i++) {
                    if (tabuleiro->M[i][j] == 0) {
                        marcaJogada(tabuleiro, i, j, meuTipo);
                        return 1;
                    }
                }
            }
        }

        if (tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2] == somaDesejada) {
            for (int i = 0; i < 3; i++) {
                if (tabuleiro->M[i][i] == 0) {
                    marcaJogada(tabuleiro, i, i, meuTipo);
                    return 1;
                }
            }
        }

        if (tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0] == somaDesejada) {
            if (tabuleiro->M[0][2] == 0) { marcaJogada(tabuleiro, 0, 2, meuTipo); return 1; }
            if (tabuleiro->M[1][1] == 0) { marcaJogada(tabuleiro, 1, 1, meuTipo); return 1; }
            if (tabuleiro->M[2][0] == 0) { marcaJogada(tabuleiro, 2, 0, meuTipo); return 1; }
        }
    }

    return 0;
}

int aplicaRegra2(Tabuleiro *tabuleiro, int meuTipo) {
    int alvo = (meuTipo == 1) ? 2 : 8;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[i][j] == 0) {
                tabuleiro->M[i][j] = meuTipo;
                int sequenciasCriadas = 0;

                for (int l = 0; l < 3; l++) {
                    if (tabuleiro->M[l][0] + tabuleiro->M[l][1] + tabuleiro->M[l][2] == alvo) sequenciasCriadas++;
                    if (tabuleiro->M[0][l] + tabuleiro->M[1][l] + tabuleiro->M[2][l] == alvo) sequenciasCriadas++;
                }
                if (tabuleiro->M[0][0] + tabuleiro->M[1][1] + tabuleiro->M[2][2] == alvo) sequenciasCriadas++;
                if (tabuleiro->M[0][2] + tabuleiro->M[1][1] + tabuleiro->M[2][0] == alvo) sequenciasCriadas++;

                tabuleiro->M[i][j] = 0;

                if (sequenciasCriadas >= 2) {
                    marcaJogada(tabuleiro, i, j, meuTipo);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int aplicaRegra3(Tabuleiro *tabuleiro, int meuTipo) {
    if (tabuleiro->M[1][1] == 0) {
        marcaJogada(tabuleiro, 1, 1, meuTipo);
        return 1;
    }
    return 0;
}

int aplicaRegra4(Tabuleiro *tabuleiro, int meuTipo) {
    int oponente = (meuTipo == 1) ? 4 : 1;

    if (tabuleiro->M[0][0] == oponente && tabuleiro->M[2][2] == 0) {
        marcaJogada(tabuleiro, 2, 2, meuTipo);
        return 1;
    }
    if (tabuleiro->M[2][2] == oponente && tabuleiro->M[0][0] == 0) {
        marcaJogada(tabuleiro, 0, 0, meuTipo);
        return 1;
    }
    if (tabuleiro->M[0][2] == oponente && tabuleiro->M[2][0] == 0) {
        marcaJogada(tabuleiro, 2, 0, meuTipo);
        return 1;
    }
    if (tabuleiro->M[2][0] == oponente && tabuleiro->M[0][2] == 0) {
        marcaJogada(tabuleiro, 0, 2, meuTipo);
        return 1;
    }
    return 0;
}

int aplicaRegra5(Tabuleiro *tabuleiro, int meuTipo) {
    int cantos[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};

    for (int k = 0; k < 4; k++) {
        int linha = cantos[k][0];
        int coluna = cantos[k][1];
        if (tabuleiro->M[linha][coluna] == 0) {
            marcaJogada(tabuleiro, linha, coluna, meuTipo);
            return 1;
        }
    }
    return 0;
}

int aplicaRegra6(Tabuleiro *tabuleiro, int meuTipo) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro->M[i][j] == 0) {
                marcaJogada(tabuleiro, i, j, meuTipo);
                return 1;
            }
        }
    }
    return 0;
}
