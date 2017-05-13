#include "declaScore.h"

void gestScore(Score *gameScore){
//BUT   : Calculer le score
//ENTREE: Position de la balle sur l'écran
//SORTIE: Incrémentation du score du joueur ayant marqué

    //Le joueur de droite marque
    if(gameScore->posBal == GAUCHE){

        gameScore->JD++;
        gameScore->posBal = AUTRE;

    //Le joueur de gauche marque
    }else if(gameScore->posBal == DROITE){

        gameScore->JG++;
        gameScore->posBal = AUTRE;

    }

}

void writeScore(game *myGame, font *myFont, Score *gameScore){
//BUT   : Afficher le score à l'écran
//ENTREE: Score des joueurs
//SORTIE: Affichage du score en temps réel

    char scoreJgauche[10];
    char scoreJdroite[2];

    //On transforme les nombres des scores en caractères
    sprintf(scoreJgauche,"%i : ",gameScore->JG);
    sprintf(scoreJdroite,"%i",gameScore->JD);

    //On les concatène dans une seule chaine
    strcat(scoreJgauche, scoreJdroite);

    //Couleur de police
    SDL_Color fontColor={255,255,255};

    //On charge le texte
    myGame->g_psurface = TTF_RenderText_Blended(myFont->g_font, scoreJgauche,fontColor);

    if(myGame->g_psurface){

        //Surface sur laquelle on va écrire
        SDL_Rect rectangle;
        rectangle.x = SCREEN_WIDTH/2 -50;
        rectangle.y = 0;
        rectangle.w = 100;
        rectangle.h = 60;

        myGame->g_ptexture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_psurface);
        SDL_FreeSurface(myGame->g_psurface);

        if(myGame->g_ptexture){

            SDL_RenderCopy(myGame->g_pRenderer, myGame->g_ptexture, NULL, &rectangle);

        }else{

            fprintf(stdout,"Echec de creation de la texture (%s)\n", SDL_GetError());

        }

    }else{

        fprintf(stdout,"Echec de creation de surface pour le texte (%s)\n", SDL_GetError());

    }

}
