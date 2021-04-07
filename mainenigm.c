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

  int r;
  int y = 0;
  int continuer = 1;
  int i = 1;
  personnage p;
  enigme e;
  SDL_Surface *ecran;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);
  ecran = SDL_SetVideoMode(650, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());
  }
  TTF_Init();
  //load(&p);
  initialiser_enigme(&e);
  initPerso(&p);
  //save(p);

  genererEnigme(&e);

  while (continuer)
  {
    afficherEnigme(e, ecran);
    if (r == 1)
    {

      afficher_true(ecran, e);
    }
    else if (r == 0)
    {

      afficher_false(ecran, e);
    }

    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
      continuer = 0;
      break;

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_a:
        if (e.reponse == 0)
        {
          r = 0;
        }

        else
        {
          r = 1;
        }

        break;

      case SDLK_b:
        if (e.reponse == 0)
        {
          r = 1;
        }

        else
        {
          r = 0;
        }

        break;

      } //fermture du switch(event.key)

      break;

    case SDL_MOUSEMOTION:
      e.poscurseur.x = event.motion.x;
      e.poscurseur.y = event.motion.y;
      /*printf("largeur:%d \n", e.poscurseur.x);
      printf("hauteur:%d \n", e.poscurseur.y);*/
      if ((event.motion.x <= 190 && event.motion.x >= 100) && (event.motion.y <=560  && event.motion.y >= 500))
      {
        y = 1;
      }
      else if ((event.motion.x < 470 && event.motion.x >= 400) && (event.motion.y < 560 && event.motion.y > 500))
      {
        y = 2;
      }
    case SDL_MOUSEBUTTONDOWN:
      switch (event.button.button)
      {
      case SDL_BUTTON_LEFT:

        if ((y == 1) && (e.reponse == 0) )
        r=0;
        else if ((y == 1) && (e.reponse == 1))
        {
          r=1;
        }
        
         

        else if ((y == 2) && (e.reponse == 0))
        r=1;
        else if ((y == 2) && (e.reponse == 1))
        r=0;
          
        break;
      }
    }
    SDL_Flip(ecran);
  }
  SDL_FreeSurface(ecran);

  free_enigme(&e);
  TTF_Quit;
  SDL_Quit();
}
