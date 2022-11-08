#include "Colisor.h"

Colisor::Colisor() {
	colidiu = false;
}

Colisor::~Colisor() {}


void Colisor::colisaoInimigo(Jogador* jog, Inimigo* inim) {

	float raioJogX = jog->getShape()->getPosition().x + jog->getShape()->getSize().x / 2;
	float raioInimX = inim->getShape()->getPosition().x + inim->getShape()->getSize().x / 2;
	float raioJogY = jog->getShape()->getPosition().y + jog->getShape()->getSize().y / 2;
	float raioInimY = inim->getShape()->getPosition().y + inim->getShape()->getSize().y / 2;

	float difJogX = jog->getShape()->getPosition().x - jog->getShape()->getSize().x / 2;
	float difInimX = inim->getShape()->getPosition().x - inim->getShape()->getSize().x / 2;
	float difJogY = jog->getShape()->getPosition().y - jog->getShape()->getSize().y / 2;
	float difInimY = inim->getShape()->getPosition().y - inim->getShape()->getSize().y / 2;

	float posCentJog = jog->getShape()->getPosition().x;
	float posCentIni = inim->getShape()->getPosition().x;

	if ((raioJogX > difInimX
		&& difJogX < raioInimX
		&& raioJogY > difInimY
		&& difJogY < raioInimY)
		) {

		if (posCentJog < posCentIni) {
			jog->getShape()->move(-70.0f, 0.0f);
		}
		if (posCentJog > posCentIni) {
			jog->getShape()->move(70.0f, 0.0f);
		}

		jog->getShape()->move(0.0f, -40.0f);
	}

}

//void Colisor::empurra(Personagem* perso, float impulso)

void Colisor::colisaoVisao(Jogador* jog, Inimigo* inim) {
	float dx = jog->getVisao().getPosition().x - inim->getVisao().getPosition().x;
	float dy = jog->getVisao().getPosition().y - inim->getVisao().getPosition().y;

	float raioJog = jog->getVisao().getRadius();
	float raioInim = inim->getVisao().getRadius();

	float distancia = sqrt(dx*dx + dy*dy);

	int direita = 2;
	int esquerda = 1;

	if (distancia < raioJog + raioInim) {
		if(dx < 0){
			inim->setDirec(esquerda);
		}
		else {
			inim->setDirec(direita);
		}

	}
	else {
		inim->setDirec(0);
	}

}


void Colisor::colisaoPlataforma(Personagem* perso, Plataforma* plat) {

	sf::Vector2f posPerso = perso->getShape()->getPosition();
	sf::Vector2f raioPerso(perso->getShape()->getSize().x / 2, perso->getShape()->getSize().y / 2);
	sf::Vector2f posPlat = plat->getShape()->getPosition();
	sf::Vector2f raioPlat(plat->getShape()->getSize().x / 2, plat->getShape()->getSize().y / 2);


	float deltaPosX = posPlat.x - posPerso.x;
	float deltaPosY = posPlat.y - posPerso.y; //diferenca entre posicoes


	float deltaFisX = abs(deltaPosX) - raioPerso.x - raioPlat.x; //diferenca entre superficies
	float deltaFisY = abs(deltaPosY) - raioPerso.y - raioPlat.y;

	if (deltaFisX < 0.0f && deltaFisY < 0.0f) {
		if (deltaFisX > deltaFisY) {
			if (deltaPosX > 0.0f) {
				perso->getShape()->move(sf::Vector2f(deltaFisX, 0.0f));
				perso->setJump(false);
			}
			else {
				perso->getShape()->move(sf::Vector2f(-deltaFisX, 0.0f));
				perso->setJump(false);
			}
		}
		else {
			if (deltaPosY > 0.0f) {
				perso->getShape()->move(sf::Vector2f(0.0f, deltaFisY));
				perso->setJump(false);
			}
			else {
				perso->getShape()->move(sf::Vector2f(0.0f, -deltaFisY));
			}

		}
		colidiu = true;
	}
}
