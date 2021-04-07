#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>
#include <string.h>
#include "background.h"
#include "entete.h"
void initBack(Background *b)
{
  b->imgBack1 = IMG_Load("ice level.png");
  b->posBack1.x = 0;
  b->posBack1.y = 0;
  b->scroll.x = 0;
  b->scroll.y = 220;
  b->scroll.w = 12098;
  b->scroll.h = 1007;
}
void afficherBack(Background b,SDL_Surface *ecran,Personne p)
{
  
  SDL_BlitSurface(b.imgBack1, &(b.scroll),ecran, NULL);
  SDL_BlitSurface(p.perso, NULL,ecran, &p.posperso);
   
}
void scrollingBack(Background *b,Personne p)
{
  if(p.direction==1) //droite
  {
b->scroll.x+=50;
b->posBack1.x+=50;
if(b->scroll.x>=10699)
b->scroll.x=10699;
printf("scroll right abcisse cam: %d abcisse bg %d\n",b->scroll.x,b->posBack1.x);
  }
  else if(p.direction==2) //gauche
  {
b->scroll.x-=50;
b->posBack1.x-=50;
if(b->scroll.x<=0)
b->scroll.x=0;
printf("scroll left abcisse cam: %d abcisse bg %d\n",b->scroll.x,b->posBack1.x);
  }
  else if(p.direction==3) //up
  {
b->scroll.y-=50;
b->posBack1.y-=50;
if(b->scroll.y<=0)
b->scroll.y=0;
  }
}
