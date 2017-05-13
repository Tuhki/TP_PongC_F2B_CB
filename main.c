#include "init.h"
#include "declaBalle.h"
#include "declaRaquette.h"
#include "declaScore.h"

void destroy(game *myGame);

int main(int argc, char *argv[]){
//BUT   : Créer le jeu pong avec la SDL
//ENTREE: inputs joueurs
//SORTIE: gestion du jeu

    Score gameScore;
    EtatRaquette raq1;
    EtatRaquette raq2;
    game myGame;
    gameState state;
    font mFont;
    Cercle balle;
    coordonnees dep;
    coordonnees dep2;
    int scoreJG;
    int scoreJD;

    initjeu(&myGame, &state, &balle, &dep, &dep2, &scoreJG, &scoreJD, &gameScore);

    while(state.g_bRunning){

        init("Pong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame,&mFont);

        while(state.g_bRunning){

            handleEvents(&state,&raq1, &raq2);
            gestionEtat(&dep, &dep2, &raq1, &raq2);
            renderTexture(&myGame,&dep,&dep2);
            renderBalle(&myGame,&balle);
            placeBalle(&balle, &dep, &dep2, &scoreJG, &scoreJD, &gameScore);
            mouvBalle(&balle);
            gestScore(&gameScore);
            writeScore(&myGame,&mFont, &gameScore);

        }

        system ("cls");

    }

    destroy(&myGame);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

void destroy(game *myGame){
//BUT   : Libérer la mémoire
//ENTREE: myGame
//SORTIE: Jeu détruit

      //Destroy render
     if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);

      //Destroy texture
     if(myGame->g_ptexture!=NULL)
        SDL_DestroyTexture(myGame->g_ptexture);

    //Destroy surface
     if(myGame->g_psurface!=NULL)
         SDL_FreeSurface(myGame->g_psurface);

    //Destroy window
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}









