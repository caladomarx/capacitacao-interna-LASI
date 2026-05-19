/*
====Sistema de Biblioteca Pessoal====

### Objetivo

Criar um sistema para gerenciamento de livros.

### Funcionalidades

* cadastrar livros;
* listar livros;
* buscar livros;
* marcar livros como lidos;
* remover livros. */

#include <stdio.h>
#include <string.h>

// função para verificar se o livro já está cadastrado.
// Recebe o array de livros, a quantidade atual de livros e o nome a pesquisar.
// Retorna 1 se o livro existir, 0 caso contrário.
int livro_existe(char arr[][100], int count, const char *nome) {
    for (int k = 0; k < count; k++) {
        if (strcmp(arr[k], nome) == 0) return 1;
    }
    return 0;
}

int main(){
    // Variável de opção do menu.
    int opcao, i = 0, encontrado = 0;

    // Array para armazenar até 3 nomes de livros, cada um com até 99 caracteres.
    char nome_livro[3][100], busca[100];

    // Status de cada livro: inicializado como "não lido".
    char status_livro[3][10] = {"não lido", "não lido", "não lido"};

    // Loop principal do programa. Continua até que o usuário escolha a opção 0.
    while (opcao != 0) {
        system("clear"); // Limpa a tela (não indicado *portabilidade *eficiência).

        /*----------------menu----------------*/
        printf("\n====Biblioteca Pessoal====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livro\n");
        printf("4. Marcar livro como lido\n");
        printf("5. Remover livro\n");
        printf("0. Sair\n");
        printf("===========================\n");
        scanf("%d", &opcao); // Lê a escolha do usuário.

        switch (opcao) {
            case 1: system("clear");
            {
                int ch;
                /* Limpa o resto da linha após a leitura da opção para evitar que o próximo fgets
                leia o enter residual do scanf*/ 
                while ((ch = getchar()) != '\n' && ch != EOF);

                // Loop de cadastro, permanece até cancelar ou atingir o limite de 3 livros.
                while (1) {
                    if (i >= 3) {
                        printf("Limite de livros atingido. Não é possível cadastrar mais livros.\n");
                        printf("Pressione Enter para continuar");
                        break;
                    }

                    // Pede o nome do livro ao usuário.
                    printf("Insira o nome do livro %d (digite 'cancel' para voltar): ", i+1);
                    if (fgets(nome_livro[i], sizeof(nome_livro[i]), stdin) == NULL) {
                        printf("Erro de leitura. Voltando ao menu.\n");
                        printf("Pressione Enter para continuar");
                        break;
                    }

                    // Remove o caractere de newline lido pelo fgets.
                    size_t len = strlen(nome_livro[i]);
                    if (len > 0 && nome_livro[i][len - 1] == '\n') {
                        nome_livro[i][len - 1] = '\0';
                    }

                    // Se o usuário digitar "cancel" ou nenhuma string, sai do cadastro.
                    if (strcmp(nome_livro[i], "cancel") == 0 || nome_livro[i][0] == '\0') {
                        printf("Cancelando cadastro...\n\n");
                        break;
                    }

                    // Verifica se o livro já foi cadastrado.
                    if (livro_existe(nome_livro, i, nome_livro[i])) {
                        printf("!!Livro já cadastrado!!\n\n");
                        continue;
                    }

                    // Se não for duplicado, adiciona o livro à lista.
                    printf("Livro cadastrado com sucesso.\n\n");
                    i++;
                    /* continua perguntando até o usuário digitar 'cancel' ou atingir o limite */
                }
            }
                printf("Pressione Enter para continuar");
                break;

            case 2: system("clear");
                // Lista todos os livros cadastrados até o índice atual i.
                printf("Lista de livros cadastrados:\n");
                for (int l = 0; l < i; l++) {
                    printf("Livro %d: %s", l + 1, nome_livro[l]);
                    if (strcmp(status_livro[l], "lido") == 0) {
                        printf(" (lido)");
                    }
                    else {
                        printf(" (não lido)");
                    }
                    printf("\n");
                }
                printf("\nPressione Enter para continuar");
                getchar();
                break;

            case 3: system("clear");
                // Busca livro pelo nome exato informado pelo usuário.
                encontrado = 0;
                printf("digite o nome do livro que deseja buscar: ");
                scanf("%s", busca);
                for (int l = 0; l < i; l++) {
                    if (strcmp(nome_livro[l], busca) == 0) {
                        printf("Livro encontrado: %s", nome_livro[l]);
                        if (strcmp(status_livro[l], "lido") == 0) {
                            printf(" (lido)");
                        }
                        else {
                            printf(" (não lido)");
                        }
                        printf("\n");
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Livro não encontrado.\n");
                }
                printf("\nPressione Enter para continuar");
                getchar();
                break;

            case 4: system("clear");
                // Marca o livro como lido se encontrado.
                encontrado = 0;
                printf("qual livro deseja marcar como lido? ");
                scanf("%s", busca);
                for (int l = 0; l < i; l++) {
                    if (strcmp(nome_livro[l], busca) == 0) {
                        strcpy(status_livro[l], "lido"); // Atualiza o status do livro.
                        printf("Livro marcado como lido: %s\n", nome_livro[l]);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Livro não encontrado.\n");
                }
                printf("\nPressione Enter para continuar");
                getchar();
                break;

            case 5: system("clear");
                // Remove o livro encontrado e desloca os elementos seguintes para preencher o espaço.
                printf("qual livro deseja remover? ");
                scanf("%s", busca);
                encontrado = 0;
                for (int l = 0; l < i; l++) {
                    if (strcmp(nome_livro[l], busca) == 0) {
                        for (int j = l; j < i - 1; j++) {
                            strcpy(nome_livro[j], nome_livro[j + 1]);
                            strcpy(status_livro[j], status_livro[j + 1]);
                        }
                        i--; // Reduz o contador de livros cadastrados.
                        printf("Livro removido: %s\n", busca);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Livro não encontrado.\n");
                }
                printf("\nPressione Enter para continuar");
                getchar();
                break;
                case 0: system("clear");
                // Encerra o programa.
                printf("Saindo do sistema. Até mais!\n");
                return 0;

            default: system("clear");
                // Caso o usuário digite uma opção inválida.
                printf("Opção inválida. Tente novamente.\n");
                getchar();

        }
        getchar(); // Aguarda Enter antes de mostrar o menu novamente.
    }

    return 0;
}