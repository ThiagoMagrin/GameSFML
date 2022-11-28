#pragma once

#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Fantasma : public Inimigo
            {
            private:
                float assombracao;

            public:
                Fantasma();
                ~Fantasma();

                void inicializar(Jogador *pJ, Jogador *pJ2);
                void movimentoEspecifico();
                void assombrar(bool a = false);
                void tratarColisao(Entidade *outraEntidade);
                void executar();
            };
        }
    }
}
