#include "declaRaquette.h"

void renderTexture(game *myGame,coordonnees *dep,coordonnees *dep2 ) {
//BUT   : Dessiner les raquettes
//ENTREE: Position des raquettes
//SORTIE: Raquette dessiner � leur nouvelle position

       //D�finition de la raquette gauche
        SDL_Rect rectangle;
        rectangle.x=dep->x;//debut x
        rectangle.y=dep->y;//debut y
        rectangle.w=dep->w; //Largeur
        rectangle.h=dep->h; //Hauteur

        //D�finition de la raquette droite
        SDL_Rect rectangle2;
        rectangle2.x=dep2->x;//debut x
        rectangle2.y=dep2->y;//debut y
        rectangle2.w=dep2->w; //Largeur
        rectangle2.h=dep2->h; //Hauteur

        //On choisit la couleur des raquettes
        SDL_SetRenderDrawColor(myGame->g_pRenderer,255,255,255,255); //couleur blanche

        //On remplit les deux raquettes
        SDL_RenderFillRect(myGame->g_pRenderer, &rectangle);
        SDL_RenderFillRect(myGame->g_pRenderer, &rectangle2);

        //On modifie � nouveau le renderer
        SDL_SetRenderTarget(myGame->g_pRenderer, NULL);
        SDL_RenderPresent(myGame->g_pRenderer);

        //Couleur du fond (noir)
        SDL_SetRenderDrawColor(myGame->g_pRenderer,0,0,0,255);

        //On nettoie l'�cran
        SDL_DestroyTexture(myGame->g_ptexture);
        SDL_RenderClear(myGame->g_pRenderer);

}

void handleEvents(gameState *state, EtatRaquette *raq1,  EtatRaquette *raq2){
//BUT    : G�rer choix de d�placement des joueurs
//ENTREE : inputs joueurs
//SORTIE : changement d'�tat des raquettes en fonction des touches appuy�es

    SDL_Event event;

    if(SDL_PollEvent(&event)){

        switch(event.type){

            case SDL_QUIT:
                state->g_bRunning=0;break;

            //Touche appuy�e
            case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                            {
                                case SDLK_z:     *raq1=HAUT; break;
                                case SDLK_s:     *raq1=BAS;  break;
                                case SDLK_UP:    *raq2=HAUT; break;
                                case SDLK_DOWN:  *raq2=BAS;  break;
                            }
                            break;

            //Touche relev�e
            case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                            {
                                case SDLK_z:     *raq1=STOP; break;
                                case SDLK_s:     *raq1=STOP; break;
                                case SDLK_UP:    *raq2=STOP; break;
                                case SDLK_DOWN:  *raq2=STOP; break;
                            }
                            break;

            default:break;

        }
    }

}

void gestionEtat(coordonnees *dep, coordonnees *dep2, EtatRaquette *raq1, EtatRaquette *raq2){
//BUT    : D�placer les raquettes
//ENTREE : Etat des raquettes
//SORTIE : d�placement de la raquette dans la direction de son �tat

    //Raquette gauche vers le haut
    if((*raq1 == HAUT)&&(dep->y > 0)){

        dep->y--;
        dep->y--;
        dep->y--;

    }

    //Raquette gauche vers le bas
    if((*raq1 == BAS)&&(dep->y < SCREEN_HEIGHT-dep->h)){

        dep->y++;
        dep->y++;
        dep->y++;

    }

    //Raquette droite vers le haut
    if((*raq2 == HAUT)&&(dep2->y > 0)){

        dep2->y--;
        dep2->y--;
        dep2->y--;

    }

    //Raquette droite vers le bas
     if((*raq2 == BAS)&&(dep2->y < SCREEN_HEIGHT-dep2->h)){

        dep2->y++;
        dep2->y++;
        dep2->y++;

    }

}
