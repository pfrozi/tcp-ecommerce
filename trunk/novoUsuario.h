#ifndef NOVOUSUARIO_H_INCLUDED
#define NOVOUSUARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include "mudaCor.h"

typedef struct
{
        int codigo;
        char nome[TAM_NOME_MAX];
        char categoria[TAM_NOME_MAX];
}USUARIO;

void novoUsuario();

#endif // NOVOUSUARIO_H_INCLUDED
