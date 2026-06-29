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
typedef struct
{
    char nome[50];
    char email[100];
    int telefone;
    int id;
    livro;
} usuario;

awd
livro books[MAX_LIVROS];
usuario user[MAX_USUARIOS];



