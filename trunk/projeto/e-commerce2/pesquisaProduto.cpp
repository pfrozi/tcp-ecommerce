#include "pesquisaProduto.h"

//funcao usada pela funcao pesquisaProduto
void imprimeVestuario(VESTUARIO produtoVestuario)
{
    mudaCor(Colors_WHITE);
    printf("\nCodigo: %d  Descricao: %s\n",produtoVestuario.codigo, produtoVestuario.descricao);
    printf("Tamanho: %s  Preco: %.2f  Estoque:  %d\n",produtoVestuario.tamanho, produtoVestuario.preco, produtoVestuario.estoque);
    printf("Cor: %s  Genero: %s\n",produtoVestuario.cor, produtoVestuario.genero);
    printf("\n================================================================");
}

//funcao usada pela funcao pesquisaProduto
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
                                     encontrados[i] = produtoVestuario.codigo;
                                     i++;
                                     produtosEncontrados++;
                                  }
                                  else
                                  if(opcao == 'P' && produtoVestuario.preco <= precoMax && produtoVestuario.preco >= precoMin)
                                  {
                                     imprimeVestuario(produtoVestuario);
                                     encontrados[i] = produtoVestuario.codigo;
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
                if(opcaoValida==false)
                {
                     mudaCor(Colors_RED);
                     printf("Opcao invalida. Por favor digite uma opcao valida: ");
                }
            }while(opcaoValida==false);
    }while(continuaPesquisa);
}
