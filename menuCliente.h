#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "mudaCor.h"
#include "pesquisaProduto.h"


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

void cancelaTodasCompras(int cadastro);

void visualizaCompras(int cadastro);

void insereProdutoCarrinho(int cadastro);

void excluiProdutoCarrinho(int cadastro);

void fechaCompra(int cadastro);

int contaComprasSuspensas();

void menuCliente(char nome[], int cadastro);

#endif // MENUCLIENTE_H_INCLUDED
