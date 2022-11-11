#include "Fase.h"
#include "Jogador.h"

namespace Fases{
    Fase::Fase(): pJogador(), pEsqueleto(), pChefao(), pAranha(), pPedra(), pEspinho(), pTronco(), pListaDinamica(), pListaEstatica(), pColisao(){}
    Fase::~Fase(){
        if(pJogador){
            delete(pJogador);
            pJogador = nullptr;
        }

        if(pEsqueleto){
            delete(pEsqueleto);
            pEsqueleto = nullptr;
        }

        if(pChefao){
            delete(pChefao);
            pChefao = nullptr;
        }

        if(pAranha){
            delete(pAranha);
            pAranha = nullptr;
        }

        if(pPedra){
            delete(pPedra);
            pPedra = nullptr;
        }

        if(pEspinho){
            delete(pEspinho);
            pEspinho = nullptr;
        }

        if(pTronco){
            delete(pTronco);
            pTronco = nullptr;
        }
        if(pListaDinamica){
            delete(pListaDinamica);
            pListaDinamica = nullptr;
        }
        if(pListaEstatica){
            delete(pListaEstatica);
            pListaEstatica = nullptr;
        }
        if(pColisao){
            delete(pColisao);
            pColisao = nullptr;
        }
    }
}
