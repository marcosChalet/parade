#include "pilha.h"

struct pilha {
  int qtd;
  struct carta baralho[MAX_CARTAS];
};


Pilha* criarPilha () {

  Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
  if (pilha == NULL) return 0;

  pilha->qtd = 0;

  return pilha;
}


int pilhaCheia (Pilha* pilha) {
  if (pilha == NULL) return -1;
  if (pilha->qtd == MAX_CARTAS) return 1;
  return 0;
}


int inserirPilha (Pilha* pilha, Carta dadosCarta) {
  if (pilha == NULL) return 0;
  if (pilhaCheia(pilha)) return 0;

  pilha->baralho[pilha->qtd] = dadosCarta;
  pilha->qtd++;

  return 1;	
}


int removerPilha (Pilha* pilha, Carta* carta) {
  if(pilha == NULL) return 0;
  if(pilha->qtd == 0) return 0;

  *carta = pilha->baralho[pilha->qtd-1];

  pilha->qtd--;
  return 1;
}


int tamanhoPilha (Pilha *pilha) {
  if (pilha == NULL) return -1;
  return pilha->qtd;
}


void swap (Pilha *pilha, int posA, int posB) {
  Carta aux;

  aux = pilha->baralho[posA];
  pilha->baralho[posA] = pilha->baralho[posB];
  pilha->baralho[posB] = aux;
}


int embaralharPilha (Pilha *pilha) {
  if (pilha == NULL) return 0;
  if (pilha->qtd == 0) return 0;

  int cont = 0;
  while (QTD_TROCAS != cont++)
    swap(pilha, rand()%66, rand()%66);

  return 1;
}


int mostrarPilha (Pilha *pilha) {

  if(pilha == NULL) return 0;
  if(pilha->qtd == 0) return 0;

  printf("[ Topo da Pilha ]\n");
  for (int i = MAX_CARTAS-1; i >= 0; i--) 
    printf("%-2d, %c\n", pilha->baralho[i].numero, pilha->baralho[i].naipe);
}
