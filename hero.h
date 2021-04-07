
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




	int jumpspeed;
	int jumpheight;
	int distanceup;
	int distancedown;
	int fall;
	int jump;
	int gravity;
SDL_Surface *tab1[7];
SDL_Surface *tab2[7];
SDL_Surface *tab3[7];
SDL_Surface *tab4[7];
SDL_Surface *tab5[7];
SDL_Surface *tab6[7];
SDL_Surface *tab7[7];
SDL_Surface *tab8[7];
SDL_Surface *imgscore;
SDL_Surface *tabvie[8];
int num1;
int num2;
int num3;
int num4;
int num5;
int num6;
int num7;
int num8;
int numvie;
int frame;
int frame1;
int frame2;
int frame3;
int frame4;
int frame5;
int frame6;
int frame7;
int direction;
int up;
int down;
int frapper;
float vitesse;
float vitessesaut;
float acceleration;
float accelerationsaut;
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
void afficherPerso(perso p,SDL_Surface *ecran, int dx,int ts,int v,int dy);
void deplacerPerso(perso *p,Uint32 dt,int *dx);
void animerperso(perso *p,SDL_Surface *ecran,int dx,int dy,int v);
//void saut(perso *p);
    void jumpin(perso *p,Uint32 dt,int dx);
    void gravity(perso *p);

#endif

