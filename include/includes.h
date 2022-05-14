#ifndef INCLUDES_H
#define INCLUDES_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CARTAS 66
#define QTD_TROCAS 200
#define QTD_MAO 5
#define QTD_MESA 5
#define QTD_JOGADORES 2
#define QTD_NAIPES 6

struct carta {
  int numero;
  char naipe;
};

enum jogadores {
  JOGADOR,
  MAQUINA
};

typedef struct carta Carta;
typedef struct pilha Pilha;
typedef struct elemento* Lista;

#endif /* !INCLUDES_H */
