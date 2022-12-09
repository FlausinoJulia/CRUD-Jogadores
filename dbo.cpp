#include "Dbo.h"

// implementação da classe do dbo
Dbo::Dbo(){}

Dbo::~Dbo(){}

// construtor overload
Dbo::Dbo(char nomeCompleto, char nomeCamiseta, char pais, char time,
char posicao, unsigned int id, unsigned int idade, unsigned int numero) {
  this->nomeCompleto = nomeCompleto;
  this->nomeCamiseta = nomeCamiseta;
  this->pais         = pais;
  this->time         = time;
  this->posicao      = posicao;
  this->id           = id;
  this->idade        = idade;
  this->numero       = numero;
}

// getters e setters
char Dbo::getNomeCompleto()  { return this->nomeCompleto; }

char Dbo::getNomeCamiseta()  { return this->nomeCamiseta; }

char Dbo::getPais()          { return this->pais;         }

char Dbo::getTime()          { return this->time;         }

char Dbo::getPosicao()       { return this->posicao;      }

unsigned int Dbo::getId()    { return this->id;           }

unsigned int Dbo::getIdade() { return this->idade;        }

unsigned int Dbo::getNumero(){ return this->numero;       }


void Dbo::setNomeCompleto(char nomeCompleto) { this->nomeCompleto = nomeCompleto; }

void Dbo::setNomeCamiseta(char nomeCamiseta) { this->nomeCamiseta = nomeCamiseta; }

void Dbo::setPais(char pais)                 { this->pais         = pais;         }

void Dbo::setTime(char time)                 { this->time         = time;         }

void Dbo::setPosicao(char posicao)           { this->posicao      = posicao;      }

void Dbo::setId(unsigned int id)             { this->id           = id;           }

void Dbo::setIdade(unsigned int idade)       { this->idade        = idade;        }

void Dbo::setNumero(unsigned int numero)     { this->numero       = numero;       }


