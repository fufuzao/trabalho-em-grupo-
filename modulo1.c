#include <stdio.h>
#include <locale.h> // Para permitir acentos no printf

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200
#define MAX_NOMES 50

// 1. Definição da Struct (Cada livro tem apenas 1 código, 1 título, etc.)
struct Livro {
    int codigo;
    char titulo[MAX_NOMES];
    char autor[MAX_NOMES];
    char categoria[MAX_NOMES];
    int ano;
    int quantidade;
    int disponivel;
};

struct Livro livros[MAX_LIVROS];
int total_livros = 0; 

void modulo1() {
    int opcao2;

    do {
        printf("\n============ BIBLIOTECA ============\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Listar Livros\n");
        printf("3 - Buscar Livro\n");
        printf("4 - Alterar Livro\n");
        printf("5 - Excluir Livro\n");
        printf("0 - Voltar ao Menu Principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao2);
    
        
        switch(opcao2) {
            case 1:
                
                break;

            case 2:
                break;
            
            case 3:
            
            case 0:
                printf("\nSaindo\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
                break;
         }
          
    } while (opcao2 != 0);
}

int main() {



    return 0;
}