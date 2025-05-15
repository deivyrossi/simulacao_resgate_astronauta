#ifndef MODULONORMAL_HPP
#define MODULONORMAL_HPP
#include "Modulo.hpp"

class ModuloNormal : public Modulo
{
public:
    ModuloNormal(char tipo);
    bool podeAcessar() override;
};
#endif