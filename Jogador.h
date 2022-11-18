#pragma once
#include "Personagem.h"

namespace Entidades{
        namespace Personagens{
            class Jogador : public Personagem{
                private:
                    int pontuacao;

                public:
                    Jogador();
                    ~Jogador();

                    void setPontuacao(int p);
                    const int getPontuacao() const;

                    void movimento();
                    void inicializar();
                    void executar();

                    void colisao(Entidade* outraEntidade);
                };
        }
}
