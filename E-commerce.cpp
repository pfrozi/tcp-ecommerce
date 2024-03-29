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


typedef struct
{
        int codigo;
        char nome[TAM_NOME_MAX];
        char categoria[TAM_NOME_MAX];
}USUARIO;

typedef struct
{
        USUARIO cadastro[MAX_USUARIOS];
        int totalUsuarios;
}CADASTRO;

typedef struct
{
        int codigo;
        char descricao[TAM_NOME_MAX];
        int altura;
        int largura;
        int profundidade;
        float preco;
        int estoque;
        char cor[TAM_NOME_MAX];
}ELETRO;

typedef struct
{
        int codigo;
        char descricao[TAM_NOME_MAX];
        char tamanho[TAM_NOME_MAX];
        float preco;
        int estoque;
        char cor[TAM_NOME_MAX];
        char genero[TAM_NOME_MAX];
}VESTUARIO;

typedef struct
{
        ELETRO eletronico[MAX_CAR];
        VESTUARIO vestuario[MAX_CAR];
        int itensEletro;
        int itensVestuario;
}CARRINHO;

typedef struct
{
        int valorTotal;
        int qtdEletronico;
        int qtdVestuario;
}VENDA;


typedef enum {Colors_BLUE = 9, Colors_GREEN = 10, Colors_RED = 12, Colors_YELLOW = 14, Colors_WHITE = 15} Colors;

void mudaCor (Colors cor){
    textcolor(cor);
}

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

//MOSTRA AS INFORMACOES DO PROGRAMA.
void showInfo()
{
     system("cls");
     mudaCor(Colors_YELLOW);
     printf("\nINFORMACOES DO PROGRAMA:");
     mudaCor(Colors_WHITE);
     printf("\n================================================================");
     printf("\nPrograma desenvolvido pelos alunos X e Y para a disciplina Z ");
     printf("\n O programa gera um arquivo chamado report.txt que contro");
     printf("\nla as vendas e suas respectivas datas e necessita dos arquivos");
     printf("\neletro.txt, vestuario.txt e usuarios.txt para controlar os esto-");
     printf("\nques e os cadastros.");
     printf("\n================================================================");
     fflush(stdin);
     getch();
}
//FIM DA FUNCAO QUE MOSTRA AS INFORMACOES DO PROGRAMA

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

