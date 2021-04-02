#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>

typedef struct
{
  SDL_Surface *imgnewgame;
  SDL_Surface *imgloadgame;
  SDL_Surface *imgmultijoueur;
  SDL_Surface *imgnewgame2;
  SDL_Surface *imgloadgame2;
  SDL_Surface *imgmultijoueur2;
  SDL_Surface *ecran;
  SDL_Surface *imgplay;
  SDL_Surface *imgoption;
  SDL_Surface *imgbackground[12];
  SDL_Surface *imgquit;
  SDL_Surface *imgcurseur;
  SDL_Surface *textecm;
  SDL_Surface *imgplay2;
  SDL_Surface *imgoption2;
  SDL_Surface *imgquit2;
  SDL_Surface *seq;
  SDL_Surface *imgv100;
  SDL_Surface *imgfullscreen;
  SDL_Surface *imgnormalscreen;
  SDL_Surface *imgfullscreen2;
  SDL_Surface *imgnormalscreen2;
  SDL_Surface *imgtxtaffichaage;
  SDL_Surface *imgtxtvolume;
  SDL_Surface *imgoption3;
  SDL_Surface *imgv0;
  SDL_Surface *imgv25;
  SDL_Surface *imgv75;
  SDL_Surface *imgv50;
  SDL_Surface *imgicon;
  SDL_Surface *imgbackfull;
  SDL_Surface *imgbackloading;
  SDL_Rect posplay;
  SDL_Rect posoption;
  SDL_Rect posbackground;
  SDL_Rect posbackground1;
  SDL_Rect posbackground2;
  SDL_Rect posquit;
  SDL_Rect poscurseur;
  SDL_Rect postextecm;
  SDL_Rect posvolume;
  SDL_Rect posfullscreen;
  SDL_Rect posnormalscreen;
  SDL_Rect postextevolume;
  SDL_Rect posaffichage;
  SDL_Rect posoption2;
  SDL_Rect posnewgame;
  SDL_Rect posloadgame;
  SDL_Rect posmultijoueur;
  Mix_Music *musique;
  Mix_Chunk *son;

} menu;

void menu1(int *page,int *continuer, menu m);
void intialiser(menu *m);
void affichage(int interface, int y, int f, int k, menu m, SDL_Surface *ecran, int n);
void animation(menu m, SDL_Surface *ecran,int *t);
void initanim(SDL_Surface *imgbackground[]);
void motion(int *page,int *continuer, menu m);

#endif

