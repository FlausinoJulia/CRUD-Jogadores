#ifndef JOGADORES
#define JOGADORES

#include <iostream>
#include <fstream>
#include <string>
#include "jogador.h"
using namespace std;

class Jogadores
{
    private:
        string nomeArquivo;
    public:
        Jogadores(string nomeArquivo);
        bool incluir(Jogador);
        bool excluir(int id);
        bool atualizar(Jogador);
        Jogador buscarJogador(int id);
};

#endif