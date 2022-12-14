#include "jogadores.h"
#include <fstream>  // biblioteca para mexer com arquivos
#include <iostream> // biblioteca para mexer com streams de entrada e saída
#include <stdio.h>  // para remover e alterar o nome dos arquivos
using namespace std;

bool Jogadores::arquivoEstaVazio(ifstream &arquivo) {
  arquivo.seekg(0); // ponteiro de leitura no inicio do arq.
  return arquivo.peek() == ifstream::traits_type::eof();
}

void Jogadores::incluir(Jogador jog) {
  // criando um arquivo para a escrita
  ofstream arquivo;
  // abrindo o arquivo binario e colocando o ponteiro de escrita no final
  arquivo.open("jogadores.dat", ios::binary | ios::app);

  if (arquivo.is_open()) // se o arquivo está realmente aberto
  {
    // escrevemos o jogador no arquivo
    arquivo.write((char *)&jog, sizeof(jog));
    arquivo.close(); // fechamos o arquivo
  } else // não foi possível incluir o jogador
  {
    throw 1; // nao foi possivel abrir o arquivo
  }
}

void Jogadores::excluir(int id) {
  ifstream arquivo;
  ofstream arquivoNovo;

  arquivo.open("jogadores.dat", ios::binary);
  arquivoNovo.open("nomeTemp.dat", ios::binary | ios::app);

  if (arquivo.is_open() && arquivoNovo.is_open()) {
    Jogador jog;

    if (arquivoEstaVazio(arquivo)) {
      throw 2; // nao ha nenhum jogador para excluir
    }
    else
    {
      while (arquivo.read((char *)&jog, sizeof(jog))) {
        if (jog.getId() != id) {
        arquivoNovo.write((char *)&jog, sizeof(jog));
        }
      }
      arquivo.close();
      arquivoNovo.close();
    
      remove("jogadores.dat");
      rename("nomeTemp.dat", "jogadores.dat");
    }
  } else {
    throw 1; // nao foi possivel abrir o arquivo
  }
}

void Jogadores::atualizar(Jogador jogAtualizado, int idProcurado) {
  fstream arquivo;
  arquivo.open("jogadores.dat", ios::binary | ios::in | ios::out);

  if (arquivo.is_open()) {
    arquivo.seekg(0); // posicionando o ponteiro de leitura no inicio do arq.

    bool achou = false;
    int pos;
    Jogador jogProcurado;

    while (!arquivo.eof()) // enquanto nao for o fim do arquivo
    {
      // guardamos a posicao atual de leitura
      pos = arquivo.tellg();
      // lemos o proximo jogador
      arquivo.read((char *)&jogProcurado, sizeof(jogProcurado));
      if (jogProcurado.getId() == idProcurado) {
        arquivo.seekp(pos); // voltamos para o incio do registro
        // escrevendo os dados atualizados
        arquivo.write((char *)&jogAtualizado, sizeof(jogAtualizado));
      }
    }

    arquivo.close();
  } else {
    throw 1; // nao foi possivel abrir o arquivo
  }
}

Jogador Jogadores::buscarJogador(int idProcurado) {
  Jogador jog;
  ifstream arquivo;
  arquivo.open("jogadores.dat", ios::binary);

  if (arquivo.is_open()) {
    if (arquivoEstaVazio(arquivo)) {
      throw 2; // arquivo vazio
    } else {
      while (arquivo.read((char *)&jog, sizeof(jog))) {
        if (jog.getId() == idProcurado)
          return jog; // encontramos o jogador
      }
      throw 3; // jogador procurado nao existe
    }
  } else {
    throw 1; // nao foi possivel abrir o arquivo
  }
}

bool Jogadores::existeJogador(int idProcurado) {
  ifstream arquivo;
  arquivo.open("jogadores.dat", ios::binary);

  if (arquivo.is_open()) {
    if (arquivoEstaVazio(arquivo)) {
      return false;
    } else {
      Jogador jog;
      while (arquivo.read((char *)&jog, sizeof(jog))) {
        if (jog.getId() == idProcurado)
          return true;
      }
    }

  } else {
    return false; // nenhum jogador foi cadastrado
  }

  return false;
}

void Jogadores::exibirJogadores() {
  ifstream arquivo;
  arquivo.open("jogadores.dat", ios::binary);

  if (arquivo.is_open()) {
    if (arquivoEstaVazio(arquivo)) {
      cout << "\nNenhum jogador cadastrado. " << endl;
    } else {
      Jogador jog;
      int cont = 0;
      cout << "\nJOGADORES" << endl;
      while (arquivo.read((char *)&jog, sizeof(jog))) {
        jog.exibir();
      }
    }

    arquivo.close();
  } else {
    cerr << "\nNao foi possivel abrir o arquivo! " << endl;
  }
}