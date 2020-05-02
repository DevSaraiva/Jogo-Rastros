/**
@file bot.h
Definição das funções relacionadas com listas ligadas
*/



#ifndef _BOT_H
#define _BOT_H
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_de_dados.h"
#include "logica_do_programa.h"
#include "camada_da_interface.h"

/**
\brief  Função que cria uma lista com todas as jogadas possiveis
*/

LISTA jogadas_possivel (ESTADO *e,COORDENADA c);


/**
\brief  Função que dadas 1 coordenada calcula a distância euclidiana entre essa e posição onde termina o jogo considerando o jogador atuak
*/

double calcula_dist(COORDENADA * C, int jog);


/**
\brief  Função que aplica a heuristica do vizinho mais proximo e joga automáticamente
*/
COORDENADA joga_euclidiana (ESTADO *e);

/**
\brief  Função que aplica a heuristica aleatoria e joga automáticamente
*/
COORDENADA joga_aleatorio (ESTADO *e);

#endif //_GUIAO5_BOT_H