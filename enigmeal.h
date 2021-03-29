#ifndef enigmeal_H_INCLUDED
#define enigmeal_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
    char question[50];
    int reponse;
    int resolu;
    SDL_Surface *imgeng;
    SDL_Surface *texteng;
    SDL_Rect poseng;
    SDL_Rect posimg;
    TTF_Font *police;
    SDL_Color couleurblanche;

} enigme;

void initialiser_enigme(enigme *e);
void afficherEnigme(enigme e, SDL_Surface *ecran);
void genererEnigme(enigme *e);

/*void sauvegarder(personne p,background);
void charger(personne*p,background*b);*/

#endif