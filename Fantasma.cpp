#include "Fantasma.h"

#define VIDA_FANTASMA 25
#define DANO_FANTASMA 1

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Fantasma::Fantasma() : Inimigo(nullptr), assombracao(0){}
            Fantasma::~Fantasma() {}

            void Fantasma::inicializar(Jogador* pJ, Jogador* pJ2) {
                setJogador(pJ, pJ2);

                assombracao = 1 + rand() % 4;
                setVida(VIDA_FANTASMA);
                setDano(DANO_FANTASMA * assombracao);
                setTamanho({70.0f, 70.0f});

               // posicao = sf::Vector2f(700.0f, 530.0f);
               // posicao = sf::Vector2f({ 280.0f, 280.0f });
                posicao = sf::Vector2f(posicaoAleatoria(1));
                velocidade = sf::Vector2f(70.0f, 70.0f);

                textura = pGraf->carregarTextura("images/Fantasma.png");
                corpo.setTexture(textura, true);
                corpo.setPosition(posicao);


                std::cout << "nivel assombracao = " << assombracao << std::endl;
            }

            /*void Fantasma::movimentoEspecifico(){
                float posI = getPosicao().x;
                if(posI >= 600.0f - 20 && lado == false){
                    if(posI < 600.0f - 19) lado = true;
                    corpo.move(-0.04f, 0.0f);
                }

                else if(posI <= 600.0f + 20 && lado == true){
                    if(posI > 600.0f + 19) lado = false;
                    corpo.move(0.04f, 0.0f);
                }

            }*/
        }
    }
}
