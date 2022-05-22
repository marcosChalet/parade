#include "lista.h"
#include "pilha.h"

int preencheBaralho (Pilha* baralho) {

  int num = 0;
  char cor = 65;
  Carta carta;

  for (int i = 0; i < 66; i++) {
    carta.numero = num++;
    carta.naipe  = cor;
    inserirPilha(baralho, carta);
    
    if ((i+1) % 11 == 0) {
      num = 0;
      cor++;
    }
  }

  embaralharPilha(baralho);
  return 1;
}


int preencheMao (Lista* mao, Pilha *baralho) {
  Carta carta;
  for (int i = 0; i < QTD_MAO; i++) {
    removerPilha(baralho, &carta);
    inserirInicio(mao, carta);
  }
  return 1;
}


int preencheMesa (Lista* mesa, Pilha *baralho) {
  Carta carta;
  for (int i = 0; i < QTD_MAO; i++) {
    removerPilha(baralho, &carta);
    inserirInicio(mesa, carta);
  }
  return 1;
}


void mostrarTurno (Lista *mao, Lista *mesa, Lista **colJog, int qtdPilha) {

  // system("clear||cls");
  printf("[NOVA CARTA] -> ");
  mostrarLista(mesa);
  printf("|| Baralho (%d cartas)\n", qtdPilha);
  puts("\n");

/*  printf("%-17s", " ");
  for(int i = 0; i < MAX_CARTAS-5 - qtdPilha; i++) {
    printf("(%d)%-7s", i+1, " ");
  }
  puts("\n");*/

  printf("Coleção: \n");
  for (int i = 0; i < 6; i++) {
    printf("%c -> ", i+'A');
    if (colJog[i] == NULL || *colJog[i] == NULL) {
      printf("Vazio\n");
    } else {
      mostrarLista(colJog[i]);
    }
  }
  puts("\n");

  int totalMao = quantidade(mao);
  printf("[Mão] -> ");
  mostrarLista(mao);
  printf("||\n");
  printf("%-10s", " ");
  for(int i = 0; i < totalMao; i++) {
    printf("(%d)%-7s", i+1, " ");
  }
  puts("\n\n");

}


void criaEstruturas (Lista** mao, Lista** mesa, Pilha** baralho) {
  *baralho = criarPilha();
  *mao     = criarLista();
  *mesa    = criarLista();
}


void criaPtEstruturas (Lista ***colecoes) {
  colecoes[JOGADOR] = (Lista**)malloc(sizeof(Lista*)*6);
  colecoes[MAQUINA] = (Lista**)malloc(sizeof(Lista*)*6);

  for(int i = 0; i < 6; i++) {
    colecoes[JOGADOR][i] = NULL;
    colecoes[MAQUINA][i] = NULL;
    colecoes[JOGADOR][i] = criarLista();
    colecoes[MAQUINA][i] = criarLista();
  }
}


void jogadaPlayer(Lista* mao, Lista* mesa, Lista** colJog, Pilha* baralho) {

  Carta carta;
  int jogada;
  printf("Escolha qual a carta da sua mão será a NOVA CARTA...\n-> ");
  scanf("%d", &jogada);

  acessarIndice(mao, jogada-1, &carta);
  inserirInicio(mesa, carta);
  removerQualquer(mao, carta, exatamenteIguais);
  pegaDesprotegida(mao, mesa, carta);
  
  // Compra uma carta
  removerPilha(baralho, &carta);
  inserirInicio(mesa, carta);
}

int main (int argc, char *argv[]) {

  srand(time(NULL));
  Pilha *baralho = NULL;
  Lista *mao = NULL, *mesa = NULL;
  Lista **colecoes[QTD_JOGADORES];

  /* Validar alocação de memória! */
  // colecoes[JOGADOR] = (Lista**)malloc(sizeof(Lista*)*6);
  // colecoes[MAQUINA] = (Lista**)malloc(sizeof(Lista*)*6);

  // baralho = criarPilha();
  // mao     = criarLista();
  // mesa    = criarLista();
  criaEstruturas(&mao, &mesa, &baralho);
  criaPtEstruturas(colecoes);
  /*for(int i = 0; i < 6; i++) {
    colecoes[JOGADOR][i] = NULL;
    colecoes[MAQUINA][i] = NULL;
    colecoes[JOGADOR][i] = criarLista();
    colecoes[MAQUINA][i] = criarLista();
  }*/

  preencheBaralho(baralho);
  preencheMao(mao, baralho);
  preencheMesa(mesa, baralho);

  while (true) {
    mostrarTurno(mao, mesa, colecoes[JOGADOR], tamanhoPilha(baralho));
    jogadaPlayer(mao, mesa, colecoes[JOGADOR], baralho);
    mostrarTurno(mao, mesa, colecoes[JOGADOR], tamanhoPilha(baralho));
    // jogadaMaquina();
    break;
  }

  // mostrarLista(mao);
  // mostrarLista(mesa);

  return 0;
}
