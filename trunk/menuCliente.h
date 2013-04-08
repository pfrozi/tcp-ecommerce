#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "mudaCor.h"
#include "pesquisaProduto.h"

#define MAX_CAR 20
#define MAX_DIGITOS 10
#define MAX_PRODUTOS 50
#define MAX_LINHA 256

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
