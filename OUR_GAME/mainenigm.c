#include "enigmealf.h"
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

  int r;             // 1 si resolu , 0 si non resolu
  int y = 0;         // pos of mouse , 1 on yes ,  or 2 on no or  0 none
  int enigmealfalf = 1; // 1 si enigmealf commence 0 si il  n y a pas dengime
  
  enigmealf ealf;
  SDL_Surface *ecran;
  SDL_Event event;

  // **************INIT enigmealf , ecran,generer enigmealf de fichier ************************

  SDL_Init(SDL_INIT_EVERYTHING);
  ecran = SDL_SetVideoMode(640, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL)
  {
    printf("unable to set video mo de:%s \n", SDL_GetError());
  }
  //**************POUR tester *******************
  //initPerso(&p);
  //save(p);
  //load(&p);

  TTF_Init();
  initialiser_enigmealf(&ealf);
  genererenigmealf(&ealf);

  // player coll with enigmealf al with file
  while (enigmealfalf)
  {

    afficherenigmealf(ealf, ecran);
    if (r == 1)
    {

      afficher_true(ecran, ealf);
      enigmealfalf = 0;
    }
    else if (r == 0)
    {

      afficher_false(ecran, ealf);
      enigmealfalf = 0;
    }

    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
      enigmealfalf = 0;
      break;

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_a:
        if (ealf.reponse == 0)
        {
          r = 0;
        }

        else
        {
          r = 1;
        }

        break;

      case SDLK_b:
        if (ealf.reponse == 0)
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
      ealf.poscurseur.x = event.motion.x;
      ealf.poscurseur.y = event.motion.y;
      /*printf("largeur:%d \n", e.poscurseur.x);
      printf("hauteur:%d \n", e.poscurseur.y);*/
      if ((event.motion.x <= 190 && event.motion.x >= 100) && (event.motion.y <= 560 && event.motion.y >= 500))
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

        if ((y == 1) && (ealf.reponse == 0))
          r = 0;
        else if ((y == 1) && (ealf.reponse == 1))
        {
          r = 1;
        }

        else if ((y == 2) && (ealf.reponse == 0))
          r = 1;
        else if ((y == 2) && (ealf.reponse == 1))
          r = 0;

        break;
      }
    }
    SDL_Flip(ecran);
  }
  SDL_Delay(3000);

  //free memory

  SDL_FreeSurface(ecran);
  
  TTF_Quit;
  SDL_Quit();
}
