#pragma once
#include "Entidade.h"

namespace Entidades
{
    class Plataforma : public Entidade
    {
    private:
    public:
        Plataforma();
        Plataforma(sf::Vector2f pos);
        ~Plataforma();

        void tratarColisao(Entidade *outraEntidade);
        void executar();
        void imprimir();
    };
}
