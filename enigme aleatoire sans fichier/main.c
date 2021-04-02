

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include "enigmealeatoire.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<math.h>


int main(int argc, char *argv[])
{SDL_Surface *ecran = NULL;
TTF_Init();
enigme e;
int reponsejuste=-1;

int bonnerep=-1;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
 ecran= SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);





e=generer();




int continuer=1;
 SDL_Event event;
//iniitenigme()//







while(continuer)
{afficherenigme(e,ecran);


if(reponsejuste==1) { affichage_repvraie(ecran);
                                        SDL_Delay(2000);
                                           continuer=0;  
                                              }

         else if(reponsejuste==0) {affichage_repfausse(ecran);}
                  

SDL_PollEvent(&event);


switch(event.type)
{case SDL_QUIT: continuer=0;break;


case SDL_KEYUP :
switch (event.key.keysym.sym)
{
case SDLK_KP1:if (e.numrepjuste==0) { reponsejuste=1;}
                        else(reponsejuste=0);
  break;


 case SDLK_KP2:if (e.numrepjuste==1) { reponsejuste=1;}
                        else(reponsejuste=0);

  break;
case SDLK_KP3:if (e.numrepjuste==2) {  reponsejuste=1;}
                       else(reponsejuste=0);
                       break;


    }//fermture du switch(event.key)

break;




 
   }   //fermture du switch(event.type)


}   //fermture du while(continuer)

SDL_Flip(ecran);

}






