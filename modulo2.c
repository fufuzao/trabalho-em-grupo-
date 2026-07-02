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
    }
   break;
       
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

printf("\n--- ALTERAR USUÁRIO ---\n");
if (total_usuario == 0) {
printf("Nenhum usuário cadastrado.\n");
} else {
int codigo_alterar, achou = 0;
printf("Digite o código do usuário que deseja alterar: ");
scanf("%d", &codigo_alterar);
getchar();

for (int i = 0; i < total_usuario; i++) {
if (banco_de_dados[i].codigo == codigo_alterar) {
printf("Novo Nome: ");
fgets(banco_de_dados[i].nome, sizeof(banco_de_dados[i].nome), stdin);
banco_de_dados[i].nome[strcspn(banco_de_dados[i].nome, "\n")] = 0;

printf("Novo Telefone: ");
fgets(banco_de_dados[i].telefone, sizeof(banco_de_dados[i].telefone), stdin);
banco_de_dados[i].telefone[strcspn(banco_de_dados[i].telefone, "\n")] = 0;

printf("Novo E-mail: ");
fgets(banco_de_dados[i].email, sizeof(banco_de_dados[i].email), stdin);
banco_de_dados[i].email[strcspn(banco_de_dados[i].email, "\n")] = 0;
printf("Dados alterados com sucesso!\n");
achou = 1;
 break;
 }
}
if (!achou) printf("Código não encontrado.\n");
}
break;

case 5:

printf("\n--- EXCLUIR USUÁRIO ---\n");
if(total_usuario == 0) {
printf("Nenhum usuário cadastrado.\n");
} else {
int codigo_excluir, i, encontrado = 0;
printf("Digite o código do usuário a ser excluído: ");
scanf("%d", &codigo_excluir); 
getchar();

for (i = 0; i < total_usuario; i++) {
if(banco_de_dados[i].codigo == codigo_excluir){
 encontrado = 1;
 break;
}
}

        
if (encontrado){
for(int j = i; j < total_usuario - 1; j++){
banco_de_dados[j] = banco_de_dados[j+1];
}
total_usuario--;
printf("Usuário excluído com sucesso!\n");
} else {
printf("Usuário não encontrado.\n");
}
}
break;


case 6:
  printf("Saindo do sistema...\n");
break;

default:
printf("Opção inválida! Tente novamente.\n");

}

}while (opcao !=6);

return 0;
}