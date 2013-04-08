#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX_USUARIOS 100
#define MAX_PRODUTOS 50
#define TAM_NOME_MAX 60
#define MAX_LINHA 256
#define MAX_DIGITOS 10
#define MAX_CAR 20
#define DIAS_UTEIS 7
#define MAX_COMPRAS_SUSP 50

int main()
{
    FILE *arq;
    int cadastro, opcaoinicial, opcaologin;
    mudaCor(Colors_WHITE);

    //cria o arquivo usuarios.txt caso ele nao existir
    arq=fopen("usuarios.txt", "a");
    if(!arq)
    {
            mudaCor(Colors_RED);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            mudaCor(Colors_WHITE);
            getch();
            exit(1);
    }
    fclose(arq);

    //cria o arquivo vestuario.txt caso ele nao existir
    arq=fopen("vestuario.txt", "a");
    if(!arq)
    {
            mudaCor(Colors_RED);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            mudaCor(Colors_WHITE);
            getch();
            exit(1);
    }
    fclose(arq);

    //cria o arquivo eletro.txt caso ele nao exitir
    arq=fopen("eletro.txt", "a");
    if(!arq)
    {
            mudaCor(Colors_RED);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            mudaCor(Colors_WHITE);
            getch();
            exit(1);
    }
    fclose(arq);

    do
         {
             system("cls");
             opcaoinicial=telaInicial();
             switch(opcaoinicial)
             {
                case 1:
                {
                     telaLogin();
                     break;
                }
                case 2:
                {
                     novoUsuario();
                     break;
                }
                case 3:
                {    showInfo();
                     break;
                }
             }
    }while(opcaoinicial!=4);
    system("cls");
    mudaCor(Colors_RED);
    printf("\n                           tMMM0.                        ");
    printf("\n                         1MMMM                           ");
    printf("\n                        :MMMM   :$                       ");
    printf("\n                       .EMMMM  cMM                       ");
    printf("\n                      M  MMMM# ;MMM.                     ");
    printf("\n                     8Mn :MMMMM YMMM                     ");
    printf("\n                     .MM@ .;MMMM MMM                     ");
    printf("\n                       #MMM$ MM0 MMt                     ");
    printf("\n                           ,:YW.#Q                       ");
    printf("\n                    i6WMMM@B@M@MM@$M#0c.                 ");
    printf("\n                        ,:;BUWSQ;,,.                     ");
    printf("\n                           1 c S                         ");
    mudaCor(Colors_BLUE);
    printf("\n                                                         ");
    printf("\n      MM    MM  MMMMMMM  MMMMMMM      MMMMMMM   MMMMMM    ");
    printf("\n      MM    MM  MM       MM   MMM    MM    MM  MMM  MMM   ");
    printf("\n      MM    MM  MM       MM    MM   MM         MMM        ");
    printf("\n      MM    MM  MMMMMM   MMMMMMM   MM   MMMMM  MMMMMM    ");
    printf("\n      MM    MM  MM       MM   MM    MM     MM       MMM   ");
    printf("\n      MMMMMMMM  MM       MM    MM    MM    MM  MMM  MMM     ");
    printf("\n       MMMMM    MM       MW     MM    MMMMMMM   MMMMM     ");
    fflush(stdin);
    getch();
    return(0);
}
