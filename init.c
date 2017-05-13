#include "init.h"

int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame, font *mfont){
//BUT    : Initialiser la fenêtre d'affichage
//ENTREE : Attributs liés à la SDL
//SORTIE : Fenêtre initialisée

    myGame->g_pWindow=NULL;
    myGame->g_pRenderer=NULL;
    myGame->g_psurface=NULL;
    myGame->g_ptexture=NULL;

    //initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            //if succeeded create our window
            myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
            //if succeeded create window, create our render
            if(myGame->g_pWindow!=NULL){
                myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_PRESENTVSYNC);

            }

    }else{

        return 0;
    }

    //On initialise le TTF
    if(TTF_Init() == -1){

        fprintf(stderr, "Probleme d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);

    }

    //On choisit sa police
    mfont->g_font = TTF_OpenFont("./police/recharge.ttf",14);

    return 1;

}

void initjeu(game *myGame, gameState *state, Cercle *balle, coordonnees *dep, coordonnees *dep2, int *scoreJG, int *scoreJD, Score *gameScore){
//BUT    : Initialiser le jeu
//ENTREE : Différents objets du jeu
//SORTIE : Jeu prêt

    dep->x=0;
    dep->y=0;
    dep->w=10;
    dep->h=100;

    dep2->x=SCREEN_WIDTH-10;
    dep2->y=0;
    dep2->w=10;
    dep2->h=100;

    balle->x=SCREEN_HEIGHT/2;
    balle->y=SCREEN_WIDTH/2;
    balle->r=10;
    balle->dir=1;

    scoreJG = 0;
    scoreJD = 0;

    gameScore->JD = 0;
    gameScore->JG = 0;
    gameScore->posBal = AUTRE;

    state->g_bRunning=1;

}
