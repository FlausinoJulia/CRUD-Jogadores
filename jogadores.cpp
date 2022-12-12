#include "jogadores.h"
#include <iostream>    // biblioteca para mexer com streams de entrada e saída
#include <fstream>     // biblioteca para mexer com arquivos
#include <stdio.h>     // para remover e alterar o nome dos arquivos
using namespace std;

bool Jogadores::arquivoEstaVazio(ifstream& arquivo)
{
    arquivo.seekg(0); // ponteiro de leitura no inicio do arq.
    return arquivo.peek() == ifstream::traits_type::eof();
}

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
        cerr << "\nNao foi possível abrir o arquivo! ";
        return false;
    }
}

bool Jogadores::excluir(int id)
{
    ifstream arquivo;
    ofstream arquivoNovo;

    arquivo.open("jogadores.dat", ios::binary);
    arquivoNovo.open("nomeTemp.dat", ios::binary | ios::app);

    if (arquivo.is_open() && arquivoNovo.is_open())
    {
        Jogador jog;
        while (arquivo.read((char*) &jog, sizeof(jog)))
        {
            if (jog.id != id)
            {
                arquivoNovo.write((char*) &jog, sizeof(jog));
            }
        }
        arquivo.close();
        arquivoNovo.close();

        remove("jogadores.dat");
        rename("nomeTemp.dat", "jogadores.dat");
        return true;
    }
    else
    {
        cout << "\nNao foi possivel abrir o arquivo! ";
        return false;
    }    
}

bool Jogadores::atualizar(Jogador jogAtualizado, int idProcurado)
{
    fstream arquivo;
    arquivo.open("jogadores.dat", ios::binary | ios::in | ios::out);

    if (arquivo.is_open())
    {
        arquivo.seekg(0); // posicionando o ponteiro de leitura no inicio do arq.

        bool achou = false;
        int pos;
        Jogador jogProcurado;

        while (!arquivo.eof()) // enquanto nao for o fim do arquivo
        {
            // guardamos a posicao atual de leitura
            pos = arquivo.tellg(); 
            // lemos o proximo jogador
            arquivo.read((char*)&jogProcurado, sizeof(jogProcurado));
            if (jogProcurado.id == idProcurado)
            {
                arquivo.seekp(pos); // voltamos para o incio do registro
                // escrevendo os dados atualizados
                arquivo.write((char*)&jogAtualizado, sizeof(jogAtualizado));  
                return true;              
            }
        }

        arquivo.close();
    }
    else
    {
        cerr << "\nNao foi possível abrir o arquivo! ";
        return false;
    }

    return false;
}

Jogador Jogadores::buscarJogador(int idProcurado)
{
    Jogador jog;
    ifstream arquivo;
    arquivo.open("jogadores.dat", ios::binary);

    if (arquivo.is_open())
    {
        if (arquivoEstaVazio(arquivo))
        {
            cout << "Nenhum jogador foi cadastrado. " << endl;
            return jog;
        }
        else
        {
            while (arquivo.read((char*)&jog, sizeof(jog)))
            {
                if (jog.id == idProcurado)
                    break; // encontramos o jogador
            }
        }
    }
    else
    {
        cerr << "\nNao foi possivel abrir o arquivo! " ;
    }    
    
    return jog;
}

bool Jogadores::existeJogador(int idProcurado)
{
    ifstream arquivo;
    arquivo.open("jogadores.dat", ios::binary);

    if (arquivo.is_open())
    {
        if (arquivoEstaVazio(arquivo))
        {
            cout << "Nenhum jogador foi cadastrado. " << endl;
            return false;
        }
        else
        {
            Jogador jog;
            while (arquivo.read((char*)&jog, sizeof(jog)))
            {
                if (jog.id == idProcurado)
                    return true;
            }
        }
        
    }
    else
    {
        cerr << "\nNao foi possivel abrir o arquivo! " ;
    }    
    
    return false;
}

void Jogadores::exibirJogadores()
{
    ifstream arquivo;
    arquivo.open("jogadores.dat", ios::binary);

    if (arquivo.is_open())
    {
        if (arquivoEstaVazio(arquivo))
        {
            cout << "Nenhum jogador foi cadastrado. " << endl;
        }
        else
        {
            Jogador jog;
            int cont = 0;
            cout << "\nJOGADORES" << endl;
            while (arquivo.read((char*)&jog, sizeof(jog)))
            {
                jog.exibir();
            }
        }

        arquivo.close();
    }
    else
    {
        cerr << "\nNao foi possivel abrir o arquivo! " << endl;
    }
}