void insereProdutoCarrinho(int cadastro)
{
     FILE *arq, *arq2;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;
     char cadastroEmChar[MAX_DIGITOS], stringTemp[MAX_LINHA], salvaLinha[MAX_PRODUTOS][MAX_LINHA];
     int codigoProduto, quantidadeProduto, codigoCompara, contalinha=0, i;
     bool achouProduto=false, carrinhoDisponivel;

     system("cls");
     mudaCor(Colors_YELLOW);printf("\nINSERIR NOVO ITEM NO CARRINHO DE COMPRAS");
     mudaCor(Colors_WHITE);printf("\n==========================================================================");
     printf("\nDigite o codigo do produto que voce quer adicionar ao seu carrinho: ");
     do
     {
             mudaCor(Colors_GREEN);
             scanf("%d", &codigoProduto);
             mudaCor(Colors_WHITE);
             printf("Digite a quantidade do produto que voce quer adicionar ao seu carrinho: ");
             do
             {
                 mudaCor(Colors_GREEN);
                 scanf("%d", &quantidadeProduto);
                 if(quantidadeProduto<=0 || MAX_CAR<quantidadeProduto)
                 {
                     mudaCor(Colors_RED);printf("Quantidade muito grande. Informe uma quantidade de no maximo %d itens: ", MAX_CAR);
                 }
             }while(quantidadeProduto<=0 || MAX_CAR<quantidadeProduto);
             mudaCor(Colors_WHITE);
             //abre o arquivo de eletrodomesticos para procurar o codigo
             arq=fopen("eletro.txt", "r+");
             if(!arq)
             {
                 mudaCor(Colors_RED);
                 printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                 mudaCor(Colors_WHITE);
                 getch();
                 exit(1);
             }
             while((!feof(arq)) && (achouProduto==false))
             {
                 fgets(stringTemp, sizeof(stringTemp), arq);
                 codigoCompara=atoi(strtok(stringTemp, ","));
                 if(codigoProduto==codigoCompara)
                 {
                      achouProduto=true;
                      eletronico.codigo=codigoProduto;
                      strcpy(eletronico.descricao, strtok(NULL, ","));
                      eletronico.altura=atoi(strtok(NULL, ","));
                      eletronico.largura=atoi(strtok(NULL, ","));
                      eletronico.profundidade=atoi(strtok(NULL, ","));
                      eletronico.preco=atof(strtok(NULL, ","));
                      eletronico.estoque=atoi(strtok(NULL, ","));
                      strcpy(eletronico.cor, strtok(NULL, "\n"));
                      mudaCor(Colors_GREEN);printf("\nProduto a ser adicionado: \n");mudaCor(Colors_WHITE);
                      printf("%s   Altura: %d cm    Largura: %d cm" , eletronico.descricao, eletronico.altura, eletronico.largura);
                      printf("\nEstoque: %d   Profundidade: %d cm    Preco: %.2f    Cor: %s", eletronico.estoque, eletronico.profundidade, eletronico.preco, eletronico.cor);
                      printf("\n==========================================================================");
                      fflush(stdin);
                      getch();
                 }
             }
             fclose(arq);

             if(achouProduto==true)
             {
                      if(quantidadeProduto<=eletronico.estoque)
                      {
                               //abre o arquivo de carrinho para salvar
                                carrinhoDisponivel=true;
                                itoa(cadastro, cadastroEmChar, 10); //converte o codigo para char
                                arq=fopen(cadastroEmChar, "rb");
                                if(!arq)
                                {
                                       arq=fopen(cadastroEmChar, "wb");
                                }
                                if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                {
                                          if(carrinho.itensEletro+quantidadeProduto<=MAX_CAR)
                                          {
                                               for(i=carrinho.itensEletro; i<(carrinho.itensEletro+quantidadeProduto); i++)
                                               {
                                                    carrinho.eletronico[i]=eletronico;
                                               }
                                               carrinho.itensEletro+=quantidadeProduto;
                                          }
                                          else
                                          {
                                              mudaCor(Colors_RED);printf("\nSeu carrinho de eletrodomesticos ja esta cheio.");
                                              mudaCor(Colors_WHITE);fflush(stdin);getch();
                                              carrinhoDisponivel=false;
                                          }
                                }
                                else
                                {
                                    carrinho.itensEletro=0;
                                    if(carrinho.itensEletro+quantidadeProduto<=MAX_CAR)
                                    {
                                           for(i=carrinho.itensEletro; i<(carrinho.itensEletro+quantidadeProduto); i++)
                                           {
                                                carrinho.eletronico[i]=eletronico;
                                           }
                                           carrinho.itensEletro+=quantidadeProduto;
                                    }
                                    else
                                    {
                                        mudaCor(Colors_RED);printf("\nSeu carrinho de eletrodomesticos ja esta cheio.");
                                        mudaCor(Colors_WHITE);fflush(stdin);getch();
                                        carrinhoDisponivel=false;
                                    }
                                }
                                fclose(arq);
                                if(carrinhoDisponivel==true)  //ha espaco no carrinho
                                {
                                    arq=fopen(cadastroEmChar, "wb");
                                    if(!arq)
                                    {
                                            mudaCor(Colors_RED);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                    {
                                           mudaCor(Colors_YELLOW);printf("\nOs itens foram adicionados ao carrinho com sucesso.");
                                           fflush(stdin);getch();mudaCor(Colors_WHITE);
                                    }
                                    else
                                    {
                                        mudaCor(Colors_RED);printf("\nHouve um problema ao adicionar os itens ao carrinho.");
                                        fflush(stdin);getch();mudaCor(Colors_WHITE);
                                    }
                                    fclose(arq);
                                    //edita o estoque
                                    arq=fopen("eletro.txt", "r+");
                                    if(!arq)
                                    {
                                            mudaCor(Colors_RED);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    contalinha=0;
                                    while(!feof(arq))
                                    {
                                        fgets(salvaLinha[contalinha], sizeof(salvaLinha[contalinha]), arq);
                                        contalinha++;
                                    }
                                    fclose(arq);
                                    remove("eletro.txt");

                                    arq=fopen("eletro.txt", "w");
                                    if(!arq)
                                    {
                                            mudaCor(Colors_RED);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    eletronico.estoque=eletronico.estoque-quantidadeProduto;
                                    for(i=0; i<contalinha; i++)
                                    {
                                        strcpy(stringTemp, salvaLinha[i]);
                                        codigoCompara=atoi(strtok(stringTemp, ","));
                                        if(codigoCompara!=codigoProduto)
                                        {
                                           fputs(salvaLinha[i], arq);
                                        }
                                        else
                                        {
                                            fseek(arq, 0*sizeof(char), SEEK_END);
                                            fprintf(arq,"%d%c%s%c%d%c%d%c%d%c%.2f%c%d%c%s%c", eletronico.codigo, ',', eletronico.descricao, ',', eletronico.altura, ',', eletronico.largura, ',', eletronico.profundidade, ',', eletronico.preco, ',', eletronico.estoque, ',', eletronico.cor, '\n');
                                        }
                                    }
                                    fclose(arq);
                               }
                      }
                      else
                      {
                          mudaCor(Colors_RED);
                          printf("\nDesculpe. Nao ha itens em estoque suficientes para efetuar a compra.");
                          mudaCor(Colors_WHITE);fflush(stdin);getch();
                      }
             }
             else //caso nao tenha achado nos eletrodomesticos, procura no vestuario
             {
                     arq=fopen("vestuario.txt", "r+");
                     if(!arq)
                     {
                         mudaCor(Colors_RED);
                         printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                         mudaCor(Colors_WHITE);
                         getch();
                         exit(1);
                     }
                     while((!feof(arq)) && (achouProduto==false))
                     {
                         fgets(stringTemp, sizeof(stringTemp), arq);
                         codigoCompara=atoi(strtok(stringTemp, ","));
                         if(codigoProduto==codigoCompara)
                         {
                              achouProduto=true;
                              vestuario.codigo=codigoProduto;
                              strcpy(vestuario.descricao, strtok(NULL, ","));
                              strcpy(vestuario.tamanho, strtok(NULL, ","));
                              vestuario.preco=atof(strtok(NULL, ","));
                              vestuario.estoque=atoi(strtok(NULL, ","));
                              strcpy(vestuario.cor, strtok(NULL, ","));
                              strcpy(vestuario.genero, strtok(NULL, "\n"));
                              mudaCor(Colors_GREEN);printf("\nProduto a ser adicionado: \n");
                              mudaCor(Colors_WHITE);
                              printf("%s    Tamanho: %s    Preco: %.2f" , vestuario.descricao, vestuario.tamanho, vestuario.preco);
                              printf("\nEstoque: %d    Cor: %s    Genero: %s", vestuario.estoque, vestuario.cor, vestuario.genero);
                              printf("\n==========================================================================");
                              fflush(stdin);getch();
                         }
                     }
                     fclose(arq);
                     //confere se achou nos vestuarios
                     if(achouProduto==true)
                     {
                              if(quantidadeProduto<=vestuario.estoque)
                              {
                                        carrinhoDisponivel=true;
                                        itoa(cadastro, cadastroEmChar, 10); //converte o codigo para char
                                        arq=fopen(cadastroEmChar, "rb");
                                        if(!arq)
                                        {
                                               arq=fopen(cadastroEmChar, "wb");
                                        }
                                        if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                        {
                                                  if(carrinho.itensVestuario+quantidadeProduto<=MAX_CAR)
                                                  {
                                                       for(i=carrinho.itensVestuario; i<(carrinho.itensVestuario+quantidadeProduto); i++)
                                                       {
                                                            carrinho.vestuario[i]=vestuario;
                                                       }
                                                       carrinho.itensVestuario+=quantidadeProduto;
                                                  }
                                                  else
                                                  {
                                                      mudaCor(Colors_RED);printf("\nSeu carrinho de vestuario ja esta cheio.");
                                                      mudaCor(Colors_WHITE);fflush(stdin);getch();
                                                      carrinhoDisponivel=false;
                                                  }
                                        }
                                        else
                                        {
                                            carrinho.itensVestuario=0;
                                            if(carrinho.itensVestuario+quantidadeProduto<=MAX_CAR)
                                            {
                                                   for(i=carrinho.itensVestuario; i<(carrinho.itensVestuario+quantidadeProduto); i++)
                                                   {
                                                        carrinho.vestuario[i]=vestuario;
                                                   }
                                                   carrinho.itensVestuario+=quantidadeProduto;
                                            }
                                            else
                                            {
                                                mudaCor(Colors_RED);printf("\nSeu carrinho de vestuario ja esta cheio.");
                                                mudaCor(Colors_WHITE);fflush(stdin);getch();
                                                carrinhoDisponivel=false;
                                            }
                                        }
                                        fclose(arq);
                                        if(carrinhoDisponivel==true)  //ha espaco no carrinho
                                        {
                                            arq=fopen(cadastroEmChar, "wb");
                                            if(!arq)
                                            {
                                                    mudaCor(Colors_RED);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                            {
                                                 mudaCor(Colors_YELLOW);printf("\nOs itens foram adicionados ao carrinho com sucesso.");
                                                 fflush(stdin);getch();mudaCor(Colors_WHITE);
                                            }
                                            else
                                            {
                                                 mudaCor(Colors_RED);printf("\nHouve um problema ao adicionar os itens ao carrinho.");
                                                 fflush(stdin);getch();mudaCor(Colors_WHITE);
                                            }
                                            fclose(arq);
                                            //edita o estoque
                                            arq=fopen("vestuario.txt", "r+");
                                            if(!arq)
                                            {
                                                    mudaCor(Colors_RED);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            contalinha=0;
                                            while(!feof(arq))
                                            {
                                                fgets(salvaLinha[contalinha], sizeof(salvaLinha[contalinha]), arq);
                                                contalinha++;
                                            }
                                            fclose(arq);
                                            remove("vestuario.txt");

                                            arq=fopen("vestuario.txt", "w");
                                            if(!arq)
                                            {
                                                    mudaCor(Colors_RED);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            vestuario.estoque=vestuario.estoque-quantidadeProduto;
                                            for(i=0; i<contalinha; i++)
                                            {
                                                strcpy(stringTemp, salvaLinha[i]);
                                                codigoCompara=atoi(strtok(stringTemp, ","));
                                                if(codigoCompara!=codigoProduto)
                                                {
                                                   fputs(salvaLinha[i], arq);
                                                }
                                                else
                                                {
                                                    fseek(arq, 0*sizeof(char), SEEK_END);
                                                    fprintf(arq,"%d%c%s%c%s%c%.2f%c%d%c%s%c%s%c", vestuario.codigo, ',', vestuario.descricao, ',', vestuario.tamanho, ',', vestuario.preco, ',', vestuario.estoque, ',', vestuario.cor, ',', vestuario.genero, '\n');
                                                }
                                            }
                                            fclose(arq);
                                    }
                              }
                              else
                              {
                                  mudaCor(Colors_RED);
                                  printf("\nDesculpe. Nao ha itens em estoque suficientes para efetuar a compra.");
                                  mudaCor(Colors_WHITE);fflush(stdin);getch();
                              }
                     }
             }
             if(achouProduto==false)
             {
                 mudaCor(Colors_RED);printf("Codigo buscado nao encontrado, por favor digite um codigo valido.");
             }
     }while(achouProduto==false);
}



//funcao usadas pela funcao pesquisa
void imprimeVestuario(VESTUARIO produtoVestuario)
{
    mudaCor(Colors_WHITE);
    printf("\nCodigo: %d  Descricao: %s\n",produtoVestuario.codigo, produtoVestuario.descricao);
    printf("Tamanho: %s  Preco: %.2f  Estoque:  %d\n",produtoVestuario.tamanho, produtoVestuario.preco, produtoVestuario.estoque);
    printf("Cor: %s  Genero: %s\n",produtoVestuario.cor, produtoVestuario.genero);
    printf("\n================================================================");
}
//funcao usadas pela funcao pesquisa
void imprimeEletro(ELETRO produtoEletro)
{
     mudaCor(Colors_WHITE);
     printf("\nCodigo: %d  Descricao: %s\n",produtoEletro.codigo, produtoEletro.descricao);
     printf("Altura: %d cm  Largura: %d cm  Profundidade:  %d cm\n",produtoEletro.altura, produtoEletro.largura, produtoEletro.profundidade);
     printf("Preco: %.2f Reais  Produtos em estoque: %d  Cor: %s\n",produtoEletro.preco, produtoEletro.estoque, produtoEletro.cor);
     printf("\n================================================================");
}

void pesquisaProduto()
{
    FILE *arq;
    char opcao, resposta;
    char linha[MAX_LINHA];
    ELETRO produtoEletro;
    VESTUARIO produtoVestuario;
    char *r;
    char objeto[TAM_NOME_MAX];
    int encontrados[TAM_NOME_MAX];
    int i=0;
    float precoMin;
    float precoMax;
    bool continuaPesquisa;
    int produtosEncontrados=0;
    bool opcaoValida=false;

    do
    {
            system("cls");
            mudaCor(Colors_YELLOW);
            printf("\nPESQUISA:");
            mudaCor(Colors_WHITE);
            printf("\n=================================================================");
            printf("\nO que voce deseja pesquisar?");
            mudaCor(Colors_GREEN);
            printf("\nE");mudaCor(Colors_WHITE);printf("letronico           ");mudaCor(Colors_GREEN);printf("V");mudaCor(Colors_WHITE);printf("estuario\n");
            opcaoValida=false;
            produtosEncontrados=0;
            do
            {
                mudaCor(Colors_GREEN);
                fflush(stdin);
                scanf("%c",&opcao);
                opcao=toupper(opcao);
                if(opcao=='E')
                   opcaoValida=true;
                if(opcao=='V')
                   opcaoValida=true;
                if(opcaoValida!=true)
                {
                    mudaCor(Colors_RED);
                    printf("Opcao invalida. Por favor digite uma opcao valida: ");
                }
            }while(opcaoValida!=true);
            mudaCor(Colors_WHITE);
            switch(opcao)
            {
                case 'E':
                     arq = fopen("eletro.txt","r");
                     if(!arq)
                     {
                         mudaCor(Colors_RED);
                         puts("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                         getch();
                         exit(1);
                     }
                     printf("\n=================================================================");
                     printf("\nComo voce deseja pesquisar o produto?");
                     mudaCor(Colors_GREEN);printf("\nD");mudaCor(Colors_WHITE);printf("escricao    ");mudaCor(Colors_GREEN);printf("C");mudaCor(Colors_WHITE);printf("or");mudaCor(Colors_GREEN);printf("    P");mudaCor(Colors_WHITE);printf("reco\n");
                     opcaoValida=false;
                     do
                     {
                         mudaCor(Colors_GREEN);
                         fflush(stdin);
                         scanf("%c",&opcao);
                         opcao=toupper(opcao);
                         if(opcao=='D')
                             opcaoValida=true;
                         if(opcao=='C')
                              opcaoValida=true;
                         if(opcao=='P')
                              opcaoValida=true;
                         if(opcaoValida!=true)
                         {
                              mudaCor(Colors_RED);
                              printf("Opcao invalida. Por favor digite uma opcao valida: ");
                         }
                     }while(opcaoValida!=true);
                     mudaCor(Colors_WHITE);
                     switch(opcao)
                     {
                         case 'D':
                             printf("Informe a descricao buscada: ");
                             fflush(stdin);
                             mudaCor(Colors_GREEN);
                             gets(objeto);
                             strcpy(objeto,strlwr(objeto));
                             break;
                         case 'C':
                             printf("Informe a cor buscada: ");
                             fflush(stdin);
                             mudaCor(Colors_GREEN);
                             gets(objeto);
                             strcpy(objeto,strlwr(objeto));
                             break;
                         case 'P':
                             printf("Informe o preco minimo buscado: ");
                             mudaCor(Colors_GREEN);
                             scanf("%f",&precoMin);
                             mudaCor(Colors_WHITE);
                             printf("Informe o preco maximo buscado: ");
                             mudaCor(Colors_GREEN);
                             scanf("%f",&precoMax);
                             break;
                     }
                     mudaCor(Colors_WHITE);
                     while(!feof(arq))
                     {
                         r = fgets(linha,MAX_LINHA,arq);
                         if (r)
                         {

                             produtoEletro.codigo = atoi(strtok(linha,","));
                             strcpy(produtoEletro.descricao,(strtok(NULL,",")));
                             produtoEletro.altura = atoi(strtok(NULL,","));
                             produtoEletro.largura = atoi(strtok(NULL,","));
                             produtoEletro.profundidade = atoi(strtok(NULL,","));
                             produtoEletro.preco = atof(strtok(NULL,","));
                             produtoEletro.estoque = atoi(strtok(NULL,","));
                             strcpy(produtoEletro.cor,strtok(NULL,"\n"));

                             if(opcao == 'D' && (strcmp(objeto,produtoEletro.descricao) == 0))
                             {
                                 imprimeEletro(produtoEletro);
                                 encontrados[i] = produtoEletro.codigo;
                                 i++;
                                 produtosEncontrados++;
                             }
                             else
                                 if(opcao == 'C' && (strcmp(objeto,produtoEletro.cor) == 0))
                                 {
                                     imprimeEletro(produtoEletro);
                                     encontrados[i] = produtoEletro.codigo;
                                     i++;
                                     produtosEncontrados++;
                                 }
                                 else
                                     if(opcao == 'P' && produtoEletro.preco <= precoMax && produtoEletro.preco >= precoMin)
                                     {
                                         imprimeEletro(produtoEletro);
                                         encontrados[i] = produtoEletro.codigo;
                                         i++;
                                         produtosEncontrados++;
                                     }
                             }

                     }
                     if(produtosEncontrados==0)
                     {
                         mudaCor(Colors_RED);
                         printf("\nNenhum produto encontrado.");
                         fflush(stdin);getchar();
                         mudaCor(Colors_WHITE);
                     }
                     else
                     {
                         printf("\nForam encontrados ");
                         mudaCor(Colors_GREEN);
                         printf("%d", produtosEncontrados);
                         mudaCor(Colors_WHITE);
                         printf(" produtos.");
                         fflush(stdin);getchar();
                     }fclose(arq);break;

                     case 'V':
                     arq = fopen("vestuario.txt","r");
                     if(arq == NULL)
                     {
                         mudaCor(Colors_RED);
                         printf("Houve um erro ao abrir o arquivo. O programa sera terminado.");
                         fflush(stdin);getch();
                         exit(1);
                     }
                     else
                         printf("\n=================================================================");
                         printf("\nComo voce deseja pesquisar o produto?");
                         mudaCor(Colors_GREEN);printf("\nD");mudaCor(Colors_WHITE);printf("escricao    ");mudaCor(Colors_GREEN);printf("C");mudaCor(Colors_WHITE);printf("or");mudaCor(Colors_GREEN);printf("    P");mudaCor(Colors_WHITE);printf("reco");mudaCor(Colors_GREEN);
                         printf("\nG");mudaCor(Colors_WHITE);printf("enero");mudaCor(Colors_WHITE);mudaCor(Colors_GREEN);printf("       T");mudaCor(Colors_WHITE);printf("amanho\n");
                         opcaoValida=false;
                         do
                         {
                             mudaCor(Colors_GREEN);fflush(stdin);scanf("%c",&opcao);opcao=toupper(opcao);
                             if(opcao=='D')
                                 opcaoValida=true;
                             if(opcao=='C')
                                  opcaoValida=true;
                             if(opcao=='P')
                                  opcaoValida=true;
                             if(opcao=='T')
                                  opcaoValida=true;
                             if(opcao=='G')
                                  opcaoValida=true;
                             if(opcaoValida!=true)
                             {
                                  mudaCor(Colors_RED);
                                  printf("Opcao invalida. Por favor digite uma opcao valida: ");
                             }
                         }while(opcaoValida!=true);
                         mudaCor(Colors_WHITE);
                         switch(opcao)
                         {
                             case 'D':
                                  printf("Informe a descricao buscada: ");
                                  mudaCor(Colors_GREEN);fflush(stdin);gets(objeto);
                                  strcpy(objeto,strlwr(objeto));
                                  break;
                             case 'T':
                                  printf("Escolha o tamanho:\n(");
                                  mudaCor(Colors_GREEN);printf("PP");mudaCor(Colors_WHITE);printf(" / ");mudaCor(Colors_GREEN);printf("P");
                                  mudaCor(Colors_WHITE);printf(" / ");mudaCor(Colors_GREEN);printf("M");
                                  mudaCor(Colors_WHITE);printf(" / ");mudaCor(Colors_GREEN);printf("G");
                                  mudaCor(Colors_WHITE);printf(" / ");mudaCor(Colors_GREEN);printf("XG");
                                  mudaCor(Colors_WHITE);printf(")\n");
                                  opcaoValida=false;
                                  do
                                  {
                                      mudaCor(Colors_GREEN);fflush(stdin);gets(objeto);
                                      strcpy(objeto,strupr(objeto));
                                      if(strcmp(objeto,"PP")==0)
                                          opcaoValida=true;
                                      if(strcmp(objeto,"P")==0)
                                          opcaoValida=true;
                                      if(strcmp(objeto,"M")==0)
                                          opcaoValida=true;
                                      if(strcmp(objeto,"G")==0)
                                          opcaoValida=true;
                                      if(strcmp(objeto,"XG")==0)
                                          opcaoValida=true;
                                      if(opcaoValida!=true)
                                      {
                                           mudaCor(Colors_RED);
                                           printf("Opcao invalida. Por favor digite uma opcao valida: ");
                                      }
                                  }while(opcaoValida!=true);
                                  break;
                             case 'P':
                                   printf("Informe o preco minimo buscado: ");
                                   mudaCor(Colors_GREEN);scanf("%f",&precoMin);
                                   mudaCor(Colors_WHITE);printf("Informe o preco maximo buscado.\n");
                                   mudaCor(Colors_GREEN);scanf("%f",&precoMax);fflush(stdin);
                                   break;
                             case 'C':
                                  printf("Informe a cor buscada: ");
                                  mudaCor(Colors_GREEN);fflush(stdin);scanf("%s",objeto);
                                  strcpy(objeto,strlwr(objeto));
                                  break;
                             case 'G':
                                  printf("Informe o genero (");mudaCor(Colors_GREEN);printf("masculino");mudaCor(Colors_WHITE);printf(", ");
                                  mudaCor(Colors_GREEN);printf("feminino");mudaCor(Colors_WHITE);printf(" ou ");mudaCor(Colors_GREEN);printf("unissex");
                                  mudaCor(Colors_WHITE);printf("): ");
                                   opcaoValida=false;
                                  do
                                  {
                                      mudaCor(Colors_GREEN);fflush(stdin);gets(objeto);
                                      strupr(objeto);
                                      if(strcmp(objeto,"MASCULINO")==0)
                                          opcaoValida=true;
                                      if(strcmp(objeto,"FEMININO")==0)
                                          opcaoValida=true;
                                      if(strcmp(objeto,"UNISSEX")==0)
                                          opcaoValida=true;
                                      if(opcaoValida!=true)
                                      {
                                           mudaCor(Colors_RED);
                                           printf("Opcao invalida. Por favor digite uma opcao valida: ");
                                      }
                                  }while(opcaoValida!=true);
                                  strcpy(objeto,strlwr(objeto));
                                  break;
                         }
                         while(!feof(arq))
                         {
                             r = fgets(linha,MAX_LINHA,arq);
                             if (r)
                             {
                                  produtoVestuario.codigo = atoi(strtok(linha,","));
                                  strcpy(produtoVestuario.descricao,(strtok(NULL,",")));
                                  strcpy(produtoVestuario.tamanho,(strtok(NULL,",")));
                                  produtoVestuario.preco = atof(strtok(NULL,","));
                                  produtoVestuario.estoque = atoi(strtok(NULL,","));
                                  strcpy(produtoVestuario.cor,(strtok(NULL,",")));
                                  strcpy(produtoVestuario.genero,(strtok(NULL,"\n")));

                                  if(strcmp(objeto,produtoVestuario.descricao)==0 || strcmp(objeto,produtoVestuario.tamanho)==0 ||
                                  strcmp(objeto,produtoVestuario.cor)==0 || strcmp(objeto,produtoVestuario.genero)==0)
                                  {
                                     imprimeVestuario(produtoVestuario);
                                     encontrados[i] = produtoEletro.codigo;
                                     i++;
                                     produtosEncontrados++;
                                  }
                                  else
                                  if(opcao == 'P' && produtoVestuario.preco <= precoMax && produtoVestuario.preco >= precoMin)
                                  {
                                     imprimeVestuario(produtoVestuario);
                                     encontrados[i] = produtoEletro.codigo;
                                     i++;
                                     produtosEncontrados++;
                                  }

                             }
                         }

                         if(produtosEncontrados==0)
                         {
                             mudaCor(Colors_RED);
                             printf("\nNenhum produto encontrado.");
                             fflush(stdin);getchar();
                         }
                         else
                         {
                                mudaCor(Colors_WHITE);
                                printf("\nForam encontrados ");
                                mudaCor(Colors_GREEN);
                                printf("%d", produtosEncontrados);
                                mudaCor(Colors_WHITE);
                                printf(" produtos.");
                                fflush(stdin);getchar();
                         }
                         break;
            }
            mudaCor(Colors_WHITE);printf("\nVoce deseja realizar mais uma pesquisa? (");
            mudaCor(Colors_GREEN);printf("S");mudaCor(Colors_WHITE);printf(" ou ");mudaCor(Colors_GREEN);printf("N");mudaCor(Colors_WHITE);printf(">");
            opcaoValida=false;
            do
            {
                mudaCor(Colors_GREEN);fflush(stdin);scanf("%c", &resposta);
                resposta=toupper(resposta);
                if(resposta=='S')
                {
                     continuaPesquisa=true;
                     opcaoValida=true;
                }
                if(resposta=='N')
                {
                     continuaPesquisa=false;
                     opcaoValida=true;
                }
                if(opcaoValida==0)
                {
                     mudaCor(Colors_RED);
                     printf("Opcao invalida. Por favor digite uma opcao valida: ");
                }
            }while(opcaoValida==0);
    }while(continuaPesquisa);
}

//mostra todas as compras do carrinho
void visualizaCompras(int cadastro)
{
     FILE *arq;
     CARRINHO carrinho;
     char cadastroEmCar[MAX_DIGITOS];
     int i;

     system("cls");
     itoa(cadastro, cadastroEmCar, 10);
     mudaCor(Colors_YELLOW);printf("\nSEU CARRINHO DE COMPRAS:");
     mudaCor(Colors_WHITE);printf("\n=======================================================================");
     arq=fopen(cadastroEmCar, "rb");
     if(!arq)
     {
         printf("\nAinda nao ha itens no seu carrinho de compras.");
         fflush(stdin);getch();mudaCor(Colors_WHITE);
     }
     else
     {
             if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
             {
                 printf("\nVoce possui");mudaCor(Colors_GREEN);printf(" %d ", carrinho.itensEletro);mudaCor(Colors_WHITE);
                 printf("eletrodomesticos e");mudaCor(Colors_GREEN);printf(" %d ", carrinho.itensVestuario);
                 mudaCor(Colors_WHITE);printf("pecas de vestuario no seu carrinho.");
                 for(i=0;i<carrinho.itensEletro;i++)
                 {
                     printf("\n===========================================================");
                     printf("\nCodigo do produto: %d", carrinho.eletronico[i].codigo);
                     printf("\nDescricao: %s", carrinho.eletronico[i].descricao);
                     printf("\nAltura: %d cm", carrinho.eletronico[i].altura);
                     printf("\nLargura: %d cm", carrinho.eletronico[i].largura);
                     printf("\nProfundidade: %d cm", carrinho.eletronico[i].profundidade);
                     printf("\nPreco: %.2f reais", carrinho.eletronico[i].preco);
                     printf("\nCor: %s", carrinho.eletronico[i].cor);
                 }
                 for(i=0;i<carrinho.itensVestuario;i++)
                 {
                     printf("\n===========================================================");
                     printf("\nCodigo do produto: %d", carrinho.vestuario[i].codigo);
                     printf("\nDescricao: %s", carrinho.vestuario[i].descricao);
                     printf("\nTamanho: %s", carrinho.vestuario[i].tamanho);
                     printf("\nPreco: %.2f reais", carrinho.vestuario[i].preco);
                     printf("\nCor: %s", carrinho.vestuario[i].cor);
                     printf("\nGenero: %s", carrinho.vestuario[i].genero);
                 }
             }
             fclose(arq);
             fflush(stdin);getch();
     }
}
//fim da funcao que mostra as compras

//funcao cancela a compra e repoe o estoqueitem a item
void cancelaTodasCompras(int cadastro)
{
     FILE *arq, *arqtxt;
     char cadastroEmChar[MAX_DIGITOS], salvaLinha[MAX_PRODUTOS][MAX_LINHA], stringTemp[MAX_LINHA];
     int i, j, k, contaLinhas, comparaCodigo, codigo;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;

     system("cls");
     mudaCor(Colors_YELLOW);printf("\nCANCELAR TODAS AS COMPRAS:");
     mudaCor(Colors_WHITE);printf("\n=======================================================================");
     itoa(cadastro, cadastroEmChar, 10);
     arq=fopen(cadastroEmChar, "rb");
     if(!arq)
     {
             printf("\nNao ha itens em seu carrinho para serem excluidos.");
             fflush(stdin);getch();mudaCor(Colors_WHITE);
     }
     else
     {
         if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
         {
             for(i=0;i<carrinho.itensEletro;i++)
             {
                         arqtxt=fopen("eletro.txt", "r");
                         if(!arqtxt)
                         {
                             mudaCor(Colors_RED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             mudaCor(Colors_WHITE);
                             getch();
                             exit(1);
                         }
                         contaLinhas=0;
                         while(!feof(arqtxt))
                         {
                              fgets(salvaLinha[contaLinhas], sizeof(salvaLinha[contaLinhas]), arqtxt);
                              contaLinhas++;
                         }
                         fclose(arqtxt);
                         remove("eletro.txt");

                         arqtxt=fopen("eletro.txt", "w");
                         if(!arqtxt)
                         {
                             mudaCor(Colors_RED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             mudaCor(Colors_WHITE);
                             getch();
                             exit(1);
                         }
                         for(j=0; j<contaLinhas; j++)
                         {
                                  strcpy(stringTemp, salvaLinha[j]);
                                  codigo=atoi(strtok(stringTemp, ","));
                                  if(codigo==carrinho.eletronico[i].codigo)
                                  {
                                        eletronico.codigo=atoi(strtok(salvaLinha[j], ","));;
                                        strcpy(eletronico.descricao, strtok(NULL, ","));
                                        eletronico.altura=atoi(strtok(NULL, ","));
                                        eletronico.largura=atoi(strtok(NULL, ","));
                                        eletronico.profundidade=atoi(strtok(NULL, ","));
                                        eletronico.preco=atof(strtok(NULL, ","));
                                        eletronico.estoque=atoi(strtok(NULL, ","))+1;
                                        strcpy(eletronico.cor, strtok(NULL, "\n"));
                                        fseek(arq, 0*sizeof(char), SEEK_END);
                                        fprintf(arqtxt,"%d%c%s%c%d%c%d%c%d%c%.2f%c%d%c%s%c", eletronico.codigo, ',', eletronico.descricao, ',', eletronico.altura, ',', eletronico.largura, ',', eletronico.profundidade, ',', eletronico.preco, ',', eletronico.estoque, ',', eletronico.cor, '\n');
                                  }
                                  else
                                      fputs(salvaLinha[j], arqtxt);
                         }
                         fclose(arqtxt);
             }
             //repoe o estoque dos vestuarios
             for(i=0;i<carrinho.itensVestuario;i++)
             {
                         arqtxt=fopen("vestuario.txt", "r");
                         if(!arqtxt)
                         {
                             mudaCor(Colors_RED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             mudaCor(Colors_WHITE);
                             getch();
                             exit(1);
                         }
                         contaLinhas=0;
                         while(!feof(arqtxt))
                         {
                              fgets(salvaLinha[contaLinhas], sizeof(salvaLinha[contaLinhas]), arqtxt);
                              contaLinhas++;
                         }
                         fclose(arqtxt);
                         remove("vestuario.txt");

                         arqtxt=fopen("vestuario.txt", "w");
                         if(!arqtxt)
                         {
                             mudaCor(Colors_RED);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             mudaCor(Colors_WHITE);
                             getch();
                             exit(1);
                         }
                         for(j=0; j<contaLinhas; j++)
                         {
                                  strcpy(stringTemp, salvaLinha[j]);
                                  codigo=atoi(strtok(stringTemp, ","));
                                  if(codigo==carrinho.vestuario[i].codigo)
                                  {
                                        vestuario.codigo=atoi(strtok(salvaLinha[j], ","));;
                                        strcpy(vestuario.descricao, strtok(NULL, ","));
                                        strcpy(vestuario.tamanho, strtok(NULL, ","));
                                        vestuario.preco=atof(strtok(NULL, ","));
                                        vestuario.estoque=atoi(strtok(NULL, ","))+1;
                                        strcpy(vestuario.cor, strtok(NULL, ","));
                                        strcpy(vestuario.genero, strtok(NULL, "\n"));
                                        fseek(arq, 0*sizeof(char), SEEK_END);
                                        fprintf(arqtxt,"%d%c%s%c%s%c%.2f%c%d%c%s%c%s%c", vestuario.codigo, ',', vestuario.descricao, ',', vestuario.tamanho, ',', vestuario.preco, ',', vestuario.estoque, ',', vestuario.cor, ',', vestuario.genero, '\n');
                                  }
                                  else
                                      fputs(salvaLinha[j], arqtxt);
                         }
                         fclose(arqtxt);
             }
         }
         fclose(arq);
         remove(cadastroEmChar);
         mudaCor(Colors_YELLOW);printf("\nSeu carrinho foi esvaziado!");mudaCor(Colors_WHITE);fflush(stdin);getch();
     }
}
//fim da funcao de cancelamento de pedido

void excluiProdutoCarrinho(int cadastro)
{

     FILE *arq, *arqtxt;
     int codigoExcluir, i, j, contaLinhas, codigo; bool encontrouProduto;
     bool continuaExcluindo, opcaoValida;
     char cadastroEmChar[MAX_DIGITOS], salvaLinha[MAX_PRODUTOS][MAX_LINHA], stringTemp[MAX_LINHA];
     char resposta;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;

     do
     {
             encontrouProduto=false;
             system("cls");
             mudaCor(Colors_YELLOW);printf("\nEXCLUIR ITEM DO CARRINHO");
             mudaCor(Colors_WHITE);printf("\n==================================================================");
             itoa(cadastro, cadastroEmChar, 10);
             arq=fopen(cadastroEmChar, "rb");
             if(!arq)
             {
                     mudaCor(Colors_WHITE);printf("\nNao ha itens em seu carrinho para serem excluidos.");
                     fflush(stdin);getch();mudaCor(Colors_WHITE);
                     continuaExcluindo=false;
             }
             else
             {
                 printf("\nInforme o codigo do produto que voce quer excluir do seu carrinho: ");
                 mudaCor(Colors_GREEN);scanf("%d", &codigoExcluir);mudaCor(Colors_WHITE);
                 if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                 {
                       fclose(arq);
                       for(i=0; i<carrinho.itensEletro; i++)
                       {
                                if(codigoExcluir==carrinho.eletronico[i].codigo && encontrouProduto==false)
                                {
                                    arq=fopen(cadastroEmChar, "wb");
                                    if(!arq)
                                    {
                                            mudaCor(Colors_RED);printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            fflush(stdin);getch();exit(1);
                                    }
                                    encontrouProduto=true;
                                    carrinho.eletronico[i]=carrinho.eletronico[carrinho.itensEletro-1];
                                    carrinho.itensEletro=carrinho.itensEletro-1;
                                    if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                    {
                                        mudaCor(Colors_YELLOW);printf("Uma unidade do produto de codigo");
                                        mudaCor(Colors_GREEN);printf(" %d ", codigoExcluir);
                                        mudaCor(Colors_YELLOW);printf("foi excluido de seu carrinho.");
                                        fflush(stdin);getch();
                                    }
                                    fclose(arq);
                                    if(carrinho.itensEletro==0 && carrinho.itensVestuario==0)
                                        remove(cadastroEmChar);
                                    //repoe o estoque dos eletrodomesticos
                                    arqtxt=fopen("eletro.txt", "r");
                                     if(!arqtxt)
                                     {
                                             mudaCor(Colors_RED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                     }
                                     contaLinhas=0;
                                     while(!feof(arqtxt))
                                     {
                                          fgets(salvaLinha[contaLinhas], sizeof(salvaLinha[contaLinhas]), arqtxt);
                                          contaLinhas++;
                                     }
                                     fclose(arqtxt);
                                     remove("eletro.txt");

                                     arqtxt=fopen("eletro.txt", "w");
                                     if(!arqtxt)
                                     {
                                             mudaCor(Colors_RED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                     }
                                     for(j=0; j<contaLinhas; j++)
                                     {
                                              strcpy(stringTemp, salvaLinha[j]);
                                              codigo=atoi(strtok(stringTemp, ","));
                                              if(codigo==codigoExcluir)
                                              {
                                                    eletronico.codigo=atoi(strtok(salvaLinha[j], ","));;
                                                    strcpy(eletronico.descricao, strtok(NULL, ","));
                                                    eletronico.altura=atoi(strtok(NULL, ","));
                                                    eletronico.largura=atoi(strtok(NULL, ","));
                                                    eletronico.profundidade=atoi(strtok(NULL, ","));
                                                    eletronico.preco=atof(strtok(NULL, ","));
                                                    eletronico.estoque=atoi(strtok(NULL, ","))+1;
                                                    strcpy(eletronico.cor, strtok(NULL, "\n"));
                                                    fseek(arq, 0*sizeof(char), SEEK_END);
                                                    fprintf(arqtxt,"%d%c%s%c%d%c%d%c%d%c%.2f%c%d%c%s%c", eletronico.codigo, ',', eletronico.descricao, ',', eletronico.altura, ',', eletronico.largura, ',', eletronico.profundidade, ',', eletronico.preco, ',', eletronico.estoque, ',', eletronico.cor, '\n');
                                              }
                                              else
                                                  fputs(salvaLinha[j], arqtxt);
                                     }
                                     fclose(arqtxt);
                                }
                       }
                       if(encontrouProduto!=true)
                       {
                             for(i=0; i<carrinho.itensVestuario; i++)
                             {
                                    if(codigoExcluir==carrinho.vestuario[i].codigo && encontrouProduto==false)
                                    {
                                        arq=fopen(cadastroEmChar, "wb");
                                        if(!arq)
                                        {
                                            mudaCor(Colors_RED);printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            fflush(stdin);getch();exit(1);
                                        }
                                        encontrouProduto=true;
                                        carrinho.vestuario[i]=carrinho.vestuario[carrinho.itensVestuario-1];
                                        carrinho.itensVestuario=carrinho.itensVestuario-1;
                                        if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                        {
                                            mudaCor(Colors_YELLOW);printf("Uma unidade do produto de codigo");
                                            mudaCor(Colors_GREEN);printf(" %d ", codigoExcluir);
                                            mudaCor(Colors_YELLOW);printf("foi excluido de seu carrinho.");
                                            fflush(stdin);getch();
                                        }
                                        fclose(arq);

                                        if(carrinho.itensEletro==0 && carrinho.itensVestuario==0)
                                             remove(cadastroEmChar);
                                        //repoe o estoque
                                         arqtxt=fopen("vestuario.txt", "r");
                                         if(!arqtxt)
                                         {
                                             mudaCor(Colors_RED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                         }
                                         contaLinhas=0;
                                         while(!feof(arqtxt))
                                         {
                                              fgets(salvaLinha[contaLinhas], sizeof(salvaLinha[contaLinhas]), arqtxt);
                                              contaLinhas++;
                                         }
                                         fclose(arqtxt);
                                         remove("vestuario.txt");

                                         arqtxt=fopen("vestuario.txt", "w");
                                         if(!arqtxt)
                                         {
                                             mudaCor(Colors_RED);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                         }
                                         for(j=0; j<contaLinhas; j++)
                                         {
                                                  strcpy(stringTemp, salvaLinha[j]);
                                                  codigo=atoi(strtok(stringTemp, ","));
                                                  if(codigoExcluir==codigo)
                                                  {
                                                        vestuario.codigo=atoi(strtok(salvaLinha[j], ","));;
                                                        strcpy(vestuario.descricao, strtok(NULL, ","));
                                                        strcpy(vestuario.tamanho, strtok(NULL, ","));
                                                        vestuario.preco=atof(strtok(NULL, ","));
                                                        vestuario.estoque=atoi(strtok(NULL, ","))+1;
                                                        strcpy(vestuario.cor, strtok(NULL, ","));
                                                        strcpy(vestuario.genero, strtok(NULL, "\n"));
                                                        fseek(arq, 0*sizeof(char), SEEK_END);
                                                        fprintf(arqtxt,"%d%c%s%c%s%c%.2f%c%d%c%s%c%s%c", vestuario.codigo, ',', vestuario.descricao, ',', vestuario.tamanho, ',', vestuario.preco, ',', vestuario.estoque, ',', vestuario.cor, ',', vestuario.genero, '\n');
                                                  }
                                                  else
                                                      fputs(salvaLinha[j], arqtxt);
                                         }
                                         fclose(arqtxt);
                                    }
                             }
                       }
                       if(encontrouProduto!=true)
                       {
                           mudaCor(Colors_RED);printf("Nao foi encontrado nenhum item com esse codigo em seu carrinho.");
                       }
                 }
                 else
                 {
                     mudaCor(Colors_RED);printf("Houve um problema ao abrir seu carrinho.");
                     fflush(stdin);getch();
                     fclose(arq);
                 }
                    mudaCor(Colors_WHITE);printf("\nVoce deseja excluir mais um item do seu carrinho? (");
                    mudaCor(Colors_GREEN);printf("S");mudaCor(Colors_WHITE);printf(" ou ");mudaCor(Colors_GREEN);printf("N");mudaCor(Colors_WHITE);printf(">");
                    opcaoValida=false;
                    do
                    {
                        mudaCor(Colors_GREEN);fflush(stdin);scanf("%c", &resposta);
                        resposta=toupper(resposta);
                        if(resposta=='S')
                        {
                             continuaExcluindo=true;
                             opcaoValida=true;
                        }
                        if(resposta=='N')
                        {
                             continuaExcluindo=false;
                             opcaoValida=true;
                        }
                        if(opcaoValida==false)
                        {
                             mudaCor(Colors_RED);
                             printf("Opcao invalida. Por favor digite uma opcao valida: ");
                        }
                    }while(opcaoValida==false);
             }
     }while(continuaExcluindo);
}

void fechaCompra(int cadastro)
{
     FILE *arq, *arqtxt;
     CARRINHO carrinho;
     int i;
     float valorDaCompra;
     char stringTemp[MAX_LINHA], dia[MAX_DIGITOS], mes[MAX_DIGITOS], ano[MAX_DIGITOS];
     char cadastroEmChar[MAX_DIGITOS];

     system("cls");
     itoa(cadastro, cadastroEmChar, 10);
     mudaCor(Colors_YELLOW);printf("\nFECHAR COMPRA");
     mudaCor(Colors_WHITE);printf("\n==============================================================");
     strcpy(stringTemp, __DATE__);
     strcpy(mes, strupr(strtok(stringTemp, " ")));
     strcpy(dia, strtok(NULL, " "));
     strcpy(ano, strtok(NULL, "\n"));
     arq=fopen(cadastroEmChar, "rb");
     if(!arq)
     {
             mudaCor(Colors_WHITE);printf("\nSeu carrinho ainda nao possui nenhum item para poder fechar a compra");
             fflush(stdin);getch();
     }
     else
     {
         if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
         {
                    valorDaCompra=0;
                    for(i=0; i<carrinho.itensEletro; i++)
                    {
                             valorDaCompra+=carrinho.eletronico[i].preco;
                    }
                    for(i=0; i<carrinho.itensVestuario; i++)
                    {
                             valorDaCompra+=carrinho.vestuario[i].preco;
                    }
                    arqtxt=fopen("report.txt", "a");
                    if(!arqtxt)
                    {
                          mudaCor(Colors_RED);printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                          fflush(stdin);getch();exit(1);
                    }
                    fprintf(arqtxt, "%c%s%c%s%c%s%c", '\n', dia, ',', mes, ',', ano, ',');
                    fprintf(arqtxt, "%d%c%d%c%.2f", carrinho.itensEletro, ',', carrinho.itensVestuario, ',', valorDaCompra);
                    fclose(arqtxt);
                    printf("\nData da compra: ");mudaCor(Colors_GREEN);printf("%s", dia);
                    mudaCor(Colors_WHITE);printf("/");mudaCor(Colors_GREEN);printf("%s", mes);
                    mudaCor(Colors_WHITE);printf("/");mudaCor(Colors_GREEN);printf("%s", ano);
                    mudaCor(Colors_WHITE);printf("\nValor total da compra: ");mudaCor(Colors_GREEN);printf("%.2f.", valorDaCompra);
                    mudaCor(Colors_WHITE);
                    if(carrinho.itensEletro!=0)
                    {
                           printf("\nEletrodomesticos comprados: ");mudaCor(Colors_GREEN);printf("%d", carrinho.itensEletro);
                    }
                    else
                          printf("\nNenhum eletrodomestico comprado.");
                    mudaCor(Colors_WHITE);
                    if(carrinho.itensVestuario!=0)
                    {
                           printf("\nPecas de vestuario compradas: ");mudaCor(Colors_GREEN);printf("%d.", carrinho.itensVestuario);
                    }
                    else
                          printf("\nNenhuma peca de vestuario comprada.");
                    mudaCor(Colors_YELLOW);printf("\nSua compra foi finalizada! \nVoce estara recebendo sua encomenda");
                    printf(" dentro de");mudaCor(Colors_GREEN);printf(" %d ", DIAS_UTEIS);mudaCor(Colors_YELLOW);printf("dias uteis.");
                    fflush(stdin);getch();
         }
         else
         {
                     mudaCor(Colors_RED);
                     printf("\nHouve um erro ao abrir o seu carrinho.");
                     fflush(stdin);getch();
         }
         fclose(arq);
         remove(cadastroEmChar);
     }
}

int contaComprasSuspensas()
{
    FILE *arq;
    int contador, i, totalCarrinhosAbertos, listaCarrinhosAbertos[MAX_USUARIOS], codigo;
    char cadastroEmChar[MAX_DIGITOS], linha[MAX_LINHA];

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
            listaCarrinhosAbertos[totalCarrinhosAbertos]=i;
            totalCarrinhosAbertos++;
            fclose(arq);
        }
    }
    return(totalCarrinhosAbertos);
}

void menuCliente(char nome[], int cadastro)
{
    FILE *arq;
    char resposta, cadastroEmChar[MAX_DIGITOS];
    int comprasSuspensas;
    bool opcaoValida,continua=true;
    do
    {
            system("cls");
            mudaCor(Colors_YELLOW);
            printf("\nCLIENTE: ");
            mudaCor(Colors_GREEN);
            printf("%s", nome);
            mudaCor(Colors_WHITE);
            printf("\nData: %s Hora: %s",__DATE__,__TIME__);
            printf("\n=====================================================================");
            printf("\nSelecione a letra correspondente em verde para acessar a opcao.\n");
            mudaCor(Colors_GREEN);
            printf("\nT");mudaCor(Colors_WHITE);printf("rocar Usuario (Suspende as compras que estiverem abertas e faz logout)");
            mudaCor(Colors_GREEN);printf("\nS");mudaCor(Colors_WHITE);printf("air (Cancela suas compras e faz logout)");
            printf("\nC");mudaCor(Colors_GREEN);printf("o");mudaCor(Colors_WHITE);printf("ncluir (Fecha as suas compras e faz logout)");
            mudaCor(Colors_GREEN);printf("\n\nP");mudaCor(Colors_WHITE);printf("esquisar");
            mudaCor(Colors_GREEN);printf("                 I");mudaCor(Colors_WHITE);printf("nserir");
            mudaCor(Colors_GREEN);printf("\nE");mudaCor(Colors_WHITE);printf("xcluir um item");
            mudaCor(Colors_GREEN);printf("           V");mudaCor(Colors_WHITE);printf("isualizar");
            mudaCor(Colors_GREEN);printf("\nF");mudaCor(Colors_WHITE);printf("echar as compras");
            mudaCor(Colors_GREEN);printf("         C");mudaCor(Colors_WHITE);printf("ancelar as compras");
            printf("\n==================================================================\n");
            do
            {
                mudaCor(Colors_GREEN);fflush(stdin);scanf("%c", &resposta);
                resposta=toupper(resposta);
                mudaCor(Colors_WHITE);
                opcaoValida=true;
                switch(resposta)
                {
                    case 'T':
                    {
                        itoa(cadastro, cadastroEmChar, 10);
                        arq=fopen(cadastroEmChar, "rb");
                        if(arq)                        //checa se o usuario tem comopras para suspender
                        {
                            comprasSuspensas=contaComprasSuspensas();
                            if(comprasSuspensas<MAX_COMPRAS_SUSP)
                            {
                                printf("\nSuas compras ficarao suspensas. Voce podera finaliza-las mais tarde.");
                                fflush(stdin);getch();
                                continua=false;
                            }
                            else
                            {
                                mudaCor(Colors_RED);printf("\nO numero maximo de compras suspensas simultaneas");
                                printf("\nfoi atingido. Voce tera que fechar suas compras ou cancela-las.");
                                mudaCor(Colors_WHITE);
                                continua=true;
                            }
                            fclose(arq);
                        }
                        else
                            continua=false;
                        break;
                    }
                    case 'S':
                    {
                        printf("\nSuas compras serao canceladas antes de voce fazer logout.");
                        fflush(stdin);getch();
                        cancelaTodasCompras(cadastro);
                        continua=false;
                        break;
                    }
                    case 'O':
                    {
                        printf("\nSuas compras serao finalizadas antes de voce fazer logout.");
                        fflush(stdin);getch();
                        fechaCompra(cadastro);
                        continua=false;
                        break;
                    }
                    case 'P':
                    {
                        pesquisaProduto();
                        break;
                    }
                    case 'I':
                    {
                        insereProdutoCarrinho(cadastro);
                        break;
                    }
                    case 'E':
                    {
                        excluiProdutoCarrinho(cadastro);
                        break;
                    }
                    case 'V':
                    {
                        visualizaCompras(cadastro);
                        break;
                    }
                    case 'F':
                    {
                        fechaCompra(cadastro);
                        break;
                    }
                    case 'C':
                    {
                        cancelaTodasCompras(cadastro);
                        break;
                    }
                    default:
                    {
                      mudaCor(Colors_RED);
                      printf("Opcao invalida. Por favor digite uma opcao valida: ");
                      opcaoValida=false;
                    }
                }
            }while(!opcaoValida);
    }while(continua);
}

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
