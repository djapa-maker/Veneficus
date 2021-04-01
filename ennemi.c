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
  e->direction=1;
  e->posEnnemi.x = 1200;
  e->posEnnemi.y = 500;
  e->PosMax.x = 1300;
  e->PosMax.y = 500;
  e->PosMin.x = 1000;
  e->PosMin.y = 500;
  char char1[10],char2[10],char3[10],char4[10];// char pour stocker les no;s des images
  int t;
  for (t = 1; t < 8; t++)
  {
    sprintf(char1, "%d.png",t);
    e->tabMar1[t] = IMG_Load(char1);
  }

for (t= 1; t< 8; t++)
  {
    sprintf(char2, "1%d.png",t);
    e->tabMar2[t] = IMG_Load(char2);
  }
  for (t = 1; t < 8; t++)
  {
    sprintf(char3, "2%d.png",t);
    e->tabDeg[t] = IMG_Load(char3);
  }
  for (t = 1; t < 8; t++)
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
  void afficherback(back b,SDL_Surface *ecran)
 {      
          SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
      //  SDL_Flip(ecran);
 }
void afficherEnnemi(Ennemi e,SDL_Surface *ecran)
{
  //if ((e.direction==1))
  //{
     SDL_BlitSurface(e.tabMar1[1], NULL, ecran, &e.posEnnemi);
  //}
 //else if ((e.direction==0))
 //{
   SDL_BlitSurface(e.tabMar2[1], NULL, ecran, &e.posEnnemi);
 //}
 SDL_Flip(ecran);
}
void animerEnnemi(Ennemi *e,SDL_Surface *ecran)
{
   int t=1;
   int t1=1;
  if ((e->direction==1))
    {
    SDL_BlitSurface(e->tabMar1[t], NULL, ecran, &e->posEnnemi);
    SDL_Delay(40);
    (t)++;
    if (t == 6)
      (t) = 1;
      }

    else if ((e->direction==0))
    {
       SDL_BlitSurface(e->tabMar2[t1], NULL, ecran, &e->posEnnemi);
       SDL_Delay(40);
        (t1)++;
        if (t1 == 6)
         (t1) = 1;
    }
}
void deplacer(Ennemi *e)
{
   SDL_Surface *ecran;
  if((e->posEnnemi.x>e->PosMax.x))
  {
    e->direction==1;
    printf("%d",e->direction);
  }
  else if((e->posEnnemi.x<e->PosMin.x))
   {
     printf("posenimi-inf");
     e->direction==0;
   }
   printf("%d",e->direction);
   if((e->direction==0))
     {
     e->posEnnemi.x--;
     }
    else if((e->direction==1))
    {
      e->posEnnemi.x++;
    }
    animerEnnemi(e,ecran);
}

