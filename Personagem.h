#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "Entidade.h"

namespace Entidades{
    namespace Personagens{
        class Personagem : public Entidade {
        protected:
            int vida, dano;
            bool chao, morrer;
        public:
            Personagem();
            ~Personagem();

            void setVida(int v);
            const int getVida() const;

            void setDano(int d);
            const int getDano() const;
        };
    }
}
