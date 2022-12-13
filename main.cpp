// PROJETO FINAL - INI 44 - TÓPICOS EM POO
// CRUD de jogadores - Copa do Mundo 2022
// Giovanna do Amaral Brigo 21685
// Julia Flausino da Silva  21241

#include <fstream>  // biblioteca para mexer com arquivos
#include <iostream> // biblioteca para mexer com streams de entrada e saída
#include <string.h> // biblioteca para mexer com strings

#include "jogador.h"   // nosso dbo
#include "jogadores.h" // nosso dao

using namespace std;

bool isnumber(const string &str) {
  return str.find_first_not_of("0123456789") == std::string::npos;
}

int main() {
  Jogadores jogadores;
  string opcao;
  bool erro = false; // para tratar excecoes

  while (opcao[0] != 'S') {
    cout << "\n--------------------" << endl;
    cout << "MENU" << endl;
    cout << "\n1 - Cadastrar jogador" << endl;
    cout << "2 - Exibir todos os jogadores" << endl;
    cout << "3 - Buscar jogador pelo ID" << endl;
    cout << "4 - Atualizar registro de um jogador" << endl;
    cout << "5 - Deletar jogador" << endl;
    cout << "S - Sair " << endl;
    cout << "\nSelecione a opcao desejada: ";
    cin >> opcao;

    if (opcao.length() > 1) {
      cout << "\nOpcao invalida!" << endl;
    } else {
      switch (opcao[0]) {
      case '1': {

        Jogador jog;
        string nomeCompleto, nomeCamiseta, pais, time, posicao;
        string id, idade, numero;

        cout << "\n--------------------" << endl;
        cout << "ADICIONANDO JOGADOR" << endl;

        cin.ignore();
        cout << "\nID..............: ";
        getline(cin, id);

        do {
          if (isnumber(id)) {
            int idDigitado = stoi(id.c_str());
            try {
              jog.setId(idDigitado);
              erro = false;
            } catch (int execao) {
              erro = true;
              cout << "\nID invalido! O ID deve ser um numero inteiro positivo."
                   << endl;
              cout << "Digite um ID diferente: ";
              getline(cin, id);
            }
          } else {
            erro = true;
            cout << "\nID invalido! O ID deve ser um numero inteiro positivo."
                 << endl;
            cout << "Digite um ID diferente: ";
            getline(cin, id);
          }
        } while (erro);

        while (jogadores.existeJogador(jog.getId())) {
          cout << "\nJa existe um jogador com esse ID!" << endl;
          cout << "Digite um ID diferente: ";
          getline(cin, id);

          do {
            if (isnumber(id)) {
              int idDigitado = stol(id);
              try {
                jog.setId(idDigitado);
                erro = false;
              } catch (int execao) {
                erro = true;
                cout << "\nID invalido! O ID deve ser um numero inteiro "
                        "positivo."
                     << endl;
                cout << "Digite um ID diferente: ";
                getline(cin, id);
              }
            } else {
              erro = true;
              cout << "\nID invalido! O ID deve ser um numero inteiro positivo."
                   << endl;
              cout << "Digite um ID diferente: ";
              getline(cin, id);
            }
          } while (erro);
        }

        // cin.ignore(); // ignorando \n do buffer
        do {
          cout << "Nome completo...: ";
          getline(cin, nomeCompleto);
          try {
            jog.setNomeCompleto(nomeCompleto);
            erro = false;
          } catch (int execao) {
            if (execao == 1) {
              erro = true;
              cout << "Nome invalido! O nome deve conter no maximo 50 "
                      "caracteres."
                   << endl;
            }
          }
        } while (erro);

        do {
          cout << "Nome na camiseta: ";
          getline(cin, nomeCamiseta);
          try {
            jog.setNomeCamiseta(nomeCamiseta);
            erro = false;
          } catch (int execao) {
            if (execao == 1) {
              erro = true;
              cout << "Nome invalido! O nome deve conter no maximo 20 "
                      "caracteres."
                   << endl;
            }
          }
        } while (erro);

        cout << "Idade...........: ";
        getline(cin, idade);

        do {
          if (isnumber(idade)) {
            int idadeDigitada = stol(idade);
            try {
              jog.setIdade(idadeDigitada);
              erro = false;
            } catch (int execao) {
              erro = true;
              cout << "\nIdade invalida! A idade deve estar entre 18 e 60 anos."
                   << endl;
              cout << "Digite um idade diferente: ";
              getline(cin, idade);
            }
          } else {
            erro = true;
            cout
                << "\nIdade invalida! A idade deve ser um numero entre 18 e 60."
                << endl;
            cout << "Digite uma idade diferente: ";
            getline(cin, idade);
          }
        } while (erro);

        cout << "Numero..........: ";
        getline(cin, numero);
        // cin.ignore();

        do {
          if (isnumber(numero)) {
            int numeroDigitado = stol(numero);
            try {
              jog.setNumero(numeroDigitado);
              erro = false;
            } catch (int execao) {
              erro = true;
              cout << "\nNumero invalido! O numero deve estar entre 1 e 23."
                   << endl;
              cout << "Digite um numero diferente: ";
              getline(cin, numero);
            }
          } else {
            erro = true;
            cout << "\nNumero invalido! O numero deve estar entre 1 e 23."
                 << endl;
            cout << "Digite um numero diferente: ";
            getline(cin, numero);
          }
        } while (erro);

        do {
          cout << "Pais............: ";
          getline(cin, pais);
          try {
            jog.setPais(pais);
            erro = false;
          } catch (int execao) {
            if (execao == 1) {
              erro = true;
              cout << "Pais invalido! O pais deve conter no maximo 30 "
                      "caracteres."
                   << endl;
            }
          }
        } while (erro);

        /*
        cout << "Time............: ";
        getline(cin, time);
        // jog.time recebe uma copia da string lida no padrão de c++
        strcpy(jog.time, time.c_str());*/

        do {
          cout << "Time............: ";
          getline(cin, time);
          try {
            jog.setTime(time);
            erro = false;
          } catch (int execao) {
            if (execao == 1) {
              erro = true;
              cout << "Time invalido! O time deve conter no maximo 30 "
                      "caracteres."
                   << endl;
            }
          }
        } while (erro);

        do {
          cout << "Posicao.........: ";
          getline(cin, posicao);
          try {
            jog.setPosicao(posicao);
            erro = false;
          } catch (int execao) {
            if (execao == 1) {
              erro = true;
              cout << "Posicao invalida! Deve conter no maximo 20 "
                      "caracteres."
                   << endl;
            }
          }
        } while (erro);

        if (jogadores.incluir(jog)) {
          cout << "\nJogador incluido com sucesso!" << endl;
        } else {
          cout << "O jogador nao foi cadastrado." << endl;
        }
        break;
      }
      case '2': {
        cout << "\n--------------------" << endl;
        cout << "EXIBINDO JOGADORES" << endl;
        jogadores.exibirJogadores();
        break;
      }
      case '3': {
        string idProcurado;

        cout << "\n--------------------" << endl;
        cout << "BUSCANDO JOGADOR" << endl;

        cin.ignore();
        cout << "\nDigite o ID do jogador: ";
        getline(cin, idProcurado);

        do {
          if (isnumber(idProcurado)) {
            int idDigitado = stol(idProcurado);

            if (idDigitado < 0) // id invalido
            {
              erro = true;
              cout << "ID invalido! O ID deve ser um numero inteiro positivo."
                   << endl;
              cout << "Digite um ID diferente: ";
              getline(cin, idProcurado);
            } else // o usuario digitou um numero valido
            {
              erro = false;
            }
          } else // o usuario nao digitou um numero
          {
            erro = true;
            cout << "ID invalido! O ID deve ser um numero inteiro positivo."
                 << endl;
            cout << "Digite um ID diferente: ";
            getline(cin, idProcurado);
          }
        } while (erro);

        int id = stol(idProcurado);
        Jogador jog;
        jog = jogadores.buscarJogador(id);

        if (jog.getId() == id) {
          cout << "\nO jogador foi encontrado!" << endl;
          jog.exibir();
        } else {
          cout << "Jogador nao existe. " << endl;
        }

        break;
      }
      case '4': {
        string idProcurado;

        cout << "\n--------------------" << endl;
        cout << "ATUALIZANDO JOGADOR" << endl;

        cin.ignore();
        cout << "\nDigite o ID do jogador: ";
        getline(cin, idProcurado);

        do {
          if (isnumber(idProcurado)) {
            int idDigitado = stoi(idProcurado);

            if (idDigitado < 0) // id invalido
            {
              erro = true;
              cout << "ID invalido! O ID deve ser um numero inteiro positivo."
                   << endl;
              cout << "Digite um ID diferente: ";
              getline(cin, idProcurado);
            } else // o usuario digitou um numero valido
            {
              erro = false;
            }
          } else // o usuario nao digitou um numero
          {
            erro = true;
            cout << "ID invalido! O ID deve ser um numero inteiro positivo."
                 << endl;
            cout << "Digite um ID diferente: ";
            getline(cin, idProcurado);
          }
        } while (erro);

        int id = stoi(idProcurado);
        Jogador jogDesatualizado = jogadores.buscarJogador(id);
        if (jogDesatualizado.getId() != id) {
          cout << "Esse jogador nao existe! ";
        } else {
          char desejaAlterar = 'S';

          // MUDAR NOME COMPLETO //
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o nome completo do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string nomeCompleto;
              do {
                cout << "Novo nome completo: ";
                getline(cin, nomeCompleto);

                try {
                  jogDesatualizado.setNomeCompleto(nomeCompleto);
                  erro = false;
                } catch (int execao) {
                  erro = true;
                  cout << "Nome invalido! Deve conter no maximo 50 caracteres. "
                       << endl;
                }
              } while (erro);

              // strcpy(jogDesatualizado.getNomeCompleto(),
              // nomeCompleto.c_str());
              break;
            }
          }

          // MUDAR NOME CAMISETA /

          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o nome da camiseta do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string nomeCamiseta;
              do {
                cout << "Novo nome na camiseta: ";
                getline(cin, nomeCamiseta);

                try {
                  jogDesatualizado.setNomeCamiseta(nomeCamiseta);
                  erro = false;
                } catch (int execao) {
                  erro = true;
                  cout << "Nome invalido! Deve conter no maximo 20 caracteres. "
                       << endl;
                }
              } while (erro);

              // strcpy(jogDesatualizado.getNomeCompleto(),
              // nomeCompleto.c_str());
              break;
            }
          }

          // MUDAR IDADE //
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar a idade do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string idade;
              do {
                cout << "Nova idade: ";
                getline(cin, idade);

                if (isnumber(idade)) {
                  int idadeDigitada = stoi(idade);

                  try {
                    jogDesatualizado.setIdade(idadeDigitada);
                    erro = false;
                  } catch (int execao) {
                    erro = true;
                    cout << "Idade invalida! Idade deve ser um numero inteiro "
                            "entre 18 e 60"
                         << endl;
                  }
                } else {
                  erro = true;
                  cout << "Idade invalida! Idade deve ser um numero inteiro "
                          "entre 18 e 60"
                       << endl;
                }
              } while (erro);

              break;
            }
          }

          // MUDAR NUMERO //
          /*
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o numero do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              int numero;
              cout << "Novo numero: ";
              cin >> numero;
              jogDesatualizado.numero = numero;
              break;
            }
          }*/

          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o numero do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string numero;
              do {
                cout << "Novo numero: ";
                getline(cin, numero);

                if (isnumber(numero)) {
                  int numeroDigitado = stoi(numero);

                  try {
                    jogDesatualizado.setNumero(numeroDigitado);
                    erro = false;
                  } catch (int execao) {
                    erro = true;
                    cout << "Numero invalido! Numero deve ser um numero "
                            "inteiro entre 1 e 23"
                         << endl;
                  }

                } else {
                  erro = true;
                  cout << "Numero invalido! Numero deve ser um numero inteiro "
                          "entre 1 e 23"
                       << endl;
                }

              } while (erro);

              break;
            }
          }

          // MUDAR PAIS //
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o pais do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string pais;
              do {
                cout << "Novo pais: ";
                getline(cin, pais);

                try {
                  jogDesatualizado.setPais(pais);
                  erro = false;
                } catch (int execao) {
                  erro = true;
                  cout << "Pais invalido! Deve conter no maximo 30 caracteres. "
                       << endl;
                }
              } while (erro);
              break;
            }
          }

          // MUDAR TIME //
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o time do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string time;
              do {
                cout << "Novo time: ";
                getline(cin, time);

                try {
                  jogDesatualizado.setTime(time);
                  erro = false;
                } catch (int execao) {
                  erro = true;
                  cout << "Time invalido! Deve conter no maximo 30 caracteres. "
                       << endl;
                }
              } while (erro);
              break;
            }
          }

          // MUDAR POSICAO //
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar a posicao do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string pos;
              do {
                cout << "Nova posicao: ";
                getline(cin, pos);

                try {
                  jogDesatualizado.setPosicao(pos);
                  erro = false;
                } catch (int execao) {
                  erro = true;
                  cout << "Posicao invalida! Deve conter no maximo 20 "
                          "caracteres. "
                       << endl;
                }
              } while (erro);
              break;
            }
          }

          if (jogadores.atualizar(jogDesatualizado, id)) {
            cout << "Jogador atualizado com sucesso! " << endl;
          } else {
            cout << "Nenhuma alteracao foi feita." << endl;
          }
        }

        break;
      }
      case '5': {
        string idProcurado;

        cout << "\n--------------------" << endl;
        cout << "DELETANDO JOGADOR" << endl;

        cin.ignore();
        cout << "\nDigite o ID do jogador: ";
        getline(cin, idProcurado);

        do {
          if (isnumber(idProcurado)) {
            int idDigitado = stol(idProcurado);

            if (idDigitado < 0) // id invalido
            {
              erro = true;
              cout << "ID invalido! O ID deve ser um numero inteiro positivo."
                   << endl;
              cout << "Digite um ID diferente: ";
              getline(cin, idProcurado);
            } else // o usuario digitou um numero valido
            {
              erro = false;
            }
          } else // o usuario nao digitou um numero
          {
            erro = true;
            cout << "ID invalido! O ID deve ser um numero inteiro positivo."
                 << endl;
            cout << "Digite um ID diferente: ";
            getline(cin, idProcurado);
          }
        } while (erro);

        int id = stol(idProcurado);
        Jogador jog;
        jog = jogadores.buscarJogador(id);

        if (jog.getId() == id) {
          if (jogadores.excluir(id)) {
            cout << "\nO registro do jogador foi excluido!" << endl;
          } else {
            cout << "Nenhum jogador foi excluido. " << endl;
          }
        } else {
          cout << "Esse jogador nao existe! " << endl ;
        }
      }
      case 'S': {
        break;
      }
      default:
        cout << "\nOpcao invalida!" << endl;
        break;
      }
    }
  }

  return 0;
}