#include "enigmeal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void initialiser_enigme(enigme *e)
{

    TTF_Init();
    TTF_Font *police = NULL;
    e->posimg.x = 0;
    e->posimg.y = 0;
    e->imgeng = NULL;
    e->texteng = NULL;
    e->poseng.x = 0;

    e->poseng.y = 0;
    

    e->imgeng = IMG_Load("enigme.png");

    e->police = TTF_OpenFont("texxte.ttf", 20);
}
void afficherEnigme(enigme e, SDL_Surface *ecran)
{
    e.couleurblanche = {255, 255, 255} ;

    e.texteng = TTF_RenderText_Blended(e.police, "10+20=30?", e.couleurblanche);
    SDL_BlitSurface(e.texteng, NULL, ecran, &(e.poseng));
    SDL_BlitSurface(e.imgeng, NULL, ecran, &(e.posimg));
}

void genererEnigme(enigme *e)
{
}
/*void sauvegarder(personne p,background)
{

}
void charger(personne*p,background*b)
{
  
}*/