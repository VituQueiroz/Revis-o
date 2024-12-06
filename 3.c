#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void adicionarProduto(Produto produtos[], int *quantidadeAtual, int maximo) {
    if (*quantidadeAtual >= maximo) {
        printf("\nLimite de produtos atingido.\n");
        return;
    }

    printf("\nInsira os dados do produto:\n");
    printf("Nome: ");
    scanf(" %49[^\n]", produtos[*quantidadeAtual].nome);
    printf("Preço: ");
    scanf("%f", &produtos[*quantidadeAtual].preco);
    printf("Quantidade: ");
    scanf("%d", &produtos[*quantidadeAtual].quantidade);

    (*quantidadeAtual)++;
    printf("Produto adicionado com sucesso!\n");
}

void listarProdutos(Produto produtos[], int quantidadeAtual) {
    if (quantidadeAtual == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de produtos:\n");
    for (int i = 0; i < quantidadeAtual; i++) {
        printf("Produto %d:\n", i + 1);
        printf("  Nome: %s\n", produtos[i].nome);
        printf("  Preço: %.2f\n", produtos[i].preco);
        printf("  Quantidade: %d\n", produtos[i].quantidade);
    }
}

void buscarProduto(Produto produtos[], int quantidadeAtual) {
    if (quantidadeAtual == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    char nomeBusca[50];
    printf("\nDigite o nome do produto que deseja buscar: ");
    scanf(" %49[^\n]", nomeBusca);

    for (int i = 0; i < quantidadeAtual; i++) {
        if (strcmp(produtos[i].nome, nomeBusca) == 0) {
            printf("\nProduto encontrado:\n");
            printf("  Nome: %s\n", produtos[i].nome);
            printf("  Preço: %.2f\n", produtos[i].preco);
            printf("  Quantidade: %d\n", produtos[i].quantidade);
            return;
        }
    }

    printf("\nProduto não encontrado.\n");
}

void salvarEmCSV(Produto produtos[], int quantidadeAtual) {
    if (quantidadeAtual == 0) {
        printf("\nNenhum produto para salvar.\n");
        return;
    }

    char nomeArquivo[100];
    printf("\nDigite o nome do arquivo CSV para salvar: ");
    scanf(" %99[^\n]", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome,Preco,Quantidade\n");
    for (int i = 0; i < quantidadeAtual; i++) {
        fprintf(arquivo, "%s,%.2f,%d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em %s\n", nomeArquivo);
}

int main() {
    const int MAX_PRODUTOS = 100;
    Produto produtos[MAX_PRODUTOS];
    int quantidadeAtual = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Buscar produto pelo nome\n");
        printf("4. Salvar em arquivo CSV\n");
        printf("5. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(produtos, &quantidadeAtual, MAX_PRODUTOS);
                break;
            case 2:
                listarProdutos(produtos, quantidadeAtual);
                break;
            case 3:
                buscarProduto(produtos, quantidadeAtual);
                break;
            case 4:
                salvarEmCSV(produtos, quantidadeAtual);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
