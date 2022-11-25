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
            bool atingiu, morreu;

        public:
            Entidade();
            virtual ~Entidade();
            void setPosicao(sf::Vector2f pos);
            const sf::Vector2f getPosicao() const;
            void setTamanho(sf::Vector2f tam);
            const sf::Vector2f getTamanho() const;
            sf::Sprite getCorpo();
            sf::Vector2f posicaoAleatoria(int tipo);
            void setAtingiu(bool b);
            bool getAtingiu();
            int getVida();
            void setVida(int v);
            int getDano();
            void setDano(int d);
            //virtual void setPontuacao(int p) {}
            //virtual const int getPontuacao() const{
            //    return 0;
            //}
            virtual void setChao(bool b) {}
            virtual void setDireita(bool b) {};
            virtual void setEsquerda(bool b) {};
            virtual void tratarColisao(Entidade* outraEntidade) {}
            virtual void imprimir();
            virtual void executar();
            void cair(float intensificador);
            void setMorrer(bool m);
            bool getMorrer();
        };
}
