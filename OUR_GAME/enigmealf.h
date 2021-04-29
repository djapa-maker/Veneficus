#ifndef enigmealfalf_H_INCLUDED
#define enigmealfalf_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "hero.h"
#include "background.h"

typedef struct
{
    char question[50];
    int reponse; // 1: if yes  0: if no
    TTF_Font *police;
    TTF_Font *policef;
    SDL_Surface *imgeng;
    SDL_Surface *texteng;
    SDL_Surface *yeseng;
    SDL_Surface *noeng;
    SDL_Surface *passeng;
    SDL_Surface *faileng;
    SDL_Rect poseng;
    SDL_Rect posyes;
    SDL_Rect posno;
    SDL_Rect posimg;
    SDL_Rect pospass;
    SDL_Rect posfail;
    SDL_Rect poscurseur;

} enigmealf;

void initialiser_enigmealf(enigmealf *ealf);
void afficherenigmealf(enigmealf ealf, SDL_Surface *ecran);
void genererenigmealf(enigmealf *ealf);
void afficher_true(SDL_Surface *ecran, enigmealf ealf);
void afficher_false(SDL_Surface *ecran, enigmealf ealf);
void free_enigmealf(enigmealf *ealf);

void save(perso p,Background b,minimap m,int ts,int v);
void load(perso *p,Background *b,minimap *m,int *ts,int *v);


#endif