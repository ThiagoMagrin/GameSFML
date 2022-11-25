#include "Menu.h"
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

typedef struct Registro {
    std::string nome;
    int pts;
}Registro;

Menu::Menu() {
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    inicializar();
}

Menu::~Menu() {
    delete font;
    delete image;
    delete bg;
}

void Menu::inicializar() {
    pos = 0;
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

    limpar();
}

void Menu::limpar(){
    texts[1].setOutlineThickness(4);
    pos = 1;
}

void Menu::selecao() {
    sf::Event event;
    bool pressed = false;
    bool theselect = false;
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
                setOpcao(1);
                break;
            case 2:
                setOpcao(2);
                break;
            case 3:
                setOpcao(3);
                mostrarRanking();
                break;
            case 4:
                setOpcao(4);
                break;
            }
        }
    }
}

const int Menu::getOpcao(int op)
{
    return opcao;
}
void Menu::setOpcao(int op)
{
    opcao = op;
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
    selecao();
    desenhar();
}

void Menu::mostrarRanking()
{
    std::string novoJogador;
    int novaPontuacao;
    Registro rec;
    std::list<Registro> lista;
    std::string dadoJogador;
    std::vector<std::string> dados;

    std::ifstream Recupera("ranking.txt", std::ios::app);
    if (!Recupera)
    {
        std::cerr << " Arquivo não pode ser aberto" << std::endl;
        fflush(stdin);
        getchar();
    }

    while (!Recupera.eof()) {
        Recupera >> rec.nome >> rec.pts;
        lista.push_back(rec);
    }

    std::cout << "\n************* \n";
    std::cout << "\nRANKING - TOP 3 \n";

  
    int top = 3;

    std::list<Registro>::iterator it = lista.begin();
    for (int i = 0; i < top; i++) {
        
        std::cout << "nome: " << (it)->nome << " pts: " << (it)->pts << std::endl;
        dadoJogador = (it)->nome + " ";
        dadoJogador += std::to_string((it)->pts);
        dados.push_back(dadoJogador);
        it++;
    }
    Recupera.close();

    sf::Text aux;
    aux.setFont(*font);
    aux.setCharacterSize(50);
    aux.setOutlineColor(sf::Color::Red);

    int posx = 355, posy = 50;

    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        pGraf->limpaJanela();
        pGraf->desenhaBackground(*bg);

        aux.setString("RANKING - TOP 3 ");
        aux.setOutlineColor(sf::Color::Red);
        aux.setPosition(posx,posy);

        pGraf->escreveTexto(&aux);

        for (int i = 1; i < 4; i++) {
            dadoJogador = dados[i-1];
            aux.setString(dadoJogador);
            aux.setPosition(posx,posy + 120*i);
            pGraf->escreveTexto(&aux);
        }

        pGraf->mostrarJanela();
    }
}
