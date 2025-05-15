#include "Modulo.hpp"

Modulo::Modulo(char tipo) : tipo(tipo) {}

Modulo::Modulo() : tipo(' ') {}

bool Modulo::podeAcessar(){
    return false;
}

char Modulo::getTipo() const{
    return tipo;
}

void Modulo::setTipo(char ch){
    tipo = ch;
}