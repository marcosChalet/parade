#ifndef PILHA_H
#define PILHA_H

#include "includes.h"

Pilha* criarPilha ();
int inserirPilha (Pilha *, struct carta);
int tamanhoPilha (Pilha *);
int mostrarPilha (Pilha *);
int embaralharPilha (Pilha *);
int removerPilha (Pilha *, Carta *);

#endif
