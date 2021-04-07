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
int main()
{
  TTF_Init();
  SDL_Event event;
    SDL_Surface *ecran=NULL;
    int direction,continuer=1,frame=0;
    const int FPS=20;
    Background b;
    Personne p;
    p.perso= IMG_Load("8.png");
    p.posperso.x = 60;
    p.posperso.y = 380;
    p.posperso.h=267;
p.posperso.w=200;
    SDL_Surface *imageM;
    imageM=IMG_Load("masque.jpg"); 
    SDL_Rect posimage;
    posimage.x=0;
    posimage.y=0;
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
   int temps;
temps=60;

    Uint32 start;
   
   minimap m;
initmap(&m);
SDL_EnableKeyRepeat(200,200);
    while(continuer)
    {
        afficherBack(b,ecran,p);
       
         afficherminimap (m,  ecran);
      start=SDL_GetTicks();
	affichertemps ( temps,ecran);
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
          p.direction=1;
          if(p.posperso.x<(ecran->w/2) || b.scroll.x>=(b.scroll.w-ecran->w))
      {
        if(collisionPP(p,imageM,b)==0)
		    {
        p.posperso.x+=50;
        if(m.pospoint.x<=m.posminimap.x+1240)
          m.pospoint.x+=5;
        printf("dep right poshero %d  abcisse cam %d\n",p.posperso.x,b.scroll.x);
        }
      }
      else if(p.posperso.x>=(ecran->w/2))
      {
        if(collisionPP(p,imageM,b)==0)
		    {
        scrollingBack(&b,p);
        if(m.pospoint.x<=m.posminimap.x+1240)
          m.pospoint.x+=5;
        }
      }
      if(p.posperso.x>=(ecran->w-239))
      {
        p.posperso.x=(ecran->w-239);
        m.pospoint.x=100;
      }
          break;
        case SDLK_LEFT:
          p.direction=2;
           
      if((b.scroll.x>=50 && b.scroll.x<(b.scroll.w-ecran->w)) || (b.scroll.x==(b.scroll.w-ecran->w) && p.posperso.x<=760))
      {
           scrollingBack(&b,p);
      }
      else  if(b.scroll.x<50 || b.scroll.x>=(b.scroll.w-ecran->w))
      {
        if(collisionPP(p,imageM,b)==0)
		{
          p.posperso.x-=50;
          printf("dep left poshero %d abcisse cam : %d\n",p.posperso.x,b.scroll.x);
      if(m.pospoint.x>=m.posminimap.x)
		m.pospoint.x-=5;
               }
      }
      if(p.posperso.x<=60)
      {
        p.posperso.x=60;
        m.pospoint.x=100;
      }
          break;
         case SDLK_UP:
          p.direction=3;
         if( p.posperso.y<=380 && p.posperso.y>=((ecran->h)/2) || (b.scroll.y==0 && p.posperso.y<=380))
      {
             printf("poshero %d",p.posperso.y);
             printf("pos cam %d",b.scroll.y);
          p.posperso.y-=50;
          if(p.posperso.y<=30)
          p.posperso.y=30;
     
      }
      else if(p.posperso.y<393)
      {
        printf("poshero %d",p.posperso.y);
         printf("pos cam %d",b.scroll.y);
        scrollingBack(&b,p);
       
      }
          break;

        }
      }
    }
    SDL_Flip(ecran);
    frame++;
if(frame==30)
{
  if(temps>0)
temps--;
frame=0;
}
        if(1000/FPS>SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(p.perso);
    SDL_FreeSurface(b.imgBack1);
    SDL_Quit;
}