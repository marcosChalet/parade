#ifndef _LISTA_H
#define _LISTA_H

#include "includes.h"

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
