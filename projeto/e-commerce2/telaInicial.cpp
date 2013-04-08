#include "telaInicial.h"

//TELA INICIAL
int telaInicial()
{
     char opcaoTelaInicial;
     int respostaTelaInicial;
     mudaCor(Colors_YELLOW);
     printf("\n         MM                                    ");
     printf("\n        MMM  MM    MM       nc     @Mo         ");
     printf("\n       MMM   MM    MM      bMM.    MMMM        ");
     printf("\n      MM#    MM    MM     cMMMM    MMMMM,      ");
     printf("\n     MME     MM    MM    .MM MMM   MM  MMM     ");
     printf("\n    MM7      MM    MM    MM   MMi  MM   MMM    ");
     printf("\n   MMQ       MM    MM   MM.    MM  MM     MMM  ");
     printf("\n   ;MMM      MMMMMMMM  MMv     MMM MM   ,MMMM  ");
     printf("\n     MMM     MMMMMMMM .MM       MM MM MMMMM    ");
     printf("\n      MMM.   MM    MM  MMM     @MM MMMMMv      ");
     printf("\n        MMM  MM    MM   MM    QMM  MMM         ");
     printf("\n        MMM  MM    MM   .MM  tMM   MM          ");
     printf("\n      .MMz   MM    MM    MM8 MM    MM          ");
     printf("\n     IMM.    MM    MM     MMMM     MM          ");
     printf("\n    MMM      MM    MM     IMM      MM          ");
     printf("\n   MMM       MM    MM      ;       #M          ");
     printf("\n   MM                                          ");
     mudaCor(Colors_WHITE);
     printf("\n================================================================");
     printf("\nSeja bem vindo. O que voce deseja fazer?");
     mudaCor(Colors_GREEN);printf("\nL");mudaCor(Colors_WHITE);printf("ogin");
     mudaCor(Colors_GREEN);printf("\nC");mudaCor(Colors_WHITE);printf("riar nova conta");
     mudaCor(Colors_GREEN);printf("\nI");mudaCor(Colors_WHITE);printf("nformacoes");
     mudaCor(Colors_GREEN);printf("\nS");mudaCor(Colors_WHITE);printf("air");
     printf("\n================================================================\n");
     fflush(stdin);
     do
     {
        mudaCor(Colors_GREEN);
        fflush(stdin);
        scanf("%c", &opcaoTelaInicial);
        opcaoTelaInicial=toupper(opcaoTelaInicial);
        mudaCor(Colors_WHITE);
        switch(opcaoTelaInicial)
        {
            case 'L':
            {    respostaTelaInicial=1;
                 break;
            }
            case 'C':
            {    respostaTelaInicial=2;
                 break;
            }
            case 'I':
            {    respostaTelaInicial=3;
                 break;
            }
            case 'S':
            {    respostaTelaInicial=4;
                 break;
            }
            default:
            {
               mudaCor(Colors_RED);
               printf("Opcao Invalida. Por favor digite uma opcao valida: ");
               mudaCor(Colors_WHITE);
               respostaTelaInicial=0;
            }
        }
     }while(respostaTelaInicial==0);
     return(respostaTelaInicial);
}
