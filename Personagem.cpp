#include "Personagem.h"
#include <SFML/Graphics.hpp>
#include <cmath>
namespace Entidades {

    namespace Personagens {
        Personagem::Personagem() : Entidade(), chao(true), direita(true), esquerda(true) {}

        Personagem::~Personagem() {}

        void Personagem::setChao(bool b){
            chao = b;
        }

        void Personagem::setDireita(bool b){
            direita = b;
        }

        void Personagem::setEsquerda(bool b){
            esquerda = b;
        }

        void Personagem::pular(float pulo)
        {
            // Equacao de Torricelli
            //v^2 = G*H
            pulo = sqrt(2.0f * GRAVIDADE * pulo);
            corpo.move(0.0f, -pulo * 10);
        }
    }
}
