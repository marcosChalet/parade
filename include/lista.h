#ifndef _LISTA_H
#define _LISTA_H

#include "includes.h"

typedef struct elemento* Lista;

Lista* criarLista ();

int inserirInicio (Lista *, Carta);
void destruirLista (Lista *);
int removerQualquer (Lista *, Carta);
int acessarIndice (Lista *, int, Carta *);
int quantidade (Lista *);
int somarValores (Lista *);

void mostrarLista (Lista *);

#endif
