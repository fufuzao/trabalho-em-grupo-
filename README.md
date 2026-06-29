# Sistema de Gestão de Biblioteca

Projeto de um sistema simples para gerenciamento de biblioteca, com módulos para controle de livros, usuários e empréstimos.

## Objetivo

O objetivo do sistema é permitir o cadastro, organização e controle de livros, usuários e empréstimos dentro de uma biblioteca, facilitando a consulta de informações e o gerenciamento da disponibilidade dos livros.

## Menu Principal

```text
1 - Módulo: Gestão de Livros
2 - Módulo: Gestão de Usuários
3 - Módulo: Gestão de Empréstimos
0 - Sair
```

## 1. Módulo: Gestão de Livros

O módulo de gestão de livros será responsável por cadastrar, listar, buscar, alterar e excluir livros do sistema.

### Cadastro de Livros

Cada livro deve possuir as seguintes informações:

| Campo                 | Descrição                                            |
| --------------------- | ---------------------------------------------------- |
| Código                | Identificador único do livro                         |
| Título                | Nome do livro                                        |
| Autor                 | Autor do livro                                       |
| Categoria             | Categoria ou gênero do livro                         |
| Ano                   | Ano de publicação                                    |
| Quantidade total      | Quantidade total de exemplares cadastrados           |
| Quantidade disponível | Quantidade de exemplares disponíveis para empréstimo |

### Operações do Módulo de Livros

* Cadastrar novo livro
* Listar livros cadastrados
* Buscar livro por código, título, autor ou categoria
* Alterar dados de um livro
* Excluir livro do sistema
* Consultar quantidade total e quantidade disponível
