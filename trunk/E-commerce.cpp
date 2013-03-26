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

//funcao tela inicial, chamada pela
int telaInicial()
{
     char resposta;
     int respostaalg;
     textcolor(14);
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
     textcolor(15);
     printf("\n================================================================");
     printf("\nSeja bem vindo. O que voce deseja fazer?");
     textcolor(10);printf("\nL");textcolor(15);printf("ogin");
     textcolor(10);printf("\nC");textcolor(15);printf("riar nova conta");
     textcolor(10);printf("\nI");textcolor(15);printf("nformacoes");
     textcolor(10);printf("\nS");textcolor(15);printf("air");
     printf("\n================================================================\n");
     fflush(stdin);
     do
     {
        textcolor(10);
        fflush(stdin);
        scanf("%c", &resposta);
        resposta=toupper(resposta);
        textcolor(15);
        switch(resposta)
        {
            case 'L':
            {    respostaalg=1;
                 break;
            }
            case 'C':
            {    respostaalg=2;
                 break;
            }
            case 'I':
            {    respostaalg=3;
                 break;
            }
            case 'S':
            {    respostaalg=4;
                 break;
            }
            default:
            {
               textcolor(12);
               printf("Opcao Invalida. Por favor digite uma opcao valida: ");
               textcolor(15);
               respostaalg=0;
            }
        }
     }while(respostaalg==0);
     return(respostaalg);
}

//MOSTRA AS INFORMACOES DO PROGRAMA
void showInfo()
{
     system("cls");
     textcolor(14);
     printf("\nINFORMACOES DO PROGRAMA:");
     textcolor(15);
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
     int contador, continua, i;
     char string[MAX_LINHA], categoria;
     system("cls");
     arq=fopen("usuarios.txt", "r");
     if(!arq)
     {
             printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
             getch();
             exit(1);
     }
     contador=0;
     while(!feof(arq))
     {
        fgets(string, MAX_LINHA, arq);
        if(string[0]!='\n')
           contador++;
     }
     fclose(arq);
     if(contador<MAX_USUARIOS)
     {
         novoUsuario.codigo=contador+1;
         textcolor(14);
         printf("\nCADASTRO DE NOVO USUARIO");
         textcolor(15);
         printf("\n=============================================================");
         printf("\nSeu cadastro: ");
         textcolor(10);
         printf("%d", contador+1);
         textcolor(15);
         printf("\nInforme o seu nome: ");
         do
         {
             continua=0;
             fflush(stdin);
             textcolor(10);
             gets(novoUsuario.nome);
             if(3<=strlen(novoUsuario.nome))
             {
                 for(i=0;i<strlen(novoUsuario.nome);i++)
                 {
                     if(novoUsuario.nome[i]==',')
                     {
                         textcolor(12);
                         printf("Nome informado invalido. Por favor, nao insira virgulas no nome.\n");
                         textcolor(15);
                         continua=1;
                     }
                 }
             }
             else
             {
                 textcolor(12);
                 if(strlen(novoUsuario.nome)==0)
                     printf("Por favor, insira um nome valido.\n");
                 else
                     printf("Seu nome deve conter pelo menos 3 letras.\n");
                 textcolor(15);
                 continua=1;
             }
         }while(continua);
         textcolor(15);
         printf("Informe sua categoria. (C para cliente ou G para gerente): ");
         continua=1;
         do
         {
             fflush(stdin);
             textcolor(10);
             scanf("%c", &categoria);
             categoria=toupper(categoria);
             switch(categoria)
             {
                case 'C':
                {
                     strcpy(novoUsuario.categoria, "cliente");
                     continua=0;
                     break;
                }
                case 'G':
                {
                     strcpy(novoUsuario.categoria, "gerente");
                     continua=0;
                     break;
                }
                default:
                {
                     textcolor(12);
                     printf("Caractere informado invalido! Informe um caractere valido:");
                     break;
                }
             }
          }while(continua);
          arq=fopen("usuarios.txt", "a");
          if(!arq)
          {
              printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
              getch();
              exit(1);
          }
          fprintf(arq,"%c%d%c%s%c%s", '\n', novoUsuario.codigo, ',', novoUsuario.nome, ',', novoUsuario.categoria);
          fclose(arq);
          textcolor(14);
          printf("\nCadastro criado com sucesso!");
          getch();
          textcolor(15);
     }
     else
     {
         textcolor(12);
         printf("Numero maximo de usuarios atingido!");
         fclose(arq);
         textcolor(15);
         getch();
     }
}
//FIM DA FUNÇÃO PARA CRIAR NOVO USUARIO


