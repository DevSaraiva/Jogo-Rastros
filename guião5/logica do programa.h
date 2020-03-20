/**
@file logicadoprograma.h
Definição das funções da componente lógica do jogo
*/




#ifndef _GUIAO5_LOGICA_DO_PROGRAMA_H
#define _GUIAO5_LOGICA_DO_PROGRAMA_H
#include "camada de dados.h"

int casa_vencedora (ESTADO *e,COORDENADA c);
int jogada_e_valida (ESTADO *estado, COORDENADA c);
int jogar(ESTADO *estado, COORDENADA c);



#endif //_GUIAO5_LOGICA_DO_PROGRAMA_H
