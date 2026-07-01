#include <stdio.h>
#include <windows.h>
#include <string.h>

#define MAX_USUARIOS 50


typedef struct
{
 int codigo;
 char nome [100];
char telefone [20];
 char email [80];
}usuario;

usuario banco_de_dados[MAX_USUARIOS];

int total_usuario =0;

int main(){
SetConsoleOutputCP(CP_UTF8);

int opcao;


do{
   printf("\n===== CADASTRO DE USUÁRIO =====\n");
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Buscar\n");
        printf("4. Alterar\n");
        printf("5. Excluir\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();


switch(opcao){


case 1: 

        if (total_usuario>=MAX_USUARIOS){
         printf("limite total de usuários atingido\n");
        }else{
        printf("coloque o código: ");
        scanf("%d", &banco_de_dados[total_usuario].codigo);
        getchar();

      printf("escreva seu nome: ");
      fgets(banco_de_dados[total_usuario].nome, sizeof(banco_de_dados[total_usuario].nome), stdin);
      banco_de_dados[total_usuario].nome[strcspn(banco_de_dados[total_usuario].nome, "\n")] = 0;
                  
      printf("digite seu telefone: ");          
      fgets(banco_de_dados[total_usuario].telefone, sizeof(banco_de_dados[total_usuario].telefone), stdin);
      banco_de_dados[total_usuario].telefone[strcspn(banco_de_dados[total_usuario].telefone, "\n")] = 0;

    printf("escreva o seu email: ");
    fgets(banco_de_dados[total_usuario].email, sizeof(banco_de_dados[total_usuario].email), stdin);
    banco_de_dados[total_usuario].email[strcspn(banco_de_dados[total_usuario].email, "\n")] = 0;

    total_usuario++; 
    printf("Acesso do úsuario com sucesso\n");
        }
    break;

case 2:
       printf("\n---Lista de usuários---\n");
       if(total_usuario==0){
        printf("\nNenhum usuário encontrado\n");
       }
       for (int i = 0; i < total_usuario; i++) {

    printf("ID: %d | Nome: %s | Tel: %s | E-mail: %s\n",

    banco_de_dados[i].codigo, banco_de_dados[i].nome,

   banco_de_dados[i].telefone, banco_de_dados[i].email);
   
   break;
       }
case 3:

 printf("\n--- Busca de usuário ---\n");
  if (total_usuario == 0) {
   printf("\nNenhum usuário cadastrado \n");  
    } else {
                    
     int codigo_busca, i;
                    
    printf("Digite o código do usuário que procura: ");
     scanf("%d", &codigo_busca);
      getchar();
                                       
                    
    for (i = 0; i < total_usuario; i++) {
      if (banco_de_dados[i].codigo == codigo_busca) {
        break; 
     }
       }

                    
     if (i < total_usuario) {
                       
     printf("\nUsuário Encontrado:\n");
    printf("Nome: %s\nTelefone: %s\nE-mail: %s\n", 
    banco_de_dados[i].nome, 
     banco_de_dados[i].telefone, 
     banco_de_dados[i].email);
       } else {
    
     printf("Usuário com o código %d não foi encontrado.\n", codigo_busca);
    }
   } 
   break;

case 4:



case 5:

case 6:

}

}while (opcao !=6);

return 0;
}