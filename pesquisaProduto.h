#ifndef PESQUISAPRODUTO_H_INCLUDED
#define PESQUISAPRODUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "mudaCor.h"

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

void imprimeVestuario(VESTUARIO produtoVestuario);

void imprimeEletro(ELETRO produtoEletro);

void pesquisaProduto();

#endif // PESQUISAPRODUTO_H_INCLUDED
