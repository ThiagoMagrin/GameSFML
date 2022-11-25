#include "Plataforma.h"

namespace Entidades{
    Plataforma::Plataforma(sf::Vector2f pos){
        setID(4);
        std::cout << getId() << std::endl;
        posicao = pos;
        setTamanho( {600.0f, 10.f});
        executar();
        imprimir();
    }

    Plataforma::~Plataforma(){}

    void Plataforma::executar(){
        textura = pGraf->carregarTextura("images/Plataforma.png");
        corpo.setTexture(textura, true);
        corpo.setPosition(posicao);
    }

    void Plataforma::imprimir(){
        pGraf->desenhaElemento(corpo);
    }

    void Plataforma::colisao(Entidade* outraEntidade){
        if(outraEntidade->getId() == 1 || outraEntidade->getId() == 2){
           // std::cout << "Colidiu jogador e plataforma" << std::endl;
        }
    }
}
