#include "Astronauta.hpp"
#include <sstream>

Astronauta::Astronauta(string nome, int nivelSaude, bool atendimentoUrgente, int x, int y)
    : nome(nome), nivelSaude(nivelSaude), atendimentoUrgente(atendimentoUrgente), x(x), y(y) {}

Astronauta::Astronauta(string nome, int nivelSaude, bool atendimentoUrgente):
    nome(nome), nivelSaude(nivelSaude), atendimentoUrgente(atendimentoUrgente){};


bool Astronauta::isAtendimentoUrgente() const {
    return atendimentoUrgente;
}

string Astronauta::toString() const {
    ostringstream astro;
    astro << nome
        << ": Saúde " << nivelSaude
        << ", Atendimento Médico Urgente: " << (atendimentoUrgente ? "Sim" : "Não")
        << ", Posição: (" << x << ", " << y << ")" << endl;
    return astro.str();
}


int Astronauta::getX() const {
    return x;
}

int Astronauta::getY() const {
    return y;
}

string Astronauta::getNome() const {
    return nome;
}

int Astronauta::getNivelSaude() const {
    return nivelSaude;
}

void Astronauta::setX(int x) {
    this->x = x;
}

void Astronauta::setY(int  y ){
    this -> y = y;
}