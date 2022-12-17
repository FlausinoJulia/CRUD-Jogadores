#include "jogador.h"
#include <string.h>

using namespace std;

void Jogador::setId(int id) {
  if (id < 0)
    throw 1; // erro - id inválido

  this->dados.id = id;
}

int Jogador::getId() { return this->dados.id; }

void Jogador::setIdade(int idade) {
  if (idade < 18 || idade > 60)
    throw 1; // erro - idade invalida

  this->dados.idade = idade;
}

int Jogador::getIdade() { return this->dados.idade; }

void Jogador::setNumero(int numero) {
  if (numero < 1 || numero > 23)
    throw 1; // erro - numero invalido

  this->dados.numero = numero;
}

int Jogador::getNumero() { return this->dados.numero; }

void Jogador::setNomeCompleto(string nomeCompleto) {
  if (nomeCompleto.length() > 51 || nomeCompleto.empty())
    throw 1;

  strcpy(this->dados.nomeCompleto, nomeCompleto.c_str());
}

string Jogador::getNomeCompleto() {
  string texto = this->dados.nomeCompleto;
  return texto;
}

void Jogador::setNomeCamiseta(string nomeCamiseta) {
  if (nomeCamiseta.length() > 21 || nomeCamiseta.empty())
    throw 1;

  strcpy(this->dados.nomeCamiseta, nomeCamiseta.c_str());
}

string Jogador::getNomeCamiseta() {
  string texto = this->dados.nomeCamiseta;
  return texto;
}

void Jogador::setPais(string pais) {
  if (pais.length() > 31 || pais.empty())
    throw 1;

  strcpy(this->dados.pais, pais.c_str());
}

string Jogador::getPais() {
  string texto = this->dados.pais;
  return texto;
}

void Jogador::setTime(string time) {
  if (time.length() > 31 || time.empty())
    throw 1;

  strcpy(this->dados.time, time.c_str());
}

string Jogador::getTime() {
  string texto = this->dados.time;
  return texto;
}

void Jogador::setPosicao(string posicao) {
  if (posicao.length() > 31 || posicao.empty())
    throw 1;

  strcpy(this->dados.posicao, posicao.c_str());
}

string Jogador::getPosicao() {
  string texto = this->dados.posicao;
  return texto;
}

void Jogador::criar(int id, string nomeCompleto, int idade, string nomeCamiseta,
                    int numero, string pais, string time, string posicao) {
  try {
    setId(id);
    setNomeCompleto(nomeCompleto);
    setIdade(idade);
    setNomeCamiseta(nomeCamiseta);
    setNumero(numero);
    setPais(pais);
    setTime(time);
    setPosicao(posicao);
  } catch (int erro) {
    throw erro;
  }
}

/*
// podia ser substituido por operator <<
void Jogador::exibir() {
  cout << "\nID..............: " << this->dados.id << endl;
  cout << "Nome completo...: " << this->dados.nomeCompleto << endl;
  cout << "Nome na camiseta: " << this->dados.nomeCamiseta << endl;
  cout << "Numero..........: " << this->dados.numero << endl;
  cout << "Idade...........: " << this->dados.idade << endl;
  cout << "Pais............: " << this->dados.pais << endl;
  cout << "Time............: " << this->dados.time << endl;
  cout << "Posicao.........: " << this->dados.posicao << endl;
}
*/

ostream& operator << (ostream& os, const Jogador& jog)
{ 
  os << "\nID..............: " << jog.dados.id << endl;
  os << "Nome completo...: " << jog.dados.nomeCompleto << endl;
  os << "Nome na camiseta: " << jog.dados.nomeCamiseta << endl;
  os << "Numero..........: " << jog.dados.numero << endl;
  os << "Idade...........: " << jog.dados.idade << endl;
  os << "Pais............: " << jog.dados.pais << endl;
  os << "Time............: " << jog.dados.time << endl;
  os << "Posicao.........: " << jog.dados.posicao << endl;
  return os;
}