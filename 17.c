#include <stdio.h>

void somaLinhas(int matriz[][3], int linhas, int colunas, int resultado[]) {
    for (int i = 0; i < linhas; i++) {
        resultado[i] = 0;
        for (int j = 0; j < colunas; j++) {
            resultado[i] += matriz[i][j];
        }
    }
}

int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int resultado[3];
    somaLinhas(matriz, 3, 3, resultado);
    for (int i = 0; i < 3; i++) {
        printf("Soma da linha %d: %d\n", i + 1, resultado[i]);
    }
    return 0;
}
