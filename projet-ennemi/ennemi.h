#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
typedef struct
{
    SDL_Rect posEnnemi;
    SDL_Rect posMax;
    SDL_Rect posMin;
    SDL_Surface *tabMar1[7];
    SDL_Surface *tabMar2[7];
    SDL_Surface *tabDeg[7];
    SDL_Surface *tabAct[7];
    int frame1;
    int frame2;
    int frameAct;
    int frameDeg;
    int direction;
} Ennemi;
typedef struct
{
    SDL_Surface *imgbackground;
    SDL_Rect posbackground;
} back;
typedef struct
{
    SDL_Rect poshero;
    SDL_Surface *imageh;
} personne;
void initEnnemi(Ennemi*e);
void initback(back *b);
void initperso(personne *p);
void afficherback(back b,SDL_Surface *ecran);
void afficherEnnemi(Ennemi e,SDL_Surface *ecran);
void afficherperso(personne p,SDL_Surface *ecran);
void animerEnnemi(Ennemi *e,SDL_Surface *ecran);
void deplacer(Ennemi *e);
int collisionBB(personne p,Ennemi e,int collision);
/*void deplacerIA(Ennemi *e);*/
