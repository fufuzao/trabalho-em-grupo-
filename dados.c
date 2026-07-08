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
    int quantidadeindisponivel;
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

//struct emprestimo
typedef struct
{
    int idUsuario;
    int idLivro;
    int ativo;
} Emprestimo;
Emprestimo emprestimos[MAX_EMPRESTIMOS];


// Variaveis
int livrosTotais, usuariosTotais, IDdoLivro, IDdoUsuario, emprestimostotais;

// Prototipos
void menuPrincipal();
void subMenuRelatorio();
void menuGerenciarLivros();
void menuGerenciarUsuarios();
void limpa();
void pausarTela();
void limparBufferEntrada();
void removerNovaLinha(char *str);
int lerOpcao(int *opcao);
void cadastroGeral();
int BuscarId(int idBusca);
void Listar();
char BuscarTítulo(char LivroBusca[50]);
void Alterar();
void excluir();
void menudeemprestimo();
void menuEmprestimos();
void cadastroTitulo();
void cadastroAutor();
int cadastroCategoria();
void cadastroAno();
void cadastroQuantidade();
void cadastroQuantidadeDisponível();
void estruturaDaMain();
void relatorioLivro();
void relatorioUsuario();
int localizarLivro(int idLivro); // vinicius
int localizarUsuario(int idUsuario); // vinicius
void registrarEmprestimo(); // vinicius
void devolverLivro(); // vinicius
void listarEmprestimos(); // vinicius
void usuariosCadastrados();
void usuariosComEmprestimo();
void cadastroUsuario();
void listarUsuarios();
void buscarUsuario();
void alterarUsuario();
void excluirUsuario();
void gerenciarLivros();
void gerenciarUsuarios();


