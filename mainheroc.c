
#include "hero.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    SDL_Event event;
    SDL_Surface *ecran,*imgbackground ;
    Uint32 dt, t_prev;
    perso p;
    back b;
int dx,v=1,ts=0,dy;
    int continuer = 1;
int t1=1,t=1, t2=1, t3=1;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

    ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

initPerso(&p);
init(&b);
    SDL_EnableKeyRepeat(70, 70);
    while (continuer)
    {
        t_prev=SDL_GetTicks();
         aff(b,ecran);


        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
              case SDLK_RIGHT:
                   if (v!=7)
                  {  p.direction=0;
                    p.acceleration+=0.003;
                    printf("plus:%f \n",p.acceleration);
                    deplacerPerso(&p,dt,&dx);}
                    break;
                case SDLK_LEFT:
                    if (v!=7)
                    {p.direction=1;
                     p.acceleration-=0.003;
                    printf("moins:%f \n",p.acceleration);
                    deplacerPerso(&p,dt,&dx);}
                    break;
                   /* case SDLK_UP:
                    p.up=1;
                                         p.acceleration+=0.003;
                    saut(&p,dt,&dy);
                    break;*/
                  case  SDLK_KP_PLUS:
                  if (ts<9999)
                  ts++;
                  break;
                 case SDLK_KP_MINUS:
                 if (ts<9999)
                 ts--;
                 break;
                 case SDLK_LCTRL:
                if (v<7)
                 v++;
                 break;
                }
                break;
                            }
        }

       if (dx>0)
      { p.acceleration-=0.001;
        printf("moins auto: %f \n",p.acceleration);
       deplacerPerso(&p,dt,&dx);
               }
               else if (dx<0) 
                { p.acceleration+=0.001;
                  printf("plus auto: %f \n",p.acceleration);
               deplacerPerso(&p,dt,&dx);}
             
                        
                        if (((p.direction==0)||(p.direction==1)))
                        {animerperso(p,ecran,&t1,&t,&t2,&t3,dx,v,ts);
                        }
                        
                      dt=SDL_GetTicks()-t_prev;

          


    }

    /*SDL_FreeSurface( p.tab1[1]);
        SDL_FreeSurface(p.tab2[1]);
        SDL_FreeSurface( p.tabvie[1]);
        SDL_FreeSurface( p.tab1[2]);
        SDL_FreeSurface(p.tab2[2]);
        SDL_FreeSurface( p.tabvie[2]);
        SDL_FreeSurface( p.tab1[3]);
        SDL_FreeSurface(p.tab2[3]);
        SDL_FreeSurface( p.tabvie[3]);
        SDL_FreeSurface( p.tab1[4]);
        SDL_FreeSurface(p.tab2[4]);
        SDL_FreeSurface( p.tabvie[4]);
        SDL_FreeSurface( p.tab1[5]);
        SDL_FreeSurface(p.tab2[5]);
        SDL_FreeSurface( p.tabvie[5]);
        SDL_FreeSurface( p.tab1[6]);
        SDL_FreeSurface(p.tab2[6]);
        SDL_FreeSurface( p.tabvie[6]);
        SDL_FreeSurface( p.tab1[7]);
        SDL_FreeSurface(p.tab2[7]);
        SDL_FreeSurface( p.tabvie[7]);
           SDL_FreeSurface( p.tab1[7]);
        SDL_FreeSurface(p.tab2[7]);*/
   SDL_FreeSurface(p.imgscore);

    //SDL_FreeSurface(p.tab1[1]);
    SDL_FreeSurface(b.imgbackground);
        SDL_FreeSurface(ecran);
        TTF_Quit;
    SDL_Quit();
    }



