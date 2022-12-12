#ifndef JOGADORES
#define JOGADORES

#include "jogador.h"

class Jogadores
{
    private:
        bool arquivoEstaVazio(std::ifstream&); // função auxiliar da buscaJogador
    public: 
        bool incluir(Jogador);        // incluir um jogador no arquivo
        bool excluir(int);            // excluir um jogador do arquivo
        bool atualizar(Jogador, int); // atualizar as infos de um jogador
        Jogador buscarJogador(int);   // buscar um jogador no arquivo e retorna suas informacoes
        bool existeJogador(int);      // busca o jogador e retorna se existe ou nao
        void exibirJogadores();       // exibe todos os jogadores
};

#endif