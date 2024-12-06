#include <stdio.h>

int somaRecursiva(int n) {
    int num;
    if (n == 0) return 0;
    scanf("%d", &num);
    return num + somaRecursiva(n - 1);
}

int main() {
    printf("Digite 10 numeros:\n");
    int resultado = somaRecursiva(10);
    printf("A soma é: %d\n", resultado);
    return 0;
}
