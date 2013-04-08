#include "menuGerente.h"

//funções de relatorios de gerentes

void relatorioComprasEmAndamento()
{
     FILE *arq;
     int contador, i, totalCarrinhosAbertos, carrinhosAbertos[MAX_USUARIOS], codigo;
     char cadastroEmChar[MAX_DIGITOS], linha[MAX_LINHA];

     system("cls");
     mudaCor(Colors_YELLOW);printf("\nUSUARIOS COM CARRINHOS ABERTOS:");
     mudaCor(Colors_WHITE);printf("\n===============================================================");
     arq=fopen("usuarios.txt", "r");
     if(!arq)
     {
            mudaCor(Colors_RED);printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
            fflush(stdin);getch();exit(1);
     }
     contador=0;
     while(!feof(arq))
     {
        fgets(linha, MAX_LINHA, arq);
        if(linha[0]!='\n')
           contador++;
     }
     fclose(arq);
     //contador verifica quantos usuarios ha cadastrados
     totalCarrinhosAbertos=0;
     for(i=1; i<=contador; i++)
     {
            itoa(i, cadastroEmChar, 10);
            arq=fopen(cadastroEmChar, "rb");
            if(arq)
            {
                carrinhosAbertos[totalCarrinhosAbertos]=i;
                totalCarrinhosAbertos++;
                fclose(arq);
            }
     }

     if(totalCarrinhosAbertos!=0)
     {
            printf("\nTotal de usuarios com carrinhos abertos: ");mudaCor(Colors_GREEN);printf("%d", totalCarrinhosAbertos);
            mudaCor(Colors_WHITE);printf("\nUsuarios com carrinhos abertos:");
            arq=fopen("usuarios.txt", "r");
            if(!arq)
            {
                mudaCor(Colors_RED);printf("\nHouve um problema ao abrir o arquivo, o programa será encerrado.");
                fflush(stdin);getch();exit(1);
            }
             for(i=0; i<totalCarrinhosAbertos; i++)
             {
                rewind(arq);
                while(!feof(arq))
                {
                    fgets(linha, MAX_LINHA, arq);
                    codigo=atoi(strtok(linha, ","));
                    if(codigo==carrinhosAbertos[i])
                    {
                        mudaCor(Colors_WHITE);
                        printf("\n===========================================");
                        printf("\nCodigo: ");mudaCor(Colors_GREEN);printf("%d", codigo);
                        mudaCor(Colors_WHITE);
                        printf("\nNome: ");mudaCor(Colors_GREEN);printf("%s", strtok(NULL, ","));
                        mudaCor(Colors_WHITE);
                        printf("\nTipo: ");mudaCor(Colors_GREEN);printf("%s", strtok(NULL, "\n"));
                    }
                }
            }
            fflush(stdin);getch();
    }
    else
    {
        printf("\nNao ha nenhum cliente com o carrinho de compras aberto.");
        fflush(stdin);getch();
    }
}

