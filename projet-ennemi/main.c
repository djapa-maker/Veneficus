#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "ennemi.h"
int main(int argc, char *argv[])
{
  SDL_Surface *ecran;
  SDL_Surface *imgbackground;
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Game", NULL);
  Ennemi e;
  back b;
   SDL_Event event;   
   
  initEnnemi(&e);
  initback(&b);
  while(1)
  {
   /*while ((SDL_PollEvent(&event)))
    { 
      switch (event.type)
      {
      case SDL_MOUSEMOTION:
        printf("largeur:%d \n",event.motion.x);
        printf("hauteur:%d \n",event.motion.y);
        break;
      }
     }*/
  //deplacer(&e);
  afficherback(b,ecran);
  //deplacer(&e);
  //animerEnnemi(&e,ecran);
  afficherEnnemi(e,ecran);
  SDL_Flip(ecran);
}
}
