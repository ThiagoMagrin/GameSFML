#include "Jogo.h"
#include "Fase_Terra.h"
#include "Fase_Gelo.h"
#include "Gerenciador_Grafico.h"
#include <list>
#include <iterator>
#include <fstream>

using namespace std;
using namespace Fases;

Jogo::Jogo() : Ente(0), dois_jogadores(false){
    Ente::setGraf(GerenciadorGrafico::getGerenciadorGrafico());

    srand(time(NULL));

    executar();
}

Jogo::~Jogo(){
    if(objFase_Terra){
        delete objFase_Terra;
    }
    objFase_Terra = nullptr;

    if(objFase_Gelo){
        delete objFase_Gelo;
    }
    objFase_Gelo = nullptr;

    GerenciadorGrafico::deletarGerenciadorGrafico();
}

void Jogo::executarFase1(bool doisJ){// AINDA NAO EH SELECIONADO PELO MENU
    dois_jogadores = doisJ;


    dois_jogadores = true;


    objFase_Terra = new Fase_Terra(dois_jogadores);
    objFase_Terra->executar();

    if(dois_jogadores == true){
        executarFase2(true, objFase_Terra->getJogador().getPontuacao(), objFase_Terra->getJogador2().getPontuacao());
    }
    else{
        executarFase2(false, objFase_Terra->getJogador().getPontuacao(), 0);
    }
}

void Jogo::executarFase2(bool doisJ, int p1, int p2){
    dois_jogadores = doisJ;
    dois_jogadores = true;
    objFase_Gelo = new Fase_Gelo(dois_jogadores);

    objFase_Gelo->executar(p1, p2);

    if(objFase_Gelo->getSobreviveram()){

        if(dois_jogadores == true){
            std::cout << "DIGITE O NOME DO JOGADOR 1: ";
            //objFase_Gelo->GravarPontuacao(objFase_Gelo->getJogador().getPontuacao());

            std::cout << "\nDIGITE O NOME DO JOGADOR 2: ";
            //objFase_Gelo->GravarPontuacao(objFase_Gelo->getJogador2().getPontuacao());
        }
        else{
            std::cout << "DIGITE O NOME DO JOGADOR 1: ";
            //objFase_Gelo->GravarPontuacao(objFase_Gelo->getJogador().getPontuacao());
        }

    }
}

void Jogo::executar()
{
    int op = 0;
    int ant = -1;
    while (pGraf->verificaJanelaAberta())
    {
        menu.run_menu();
        op = menu.getOpcao();
        if (ant != op) {
            switch (op) {
            case 1:
                executarFase1(true);
                break;
            case 2:
                executarFase2(false, 0, 0);
                break;
            case 3:
             //   InformarPontuacao();
                break;
            case 4:
                pGraf->fecharJanela();
                break;
            default:
                break;
            }
        }
        ant = menu.getOpcao();
    }
};

// *********************** ranking teste
//
//typedef struct Registro {
//    std::string nome;
//    int pts;
//}Registro;
//
//
//void Jogo::InformarPontuacao()
//{
//    Registro rec;
//    std::list<Registro> lista;
//
//    std::ifstream Recupera("ranking.txt", std::ios::app);
//    if (!Recupera)
//    {
//        std::cerr << " Arquivo não pode ser aberto" << std::endl;
//        fflush(stdin);
//        getchar();
//    }
//
//    std::cout << "\nLendo arquivo \n";
//    while (!Recupera.eof()) {
//        Recupera >> rec.nome >> rec.pts;
//        std::cout << "nome: " << rec.nome << " pts: " << rec.pts << std::endl;
//        lista.push_back(rec);
//    }
//
//    std::cout << "\n************* \n";
//    std::cout << "\nRANKING - TOP 5 \n";
//    int top = 5;
//    std::list<Registro>::iterator it = lista.begin();
//    for (int i = 0; i < top; i++) {
//        it++;
//        std::cout << "nome: " << (it)->nome << " pts: " << (it)->pts << std::endl;
//    }
//
//    Recupera.close();
//}

