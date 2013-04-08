#include "menuCliente.h"

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
     int i, j, contaLinhas, codigo;
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

void insereProdutoCarrinho(int cadastro)
{
     FILE *arq;
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
    int contador, i, totalCarrinhosAbertos, listaCarrinhosAbertos[MAX_USUARIOS];
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
