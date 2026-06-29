
#include <stdio.h>
#include <windows.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200
#define MAX_NOMES 50

void medulo1(){
    int opcao2,i,j;

   struct main
   {
   int Código ;
   char Título [50];
   char Autor [50];
   char Categoria [50];
   int Ano ;
   int Quantidade ;
   int disponível ;
    
   };
   


    do {
        printf("\n============ BIBLIOTECA ============\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("Escolha: ");
        scanf("%d", &opcao2);
    
        switch(opcao2){
            
            
            case 1:

            break;


            case 2:
                
           
            break;

         }
          
    }while (opcao2!=0);
}





















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
