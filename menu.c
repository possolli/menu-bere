#include <stdio.h>
#include <stdlib.h>

// Adicionamos as funções na ordem que está no menu principal.
// Cada variavel representa o valor total em cada area de compras.
float total_limpeza, total_alimentos, total_padaria, total_geral, total_faturamento = 0.0;
int total_produtos, total_vendas = 0;

// Informacoes para o menu de saida
int numero_produtos;

// Variavel usada para indicar qual menu estamos exibindo.
int menu_selecionado;

// Primeiro menu da berenice.
void exibir_menu_principal() {
  printf("\n*********************** MENU PRINCIPAL ***********************\n");
  printf("1.\tMateriais de Limpeza\n");
  printf("2.\tVenda de Alimentos\n");
  printf("3.\tPadaria\n");
  printf("4.\tPagamento\n");
  printf("5. Sair\n");
  printf("***************************************************************\n\n");
}

// Menu de limpeza
void exibir_menu_limpeza() {
    int produto_codigo, produto_quantidade;
    float produto_valor, produto_total;

    do {
        printf("\n************************ MENU LIMPEZA ************************\n");
        printf("Item (Codigo)\t\tNome\t\t\t\tValor (unidade)\n");
        printf("11.\t\t\tDetergente\t\t\tR$1.99\n");
        printf("12.\t\t\tSabao em Po (1KG)\t\tR$8.99\n");
        printf("13.\t\t\tEsponja\t\t\t\tR$1.50\n");
        printf("14.\t\t\tAmaciante (1LT)\t\t\tR$15.00\n");
        printf("15. Voltar ao Menu Principal\n");
        printf("***************************************************************\n\n");

        printf(">>>>>>>>>> Insira o codigo: ");
        scanf("%d", &produto_codigo);

        switch (produto_codigo) {
            case 11:
                produto_valor = 1.99;
                break;
            case 12:
                produto_valor = 8.99;
                break;
            case 13:
                produto_valor = 1.50;
                break;
            case 14:
                produto_valor = 15.00;
                break;
            case 15:
                return;
            default:
                // Vai aparecer caso o usuario digite um numero/algo invalido.
                printf("\n\n* [ERRO] Por favor, insira um dos valores listados acima!\n");
                continue;
        }

        printf(">>>>>>>>>> Insira a quantidade: ");
        scanf("%d", &produto_quantidade);

        while (produto_quantidade <= 0) {
            printf("\n* [AVISO] Insira uma quantidade maior que zero!\n\n");
            printf(">>>>>>>>>> Insira a quantidade: ");
            scanf("%d", &produto_quantidade);
        }

        produto_total = (produto_valor * produto_quantidade);
        numero_produtos += produto_quantidade;
        total_limpeza += produto_total;
        total_geral += produto_total;

        printf("\n* [SUCESSO] Foi adicionado +R$%.2f ao carrinho!\n", produto_total);
        printf("* [INFO] Total do carrinho de Limpeza: R$%.2f\n", total_limpeza);
        
    } while (produto_codigo != 15);
}

// Menu de alimentos
void exibir_menu_alimentos() {
    int produto_codigo, produto_quantidade;
    float produto_valor, produto_total;

    do {
        printf("\n************************ MENU ALIMENTOS ***********************\n");
        printf("Item (Codigo)\t\tNome\t\t\t\tValor (unidade)\n");
        printf("21.\t\t\tCafe\t\t\t\tR$19.99\n");
        printf("22.\t\t\tLeite (CAIXA)\t\t\tR$5.90\n");
        printf("23.\t\t\tArroz (1KG)\t\t\tR$4.50\n");
        printf("24.\t\t\tFeijao Preto (1KG)\t\tR$8.00\n");
        printf("25.\t\t\tAcucar (1KG)\t\t\tR$5.00\n");
        printf("26. Voltar ao Menu Principal\n");
        printf("****************************************************************\n\n");

        printf(">>>>>>>>>> Insira o codigo: ");
        scanf("%d", &produto_codigo);

        if (produto_codigo == 26) return;

        switch (produto_codigo) {
            case 21:
                produto_valor = 19.99;
                break;
            case 22:
                produto_valor = 5.90;
                break;
            case 23:
                produto_valor = 4.50;
                break;
            case 24:
                produto_valor = 8.00;
                break;
            case 25:
                produto_valor = 5.00;
                break;
            case 26:
                return;
            default:
                printf("\n* [ERRO] Codigo incorreto! Insira um codigo valido.\n");
                continue;
        }

        printf(">>>>>>>>>> Insira a quantidade: ");
        scanf("%d", &produto_quantidade);

        while (produto_quantidade <= 0) {
            printf("\n* [AVISO] Insira uma quantidade maior que zero!\n\n");
            printf(">>>>>>>>>> Insira a quantidade: ");
            scanf("%d", &produto_quantidade);
        }

        produto_total = (produto_valor * produto_quantidade);
        numero_produtos += produto_quantidade;
        total_alimentos += produto_total;
        total_geral += produto_total;

        printf("\n* [SUCESSO] Foi adicionado +R$%.2f ao carrinho!\n", produto_total);
        printf("* [INFO] Total do carrinho de Alimentos: R$%.2f\n", total_alimentos);
        
    } while (produto_codigo != 26);
}

