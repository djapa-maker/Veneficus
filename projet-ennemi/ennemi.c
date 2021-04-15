#include "ennemi.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
void initEnnemi(Ennemi *e)
{
    SDL_Surface *ecran = NULL;
    e->tabMar1[7] = NULL;
    e->tabMar2[7] = NULL;
    e->tabDeg[7] = NULL;
    e->tabAct[7] = NULL;
    e->frame1=0;
    e->frame2=0;
    e->frameAct=0;
    e->frameDeg=0;
    e->direction=1;
    e->posEnnemi.x = 1180;
    e->posEnnemi.y = 500;
    e->posEnnemi.w = 170;
    e->posEnnemi.h = 250;
    e->posMax.x = 1190;
    e->posMax.y = 500;
    e->posMin.x = 1000;
    e->posMin.y = 500;
    char char1[10],char2[10],char3[10],char4[10];// char pour stocker les no;s des images
    int t;
    for (t = 0; t < 5; t++)
    {
        sprintf(char1, "%d.png",t);
        e->tabMar1[t] = IMG_Load(char1);
    }

    for (t= 0; t< 5; t++)
    {
        sprintf(char2, "1%d.png",t);
        e->tabMar2[t] = IMG_Load(char2);
    }
    for (t = 1; t < 6; t++)
    {
        sprintf(char3, "2%d.png",t);
        e->tabDeg[t] = IMG_Load(char3);
    }
    for (t = 1; t < 6; t++)
    {
        sprintf(char4, "3%d.png",t);
        e->tabAct[t] = IMG_Load(char4);
    }

}
void initback(back *b)
{
    b->imgbackground= NULL;
    b->imgbackground= IMG_Load("imgbackground.png");

    b->posbackground.x=0;
    b->posbackground.y=0;
}
void initperso(personne *p)
{
    p->poshero.x = 20;
    p->poshero.y = 500;
    p->poshero.w = 170;
    p->poshero.h = 250;
    p->imageh= IMG_Load("djapa.png");
}
void afficherperso(personne p,SDL_Surface *ecran)
{
    SDL_BlitSurface(p.imageh, NULL, ecran, &p.poshero);
}
void afficherback(back b,SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
}
void afficherEnnemi(Ennemi e,SDL_Surface *ecran)
{
    if ((e.direction==1))
    {
        SDL_Delay(70);
        SDL_BlitSurface(e.tabMar1[e.frame1], NULL, ecran, &e.posEnnemi);
    }
    else if ((e.direction==0))
    {
        SDL_Delay(70);
        SDL_BlitSurface(e.tabMar2[e.frame2], NULL, ecran, &e.posEnnemi);
    }
}
void animerEnnemi(Ennemi *e,SDL_Surface *ecran)
{

    if ((e->direction==1))
    {
        SDL_Delay(70);
        (e->frame1)++;
        if ( e->frame1== 5)
            (e->frame1) = 0;
    }

    else if ((e->direction==0))
    {
        SDL_Delay(70);
        (e->frame2)++;
        if (e->frame2== 5)
            (e->frame2) = 0;
    }
}
void deplacer(Ennemi *e)
{
    if(e->direction==1)
    {

        if((e->posEnnemi.x<=e->posMax.x)&&(e->posEnnemi.x>e->posMin.x))
        {
            e->posEnnemi.x-=5;
        }
        else if((e->posEnnemi.x==e->posMin.x))
        {
            e->direction=0;

        }
    }
    else if((e->direction==0))
    {

        if((e->posEnnemi.x<e->posMax.x)&&(e->posEnnemi.x>=e->posMin.x))
        {
            e->posEnnemi.x+=5;
        }
        else if((e->posEnnemi.x==e->posMax.x))
        {
            e->direction=1;
        }
    }
}
int collisionBB(personne p,Ennemi e,int collision)
{
    if((p.poshero.x + p.poshero.w<e.posEnnemi.x)||(p.poshero.x>e.posEnnemi.x+e.posEnnemi.w)||(p.poshero.y+p.poshero.h<e.posEnnemi.y)||(p.poshero.y>e.posEnnemi.y+e.posEnnemi.h))
    {
        collision=0;
    }
    else
    {
        collision=1;
    }
    return collision;
}
