#include "jogador.h"
#include <string.h>

using namespace std;

void Jogador::setId(int id) {
  if (id < 0)
    throw 1; // erro - id inválido

  this->id = id;
}

int Jogador::getId() { return this->id; }

void Jogador::setIdade(int idade) {
  if (idade < 18 || idade > 60)
    throw 1; // erro - idade invalida

  this->idade = idade;
}

int Jogador::getIdade() { return this->idade; }

void Jogador::setNumero(int numero) { this->numero = numero; }

int Jogador::getNumero() { return this->numero; }

void Jogador::setNomeCompleto(string nomeCompleto) {
  if (nomeCompleto.length() > 51)
    throw 1;

  strcpy(this->nomeCompleto, nomeCompleto.c_str());
}

string Jogador::getNomeCompleto() {
  string texto = this->nomeCompleto;
  return texto;
}

void Jogador::setNomeCamiseta(string nomeCamiseta) {
  if (nomeCamiseta.length() > 21)
    throw 1;

  strcpy(this->nomeCamiseta, nomeCamiseta.c_str());
}

string Jogador::getNomeCamiseta() {
  string texto = this->nomeCamiseta;
  return texto;
}

void Jogador::setPais(string pais) {
  if (pais.length() > 31)
    throw 1;

  strcpy(this->pais, pais.c_str());
}
string Jogador::getPais() {
  string texto = this->pais;
  return texto;
}

void Jogador::setTime(string time) {
  if (time.length() > 31)
    throw 1;

  strcpy(this->pais, time.c_str());
}

string Jogador::getTime() {
  string texto = this->time;
  return texto;
}

void Jogador::setPosicao(string posicao) {
  if (posicao.length() > 31)
    throw 1;

  strcpy(this->pais, posicao.c_str());
}

string Jogador::getPosicao() {
  string texto = this->posicao;
  return texto;
}

void Jogador::criar(int id, string nomeCompleto, int idade, string nomeCamiseta, int numero, 
          string pais, string time,  string posicao)
{
  try 
  {
    setId(id);
    setNomeCompleto(nomeCompleto);
    setIdade(idade);
    setNomeCamiseta(nomeCamiseta);
    setNumero(numero);
    setPais(pais);
    setTime(time);
    setPosicao(posicao);
  }
  catch (int erro)
  {
    throw erro;
  }
}

void Jogador::exibir() {
  cout << "\nID..............: " << id << endl;
  cout << "Nome completo...: " << nomeCompleto << endl;
  cout << "Nome na camiseta: " << nomeCamiseta << endl;
  cout << "Numero..........: " << numero << endl;
  cout << "Idade...........: " << idade << endl;
  cout << "Pais............: " << pais << endl;
  cout << "Time............: " << time << endl;
  cout << "Posicao.........: " << posicao << endl;
}