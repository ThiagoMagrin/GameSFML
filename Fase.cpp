#include "Fase.h"
#include "Jogador.h"
#include <time.h>
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

typedef struct Registro {
    string nome;
    int pts;
}Registro;

namespace Fases {
    Fase::Fase(bool doisJogadores) : Ente(0), pJogador(nullptr), pJogador2(nullptr), pFantasma(nullptr), pPedra(nullptr), texturaBG(), background(), pausado(false){
        sorteiaNumEnt();

        fonte.loadFromFile("times new roman.ttf");

        textoVida.setFont(fonte);
        textoVida.setPosition(0, 0);

        textoVida2.setFont(fonte);
        textoVida2.setPosition(0, 40);

        textoPause.setFont(fonte);
        textoPause.setCharacterSize(40);
        textoPause.setPosition(100, 100);
       
        pListaDinamica = new ListaEntidade();
        pListaEstatica = new ListaEntidade();
        pJogador = new Jogador();
        pPlataforma = new Plataforma({ 280.0f, 350.0f });
        pColisao = new GerenciadorColisao(pListaEstatica, pListaDinamica);

        Entidades::Entidade* jogador = static_cast<Entidades::Entidade*> (pJogador);
        Entidades::Entidade* plataforma = static_cast<Entidades::Entidade*> (pPlataforma);
      
        pListaDinamica->adicionarEntidade(jogador);
        pListaEstatica->adicionarEntidade(plataforma);
        if (doisJogadores) {

            criarJogador2();
        }
        else {
            pJogador2 = nullptr;
        }
        criarFantasmas();
        criarPedras();
    }

    Fase::~Fase() {}

    void Fase::sorteiaNumEnt() {
        numEnt = rand() % 2 + 3;
    }

    void Fase::atualizaTexto() {
        std::string text;

        if(pJogador->getVida() < 0){
            pJogador->setVida(0);
        }

        text = "Vida Jogador 1: ";
        text += std::to_string(pJogador->getVida());
        text += " Pontuacao: ";
        text += std::to_string(pJogador->getPontuacao());
        textoVida.setString(text);

        if (pJogador2 != nullptr) {
            if(pJogador2->getVida() < 0){
                pJogador2->setVida(0);
            }

            text = "Vida Jogador 2: ";
            text += std::to_string(pJogador2->getVida());
            text += " Pontuacao: ";
            text += std::to_string(pJogador2->getPontuacao());
            textoVida2.setString(text);
        }
    }

    void Fase::criarFantasmas() {
        for (int i = 0; i < numEnt; i++) {
            pFantasma = new Fantasma();

            pFantasma->inicializar(pJogador, pJogador2);
            Entidades::Entidade* fantasma = static_cast<Entidades::Entidade*> (pFantasma);
            pListaDinamica->adicionarEntidade(fantasma);
        }
        std::cout << "FANTASMAS CRIADAS!\n";
    }

    void Fase::criarPedras() {
        for (int i = 0; i < numEnt; i++) {
            pPedra = new Pedra();

            pPedra->inicializar();
            Entidades::Entidade* Pedra = static_cast<Entidades::Entidade*> (pPedra);
            pListaEstatica->adicionarEntidade(Pedra);
        }
        std::cout << "PEDRAS CRIADAS!\n";
    }
}
    /* gravar pontuacao */

    bool compare(Registro& first, Registro second)
    {
        if (first.pts > second.pts) return true;
        else if (first.pts < second.pts) return false;
        return (first.pts < second.pts);
    }

    void Fases::Fase::GravarPontuacao(int pts)
    {
        std::list<Registro> lista;
        Registro aux;
        aux.pts = pts;

        std::cin >> aux.nome;

        std::cout << " jogador incluido - " << aux.nome << " " << aux.pts << "\n\n";
        lista.push_back(aux);

        //recupera arquivos e os coloca na lista
        std::ifstream Recupera("ranking.txt", std::ios::in);//in
        if (!Recupera)
        {
            std::cerr << " Arquivo não pode ser aberto" << std::endl;
            fflush(stdin);
            getchar();
        }
        std::cout << "REGISTROS RECUPERADOS!\n";
        while (!Recupera.eof()) {
            Recupera >> aux.nome >> aux.pts;
            lista.push_back(aux);
            std::cout << "nome: " << aux.nome << " pts: " << aux.pts << std::endl;
        }
        remove("ranking.txt");//limpa arquivo -  n esta funcionado
        Recupera.close();

        //grava no arquivo
        std::ofstream Grava("ranking.txt", std::ios::in);
        if (!Grava)
        {
            std::cerr << " Arquivo não pode ser aberto " << std::endl;
            fflush(stdin);
            return;
        }
        remove("ranking.txt");
        lista.sort(compare);
        std::cout << "REGISTRO ORDENADO \n ";
        for (std::list<Registro>::iterator it = lista.begin(); it != lista.end(); it++) {
            std::cout << "nome: " << (it)->nome << " pts: " << (it)->pts << std::endl;
            Grava << (it)->nome << ' ' << (it)->pts << "\n";
        }
        Grava.close();
    }

    void Fases::Fase::criarJogador2()
    {
       //std::cout << "CRIANDO SEGUNDO JOGADOR!";
        pJogador2 = new Jogador();
        Entidades::Entidade* jogador2 = static_cast<Entidades::Entidade*> (pJogador2);
        pListaDinamica->adicionarEntidade(jogador2);
        pJogador2->inicializar({120.0f, 490.0f});
        pJogador2->setSegundoJogador(true);
       //std::cout << "SEGUNDO JOGADOR CRIADO!";
    }
