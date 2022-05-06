#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct aluno {
    char nome[50];
    int matricula;
    float av1;
    float av2;
    float av3;
};

typedef struct elemento* Lista;

Lista* criaLista ();
bool listaVazia (Lista *);

bool insereInicio (Lista *, struct aluno);
bool insereFim (Lista *, struct aluno);

void destoiLista (Lista *);
bool removeElemento (Lista *, int);
bool removeInicio (Lista *);
bool removeFim (Lista *);

bool acessaIndice (Lista *, int, struct aluno *);
bool acessaValor (Lista *, int, struct aluno *);

void mostraLista (Lista *);

#endif
