#ifndef MENUGERENTE_H_INCLUDED
#define MENUGERENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "mudaCor.h"
#include "pesquisaProduto.h"

void relatorioComprasEmAndamento();

void vendas();

void verificaEstoque();

void clientesCadastrados();

void menuGerente(char nome[], int cadastro);

#endif // MENUGERENTE_H_INCLUDED
