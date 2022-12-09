#ifndef JOGADORES
#define JOGADORES

#include "jogador.h"

class Jogadores
{
    public:
        bool incluir(Jogador);
        bool excluir(int id);
        bool atualizar(Jogador);
        Jogador buscarJogador(int id);
};

#endif