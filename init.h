#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>

#include <time.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 700


typedef enum {

    STOP,HAUT,BAS

}EtatRaquette;

typedef enum {

    GAUCHE,DROITE,AUTRE

}EtatBalle;

typedef struct game{

     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_ptexture;
     SDL_Surface *g_psurface;

}game;

typedef struct gameState{

    int g_bRunning;

}gameState;

typedef struct font{

    TTF_Font *g_font;

}font;

typedef struct coordonnees{

    double x;
    double y;
    double h;
    double w;

}coordonnees;

typedef struct Cercle{

    double x;
    double y;
    double r;
    int dir;

}Cercle;

typedef struct Score{

    int JG;
    int JD;
    EtatBalle posBal;

}Score;

int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame, font *mfont);
void initjeu(game *myGame, gameState *state, Cercle *balle, coordonnees *dep, coordonnees *dep2, int *scoreJG, int *scoreJD, Score *gameScore);

#endif // INIT_H_INCLUDED
