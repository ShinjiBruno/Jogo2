#include "Fase.h"

Fase::Fase(Jogador* jog, sf::RenderWindow* w) {
	jogador = jog;
	window = w;

	inim = new Inimigo();
	inim->setWindow(window);

	plat = new Plataforma();
	plat->setWindow(window);

	plat->configuraPlataforma(sf::Vector2f(1000, 50), sf::Vector2f(550, 650));

	lisEnt = new ListaEntidades();
	lisPerso = new ListaPersonagem();

	criaListas();

}

Fase::~Fase() {
	delete lisEnt;
}

void Fase::gerenciaColisao() {
	int i;
	gerenciaCol.colisaoInimigo(jogador, inim);
	gerenciaCol.colisaoVisao(jogador, inim);
	for (i = 0; i < lisPerso->LPs.getQuant(); i++) {
		Personagem* tmp = lisPerso->LPs.getItem(i);
		gerenciaCol.colisaoPlataforma(tmp, plat);
		
	}
}

void Fase::gravidade() {
	for (int i = 0; i < lisEnt->LEs.getQuant(); i++) {
		Entidade* tmp = lisEnt->LEs.getItem(i);

		if (tmp->EhPersonagem() == true)
            tmp->getShape()->move(sf::Vector2f(0.0f, 0.2f));
	}
}


void Fase::criaListas() {

	//LISTA ENTIDADES
	lisEnt->LEs.push(jogador);
	lisEnt->LEs.push(inim);
	lisEnt->LEs.push(plat);

	lisPerso->LPs.push(jogador);
	lisPerso->LPs.push(inim);

}
;


void Fase::drawFase() {
	for (int i = 0; i < lisEnt->LEs.getQuant(); i++) {
		Entidade* tmp = lisEnt->LEs.getItem(i);
		tmp->drawEntidade();
	}
}

void Fase::executa() {
	jogador->executa();
	inim->executa();
	gravidade();
	gerenciaColisao();
	drawFase();
}

