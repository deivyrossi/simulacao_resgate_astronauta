#ifndef ROBO_RESGATE_HPP
#define ROBO_RESGATE_HPP

#include "EstacaoEspacial.hpp"
#include "Astronauta.hpp"

class RoboDeResgate
{
private:
    int posicaoInicialX;
    int posicaoInicialY;
    EstacaoEspacial estacao;
    vector<Astronauta> resgatados;
    vector<Astronauta> naoResgatados;
    int passos;
    vector<vector<bool>> visitado;
    vector<vector<int>> distancias;

    int numLinhas = estacao.getLinhas();
    int numColunas = estacao.getColunas();

    vector<vector<pair<int, int>>> antecessores;

    pair<int, int> home;
    bool acabou = false;

public:
    RoboDeResgate(int posX, int posY, EstacaoEspacial _estacao);
    RoboDeResgate();

   
    void iniciarResgate(int xIni, int yIni, bool acabou);
    bool fogoAoRedor(int x, int y);
    void mostrarCaminho(vector<pair<int,int>>& caminho);
    void voltarParaBase();
    void gerarRelatorio(const string& nomeArquivoEntrada);
    void caminhodevolta(int destX, int destY);
    void exibirMatriz(const vector<vector<Modulo*>> &matriz);
};

#endif
