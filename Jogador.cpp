#include "Jogador.h"

#define VIDAJOGADOR 5000
#define DANOJOGADOR 3
#define VELJOGADOR 0.2f
#define PULOJOGADOR 70.0f

namespace Entidades {
    namespace Personagens {
        Jogador::Jogador() : Personagem(), pontuacao(0){
            Ente::setID(1);
        }

        Jogador::~Jogador() {}

        void Jogador::inicializar(){
            setVida(VIDAJOGADOR);
            setDano(DANOJOGADOR);

            velocidade = {VELJOGADOR,VELJOGADOR};
            posicao = {50.0f, 490.0f};

            textura = pGraf->carregarTextura("images/Jogador.png");
            corpo.setTexture(textura, true);
            corpo.setPosition(posicao);

            std::cout << "Jogador inicializado" << std::endl;
        }

        void Jogador::movimento(){
            float posJ = getPosicao().x;

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && esquerda == true && posJ > 0.0f){
                corpo.move(-velocidade.x, 0.0f);
            }

            else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && direita == true && posJ < 1200.0f - 50.0f){
                corpo.move(velocidade.x, 0.0f);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)  || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if(chao == true){
                    pular(PULOJOGADOR);
                    chao = false;
                }
            }

            if(chao == false){
                cair(0.07f);
            }
        }

        void Jogador::executar() {
            posicao = corpo.getPosition();

            if ((posicao.y >= 490.0f)){
                chao = true;
            }
            movimento();
        }

        void Jogador::colisao(Entidade* outraEntidade){
            switch(outraEntidade->getId()){
                case 1:{
                    //std::cout << "Colisao jogador e jogador" << std::endl;
                    break;
                }
                case 2:{
                    outraEntidade->setVida(-DANOJOGADOR);
                    setVida(-outraEntidade->getDano());
                    std::cout << "Combate Jogador x Inimigo - Vida Jogador: " << getVida() << " Vida Inimigo: " << outraEntidade->getVida() << std::endl;

                    if(getVida() <= 0){
                        setMorrer(true);
                    }

                    if(outraEntidade->getVida() <= 0){
                        outraEntidade->setMorrer(true);
                    }

                    if(outraEntidade->getPosicao().x > posicao.x){
                        direita = false;
                        outraEntidade->setEsquerda(false);
                    }
                    else{
                        esquerda = false;
                        outraEntidade->setDireita(false);
                    }

                    break;
                }
                case 3:{
                    setVida(-outraEntidade->getDano());
                    std::cout << "Colidiu com obstaculo - Vida Jogador: " << getVida() << std::endl;

                    if(getVida() <= 0){
                        setMorrer(true);
                    }

                    break;
                }
                case 4:{
                    if(outraEntidade->getPosicao().y - 110 > posicao.y){
                        chao = true;
                    }
                    break;
                }
                case 5:{
                    setVida(-outraEntidade->getDano());
                    std::cout << "Vida Jogador: " << getVida() << std::endl;
                    outraEntidade->setAtingiu(true);

                    break;
                }
            }
        }

        void Jogador::setPontuacao(int p) {
            pontuacao += p;
        }

        const int Jogador::getPontuacao() const {
            return pontuacao;
        }
    }
}
