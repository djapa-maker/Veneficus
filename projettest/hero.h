
#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int X;
    int Y;
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
    SDL_Rect poshero;
    SDL_Rect posimgvie;
    SDL_Rect posimgscore;
} perso;

typedef struct
{
    SDL_Surface *imgbackground;
    SDL_Rect posbackground;
} back;
typedef struct
{
    int left;
    int right;
    int jump;
    int fight;
} Input;

void initPerso(perso *p);
void init(back *b);
void aff(back b, SDL_Surface *ecran);
void afficherPerso(perso p, SDL_Surface *ecran, int ts, int v, Input I);
void mouvementright(perso *p);
void mouvementleft(perso *p);
void initialiser_input(Input *I);
void animerperso(perso *p, SDL_Surface *ecran, int v, Input *I);
void freesurface(perso p, SDL_Surface *ecran, back b);
void saut(perso *p);

#endif
