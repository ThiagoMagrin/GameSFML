#include "Fase.h"
#include "Jogador.h"

namespace Fases{
    Fase::Fase(): pJogador(){}
    Fase::~Fase(){
        if(pJogador){
            delete(pJogador);
            pJogador = nullptr;
        }
        if(pInimigo1){
            delete(pJogador);
            pInimigo1 = nullptr;
        }
        if(pInimigo2){
            delete(pInimigo2);
            pInimigo2 = nullptr;
        }
        if(pInimigo3){
            delete(pInimigo3);
            pInimigo3 = nullptr;
        }
    }
}
