#ifndef ENTETE_H_
#define ENTETE_H_
#include "background.h"

typedef struct
{
SDL_Surface *perso;
SDL_Rect posperso;
int direction;
}Personne;
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
int collisionPP( Personne p, SDL_Surface * Masque,Background b);


#endif
