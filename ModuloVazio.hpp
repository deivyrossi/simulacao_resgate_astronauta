#ifndef MODULO_VAZIO_HPP
#define MODULO_VAZIO_HPP
#include "Modulo.hpp"

class ModuloVazio : public Modulo
{
public:
    ModuloVazio(char tipo);
    bool podeAcessar() override;
};
#endif