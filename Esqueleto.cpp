#include "Esqueleto.h"

#define VIDA_ESQUELETO 25
#define DANO_ESQUELETO 5

namespace Entidades {
    namespace Personagens {
        namespace Inimigos{
            Esqueleto::Esqueleto() : Inimigo(nullptr) , decomposicao(0) {}
            Esqueleto::~Esqueleto() {}

            void Esqueleto::inicializar(Jogador* pJ) {
                setJogador(pJ);

                decomposicao = rand() % 4;
                setVida(VIDA_ESQUELETO);
                setDano(DANO_ESQUELETO - decomposicao);

                //posicao = sf::Vector2f(900.0f, 540.0f);
                posicao = sf::Vector2f(posicaoAleatoria());
                velocidade = sf::Vector2f(70.0f, 70.0f);
                tamanho = sf::Vector2f(70.0f, 70.0f);
                setTamanho(tamanho);

                textura = pGraf->carregarTextura("images/Esqueleto.png");
                corpo.setTexture(textura, true);
                corpo.setPosition(posicao);
            }

            /*void Esqueleto::movimentoEspecifico(){
                float posI = getPosicao().x;

                if(posI >= 900.0f - 20 && lado == false){
                    if(posI < 900.0f - 19) lado = true;
                    corpo.move(-0.04f, 0.0f);
                }

                else if(posI <= 900.0f + 20 && lado == true){
                    if(posI > 900.0f + 19) lado = false;
                    corpo.move(0.04f, 0.0f);
                }

            }*/
        }
    }
}
