#include "MenuRanking.h"
#include <list>
#include <iterator>
#include <fstream>

typedef struct Registro
{
    std::string nome;
    int pts;
} Registro;

MenuRanking::MenuRanking() {}

MenuRanking::~MenuRanking()
{
}

void MenuRanking::recuperaDados()
{
    std::string novoJogador;
    Registro rec;
    std::list<Registro> lista;
    std::string dadoJogador;

    dados = {};

    std::ifstream Recupera("ranking.txt", std::ios::app);
    if (!Recupera)
    {
        std::cerr << " Arquivo nao pode ser aberto" << std::endl;
        fflush(stdin);
        getchar();
    }

    while (!Recupera.eof())
    {
        Recupera >> rec.nome >> rec.pts;
        lista.push_back(rec);
    }

    for (std::list<Registro>::iterator it = lista.begin(); it != lista.end(); it++)
    {
        dadoJogador = (it)->nome + " ";
        dadoJogador += std::to_string((it)->pts);
        dados.push_back(dadoJogador);
    }
    Recupera.close();
}

void MenuRanking::inicializar()
{
    float posX = 500, posY = 150;

    recuperaDados();

    pGraf->limpaJanela();
    numTexto = 4;
    texts.resize(numTexto);

    options.push_back("RANKING TOP 3");
    coords.push_back({450, 40});

    for (int i = 0; i < numTexto - 1; i++)
    {
        options.push_back(dados[i]);
        coords.push_back({posX, posY});
        posY += 100;
    }

    for (std::size_t i{}; i < texts.size(); ++i)
    {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(30);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
        texts[i].setOutlineThickness(0);
    }

    texts[0].setFillColor(sf::Color::Black);

    pos = 1;
    texts[pos].setOutlineThickness(4);
}
