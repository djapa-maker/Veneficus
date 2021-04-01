#ifndef enigmeal_H_INCLUDED
#define enigmeal_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct {

int score;
int numvie;
int direction;
SDL_Rect poshero;
}personnage;

typedef struct
{
    char question[50];
    int reponse; // 1: if yes  0: if no
    int resolu;
    SDL_Surface *imgbutton;
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

} enigme;
void initPerso(personnage *p);
void initialiser_enigme(enigme *e);
void afficherEnigme(enigme e, SDL_Surface *ecran);
void genererEnigme(enigme *e);
int resolution(int *running, int *run);
void afficher_resultat(SDL_Surface *ecran, int s, int r, enigme e);

void save (personnage p);
void load (personnage *p);

#endif