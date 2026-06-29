
#include <stdio.h>
#include <windows.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200



int main(){

SetConsoleOutputCP(CP_UTF8);

int opcao;


    do {
        printf("\n============ BIBLIOTECA ============\n");
        printf("1 - Gerenciar Livros\n");
        printf("2 - Gerenciar Usuários\n");
        printf("3 - Empréstimos\n");
        printf("4 - Relatórios\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
    
        switch(opcao){
            
            
            case 1:

            break;


            case 2:
                
           
            break;

         }
          
    }while (opcao!=0);
}

