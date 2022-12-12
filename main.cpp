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
        bool erro = false; // para tratar excecoes
        Jogador jog;
        string nomeCompleto, nomeCamiseta, pais, time, posicao;
        string id;

        cout << "\n--------------------" << endl;
        cout << "ADICIONANDO JOGADOR" << endl;

        cout << "\nID..............: ";
        cin >> id;

        do 
        {
          if (isnumber(id))
          {
            int idDigitado = stol(id);
            try 
            {
              jog.setId(idDigitado);
            }
            catch(int erro)
            {
              erro = true;
              cout << "\nID inválido! O ID deve ser um número inteiro positivo." << endl;
              cout << "Digite um ID diferente: ";
              cin >> id;
            }
          }
          else
          {
            erro = true;
            cout << "\nID inválido! O ID deve ser um número inteiro positivo." << endl;
            cout << "Digite um ID diferente: ";
            cin >> id;
          }
        }
        while(erro);

        while (jogadores.existeJogador(jog.getId())) 
        {
          cout << "\nJa existe um jogador com esse ID!" << endl;
          cout << "Digite um ID diferente: ";
          cin >> id;

          do 
          {
            if (isnumber(id))
            {
              int idDigitado = stol(id);
              try 
              {
                jog.setId(idDigitado);
              }
              catch(int erro)
              {
                erro = true;
                cout << "\nID inválido! O ID deve ser um número inteiro positivo." << endl;
                cout << "Digite um ID diferente: ";
                cin >> id;
              }
            }
            else
            {
              erro = true;
              cout << "\nID inválido! O ID deve ser um número inteiro positivo." << endl;
              cout << "Digite um ID diferente: ";
              cin >> id;
            }
          }
          while(erro);
        }

        cin.ignore(); // ignorando \n do buffer
        cout << "Nome completo...: ";
        getline(cin, nomeCompleto);
        // jog.nomecompleto recebe uma copia da string lida no padrão de c++
        strcpy(jog.nomeCompleto, nomeCompleto.c_str());

        cout << "Nome na camiseta: ";
        getline(cin, nomeCamiseta);
        // jog.nomeCamiseta recebe uma copia da string lida no padrão de c++
        strcpy(jog.nomeCamiseta, nomeCamiseta.c_str());

        cout << "Idade...........: ";
        cin >> jog.idade;

        cout << "Numero..........: ";
        cin >> jog.numero;
        cin.ignore();

        cout << "Pais............: ";
        getline(cin, pais);
        // jog.pais recebe uma copia da string lida no padrão de c++
        strcpy(jog.pais, pais.c_str());

        cout << "Time............: ";
        getline(cin, time);
        // jog.time recebe uma copia da string lida no padrão de c++
        strcpy(jog.time, time.c_str());

        cout << "Posicao.........: ";
        getline(cin, posicao);
        // jog.posicao recebe uma copia da string lida no padrão de c++
        strcpy(jog.posicao, posicao.c_str());

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
        int idProcurado;

        cout << "\n--------------------" << endl;
        cout << "BUSCANDO JOGADOR" << endl;

        cout << "\nDigite o ID do jogador: ";
        cin >> idProcurado;

        Jogador jog;
        jog = jogadores.buscarJogador(idProcurado);

        if (jog.getId() == idProcurado) {
          cout << "\nO jogador foi encontrado!" << endl;
          jog.exibir();
        } else {
          cout << "Jogador nao existe. " << endl;
        }

        break;
      }
      case '4': {
        int idProcurado;

        cout << "\n--------------------" << endl;
        cout << "ATUALIZANDO JOGADOR" << endl;

        cout << "\nDigite o ID do jogador: ";
        cin >> idProcurado;

        Jogador jogDesatualizado = jogadores.buscarJogador(idProcurado);
        if (jogDesatualizado.getId() != idProcurado) {
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
              cout << "Novo nome completo: ";
              getline(cin, nomeCompleto);
              strcpy(jogDesatualizado.nomeCompleto, nomeCompleto.c_str());
              break;
            }
          }

          // MUDAR NOME CAMISETA //
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o nome da camiseta do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string nomeCamiseta;
              cout << "Novo nome da camiseta: ";
              getline(cin, nomeCamiseta);
              strcpy(jogDesatualizado.nomeCamiseta, nomeCamiseta.c_str());
              break;
            }
          }

          // MUDAR IDADE //
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar a idade do jogador? [S/N] ";
            cin >> desejaAlterar;

            if (std::toupper(desejaAlterar) == 'S') {
              int idade;
              cout << "Nova idade: ";
              cin >> idade;
              jogDesatualizado.idade = idade;
              break;
            }
          }

          // MUDAR NUMERO //
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
          }

          // MUDAR PAIS //
          desejaAlterar = 'S';
          while (std::toupper(desejaAlterar) != 'N') {
            cout << "\nDeseja alterar o pais do jogador? [S/N] ";
            cin >> desejaAlterar;
            cin.ignore();

            if (std::toupper(desejaAlterar) == 'S') {
              string pais;
              cout << "Novo pais: ";
              getline(cin, pais);
              strcpy(jogDesatualizado.pais, pais.c_str());
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
              cout << "Novo time: ";
              getline(cin, time);
              strcpy(jogDesatualizado.time, time.c_str());
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
              cout << "Nova posicao: ";
              getline(cin, pos);
              strcpy(jogDesatualizado.posicao, pos.c_str());
              break;
            }
          }

          if (jogadores.atualizar(jogDesatualizado, idProcurado)) {
            cout << "Jogador atualizado com sucesso! " << endl;
          } else {
            cout << "Nenhuma alteracao foi feita." << endl;
          }
        }

        break;
      }
      case '5': {
        int idProcurado;

        cout << "\n--------------------" << endl;
        cout << "DELETANDO JOGADOR" << endl;

        cout << "\nDigite o ID do jogador: ";
        cin >> idProcurado;

        Jogador jog;
        jog = jogadores.buscarJogador(idProcurado);

        if (jog.getId() == idProcurado) {
          if (jogadores.excluir(idProcurado)) {
            cout << "\nO registro do jogador foi excluido!" << endl;
          } else {
            cout << "Nenhum jogador foi excluido. " << endl;
          }
        } else {
          cout << "Esse jogador nao existe! ";
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