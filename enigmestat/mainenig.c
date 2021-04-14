#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "enigmestat.h"

int main(int argc, char *argv[])
{
TTF_Init();
SDL_Event event;
SDL_Surface *ecran=NULL;
enigme enig;
int continuer = 1,reponsevraie=0;// 0 rien, 1 si rep vraie, -1 si  rep est fausse
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
ecran=SDL_SetVideoMode(1399,787,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
init_enigme(&enig);
  while(continuer)
  {
       afficher_enigme(ecran,enig);

       if(reponsevraie==1)
      {
        
        rep_vrai(ecran,enig);
        continuer=0;
        
      }
       else if(reponsevraie==-1)
      {
        rep_fausse(ecran,enig);
        continuer=0;
      }

       while(SDL_PollEvent(&event))
         {
           switch (event.type)

            {
              case SDL_QUIT:
               continuer=0;
                break;
              case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
            {

              case SDLK_a:
               reponsevraie=-1;
               
              break;
              case SDLK_b:
               reponsevraie=1;
               
              break;
              case SDLK_c:
               reponsevraie=-1;
               
               
              break;

            } 


            }
         }
SDL_Flip(ecran);
  
  }
 SDL_Delay(3000);
 SDL_Quit();
 TTF_Quit;
}
