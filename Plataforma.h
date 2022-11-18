#pragma once
#include "Entidade.h"

namespace Entidades{
    class Plataforma : public Entidade{
        private:

        public:
            Plataforma(sf::Vector2f pos);
            ~Plataforma();

            void colisao(Entidade* outraEntidade);
            void executar();
            void imprimir();
    };
}

