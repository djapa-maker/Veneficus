#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "fichier2.h"

int main(int argc, char *argv[])
{
  int continuer = 1;
  int y, k=4, f, interface, n, z, t;
  Mix_Music *musique;
  Mix_Chunk *son;
  SDL_Surface *ecran;
  SDL_Surface *imgbackground;
  SDL_Event event;
  menu m;
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);



  intialiser(&m);
  initanim(m.imgbackground);

  SDL_EnableKeyRepeat(70, 70);
  while (continuer)

  {

    animation(m, ecran, &t);

    affichage(interface, y, f, k, m, ecran, n);

    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        continuer = 0;
        break;

      case SDL_MOUSEMOTION:
        m.poscurseur.x = event.motion.x;
        m.poscurseur.y = event.motion.y;
        /*printf("largeur:%d \n",poscurseur.x);
        printf("hauteur:%d \n",poscurseur.y);*/
        if (interface == 0)
        { //curseur dans les intervals des images play/options/quit//
          if ((event.motion.x <= 428 && event.motion.x >= 100) && (event.motion.y <= 479 && event.motion.y >= 370))
          {
            y = 1;
          }
          else if ((event.motion.x < 429 && event.motion.x >= 100) && (event.motion.y <= 586 && event.motion.y > 500))
          {
            y = 2;
          }
          else if ((event.motion.x <= 450 && event.motion.x >= 90) && (event.motion.y <= 680 && event.motion.y >= 600))
          {
            y = 3;
          }
          else
            y = 0;
        }

        else if (interface == 1)
        {
          //curseur dans interval de la barre du  son//
          if ((event.motion.x <= 260 && event.motion.x >= 100) && (event.motion.y <= 420 && event.motion.y >= 380))
          {
            y = 1;
            z = 0;
          }
          else if ((event.motion.x < 420 && event.motion.x >= 260) && (event.motion.y <= 420 && event.motion.y > 380))
          {
            y = 1;
            z = 1;
          }
          else if ((event.motion.x <= 580 && event.motion.x >= 420) && (event.motion.y <= 420 && event.motion.y >= 380))
          {
            y = 1;
            z = 2;
          }
          if ((event.motion.x <= 740 && event.motion.x >= 580) && (event.motion.y <= 420 && event.motion.y >= 380))
          {
            y = 1;
            z = 3;
          }
          else if ((event.motion.x < 860 && event.motion.x >= 740) && (event.motion.y < 420 && event.motion.y > 380))
          {
            y = 1;
            z = 4;
          }

          //curseur dans interval des images "fullscreen"/"fenetre"//
          else if ((event.motion.x <= 415 && event.motion.x >= 94) && (event.motion.y <= 687 && event.motion.y >= 613))
          {
            y = 2;
            f = 0;
          }
          else if ((event.motion.x < 804 && event.motion.x >= 471) && (event.motion.y <= 687 && event.motion.y > 613))
          {
            y = 2;
            f = 1;
          }
        }
        break;

      case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button)
        {
        case SDL_BUTTON_LEFT:
          /*Mix_PlayChannel(-1, son, 0);*/
          if (interface == 0)
          {
            if (y == 1)
              interface = 2;
            else if (y == 2)
            {
              interface = 1;
              y = 1;
            }
            else if (y == 3)
              continuer = 0;
          }
          else if (interface == 1)
          {
            if (z == 0)
            {
              k = 0;
              y = 1;
            }
            else if (z == 1)
            {
              k = 1;
              y = 1;
            }
            else if (z == 2)
            {
              k = 2;
              y = 1;
            }
            else if (z == 3)
            {
              k = 3;
              y = 1;
            }
            else if (z == 4)
            {
              k = 4;
              y = 1;
            }

            else if (y == 2)
              switch (f)
              {
              case 0:
                n = 1;
                break;
              case 1:
                n = 2;
                break;
              }
          }
        }
        break;

      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
          if (interface == 0)
          {
            continuer = 0;
          }
          else if (interface == 1)
            interface = 0;
          else if (interface == 2)
            interface = 0;
          break;

        case SDLK_RETURN:

          if (interface == 0)
          {
            if (y == 1)
              interface = 2;
            else if (y == 2)
            {
              interface = 1;
              y = 1;
            }
            else if (y == 3)
              continuer = 0;
          }
          else if (interface == 1)
          {
            if (y == 2)
              switch (f)
              {
              case 0:
                n = 1;
                break;
              case 1:
                n = 2;
                break;
              }
          }
          break;
        case SDLK_UP:
          if (y == 0)
          {
            y = 3;
            break;
          }
          if (y == 3)
          {
            y = 2;
            break;
          }
          if (y == 2)
          {
            y = 1;
            break;
          }
          if (y == 1)
          {
            y = 3;
            break;
          }
        case SDLK_DOWN:
          if (y == 0)
          {
            y = 1;
            break;
          }
          if (y == 1)
          {
            y = 2;
            break;
          }
          if (y == 2)
          {
            y = 3;
            break;
          }
          if (y == 3)
          {
            y = 1;
            break;
          }
        case SDLK_RIGHT:
          if (y == 1)
          {
            if (k == 0)
            {
              k = 1;
              break;
            }
            if (k == 1)
            {
              k = 2;
              break;
            }
            if (k == 2)
            {
              k = 3;
              break;
            }
            if (k == 3)
            {
              k = 4;
              break;
            }
            if (k == 4)
            {
              k = 4;
              break;
            }
          }

          if (f == 0)
          {
            f = 1;
            break;
          }
          if (f == 1)
          {
            f = 1;
            break;
          }

        case SDLK_LEFT:
          if (y == 1)
          {
            if (k == 4)
            {
              k = 3;
              break;
            }
            if (k == 3)
            {
              k = 2;
              break;
            }
            if (k == 2)
            {
              k = 1;
              break;
            }
            if (k == 1)
            {
              k = 0;
              break;
            }
            if (k == 0)
            {
              k = 0;
              break;
            }
          }
          if (f == 0)
          {
            f = 0;
            break;
          }
          if (f == 1)
          {
            f = 0;
            break;
          }
          ///fermuture if(n==2)//
        } //fermuture switch(key event)//
      }   //fermuture switch(type event)//
    }
  }
  SDL_FreeSurface(ecran );
    SDL_FreeSurface(m.imgplay) ;
    SDL_FreeSurface(m.imgoption);
    SDL_FreeSurface(m.imgbackground[11]) ;
    SDL_FreeSurface(m.imgquit) ;
    SDL_FreeSurface(m.imgcurseur) ;
SDL_FreeSurface(m.textecm );
    SDL_FreeSurface(m.imgplay2 );
    SDL_FreeSurface(m.imgoption2) ;
    SDL_FreeSurface(m.imgquit2) ;
    SDL_FreeSurface(m.seq);
    SDL_FreeSurface(m.imgv100) ;
    SDL_FreeSurface(m.imgfullscreen);
    SDL_FreeSurface(m.imgnormalscreen) ;
    SDL_FreeSurface(m.imgfullscreen2) ;
    SDL_FreeSurface(m.imgnormalscreen2) ;
    SDL_FreeSurface(m.imgtxtaffichaage) ;
    SDL_FreeSurface(m.imgtxtvolume)  ;
    SDL_FreeSurface(m.imgoption3) ;
    SDL_FreeSurface(m.imgv0) ;
    SDL_FreeSurface(m.imgv25) ;
    SDL_FreeSurface(m.imgv75) ;
    SDL_FreeSurface(m.imgv50) ;
    SDL_FreeSurface(m.imgicon);
    SDL_FreeSurface(m.imgbackfull);
    SDL_FreeSurface(m.imgbackloading);
  SDL_Quit();

  TTF_Quit;
  Mix_FreeChunk(son);
  Mix_FreeMusic(musique);
}

