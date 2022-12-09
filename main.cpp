// PROJETO FINAL - INI 44 - TÓPICOS EM POO
// CRUD de jogadores - Copa do Mundo 2022
// Giovanna do Amaral Brigo 21685
// Julia Flausino da Silva  21241

#include <iostream>    // biblioteca para mexer com streams de entrada e saída
#include <fstream>     // biblioteca para mexer com arquivos
#include <string>      // biblioteca para mexer com strings

#include "jogadores.h" // nosso dao
#include "jogador.h"   // nosso dbo

using namespace std;

struct jogador
{
    unsigned int id;
    char[51] nomeCompleto;
    char[31] nomeCamiseta, time;
    char[21] pais, posicao;
    unsigned char idade, numero;
}

int main ()
{
    ofstream ofs("jogadores.dat", ios::binary);

    jogador jog = {0, "Richarlison de Andrade", "Richarlison", "Tottenham", "Brasil", "Atacante", 25, 9};

    return 0;
}