#include "jogadores.h"
#include <iostream>    // biblioteca para mexer com streams de entrada e saída
#include <fstream>     // biblioteca para mexer com arquivos
using namespace std;

bool Jogadores::incluir(Jogador jog)
{
    // criando um arquivo para a escrita
    ofstream arquivo;
    // abrindo o arquivo binario e colocando o ponteiro de escrita no final
    arquivo.open("jogadores.dat", ios::binary | ios::app);

    cout << "\nID..............: " << jog.id << endl;
    cout << "Nome completo...: " << jog.nomeCompleto << endl;
    cout << "Nome na camiseta: " << jog.nomeCamiseta << endl;
    cout << "Numero..........: " << jog.numero << endl;
    cout << "Idade...........: " << jog.idade << endl;
    cout << "Pais............: " << jog.pais << endl;
    cout << "Time............: " << jog.time << endl;
    cout << "Posicao.........: " << jog.posicao << endl;

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
        cerr << "\nNao foi possível abrir o arquivo! " << endl;
        return false;
    }
}

bool Jogadores::excluir(unsigned int id)
{
    unsigned int idui = id;
    return false;
}

bool Jogadores::atualizar(Jogador jogador)
{
    unsigned int uiui = jogador.id;
    return false;
}

Jogador Jogadores::buscarJogador(unsigned int id)
{ 
    unsigned int idui = id;
    Jogador jog;
    return jog;
}

void Jogadores::exibirJogadores()
{
    ifstream arquivo;
    arquivo.open("jogadores.dat", ios::binary);

    if (arquivo.is_open())
    {
        Jogador jog;
        int cont = 0;
        cout << "\nJOGADORES" << endl;
        while (arquivo.read((char*)&jog, sizeof(jog)))
        {
            cout << "\nID..............: " << jog.id << endl;
            cout << "Nome completo...: " << jog.nomeCompleto << endl;
            cout << "Nome na camiseta: " << jog.nomeCamiseta << endl;
            cout << "Numero..........: " << jog.numero << endl;
            cout << "Idade...........: " << jog.idade << endl;
            cout << "Pais............: " << jog.pais << endl;
            cout << "Time............: " << jog.time << endl;
            cout << "Posicao.........: " << jog.posicao << endl;
            cont++;
        }

        if (cont == 0)
        {
            cout << "\nNenhum jogador foi cadastrado." << endl;
        }
        
        arquivo.close();
    }
    else
    {
        cerr << "\nNao foi possivel abrir o arquivo! " << endl;
    }
}