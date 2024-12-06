#include <stdio.h>

int main() {
    int n, i, acimaDaMedia = 0;
    float soma = 0, media;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    printf("Digite os elementos do vetor: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / n;

    for (i = 0; i < n; i++) {
        if (vetor[i] > media) {
            acimaDaMedia++;
        }
    }

    printf("Media: %.2f\n", media);
    printf("Valores acima da media: %d\n", acimaDaMedia);

    return 0;
}
