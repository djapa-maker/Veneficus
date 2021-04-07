
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
 
    int posint,poslimit;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    TTF_Init();
    ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    initPerso(&p);
    init(&b);
    SDL_EnableKeyRepeat(90, 90);
    while (continuer)
    {


        t_prev=SDL_GetTicks();
        aff(b,ecran);
afficherPerso(p,ecran,dx,ts,v,dy);
p.frapper=0;
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
                
                    if ((v!=7)&&(p.jump==0)&&(p.frapper==0)&&(p.fall==1))
                    {
                        p.direction=0;
                        p.acceleration+=0.007;
                        printf("plus:%f \n",p.acceleration);
                        deplacerPerso(&p,dt,&dx);
                    }
                    break;
                case SDLK_LEFT:
                    if ((v!=7)&&(p.jump==0)&&(p.frapper==0)&&(p.fall==1))
                    {
                        p.direction=1;
                        p.acceleration-=0.003;
                        printf("moins:%f \n",p.acceleration);
                        deplacerPerso(&p,dt,&dx);
                    }
                    break;
                case SDLK_SPACE:
                    if ((v!=7)&&(p.jump==0)&&(p.fall==1))
                    {p.frapper=1;
                     printf("frapper1\n");}
                    break;

                case SDLK_UP:
                if (v!=7)
           	p.jump=1; 



                    break;
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

        if ((dx>0)&&(p.distancedown==0)&&(p.distanceup!=1))
        {
            p.acceleration-=0.0009;
            printf("moins  auto: %f \n",p.acceleration);
            deplacerPerso(&p,dt,&dx );
        }


        else if ((dx<0)&&(p.distancedown==0)&&(p.distanceup!=1))
        {
            p.acceleration+=0.001;
            printf("plus auto: %f \n",p.acceleration);
            deplacerPerso(&p,dt,&dx);
        }
            
       
       
jumpin(&p,dt,dx);
gravity(&p);
animerperso(&p,ecran,dx,dy,v);
 dt=SDL_GetTicks()-t_prev;
 SDL_Flip(ecran);


    }

 freesurface(p,ecran, b);



    TTF_Quit;
    SDL_Quit();
}

