#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

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

// Prototipos
int menuPrincipal();
void menuGerenciarLivros();
void limpa();
void limparBufferEntrada();

// Main
int main()
{
    printf("main");
    return 0;
}

// Funcoes

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
void menuGerenciarLivros(){}
    
