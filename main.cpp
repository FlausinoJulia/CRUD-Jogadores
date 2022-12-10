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

int main ()
{
    Jogadores jogadores;
    char opcao;
    

    while (opcao != 'S')
    {
        cout << "Selecione a opção desejada:" << endl;
        cout << "1 - Cadastrar jogador" << endl; 
        cout << "S - Sair " << endl; 
        cin >> opcao;

        switch (opcao)
        {
            case '1':
            {
                unsigned int id;
                string nomeCompleto, nomeCamisa, pais, time, posicao;
                unsigned char idade, numero;

                cout << "\nID: ";
                cin >> id;
                cout << "\nNome completo: ";
                cin >> nomeCompleto;
                cout << "\nIdade: ";
                cin >> idade;
                cout << "\nNome na camiseta: ";
                cin >> nomeCamisa;
                cout << "\nNumero na camiseta: ";
                cin >> numero;
                cout << "\nPais: ";
                cin >> pais;
                cout << "\nTime: ";
                cin >> time;
                cout << "\nPosicao: ";
                cin >> posicao;

                Jogador jog = {id, nomeCompleto, idade, nomeCamisa, numero, pais, time, posicao};
                jogadores.incluir(jog);

                break;
            }
            case 'S':
            {
                break;
            }
        }                      
    }
    
    return 0;
}