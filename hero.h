#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
SDL_Surface *tab1[7];
SDL_Surface *tab2[7];
SDL_Surface *tab3[7];
SDL_Surface *tab4[7];
SDL_Surface *imgscore;
SDL_Surface *tabvie[8];
int num1;
int num2;
int num3;
int num4;
int numvie;
int direction;
int up;
float vitesse;
float acceleration;
SDL_Rect poshero;
SDL_Rect posimgvie;
SDL_Rect posimgscore;
}perso;

typedef struct 
{SDL_Surface *imgbackground;
SDL_Rect posbackground; 	
}back;

//void init(perso *p,int numperso);
void initPerso(perso *p);
void init(back *b);
void aff(back b,SDL_Surface *ecran);
void afficherPerso(perso p,SDL_Surface *ecran,int dx,int ts,int v);
void deplacerPerso(perso *p,Uint32 dt,int *dx);
void animerperso(perso p,SDL_Surface *ecran,int *t1,int *t,int *t2,int *t3,int dx,int v,int ts);
void saut(perso *p,Uint32 dt,int *dy);

#endif


