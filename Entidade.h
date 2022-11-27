#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

#define GRAVIDADE 9.98f

class Personagem;

namespace Entidades {
    class Entidade : public Ente {
        protected:
            sf::Vector2f posicao, tamanho;
            sf::Sprite corpo;
            sf::Texture textura;

            
            int vida, dano;
            bool morreu, chao, atingiu;

        public:
            Entidade();
            virtual ~Entidade();

            void setPosicao(sf::Vector2f pos);
            const sf::Vector2f getPosicao() const;
            void setTamanho(sf::Vector2f tam);
            const sf::Vector2f getTamanho() const;
            sf::Sprite getCorpo();
            sf::Vector2f posicaoAleatoria(int tipo);

            
            void setVida(int v);       
            const int getVida() const;
            void setDano(int d);
            const int getDano() const;
            void setMorrer(bool m);
            const bool getMorrer() const;
            void setChao(bool b);
            const bool getChao() const;
            void setAtingiu(bool b);
            const bool getAtingiu() const;

            virtual void tratarColisao(Entidade* outraEntidade) = 0;
            void imprimir() ;
            virtual void executar() = 0;
            void cair(float intensificador);        
           
        };
}
