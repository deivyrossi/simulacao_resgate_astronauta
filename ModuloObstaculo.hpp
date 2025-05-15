#ifndef MODULO_OBSTACULO_HPP
#define MODULO_OBSTACULO_HPP
#include "Modulo.hpp"

class ModuloObstaculo : public Modulo
{
public:
    ModuloObstaculo(char tipo);
    bool podeAcessar() override;
 
};
#endif