void vendas()
{
     FILE *arq;
     char dia[MAX_DIGITOS], mes[MAX_DIGITOS], ano[MAX_DIGITOS], linha[MAX_LINHA];
     char comp[MAX_LINHA];
     int confirmacao, vendasEletro=0, vendasVestuario=0;
     bool  encontrou=false;
     float valorTotalVendas=0;

     system("cls");
     mudaCor(Colors_YELLOW);printf("\nVENDAS POR TIPO:");
     mudaCor(Colors_WHITE);printf("\n======================================================");
     printf("\nInforme uma data. Ex (8, jul , 2010)");
     printf("\nDia: ");mudaCor(Colors_GREEN);fflush(stdin);gets(dia);
     mudaCor(Colors_WHITE);printf("Mes: ");mudaCor(Colors_GREEN);fflush(stdin);gets(mes);strupr(mes);
     mudaCor(Colors_WHITE);printf("Ano: ");mudaCor(Colors_GREEN);fflush(stdin);gets(ano);
     arq=fopen("report.txt", "r");
     if(arq)
     {
             while(!feof(arq))
             {
                 fgets(linha, MAX_LINHA, arq);
                 if(linha[0]!='\n')
                 {
                     confirmacao=0;
                     strcpy(comp, strtok(linha, ","));
                     if(strcmp(dia, comp)==0)
                     {
                        confirmacao++;
                     }
                     strcpy(comp, strtok(NULL, ","));
                     if(strcmp(mes, comp)==0)
                     {
                        confirmacao++;
                     }
                     strcpy(comp, strtok(NULL, ","));
                     if(strcmp(ano, comp)==0)
                     {
                        confirmacao++;
                     }
                     if(confirmacao==3)
                     {
                         vendasEletro+=atoi(strtok(NULL, ","));
                         vendasVestuario+=atoi(strtok(NULL, ","));
                         valorTotalVendas+=atof(strtok(NULL, "\n"));
                         encontrou=true;
                     }
                 }
             }
             fclose(arq);
             if(encontrou)
             {
                 mudaCor(Colors_WHITE);printf("\nTotal de vendas no dia ");mudaCor(Colors_GREEN);printf("%s", dia);
                 mudaCor(Colors_WHITE);printf("/");mudaCor(Colors_GREEN);printf("%s", mes);mudaCor(Colors_GREEN);printf("/");
                 mudaCor(Colors_GREEN);printf("%s", ano);mudaCor(Colors_WHITE);printf(":");
                 printf("\nNumero de eletrodomesticos vendidos: ");mudaCor(Colors_GREEN);printf("%d", vendasEletro);
                 mudaCor(Colors_WHITE);printf("\nNumero de pecas de vestuario vendidas: ");
                 mudaCor(Colors_GREEN);printf("%d", vendasVestuario);mudaCor(Colors_WHITE);
                 printf("\nTotal de vendas: R$ ");mudaCor(Colors_GREEN);printf("%.2f", valorTotalVendas);
                 fflush(stdin);getch();
             }
             else
             {
                 mudaCor(Colors_RED);printf("\nA data informada nao foi encontrada nos registros.");
                 fflush(stdin);getch();
             }
     }
     else
     {
         mudaCor(Colors_RED);printf("\nNenhuma venda foi efetuada ainda.");
         fflush(stdin);getch();
     }
}

