#pragma once
#include "Personagem.h"

namespace Entidades{
        namespace Personagens{
            class Jogador : public Personagem{
                private:
                    int pontuacao;

                public:
                    Jogador();
                    Jogador(const sf::Vector2f pos, sf::Vector2f tam);
                    ~Jogador();
                    void setPontuacao(int p);
                    const int getPontuacao() const;
                    void movimento();
                    void atualizar();
                    void inicializar();
                    void renderizar();
                    void executar();
                    void cair();
                };
        }
}
