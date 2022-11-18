#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

#define GRAVIDADE 9.98f

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
            sf::Vector2f posicaoAleatoria(float inicio = 200);

            void setAtingiu(bool b){
                atingiu = b;
            }

            bool getAtingiu(){
                return atingiu;
            }

            int getVida(){
                return vida;
            }

            void setVida(int v) {
                vida += v;
            }

            int getDano(){
                return dano;
            }

            void setDano(int d){
                dano = d;
            }

            virtual void setChao(bool b) {}
            virtual void setDireita(bool b) {}
            virtual void setEsquerda(bool b) {}

            virtual void colisao(Entidade* outraEntidade) {}
            virtual void imprimir();
            virtual void executar();

            void cair(float intensificador);

            void setMorrer(bool m);
            bool getMorrer();
        };
}
