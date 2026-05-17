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
int main(){
    int opcao, i = 0, encontrado = 0;
    char nome_livro[3][100], busca[100];
    char status_livro[3][10] = {"não lido", "não lido", "não lido"}; // Array para armazenar o status dos livros

    while (1) {

      /*----------------menu----------------*/
        printf("\n====Biblioteca Pessoal====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livro\n");
        printf("4. Marcar livro como lido\n");
        printf("5. Remover livro\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (i >= 3) {
                    printf("Limite de livros atingido. Não é possível cadastrar mais livros.\n");
                    break;

                }
                printf("insira o nome do livro %d: ", i+1);
                scanf("%s", nome_livro[i]);
                if (strcmp(nome_livro[i], "cancel") == 0) {
                    printf("cancelando cadastro...\n");
                    break;

                }
                else {
                    printf("Livro cadastrado com sucesso.\n");
                    i++;
                }
                break;

            case 2:
                printf("Listar livros selecionado.\n");
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
                break;

            case 3:
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
                break;

            case 4:
                encontrado = 0;
                printf("qual livro deseja marcar como lido? ");
                scanf("%s", busca);
                for (int l = 0; l < i; l++) {
                    if (strcmp(nome_livro[l], busca) == 0) {
                        strcpy(status_livro[l], "lido"); // Marca o livro como lido
                        printf("Livro marcado como lido: %s\n", nome_livro[l]);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Livro não encontrado.\n");
                }
                break;
            case 5:
                printf("Remover livro selecionado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");


        }
    }

    return 0;

}