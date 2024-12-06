#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void inserirDados(Aluno alunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\nInsira os dados do aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }
}

void exibirDados(Aluno alunos[], int tamanho) {
    printf("\nDados dos Alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("  Nome: %s\n", alunos[i].nome);
        printf("  Idade: %d\n", alunos[i].idade);
        printf("  Nota: %.2f\n", alunos[i].nota);
    }
}

void encontrarMaiorNota(Aluno alunos[], int tamanho) {
    int indiceMaior = 0;
    for (int i = 1; i < tamanho; i++) {
        if (alunos[i].nota > alunos[indiceMaior].nota) {
            indiceMaior = i;
        }
    }
    printf("\nAluno com a maior nota:\n");
    printf("  Nome: %s\n", alunos[indiceMaior].nome);
    printf("  Idade: %d\n", alunos[indiceMaior].idade);
    printf("  Nota: %.2f\n", alunos[indiceMaior].nota);
}

int main() {
    const int NUM_ALUNOS = 5;
    Aluno alunos[NUM_ALUNOS];

    inserirDados(alunos, NUM_ALUNOS);
    exibirDados(alunos, NUM_ALUNOS);
    encontrarMaiorNota(alunos, NUM_ALUNOS);

    return 0;
}
