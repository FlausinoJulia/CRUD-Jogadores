#ifndef JOGADORES
#define JOGADORES

#include <iostream>
#include <fstream>
#include <string>
#include "jogador.h"

class Jogadores
{
    public:
        bool incluir(Jogador);               // incluir um jogador no arquivo
        bool excluir(unsigned int);          // excluir um jogador do arquivo
        bool atualizar(Jogador);             // atualizar as infos de um jogador
        Jogador buscarJogador(unsigned int); // buscar um jogador no arquivo
};

#endif