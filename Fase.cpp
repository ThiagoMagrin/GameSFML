#include "Fase.h"
#include "Jogador.h"

namespace Fases{
    Fase::Fase(): pJogador() {}
    Fase::~Fase(){
        if(pJogador){
            delete(pJogador);
            pJogador = nullptr;
        }
        if(pInimigo1){
            delete(pJogador);
            pJogador = nullptr;
        }
        if(pInimigo2){
            delete(pJogador);
            pJogador = nullptr;
        }
    }
}
