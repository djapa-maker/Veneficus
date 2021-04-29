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
    printf("scroll right abcisse cam: %d abcisse bg %d pos perso %d\n", b->scroll.x, b->posBack1.x,p.poshero.x);
  }
  else if (p.direction == 1) //gauche
  {
    b->scroll.x -= p.X;
    b->posBack1.x -= p.X;
    if (b->scroll.x <= 0)
      b->scroll.x = 0;
    printf("scroll left abcisse cam: %d abcisse bg %d\n", b->scroll.x, b->posBack1.x);
  }

  /*else if (p.poshero.y != 400) //up
  {
    b->scroll.y -= p.X;
    b->posBack1.y -= p.X;
    if (b->scroll.y <= 0)
      b->scroll.y = 0;
          printf("jump col");

  }*/
}
