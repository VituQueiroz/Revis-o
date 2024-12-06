#include <stdio.h>

void exibirPares(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6};
    exibirPares(vetor, 6);
    return 0;
}
