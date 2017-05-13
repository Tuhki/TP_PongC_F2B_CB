#ifndef DECLABALLE_H_INCLUDED
#define DECLABALLE_H_INCLUDED

#include "init.h"

void renderBalle(game *myGame,Cercle *balle );
void mouvBalle(Cercle *balle);
void placeBalle(Cercle *balle, coordonnees *dep, coordonnees *dep2, int *scoreJG, int *scoreJD, Score *gameScore);

#endif // DECLABALLE_H_INCLUDED
