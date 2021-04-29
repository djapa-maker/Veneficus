#ifndef ENTETE_H_
#define ENTETE_H_
#include "background.h"


typedef struct
{
SDL_Surface *minimap;
SDL_Surface *point;
SDL_Rect posminimap;
SDL_Rect pospoint;
}minimap;
void initmap( minimap * m); 
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemps (int temps, SDL_Surface * screen);
int collisionPP( perso p, SDL_Surface * Masque,Background b,Input I);
int collisionPP1(perso p, SDL_Surface *Masque, Background b, Input I);


#endif
