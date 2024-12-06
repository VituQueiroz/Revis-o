#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void imprimirTabuleiro(int tabuleiro[N][N], int x, int y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == x && j == y) {
                printf("J ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[N][N] = {0};
    int jogadorX = 0, jogadorY = 0;
    int pontos = 0;
    char movimento;

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        tabuleiro[rand() % N][rand() % N] = 1;
        tabuleiro[rand() % N][rand() % N] = 2;
    }

    while (pontos < 5) {
        system("clear");
        imprimirTabuleiro(tabuleiro, jogadorX, jogadorY);
        printf("Pontos: %d\n", pontos);
        printf("Movimento do jogador (w/a/s/d para cima, esquerda, baixo, direita, q para sair): ");
        scanf(" %c", &movimento);

        if (movimento == 'q') break;

        int novoX = jogadorX, novoY = jogadorY;
        if (movimento == 'w' && jogadorX > 0) novoX--;
        if (movimento == 's' && jogadorX < N - 1) novoX++;
        if (movimento == 'a' && jogadorY > 0) novoY--;
        if (movimento == 'd' && jogadorY < N - 1) novoY++;

        if (tabuleiro[novoX][novoY] == 1) pontos++;
        if (tabuleiro[novoX][novoY] == 2) pontos--;
        tabuleiro[novoX][novoY] = 0;

        jogadorX = novoX;
        jogadorY = novoY;
    }

    system("clear");
    imprimirTabuleiro(tabuleiro, jogadorX, jogadorY);
    printf("Fim do jogo. Pontos finais: %d\n", pontos);

    return 0;
}
