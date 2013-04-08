#include "novoUsuario.h"

//INICIO DA FUNÇÃO PARA CRIAR NOVO USUARIO
void novoUsuario()
{
     FILE *arq;
     USUARIO novoUsuario;
     bool entradaValida;
     int numRegistrosArquivo, i;
     char stringTemp[MAX_LINHA], categoria;
     system("cls");
     arq=fopen("usuarios.txt", "r");
     if(!arq)
     {
             printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
             getch();
             exit(1);
     }
     numRegistrosArquivo=0;
     while(!feof(arq))
     {
        fgets(stringTemp, MAX_LINHA, arq);
        if(stringTemp[0]!='\n')
           numRegistrosArquivo++;
     }
     fclose(arq);
     if(numRegistrosArquivo<MAX_USUARIOS)
     {
         novoUsuario.codigo=numRegistrosArquivo+1;
         mudaCor(Colors_YELLOW);
         printf("\nCADASTRO DE NOVO USUARIO");
         mudaCor(Colors_WHITE);
         printf("\n=============================================================");
         printf("\nSeu cadastro: ");
         mudaCor(Colors_GREEN);
         printf("%d", numRegistrosArquivo+1);
         mudaCor(Colors_WHITE);
         printf("\nInforme o seu nome: ");
         do
         {
             entradaValida=true;
             fflush(stdin);
             mudaCor(Colors_GREEN);
             gets(novoUsuario.nome);
             if(3<=strlen(novoUsuario.nome))
             {
                 for(i=0;i<strlen(novoUsuario.nome);i++)
                 {
                     if(novoUsuario.nome[i]==',')
                     {
                         mudaCor(Colors_RED);
                         printf("Nome informado invalido. Por favor, nao insira virgulas no nome.\n");
                         mudaCor(Colors_WHITE);
                         entradaValida=false;
                     }
                 }
             }
             else
             {
                 mudaCor(Colors_RED);
                 if(strlen(novoUsuario.nome)==0)
                     printf("Por favor, insira um nome valido.\n");
                 else
                     printf("Seu nome deve conter pelo menos 3 letras.\n");
                 mudaCor(Colors_WHITE);
                 entradaValida=false;
             }
         }while(!entradaValida);
         mudaCor(Colors_WHITE);
         printf("Informe sua categoria. (C para cliente ou G para gerente): ");
         entradaValida=false;
         do
         {
             fflush(stdin);
             mudaCor(Colors_GREEN);
             scanf("%c", &categoria);
             categoria=toupper(categoria);
             switch(categoria)
             {
                case 'C':
                {
                     strcpy(novoUsuario.categoria, "cliente");
                     entradaValida=true;
                     break;
                }
                case 'G':
                {
                     strcpy(novoUsuario.categoria, "gerente");
                     entradaValida=true;
                     break;
                }
                default:
                {
                     mudaCor(Colors_RED);
                     printf("Caractere informado invalido! Informe um caractere valido:");
                     break;
                }
             }
          }while(!entradaValida);
          arq=fopen("usuarios.txt", "a");
          if(!arq)
          {
              printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
              getch();
              exit(1);
          }
          fprintf(arq,"%c%d%c%s%c%s", '\n', novoUsuario.codigo, ',', novoUsuario.nome, ',', novoUsuario.categoria);
          fclose(arq);
          mudaCor(Colors_YELLOW);
          printf("\nCadastro criado com sucesso!");
          getch();
          mudaCor(Colors_WHITE);
     }
     else
     {
         mudaCor(Colors_RED);
         printf("Numero maximo de usuarios atingido!");
         fclose(arq);
         mudaCor(Colors_WHITE);
         getch();
     }
}
//FIM DA FUNÇÃO PARA CRIAR NOVO USUARIO
