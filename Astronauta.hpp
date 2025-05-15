#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP
#include <string>
using namespace std;

class Astronauta
{
private:
    string nome;
    int nivelSaude;
    bool atendimentoUrgente;
    int x;
    int y;

public:
    Astronauta(string nome, int nivelSaude, bool atendimentoUrgente, int x, int y);
    Astronauta(string nome, int nivelSaude, bool atendimentoUrgente);
    bool isAtendimentoUrgente() const;
    int getNivelSaude() const;
    string toString() const;
    string getNome() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
};

#endif