#ifndef MODULO_SEGURANCA_HPP
#define MODULO_SEGURANCA_HPP
#include "Modulo.hpp"

class ModuloSeguranca : public Modulo
{
public:
    ModuloSeguranca(char tipo);
    bool podeAcessar() override;
 
};

#endif