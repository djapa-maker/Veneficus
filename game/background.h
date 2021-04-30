#ifndef BACKGROUNG_H_INCLUDED
#define BACKGROUNG_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "hero.h"
typedef struct
{
SDL_Surface *minimap;
SDL_Surface *point;
SDL_Rect posminimap;
SDL_Rect pospoint;
}minimap;


typedef struct
{
  SDL_Surface *imgBack1;
  SDL_Rect posBack1;
  SDL_Rect scroll;
  SDL_Surface *imageM;
} Background;
void initBack(Background *b);
void afficherBack(Background b, SDL_Surface *ecran);
void afficherBack1(Background b, SDL_Surface *ecran);
void scrollingBack(Background *b, perso p,Input I);
void jumpin(perso *p,Input *I,Background *b,int multijoueur);
void gravity(perso *p,Input *I,Background *b,int multijoueur);


void initmap( minimap * m); 
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemps (int temps, SDL_Surface * screen);
int collisionPP( perso p, SDL_Surface * Masque,Background b,Input I);
int collisionPP1( perso p, SDL_Surface * Masque,Background b,Input I);
#endif