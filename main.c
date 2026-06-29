
#include <stdio.h>
#include <windows.h>

#define linhas 6
#define  colunas 8
int sala [linhas] [colunas] = {0};


int main(){

SetConsoleOutputCP(CP_UTF8);

int i, j, opcao,opcao2;


    do {
        printf("\n---- Cine prinemax ----\n");
        printf("1 - filmes \n");
        printf("2 - Compra de ingresso\n");
        printf("3 - Comprovante\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
    
        switch(opcao){
            
            
            case 1:


            menufilmes (opcao2);

            break;


            case 2:

            menufilmes (opcao2);
           
            break;

        }
