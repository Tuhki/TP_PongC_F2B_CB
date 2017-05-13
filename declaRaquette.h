#ifndef DECLARAQUETTE_H_INCLUDED
#define DECLARAQUETTE_H_INCLUDED

#include "init.h"

void handleEvents(gameState *state, EtatRaquette *raq1,  EtatRaquette *raq2);
void renderTexture(game *myGame,coordonnees *dep,coordonnees *dep2 );
void gestionEtat(coordonnees *dep, coordonnees *dep2, EtatRaquette *raq1, EtatRaquette *raq2);

#endif // DECLARAQUETTE_H_INCLUDED
