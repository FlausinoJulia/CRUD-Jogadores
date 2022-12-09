// #ifndef DBO
// #define DBO


// #include <string.h>

//#pragma once
 
// using namespace std;

class Dbo
{
    private:
        // atributos
        char nomeCompleto,
                nomeCamiseta,
                pais,
                time,
                posicao;
        unsigned int id, idade, numero;

    public:

    // construtor
    Dbo();
    ~Dbo();
 
    // construtor Overload
    Dbo(char nomeCompleto, char nomeCamiseta, char pais, 
        char time, char posicao, unsigned int id,
        unsigned int idade, unsigned int numero);

    // metodos getter e setter
    void setId(unsigned int id);
    unsigned int getId();

    void setIdade(unsigned int idade);
    unsigned int getIdade();

    void setNumero(unsigned int numero);
    unsigned int getNumero();

    void setNomeCompleto(char nomeCompleto);
    char getNomeCompleto();

    void setNomeCamiseta(char nomeCamiseta);
    char getNomeCamiseta();

    void setPais(char pais);
    char getPais();

    void setTime(char time);
    char getTime();

    void setPosicao(char posicao);
    char getPosicao();

};

// #endif