void verificaEstoque()
{
     FILE *arq;
     char linha[MAX_LINHA];

     //imprime eletro
     system("cls");
     mudaCor(Colors_YELLOW);printf("\nESTOQUE:");
     mudaCor(Colors_WHITE);printf("\n===============================================================");
     arq=fopen("eletro.txt", "r");
     mudaCor(Colors_YELLOW);printf("\nEletrodomesticos:");
     while(!feof(arq))
     {
         fgets(linha, sizeof(linha), arq);
         mudaCor(Colors_WHITE);printf("\n====================================================");
         printf("\nCodigo do produto: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(linha,","));
         mudaCor(Colors_WHITE);printf("\nDescricao do produto: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));
         mudaCor(Colors_WHITE);printf("\nAltura: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));mudaCor(Colors_WHITE);printf(" cm");
         mudaCor(Colors_WHITE);printf("\nLargura: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));mudaCor(Colors_WHITE);printf(" cm");
         mudaCor(Colors_WHITE);printf("\nProfundidade: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));mudaCor(Colors_WHITE);printf(" cm");
         mudaCor(Colors_WHITE);printf("\nPreco:");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));mudaCor(Colors_WHITE);printf(" reais");
         mudaCor(Colors_YELLOW);printf("\nEstoque: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));mudaCor(Colors_WHITE);printf(" unidades");
         mudaCor(Colors_WHITE);printf("\nCor do produto: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,"\n"));
     }
     fclose(arq);
     fflush(stdin);getch();
     //imprime vestuario
     system("cls");
     mudaCor(Colors_YELLOW);printf("\nESTOQUE:");
     mudaCor(Colors_WHITE);printf("\n===============================================================");
     arq=fopen("vestuario.txt", "r");
     mudaCor(Colors_YELLOW);printf("\nVestuario:");
     while(!feof(arq))
     {
         fgets(linha, sizeof(linha), arq);
         mudaCor(Colors_WHITE);printf("\n====================================================");
         printf("\nCodigo do produto: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(linha,","));
         mudaCor(Colors_WHITE);printf("\nDescricao do produto: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));
         mudaCor(Colors_WHITE);printf("\nTamanho: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));
         mudaCor(Colors_WHITE);printf("\nPreco:");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));mudaCor(Colors_WHITE);printf(" reais");
         mudaCor(Colors_YELLOW);printf("\nEstoque: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));mudaCor(Colors_WHITE);printf(" unidades");
         mudaCor(Colors_WHITE);printf("\nCor do produto: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,","));
         mudaCor(Colors_WHITE);printf("\nGenero: ");
         mudaCor(Colors_GREEN);printf("%s", strtok(NULL,"\n"));
     }
     fclose(arq);
     fflush(stdin);getch();
}

void clientesCadastrados()
{
      FILE *arq;
      char stringTemp[MAX_LINHA];

      system("cls");
      mudaCor(Colors_YELLOW);printf("\nCLIENTES CADASTRADOS:");
      mudaCor(Colors_WHITE);printf("\n=======================================================");
      arq=fopen("usuarios.txt", "r");
      if(!arq)
      {
             mudaCor(Colors_RED);printf("\nHouve um problema ao abrir o arquivo, o programa será encerrado.");
             fflush(stdin);getch();exit(1);
      }
      while(!feof(arq))
      {
          fgets(stringTemp, sizeof(stringTemp), arq);
          printf("\n===========================================");
          printf("\nCodigo: ");mudaCor(Colors_GREEN);printf("%s", strtok(stringTemp, ","));
          mudaCor(Colors_WHITE);
          printf("\nNome: ");mudaCor(Colors_GREEN);printf("%s", strtok(NULL, ","));
          mudaCor(Colors_WHITE);
          printf("\nTipo: ");mudaCor(Colors_GREEN);printf("%s", strtok(NULL, "\n"));
          mudaCor(Colors_WHITE);printf("\n===========================================");
      }
      fflush(stdin);getch();
}


void menuGerente(char nome[], int cadastro)
{
    char opcaoMenuGerente;               //resposta caracter informada pelo usuario
    int respostaMenuGerente=0;           //resposta devolvida pela funcao

    do
    {
        system("cls");
        mudaCor(Colors_YELLOW);printf("\nGERENTE: ");
        mudaCor(Colors_GREEN);printf(" %s", nome);
        mudaCor(Colors_WHITE);printf("\nData: %s Hora: %s",__DATE__,__TIME__);
        printf("\n====================================================================");
        printf("\nSelecione a letra correspondente em verde para acessar a opcao.\n");
        mudaCor(Colors_GREEN);printf("\nT");mudaCor(Colors_WHITE);printf("rocar Usuario");
        mudaCor(Colors_GREEN);printf("\n\nP");mudaCor(Colors_WHITE);printf("esquisar");
        printf("\n\nRelatorios:");
        mudaCor(Colors_GREEN);
        printf("\nC");mudaCor(Colors_WHITE);printf("ompras em Andamento");
        mudaCor(Colors_GREEN);printf("\nV");mudaCor(Colors_WHITE);printf("endas");
        mudaCor(Colors_GREEN);printf("\nE");mudaCor(Colors_WHITE);printf("stoque");
        printf("\nC");mudaCor(Colors_GREEN);printf("l");mudaCor(Colors_WHITE);printf("lientes Cadastrados");
        printf("\n==================================================================\n");
        do
        {
            mudaCor(Colors_GREEN);
            fflush(stdin);
            scanf("%c", &opcaoMenuGerente);
            respostaMenuGerente=toupper(opcaoMenuGerente);
            mudaCor(Colors_WHITE);
            switch(opcaoMenuGerente)
            {
                case 'T':
                {    respostaMenuGerente=10;
                     break;
                }
                case 'P':
                {
                     pesquisaProduto();
                     respostaMenuGerente=1;
                     break;
                }
                case 'C':
                {
                     relatorioComprasEmAndamento();
                     respostaMenuGerente=1;
                     break;
                }
                case 'V':
                {
                     vendas();
                     respostaMenuGerente=1;
                     break;
                }
                case 'E':
                {
                     verificaEstoque();
                     respostaMenuGerente=1;
                     break;
                }
                case 'L':
                {
                     clientesCadastrados();
                     respostaMenuGerente=1;
                     break;
                }
                default:
                {
                   mudaCor(Colors_RED);
                   printf("Opcao invalida. Por favor digite uma opcao valida: ");
                   respostaMenuGerente=0;
                }
            }
         }while(respostaMenuGerente==0);
    }while(respostaMenuGerente!=10);
}
