#pragma once

namespace Listas{
    template <class TIPO>
    class Lista
    {
    public:
        template <class TIPO>
        class Elemento
        {
        private:
            TIPO* pTipo;
            Elemento <TIPO> *pProx;
        public:
            Elemento() { pProx = NULL; pTipo = NULL; pAnte = NULL; }
            ~Elemento() { pTipo = NULL; pProx = NULL; }

            void setTipo(TIPO* ptipo) { pTipo = ptipo; }
            TIPO* getTipo() { return pTipo; }

            void setProx(Elemento* p) { pProx = p; }
            Elemento <TIPO>* getProx() { return pProx; }
        };

    private:

        Elemento <TIPO>* pPrimeiro;
        Elemento <TIPO>* pUltimo;

    public:
        Lista();
        ~Lista();

        void getInicio(){
            return pPrimeiro;
        }

        void incluaTipo(TIPO* ptipo);
        void percorrer();
        void remover(TIPO* ptipo);
        int tamanho();
    };

    template<class TIPO>
    inline Lista<TIPO>::Lista()
    {
        pPrimeiro = NULL;
        pUltimo = NULL;
    }

    template<class TIPO>
    inline Lista<TIPO>::~Lista()
    {
        Elemento <TIPO>* pAux = NULL;

        pAux = pPrimeiro;

        while (pAux != NULL)
        {
            pPrimeiro = pPrimeiro->getProx();
            delete pAux;
            pAux = NULL;
            pAux = pPrimeiro;
        }
        pAux = NULL;
        pPrimeiro = NULL;
        pUltimo = NULL;
    }

    template<class TIPO>
    inline void Lista<TIPO>::incluaTipo(TIPO* ptipo){
        Elemento <TIPO>* pAux = NULL;

        pAux = new Elemento<TIPO>();
        pAux->setTipo(ptipo);

        if (pPrimeiro == NULL)
        {
            pPrimeiro = pAux;
            pUltimo = pAux;
        }
        else
        {
            pUltimo->setProx(pAux);
            pAux->setAnte(pUltimo);
            pUltimo = pAux;
        }
    }

    template<class TIPO>
    inline TIPO* Lista<TIPO>::percorrer(){
        Elemento<TIPO>* pAux = getInicio();
        while(pAux->proximo!=NULL){
            tipo* pAux2 = pAtual->getTipo();
            pAux2->executar();
            pAux2->imprimir();
            pAux = pAux->getProx();
        }

        delete pAux, pAux2;
    }

    template<class TIPO>
    inline int Lista<TIPO>::tamanho()
    {
        Elemento <TIPO>* pAux = NULL;
        int tamanho = 0;

        pAux = pPrimeiro;

        while (pAux != NULL)
        {
            tamanho++;
            pAux = pAux->getProx();
        }

        return tamanho;
    }

    template<class TIPO>
    inline void Lista<TIPO>::limparTudo()
    {
        Elemento <TIPO>* pAux = NULL;

        pAux = pPrimeiro;

        while (pAux != NULL && pAux->getTipo() != NULL)
        {
            pPrimeiro = pPrimeiro->getProx();
            delete pAux;
            pAux = NULL;
            pAux = pPrimeiro;
        }
        pAux = NULL;
        pPrimeiro = NULL;
        pUltimo = NULL;
        pAtual = NULL;
    }

    template<class TIPO>
    inline void Lista<TIPO>::remover(TIPO* ptipo)
    {
        Elemento <TIPO>* pAux = NULL;
        TIPO* pE = NULL;

        pAux = pPrimeiro;

        while (pAux != NULL && pAux->getTipo() != ptipo){
            pAux = pAux->getProx();
        }

        pE = pAux->getTipo();

        if (pAux->getAnte() != NULL)
            pAux->getAnte()->setProx(pAux->getProx());
        else
        {
            pPrimeiro = pAux->getProx();
            pPrimeiro->setAnte(NULL);
        }
        if (pAux->getProx() != NULL)
            pAux->getProx()->setAnte(pAux->getAnte());
        else
        {
            pUltimo = pAux->getAnte();
            pUltimo->setProx(NULL);
        }
        delete pE;
        delete pAux;
    }

    template<class TIPO>
    inline void Lista<TIPO>::percorrer(){

    }
}
