#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char email[50];
} Cliente;

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
int totalClientes = 0;
int totalProdutos = 0;

void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) return;
    printf("ID do cliente: ");
    scanf("%d", &clientes[totalClientes].id);
    printf("Nome do cliente: ");
    scanf(" %[^\n]", clientes[totalClientes].nome);
    printf("Email do cliente: ");
    scanf(" %[^\n]", clientes[totalClientes].email);
    totalClientes++;
}

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) return;
    printf("ID do produto: ");
    scanf("%d", &produtos[totalProdutos].id);
    printf("Nome do produto: ");
    scanf(" %[^\n]", produtos[totalProdutos].nome);
    printf("Preço do produto: ");
    scanf("%f", &produtos[totalProdutos].preco);
    totalProdutos++;
}

void listarClientes() {
    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d, Nome: %s, Email: %s\n", clientes[i].id, clientes[i].nome, clientes[i].email);
    }
}

void listarProdutos() {
    for (int i = 0; i < totalProdutos; i++) {
        printf("ID: %d, Nome: %s, Preço: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
}

void salvarDados() {
    FILE *arquivo = fopen("dados.txt", "w");
    if (!arquivo) return;
    fprintf(arquivo, "Clientes:\n");
    for (int i = 0; i < totalClientes; i++) {
        fprintf(arquivo, "%d,%s,%s\n", clientes[i].id, clientes[i].nome, clientes[i].email);
    }
    fprintf(arquivo, "Produtos:\n");
    for (int i = 0; i < totalProdutos; i++) {
        fprintf(arquivo, "%d,%s,%.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
    fclose(arquivo);
}

int main() {
    int opcao;
    do {
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Produto\n");
        printf("3. Listar Clientes\n");
        printf("4. Listar Produtos\n");
        printf("5. Salvar e Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) cadastrarCliente();
        else if (opcao == 2) cadastrarProduto();
        else if (opcao == 3) listarClientes();
        else if (opcao == 4) listarProdutos();
    } while (opcao != 5);

    salvarDados();
    return 0;
}
