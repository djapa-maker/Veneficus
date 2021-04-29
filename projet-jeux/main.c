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
#include "hero.h"
#include "jeux.h"
#define vitesse_max 40
#define G 10

int main()
{
  /*------------------------declaration ----------*/
  SDL_Event event;
  SDL_Surface *ecran = NULL;
  int direction, continuer = 1, frame = 0,interface=0,n,y,k,f;
  const int FPS = 20;
  Background b;
  perso p;
  menu menu;
  animation anim;
  int v = 1, ts = 0;
  Uint32 start;
  Input I;
  int dt;
  Uint32 t_prev;
  minimap m;
  int temps = 60;
  int page = 0; // 1:6 c'est le jeu  de stage 1->6, 7 enigme 1, 8 enigme 2, 9 enigme 3 , 0 menu principale
  int input = 0;     //1 fleche right, 2 fleche left

  /*--------------------initialisation SDL*********/
  TTF_Init();
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0)
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
  SDL_EnableKeyRepeat(100, 100);
  /*******initialisation des erntités*************/
  initanim(&anim);
  intialiser(&menu);
  initBack(&b);
  initPerso(&p);
  initmap(&m);
  initialiser_input(&I);
    I.jump = 0;

  /**********boucle du jeu*******************/
  while (continuer)
  {

    start = SDL_GetTicks();
    input = 0;
    /******* Module d'affichage****/
    if (page==0)
  {
    
    Animation(menu,ecran,&continuer,anim);
    
    
  }
    else if (page == 1)
    {
      afficherBack(b, ecran);
      afficherminimap(m, ecran);
      afficherPerso(p, ecran, ts, v, I);
      affichertemps(temps, ecran);
    }
    // udpate

    /****** Module input****/
    while (SDL_PollEvent(&event))
    {
      initialiser_input(&I);

      switch (event.type)
      {
      case SDL_QUIT:
        continuer = 0;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:
          if (v != 7)
          {
            I.right = 1;
            p.direction = 0;
          }

          break;
        case SDLK_LEFT:
          if (v != 7)
          {
            I.left = 1;
            p.direction = 1;
          }
          break;
        case SDLK_UP:
          if (p.poshero.y <= 400 && p.poshero.y >= ((ecran->h) / 2) || (b.scroll.y == 0 && p.poshero.y <= 400))
          {
            printf("poshero %d", p.poshero.y);
            printf("pos cam %d", b.scroll.y);

            if ((p.poshero.y == 400) && (v != 7))
            {
              I.jump = 1;
              saut(&p);
            }

            /*if (p.poshero.y <= 30)
              p.poshero.y = 30;*/
          }
          else if (p.poshero.y < 393)
          {
            printf("poshero %d", p.poshero.y);
            printf("pos cam %d", b.scroll.y);
            scrollingBack(&b, p, I);
          }
          break;
        case SDLK_SPACE:
          if (v != 7)
          {
            I.fight = 1;
            printf("frapper1\n");
          }
          break;
        case SDLK_KP_PLUS:
          if (ts < 9999)
            ts++;
          break;
        case SDLK_KP_MINUS:
          if (ts < 9999)
            ts--;
          break;
        case SDLK_LCTRL:
          if (v < 7)
            v++;
          break;
        }

        break;
      }
    }

    /****Module update *******/

    if (page == 1)
    {
      if ((I.right == 1) && (v != 7)) // fleche right
      {
        if (p.poshero.x < (ecran->w / 2) || b.scroll.x >= (b.scroll.w - ecran->w)) // deplacement
        {
          if (collisionPP(p, b.imageM, b) == 0) // pas de collision avec background
          {
            printf("deplacement\n");
            /**** update personage *****/
            p.X++;
            mouvementright(&p);
            p.direction = 0;
            /** update mini map***/
            if (m.pospoint.x <= m.posminimap.x + 1240)
              m.pospoint.x += p.X;
            printf("dep right poshero %d  abcisse cam %d\n", p.poshero.x, b.scroll.x);
          }
          // else
          { // famma collision

            // condition de collision avec enegime1
            // condition de collision avec enegime2
            // condition de collision avec enegime3
          }

          //  if( collision bouding box)// collision avec enemie
        }
        else
        // scrolling  if (p.poshero.x >= (ecran->w / 2))
        {
          if (collisionPP(p, b.imageM, b) == 0) // pas de collision
          {
            printf("scrolling\n");
            printf("pas de collision\n");

            // p.X++;
            //mouvementright(&p);
            p.direction = 0;
            //p.acceleration += 0.007;

            printf("p.X:%d \n", p.X);
            scrollingBack(&b, p, I);
          }

          /*update mini map***/
          if (m.pospoint.x <= m.posminimap.x + 1240)
            m.pospoint.x += 5;
        }
      } /*
          if (p.poshero.x >= (ecran->w - 239))
          {
            p.poshero.x = (ecran->w - 239);
            m.pospoint.x = 100;
          }*/

      else if ((v != 7) && (I.left == 1))
      {
        printf("input done");
        if ((b.scroll.x >= 50 && b.scroll.x < (b.scroll.w - ecran->w)) || (b.scroll.x == (b.scroll.w - ecran->w) && p.poshero.x <= 760))
        {
          //scrollingBack(&b, p, &p.X, dt);
 if (collisionPP(p, b.imageM, b) == 0) {
          //p.X++;
          //mouvementleft(&p);
          p.direction = 1;
          scrollingBack(&b, p, I);}
        }

        /*update mini map***/
        if (m.pospoint.x >= m.posminimap.x + 1240)
          m.pospoint.x -= 5;

        else if (b.scroll.x < 50 || b.scroll.x >= (b.scroll.w - ecran->w))
        {
          if (collisionPP(p, b.imageM, b) == 0)
          {

            p.X++;
            mouvementleft(&p);
            p.direction = 1;
            printf("dep left poshero %d abcisse cam : %d\n", p.poshero.x, b.scroll.x);
            if (m.pospoint.x >= m.posminimap.x)
              m.pospoint.x -= 5;
            if (p.poshero.x <= 60)
            {
              p.poshero.x = 60;
              m.pospoint.x = 100;
            }
          }
        }
      }
    }
    p.poshero.y += p.Y;
    p.Y += G;
    if (p.poshero.y > 400)
    {
      p.Y = 0;
      p.poshero.y = 400;
          I.jump = 0;

      // I.jump = 0;
    }

    animerperso(&p, ecran, v, &I);
    dt = SDL_GetTicks() - t_prev;
    SDL_Flip(ecran);
    frame++;
    if (frame == 30)
    {
      if (temps > 0)
        temps--;
      frame = 0;
    }
    if (1000 / FPS > SDL_GetTicks() - start)
      SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
  }
  freesurface(p, ecran);
  TTF_Quit;
  SDL_FreeSurface(ecran);
  SDL_FreeSurface(b.imgBack1);
  SDL_Quit;
}
