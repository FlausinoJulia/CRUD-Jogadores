#ifndef JOGADOR
#define JOGADOR

#include <iostream>

struct Jogador
{
    unsigned int id;
    std::string nomeCompleto;
    unsigned char idade;
    std::string nomeCamiseta;
    unsigned char numero;
    std::string pais;
    std::string time;
    std::string posicao;
    /*
    
    private:
        unsigned int id;
        string nomeCompleto;
        string nomeCamiseta;
        unsigned char numero;
        unsigned char idade;
        string pais;
        string time;
        string posicao;
    public:
        void criar(unsigned int pid, string pnomeCompleto, string pnomeCamiseta, unsigned char pnumero,
                   unsigned char pidade, string ppais, string ptime, string pposicao);

        // getters e setters // 
        void setId(unsigned int pid);
        unsigned int getId();

        void setIdade(unsigned char pidade);
        unsigned char getIdade();

        void setNumero(unsigned char pnumero);
        unsigned char getNumero();

        void setNomeCompleto(string pnomeCompleto);
        string getNomeCompleto();

        void setNomeCamiseta(string pnomeCamiseta);
        string getNomeCamiseta();

        void setPais(string ppais);
        string getPais();

        void setTime(string ptime);
        string getTime();

        void setPosicao(string pposicao);
        string getPosicao();
        */
};

#endif