#ifndef ENIGMESTAT_H_INCLUDED
#define ENIGMESTAT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>



typedef struct
{
    
    SDL_Surface *image,*dev;
    SDL_Surface *texte1,*texte2,*texte3,*repvrai,*repfausse;
    TTF_Font *police;
    SDL_Rect posim,post1,post2,post3,posdev,posrep;
}enigme;

void init_enigme(enigme *enig);


void afficher_enigme(SDL_Surface *ecran,enigme enig);

void rep_vrai(SDL_Surface *ecran, enigme enig);

void rep_fausse(SDL_Surface *ecran, enigme enig);
#endif // ENIGMESTAT_H_INCLUDED

