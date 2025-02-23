#include <stdio.h>

// Estrutura para representar um item de venda
typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

// Função para exibir o menu de categorias
void exibirMenuPrincipal() {
    printf("\nMenu Principal\n");
    printf("1. Material de Limpeza\n");
    printf("2. Venda de Alimentos\n");
    printf("3. Padaria\n");
    printf("4. Pagamento\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

// Função para exibir os produtos de uma categoria
void exibirProdutos(Produto produtos[], int tamanho) {
    printf("\nCódigo - Nome do Item - Valor (Unidade)\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d - %s - R$%.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
    printf("0 - Voltar ao Menu Principal\n");
}

// Função para processar compras
float processarCompra(Produto produtos[], int tamanho) {
    int codigo, quantidade;
    float total = 0;
    while (1) {
        exibirProdutos(produtos, tamanho);
        printf("Digite o código do item ou 0 para voltar: ");
        scanf("%d", &codigo);
        if (codigo == 0) break;
        for (int i = 0; i < tamanho; i++) {
            if (produtos[i].codigo == codigo) {
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total += produtos[i].preco * quantidade;
                printf("Total acumulado: R$%.2f\n", total);
            }
        }
    }
    return total;
}

// Função para processar o pagamento
void processarPagamento(float totalMaterial, float totalAlimentos, float totalPadaria) {
    float totalGeral = totalMaterial + totalAlimentos + totalPadaria;
    float desconto = 0;
    int metodo;
    printf("\nResumo da Compra:\n");
    printf("Material de Limpeza: R$%.2f\n", totalMaterial);
    printf("Alimentos: R$%.2f\n", totalAlimentos);
    printf("Padaria: R$%.2f\n", totalPadaria);
    printf("Total Geral: R$%.2f\n", totalGeral);
    
    printf("Forma de pagamento:\n1 - Dinheiro\n2 - Cartão\nEscolha: ");
    scanf("%d", &metodo);
    
    if (metodo == 1) {
        if (totalGeral <= 50) desconto = totalGeral * 0.05;
        else if (totalGeral < 100) desconto = totalGeral * 0.10;
        else desconto = totalGeral * 0.18;
        totalGeral -= desconto;
        printf("Desconto aplicado: R$%.2f\n", desconto);
        printf("Total com desconto: R$%.2f\n", totalGeral);
        float recebido;
        printf("Valor recebido: R$");
        scanf("%f", &recebido);
        printf("Troco: R$%.2f\n", recebido - totalGeral);
    } else {
        int status;
        printf("Pagamento na máquina (1 - Ok / 0 - Falhou): ");
        scanf("%d", &status);
        if (status == 0) {
            printf("Pagamento falhou. Escolha outra forma de pagamento.\n");
            processarPagamento(totalMaterial, totalAlimentos, totalPadaria);
        }
    }
    printf("Pagamento concluído!\n");
}

int main() {
    Produto materialDeLimpeza[] = {{11, "Detergente", 1.99}, {12, "Sabão em Pó", 8.99}, {13, "Esponja", 1.50}, {14, "Amaciante", 15.00}};
    Produto alimentos[] = {{21, "Café", 19.99}, {22, "Leite", 5.90}, {23, "Arroz", 4.50}, {24, "Feijão Preto", 8.00}, {25, "Açúcar", 5.00}};
    Produto padaria[] = {{31, "Pão de Forma", 9.50}, {32, "Pão Integral", 12.50}, {33, "Pão Francês", 1.90}, {34, "Sonho", 8.50}};
    
    float totalMaterial = 0, totalAlimentos = 0, totalPadaria = 0;
    int opcao;
    do {
        exibirMenuPrincipal();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: totalMaterial += processarCompra(materialDeLimpeza, 4); break;
            case 2: totalAlimentos += processarCompra(alimentos, 5); break;
            case 3: totalPadaria += processarCompra(padaria, 4); break;
            case 4: processarPagamento(totalMaterial, totalAlimentos, totalPadaria); break;
            case 5: printf("Encerrando sistema.\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 5);
    
    return 0;
}
