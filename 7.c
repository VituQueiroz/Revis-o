#include <stdio.h>

int main() {
    int n;

    printf("Digite o valor de N (dimensão da matriz NxN): ");
    scanf("%d", &n);

    int matriz[n][n];
    int vetor[n * n];
    int k = 0;

    printf("Digite os elementos da matriz %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            vetor[k++] = matriz[i][j];
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = vetor[k++];
        }
    }

    printf("Matriz ordenada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
