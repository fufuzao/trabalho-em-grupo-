#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

// Structs de usuarios e livros
typedef struct
{
    char titulo[100];
    char autor[50];
    int categoria;
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
int livrosTotais, pessoasTotais, IDdoLivro;

// Prototipos
void menuPrincipal();
void menuGerenciarLivros();
void limpa();
void limparBufferEntrada();
void cadastroGeral();
int BuscarId(int idBusca);
void Buscar();
void Listar();
char BuscarTítulo(char LivroBusca[50]);
void cadastroTitulo();
void cadastroAutor();
int cadastroCategoria();
void cadastroAno();
void cadastroQuantidade();
void cadastroQuantidadeDisponível();
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

    cadastroGeral();
    return 1;
}

// Funcoes
void menuPrincipal()
void menuPrincipal ()
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

void limparBufferEntrada()
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
void estruturaDaMain() {}

void cadastroTitulo()
{
    if (livrosTotais >= MAX_LIVROS)
    {

        printf("Limite maximo de livros atingido");
        return;
    }
    printf("\nDigite o titulo do seu livro: ");
    fgets(books[livrosTotais].titulo, 100, stdin);
}

void cadastroAutor()
{
//Cadastro básico de autor com printf e guardando na struct
    printf("\nDigite o nome do autor: ");
    fgets(books[livrosTotais].autor, 100, stdin);
}

int cadastroCategoria()
{
//Cadastro de uma em 15 categorias dando valor para a variável e definindo com o número da opção do usuário
    int opcao;

    printf("\n============ CATEGORIAS ============\n");
    printf("1 - Romance\n");
    printf("2 - Fantasia\n");
    printf("3 - Suspense\n");
    printf("4 - Terror\n");
    printf("5 - Mistério\n");
    printf("6 - Distopia\n");
    printf("7 - Biografia\n");
    printf("8 - Autoajuda\n");
    printf("9 - História\n");
    printf("10 - Negócios e Economia\n");
    printf("11 - Filosofia\n");
    printf("12 - Ciência e Tecnologia\n");
    printf("13 - Crimes Reais\n");
    printf("14 - Drama\n");
    printf("15 - Poesia\n");
    printf("0 - Sair\n");

    printf("Escolha: ");
    scanf("%d",&opcao);

    if (opcao == 1)
    {

        books->categoria = 1;
        printf("\nRomance");
    }
    if (opcao == 2)
    {

        books->categoria = 2;
        printf("\nFantasia");
    }
    if (opcao == 3)
    {

        books->categoria = 3;
        printf("\nSuspense");
    }
    if (opcao == 4)
    {

        books->categoria = 4;
        printf("\nTerror");
    }
    if (opcao == 5)
    {

        books->categoria = 5;
        printf("\nMistério");
    }
    if (opcao == 6)
    {

        books->categoria = 6;
        printf("\nDistopia");
    }
    if (opcao == 7)
    {

        books->categoria = 7;
        printf("\nBiografia");
    }
    if (opcao == 8)
    {

        books->categoria = 8;
        printf("\nAutoajuda");
    }
    if (opcao == 9)
    {

        books->categoria = 9;
        printf("\nHistória");
    }
    if (opcao == 10)
    {

        books->categoria = 10;
        printf("\nNegócios e Economia");
    }
    if (opcao == 11)
    {

        books->categoria = 11;
        printf("\nFilosofia");
    }
    if (opcao == 12)
    {

        books->categoria = 12;
        printf("\nCiência e Tecnologia");
    }
    if (opcao == 13)
    {

        books->categoria = 13;
        printf("\nCrimes Reais");
    }
    if (opcao == 14)
    {

        books->categoria = 14;
        printf("\nDrama");
    }
    if (opcao == 15)
    {

        books->categoria = 15;
        printf("\nPoesia");
    }
    if (opcao != 0)
    {

        return 0;
    }
    else
    {
    }

    printf("\nOpção inexistente escolha uma entre 0 e 15");
}

void cadastroAno()
{

    printf("\nDigite o ano do seu livro: ");
    scanf("%d",books[livrosTotais].ano);
}

void cadastroQuantidade()
{

    printf("\nDigite a sua quantidade: ");
    scanf("%d",books[livrosTotais].quantidade);
}

void cadastroQuantidadeDisponível()
{

    // não sei
}

void cadastroGeral()
{
//Cadastro geral contendo todas as funções anteriores e chamando apenas ele na Main
    cadastroTitulo();
    cadastroAutor();
    cadastroCategoria();
    cadastroAno();
    cadastroQuantidade();
    cadastroQuantidadeDisponível();

    IDdoLivro++;
    books[livrosTotais].id++;
}

void Listar()
{

    for (int i = 0; i = MAX_LIVROS; i++)
    {

        printf("%d ", books[livrosTotais].titulo);
    }
}

int BuscarId(int idBusca)
{

    printf("\nQual o ID do seu livro");
    scanf("%d",&idBusca);

    for (int i = 0; i > livrosTotais; i++)
    {

        if (idBusca == books[i].id)
        {

            return idBusca;
        }
    }
}

char BuscarTítulo(char LivroBusca[50])
{

    printf("\nQual o Título do livro que você deseja procurar");
    fgets(LivroBusca, 50, stdin);

    for (int i = 0; i > livrosTotais; i++)
    {

        if (strcmp(books[i].titulo, LivroBusca) == 0)
        {

            printf("\nLivro encontrado: %s", LivroBusca);

            printf("\nId do seu livro: %d", books[i].id);

            printf("\nAutor do seu livro: %s", books[i].autor);

            printf("\nAno do seu livro: %d", books[i].ano);

            printf("\nQuantidade do seu livro: %d", books[i].quantidade);

            printf("\nQuantidade disponível do seu livro: %d", books[i].quantidadeDisponivel);
        }
    }
}

void Alterar(){

    int idBusca, encontrado =0;

printf("Digite o ID do livro que deseja alterar:");
scanf("%d",&idBusca);

limparBufferEntrada();

    for(int i = 0; i < livrosTotais; i++){
    encontrado = 1;

        if(books[i].id==idBusca){
        encontrado = 1;
            printf("\nO livro foi encontrado agora insira os novos dados: ");

            printf("\nNovo título: ");
            fgets(books[i].titulo,100,stdin);

            printf("\nNovo autor: ");
            fgets(books[i].autor,100,stdin);

            printf("\nNovo ano: ");
            scanf("%d",&books[i].ano);

            printf("\nNova categoria: ");
            scanf("%d",&books[i].categoria);

            printf("\nNova quantidade total: ");
            scanf("%d",&books[i].quantidade);


            books[i].quantidade = books[i].quantidadeDisponivel;

        }

    }

}

void excluir(){

int idBusca, encontrado =0;

printf("Digite o ID de busca: ");
scanf("%d",&idBusca);

limparBufferEntrada();

    for(int i = 0; i < livrosTotais; i++){

        if(books->id == idBusca){
        encontrado = 1;

            books[i] = books[livrosTotais - 1];

            livrosTotais --;

            printf("Livro excluido");
            break;
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