#pragma once
#include "elemento.h"


template <class LIST> class Lista
{
private:
    Elemento<LIST>* pPrimeiro;
    Elemento<LIST>* pUltimo;
    int quant;

public:
    Lista();
    ~Lista();

    int getQuant(){return quant; }

    Elemento<LIST>* getPrimeiro() { return pPrimeiro; }

    LIST* getItem(int posicao){
        Elemento<LIST>* temp = pPrimeiro;
        if (posicao == 0)
            return temp->getItem();
        for (int i=0; i<posicao; i++){
            temp = temp->getProx();
        }
        return temp->getItem();
    }

    void push(LIST* it){
        if (pPrimeiro == NULL){
            pPrimeiro = new Elemento<LIST>;
            pPrimeiro->setItem(it);
            pUltimo = pPrimeiro;
        }
        else {
         Elemento<LIST>* temp = new Elemento<LIST>;
         temp->setItem(it);
         pUltimo->setProx(temp);
         pUltimo = temp;
        }
        quant++;
    }

    void pop(LIST* it){
        Elemento<LIST>* temp = pPrimeiro;
        Elemento<LIST>* tempAnt = NULL;

        while(temp->getItem()!= it){
            tempAnt = temp;
            temp = temp->getProx();
        }
        if (temp == pPrimeiro){
            pPrimeiro = temp->getProx();
        }
        else if (temp == pUltimo){
            tempAnt->setProx(NULL);
            pUltimo = tempAnt;
        }
        else {
            tempAnt->setProx(temp->getProx());
        }
        delete temp;
        quant--;
    }

};

template <class LIST>
inline Lista<LIST>::Lista()
{
    pPrimeiro = NULL;
    pUltimo = NULL;
    quant = 0;
}

template <class LIST>
inline Lista<LIST>::~Lista()
{

}
