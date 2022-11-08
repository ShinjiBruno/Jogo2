#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include <list>
#include <vector>

using namespace std;

class Colisor
{
private:
    bool colidiu;
	vector<Inimigo*> lisInim;
	list<Plataforma*> lisPlat;
	list<Jogador*> lisJog;
	

public:
	Colisor();
	~Colisor();

    //void empurra(Personagem* perso, float imp);
	void colisaoInimigo(Jogador* jog,Inimigo* inim);
	void colisaoPlataforma(Personagem* perso, Plataforma* plat);
	void colisaoVisao(Jogador* jog, Inimigo* inim);

	void pushJogador(Jogador* j) { lisJog.push_front(j); }
	void pushInimigo(Inimigo* i) { lisInim.push_back(i); }
	void pushPlataforma(Plataforma* p) { lisPlat.push_back(p); }

	
};
