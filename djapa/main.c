#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "background.h"
int main()
{
  SDL_Event event;
    SDL_Surface *ecran=NULL,*hero=NULL;
    SDL_Rect poshero;
    int direction,continuer=1;
    Background b;
    hero = IMG_Load("8.png");
    poshero.x = 60;
    poshero.y = 380;
    initBack(&b);
     SDL_Init(SDL_INIT_VIDEO);
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());
    return 1;
  }

  ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());
    return 1;
  }
   
    while(continuer)
    {
       
        afficherBack(b,ecran,hero,poshero);
      
        while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        continuer = 0;
        break;
        case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:
          direction=1;
          if(poshero.x<(ecran->w/2) || b.scroll.x>=(b.scroll.w-ecran->w))
      {
        poshero.x+=50;
        printf("dep right poshero %d  abcisse cam %d\n",poshero.x,b.scroll.x);
      }
      else if(poshero.x>=(ecran->w/2))
      {
        scrollingBack(&b,direction);
      }
      if(poshero.x>=(ecran->w-239))
      {
        poshero.x=(ecran->w-239);
      }
          break;
        case SDLK_LEFT:
          direction=2;
           
      if(/*poshero.x>=(ecran->w/2) || */(b.scroll.x>=50 && b.scroll.x<(b.scroll.w-ecran->w)) || (b.scroll.x==(b.scroll.w-ecran->w) && poshero.x<=760))
      {
           scrollingBack(&b,direction);
      }
      else  if(/*poshero.x<(ecran->w/2) || */b.scroll.x<50 || b.scroll.x>=(b.scroll.w-ecran->w))
      {
          poshero.x-=50;
          printf("dep left poshero %d abcisse cam : %d\n",poshero.x,b.scroll.x);
      }
      if(poshero.x<=60)
      {
        poshero.x=60;
      }
          break;
         case SDLK_UP:
          direction=3;
         if( poshero.y<=380 && poshero.y>=((ecran->h)/2) || (b.scroll.y==0 && poshero.y<=380))
      {
             printf("poshero %d",poshero.y);
             printf("pos cam %d",b.scroll.y);
          poshero.y-=50;
          if(poshero.y<=30)
          poshero.y=30;
     
      }
      else if(poshero.y<393)
      {
        printf("poshero %d",poshero.y);
         printf("pos cam %d",b.scroll.y);
        scrollingBack(&b,direction);
       
      }
          break;

        }
      }
    }
    SDL_Flip(ecran);
    }
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(hero);
    SDL_FreeSurface(b.imgBack1);
    SDL_Quit;
}