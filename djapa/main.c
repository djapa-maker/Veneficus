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
    SDL_Surface *ecran=NULL,*perso;
    int direction,continuer=1;
    Background b;
    perso= IMG_Load("8.png");
    SDL_Rect posperso;
    posperso.x = 60;
   posperso.y = 380;
    initBack(&b);
     SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) != 0)
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
SDL_EnableKeyRepeat(200,200);
    while(continuer)
    {
        afficherBack(b,ecran);
        SDL_BlitSurface(perso, NULL,ecran, &posperso);
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
          if(posperso.x<(ecran->w/2) || b.scroll.x>=(b.scroll.w-ecran->w))
      {
        posperso.x+=50;
        printf("dep right poshero %d  abcisse cam %d\n",posperso.x,b.scroll.x);
      }
      else if(posperso.x>=(ecran->w/2))
      {
 scrollingBack(&b,posperso,direction);
      }
      if(posperso.x>=(ecran->w-239))
      {
        posperso.x=(ecran->w-239);
      }
          break;
        case SDLK_LEFT:
          direction=2;
           
      if((b.scroll.x>=50 && b.scroll.x<(b.scroll.w-ecran->w)) || (b.scroll.x==(b.scroll.w-ecran->w) && posperso.x<=760))
      {
           scrollingBack(&b,posperso,direction);
      }
      else  if(b.scroll.x<50 || b.scroll.x>=(b.scroll.w-ecran->w))
      {
        
          posperso.x-=50;
          printf("dep left poshero %d abcisse cam : %d\n",posperso.x,b.scroll.x);
      }
      if(posperso.x<=60)
      {
        posperso.x=60;
      }
          break;
         case SDLK_UP:
          direction=3;
         if( posperso.y<=380 && posperso.y>=((ecran->h)/2) || (b.scroll.y==0 && posperso.y<=380))
      {
             printf("poshero %d",posperso.y);
             printf("pos cam %d",b.scroll.y);
          posperso.y-=50;
          if(posperso.y<=30)
          posperso.y=30;
     
      }
      else if(posperso.y<393)
      {
        printf("poshero %d",posperso.y);
         printf("pos cam %d",b.scroll.y);
        scrollingBack(&b,posperso,direction);
       
      }
          break;

        }
      }
    }
    SDL_Flip(ecran);

    }
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(perso);
    SDL_FreeSurface(b.imgBack1);
    SDL_Quit;
}
