#ifndef JOGADOR
#define JOGADOR

#include <iostream>

struct Jogador {
private:
  int id;
  char nomeCompleto[51];
  int idade;
  char nomeCamiseta[21];
  int numero;
  char pais[31];
  char time[31];
  char posicao[21];

public:
  void setId(int);
  int getId();

  void setIdade(int);
  int getIdade();

  void setNumero(int);
  int getNumero();

  void setNomeCompleto(std::string);
  std::string getNomeCompleto();

  void setNomeCamiseta(std::string);
  std::string getNomeCamiseta();

  void setPais(std::string);
  std::string getPais();

  void setTime(std::string);
  std::string getTime();

  void setPosicao(std::string);
  std::string getPosicao();

  void criar(int id, char[51], int, char[21], int, char[31], char[31], char[21]);

  void exibir();
};

#endif