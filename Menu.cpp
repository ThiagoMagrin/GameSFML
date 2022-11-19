#include "Menu.h"

Menu::Menu() {
    Ente::setGraf(GerenciadorGrafico::getGerenciadorGrafico());
  
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();
    obgJogo = new Jogo;

    inicializar();
}

Menu::~Menu() {

    delete font;
    delete image;
    delete bg;
    delete obgJogo;
    GerenciadorGrafico::deletarGerenciadorGrafico();
}

void Menu::inicializar() {

    
    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("times new roman.ttf");
    image->loadFromFile("images/menu.png");

    bg->setTexture(*image);
   


    options = { "NOME DO JOGO", "Fase Terra", "Fase Gelo", "Ranking", "Sair" };
    texts.resize(5);
    coords = { {490,40},{510,190},{510,282},{510,370},{510,456} };
    sizes = { 20,28,24,24,24 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(4);
    pos = 1;


}

void Menu::selecao() {
    sf::Event event;
    while (pGraf->getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            pGraf->fecharJanela();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 4) {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 1) {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            std::cout << options[pos] << '\n';
            switch (pos)
            {
            case 1 :
                obgJogo->executarFase1();
                break;
            case 2:
                obgJogo->executarFase2();
                break;
            case 3:
                std::cout << "MOSTAR RANKING\n";
                break;
            case 4:
                pGraf->fecharJanela();
                break;
            }
            
        }
    }
}

void Menu::desenhar() {
    pGraf->limpaJanela();
    pGraf->desenhaBackground(*bg);
    for (auto &t : texts) {
        pGraf->escreveTexto(&t);
    }
    pGraf->mostrarJanela();
}

void Menu::run_menu() {

    while (pGraf->verificaJanelaAberta())
    {
        selecao();
        desenhar();
    }
}