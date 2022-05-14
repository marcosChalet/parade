#ifndef _LISTA_H
#define _LISTA_H

#include "includes.h"

typedef struct elemento* Lista;

Lista* criarLista ();

int inserirInicio (Lista *, Carta);
void destruirLista (Lista *);
int removerQualquer (Lista *, Carta, bool cartasIguais(Carta a, Carta b));
int acessarIndice (Lista *, int, Carta *);
int quantidade (Lista *);
int somarValores (Lista *);

bool exatamenteIguais (Carta a, Carta b);
bool parcialmenteIguais (Carta a, Carta b);
void pegaDesprotegida (Lista *, Lista *, Carta);
void mostrarLista (Lista *);

#endif
