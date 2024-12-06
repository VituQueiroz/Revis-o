#include <stdio.h>

int main() {
    int n, i, valor, encontrado = -1;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    printf("Digite os elementos do vetor: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    for (i = 0; i < n; i++) {
        if (vetor[i] == valor) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Valor encontrado na posição: %d\n", encontrado);
    } else {
        printf("Valor não encontrado.\n");
    }

    return 0;
}
