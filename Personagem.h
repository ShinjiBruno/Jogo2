#pragma once
#include "Entidade.h"

class Personagem: public Entidade
{
protected:
	float veloc;
	bool jump;
    float impulso;

	sf::CircleShape visao;

public:
	Personagem();
	~Personagem();

    void pula();
	float getVeloc() { return veloc;  }
	bool getJump() {return jump; }
	void setJump(bool j) { jump = j; }


	sf::CircleShape getVisao() { return visao; }

	virtual void  move() = 0;
	virtual void executa() = 0;
};

