#include "Entidade.h"
#include <time.h>

namespace Entidades
{
    Entidade::Entidade() : Ente(0), chao(false), posicao({0.f, 0.f}), tamanho({0.f, 0.f}), corpo(), textura(), vida(0), dano(0), atingiu(false), morreu(false) {}

    Entidade::~Entidade() {}

    void Entidade::setPosicao(sf::Vector2f pos)
    {
        posicao = pos;
    }

    const sf::Vector2f Entidade::getPosicao() const
    {
        return posicao;
    }

    void Entidade::setTamanho(sf::Vector2f tam)
    {
        tamanho = tam;
    }

    const sf::Vector2f Entidade::getTamanho() const
    {
        return tamanho;
    }

    sf::Sprite Entidade::getCorpo()
    {
        return corpo;
    }

    sf::Vector2f Entidade::posicaoAleatoria(int tipo)
    {
        // PEGAR POSICAO DA PLATAFORMA OU DO CHAO
        // Plataforma {280.0f, 280.0f}
        // chao (700.0f, 530.0f}
        float x, y;

        if (tipo == 0)
        {
            x = static_cast<float>(rand() % 740 + 250);
            y = 280;
        }

        else
        {
            x = static_cast<float>(rand() % 600 + 370);
            y = 530;
        }

        return sf::Vector2f(x, y);
    }

    void Entidade::setChao(bool b)
    {
        chao = b;
    }

    void Entidade::imprimir()
    {
        pGraf->desenhaElemento(corpo);
    }

    void Entidade::setMorreu(bool m)
    {
        morreu = m;
    }

    bool Entidade::getMorreu()
    {
        return morreu;
    }

    void Entidade::executar() {}

    void Entidade::cair(float intensificador)
    {
        // Equacao da velocidade do corpo na queda livre: V = G*T
        // fonte: https://brasilescola.uol.com.br/fisica/queda-livre.htm#Equa%C3%A7%C3%A3o+de+Torricelli
        float velQueda;
        float t = 1; // TEMPO em segundos
        velQueda = intensificador * (GRAVIDADE * t);
        corpo.move(0, velQueda);
    }

    void Entidade::setAtingiu(bool b)
    {
        atingiu = b;
    }

    bool Entidade::getAtingiu()
    {
        return atingiu;
    }

    int Entidade::getVida()
    {
        return vida;
    }

    void Entidade::setVida(int v)
    {
        vida += v;
    }

    int Entidade::getDano()
    {
        return dano;
    }

    void Entidade::setDano(int d)
    {
        dano = d;
    }

    void Entidade::danar(Entidade *outraEntidade)
    {
        if (outraEntidade->getMorreu() == false)
        {
            outraEntidade->setVida(-getDano());
            if (outraEntidade->getVida() <= 0)
            {
                outraEntidade->setMorreu(true);
            }
        }
    }
}
