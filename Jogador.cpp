#include "Jogador.h"

#define VIDAJOGADOR 100
#define DANOJOGADOR 5

namespace Entidades {
    namespace Personagens {
        Jogador::Jogador() : Personagem(), pontuacao(0){
            Ente::setId(1);
        }

        Jogador::~Jogador() {}

        void Jogador::inicializar(){

            setVida(VIDAJOGADOR);
            setDano(DANOJOGADOR);

            velocidade = {5.0f, 5.0f};
            posicao = {200.0f, 380.0f};

            corpo.setSize({50.0f, 70.0f});
            corpo.setPosition(posicao);
            corpo.setFillColor(sf::Color::Blue);

            std::cout << "Jogador inicializado" << std::endl;
        }

        void Jogador::movimento(){
            float posJ = getPosicao().x;

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && posJ > 0.0f){
                corpo.move(-velocidade.x, 0.0f);
            }

            else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && posJ < 1200.0f - 50.0f){
                corpo.move(velocidade.x, 0.0f);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)  || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (chao == true) {
                    corpo.move(0.0f, -velocidade.y*50);
                }

                //else std::cout << "Jogador nao esta no Chao\n";
            }
        }

        void Jogador::cair() {
            corpo.move(0.0f, velocidade.y*5);
        }

        void Jogador::executar() {
            posicao = corpo.getPosition();

            if ((posicao.y >= 380.0f) || ((posicao.x >= 30.0f && posicao.x <= 240.0f && posicao.y == 130.0f)) || (posicao.y == 180.0f && posicao.x >= 275.0f && posicao.x <= 800.0f) || (posicao.y == 155.0f && posicao.x >= 835.0f && posicao.x <= 1100.0f)) {
                chao = true;
            }
            else {
                cair();
                chao = false;
            }

            movimento();
        }

        void Jogador::setPontuacao(int p) {
            pontuacao += p;
        }

        const int Jogador::getPontuacao() const {
            return pontuacao;
        }
    }
}