void exibir_menu_padaria() {
    int produto_codigo, produto_quantidade;
    float produto_valor, produto_total;

    do {
        printf("\n************************ MENU PADARIA ************************\n");
        printf("Item (Codigo)\t\tNome\t\t\t\tValor (unidade)\n");
        printf("31.\t\t\tPao de Forma\t\t\tR$9.50\n");
        printf("32.\t\t\tPao Integral\t\t\tR$12.50\n");
        printf("33.\t\t\tPao Frances\t\t\tR$1.90\n");
        printf("34.\t\t\tSonho\t\t\t\tR$8.50\n");
        printf("35. Voltar ao Menu Principal\n");
        printf("\n\n");

        printf(">>>>>>>>>> Insira o codigo: ");
        scanf("%d", &produto_codigo);

        if (produto_codigo == 35) return;

        switch (produto_codigo) {
            case 31:
                produto_valor = 9.50;
                break;
            case 32:
                produto_valor = 12.50;
                break;
            case 33:
                produto_valor = 1.90;
                break;
            case 34:
                produto_valor = 8.50;
                break;
            case 35:
                return;
            default:
                printf("\n* [ERRO] Codigo incorreto! Insira um codigo valido.\n");
                continue;
        }

        printf(">>>>>>>>>> Insira a quantidade: ");
        scanf("%d", &produto_quantidade);

        while (produto_quantidade <= 0) {
            printf("\n* [AVISO] Insira uma quantidade maior que zero!\n\n");
            printf(">>>>>>>>>> Insira a quantidade: ");
            scanf("%d", &produto_quantidade);
        }

        produto_total = (produto_valor * produto_quantidade);
        numero_produtos += produto_quantidade;
        total_padaria += produto_total;
        total_geral += produto_total;

        printf("\n* [SUCESSO] Foi adicionado +R$%.2f ao carrinho!\n", produto_total);
        printf("* [INFO] Total do carrinho de Padaria: R$%.2f\n", total_padaria);
        
    } while (produto_codigo != 35);
}

void resetar_valores() {
  total_limpeza = 0;
  total_alimentos = 0;
  total_padaria = 0;
  total_geral = 0;
  numero_produtos = 0;
}

