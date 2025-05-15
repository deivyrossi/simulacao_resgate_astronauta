#ifndef MODULOCOMASTRONAUTA_HPP
#define MODULOCOMASTRONAUTA_HPP
#include "Modulo.hpp"

class ModuloComAstronauta : public Modulo
{

public:
    ModuloComAstronauta(char tipo);
    ModuloComAstronauta();

    bool podeAcessar() override;
};

#endif

