#ifndef	MODELOS_H
#define MODELOS_H

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
    int emprestimo;

} usuario;

#endif
