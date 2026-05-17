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
int main(){
    int opcao, i = 0;
    char nome_livro[10][100];

    while (1) {

      /*----------------menu----------------*/
        printf("====Biblioteca Pessoal====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livro\n");
        printf("4. Marcar livro como lido\n");
        printf("5. Remover livro\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("insira o nome do livro %d: ", i);
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
                break;
            case 3:
                printf("Buscar livro selecionado.\n");
                break;
            case 4:
                printf("Marcar livro como lido selecionado.\n");
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