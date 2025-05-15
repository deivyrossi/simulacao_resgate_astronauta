#include "EstacaoEspacial.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloComAstronauta.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloNormal.hpp"
#include <iostream>

using namespace std;

EstacaoEspacial::EstacaoEspacial(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    matriz.resize(linhas, vector<Modulo*>(colunas, nullptr));
}

EstacaoEspacial::EstacaoEspacial() : linhas(0), colunas(0)
{
    matriz.resize(linhas, vector<Modulo*>(colunas, nullptr));
}

void EstacaoEspacial::adicionarCel(int linha, int coluna, char tipo) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        if (tipo == 'S') {
            matriz[linha][coluna] = new ModuloSeguranca(tipo);
        } else if (tipo == 'A') {
            matriz[linha][coluna] = new ModuloComAstronauta(tipo);
        } else if (tipo == '#') {
            matriz[linha][coluna] = new ModuloObstaculo(tipo);
        } else if (tipo == '~') {
            matriz[linha][coluna] = new ModuloVazio(tipo);
        } else if (tipo == 'F') {
            matriz[linha][coluna] = new ModuloComFogo(tipo);
        } else if (tipo == '.') {
            matriz[linha][coluna] = new ModuloNormal(tipo);
        } else {
            cout << "\nValor da cédula inválido!" << endl;
        }
    } else {
        cout << "Posição inválida" << endl;
    }
}

Astronauta EstacaoEspacial::getAstroPos(int x, int y) {
    for (const Astronauta &astronauta : astronautas) {
        if (astronauta.getX() == x && astronauta.getY() == y) {
            return astronauta;
        }
    }
    return Astronauta("", 0, false);
}

void EstacaoEspacial::adicionarAstronauta(const Astronauta &astronauta) {
    astronautas.push_back(astronauta);
}

const vector<vector<Modulo*>> &EstacaoEspacial::getMatriz() const {
    return matriz;
}

const vector<Astronauta> &EstacaoEspacial::getAstronautas() const {
    return astronautas;
}

int EstacaoEspacial::getLinhas() const {
    return linhas;
}

int EstacaoEspacial::getColunas() const {
    return colunas;
}

void EstacaoEspacial::setPos(int x, int y, int cont) {
    if (cont >= 0 && cont < astronautas.size()) {
        astronautas[cont].setX(x);
        astronautas[cont].setY(y);
    }
}

