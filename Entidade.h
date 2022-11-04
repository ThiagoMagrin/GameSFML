#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

#define GRAVIDADE 998.f

namespace Entidades {

    class Entidade : public Ente {
    protected:
        sf::Vector2f posicao, tamanho, velocidade;

    public:
        //Entidade();
        Entidade(sf::Vector2f posicao = { 0.f, 0.f }, sf::Vector2f tamanho = { 0.f, 0.f }, sf::Vector2f velocidade = { 0.f, 0.f });
        virtual ~Entidade();

        void setPosicao(sf::Vector2f pos);
        const sf::Vector2f getPosicao() const;

        void setTamanho(sf::Vector2f tam);
        const sf::Vector2f getTamanho() const;

        void setVelocidade(sf::Vector2f vel);
        const sf::Vector2f getVelocidade() const;

        virtual void renderizar() = 0;
        virtual void inicializar() = 0;
        virtual void atualizar() = 0;
        virtual void executar() = 0;
    };

}
