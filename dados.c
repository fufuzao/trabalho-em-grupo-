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
    int emprestimo;
    livro livroAlocado[MAX_LIVROS];
} usuario;
usuario user[MAX_USUARIOS];

// Variaveis
int livrosTotais, usuariosTotais;

// Prototipos
void menuPrincipal ();
void subMenuRelatorio ();
void menuGerenciarLivros ();
void limpa ();
void pausarTela ();
void limparBufferEntrada ();
void estruturaDaMain ();
void relatorioLivro ();
void relatorioUsuario ();

// Main
int main ()
{
    printf("main");
    return 0;
}

// Funcoes
void menuPrincipal ()
{
    printf("\n============ BIBLIOTECA ============\n");
    printf("1 - Gerenciar Livros\n");
    printf("2 - Gerenciar Usuarios\n");
    printf("3 - Emprestimos\n");
    printf("4 - Relatorios\n");
    printf("0 - Voltar ao Menu Principal\n");
    printf("Escolha: ");
}

void menuGerenciarLivros ()
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

void menuGerenciarUsuarios ()
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

void limpa ()
{
    system("cls");
    system("clear");
}

void pausarTela ()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void limparBufferEntrada ()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
void estruturaDaMain ()
{
    int opcao = 0;
    enum
    {
        sair = 0,
        modulo1 = 1,
        modulo2 = 2,
        modulo3 = 3
    };
        menuPrincipal ();
        do
        { 
        scanf (&opcao);
            swicth (opcao)
            {
                case modulo1:
            
                    pausarTela ();
                
                break;
                
                case modulo2:
            
                    pausarTela ();
                
                break:
                
                case modulo3:
            
                    pausarTela ();
                
                break;

                case default:

                    printf (" Escolha uma alternativa existente");
                    pausarTela ();

                break;
                
            }
    }while (opcao != sair);
}

void subMenuRelatorio ()
{
    limpa ();
    printf ("\n============ RELATORIO ============\n");
    printf ("1 - Relatorio Sobre usuarios");
    printf ("2 - Relatorios Sobre Livros")
    printf ("0 - Voltar ao Menu Principal\n");
    printf ("Escolha: ");   
}

void relatorioUsuario ()
{
    enum opcoes
    {
        cadastros = 1,
        emprestimos = 2,
        atrasos = 3,
        sair = 0
    };

    int opcao = 0;

    
    limpa ();
    printf ("1 - Usuarios Cadastrados\n");
    printf ("2 - Usuarios Com Emprestimos");
    printf ("3 - Usuarios Com Atraso");
    
    do
    {
        switch (opcao)
        { 
            case cadastros:
                limpa();
            break;
                
            case emprestimos:
                limpa();
            break;
            
            case atrasos:
                limpa();
            break;

            case sair:
                limpa();
            break;
            
            default:
                limpa();
        
            break;
        
        }
    }while (opcao != sair);
}

void relatorioLivro ()
{

    limpa ();
    printf ("1 - Listar Todos os Livros\n");
    printf ("2 - Listar Por Categoria");
    printf ("2 - Livros Disponiveis\n");
    printf ("3 - Livros Emprestados\n");
    printf ("4 - Livros Com atraso\n");

}

void usuariosCadastrados ()
{
    if(usuariosTotais == 0){
        printf ("\nNenhum usuario cadastrado!");
        printf ("\n+===================================+\n");
        printf("==== Pressione enter para sair ====");
        printf ("\n+===================================+\n");
        pausarTela ();
        
        return;
    }
    
    printf ("\n+============ RELATORIO ============+\n");
    printf ("| %2.d |   Usuarios Registrados     |", usuariosTotais);
    printf ("\n+===================================+\n");

    for(int i = 0; i < usuariosTotais; i++)
    {
        printf ("\n| %2.d | %s", user[i].id , user[i].nome);
    }

    printf ("\n+===================================+\n");
    printf("==== Pressione enter para sair ====");
    printf ("\n+===================================+\n");
    pausarTela();

}

void usuariosCadastrados ()
{
    printf ("\n+============ RELATORIO ============+\n");
    printf ("| %2.d |   Usuarios com Emprestimos |", usuariosTotais);
    printf ("\n+===================================+\n");

    for(int i = 0; i < usuariosTotais; i++)
    {
        if(user[i].emprestimo == 1){
            printf ("\n| %2.d | %s", user[i].id , user[i].nome);
        }
    }
    printf ("\n+===================================+\n");
    printf("==== Pressione enter para sair ====");
    printf ("\n+===================================+\n");
    pausarTela();

}