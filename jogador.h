#ifndef JOGADOR
#define JOGADOR

#include <iostream>

struct Jogador
{
    int id;
    char nomeCompleto[51];
    unsigned int idade;
    char nomeCamiseta[21];
    unsigned int numero;
    char pais[31];
    char time[31];
    char posicao[21];

    void exibir();
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