// Main
int main ()
{
    estruturaDaMain();
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
    printf("\n============ GERENCIAMENTO DE USUARIOS ============\n");
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

void pausarTela (){
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

// Remove o '\n' deixado pelo fgets ao final da string
void removerNovaLinha(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

// Le um inteiro de forma segura. Retorna 1 em sucesso, 0 se a entrada
// terminou (EOF) ou nao era um numero valido, evitando loop infinito
// nos menus quando a entrada e invalida ou acaba.
int lerOpcao(int *opcao)
{
    if (scanf("%d", opcao) != 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        return 0;
    }
    limparBufferEntrada();
    return 1;
}

void cadastroTitulo()
{
    if (livrosTotais >= MAX_LIVROS)
    {

        printf("Limite maximo de livros atingido");
        return;
    }
    printf("\nDigite o titulo do seu livro: ");
    fgets(books[livrosTotais].titulo, 100, stdin);
    removerNovaLinha(books[livrosTotais].titulo);
}

void cadastroAutor()
{

//Cadastro básico de autor com printf e guardando na struct
    printf("\nDigite o nome do autor: ");
    fgets(books[livrosTotais].autor, 50, stdin);
    removerNovaLinha(books[livrosTotais].autor);
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

    switch (opcao)
    {
        case 1:  books[livrosTotais].categoria = 1;  printf("\nRomance");               break;
        case 2:  books[livrosTotais].categoria = 2;  printf("\nFantasia");              break;
        case 3:  books[livrosTotais].categoria = 3;  printf("\nSuspense");              break;
        case 4:  books[livrosTotais].categoria = 4;  printf("\nTerror");                break;
        case 5:  books[livrosTotais].categoria = 5;  printf("\nMistério");              break;
        case 6:  books[livrosTotais].categoria = 6;  printf("\nDistopia");              break;
        case 7:  books[livrosTotais].categoria = 7;  printf("\nBiografia");             break;
        case 8:  books[livrosTotais].categoria = 8;  printf("\nAutoajuda");             break;
        case 9:  books[livrosTotais].categoria = 9;  printf("\nHistória");              break;
        case 10: books[livrosTotais].categoria = 10; printf("\nNegócios e Economia");   break;
        case 11: books[livrosTotais].categoria = 11; printf("\nFilosofia");             break;
        case 12: books[livrosTotais].categoria = 12; printf("\nCiência e Tecnologia");  break;
        case 13: books[livrosTotais].categoria = 13; printf("\nCrimes Reais");          break;
        case 14: books[livrosTotais].categoria = 14; printf("\nDrama");                 break;
        case 15: books[livrosTotais].categoria = 15; printf("\nPoesia");                break;
        case 0:
            return 0;
        default:
            printf("\nOpção inexistente escolha uma entre 0 e 15");
            break;
    }

    return opcao;
}

void cadastroAno()
{
    printf("\nDigite o ano do seu livro: ");
    scanf("%d",&books[livrosTotais].ano);
}

void cadastroQuantidade()
{
    printf("\nDigite a sua quantidade: ");
    scanf("%d",&books[livrosTotais].quantidade);
}

void cadastroQuantidadeDisponível(){
    books[livrosTotais].quantidadeDisponivel = books[livrosTotais].quantidade;

    books[livrosTotais].quantidadeindisponivel = 0;

    printf("\nQuantidade total: %d",books[livrosTotais].quantidade);

    printf("\nQuantidade disponivel: %d",books[livrosTotais].quantidadeDisponivel);
}

//Cadastro geral contendo todas as funções anteriores e chamando apenas ele na Main
void cadastroGeral()
{
    if (livrosTotais >= MAX_LIVROS)
    {
        printf("\nLimite maximo de livros atingido!");
        return;
    }

    cadastroTitulo();
    cadastroAutor();
    cadastroCategoria();
    cadastroAno();
    cadastroQuantidade();
    cadastroQuantidadeDisponível();

    IDdoLivro++;
    books[livrosTotais].id = IDdoLivro;
    livrosTotais++;

    printf("\nLivro cadastrado com sucesso!\n");
}

void Listar()
{
    if (livrosTotais == 0)
    {
        printf("\nNenhum livro cadastrado!\n");
        return;
    }

    for (int i = 0; i < livrosTotais; i++)
    {
        printf("\n[%d] %s", books[i].id, books[i].titulo);
    }
    printf("\n");
}

int BuscarId(int idBusca)
{
    printf("\nQual o ID do seu livro: ");
    scanf("%d",&idBusca);
    limparBufferEntrada();

    for (int i = 0; i < livrosTotais; i++)
    {
        if (idBusca == books[i].id)
        {
            return idBusca;
        }
    }
    return -1;
}

char BuscarTítulo(char LivroBusca[50])
{
    printf("\nQual o Título do livro que você deseja procurar: ");
    fgets(LivroBusca, 50, stdin);
    removerNovaLinha(LivroBusca);

    for (int i = 0; i < livrosTotais; i++)
    {
        if (strcmp(books[i].titulo, LivroBusca) == 0)
        {
            printf("\nLivro encontrado: %s", LivroBusca);
            printf("\nId do seu livro: %d", books[i].id);
            printf("\nAutor do seu livro: %s", books[i].autor);
            printf("\nAno do seu livro: %d", books[i].ano);
            printf("\nQuantidade do seu livro: %d", books[i].quantidade);
            printf("\nQuantidade disponível do seu livro: %d\n", books[i].quantidadeDisponivel);
            return 1;
        }
    }

    printf("\nLivro nao encontrado!\n");
    return 0;
}

void Alterar(){

    int idBusca, encontrado = 0;

    printf("Digite o ID do livro que deseja alterar: ");
    scanf("%d",&idBusca);

    limparBufferEntrada();

    for(int i = 0; i < livrosTotais; i++){

        if(books[i].id==idBusca){
            encontrado = 1;
            printf("\nO livro foi encontrado agora insira os novos dados: ");

            printf("\nNovo título: ");
            fgets(books[i].titulo,100,stdin);
            removerNovaLinha(books[i].titulo);

            printf("\nNovo autor: ");
            fgets(books[i].autor,50,stdin);
            removerNovaLinha(books[i].autor);

            printf("\nNovo ano: ");
            scanf("%d",&books[i].ano);

            printf("\nNova categoria: ");
            scanf("%d",&books[i].categoria);

            printf("\nNova quantidade total: ");
            scanf("%d",&books[i].quantidade);

            books[i].quantidadeDisponivel = books[i].quantidade;

            printf("\nLivro atualizado com sucesso!\n");
            break;
        }

    }

    if (!encontrado)
    {
        printf("\nLivro nao encontrado!\n");
    }
}

// menu de emprestimos
void menudeemprestimo()
{
    printf("\n===== EMPRESTIMOS =====\n");
    printf("1 - Realizar emprestimo\n");
    printf("2 - Devolver livro\n");
    printf("3 - Listar emprestimos\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
}

//usa o id do livro criado para conseguir fazer as buscas
int localizarLivro(int idLivro)
{
    for(int i = 0; i < livrosTotais; i++)
    {
        if(books[i].id == idLivro)
        {
            return i;
        }
    }

    return -1;
}

// usa o id do usuario para localizar o mesmo
int localizarUsuario(int idUsuario)
{
    for(int i = 0; i < usuariosTotais; i++)
    {
        if(user[i].id == idUsuario)
        {
            return i;
        }
    }

    return -1;
}

// registro de emprestimo ou pra mim um desafio gigante
void registrarEmprestimo()
{
    int idUsuario;
    int idLivro;

    // Verifica limite de emprestimos
    if(emprestimostotais >= MAX_EMPRESTIMOS)
    {
        printf("\nLimite de emprestimos atingido!");
        return;
    }

    printf("\nID do usuario: ");
    scanf("%d", &idUsuario);
    limparBufferEntrada();

    printf("ID do livro: ");
    scanf("%d", &idLivro);
    limparBufferEntrada();

    int posUsuario = localizarUsuario(idUsuario);
    int posLivro = localizarLivro(idLivro);

    // Verifica se o usuario existe
    if(posUsuario == -1)
    {
        printf("\nUsuario nao encontrado!");
        return;
    }

    // Verifica se o livro existe
    if(posLivro == -1)
    {
        printf("\nLivro nao encontrado!");
        return;
    }

    // Verifica disponibilidade do livro
    if(books[posLivro].quantidadeDisponivel <= 0)
    {
        printf("\nNao existe exemplar disponivel!");
        return;
    }

    // Verifica se o usuario ja possui este livro emprestado
    for(int i = 0; i < emprestimostotais; i++)
    {
        if(emprestimos[i].idUsuario == idUsuario && emprestimos[i].idLivro == idLivro && emprestimos[i].ativo == 1)
        {
            printf("\nEste usuario ja possui esse livro!");
            return;
        }
    }

    // Registra emprestimo
    emprestimos[emprestimostotais].idUsuario = idUsuario;
    emprestimos[emprestimostotais].idLivro = idLivro;
    emprestimos[emprestimostotais].ativo = 1;

    emprestimostotais++;

    // Atualiza quantidade disponivel
    books[posLivro].quantidadeDisponivel--;

    // Marca usuario com emprestimo ativo
    user[posUsuario].emprestimo = 1;

    printf("\n=================================");
    printf("\nEmprestimo realizado com sucesso!");
    printf("\nUsuario ID: %d", idUsuario);
    printf("\nLivro ID: %d", idLivro);
    printf("\nExemplares restantes: %d",
           books[posLivro].quantidadeDisponivel);
    printf("\n=================================\n");
}

// devoluçao de livro
void devolverLivro()
{
    int idUsuario;
    int idLivro;

    printf("\nID do usuario: ");
    scanf("%d", &idUsuario);
    limparBufferEntrada();

    printf("ID do livro: ");
    scanf("%d", &idLivro);
    limparBufferEntrada();

    for(int i = 0; i < emprestimostotais; i++)
    {
        if(emprestimos[i].idUsuario == idUsuario && emprestimos[i].idLivro == idLivro && emprestimos[i].ativo == 1)
        {
            emprestimos[i].ativo = 0;

            int posLivro = localizarLivro(idLivro);

            if(posLivro != -1)
            {
                books[posLivro].quantidadeDisponivel++;
            }

            int posUsuario = localizarUsuario(idUsuario);

            if(posUsuario != -1)
            {
                user[posUsuario].emprestimo = 0;
            }

            printf("\n=================================");
            printf("\nLivro devolvido com sucesso!");
            printf("\nUsuario ID: %d", idUsuario);
            printf("\nLivro ID: %d", idLivro);

            if(posLivro != -1)
            {
                printf("\nExemplares disponiveis: %d",
                       books[posLivro].quantidadeDisponivel);
            }

            printf("\n=================================\n");

            return;
        }
    }

    printf("\nEsse emprestimo nao existe!");
}

// lista todos os emprestimos feitos
void listarEmprestimos()
{
    printf("\n===== EMPRESTIMOS ATIVOS =====\n");

    int algumAtivo = 0;

    for(int i = 0; i < emprestimostotais; i++)
    {
        if(emprestimos[i].ativo == 1)
        {
            algumAtivo = 1;
            printf("\nUsuario ID: %d",
                   emprestimos[i].idUsuario);

            printf("\nLivro ID: %d\n",
                   emprestimos[i].idLivro);
        }
    }

    if (!algumAtivo)
    {
        printf("\nNenhum emprestimo ativo no momento.\n");
    }
}

//é tipo uma main de empretimo onde so precia chamar ele na int main
void menuEmprestimos()
{
    int opcao;

    do
    {
        menudeemprestimo();
        if (!lerOpcao(&opcao))
        {
            printf("\nEntrada invalida ou encerrada. Voltando...\n");
            break;
        }

        switch(opcao)
        {
            case 1:
                registrarEmprestimo();
                pausarTela();
                break;

            case 2:
                devolverLivro();
                pausarTela();
                break;

            case 3:
                listarEmprestimos();
                pausarTela();
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!");
                pausarTela();
        }

    }while(opcao != 0);
}

void excluir(){

    int idBusca, encontrado = 0;

    printf("Digite o ID de busca: ");
    scanf("%d",&idBusca);

    limparBufferEntrada();

    for(int i = 0; i < livrosTotais; i++){

        if(books[i].id == idBusca){
            encontrado = 1;

            books[i] = books[livrosTotais - 1];

            livrosTotais--;

            printf("Livro excluido");
            break;
        }

    }

    if (!encontrado)
    {
        printf("\nLivro nao encontrado!");
    }
}

// Submenu de gerenciamento de livros - liga o menu as funcoes ja existentes
void gerenciarLivros()
{
    int opcao;
    int idAchado;
    int idx;

    do
    {
        menuGerenciarLivros();
        if (!lerOpcao(&opcao))
        {
            printf("\nEntrada invalida ou encerrada. Voltando...\n");
            break;
        }

        switch (opcao)
        {
            case 1:
                cadastroGeral();
                pausarTela();
                break;

            case 2:
                limpa();
                Listar();
                pausarTela();
                break;

            case 3:
                idAchado = BuscarId(0);
                if (idAchado != -1)
                {
                    idx = localizarLivro(idAchado);
                    printf("\nTitulo: %s", books[idx].titulo);
                    printf("\nAutor: %s", books[idx].autor);
                    printf("\nAno: %d", books[idx].ano);
                    printf("\nQuantidade: %d", books[idx].quantidade);
                    printf("\nDisponivel: %d\n", books[idx].quantidadeDisponivel);
                }
                else
                {
                    printf("\nLivro nao encontrado!\n");
                }
                pausarTela();
                break;

            case 4:
                Alterar();
                pausarTela();
                break;

            case 5:
                excluir();
                pausarTela();
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!");
                pausarTela();
        }

    } while (opcao != 0);
}

// Cadastra um novo usuario
void cadastroUsuario()
{
    if (usuariosTotais >= MAX_USUARIOS)
    {
        printf("\nLimite maximo de usuarios atingido!\n");
        return;
    }

    printf("Digite o nome do usuario: ");
    fgets(user[usuariosTotais].nome, sizeof(user[usuariosTotais].nome), stdin);
    removerNovaLinha(user[usuariosTotais].nome);

    printf("Digite o telefone do usuario: ");
    scanf("%d", &user[usuariosTotais].telefone);
    limparBufferEntrada();

    printf("Digite o email do usuario: ");
    fgets(user[usuariosTotais].email, sizeof(user[usuariosTotais].email), stdin);
    removerNovaLinha(user[usuariosTotais].email);

    user[usuariosTotais].emprestimo = 0;

    IDdoUsuario++;
    user[usuariosTotais].id = IDdoUsuario;

    usuariosTotais++;

    printf("\nUsuario cadastrado com sucesso! ID: %d\n", user[usuariosTotais - 1].id);
}

// Lista todos os usuarios cadastrados
void listarUsuarios()
{
    printf("\n--- Lista de Usuarios ---\n");

    if (usuariosTotais == 0)
    {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    for (int i = 0; i < usuariosTotais; i++)
    {
        printf("ID: %d | Nome: %s | Tel: %d | E-mail: %s\n",
               user[i].id, user[i].nome, user[i].telefone, user[i].email);
    }
}

// Busca um usuario pelo ID
void buscarUsuario()
{
    printf("\n--- Busca de Usuario ---\n");

    if (usuariosTotais == 0)
    {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    int idBusca;

    printf("Digite o ID do usuario que procura: ");
    scanf("%d", &idBusca);
    limparBufferEntrada();

    int pos = localizarUsuario(idBusca);

    if (pos != -1)
    {
        printf("\nUsuario Encontrado:\n");
        printf("Nome: %s\nTelefone: %d\nE-mail: %s\n",
               user[pos].nome, user[pos].telefone, user[pos].email);
    }
    else
    {
        printf("\nUsuario com o ID %d nao foi encontrado.\n", idBusca);
    }
}

// Altera os dados de um usuario existente
void alterarUsuario()
{
    printf("\n--- Alterar Usuario ---\n");

    if (usuariosTotais == 0)
    {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    int idAlterar;

    printf("Digite o ID do usuario que deseja alterar: ");
    scanf("%d", &idAlterar);
    limparBufferEntrada();

    int pos = localizarUsuario(idAlterar);

    if (pos == -1)
    {
        printf("\nID nao encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    fgets(user[pos].nome, sizeof(user[pos].nome), stdin);
    removerNovaLinha(user[pos].nome);

    printf("Novo telefone: ");
    scanf("%d", &user[pos].telefone);
    limparBufferEntrada();

    printf("Novo email: ");
    fgets(user[pos].email, sizeof(user[pos].email), stdin);
    removerNovaLinha(user[pos].email);

    printf("\nDados alterados com sucesso!\n");
}

// Exclui um usuario pelo ID
void excluirUsuario()
{
    printf("\n--- Excluir Usuario ---\n");

    if (usuariosTotais == 0)
    {
        printf("\nNenhum usuario cadastrado!\n");
        return;
    }

    int idExcluir;

    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &idExcluir);
    limparBufferEntrada();

    int pos = localizarUsuario(idExcluir);

    if (pos == -1)
    {
        printf("\nUsuario nao encontrado.\n");
        return;
    }

    for (int j = pos; j < usuariosTotais - 1; j++)
    {
        user[j] = user[j + 1];
    }

    usuariosTotais--;

    printf("\nUsuario excluido com sucesso!\n");
}

// Submenu de usuarios - agora com o modulo de usuarios implementado
void gerenciarUsuarios()
{
    int opcao;

    do
    {
        menuGerenciarUsuarios();
        if (!lerOpcao(&opcao))
        {
            printf("\nEntrada invalida ou encerrada. Voltando...\n");
            break;
        }

        switch (opcao)
        {
            case 1:
                cadastroUsuario();
                pausarTela();
                break;

            case 2:
                limpa();
                listarUsuarios();
                pausarTela();
                break;

            case 3:
                buscarUsuario();
                pausarTela();
                break;

            case 4:
                alterarUsuario();
                pausarTela();
                break;

            case 5:
                excluirUsuario();
                pausarTela();
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!");
                pausarTela();
        }

    } while (opcao != 0);
}

void estruturaDaMain ()
{
    int opcao = 0;
    enum
    {
        sair = 0,
        modulo1 = 1,
        modulo2 = 2,
        modulo3 = 3,
        modulo4 = 4
    };

    do
    {
        menuPrincipal();
        if (!lerOpcao(&opcao))
        {
            printf("\nEntrada invalida ou encerrada. Saindo...\n");
            break;
        }

        switch (opcao)
        {
            case modulo1:
                gerenciarLivros();
                break;

            case modulo2:
                gerenciarUsuarios();
                break;

            case modulo3:
                menuEmprestimos();
                break;
            case modulo4:
                subMenuRelatorio();
                break;
            
            default:
                if (opcao != sair)
                {
                    printf(" Escolha uma alternativa existente");
                    pausarTela();
                }
                break;
        }
    } while (opcao != sair);
}

void subMenuRelatorio ()
{
    limpa ();
    printf ("\n============ RELATORIO ============\n");
    printf ("1 - Relatorio Sobre usuarios\n");
    printf ("2 - Relatorios Sobre Livros\n");
    printf ("0 - Voltar ao Menu Principal\n");
    printf ("Escolha: ");
}

void relatorioUsuario ()
{
    enum opcoes
    {
        cadastros = 1,
        emprestimos_op = 2,
        atrasos = 3,
        sair = 0
    };

    int opcao = 0;

    do
    {
        limpa ();
        printf ("1 - Usuarios Cadastrados\n");
        printf ("2 - Usuarios Com Emprestimos\n");
        printf ("3 - Usuarios Com Atraso\n");
        printf ("0 - Voltar\n");
        printf ("Escolha: ");
        if (!lerOpcao(&opcao))
        {
            printf("\nEntrada invalida ou encerrada. Voltando...\n");
            break;
        }

        switch (opcao)
        {
            case cadastros:
                limpa();
                usuariosCadastrados();
                pausarTela();
            break;

            case emprestimos_op:
                limpa();
                usuariosComEmprestimo();
                pausarTela();
            break;

            case atrasos:
                limpa();
                printf("\nFuncionalidade de atraso ainda nao implementada.\n");
                pausarTela();
            break;

            case sair:
            break;

            default:
                printf("\nOpcao invalida!\n");
                pausarTela();
            break;

        }
    }while (opcao != sair);
}

void relatorioLivro ()
{
    limpa ();
    printf ("1 - Listar Todos os Livros\n");
    printf ("2 - Listar Por Categoria\n");
    printf ("3 - Livros Disponiveis\n");
    printf ("4 - Livros Emprestados\n");
    printf ("5 - Livros Com atraso\n");
}

void usuariosCadastrados ()
{
    if(usuariosTotais == 0){
        printf ("\nNenhum usuario cadastrado!");
        printf ("\n+===================================+\n");
        printf("==== Pressione enter para sair ====");
        printf ("\n+===================================+\n");
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
}

void usuariosComEmprestimo ()
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
}