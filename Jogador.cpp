#include "Jogador.h"

#define VIDAJOGADOR 3000
#define DANOJOGADOR 5
#define VELJOGADOR 1.2f
#define PULOJOGADOR 70.0f

namespace Entidades {
    namespace Personagens {
        Jogador::Jogador() : Personagem(), pontuacao(0), segundoJogador(false){
            Ente::setID(1);
        }

        Jogador::~Jogador() {}

        void Jogador::inicializar(sf::Vector2f pos){
            setVida(VIDAJOGADOR);
            setDano(DANOJOGADOR);

            velocidade = {VELJOGADOR,VELJOGADOR};
            posicao = pos;

            textura = pGraf->carregarTextura("images/Jogador.png");
            corpo.setTexture(textura, true);
            corpo.setPosition(posicao);

            std::cout << "Jogador inicializado" << std::endl;
        }

        void Jogador::movimento(){
            float posJ = getPosicao().x;

            if(segundoJogador == false){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && posJ > 0.0f){
                    if(esquerda == true){
                        corpo.move(-velocidade.x, 0.0f);
                    }
                    else{
                        esquerda = true;
                    }
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && posJ < 1200.0f - 50.0f){
                    if(direita == true){
                        corpo.move(velocidade.x, 0.0f);
                    }
                    else{
                        direita = true;
                    }
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    if(chao == true){
                        pular(PULOJOGADOR);
                        chao = false;
                    }
                }
            }

            else{
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && posJ > 0.0f){
                    if(esquerda == true){
                        corpo.move(-velocidade.x, 0.0f);
                    }
                    else{
                        esquerda = true;
                    }
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && posJ < 1200.0f - 50.0f){
                    if(direita == true){
                        corpo.move(velocidade.x, 0.0f);
                    }
                    else{
                        direita = true;
                    }
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    if(chao == true){
                        pular(PULOJOGADOR);
                        chao = false;
                    }
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

        void Jogador::tratarColisao(Entidade* outraEntidade){
            switch(outraEntidade->getId()){
                case 1:{
                    //std::cout << "Colisao jogador e jogador" << std::endl;
                    break;
                }
                case 2:{
                    if(outraEntidade->getVida() <= 0){
                        outraEntidade->setMorrer(true);
                    }
                    else{
                        outraEntidade->setVida(-DANOJOGADOR);
                        setVida(-outraEntidade->getDano());
                        setPontuacao(1);
                    }

                    break;
                }
                case 3:{
                    setVida(-outraEntidade->getDano());

                    if(outraEntidade->getPosicao().x > posicao.x){
                        setDireita(false);
                    }

                    else{
                        setEsquerda(false);
                    }

                    if(outraEntidade->getPosicao().y - 110 > posicao.y){
                        setDireita(true);
                        setEsquerda(true);
                        setChao(true);
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
                    outraEntidade->setAtingiu(true);

                    break;
                }

            }
            if(getVida() <= 0){
                setMorrer(true);
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
