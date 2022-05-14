/*
 * Aqui há a implementação das funções de uma lista encadeada, que são:
 * inserir (início e fim), remover (inicio, fim e elemento específico),
 * recuperar, destruir lista e mostrar.
 *
 * Nota: ldse == NULL e *ldse == NULL representa que a lista não existe e
 * que a lista está vazia, respectivamente.
 * */

#include "lista.h"

typedef struct elemento {
  Carta dados;
  struct elemento *prox;
}Elemento;

typedef struct elemento Elemento;

/*
 * Aloca uma lista e seta ela como vazia caso a alocação ocorra
 * correntamente.
 *
 * */

Lista* criarLista () {

  Lista *ldse;
  ldse = (Lista*)malloc(sizeof(Lista));

  if (ldse != NULL)
    *ldse = NULL;

  return ldse;
}


/* Verifica se a lista está vazia ou foi alocada */
int Listavazia (Lista *ldse) {
  if((*ldse) != NULL)
    return 0;

  return 1;
}


int inserirInicio (Lista *ldse, Carta novosDados) {

  if(ldse == NULL) {
    return 0;
  }else {
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    if(novo == NULL) return 0;

    novo->dados = novosDados;
    novo->prox = (*ldse);
    (*ldse) = novo;
  }

  return 1;
}


void destruirLista (Lista *ldse) {
  if(ldse != NULL) {
    Elemento *aux;
    while((*ldse) != NULL) {
      aux = *ldse;
      (*ldse) = (*ldse)->prox;
      free(aux);
    }
  }
}


bool exatamenteIguais (Carta a, Carta b) {
  if (a.numero == b.numero || a.naipe == b.naipe)
    return true;
  return false;
}


bool parcialmenteIguais (Carta a, Carta b) {
  if (a.numero <= b.numero || a.naipe == b.naipe) 
    return true;
  return false;
}


int removerQualquer (Lista *ldse, Carta cartaRm, bool cartasIguais(Carta a, Carta b)) {

  if (Listavazia(ldse)) {
    return 0;

  }else if (cartasIguais((*ldse)->dados, cartaRm)) {

    Elemento *aux = *ldse;
    *ldse = (*ldse)->prox;
    free(aux);

  }else {

    Elemento *aux, *ant;
    aux = *ldse;
    while(aux && !cartasIguais(aux->dados, cartaRm)) {
      ant = aux;
      aux = aux->prox;
    }

    if(aux == NULL) return 0;

    ant->prox = aux->prox;
    free(aux);
  }

  return 1;
}


int acessarIndice (Lista *ldse, int pos, Carta *ptCarta) {

  if (Listavazia(ldse)) {
    return 0;
  }else if (pos < 0) {
    return 0;
  }else {
    Elemento *aux = *ldse;
    int cont = 0;
    while(aux && cont != pos) {
      aux = aux->prox;
      cont++;
    }

    if (aux != NULL) {
      *ptCarta = aux->dados;
    }
  }

  return 1;
}


int quantidade (Lista *ldse) {
  Elemento *aux = *ldse;
  int cont = 0;
  while(aux) {
    cont++;
    aux = aux->prox;
  }
  return cont;
}


int somarValores (Lista *ldse) {
  Elemento *aux = *ldse;
  int total = 0;
  while(aux) {
    total += aux->dados.numero;
    aux = aux->prox;
  }
  return total;
}


void mostrarLista (Lista *ldse) {
  if(ldse == NULL) return;
  if((*ldse) == NULL) return;

  Elemento *aux = (*ldse);
  while(aux) {
    printf("[%-2d %c] -> ", aux->dados.numero, aux->dados.naipe);
    aux = aux->prox;
  }
}


int buscar (Lista *lst, Carta *carta, bool cmp(Carta a, Carta b)) {

  if(lst == NULL)  return 0;
  if(*lst == NULL) return 0;

  Elemento *aux = *lst;

  bool encontrei;
  do {
    encontrei = cmp(aux->dados, *carta);
    if(encontrei){
      *carta = aux->dados;
    }else {
      aux = aux->prox;
    }

  }while (aux && !encontrei);

  return 1;
}


void pegaDesprotegida (Lista* mao, Lista* mesa, Carta carta) {

  Elemento *aux = *mesa, *final = NULL;
  Lista* mesaDesprotegida = criarLista();
  int total = carta.numero;

  while (total-- >= 0 && aux) {
    final = aux;
    aux = aux->prox;
  }

  int ret;
  Carta cartaAux;
  do {
    cartaAux = carta;
    buscar(&aux, &cartaAux, parcialmenteIguais);
    ret = removerQualquer(&aux, carta, parcialmenteIguais);
    if(ret == 1) {
      inserirInicio(mao, cartaAux);
    }
  }while(ret == 1);

  if(final != NULL)
    final->prox = aux;

}

