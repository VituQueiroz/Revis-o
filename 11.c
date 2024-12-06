#include <stdio.h>

int main() {
    int tabuleiro[5][5] = {0};
    int palpiteX, palpiteY;
    int navioX = 2, navioY = 3;
    int tentativas = 2;
    int acertou = 0;

    tabuleiro[navioX][navioY] = 1;

    while (tentativas > 0 && !acertou) {
        printf("Linha (0-4): ");
        scanf("%d", &palpiteX);
        printf("Coluna (0-4): ");
        scanf("%d", &palpiteY);

        if (palpiteX < 0 || palpiteX > 4 || palpiteY < 0 || palpiteY > 4) {
            printf("Posição inválida.\n");
            continue;
        }

        if (tabuleiro[palpiteX][palpiteY] == 1) {
            printf("Acertou!\n");
            acertou = 1;
        } else {
            tentativas--;
            printf("Errou! Tentativas restantes: %d\n", tentativas);
        }
    }

    if (!acertou) {
        printf("Você perdeu! O navio estava na posição (%d, %d).\n", navioX, navioY);
    }

    return 0;
}
