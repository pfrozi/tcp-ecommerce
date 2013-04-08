#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

#include "mudaCor.h"
#include "pesquisaProduto.h"
#include "global.h"


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
