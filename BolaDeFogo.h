#pragma once
#include "Entidade.h"

namespace Entidades
{
    class BolaDeFogo : public Entidade
    {
    private:
        sf::Vector2f velocidade;
        bool lancado;

    public:
        BolaDeFogo();
        ~BolaDeFogo();

        const bool getLancado();
        void setLancado(bool b);
        void apagar();
        void inicializar();
        void resetar(sf::Vector2f p);
        void lancar(bool esquerda);
        void executar() {}
    };
}
