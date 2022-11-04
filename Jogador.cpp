#include "Jogador.h"
#define VELOCIDADE_JOGADOR 5.0f

namespace Entidades {
    namespace Personagens {
        Jogador::Jogador() { inicializar(); }
        Jogador::Jogador(const sf::Vector2f pos, sf::Vector2f tam) :
            Personagem(),pontuacao(0)
        {
            corpo.setSize(tam);
            corpo.setPosition(pos);
            corpo.setFillColor(sf::Color::Blue);
            inicializar();
            std::cout << "Jogador criado\n";
        }

        Jogador::~Jogador() {}

        void  Jogador::movimento(){
            float posJ = getPosicao().x;
            std::cout << posJ << std::endl;
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && posJ > 0.0f){
                corpo.move(-velocidade.x, 0.0f);
                std::cout << "Left\n";
            }
            else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && posJ < 1100.0f - 50.0f){
                corpo.move(velocidade.x, 0.0f);
                std::cout << "Right\n";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)  || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (chao == true) {
                    corpo.move(0.0f, -velocidade.y*10);
                    std::cout << "Jump\n";
                    chao = false;
                }else std::cout << "Jogador nao esta no Chao\n";
            }
        }

        void Jogador::cair() {
                corpo.move(0.0f, velocidade.y*5);
        }

        void Jogador::atualizar() {
            posicao = corpo.getPosition();
            if (posicao.y >= 500) {
                chao = true;
            }
            else {
                chao = false;
                cair();
            }

            movimento();
        }

        void Jogador::setPontuacao(int p) {
            pontuacao += p;
        }

        const int Jogador::getPontuacao() const {
            return pontuacao;
        }
        void Jogador::inicializar(){
            velocidade = sf::Vector2f(VELOCIDADE_JOGADOR, VELOCIDADE_JOGADOR);
        }
        void Jogador::renderizar(){}
        void Jogador::executar(){}
    }
}
