#include "MenuDoisJogadores.h"

MenuDoisJogadores::MenuDoisJogadores() : doisJogadores(false), selecionado(false) {}

MenuDoisJogadores::~MenuDoisJogadores()
{
}

void MenuDoisJogadores::inicializar()
{
    selecionado = false;
    pGraf->limpaJanela();
    numTexto = 2;
    options = {"UM JOGADOR", "DOIS JOGADORES"};
    coords = {{500, 200}, {480, 300}};
    texts.resize(numTexto);

    for (std::size_t i{}; i < texts.size(); ++i)
    {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(20);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
        texts[i].setOutlineThickness(0);
    }

    pos = 0;
    texts[pos].setOutlineThickness(4);
}

void MenuDoisJogadores::tratarEscolha(int escolha)
{
    if (escolha == 0)
    {
        doisJogadores = false;
        selecionado = true;
    }
    else
    {
        doisJogadores = true;
        selecionado = true;
    }
}

bool MenuDoisJogadores::getDoisJogadores()
{
    return doisJogadores;
}

bool MenuDoisJogadores::getSelecionado()
{
    return selecionado;
}