void exibir_menu_pagamento() {
  int opcao_pagamento;
  
  do {
      printf("\n************************* MENU PAGAMENTO **********************\n");
      printf("1.\tDinheiro (COM DESCONTO!)\n");
      printf("2.\tCartao\n");
      printf("3. Voltar ao Menu Principal\n");
      printf("***************************************************************\n");
      printf("* VALOR LIMPEZA: R$%.2f\n", total_limpeza);
      printf("* VALOR ALIMENTOS: R$%.2f\n", total_alimentos);
      printf("* VALOR PADARIA: R$%.2f\n", total_padaria);
      printf("* VALOR TOTAL (SEM DESCONTO): R$%.2f\n", total_geral);
      printf("***************************************************************\n\n");

      printf(">>>>>>>>>> Insira o metodo de pagamento: ");
      scanf("%d", &opcao_pagamento);

      if (opcao_pagamento == 1) {
          float desconto = 0.0;

          // Adicionando desconto com base nos valores
          if (total_geral <= 50) {
              desconto = (total_geral * 0.05);
          } else if (total_geral < 100) {
              desconto = (total_geral * 0.10);
          } else {
              desconto = (total_geral * 0.18);
          }

          // Aplicamos desconto diratemento no total de todos os produtos somados
          total_geral -= desconto;

          printf("\n* [INFO] DESCONTO: R$%.2f\n", desconto);
          printf("* [INFO] VALOR TOTAL (COM DESCONTO): R$%.2f\n", total_geral);

          float recebido;
          
          // Aqui nós garantimos que o valor recebido seja maior ou igual ao total geral
          do {
              printf("\n>>>>>>>>>> Insira o valor recebido R$: ");
              scanf("%f", &recebido);

              if (recebido < total_geral) {
                  printf("\n* [ERRO] Valor insuficiente! Insira um valor maior ou igual a R$%.2f!\n", total_geral);
              }
          } while (recebido < total_geral);

          float troco = (recebido - total_geral);

          if (troco > 0) {
              printf("\n* [INFO] Troco: R$%.2f", troco);
          }

          total_faturamento += total_geral;
          total_produtos += numero_produtos;
          total_vendas += 1;
          printf("\n* [SUCESSO] Venda concluida!\n");

          resetar_valores();
          return; // Retorna ao menu principal
      } else if (opcao_pagamento == 2) {
          int status;

          // Aqui estamos simulando um pagamento com cartão e garantindo que o status seja 0 ou 1
          do {
              printf("\n* [INFO] Pagamento na maquina (1: OK | 0: FALHOU): ");
              scanf("%d", &status);

              if (status != 0 && status != 1) {
                  printf("\n* [ERRO] Opção inválida! Escolha 1 (OK) ou 0 (FALHOU)!\n");
              }
          } while (status != 0 && status != 1);

          if (status == 0) {
              printf("\n* [ERRO] Pagamento falhou - Escolha outra forma de pagamento!\n");
          } else {
              total_faturamento += total_geral;
              total_produtos += numero_produtos;
              total_vendas += 1;
              printf("\n* [SUCESSO] Venda concluida!\n");

              resetar_valores();
              return; // Retorna ao menu principal
          }
      } else if (opcao_pagamento == 3) {
          return; // Voltar ao menu principal
      } else {
          printf("\n* [ERRO] Por favor, insira um dos valores listados acima!\n");
      }

  } while (1); // Mantém o menu aberto até que uma ação seja concluída
}

// Função para encerrar o programa e mostrar o resumo final
void encerrar_programa() {
    printf("\n************************ MENU ENCERRADO ***********************\n");
    printf("* [INFO] FATURAMENTO TOTAL: R$%.2f\n", total_faturamento);
    printf("* [INFO] QNT. VENDAS: %d\n", total_vendas);
    printf("* [INFO] QNT. PRODUTOS VENDIDOS: %d\n", total_produtos);
    printf("****************************************************************");
}

int main() {
    do {
        exibir_menu_principal();
        printf(">>>>>>>>>> ");
        scanf("%d", &menu_selecionado);

        switch (menu_selecionado) {
            case 1:
                exibir_menu_limpeza();
                break;
            case 2:
                exibir_menu_alimentos();
                break;
            case 3:
                exibir_menu_padaria();
                break;
            case 4:
                exibir_menu_pagamento();
                break;
            case 5:
                if (total_geral > 0) {
                    printf("\n* [AVISO] Parece que tens items no seu carrinho!");
                    printf("\n* [AVISO] Deseja realmente sair? (1: SIM | 2: NAO)\n\n");
                    printf(">>>>>>>>>> ");

                    int sair_selecionado;
                    scanf("%d", &sair_selecionado);

                    while (sair_selecionado != 1 && sair_selecionado != 2) {
                        printf("\n* [AVISO] Digite uma opcao valida\n!");
                        printf(">>>>>>>>>> ");
                        scanf("%d", &sair_selecionado);
                    }

                    //menu_selecionado = 0;

                    switch (sair_selecionado) {
                        case 1:
                            menu_selecionado = 5;
                            encerrar_programa();
                            break;
                        case 2:
                            menu_selecionado = 0;
                            break;
                    }
                } else {
                    encerrar_programa();
                    return 0;
                }
                break;
            default:
                printf("\n* [ERRO] Por favor, insira um dos valores listados acima!\n\n");
                break;
        }
    } while (menu_selecionado != 5);

    return 0;
}