#include <stdio.h>

int main() {
    int n, m;
    int iguais = 1;

    printf("Digite o número de linhas e colunas das matrizes: ");
    scanf("%d %d", &n, &m);

    int matriz1[n][m], matriz2[n][m];

    printf("Digite os elementos da primeira matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os elementos da segunda matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz1[i][j] != matriz2[i][j]) {
                iguais = 0;
                break;
            }
        }
        if (!iguais) break;
    }

    if (iguais) {
        printf("As matrizes são iguais.\n");
    } else {
        printf("As matrizes são diferentes.\n");
    }

    return 0;
}
