#include <stdio.h>

float faturamento = 0;
int quantidadeDeVendas = 0;

/* Função para exibir o menu principal */
void exibirMenuPrincipal() {
    printf("\nMenu Principal\n");
    printf("1. Material de Limpeza\n");
    printf("2. Venda de Alimentos\n");
    printf("3. Padaria\n");
    printf("4. Pagamento\n");
    printf("5. Sair\n");
    printf("Escolha uma categoria: ");
}

/* Exibir produtos de material de limpeza */
void exibirProdutosMaterialDeLimpeza() {
    printf("\nCodigo - Nome do Item - Valor (Unidade)\n");
    printf("11 - Detergente - R$1.99\n");
    printf("12 - Sabão em Po - R$8.99\n");
    printf("13 - Esponja - R$1.50\n");
    printf("14 - Amaciante - R$15.00\n");
    printf("15 - Voltar ao Menu Principal\n");
}

/* Exibir produtos de alimentos */
void exibirProdutosAlimentos() {
    printf("\nCodigo - Nome do Item - Valor (Unidade)\n");
    printf("21 - Cafe - R$19.99\n");
    printf("22 - Leite - R$5.90\n");
    printf("23 - Arroz - R$4.50\n");
    printf("24 - Feijão Preto - R$8.00\n");
    printf("25 - Acúcar - R$5.00\n");
    printf("26 - Voltar ao Menu Principal\n");
}

/* Exibir produtos de material de limpeza */
void exibirProdutosPadaria() {
    printf("\nCodigo - Nome do Item - Valor (Unidade)\n");
    printf("31 - Pão de Forma - R$9.50\n");
    printf("32 - Pão Integral - R$12.50\n");
    printf("33 - Pão Francês - R$1.90\n");
    printf("34 - Sonho - R$8.50\n");
    printf("35 - Voltar ao Menu Principal\n");
}

/* Função para processar a compra */
float processarCompra(int categoria) {
    int codigo, quantidade;
    float total = 0;
    
    while (1) {
        switch (categoria) {
            case 1: exibirProdutosMaterialDeLimpeza(); break;
            case 2: exibirProdutosAlimentos(); break;
            case 3: exibirProdutosPadaria(); break;
        }
        
        printf("Digite o codigo do item ou 0 para voltar: ");
        scanf("%d", &codigo);
        if (codigo == 15 || codigo == 26 || codigo == 35) break;

        float preco = 0;
        switch (codigo) {
            case 11:
                preco = 1.99;
                break;
            case 12:
                preco = 8.99;
                break;
            case 13:
                preco = 1.50;
                break;
            case 14:
                preco = 15.00;
                break;
            case 21:
                preco = 19.99;
                break;
            case 22:
                preco = 5.90;
                break;
            case 23:
                preco = 4.50;
                break;
            case 24:
                preco = 8.00;
                break;
            case 25:
                preco = 5.00;
                break;
            case 31:
                preco = 9.50;
                break;
            case 32:
                preco = 12.50;
                break;
            case 33:
                preco = 1.90;
                break;
            case 34:
                preco = 8.50;
                break;
            default: printf("Codigo invalido!\n"); continue;
        }
        
        printf("Quantidade: ");
        scanf("%d", &quantidade);
        total += preco * quantidade;
        printf("Total acumulado: R$%.2f\n", total);
    }
    
    return total;
}

/* Função para processar o pagamento */
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
        printf("Pagamento na maquina (1 - Ok / 0 - Falhou): ");
        scanf("%d", &status);
        if (status == 0) {
            printf("Pagamento falhou. Escolha outra forma de pagamento.\n");
            processarPagamento(totalMaterial, totalAlimentos, totalPadaria);
        }
    }
    faturamento += totalGeral;
    quantidadeDeVendas++;
    printf("Pagamento concluido!\n");
}

void encerrarPrograma() {
    printf("Programa encerrado!\n");
    printf("Faturamento total: R$%.2f\n", faturamento);
    printf("Quantidade de vendas: %d\n", quantidadeDeVendas);
}

int main() {
    float totalMaterial = 0, totalAlimentos = 0, totalPadaria = 0;
    int categoria;

    do {
        exibirMenuPrincipal();
        scanf("%d", &categoria);
        
        switch (categoria) {
            case 1:
                totalMaterial += processarCompra(1);
                break;
            case 2:
                totalAlimentos += processarCompra(2);
                break;
            case 3:
                totalPadaria += processarCompra(3);
                break;
            case 4:
                processarPagamento(totalMaterial, totalAlimentos, totalPadaria);
                break;
            case 5:
                encerrarPrograma();
                break;
            default: printf("Opcao invalida!\n");
        }
    } while (categoria != 5);
    
    return 0;
}