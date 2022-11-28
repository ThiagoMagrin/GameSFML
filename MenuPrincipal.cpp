#include "MenuPrincipal.h"
#include <iostream>

MenuPrincipal::MenuPrincipal() {}

MenuPrincipal::~MenuPrincipal() {}

void MenuPrincipal::inicializar()
{
    numTexto = 5;
    options = {"WARRIOR++", "Fase Terra", "Fase Gelo", "Ranking", "Sair"};
    coords = {{500, 40}, {517, 130}, {517, 200}, {520, 270}, {520, 350}};
    texts.resize(numTexto);

    for (std::size_t i{}; i < texts.size(); ++i)
    {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(20);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
        texts[pos].setOutlineThickness(0);
    }

    texts[0].setFillColor(sf::Color::Black);

    pos = 1;
    texts[pos].setOutlineThickness(4);
}

int MenuPrincipal::getOpcaoJogo()
{
    return opcaoJogo;
}

void MenuPrincipal::setOpcaoJogo(int opcao)
{
    opcaoJogo = opcao;
}

void MenuPrincipal::tratarEscolha(int escolha)
{
    switch (escolha)
    {
    case 1:
        setOpcaoJogo(1);
        break;
    case 2:
        setOpcaoJogo(2);
        break;

    case 3:
        menuR.inicializar();
        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            menuR.executar();
        }
        limpar();

        break;
    case 4:
        pGraf->fecharJanela();
        break;
    }
}
