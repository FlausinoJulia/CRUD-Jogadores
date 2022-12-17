#ifndef JOGADOR
#define JOGADOR

#include <iostream>

class Jogador {
private:
  struct Dados
  {
    int id;
    char nomeCompleto[51];
    int idade;
    char nomeCamiseta[21];
    int numero;
    char pais[31];
    char time[31];
    char posicao[21];
  } dados;
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

  void criar(int, std::string, int, std::string, int, std::string, std::string,
             std::string);

  // void exibir();

  // friend para acessar os dados privados do jogador
  friend std::ostream& operator << (std::ostream&, const Jogador&);
};

#endif