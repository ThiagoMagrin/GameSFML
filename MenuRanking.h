#pragma once
#include "Menu.h"

class MenuRanking : public Menu
{
private:
    std::vector<std::string> dados;

public:
    MenuRanking();
    ~MenuRanking();

    void inicializar();
    void tratarEscolha(int escolha) {}
    void recuperaDados();
};