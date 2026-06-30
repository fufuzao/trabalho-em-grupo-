#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

// Structs de usuarios e livros
typedef struct
{
    char titulo[100];
    char autor[50];
    int ano;
    int quantidade;
    int quantidadeDisponivel;
    int id;
} livro;
livro books[MAX_LIVROS];
typedef struct
{
    char nome[50];
    char email[100];
    int telefone;
    int id;
    livro livroAlocado[MAX_LIVROS];
} usuario;
usuario user[MAX_USUARIOS];

// Variaveis
int livrosTotais, pessoasTotais;

// Prototipos
void menuPrincipal();
void menuGerenciarLivros();
void limpa();
void limparBufferEntrada();
void emprestimo();

// Main
int main()
{
    printf("main");
    return 0;
}

// Funcoes
void menuPrincipal()
{
    printf("\n============ BIBLIOTECA ============\n");
    printf("1 - Gerenciar Livros\n");
    printf("2 - Gerenciar Usuarios\n");
    printf("3 - Emprestimos\n");
    printf("4 - Relatorios\n");
    printf("5 - Excluir Livro\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("Escolha: ");
}

void menuGerenciarLivros()
{
    printf("\n============ GERENCIAMENTO DE LIVROS ============\n");
    printf("1 - Cadastrar Livro\n");
    printf("2 - Listar Livros\n");
    printf("3 - Buscar Livro\n");
    printf("4 - Alterar Livro\n");
    printf("5 - Excluir Livro\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("Escolha: ");
}

void menuGerenciarUsuarios()
{
    printf("\n============ GERENCIAMENTO DE LIVROS ============\n");
    printf("1 - Cadastrar novo Usuario\n");
    printf("2 - Listar Usuarios\n");
    printf("3 - Buscar Usuario\n");
    printf("4 - Alterar Cadastro\n");
    printf("5 - Excluir Cadastro\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("Escolha: ");
}

void limpa()
{
    system("cls");
    system("clear");
}

void limparBufferEntrada()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}





void estruturaDaMain(){}



int buscarUsuario(char nome[50]){

for(i = 0;i ==pessoasTotais; i++){

}


}



void emprestimo(){

    printf("\nnome de usuario: ");
    scanf("%c",user->nome);
    


    if(user->nome==1){
        printf("usuario %c encontrado",user->nome);
    }
    else{
        printf("Usuario nao encontrado");
    }










    if(books->titulo==1){
        printf("Livro encontrado");

    }
    else{
        printf("Livro nao encontrado");
    }
    





}
//Usuário existe?
//Livro existe?
//Está disponível?
//Registrar empréstimo
//Quantidade disponível--