void inserirProdutoCarrinho(int cadastro)
{
     FILE *arq, *arq2;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;
     char cadastroEmChar[MAX_DIGITOS], string[MAX_LINHA], salvaLinha[MAX_PRODUTOS][MAX_LINHA];
     int codigo, achou=0, quantidade, contalinha=0, i, comparaCodigo, confirmacao;

     system("cls");
     textcolor(14);printf("\nINSERIR NOVO ITEM NO CARRINHO DE COMPRAS");
     textcolor(15);printf("\n==========================================================================");
     printf("\nDigite o codigo do produto que voce quer adicionar ao seu carrinho: ");
     do
     {
             textcolor(10);
             scanf("%d", &codigo);
             textcolor(15);
             printf("Digite a quantidade do produto que voce quer adicionar ao seu carrinho: ");
             do
             {
                 textcolor(10);
                 scanf("%d", &quantidade);
                 if(quantidade<=0 || MAX_CAR<quantidade)
                 {
                     textcolor(12);printf("Quantidade muito grande. Informe uma quantidade de no maximo %d itens: ", MAX_CAR);
                 }
             }while(quantidade<=0 || MAX_CAR<quantidade);
             textcolor(15);
             //abre o arquivo de eletrodomesticos para procurar o codigo
             arq=fopen("eletro.txt", "r+");
             if(!arq)
             {
                 textcolor(12);
                 printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                 textcolor(15);
                 getch();
                 exit(1);
             }
             while((!feof(arq)) && (achou==0))
             {
                 fgets(string, sizeof(string), arq);
                 comparaCodigo=atoi(strtok(string, ","));
                 if(codigo==comparaCodigo)
                 {
                      achou=1;
                      eletronico.codigo=codigo;
                      strcpy(eletronico.descricao, strtok(NULL, ","));
                      eletronico.altura=atoi(strtok(NULL, ","));
                      eletronico.largura=atoi(strtok(NULL, ","));
                      eletronico.profundidade=atoi(strtok(NULL, ","));
                      eletronico.preco=atof(strtok(NULL, ","));
                      eletronico.estoque=atoi(strtok(NULL, ","));
                      strcpy(eletronico.cor, strtok(NULL, "\n"));
                      textcolor(10);printf("\nProduto a ser adicionado: \n");textcolor(15);
                      printf("%s   Altura: %d cm    Largura: %d cm" , eletronico.descricao, eletronico.altura, eletronico.largura);
                      printf("\nEstoque: %d   Profundidade: %d cm    Preco: %.2f    Cor: %s", eletronico.estoque, eletronico.profundidade, eletronico.preco, eletronico.cor);
                      printf("\n==========================================================================");
                      fflush(stdin);
                      getch();
                 }
             }
             fclose(arq);

             if(achou==1)
             {
                      if(quantidade<=eletronico.estoque)
                      {
                               //abre o arquivo de carrinho para salvar
                                confirmacao=1;
                                itoa(cadastro, cadastroEmChar, 10); //converte o codigo para char
                                arq=fopen(cadastroEmChar, "rb");
                                if(!arq)
                                {
                                       arq=fopen(cadastroEmChar, "wb");
                                }
                                if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                {
                                          if(carrinho.itensEletro+quantidade<=MAX_CAR)
                                          {
                                               for(i=carrinho.itensEletro; i<(carrinho.itensEletro+quantidade); i++)
                                               {
                                                    carrinho.eletronico[i]=eletronico;
                                               }
                                               carrinho.itensEletro+=quantidade;
                                          }
                                          else
                                          {
                                              textcolor(12);printf("\nSeu carrinho de eletrodomesticos ja esta cheio.");
                                              textcolor(15);fflush(stdin);getch();
                                              confirmacao=0;
                                          }
                                }
                                else
                                {
                                    carrinho.itensEletro=0;
                                    if(carrinho.itensEletro+quantidade<=MAX_CAR)
                                    {
                                           for(i=carrinho.itensEletro; i<(carrinho.itensEletro+quantidade); i++)
                                           {
                                                carrinho.eletronico[i]=eletronico;
                                           }
                                           carrinho.itensEletro+=quantidade;
                                    }
                                    else
                                    {
                                        textcolor(12);printf("\nSeu carrinho de eletrodomesticos ja esta cheio.");
                                        textcolor(15);fflush(stdin);getch();
                                        confirmacao=0;
                                    }
                                }
                                fclose(arq);
                                if(confirmacao==1)  //ha espaco no carrinho
                                {
                                    arq=fopen(cadastroEmChar, "wb");
                                    if(!arq)
                                    {
                                            textcolor(12);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                    {
                                           textcolor(14);printf("\nOs itens foram adicionados ao carrinho com sucesso.");
                                           fflush(stdin);getch();textcolor(15);
                                    }
                                    else
                                    {
                                        textcolor(12);printf("\nHouve um problema ao adicionar os itens ao carrinho.");
                                        fflush(stdin);getch();textcolor(15);
                                    }
                                    fclose(arq);
                                    //edita o estoque
                                    arq=fopen("eletro.txt", "r+");
                                    if(!arq)
                                    {
                                            textcolor(12);
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
                                            textcolor(12);
                                            printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            getch();
                                            exit(1);
                                    }
                                    eletronico.estoque=eletronico.estoque-quantidade;
                                    for(i=0; i<contalinha; i++)
                                    {
                                        strcpy(string, salvaLinha[i]);
                                        comparaCodigo=atoi(strtok(string, ","));
                                        if(comparaCodigo!=codigo)
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
                          textcolor(12);
                          printf("\nDesculpe. Nao ha itens em estoque suficientes para efetuar a compra.");
                          textcolor(15);fflush(stdin);getch();
                      }
             }
             else //caso nao tenha achado nos eletrodomesticos, procura no vestuario
             {
                     arq=fopen("vestuario.txt", "r+");
                     if(!arq)
                     {
                         textcolor(12);
                         printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                         textcolor(15);
                         getch();
                         exit(1);
                     }
                     while((!feof(arq)) && (achou==0))
                     {
                         fgets(string, sizeof(string), arq);
                         comparaCodigo=atoi(strtok(string, ","));
                         if(codigo==comparaCodigo)
                         {
                              achou=1;
                              vestuario.codigo=codigo;
                              strcpy(vestuario.descricao, strtok(NULL, ","));
                              strcpy(vestuario.tamanho, strtok(NULL, ","));
                              vestuario.preco=atof(strtok(NULL, ","));
                              vestuario.estoque=atoi(strtok(NULL, ","));
                              strcpy(vestuario.cor, strtok(NULL, ","));
                              strcpy(vestuario.genero, strtok(NULL, "\n"));
                              textcolor(10);printf("\nProduto a ser adicionado: \n");
                              textcolor(15);
                              printf("%s    Tamanho: %s    Preco: %.2f" , vestuario.descricao, vestuario.tamanho, vestuario.preco);
                              printf("\nEstoque: %d    Cor: %s    Genero: %s", vestuario.estoque, vestuario.cor, vestuario.genero);
                              printf("\n==========================================================================");
                              fflush(stdin);getch();
                         }
                     }
                     fclose(arq);
                     //confere se achou nos vestuarios
                     if(achou==1)
                     {
                              if(quantidade<=vestuario.estoque)
                              {
                                        confirmacao=1;
                                        itoa(cadastro, cadastroEmChar, 10); //converte o codigo para char
                                        arq=fopen(cadastroEmChar, "rb");
                                        if(!arq)
                                        {
                                               arq=fopen(cadastroEmChar, "wb");
                                        }
                                        if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                        {
                                                  if(carrinho.itensVestuario+quantidade<=MAX_CAR)
                                                  {
                                                       for(i=carrinho.itensVestuario; i<(carrinho.itensVestuario+quantidade); i++)
                                                       {
                                                            carrinho.vestuario[i]=vestuario;
                                                       }
                                                       carrinho.itensVestuario+=quantidade;
                                                  }
                                                  else
                                                  {
                                                      textcolor(12);printf("\nSeu carrinho de vestuario ja esta cheio.");
                                                      textcolor(15);fflush(stdin);getch();
                                                      confirmacao=0;
                                                  }
                                        }
                                        else
                                        {
                                            carrinho.itensVestuario=0;
                                            if(carrinho.itensVestuario+quantidade<=MAX_CAR)
                                            {
                                                   for(i=carrinho.itensVestuario; i<(carrinho.itensVestuario+quantidade); i++)
                                                   {
                                                        carrinho.vestuario[i]=vestuario;
                                                   }
                                                   carrinho.itensVestuario+=quantidade;
                                            }
                                            else
                                            {
                                                textcolor(12);printf("\nSeu carrinho de vestuario ja esta cheio.");
                                                textcolor(15);fflush(stdin);getch();
                                                confirmacao=0;
                                            }
                                        }
                                        fclose(arq);
                                        if(confirmacao==1)  //ha espaco no carrinho
                                        {
                                            arq=fopen(cadastroEmChar, "wb");
                                            if(!arq)
                                            {
                                                    textcolor(12);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                            {
                                                 textcolor(14);printf("\nOs itens foram adicionados ao carrinho com sucesso.");
                                                 fflush(stdin);getch();textcolor(15);
                                            }
                                            else
                                            {
                                                 textcolor(12);printf("\nHouve um problema ao adicionar os itens ao carrinho.");
                                                 fflush(stdin);getch();textcolor(15);
                                            }
                                            fclose(arq);
                                            //edita o estoque
                                            arq=fopen("vestuario.txt", "r+");
                                            if(!arq)
                                            {
                                                    textcolor(12);
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
                                                    textcolor(12);
                                                    printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                                    getch();
                                                    exit(1);
                                            }
                                            vestuario.estoque=vestuario.estoque-quantidade;
                                            for(i=0; i<contalinha; i++)
                                            {
                                                strcpy(string, salvaLinha[i]);
                                                comparaCodigo=atoi(strtok(string, ","));
                                                if(comparaCodigo!=codigo)
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
                                  textcolor(12);
                                  printf("\nDesculpe. Nao ha itens em estoque suficientes para efetuar a compra.");
                                  textcolor(15);fflush(stdin);getch();
                              }
                     }
             }
             if(achou==0)
             {
                 textcolor(12);printf("Codigo buscado nao encontrado, por favor digite um codigo valido.");
             }
     }while(achou==0);
}



//funcao usadas pela funcao pesquisa
void imprime_vest(VESTUARIO produtovest)
{
    textcolor(15);
    printf("\nCodigo: %d  Descricao: %s\n",produtovest.codigo, produtovest.descricao);
    printf("Tamanho: %s  Preco: %.2f  Estoque:  %d\n",produtovest.tamanho, produtovest.preco, produtovest.estoque);
    printf("Cor: %s  Genero: %s\n",produtovest.cor, produtovest.genero);
    printf("\n================================================================");
}
//funcao usadas pela funcao pesquisa
void imprime_eletro(ELETRO produto)
{
     textcolor(15);
     printf("\nCodigo: %d  Descricao: %s\n",produto.codigo, produto.descricao);
     printf("Altura: %d cm  Largura: %d cm  Profundidade:  %d cm\n",produto.altura, produto.largura, produto.profundidade);
     printf("Preco: %.2f Reais  Produtos em estoque: %d  Cor: %s\n",produto.preco, produto.estoque, produto.cor);
     printf("\n================================================================");
}

void pesquisar ()
{
    FILE *arq;
    char opcao, resposta;
    char linha[MAX_LINHA];
    ELETRO produto;
    VESTUARIO produtovest;
    char *r;
    char objeto[TAM_NOME_MAX];
    int encontrados[TAM_NOME_MAX];
    int i=0;
    float precomin;
    float precomax;
    int inteiro;
    int produtosencontrados=0;
    int confirmacao=0, maisuma;

    do
    {
            system("cls");
            textcolor(14);
            printf("\nPESQUISA:");
            textcolor(15);
            printf("\n=================================================================");
            printf("\nO que voce deseja pesquisar?");
            textcolor(10);
            printf("\nE");textcolor(15);printf("letronico           ");textcolor(10);printf("V");textcolor(15);printf("estuario\n");
            confirmacao=0;
            produtosencontrados=0;
            do
            {
                textcolor(10);
                fflush(stdin);
                scanf("%c",&opcao);
                opcao=toupper(opcao);
                if(opcao=='E')
                   confirmacao=1;
                if(opcao=='V')
                   confirmacao=1;
                if(confirmacao!=1)
                {
                    textcolor(12);
                    printf("Opcao invalida. Por favor digite uma opcao valida: ");
                }
            }while(confirmacao!=1);
            textcolor(15);
            switch(opcao)
            {
                case 'E':
                     arq = fopen("eletro.txt","r");
                     if(!arq)
                     {
                         textcolor(12);
                         puts("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                         getch();
                         exit(1);
                     }
                     printf("\n=================================================================");
                     printf("\nComo voce deseja pesquisar o produto?");
                     textcolor(10);printf("\nD");textcolor(15);printf("escricao    ");textcolor(10);printf("C");textcolor(15);printf("or");textcolor(10);printf("    P");textcolor(15);printf("reco\n");
                     confirmacao=0;
                     do
                     {
                         textcolor(10);
                         fflush(stdin);
                         scanf("%c",&opcao);
                         opcao=toupper(opcao);
                         if(opcao=='D')
                             confirmacao=1;
                         if(opcao=='C')
                              confirmacao=1;
                         if(opcao=='P')
                              confirmacao=1;
                         if(confirmacao!=1)
                         {
                              textcolor(12);
                              printf("Opcao invalida. Por favor digite uma opcao valida: ");
                         }
                     }while(confirmacao!=1);
                     textcolor(15);
                     switch(opcao)
                     {
                         case 'D':
                             printf("Informe a descricao buscada: ");
                             fflush(stdin);
                             textcolor(10);
                             gets(objeto);
                             strcpy(objeto,strlwr(objeto));
                             break;
                         case 'C':
                             printf("Informe a cor buscada: ");
                             fflush(stdin);
                             textcolor(10);
                             gets(objeto);
                             strcpy(objeto,strlwr(objeto));
                             break;
                         case 'P':
                             printf("Informe o preco minimo buscado: ");
                             textcolor(10);
                             scanf("%f",&precomin);
                             textcolor(15);
                             printf("Informe o preco maximo buscado: ");
                             textcolor(10);
                             scanf("%f",&precomax);
                             break;
                     }
                     textcolor(15);
                     while(!feof(arq))
                     {
                         r = fgets(linha,MAX_LINHA,arq);
                         if (r)
                         {

                             produto.codigo = atoi(strtok(linha,","));
                             strcpy(produto.descricao,(strtok(NULL,",")));
                             produto.altura = atoi(strtok(NULL,","));
                             produto.largura = atoi(strtok(NULL,","));
                             produto.profundidade = atoi(strtok(NULL,","));
                             produto.preco = atof(strtok(NULL,","));
                             produto.estoque = atoi(strtok(NULL,","));
                             strcpy(produto.cor,strtok(NULL,"\n"));

                             if(opcao == 'D' && (strcmp(objeto,produto.descricao) == 0))
                             {
                                 imprime_eletro(produto);
                                 encontrados[i] = produto.codigo;
                                 i++;
                                 produtosencontrados++;
                             }
                             else
                                 if(opcao == 'C' && (strcmp(objeto,produto.cor) == 0))
                                 {
                                     imprime_eletro(produto);
                                     encontrados[i] = produto.codigo;
                                     i++;
                                     produtosencontrados++;
                                 }
                                 else
                                     if(opcao == 'P' && produto.preco <= precomax && produto.preco >= precomin)
                                     {
                                         imprime_eletro(produto);
                                         encontrados[i] = produto.codigo;
                                         i++;
                                         produtosencontrados++;
                                     }
                             }

                     }
                     if(produtosencontrados==0)
                     {
                         textcolor(12);
                         printf("\nNenhum produto encontrado.");
                         fflush(stdin);getchar();
                         textcolor(15);
                     }
                     else
                     {
                         printf("\nForam encontrados ");
                         textcolor(10);
                         printf("%d", produtosencontrados);
                         textcolor(15);
                         printf(" produtos.");
                         fflush(stdin);getchar();
                     }fclose(arq);break;

                     case 'V':
                     arq = fopen("vestuario.txt","r");
                     if(arq == NULL)
                     {
                         textcolor(12);
                         printf("Houve um erro ao abrir o arquivo. O programa sera terminado.");
                         fflush(stdin);getch();
                         exit(1);
                     }
                     else
                         printf("\n=================================================================");
                         printf("\nComo voce deseja pesquisar o produto?");
                         textcolor(10);printf("\nD");textcolor(15);printf("escricao    ");textcolor(10);printf("C");textcolor(15);printf("or");textcolor(10);printf("    P");textcolor(15);printf("reco");textcolor(10);
                         printf("\nG");textcolor(15);printf("enero");textcolor(15);textcolor(10);printf("       T");textcolor(15);printf("amanho\n");
                         confirmacao=0;
                         do
                         {
                             textcolor(10);fflush(stdin);scanf("%c",&opcao);opcao=toupper(opcao);
                             if(opcao=='D')
                                 confirmacao=1;
                             if(opcao=='C')
                                  confirmacao=1;
                             if(opcao=='P')
                                  confirmacao=1;
                             if(opcao=='T')
                                  confirmacao=1;
                             if(opcao=='G')
                                  confirmacao=1;
                             if(confirmacao!=1)
                             {
                                  textcolor(12);
                                  printf("Opcao invalida. Por favor digite uma opcao valida: ");
                             }
                         }while(confirmacao!=1);
                         textcolor(15);
                         switch(opcao)
                         {
                             case 'D':
                                  printf("Informe a descricao buscada: ");
                                  textcolor(10);fflush(stdin);gets(objeto);
                                  strcpy(objeto,strlwr(objeto));
                                  break;
                             case 'T':
                                  printf("Escolha o tamanho:\n(");
                                  textcolor(10);printf("PP");textcolor(15);printf(" / ");textcolor(10);printf("P");
                                  textcolor(15);printf(" / ");textcolor(10);printf("M");
                                  textcolor(15);printf(" / ");textcolor(10);printf("G");
                                  textcolor(15);printf(" / ");textcolor(10);printf("XG");
                                  textcolor(15);printf(")\n");
                                  confirmacao=0;
                                  do
                                  {
                                      textcolor(10);fflush(stdin);gets(objeto);
                                      strcpy(objeto,strupr(objeto));
                                      if(strcmp(objeto,"PP")==0)
                                          confirmacao=1;
                                      if(strcmp(objeto,"P")==0)
                                          confirmacao=1;
                                      if(strcmp(objeto,"M")==0)
                                          confirmacao=1;
                                      if(strcmp(objeto,"G")==0)
                                          confirmacao=1;
                                      if(strcmp(objeto,"XG")==0)
                                          confirmacao=1;
                                      if(confirmacao!=1)
                                      {
                                           textcolor(12);
                                           printf("Opcao invalida. Por favor digite uma opcao valida: ");
                                      }
                                  }while(confirmacao!=1);
                                  break;
                             case 'P':
                                   printf("Informe o preco minimo buscado: ");
                                   textcolor(10);scanf("%f",&precomin);
                                   textcolor(15);printf("Informe o preco maximo buscado.\n");
                                   textcolor(10);scanf("%f",&precomax);fflush(stdin);
                                   break;
                             case 'C':
                                  printf("Informe a cor buscada: ");
                                  textcolor(10);fflush(stdin);scanf("%s",objeto);
                                  strcpy(objeto,strlwr(objeto));
                                  break;
                             case 'G':
                                  printf("Informe o genero (");textcolor(10);printf("masculino");textcolor(15);printf(", ");
                                  textcolor(10);printf("feminino");textcolor(15);printf(" ou ");textcolor(10);printf("unissex");
                                  textcolor(15);printf("): ");
                                   confirmacao=0;
                                  do
                                  {
                                      textcolor(10);fflush(stdin);gets(objeto);
                                      strupr(objeto);
                                      if(strcmp(objeto,"MASCULINO")==0)
                                          confirmacao=1;
                                      if(strcmp(objeto,"FEMININO")==0)
                                          confirmacao=1;
                                      if(strcmp(objeto,"UNISSEX")==0)
                                          confirmacao=1;
                                      if(confirmacao!=1)
                                      {
                                           textcolor(12);
                                           printf("Opcao invalida. Por favor digite uma opcao valida: ");
                                      }
                                  }while(confirmacao!=1);
                                  strcpy(objeto,strlwr(objeto));
                                  break;
                         }
                         while(!feof(arq))
                         {
                             r = fgets(linha,MAX_LINHA,arq);
                             if (r)
                             {
                                  produtovest.codigo = atoi(strtok(linha,","));
                                  strcpy(produtovest.descricao,(strtok(NULL,",")));
                                  strcpy(produtovest.tamanho,(strtok(NULL,",")));
                                  produtovest.preco = atof(strtok(NULL,","));
                                  produtovest.estoque = atoi(strtok(NULL,","));
                                  strcpy(produtovest.cor,(strtok(NULL,",")));
                                  strcpy(produtovest.genero,(strtok(NULL,"\n")));

                                  if(strcmp(objeto,produtovest.descricao)==0 || strcmp(objeto,produtovest.tamanho)==0 ||
                                  strcmp(objeto,produtovest.cor)==0 || strcmp(objeto,produtovest.genero)==0)
                                  {
                                     imprime_vest(produtovest);
                                     encontrados[i] = produto.codigo;
                                     i++;
                                     produtosencontrados++;
                                  }
                                  else
                                  if(opcao == 'P' && produtovest.preco <= precomax && produtovest.preco >= precomin)
                                  {
                                     imprime_vest(produtovest);
                                     encontrados[i] = produto.codigo;
                                     i++;
                                     produtosencontrados++;
                                  }

                             }
                         }

                         if(produtosencontrados==0)
                         {
                             textcolor(12);
                             printf("\nNenhum produto encontrado.");
                             fflush(stdin);getchar();
                         }
                         else
                         {
                                textcolor(15);
                                printf("\nForam encontrados ");
                                textcolor(10);
                                printf("%d", produtosencontrados);
                                textcolor(15);
                                printf(" produtos.");
                                fflush(stdin);getchar();
                         }
                         break;
            }
            textcolor(15);printf("\nVoce deseja realizar mais uma pesquisa? (");
            textcolor(10);printf("S");textcolor(15);printf(" ou ");textcolor(10);printf("N");textcolor(15);printf(">");
            confirmacao=0;
            do
            {
                textcolor(10);fflush(stdin);scanf("%c", &resposta);
                resposta=toupper(resposta);
                if(resposta=='S')
                {
                     maisuma=1;
                     confirmacao=1;
                }
                if(resposta=='N')
                {
                     maisuma=0;
                     confirmacao=1;
                }
                if(confirmacao==0)
                {
                     textcolor(12);
                     printf("Opcao invalida. Por favor digite uma opcao valida: ");
                }
            }while(confirmacao==0);
    }while(maisuma);
}

//mostra todas as compras do carrinho
void vizualizacompras(int cadastro)
{
     FILE *arq;
     CARRINHO carrinho;
     char cadastroEmCar[MAX_DIGITOS];
     int i;

     system("cls");
     itoa(cadastro, cadastroEmCar, 10);
     textcolor(14);printf("\nSEU CARRINHO DE COMPRAS:");
     textcolor(15);printf("\n=======================================================================");
     arq=fopen(cadastroEmCar, "rb");
     if(!arq)
     {
         printf("\nAinda nao ha itens no seu carrinho de compras.");
         fflush(stdin);getch();textcolor(15);
     }
     else
     {
             if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
             {
                 printf("\nVoce possui");textcolor(10);printf(" %d ", carrinho.itensEletro);textcolor(15);
                 printf("eletrodomesticos e");textcolor(10);printf(" %d ", carrinho.itensVestuario);
                 textcolor(15);printf("pecas de vestuario no seu carrinho.");
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
     char cadastroEmChar[MAX_DIGITOS], salvaLinha[MAX_PRODUTOS][MAX_LINHA], string[MAX_LINHA];
     int i, j, k, contalinha, comparaCodigo, achou=0, codigo;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;

     system("cls");
     textcolor(14);printf("\nCANCELAR TODAS AS COMPRAS:");
     textcolor(15);printf("\n=======================================================================");
     itoa(cadastro, cadastroEmChar, 10);
     arq=fopen(cadastroEmChar, "rb");
     if(!arq)
     {
             printf("\nNao ha itens em seu carrinho para serem excluidos.");
             fflush(stdin);getch();textcolor(15);
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
                             textcolor(12);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(15);
                             getch();
                             exit(1);
                         }
                         contalinha=0;
                         while(!feof(arqtxt))
                         {
                              fgets(salvaLinha[contalinha], sizeof(salvaLinha[contalinha]), arqtxt);
                              contalinha++;
                         }
                         fclose(arqtxt);
                         remove("eletro.txt");

                         arqtxt=fopen("eletro.txt", "w");
                         if(!arqtxt)
                         {
                             textcolor(12);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(15);
                             getch();
                             exit(1);
                         }
                         for(j=0; j<contalinha; j++)
                         {
                                  strcpy(string, salvaLinha[j]);
                                  codigo=atoi(strtok(string, ","));
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
                             textcolor(12);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(15);
                             getch();
                             exit(1);
                         }
                         contalinha=0;
                         while(!feof(arqtxt))
                         {
                              fgets(salvaLinha[contalinha], sizeof(salvaLinha[contalinha]), arqtxt);
                              contalinha++;
                         }
                         fclose(arqtxt);
                         remove("vestuario.txt");

                         arqtxt=fopen("vestuario.txt", "w");
                         if(!arqtxt)
                         {
                             textcolor(12);
                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                             textcolor(15);
                             getch();
                             exit(1);
                         }
                         for(j=0; j<contalinha; j++)
                         {
                                  strcpy(string, salvaLinha[j]);
                                  codigo=atoi(strtok(string, ","));
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
         textcolor(14);printf("\nSeu carrinho foi esvaziado!");textcolor(15);fflush(stdin);getch();
     }
}
//fim da funcao de cancelamento de pedido

void excluiUmProduto(int cadastro)
{

     FILE *arq, *arqtxt;
     int codigoExclui, i, j, contalinha, achou, codigo;
     int maisuma, confirmacao;
     char cadastroEmChar[MAX_DIGITOS], salvaLinha[MAX_PRODUTOS][MAX_LINHA], string[MAX_LINHA];
     char resposta;
     ELETRO eletronico;
     VESTUARIO vestuario;
     CARRINHO carrinho;

     do
     {
             achou=0;
             system("cls");
             textcolor(14);printf("\nEXCLUIR ITEM DO CARRINHO");
             textcolor(15);printf("\n==================================================================");
             itoa(cadastro, cadastroEmChar, 10);
             arq=fopen(cadastroEmChar, "rb");
             if(!arq)
             {
                     textcolor(15);printf("\nNao ha itens em seu carrinho para serem excluidos.");
                     fflush(stdin);getch();textcolor(15);
                     maisuma=0;
             }
             else
             {
                 printf("\nInforme o codigo do produto que voce quer excluir do seu carrinho: ");
                 textcolor(10);scanf("%d", &codigoExclui);textcolor(15);
                 if(fread(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                 {
                       fclose(arq);
                       for(i=0; i<carrinho.itensEletro; i++)
                       {
                                if(codigoExclui==carrinho.eletronico[i].codigo && achou==0)
                                {
                                    arq=fopen(cadastroEmChar, "wb");
                                    if(!arq)
                                    {
                                            textcolor(12);printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            fflush(stdin);getch();exit(1);
                                    }
                                    achou=1;
                                    carrinho.eletronico[i]=carrinho.eletronico[carrinho.itensEletro-1];
                                    carrinho.itensEletro=carrinho.itensEletro-1;
                                    if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                    {
                                        textcolor(14);printf("Uma unidade do produto de codigo");
                                        textcolor(10);printf(" %d ", codigoExclui);
                                        textcolor(14);printf("foi excluido de seu carrinho.");
                                        fflush(stdin);getch();
                                    }
                                    fclose(arq);
                                    if(carrinho.itensEletro==0 && carrinho.itensVestuario==0)
                                        remove(cadastroEmChar);
                                    //repoe o estoque dos eletrodomesticos
                                    arqtxt=fopen("eletro.txt", "r");
                                     if(!arqtxt)
                                     {
                                             textcolor(12);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                     }
                                     contalinha=0;
                                     while(!feof(arqtxt))
                                     {
                                          fgets(salvaLinha[contalinha], sizeof(salvaLinha[contalinha]), arqtxt);
                                          contalinha++;
                                     }
                                     fclose(arqtxt);
                                     remove("eletro.txt");

                                     arqtxt=fopen("eletro.txt", "w");
                                     if(!arqtxt)
                                     {
                                             textcolor(12);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                     }
                                     for(j=0; j<contalinha; j++)
                                     {
                                              strcpy(string, salvaLinha[j]);
                                              codigo=atoi(strtok(string, ","));
                                              if(codigo==codigoExclui)
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
                       if(achou!=1)
                       {
                             for(i=0; i<carrinho.itensVestuario; i++)
                             {
                                    if(codigoExclui==carrinho.vestuario[i].codigo && achou==0)
                                    {
                                        arq=fopen(cadastroEmChar, "wb");
                                        if(!arq)
                                        {
                                            textcolor(12);printf("Houve um erro ao abrir o arquivo. O programa sera finalizado.");
                                            fflush(stdin);getch();exit(1);
                                        }
                                        achou=1;
                                        carrinho.vestuario[i]=carrinho.vestuario[carrinho.itensVestuario-1];
                                        carrinho.itensVestuario=carrinho.itensVestuario-1;
                                        if(fwrite(&carrinho, sizeof(CARRINHO), 1, arq)==1)
                                        {
                                            textcolor(14);printf("Uma unidade do produto de codigo");
                                            textcolor(10);printf(" %d ", codigoExclui);
                                            textcolor(14);printf("foi excluido de seu carrinho.");
                                            fflush(stdin);getch();
                                        }
                                        fclose(arq);

                                        if(carrinho.itensEletro==0 && carrinho.itensVestuario==0)
                                             remove(cadastroEmChar);
                                        //repoe o estoque
                                         arqtxt=fopen("vestuario.txt", "r");
                                         if(!arqtxt)
                                         {
                                             textcolor(12);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                         }
                                         contalinha=0;
                                         while(!feof(arqtxt))
                                         {
                                              fgets(salvaLinha[contalinha], sizeof(salvaLinha[contalinha]), arqtxt);
                                              contalinha++;
                                         }
                                         fclose(arqtxt);
                                         remove("vestuario.txt");

                                         arqtxt=fopen("vestuario.txt", "w");
                                         if(!arqtxt)
                                         {
                                             textcolor(12);
                                             printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                                             fflush(stdin);getch();exit(1);
                                         }
                                         for(j=0; j<contalinha; j++)
                                         {
                                                  strcpy(string, salvaLinha[j]);
                                                  codigo=atoi(strtok(string, ","));
                                                  if(codigoExclui==codigo)
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
                       if(achou!=1)
                       {
                           textcolor(12);printf("Nao foi encontrado nenhum item com esse codigo em seu carrinho.");
                       }
                 }
                 else
                 {
                     textcolor(12);printf("Houve um problema ao abrir seu carrinho.");
                     fflush(stdin);getch();
                     fclose(arq);
                 }
                    textcolor(15);printf("\nVoce deseja excluir mais um item do seu carrinho? (");
                    textcolor(10);printf("S");textcolor(15);printf(" ou ");textcolor(10);printf("N");textcolor(15);printf(">");
                    confirmacao=0;
                    do
                    {
                        textcolor(10);fflush(stdin);scanf("%c", &resposta);
                        resposta=toupper(resposta);
                        if(resposta=='S')
                        {
                             maisuma=1;
                             confirmacao=1;
                        }
                        if(resposta=='N')
                        {
                             maisuma=0;
                             confirmacao=1;
                        }
                        if(confirmacao==0)
                        {
                             textcolor(12);
                             printf("Opcao invalida. Por favor digite uma opcao valida: ");
                        }
                    }while(confirmacao==0);
             }
     }while(maisuma);
}

void fechaCompra(int cadastro)
{
     FILE *arq, *arqtxt;
     CARRINHO carrinho;
     int i;
     float valorDaCompra;
     char string[MAX_LINHA], dia[MAX_DIGITOS], mes[MAX_DIGITOS], ano[MAX_DIGITOS];
     char cadastroEmChar[MAX_DIGITOS];

     system("cls");
     itoa(cadastro, cadastroEmChar, 10);
     textcolor(14);printf("\nFECHAR COMPRA");
     textcolor(15);printf("\n==============================================================");
     strcpy(string, __DATE__);
     strcpy(mes, strupr(strtok(string, " ")));
     strcpy(dia, strtok(NULL, " "));
     strcpy(ano, strtok(NULL, "\n"));
     arq=fopen(cadastroEmChar, "rb");
     if(!arq)
     {
             textcolor(15);printf("\nSeu carrinho ainda nao possui nenhum item para poder fechar a compra");
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
                          textcolor(12);printf("\nHouve um erro ao abrir o arquivo. O programa sera finalizado.");
                          fflush(stdin);getch();exit(1);
                    }
                    fprintf(arqtxt, "%c%s%c%s%c%s%c", '\n', dia, ',', mes, ',', ano, ',');
                    fprintf(arqtxt, "%d%c%d%c%.2f", carrinho.itensEletro, ',', carrinho.itensVestuario, ',', valorDaCompra);
                    fclose(arqtxt);
                    printf("\nData da compra: ");textcolor(10);printf("%s", dia);
                    textcolor(15);printf("/");textcolor(10);printf("%s", mes);
                    textcolor(15);printf("/");textcolor(10);printf("%s", ano);
                    textcolor(15);printf("\nValor total da compra: ");textcolor(10);printf("%.2f.", valorDaCompra);
                    textcolor(15);
                    if(carrinho.itensEletro!=0)
                    {
                           printf("\nEletrodomesticos comprados: ");textcolor(10);printf("%d", carrinho.itensEletro);
                    }
                    else
                          printf("\nNenhum eletrodomestico comprado.");
                    textcolor(15);
                    if(carrinho.itensVestuario!=0)
                    {
                           printf("\nPecas de vestuario compradas: ");textcolor(10);printf("%d.", carrinho.itensVestuario);
                    }
                    else
                          printf("\nNenhuma peca de vestuario comprada.");
                    textcolor(14);printf("\nSua compra foi finalizada! \nVoce estara recebendo sua encomenda");
                    printf(" dentro de");textcolor(10);printf(" %d ", DIAS_UTEIS);textcolor(14);printf("dias uteis.");
                    fflush(stdin);getch();
         }
         else
         {
                     textcolor(12);
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
     int contador, i, totalCarrinhosAbertos, carrinhosAbertos[MAX_USUARIOS], codigo;
     char cadastroEmChar[MAX_DIGITOS], string[MAX_LINHA];

     arq=fopen("usuarios.txt", "r");
     if(!arq)
     {
             textcolor(12);printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
             fflush(stdin);getch();exit(1);
     }
     contador=0;
     while(!feof(arq))
     {
        fgets(string, MAX_LINHA, arq);
        if(string[0]!='\n')
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
     return(totalCarrinhosAbertos);
}

void menuCLIENTE(char nome[], int cadastro)
{
    FILE *arq;
    char resposta, cadastroEmCar[MAX_DIGITOS];
    int respostaalg=0, comprasSuspensas;
    do
    {
            system("cls");
            textcolor(14);
            printf("\nCLIENTE: ");
            textcolor(10);
            printf("%s", nome);
            textcolor(15);
            printf("\nData: %s Hora: %s",__DATE__,__TIME__);
            printf("\n=====================================================================");
            printf("\nSelecione a letra correspondente em verde para acessar a opcao.\n");
            textcolor(10);
            printf("\nT");textcolor(15);printf("rocar Usuario (Suspende as compras que estiverem abertas e faz logout)");
            textcolor(10);printf("\nS");textcolor(15);printf("air (Cancela suas compras e faz logout)");
            printf("\nC");textcolor(10);printf("o");textcolor(15);printf("ncluir (Fecha as suas compras e faz logout)");
            textcolor(10);printf("\n\nP");textcolor(15);printf("esquisar");
            textcolor(10);printf("                 I");textcolor(15);printf("nserir");
            textcolor(10);printf("\nE");textcolor(15);printf("xcluir um item");
            textcolor(10);printf("           V");textcolor(15);printf("isualizar");
            textcolor(10);printf("\nF");textcolor(15);printf("echar as compras");
            textcolor(10);printf("         C");textcolor(15);printf("ancelar as compras");
            printf("\n==================================================================\n");
            do
            {
                textcolor(10);fflush(stdin);scanf("%c", &resposta);
                resposta=toupper(resposta);
                textcolor(15);
                switch(resposta)
                {
                    case 'T':
                    {
                         itoa(cadastro, cadastroEmCar, 10);
                         arq=fopen(cadastroEmCar, "rb");
                         if(arq)                        //checa se o usuario tem comopras para suspender
                         {
                             comprasSuspensas=contaComprasSuspensas();
                             if(comprasSuspensas<MAX_COMPRAS_SUSP)
                             {
                                   printf("\nSuas compras ficarao suspensas. Voce podera finaliza-las mais tarde.");
                                   fflush(stdin);getch();
                                   respostaalg=10;
                             }
                             else
                             {
                                 textcolor(12);printf("\nO numero maximo de compras suspensas simultaneas");
                                 printf("\nfoi atingido. Voce tera que fechar suas compras ou cancela-las.");
                                 textcolor(15);
                                 respostaalg=1;
                             }
                             fclose(arq);
                         }
                         else
                             respostaalg=10;
                         break;
                    }
                    case 'S':
                    {
                         printf("\nSuas compras serao canceladas antes de voce fazer logout.");
                         fflush(stdin);getch();
                         cancelaTodasCompras(cadastro);
                         respostaalg=10;
                         break;
                    }
                    case 'O':
                    {
                         printf("\nSuas compras serao finalizadas antes de voce fazer logout.");
                         fflush(stdin);getch();
                         fechaCompra(cadastro);
                         respostaalg=10;
                         break;
                    }
                    case 'P':
                    {
                         pesquisar();
                         respostaalg=1;
                         break;
                    }
                    case 'I':
                    {
                         inserirProdutoCarrinho(cadastro);
                         respostaalg=1;
                         break;
                    }
                    case 'E':
                    {
                         excluiUmProduto(cadastro);
                         respostaalg=1;
                         break;
                    }
                    case 'V':
                    {
                         vizualizacompras(cadastro);
                         respostaalg=1;
                         break;
                    }
                    case 'F':
                    {
                         fechaCompra(cadastro);
                         respostaalg=1;
                         break;
                    }
                    case 'C':
                    {
                         cancelaTodasCompras(cadastro);
                         respostaalg=1;
                         break;
                    }
                    default:
                    {
                       textcolor(12);
                       printf("Opcao invalida. Por favor digite uma opcao valida: ");
                       respostaalg=0;
                    }
                }
             }while(respostaalg==0);
    }while(respostaalg!=10);
}

//funções de relatorios de gerentes

void relatorioComprasEmAndamento()
{
     FILE *arq;
     int contador, i, totalCarrinhosAbertos, carrinhosAbertos[MAX_USUARIOS], codigo;
     char cadastroEmChar[MAX_DIGITOS], string[MAX_LINHA];

     system("cls");
     textcolor(14);printf("\nUSUARIOS COM CARRINHOS ABERTOS:");
     textcolor(15);printf("\n===============================================================");
     arq=fopen("usuarios.txt", "r");
     if(!arq)
     {
             textcolor(12);printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
             fflush(stdin);getch();exit(1);
     }
     contador=0;
     while(!feof(arq))
     {
        fgets(string, MAX_LINHA, arq);
        if(string[0]!='\n')
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
             printf("\nTotal de usuarios com carrinhos abertos: ");textcolor(10);printf("%d", totalCarrinhosAbertos);
             textcolor(15);printf("\nUsuarios com carrinhos abertos:");
             arq=fopen("usuarios.txt", "r");
             if(!arq)
             {
                     textcolor(12);printf("\nHouve um problema ao abrir o arquivo, o programa será encerrado.");
                     fflush(stdin);getch();exit(1);
             }
             for(i=0; i<totalCarrinhosAbertos; i++)
             {
                           rewind(arq);
                           while(!feof(arq))
                           {
                                fgets(string, MAX_LINHA, arq);
                                codigo=atoi(strtok(string, ","));
                                if(codigo==carrinhosAbertos[i])
                                {
                                     textcolor(15);
                                     printf("\n===========================================");
                                     printf("\nCodigo: ");textcolor(10);printf("%d", codigo);
                                     textcolor(15);
                                     printf("\nNome: ");textcolor(10);printf("%s", strtok(NULL, ","));
                                     textcolor(15);
                                     printf("\nTipo: ");textcolor(10);printf("%s", strtok(NULL, "\n"));
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
     char dia[MAX_DIGITOS], mes[MAX_DIGITOS], ano[MAX_DIGITOS], string[MAX_LINHA];
     char comp[MAX_LINHA];
     int confirmacao, vendasEletro=0, vendasVestuario=0, encontrou=0;
     float totalVendas=0;

     system("cls");
     textcolor(14);printf("\nVENDAS POR TIPO:");
     textcolor(15);printf("\n======================================================");
     printf("\nInforme uma data. Ex (8, jul , 2010)");
     printf("\nDia: ");textcolor(10);fflush(stdin);gets(dia);
     textcolor(15);printf("Mes: ");textcolor(10);fflush(stdin);gets(mes);strupr(mes);
     textcolor(15);printf("Ano: ");textcolor(10);fflush(stdin);gets(ano);
     arq=fopen("report.txt", "r");
     if(arq)
     {
             while(!feof(arq))
             {
                 fgets(string, MAX_LINHA, arq);
                 if(string[0]!='\n')
                 {
                     confirmacao=0;
                     strcpy(comp, strtok(string, ","));
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
                         totalVendas+=atof(strtok(NULL, "\n"));
                         encontrou=1;
                     }
                 }
             }
             fclose(arq);
             if(encontrou)
             {
                 textcolor(15);printf("\nTotal de vendas no dia ");textcolor(10);printf("%s", dia);
                 textcolor(15);printf("/");textcolor(10);printf("%s", mes);textcolor(10);printf("/");
                 textcolor(10);printf("%s", ano);textcolor(15);printf(":");
                 printf("\nNumero de eletrodomesticos vendidos: ");textcolor(10);printf("%d", vendasEletro);
                 textcolor(15);printf("\nNumero de pecas de vestuario vendidas: ");
                 textcolor(10);printf("%d", vendasVestuario);textcolor(15);
                 printf("\nTotal de vendas: R$ ");textcolor(10);printf("%.2f", totalVendas);
                 fflush(stdin);getch();
             }
             else
             {
                 textcolor(12);printf("\nA data informada nao foi encontrada nos registros.");
                 fflush(stdin);getch();
             }
     }
     else
     {
         textcolor(12);printf("\nNenhuma venda foi efetuada ainda.");
         fflush(stdin);getch();
     }
}

void verificaEstoque()
{
     FILE *arq;
     char string[MAX_LINHA];

     //imprime eletro
     system("cls");
     textcolor(14);printf("\nESTOQUE:");
     textcolor(15);printf("\n===============================================================");
     arq=fopen("eletro.txt", "r");
     textcolor(14);printf("\nEletrodomesticos:");
     while(!feof(arq))
     {
         fgets(string, sizeof(string), arq);
         textcolor(15);printf("\n====================================================");
         printf("\nCodigo do produto: ");
         textcolor(10);printf("%s", strtok(string,","));
         textcolor(15);printf("\nDescricao do produto: ");
         textcolor(10);printf("%s", strtok(NULL,","));
         textcolor(15);printf("\nAltura: ");
         textcolor(10);printf("%s", strtok(NULL,","));textcolor(15);printf(" cm");
         textcolor(15);printf("\nLargura: ");
         textcolor(10);printf("%s", strtok(NULL,","));textcolor(15);printf(" cm");
         textcolor(15);printf("\nProfundidade: ");
         textcolor(10);printf("%s", strtok(NULL,","));textcolor(15);printf(" cm");
         textcolor(15);printf("\nPreco:");
         textcolor(10);printf("%s", strtok(NULL,","));textcolor(15);printf(" reais");
         textcolor(14);printf("\nEstoque: ");
         textcolor(10);printf("%s", strtok(NULL,","));textcolor(15);printf(" unidades");
         textcolor(15);printf("\nCor do produto: ");
         textcolor(10);printf("%s", strtok(NULL,"\n"));
     }
     fclose(arq);
     fflush(stdin);getch();
     //imprime vestuario
     system("cls");
     textcolor(14);printf("\nESTOQUE:");
     textcolor(15);printf("\n===============================================================");
     arq=fopen("vestuario.txt", "r");
     textcolor(14);printf("\nVestuario:");
     while(!feof(arq))
     {
         fgets(string, sizeof(string), arq);
         textcolor(15);printf("\n====================================================");
         printf("\nCodigo do produto: ");
         textcolor(10);printf("%s", strtok(string,","));
         textcolor(15);printf("\nDescricao do produto: ");
         textcolor(10);printf("%s", strtok(NULL,","));
         textcolor(15);printf("\nTamanho: ");
         textcolor(10);printf("%s", strtok(NULL,","));
         textcolor(15);printf("\nPreco:");
         textcolor(10);printf("%s", strtok(NULL,","));textcolor(15);printf(" reais");
         textcolor(14);printf("\nEstoque: ");
         textcolor(10);printf("%s", strtok(NULL,","));textcolor(15);printf(" unidades");
         textcolor(15);printf("\nCor do produto: ");
         textcolor(10);printf("%s", strtok(NULL,","));
         textcolor(15);printf("\nGenero: ");
         textcolor(10);printf("%s", strtok(NULL,"\n"));
     }
     fclose(arq);
     fflush(stdin);getch();
}

void clientesCadastrados()
{
      FILE *arq;
      char string[MAX_LINHA];

      system("cls");
      textcolor(14);printf("\nCLIENTES CADASTRADOS:");
      textcolor(15);printf("\n=======================================================");
      arq=fopen("usuarios.txt", "r");
      if(!arq)
      {
             textcolor(12);printf("\nHouve um problema ao abrir o arquivo, o programa será encerrado.");
             fflush(stdin);getch();exit(1);
      }
      while(!feof(arq))
      {
          fgets(string, sizeof(string), arq);
          printf("\n===========================================");
          printf("\nCodigo: ");textcolor(10);printf("%s", strtok(string, ","));
          textcolor(15);
          printf("\nNome: ");textcolor(10);printf("%s", strtok(NULL, ","));
          textcolor(15);
          printf("\nTipo: ");textcolor(10);printf("%s", strtok(NULL, "\n"));
          textcolor(15);printf("\n===========================================");
      }
      fflush(stdin);getch();
}

void menuGERENTE(char nome[], int cadastro)
{
    char resposta;               //resposta caracter informada pelo usuario
    int respostaalg=0;           //resposta devolvida pela funcao

    do
    {
        system("cls");
        textcolor(14);printf("\nGERENTE: ");
        textcolor(10);printf(" %s", nome);
        textcolor(15);printf("\nData: %s Hora: %s",__DATE__,__TIME__);
        printf("\n====================================================================");
        printf("\nSelecione a letra correspondente em verde para acessar a opcao.\n");
        textcolor(10);printf("\nT");textcolor(15);printf("rocar Usuario");
        textcolor(10);printf("\n\nP");textcolor(15);printf("esquisar");
        printf("\n\nRelatorios:");
        textcolor(10);
        printf("\nC");textcolor(15);printf("ompras em Andamento");
        textcolor(10);printf("\nV");textcolor(15);printf("endas");
        textcolor(10);printf("\nE");textcolor(15);printf("stoque");
        printf("\nC");textcolor(10);printf("l");textcolor(15);printf("lientes Cadastrados");
        printf("\n==================================================================\n");
        do
        {
            textcolor(10);
            fflush(stdin);
            scanf("%c", &resposta);
            resposta=toupper(resposta);
            textcolor(15);
            switch(resposta)
            {
                case 'T':
                {    respostaalg=10;
                     break;
                }
                case 'P':
                {
                     pesquisar();
                     respostaalg=1;
                     break;
                }
                case 'C':
                {
                     relatorioComprasEmAndamento();
                     respostaalg=1;
                     break;
                }
                case 'V':
                {
                     vendas();
                     respostaalg=1;
                     break;
                }
                case 'E':
                {
                     verificaEstoque();
                     respostaalg=1;
                     break;
                }
                case 'L':
                {
                     clientesCadastrados();
                     respostaalg=1;
                     break;
                }
                default:
                {
                   textcolor(12);
                   printf("Opcao invalida. Por favor digite uma opcao valida: ");
                   respostaalg=0;
                }
            }
         }while(respostaalg==0);
    }while(respostaalg!=10);
}

//INICIO DA TELA DE LOGIN
void telaLogin()
{
    FILE *arq;
    int cadastro, i, comparacadastro, achou=0, GouC;
    char string[MAX_LINHA], tipoCliente[TAM_NOME_MAX], nome[TAM_NOME_MAX];
    system("cls");
    textcolor(14);
    printf("\nLOGIN");
    textcolor(15);
    printf("\n=================================================================");
    printf("\nInforme seu numero de cadastro: ");
    do
    {
            textcolor(10);
            scanf("%d", &cadastro);
            textcolor(15);
            arq=fopen("usuarios.txt", "r");
            if(!arq)
            {
                    textcolor(12);
                    printf("Houve um problema ao abrir o arquivo, o programa será encerrado.");
                    textcolor(15);
                    getch();
                    exit(1);
            }
            while(!feof(arq) && achou==0)
            {
                 fgets(string, sizeof(string), arq);
                 comparacadastro=atoi(strtok(string, ","));
                 if(cadastro==comparacadastro)
                 {
                     strcpy(nome, strtok(NULL, ","));
                     strcpy(tipoCliente, (strtok(NULL, "\n")));
                     achou=1;
                 }
            }
            fclose(arq);
            if(achou==1)
            {
                GouC=strcmp("gerente", tipoCliente);
                if(GouC==0)
                   menuGERENTE(nome, cadastro);
                else
                   menuCLIENTE(nome, cadastro);
            }
            else
            {
                textcolor(12);
                printf("Usuario nao encontrado. Informe outro cadastro: ");
                textcolor(14);
                getch();
            }
    }while(achou==0);
}
//FIM DA TELA DE LOGIN

int main()
{
    FILE *arq;
    int cadastro, opcaoinicial, opcaologin;
    textcolor(15);

    //cria o arquivo usuarios.txt caso ele nao existir
    arq=fopen("usuarios.txt", "a");
    if(!arq)
    {
            textcolor(12);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            textcolor(15);
            getch();
            exit(1);
    }
    fclose(arq);

    //cria o arquivo vestuario.txt caso ele nao existir
    arq=fopen("vestuario.txt", "a");
    if(!arq)
    {
            textcolor(12);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            textcolor(15);
            getch();
            exit(1);
    }
    fclose(arq);

    //cria o arquivo eletro.txt caso ele nao exitir
    arq=fopen("eletro.txt", "a");
    if(!arq)
    {
            textcolor(12);
            printf("\nErro ao criar arquivo! O programa sera finalizado.");
            textcolor(15);
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
    textcolor(12);
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
    textcolor(9);
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
