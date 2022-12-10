#include "jogadores.h"
#include "jogador.h"   // nosso dbo
#include <iostream>    // biblioteca para mexer com streams de entrada e saída
#include <fstream>     // biblioteca para mexer com arquivos
using namespace std;


bool Jogadores::incluir(Jogador jog)
{
    // criando um arquivo para a escrita
    ofstream arquivo;
    // abrindo o arquivo binario e colocando o ponteiro de escrita no final
    arquivo.open("jogadores.dat", ios::binary | ios::app);

    if (arquivo.is_open()) // se o arquivo está realmente aberto
    {
        // escrevemos o jogador no arquivo
        arquivo.write((char*) &jog, sizeof(jog));
        arquivo.close(); // fechamos o arquivo
        return true;     // retornamos true
    }
    else // se não foi possível incluir o jogador
    {
        // avisamos o usuário e retornamos false
        cerr << "Não foi possível abrir o arquivo!" << endl;
        return false;
    }
}

bool Jogadores::excluir(unsigned int id)
{
    return false;
}

bool Jogadores::atualizar(Jogador jogador)
{
    return false;
}

Jogador Jogadores::buscarJogador(unsigned int id)
{ 
    Jogador jog;
    return jog;
}