#ifndef ESTACAO_ESPACIAL_HPP
#define ESTACAO_ESPACIAL_HPP
#include "Modulo.hpp"
#include "ModuloComAstronauta.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloVazio.hpp"
#include "Astronauta.hpp"
#include <vector>
using namespace std;

class EstacaoEspacial
{
private:
    vector<vector<Modulo*>> matriz; 
    vector<Astronauta> astronautas; 
    int linhas;
    int colunas;
public:
    EstacaoEspacial(int linhas, int colunas);
    EstacaoEspacial();
    Astronauta getAstroPos(int x, int y);
    const vector<vector<Modulo*>>& getMatriz() const;
    const vector<Astronauta>& getAstronautas() const;
    int getLinhas() const;
    int getColunas() const;
    void setPos(int x, int y, int cont);
    void adicionarCel(int linha, int coluna, char tipo);
    void adicionarAstronauta(const Astronauta& astronauta);
};

#endif