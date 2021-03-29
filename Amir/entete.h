#ifndef HEADER_H_
#define HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct
{
SDL_Surface *perso;
SDL_Rect posperso;
int direction;
}Personne;
typedef struct
{SDL_Surface *minimap;
SDL_Surface *point;
SDL_Rect posminimap;
SDL_Rect pospoint;
}minimap;
void initmap( minimap * m); 
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemps (int temps, SDL_Surface * screen);
int collisionPP( Personne p, SDL_Surface * Masque);
void test ();
#endif
