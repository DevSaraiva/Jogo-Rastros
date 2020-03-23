

#include <stdio.h>
#include "camada_de_dados.h"
#include <math.h>
#include <stdlib.h>
int casa_val (COORDENADA c){
    int coluna = c.coluna;
    int linha = c.linha;
    if ((linha >= 0)&& (linha < 8) && (coluna >= 0) &&(coluna <8))
    return 1;
    else return 0;   
    
}

int jogada_presa (ESTADO *e,COORDENADA c){
    int c_ult = c.coluna;
    int l_ult = c.linha;
    CASA p = PRETA;
    COORDENADA x1 = {c_ult+1,l_ult};
    COORDENADA x2 = {c_ult-1,l_ult};
    COORDENADA y1 = {c_ult,l_ult+1};
    COORDENADA y2 = {c_ult,l_ult-1};
    COORDENADA z1 = {c_ult+1,l_ult+1};
    COORDENADA z2 = {c_ult+1,l_ult-1};
    COORDENADA z3 = {c_ult-1,l_ult+1};
    COORDENADA z4 = {c_ult-1,l_ult-1};
    COORDENADA ar [8] = {x1, x2, y1, y2, z1,z2,z3,z4};
    
    CASA arr [8]; 
    
    for (int i = 0; i<8; i++){
        if (casa_val (ar[i]) && obter_estado_casa(e,ar [i]) == VAZIO)
            return 0;
    }

    return 1;
}



int casa_vencedora (ESTADO *e,COORDENADA c){
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    if ((c_coluna == 0 && c_linha == 0) || (c_coluna == 7 && c_linha == 7)) return 1;
    else return 0;
}




int jogada_e_valida (ESTADO *estado,COORDENADA c){
    int c_ult = obter_ultima_jogada(estado).coluna;
    int l_ult = obter_ultima_jogada(estado).linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    CASA x = VAZIO;
    int dif_coluna = abs(c_coluna - c_ult);
    int dif_linha = abs(l_ult - c_linha);
    if (dif_coluna <= 1 &&  dif_linha <= 1 && ((obter_estado_casa(estado,c)) == x)) 
        return 1;
    else return 0;
}




int jogar (ESTADO *estado, COORDENADA c){
    int c_ult = obter_ultima_jogada(estado).coluna;
    int l_ult = obter_ultima_jogada(estado).linha;
    int c_coluna = c.coluna;
    int c_linha = c.linha;
    int j_atual = obter_jogador_atual (estado);
    printf("jogar %d %d\n", c.coluna, c.linha);
   
    if (jogada_e_valida(estado,c)){
        // Atualiza o tabuleiro
        
        estado -> tab [c.linha] [c.coluna] = BRANCA;
        estado -> tab [l_ult] [c_ult] = PRETA;
        
        // Muda de jogador e guarda a jogadas
        
        if ((j_atual == 1) && c_coluna != 0 && c_linha != 0) estado -> jogador_atual = 2;
        if ((j_atual == 2) && c_coluna != 7 && c_linha != 7) {
            estado -> jogador_atual = 1;
            COORDENADA j1 = {c_ult,l_ult};
            COORDENADA j2 = {c.coluna, c.linha};
            JOGADA j = {j1,j2};
            int i = 0;
            estado -> jogadas [i] = j;
            i++;
        }

        // Atualiza a última jogada
        estado -> ultima_jogada.coluna = c.coluna;
        estado -> ultima_jogada.linha = c.linha;
        
    }    
    else printf("Jogada inválida\n");
 
    // Aumenta número de jogadas
    if (j_atual == 2) 
        estado -> num_jogadas++;

   
    
}


