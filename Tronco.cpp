#include "Tronco.h"

#define DANO_TRONCO 0

namespace Entidades{
    namespace Obstaculos{
        Tronco::Tronco() : Obstaculo(), apodrecer(0) {}
        Tronco::~Tronco() {}

        void Tronco::inicializar(){
            setDano(DANO_TRONCO);

            posicao = sf::Vector2f(posicaoAleatoria(0).x, posicaoAleatoria(0).y - 30);
            tamanho = sf::Vector2f(70.0f, 70.0f);
            setTamanho(tamanho);

            textura = pGraf->carregarTextura("images/tronco.png");
            corpo.setTexture(textura, true);
            corpo.setPosition(posicao);
        }
    }
}
