#include "Pedra.h"

#define DANO_PEDRA 1

namespace Entidades{
    namespace Obstaculos{
        Pedra::Pedra() : Obstaculo() , ponteaguda(false) {}
        Pedra::~Pedra() {}

        void Pedra::inicializar(){

            if (rand() % 2 == 1) {//Colocar texturas diferentes para cada caso
                ponteaguda = true;
            }
            if (ponteaguda == true) {
                setDano(DANO_PEDRA);
            }
            tamanho = sf::Vector2f(70.0f, 15.0f);
            setTamanho(tamanho);
            float posicao_y = posicaoAleatoria().y + getTamanho().y;
            posicao = sf::Vector2f(posicaoAleatoria().x, posicao_y);

            textura = pGraf->carregarTextura("images/pedra.png");
            corpo.setTexture(textura, true);
            corpo.setPosition(posicao);
        }
    }
}
