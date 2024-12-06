#include <stdio.h>
#define APARTAMENTOS_POR_ANDAR 4

void alterarEstadoPortas(int andares, int portas[andares][APARTAMENTOS_POR_ANDAR]) {
    for (int i = 0; i < andares; i++) {
        for (int j = 0; j < APARTAMENTOS_POR_ANDAR; j++) {
            if ((i * APARTAMENTOS_POR_ANDAR + j + 1) % 2 == 0) {
                portas[i][j] = 1; // Abre a porta
            } else {
                portas[i][j] = 0; // Fecha a porta
            }
        }
    }
}

void apresentarEstadoPortas(int andares, int portas[andares][APARTAMENTOS_POR_ANDAR]) {
    for (int i = 0; i < andares; i++) {
        printf("Andar %d:\n", i + 1);
        for (int j = 0; j < APARTAMENTOS_POR_ANDAR; j++) {
            printf("  Apartamento %d: %s\n", j + 1, portas[i][j] ? "Aberta" : "Fechada");
        }
    }
}

int main() {
    int andares;

    printf("Digite o número de andares do prédio: ");
    scanf("%d", &andares);

    int portas[andares][APARTAMENTOS_POR_ANDAR];

    alterarEstadoPortas(andares, portas);
    apresentarEstadoPortas(andares, portas);

    return 0;
}
