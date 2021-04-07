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
  e->posEnnemi.x = 1200;
  e->posEnnemi.y = 500;
  e->posMax.x = 1190;
  e->posMax.y = 500;
  e->posMin.x = 1000;
  e->posMin.y = 500;
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
  deplacer(&e);
  if ((e.direction==1))
  {
     SDL_BlitSurface(e.tabMar1[e.frame1], NULL, ecran, &e.posEnnemi);
  }
 else if ((e.direction==0))
 {
   SDL_BlitSurface(e.tabMar2[e.frame2], NULL, ecran, &e.posEnnemi);
 }
 //SDL_Flip(ecran);
}
void animerEnnemi(Ennemi *e,SDL_Surface *ecran)
{
  
  if ((e->direction==1))
    {
    //SDL_BlitSurface(e->tabMar1[e.frame1], NULL, ecran, &e->posEnnemi);
    //SDL_Delay(40);
    (e->frame1)++;
    if ( e->frame1== 6)
      (e->frame1) = 0;
      }

    else if ((e->direction==0))
    {
       //SDL_BlitSurface(e->tabMar2[b], NULL, ecran, &e->posEnnemi);
       //SDL_Delay(40);
        (e->frame2)++;
        if (e->frame2== 6)
         (e->frame2) = 0;
    }
}
void deplacer(Ennemi *e)
{
  SDL_Surface *ecran;
  if((e->direction==0))
     {
         if((e->posEnnemi.x<e->posMax.x)&&(e->posEnnemi.x>e->posMin.x))
      {
         e->posEnnemi.x++;
        //e->direction==1;
        //printf("%d",e->direction);
       }
     //e->posEnnemi.x--;
        else if((e->direction==e->posMax.x))
       {
         e->direction==1;
        }
      }
   if(e->direction==1)
   {
     if((e->posEnnemi.x<e->posMax.x)&&(e->posEnnemi.x>e->posMin.x))
   {
     //printf("posenimi-inf");
     //e->direction==0;
     e->posEnnemi.x--;
   }
   else if((e->direction==e->posMin.x))
    {
      e->direction==0;
    }
   //printf("%d",e->direction);
   
    animerEnnemi(e,ecran);
}
}

