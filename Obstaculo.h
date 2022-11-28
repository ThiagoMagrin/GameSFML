#pragma once
#include "Entidade.h"
#include "Personagem.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
        protected:
            bool causaDano;

        public:
            Obstaculo();
            virtual ~Obstaculo();
            virtual void inicializar() = 0;
            virtual void executar();
            void setCausaDano(bool b);
            const bool getCausaDano();
            void tratarColisao(Entidade *outraEntidade);
            virtual void obstacular(Entidade *outraEntidade) = 0;
        };
    }
}
