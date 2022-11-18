
#pragma once
#include "Entidade.h"

namespace Entidades {

    class BolaDeFogo :
        public Entidade
    {
    private:
        sf::Vector2f posicaoChefao, velocidade;
        bool lancado;

    public:

        BolaDeFogo();
        ~BolaDeFogo();

        const bool getLancado() {
            return lancado;
        }

        void setLancado(bool b){
            lancado = b;
        }

        void apagar();
        void inicializar();
        void resetar(sf::Vector2f p);
        void lancar(bool esquerda);
        void executar(){}
    };
}
