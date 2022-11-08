#pragma once

template <class ELEM> class Elemento
{
private:
    Elemento <ELEM>* pProx;
    ELEM* item;

public:
    Elemento();
    ~Elemento();

    void setProx(Elemento<ELEM>* prox){this->pProx = prox; }
    void setItem(ELEM* it) {this->item = it; }
    Elemento<ELEM>* getProx() {return pProx; }
    ELEM* getItem (){return item; }
};

template<class ELEM>
inline Elemento<ELEM>::Elemento()
{
    pProx = NULL;
    item = NULL;
}
template<class ELEM>
inline Elemento<ELEM>::~Elemento()
{

}
