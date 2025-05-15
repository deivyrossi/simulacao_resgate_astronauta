#ifndef MODULOCOMFOGO_HPP
#define MODULOCOMFOGO_HPP
#include "Modulo.hpp"

class ModuloComFogo : public Modulo
{
public:
    ModuloComFogo(char tipo);
    
    bool podeAcessar() override;
}; 
#endif