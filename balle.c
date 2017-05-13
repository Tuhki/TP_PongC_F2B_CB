#include "declaBalle.h"

void renderBalle(game *myGame,Cercle *balle ) {
//BUT    : Dessiner la balle
//ENTREE : Coordonnées de la balle
//SORTIE : Affichage de la balle à sa nouvelle position

        int i;
        SDL_Point Point1;
        SDL_SetRenderDrawColor(myGame->g_pRenderer,255,255,255,0);

        //On trace le cercle
        for (i=0; i<361 ;i++){
            Point1.x=balle->x+balle->r*cos(i);
            Point1.y=balle->y+balle->r*sin(i);

            SDL_RenderDrawPoint(myGame->g_pRenderer,Point1.x,Point1.y);
        }

}

void mouvBalle(Cercle *balle){
//BUT    : Changer le mouvement de la balle
//ENTREE : Direction de la balle
//SORTIE : Modification du mouvement de la balle

    //Vers le bas et droite
    if(balle->dir == 1){

        balle->y++;
        balle->x++;
        balle->y++;
        balle->x++;

    }

    //Vers le haut et droite
    if(balle->dir == 2){

        balle->y--;
        balle->x++;
        balle->y--;
        balle->x++;

    }

    //Vers le bas et gauche
    if(balle->dir == 3){

        balle->y++;
        balle->x--;
        balle->y++;
        balle->x--;

    }

    //Vers le haut et gauche
    if(balle->dir == 4){

        balle->y--;
        balle->x--;
        balle->y--;
        balle->x--;

    }

}

void placeBalle(Cercle *balle, coordonnees *dep, coordonnees *dep2, int *scoreJG, int *scoreJD, Score *gameScore){
//BUT    : Changer la direction de la balle
//ENTREE : Coordoonées de la balle
//SORTIE : Changement de direction

    //Touche bas venant de gauche OU touche la raquette gauche en venant de bas
    if(((balle->y >= SCREEN_HEIGHT - balle->r)&&(balle->dir == 1))
       ||((balle->x <= (dep->x + dep->w + balle->r)) && (balle->y >= dep->y) && (balle->y <= dep->y + dep->h)&&(balle->dir == 4))){

        balle->dir = 2;

    }

    //Touche bas venant de droite OU touche la raquette droite en venant du bas
    if(((balle->y >= SCREEN_HEIGHT - balle->r)&&(balle->dir == 3))
       ||((balle->x >= dep2->x - balle->r) && (balle->y >= dep2->y) && (balle->y <= dep2->y + dep->h)&&(balle->dir == 2))){

        balle->dir = 4;

    }

     //Touche haut venant de droite OU touche la raquette droite en venant du haut
    if(((balle->y <= 0 + balle->r)&&(balle->dir == 4))
       ||((balle->x >= dep2->x - balle->r)&& (balle->y >= dep2->y) && (balle->y <= dep2->y + dep->h)&&(balle->dir == 1))){

        balle->dir = 3;

    }

     //Touche la raquette gauche en venant du haut OU touche haut venant de gauche
    if(((balle->x <= dep->x + dep->w + balle->r) && (balle->y >= dep->y) && (balle->y <= dep->y + dep->h)&&(balle->dir == 3))
        ||((balle->y <= 0 + balle->r)&&(balle->dir == 2))){

        balle->dir = 1;

    }

    //Le joueur marque à gauche
    if(balle->x <= 0){

        balle->x = SCREEN_WIDTH/2;
        balle->y = SCREEN_HEIGHT/2;
        balle->dir = 1;

        gameScore->posBal = GAUCHE;

    }

    //Le joueur marque à droite
    if(balle->x >= SCREEN_WIDTH){

        balle->x = SCREEN_WIDTH/2;
        balle->y = SCREEN_HEIGHT/2;
        balle->dir = 3;

        gameScore->posBal = DROITE;

    }
}

