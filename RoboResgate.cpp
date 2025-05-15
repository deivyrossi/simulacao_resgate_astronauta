#include "RoboResgate.hpp"
#include "EstacaoEspacial.hpp"
#include "Astronauta.hpp"
#include "Modulo.hpp"
#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

RoboDeResgate::RoboDeResgate(int posX, int posY, EstacaoEspacial estacao)
    : posicaoInicialX(posX), posicaoInicialY(posY), estacao(estacao) {
    int linhas = estacao.getLinhas();
    int colunas = estacao.getColunas();
    visitado.resize(linhas, vector<bool>(colunas, false));
    distancias.resize(linhas, vector<int>(colunas, -1));
    passos = 0;
}

RoboDeResgate::RoboDeResgate()
    : posicaoInicialX(0), posicaoInicialY(0), passos(0)  {
    int linhas = estacao.getLinhas();
    int colunas = estacao.getColunas();
    visitado.resize(linhas, vector<bool>(colunas, false));
    distancias.resize(linhas, vector<int>(colunas, -1));
    passos = 0;
}






void RoboDeResgate::exibirMatriz(const vector<vector<Modulo*>> &matriz) {
    for (const auto &linha : matriz) {
        for (const auto &modulo : linha) {
            if (modulo != nullptr) {
                cout << modulo->getTipo() << " ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}






void RoboDeResgate::voltarParaBase() {
    
    caminhodevolta(home.first, home.second);
    
    cout << "\nO robô retornou à base com sucesso!" << endl;
    cout << "Relatório de Resgate: " << endl;
    cout << "- Número de astronautas resgatados: " << resgatados.size() << endl;
    
    for (const Astronauta &astro : resgatados) {
        cout << "\t- " << astro.toString();
    }

    for (const Astronauta &astroExistente : estacao.getAstronautas()) {
        bool foiResgatado = false;
        for (const Astronauta &astroResgatado : resgatados) {
            if (astroExistente.getNome() == astroResgatado.getNome()) {
                foiResgatado = true;
                break;
            }
        }
        if (!foiResgatado) {
            naoResgatados.push_back(astroExistente);
        }
    }
    
    cout << "- Lista de astronautas não resgatados: " << endl;
    for (const Astronauta &astro : naoResgatados) {
        cout << "\t- " << astro.toString();
    }

    cout << "- Total de passos: " << passos << " passos." << endl << endl;
    exibirMatriz(estacao.getMatriz());
}

void RoboDeResgate::caminhodevolta(int destX, int destY) {
    vector<pair<int, int>> caminho;
    int x = destX, y = destY;

    while (x != -1 && y != -1) {
        caminho.push_back({x, y});
        auto [prevX, prevY] = antecessores[x][y];
        x = prevX;
        y = prevY;   
    }

    passos += caminho.size() - 1;
    reverse(caminho.begin(), caminho.end());
    mostrarCaminho(caminho);    
}




void RoboDeResgate::mostrarCaminho(vector<pair<int, int>> &caminho) {
    for (size_t i = 0; i < caminho.size(); i++) {
        auto posicao = caminho[i];
        estacao.getMatriz()[posicao.first][posicao.second]->setTipo('*');
    }
    exibirMatriz(estacao.getMatriz());
}




bool RoboDeResgate::fogoAoRedor(int x, int y) {
    int numLinhas = estacao.getLinhas();
    int numColunas = estacao.getColunas();
    int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
    int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
    
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= numLinhas || ny >= numColunas) {
            continue;
        }

        char tipo = estacao.getMatriz()[nx][ny]->getTipo();
        if (tipo == 'F') {
            return true;
        }        
    }
    return false;
}




void RoboDeResgate::gerarRelatorio(const string &nomeArquivoEntrada) {
    
    string nomeArquivoSaida = "saida" + nomeArquivoEntrada.substr(nomeArquivoEntrada.find_last_of("1234567890"));
    if (nomeArquivoSaida == "saida0.txt") {
        nomeArquivoSaida = "saida10.txt";
    }
    
    ofstream arquivoSaida(nomeArquivoSaida);
    if (!arquivoSaida) {
        cerr << "Erro ao criar arquivo de saída: " << nomeArquivoSaida << endl;
        return;
    }

    arquivoSaida << "Relatório de Resgate:\n";
    arquivoSaida << "- Número de astronautas resgatados: " << resgatados.size() << endl;
    
    for (const Astronauta &astro : resgatados) {
        arquivoSaida << "\t- " << astro.toString();
    }

    arquivoSaida << "- Lista de astronautas não resgatados:\n";
    for (const Astronauta &astro : naoResgatados) {
        arquivoSaida << "\t- " << astro.toString();
    }
    
    arquivoSaida << "- Total de passos: " << passos << " passos." << endl;
    arquivoSaida.close();
    cout << "Relatório gerado em: " << nomeArquivoSaida << endl;
}






void RoboDeResgate::iniciarResgate(int xIni, int yIni, bool acabou) {
    if (passos == 0) {
        home = {xIni, yIni};
    }
    
    int numLinhas = estacao.getLinhas();
    int numColunas = estacao.getColunas();
    
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            visitado[i][j] = false;
            distancias[i][j] = -1;    
        }
    }

    antecessores.clear();
    antecessores.resize(numLinhas, vector<pair<int, int>>(numColunas, {-1, -1}));

    queue<int> filaX;
    queue<int> filaY;
    filaX.push(xIni);
    filaY.push(yIni);

    visitado[xIni][yIni] = true;
    distancias[xIni][yIni] = 0;

    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int nx, ny;
    bool resgatou = false;
    
    while (!filaX.empty() && !filaY.empty()) {
        int x = filaX.front();
        int y = filaY.front();
    
        filaX.pop();
        filaY.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= numLinhas || ny >= numColunas) {
                continue;
            }

            char tipo = estacao.getMatriz()[nx][ny]->getTipo();

            if (tipo == '#' || tipo == '~' || fogoAoRedor(nx, ny)) {
                continue;
            }
            
            if (visitado[nx][ny]) {
                continue;
            }
            
            visitado[nx][ny] = true;
            distancias[nx][ny] = distancias[x][y] + 1;
            antecessores[nx][ny] = {x, y};
            
            if (tipo == 'A') {
                Astronauta astro = estacao.getAstroPos(nx, ny);
                resgatados.push_back(astro);

                caminhodevolta(nx, ny);
                cout << astro.toString();
                cout << "Astronautas resgatados até o momento: " << resgatados.size();
                cout << "\nTotal de passos para o resgate: " << passos << endl << endl;

                filaX.push(nx);
                filaY.push(ny);

                resgatou = true;
                iniciarResgate(nx, ny, false);
            }

            if (acabou == true && home.first == xIni && home.second == yIni) {
                caminhodevolta(home.first, home.second);
            }
            
            filaX.push(nx);
            filaY.push(ny);
        }
    }
    
    if (!resgatou) {
        voltarParaBase();
    }
}
