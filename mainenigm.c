#include "enigmeal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int i=1;
    personnage p;
    enigme e;
    SDL_Surface *ecran;

    SDL_Init(SDL_INIT_EVERYTHING);
    ecran = SDL_SetVideoMode(650, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());
  }
    load (&p);
    initialiser_enigme(&e);
    initPerso(&p);
    save (p);

    genererEnigme(&e);
    while (i=1)
    {
      afficherEnigme(e, ecran);

    }
    
    
    
    
}