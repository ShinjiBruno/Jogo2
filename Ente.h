#pragma once
#include "Grafico.h"

class Ente {
private:
	int id;
	Grafico* g_graf;
public:
	Ente();
	~Ente();

	virtual void executa();
	void imprimir() { g_graf->getWindow()->display(); }
};