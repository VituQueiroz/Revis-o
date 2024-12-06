#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    float valor;
} StructExemplo;

void salvarCSV(StructExemplo dados[], int tamanho, char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo) {
        for (int i = 0; i < tamanho; i++) {
            fprintf(arquivo, "%d,%s,%.2f\n", dados[i].id, dados[i].nome, dados[i].valor);
        }
        fclose(arquivo);
    }
}

int main() {
    StructExemplo dados[] = {
        {1, "Item1", 10.5},
        {2, "Item2", 20.0},
        {3, "Item3", 30.75}
    };
    salvarCSV(dados, 3, "dados.csv");
    return 0;
}
