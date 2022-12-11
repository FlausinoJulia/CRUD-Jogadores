// PROJETO FINAL - INI 44 - TÓPICOS EM POO
// CRUD de jogadores - Copa do Mundo 2022
// Giovanna do Amaral Brigo 21685
// Julia Flausino da Silva  21241

#include <iostream>    // biblioteca para mexer com streams de entrada e saída
#include <fstream>     // biblioteca para mexer com arquivos
#include <string.h>      // biblioteca para mexer com strings

#include "jogadores.h" // nosso dao
#include "jogador.h"   // nosso dbo

using namespace std;

int main ()
{
    Jogadores jogadores;
    char opcao;

    while (opcao != 'S')
    {
        cout << "\nSelecione a opcao desejada:" << endl;
        cout << "1 - Cadastrar jogador" << endl; 
        cout << "2 - Exibir todos os jogadores" << endl;
        cout << "S - Sair " << endl; 
        cin >> opcao;

        switch (opcao)
        {
            case '1':
            {
                Jogador jog;
                string nomeCompleto, nomeCamiseta, pais, time, posicao;

                cout << "\nID: ";
                cin >> jog.id;
                cin.ignore();

                cout << "\nNome completo: ";
                getline(cin, nomeCompleto);
                strcpy(jog.nomeCompleto, nomeCompleto.c_str());

                cout << "\nNome na camiseta: ";
                getline(cin, nomeCamiseta);
                strcpy(jog.nomeCamiseta, nomeCamiseta.c_str());

                cout << "\nIdade: ";
                cin >> jog.idade;

                cout << "\nNumero: ";
                cin >> jog.numero;
                cin.ignore();

                cout << "\nPais: ";
                getline(cin, pais);
                strcpy(jog.pais, pais.c_str());

                cout << "\nTime: ";
                getline(cin, time);
                strcpy(jog.time, time.c_str());

                cout << "\nPosicao: ";
                getline(cin, posicao);
                strcpy(jog.posicao, posicao.c_str());
                
                if (jogadores.incluir(jog))
                {
                    cout << "\nJogador incluido com sucesso!"<< endl;
                }
                else
                {
                    cout << "O jogador nao foi cadastrado." << endl;
                }
                break;
            }
            case '2':
            {
                jogadores.exibirJogadores();
            }
            case 'S':
            {
                break;
            }
        }                      
    }
    
    return 0;
}