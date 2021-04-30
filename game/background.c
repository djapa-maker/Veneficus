#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "background.h"
#include "hero.h"
void initBack(Background *b)
{
  b->imgBack1 = IMG_Load("ice level.png");
  b->posBack1.x = 0;
  b->posBack1.y = 0;
  b->posBack1.w=12098;
   b->posBack1.h=1007;
  b->scroll.x = 0;
  b->scroll.y = 220;
  b->scroll.w = 12098;
  b->scroll.h = 1007;
  b->imageM = IMG_Load("bgmasque.jpg");
}
void afficherBack(Background b, SDL_Surface *ecran)
{
  SDL_BlitSurface(b.imgBack1, &(b.scroll), ecran, NULL);
}
void afficherBack1(Background b, SDL_Surface *ecran)
{
  b.posBack1.x=0;
  b.posBack1.y=393;
  SDL_BlitSurface(b.imgBack1, &(b.scroll), ecran,&b.posBack1);
}
void scrollingBack(Background *b, perso p, Input I)
{
  if (p.direction == 0) //droite
  {
    b->scroll.x += p.X;
    b->posBack1.x += p.X;
    if (b->scroll.x >= 10699)
      b->scroll.x = 10699;
   // printf("scroll right abcisse cam: %d abcisse bg %d pos perso %d\n", b->scroll.x, b->posBack1.x,p.poshero.x);
  }
  else if (p.direction == 1) //gauche
  {
    b->scroll.x -= p.X;
    b->posBack1.x -= p.X;
    if (b->scroll.x <= 0)
      b->scroll.x = 0;
    //printf("scroll left abcisse cam: %d abcisse bg %d\n", b->scroll.x, b->posBack1.x);
  }

  /*else if (I.jump == 1) //up
  {
    int c=0;
    b->scroll.y -= p.jumpspeed - c;
    b->posBack1.y -= p.jumpspeed - c;
    c++;
    if(b->scroll.y <= 0)
    b->scroll.y = 0;
    printf("-------------------------------");
  }*/
}
void jumpin(perso *p, Input *I,Background *b,int multijoueur)
{

    if ((I->jump == 1 || (p->Y) != 0) && ((p->Y) < p->jumpheight) && (p->Y2) == 0)
    {
     
        p->poshero.y -= p->jumpspeed - (p->Y);
        
      
        (p->Y)++;
        if(multijoueur==0)
        {
         b->scroll.y -= 3;
         if(b->scroll.y >= 220)
    b->scroll.y = 220;
        }
       
    }
    else
    {
      
        (p->Y) = 0;
        (p->Y2) = 1;
    }
}
void gravity(perso *p, Input *I,Background *b,int multijoueur)
{
    if ((p->Y2) == 1)
    {
 printf("pshero %d",p->poshero.y);
 printf("pos cam %d",b->scroll.y);

        if (p->poshero.y < p->gravity)
        {
 if(multijoueur==0)
        {
        b->scroll.y += 5;
        if(b->scroll.y >= 220)
    b->scroll.y = 220;
        }
        // b->posBack1.y+= 7;
            p->poshero.y += p->jumpspeed;
            
            I->fall = 1;
        }
        else
            (p->Y2) = 0;
        I->jump = 0;
    }
}