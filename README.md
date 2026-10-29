# Jogo da Velha em C

Projeto prático desenvolvido para a disciplina de **Programação Estruturada**.

## Estrutura de Arquivos
```
JogoDaVelha/
├── Partida.h
├── Partida.c
├── Tabuleiro.h
├── Tabuleiro.c
├── JogadorTeclado.h
├── JogadorTeclado.c
├── JogadorIA.h
├── JogadorIA.c
├── Regra.h
├── Regra.c
├── JogadorRemoto.h
├── JogadorRemoto.c
├── Socket.h
├── Socket.c
├── ServerSocket.h
├── ServerSocket.c
├── main.c
└── README.md
```

## Modos de Jogo

1. **Jogador vs Jogador:** Dois competidores humanos alternam comandos no mesmo teclado.
2. **Humano vs Computador (IA):** O jogador enfrenta um sistema especialista autônomo baseado em regras.
3. **Multiplayer em Rede (TCP/IP):** Dois processos comunicam-se via sockets (um atuando como servidor e outro como cliente).

## Regras do Jogo e Representação de Dados

### Mapeamento do Tabuleiro
O tabuleiro $3 \times 3$ é representado por uma matriz de inteiros `int M[3][3]`:

| Valor | Significado | Símbolo Visual |
| :---: | :--- | :---: |
| `0` | Posição vazia | Espaço em branco |
| `1` | Jogador 1 | `O` |
| `4` | Jogador 2 | `X` |

### Condição de Vitória e Empate
A validação de vitória ocorre somando as três linhas, as três colunas e as duas diagonais:
* **Soma = 3:** Vitória imediata do jogador `O` ($1 + 1 + 1$).
* **Soma = 12:** Vitória imediata do jogador `X` ($4 + 4 + 4$).
* **9 jogadas realizadas sem soma 3 ou 12:** Empate (*Velha*).

### Regras da IA

A IA testa as regras na seguinte ordem:
| Regra | Descrição |
| :---: | :--- |
| **R1** | Se você ou seu oponente tiver duas marcações em sequência, marque o quadrado restante. |
| **R2** | Se houver uma jogada que crie duas sequências de duas marcações, use-a. |
| **R3** | Se o quadrado central estiver livre, marque-o. |
| **R4** | Se seu oponente tiver marcado um dos cantos, marque o canto oposto. |
| **R5** | Se houver um canto vazio, marque-o. |
| **R6** | Marque arbitrariamente um quadrado vazio. |


## Compilação e Execução
```bash
gcc -Wall -Wextra main.c Tabuleiro.c JogadorTeclado.c JogadorIA.c Regra.c Partida.c -o jogodavelha
./jogodavelha
``` 
