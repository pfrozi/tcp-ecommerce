#include "telaLogin.h"

//INICIO DA TELA DE LOGIN
void telaLogin()
{
    FILE *arq;
    int codCadastro, codComparaCadastro, verificaEntreClienteGerente;
    bool achouCadastro=false;
    char stringTemp[MAX_LINHA], tipoCliente[TAM_NOME_MAX], nomeCliente[TAM_NOME_MAX];
    system("cls");
    mudaCor(Colors_YELLOW);
    printf("\nLOGIN");
    mudaCor(Colors_WHITE);
    printf("\n=================================================================");
    printf("\nInforme seu numero de cadastro: ");
    do
    {
            mudaCor(Colors_GREEN);
            scanf("%d", &codCadastro);
            mudaCor(Colors_WHITE);
            arq=fopen("usuarios.txt", "r");
            if(!arq)
            {
                    mudaCor(Colors_RED);
                    printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
                    mudaCor(Colors_WHITE);
                    getch();
                    exit(1);
            }
            while(!feof(arq) && achouCadastro==false)
            {
                 fgets(stringTemp, sizeof(stringTemp), arq);
                 codComparaCadastro=atoi(strtok(stringTemp, ","));
                 if(codCadastro==codComparaCadastro)
                 {
                     strcpy(nomeCliente, strtok(NULL, ","));
                     strcpy(tipoCliente, (strtok(NULL, "\n")));
                     achouCadastro=true;
                 }
            }
            fclose(arq);
            if(achouCadastro==true)
            {
                verificaEntreClienteGerente=strcmp("gerente", tipoCliente);
                if(verificaEntreClienteGerente==0)
                   menuGerente(nomeCliente, codCadastro);
                else
                   menuCliente(nomeCliente, codCadastro);
            }
            else
            {
                mudaCor(Colors_RED);
                printf("Usuario nao encontrado. Informe outro cadastro: ");
                mudaCor(Colors_YELLOW);
                getch();
            }
    }while(achouCadastro==false);
}
//FIM DA TELA DE LOGIN
