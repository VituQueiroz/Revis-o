#include <stdio.h>
#define N 3 

int main() {
    int matriz[N][N];
    int simetrica = 1;

    printf("Digite os elementos da matriz %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = 0;
                break;
            }
        }
        if (!simetrica) break;
    }

    if (simetrica) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    return 0;
}
