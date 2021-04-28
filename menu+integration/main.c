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
#include "enigmestat.h"
#include "enigmealeatoire.h"
#include "enigmealf.h"

#define vitesse_max 40
#define G 10

int main(int argc, char *argv[])
{
  /*------------------------declaration ----------*/
  SDL_Event event;
  SDL_Surface *ecran = NULL;
  int direction, continuer = 1, frame = 0;
  const int FPS = 20;
  Background b;
  Background b1;
  Background b2;
  perso p, p1, p2;
  int v = 1, ts = 0;
  int v1 = 1, v2 = 1;
  int y=0;
  Uint32 start;
  Input I, I1, I2;
  int dt;
  Uint32 t_prev;
  minimap m;
  int loadd=0;
  int multijoueur = 0;
  int temps = 60;
  int f,k,n,interface=0,ym=0,z;
  int page = 0;  // 1:6 c'est le jeu  de stage 1->6, 7 enigme 1, 8 enigme 2, 9 enigme 3 , 0 menu principale
  int input = 0; //1 fleche right, 2 fleche left
 menu men;
  enigme enig; //tout ce qui concerne enigme statique//
  int reponsevraie = 0;

  enigme1 e1; // tout ce qui concerne enigme alea sans fichier//
  int reponsejuste = -1;
  int test1 = 0;

  int enigmeelf = 0;
  int teststat = 0;
  //***************enigme al aavec fichier

  enigmealf ealf;
  int r = 3;            // 1 si resolu , 0 si non resolu
  int ye = 0;            // pos of mouse , 1 on yms ,  or 2 on no or  0 none
  int enigmealfalf = 0; // 1 si enigmealf commence 0 si il  n y a pas dengime

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
  if (multijoueur == 0)
    initBack(&b);
  else if (multijoueur == 1)
  {
    initBack(&b1);
    b1.imgBack1 = IMG_Load("ice_level_multijoueur.png");
    b1.scroll.y = 0;
    b1.scroll.h = 393;
    b1.imageM = IMG_Load("bgmasquemultijoueur.jpg");
    initBack(&b2);
    b2.imgBack1 = IMG_Load("ice_level_multijoueur.png");
    b2.posBack1.y = 393;
    b2.scroll.y = 0;
    b2.scroll.h = 393;
    b2.imageM = IMG_Load("bgmasquemultijoueur.jpg");
  }
  if (multijoueur == 0)
  {
    initialiser_input(&I);
  initPerso(&p);
  initmap(&m);
  I.jump = 0;
  I.fall = 1;
  //init enigstat//
  init_enigme(&enig);

  //init e1//
  e1 = generer();
  init_enigme1(&e1);

  //*********INIT enigme al avec fichier***********
  initialiser_enigmealf(&ealf);
  genererenigmealf(&ealf);
  
  load(&p,&b,&m,&ts,&v);
  }
  else if(multijoueur==1)
  {
  initPerso2(&p1);
  initPerso2(&p2);
  p1.poshero.y = 230;
  p2.poshero.y = 630;
  I1.jump = 0;
  I1.fall = 1;
  I2.jump = 0;
  I2.fall = 1;
  }
  
  if(page==0)
  {
  intialiser(&men);
  
  }
  /**********boucle du jeu*******************/
  while (continuer)
  {
    start = SDL_GetTicks();
    input = 0;
    /******* Module d'affichage****/
    if (page == 1)
    {
      if (multijoueur == 0)
      {
        afficherBack(b, ecran);
        afficherminimap(m, ecran);
        affichertemps(temps, ecran);
        afficherPerso(p, ecran, ts, v, I,multijoueur);
      }

      else if (multijoueur == 1)
      {
        afficherBack1(b1, ecran);
        afficherBack1(b2, ecran);
        afficherminimap(m, ecran);
        affichertemps(temps, ecran);
        afficherPerso(p1, ecran, ts, v1, I1,multijoueur);
        afficherPerso(p2, ecran, ts, v2, I2,multijoueur);
      }
    }
    else if(page==0)
    {
      affichagemenuanim (men,ecran,&continuer);
       affichage(interface,y,f,k, men,ecran,n);
    }
    // udpate

    /** enigme stat**/
    if ((b.scroll.x >= 2178) && (b.scroll.x <= 2185))
    {
      teststat = 1;
      afficher_enigme(ecran, enig);

      if (reponsevraie == 1)
      {

        rep_vrai(ecran, enig);
        teststat = 0;
      }
      else if (reponsevraie == -1)
      {
        rep_fausse(ecran, enig);
        teststat = 0;
      }
    }

    ////***initilisation des enigmes ****////////

    if ((b.scroll.x >= 6270) && (b.scroll.x <= 6290))
    {
      test1 = 1;
      afficherenigme(e1, ecran); //affichage de la 2 eme enigme (mahmoud)

      if (reponsejuste == 1)
      {

        affichage_repvraie(ecran, e1);
        test1 = 0;
      }

      else if (reponsejuste == 0)
      {
        //yonkoslou fi score//

        affichage_repfausse(ecran, e1);
        test1 = 0;
      }
    }

    /** mtaa adem****/

    if ((p.poshero.x >= 1160) && (p.poshero.x <= 1190)) /*&& (r != 1) )*/
    {
      enigmealfalf = 1;
      enigmeelf = 1;
      //test1 = 1;

      afficherenigmealf(ealf, ecran);

      if (r == 1)
      {
        //test1 = 0;
        enigmeelf = 0;

        afficher_true(ecran, ealf);
        enigmealfalf = 0;
      }
      else if (r == 0)
      {
        //test1 = 0;
        enigmeelf = 0;

        afficher_false(ecran, ealf);
        enigmealfalf = 0;
      }
    }

    /****** Module input****/
    
    while (SDL_PollEvent(&event))
    {
      if(page==0)
      {
       switch (event.type)
      {
      case SDL_QUIT:
        continuer = 0;
        break;

      case SDL_MOUSEMOTION:
        men.poscurseur.x = event.motion.x;
        men.poscurseur.y = event.motion.y;
        //printf("largeur:%d \n",m.poscurseur.x);
        //printf("hauteur:%d \n",m.poscurseur.y);
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
          y=0;
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
        
        else if (interface == 2)
        { 
          if ((event.motion.x <= 428 && event.motion.x >= 100) && (event.motion.y <= 479 && event.motion.y >= 370))
          {
      
            y = 1;
          }
          else if ((event.motion.x < 429 && event.motion.x >= 100) && (event.motion.y <= 586 && event.motion.y > 500))
          {
         // printf("boutton option");
            y = 2;
          }
          else if ((event.motion.x <= 450 && event.motion.x >= 90) && (event.motion.y <= 680 && event.motion.y >= 600))
          {
       //quit
            y = 3;
          }
          else
            y = 0;
        }
        break;

     //comportement du bouton 
      case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button)
        {
        case SDL_BUTTON_LEFT:
          //Mix_PlayChannel(-1, son, 0);
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
          
          else if(interface==2) //new game
          {printf("la page est : %d ",page);
            if (y == 1)
            {
              page=1;

            } 
              else if (y == 2)
              {
              page=1;
              loadd=1;
              }
              else if (y == 3)
             page=3;
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
          else if (interface == 2)
          {
            if (y == 1)
              page=1;
              else if (y == 2)
              page=2;
              else if (y == 3)
              page=3;
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
      } 
      }
      if (page == 1)
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
            case SDLK_s:
            save(p,b,m,ts,v);
            break;
          case SDLK_RIGHT:
            if ((v != 7))
            {
              I.right = 1;
              p.direction = 0;
            }

            break;
          case SDLK_LEFT:
            if ((v != 7))
            {
              I.left = 1;
              p.direction = 1;
            }
            break;
          case SDLK_UP:
            /*if (p.poshero.y <= 400 && p.poshero.y >= ((ecran->h) / 2) || (b.scroll.y == 0 && p.poshero.y <= 400))
          {
            printf("poshero %d", p.poshero.y);
            printf("pos cam %d", b.scroll.y);

           

            if (p.poshero.y <= 30)
              p.poshero.y = 30;*/
            // }

            if ((v != 7))
            {
              I.jump = 1;
              printf("  input jump=%d\n", I.jump);
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
            ///input enigme alea sans fichiers//
          case SDLK_KP1:
            if (e1.numrepjuste == 0)
            {
              reponsejuste = 1;
              ts += 50;
            }
            else
            {
              reponsejuste = 0;
              ts -= 50;
              v++;
            }
            break;

          case SDLK_KP2:
            if (e1.numrepjuste == 1)
            {
              reponsejuste = 1;
              ts += 50;
            }

            else
            {

              reponsejuste = 0;
              ts -= 50;
              v++;
            }

            break;

          case SDLK_KP3:
            if (e1.numrepjuste == 2)
            {
              reponsejuste = 1;
              ts += 50;
            }
            else
            {
              reponsejuste = 0;
              ts -= 50;
              v++;
            }
            break;
            //****input enigstat****//
          case SDLK_a:
            reponsevraie = -1;
            ts -= 50;
            v++;

            break;
          case SDLK_b:
            reponsevraie = 1;
            ts += 50;

            break;
          case SDLK_c:
            reponsevraie = -1;
            ts -= 50;
            v++;

            break;

          //******input enigme alea avec fichiers**********
          case SDLK_v:
            if (enigmealfalf = 1)
            {

              if (ealf.reponse == 0)
              {
               // SDL_Delay(2000);
                r = 0;
                ts -= 50;
                v++;
              }

              else
              {
                //SDL_Delay(2000);
                r = 1;
                ts += 50;
              }

              break;
            }

          case SDLK_f:
            if (enigmealfalf = 1)
            {
              if (ealf.reponse == 0)
              {
                //SDL_Delay(2000);
                r = 1;
                ts += 50;
                ts -= 50;
                v++;
              }

              else
              {
            //SDL_Delay(2000);
                r = 0;
              }
            }

            break;
          }
          break;
        case SDL_MOUSEMOTION:
          ealf.poscurseur.x = event.motion.x;
          ealf.poscurseur.y = event.motion.y;
          /*printf("largeur:%d \n", e.poscurseur.x);
      printf("hauteur:%d \n", e.poscurseur.y);*/
          if ((event.motion.x <= 490 && event.motion.x >= 400) && (event.motion.y <= 560 && event.motion.y >= 500))
          {
            ye = 1;
          }
          else if ((event.motion.x < 770 && event.motion.x >= 700) && (event.motion.y < 560 && event.motion.y > 500))
          {
            ye = 2;
          }
        case SDL_MOUSEBUTTONDOWN:
          switch (event.button.button)
          {
          case SDL_BUTTON_LEFT:

            if ((ye == 1) && (ealf.reponse == 0))
            {
              r = 0;
              ts -= 50;
              v++;
            }
            else if ((ye == 1) && (ealf.reponse == 1))
            {
              r = 1;
              ts += 50;
            }
            else if ((ye == 2) && (ealf.reponse == 0))
            {
              r = 1;
              ts += 50;
            }
            else if ((ye == 2) && (ealf.reponse == 1))
            {
              r = 0;
              ts -= 50;
              v++;
            }

            break;
          }
        }
      }
    }
    /****Module update *******/

    if (page == 1)
    {
      if (multijoueur == 0)
      {
        if ((I.right == 1) && (v != 7) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0)) // fleche right
        {
          if (p.poshero.x < (ecran->w / 2) || b.scroll.x >= (b.scroll.w - ecran->w)) // deplacement
          {
            if (collisionPP(p, b.imageM, b, I) == 0) // pas de collision avec background
            {
              printf("deplacement\n");
              /**** update personage *****/
              p.X++;
              mouvementright(&p);
              p.direction = 0;
              /** update mini map***/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p.poshero.x / 172;
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
          {
            if (collisionPP(p, b.imageM, b, I) == 0) // pas de collision
            {
              printf("scrolling\n");
              printf("pas de collision\n");
              printf("poshero:%d", p.poshero.x);
              // p.X++;
              //mouvementright(&p);
              p.direction = 0;
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p.poshero.x / 172;
              printf("p.X:%d \n", p.X);
              scrollingBack(&b, p, I);
            }

            /*update mini map***/
            /**/
          }
        } /*
          if (p.poshero.x >= (ecran->w - 239))
          {
            p.poshero.x = (ecran->w - 239);
            m.pospoint.x = 100;
          }*/

        else if ((v != 7) && (I.left == 1) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0))
        {
          if ((b.scroll.x >= 50 && b.scroll.x < (b.scroll.w - ecran->w)) || (b.scroll.x == (b.scroll.w - ecran->w) && p.poshero.x <= 760))
          {
            //scrollingBack(&b, p, &p.X, dt);
            if (collisionPP(p, b.imageM, b, I) == 0)
            {
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x -= p.poshero.x / 172;
              //p.X++;
              //mouvementleft(&p);
              p.direction = 1;
              scrollingBack(&b, p, I);
            }
          }

          /*update mini map***/
          /* if (m.pospoint.x >= m.posminimap.x + 1240)
          m.pospoint.x -= p.poshero.x/80;*/

          else if (b.scroll.x < 50 || b.scroll.x >= (b.scroll.w - ecran->w))
          {
            if (collisionPP(p, b.imageM, b, I) == 0)
            {

              p.X++;
              mouvementleft(&p);
              p.direction = 1;
              printf("dep left poshero %d abcisse cam : %d\n", p.poshero.x, b.scroll.x);
              if (m.pospoint.x >= m.posminimap.x)
                m.pospoint.x -= p.poshero.x / 172;
              if (p.poshero.x <= 60)
              {
                p.poshero.x = 60;
                m.pospoint.x = 100;
              }
            }
          }
        }
      }

      else if (multijoueur == 1)
      {           

        if ((I1.right == 1) && (v1 != 7) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0)) // fleche right
        {
          if (p1.poshero.x < (ecran->w / 2) || b1.scroll.x >= (b1.scroll.w - ecran->w)) // deplacement
          {
            if (collisionPP(p1, b1.imageM, b1, I1) == 0) // pas de collision avec background
            {
              printf("deplacement\n");
              /**** update personage *****/
              p1.X++;
              mouvementright(&p1);
              p1.direction = 0;
              /** update mini map***/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p1.poshero.x / 172;
              printf("dep right poshero %d  abcisse cam %d\n", p1.poshero.x, b1.scroll.x);
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
          {
            if (collisionPP(p1, b1.imageM, b1, I1) == 0) // pas de collision
            {
              printf("scrolling joueur1\n");
              printf("pas de collision\n");
              printf("poshero:%d", p1.poshero.x);
              // p.X++;
              //mouvementright(&p);
              p1.direction = 0;
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p1.poshero.x / 172;
              printf("p.X:%d \n", p1.X);
              scrollingBack(&b1, p1, I1);
            }

            /*update mini map***/
            /**/
          }
        } /*
          if (p.poshero.x >= (ecran->w - 239))
          {
            p.poshero.x = (ecran->w - 239);
            m.pospoint.x = 100;
          }*/

        else if ((v1 != 7) && (I1.left == 1) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0))
        {
          if ((b1.scroll.x >= 50 && b1.scroll.x < (b1.scroll.w - ecran->w)) || (b1.scroll.x == (b1.scroll.w - ecran->w) && p1.poshero.x <= 760))
          {
            //scrollingBack(&b, p, &p.X, dt);
            if (collisionPP(p1, b1.imageM, b1, I1) == 0)
            {
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x -= p1.poshero.x / 172;
              //p.X++;
              //mouvementleft(&p);
              p1.direction = 1;
              scrollingBack(&b1, p1, I1);
            }
          }

          /*update mini map***/
          /* if (m.pospoint.x >= m.posminimap.x + 1240)
          m.pospoint.x -= p.poshero.x/80;*/

          else if (b1.scroll.x < 50 || b1.scroll.x >= (b1.scroll.w - ecran->w))
          {
            if (collisionPP(p1, b1.imageM, b1, I1) == 0)
            {

              p1.X++;
              mouvementleft(&p1);
              p1.direction = 1;
              printf("dep left poshero %d abcisse cam : %d\n", p1.poshero.x, b1.scroll.x);
              if (m.pospoint.x >= m.posminimap.x)
                m.pospoint.x -= p1.poshero.x / 172;
              if (p1.poshero.x <= 60)
              {
                p1.poshero.x = 60;
                m.pospoint.x = 100;
              }
            }
          }
        }
        //////////joueurrrrr2222222/////////
        if ((I2.right == 1) && (v2 != 7) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0)) // fleche right
        {
          if (p2.poshero.x < (ecran->w / 2) || b2.scroll.x >= (b2.scroll.w - ecran->w)) // deplacement
          {
            if (collisionPP(p2, b2.imageM, b2, I2) == 0) // pas de collision avec background
            {
              printf("deplacement\n");
              /**** update personage *****/
              p2.X++;
              mouvementright(&p2);
              p2.direction = 0;
              /** update mini map***/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p2.poshero.x / 172;
              printf("dep right poshero %d  abcisse cam %d\n", p2.poshero.x, b2.scroll.x);
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
          {
            if (collisionPP(p2, b2.imageM, b2, I2) == 0) // pas de collision
            {
              printf("scrolling\n");
              printf("pas de collision\n");
              printf("poshero:%d", p2.poshero.x);
              // p.X++;
              //mouvementright(&p);
              p2.direction = 0;
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p2.poshero.x / 172;
              printf("p.X:%d \n", p2.X);
              scrollingBack(&b2, p2, I2);
            }

            /*update mini map***/
            /**/
          }
        } /*
          if (p.poshero.x >= (ecran->w - 239))
          {
            p.poshero.x = (ecran->w - 239);
            m.pospoint.x = 100;
          }*/

        else if ((v2 != 7) && (I2.left == 1) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0))
        {
          if ((b2.scroll.x >= 50 && b2.scroll.x < (b2.scroll.w - ecran->w)) || (b2.scroll.x == (b2.scroll.w - ecran->w) && p2.poshero.x <= 760))
          {
            
            if (collisionPP(p2, b2.imageM, b2, I2) == 0)
            {
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x -= p2.poshero.x / 172;
              //p.X++;
              //mouvementleft(&p);
              p2.direction = 1;
              scrollingBack(&b2, p2, I2);
            }
          }

          /*update mini map***/
          /* if (m.pospoint.x >= m.posminimap.x + 1240)
          m.pospoint.x -= p.poshero.x/80;*/

          else if (b2.scroll.x < 50 || b2.scroll.x >= (b2.scroll.w - ecran->w))
          {
            if (collisionPP(p2, b2.imageM, b2, I2) == 0)
            {

              p2.X++;
              mouvementleft(&p2);
              p2.direction = 1;
              printf("dep left poshero %d abcisse cam : %d\n", p2.poshero.x, b2.scroll.x);
              if (m.pospoint.x >= m.posminimap.x)
                m.pospoint.x -= p2.poshero.x / 172;
              if (p2.poshero.x <= 60)
              {
                p2.poshero.x = 60;
                m.pospoint.x = 100;
              }
            }
          }
        }
      }
    }
   if (multijoueur == 0)
    {
      if ((collisionPP(p, b.imageM, b, I) == 0))
      {
        p.gravity = 400;
        p.jumpspeed = 40;
        jumpin(&p, &I);
        gravity(&p, &I);
      }
      else
      {
        p.gravity = 100;
        p.jumpspeed = 1;
        jumpin(&p, &I);
        gravity(&p, &I);
      }
      if ((p.direction == 0) && (collisionPP1(p, b.imageM, b, I) == 1))
      {
       
        v++;
        p.poshero.x -= 100;
        ts -= 10;
      }
      else if ((p.direction == 1) && (collisionPP1(p, b.imageM, b, I) == 1))
      {
       
        v++;
        p.poshero.x += 100;
        ts -= 10;
      }
    }
    
     if (multijoueur == 1)
    {
      if ((collisionPP(p1, b1.imageM, b1, I1) == 0))
      {
        p1.gravity = 230;
        p1.jumpspeed = 20;
        jumpin(&p1, &I1);
        gravity(&p1, &I1);
      }
      
      if ((p1.direction == 0) && (collisionPP1(p1, b1.imageM, b1, I1) == 1))
      {
       
        v1++;
        p1.poshero.x -= 100;
        ts -= 10;
      }
      else if ((p1.direction == 1) && (collisionPP1(p1, b1.imageM, b1, I1) == 1))
      {
       
        v1++;
        p1.poshero.x += 100;
        ts -= 10;
      }
      if ((collisionPP(p2, b2.imageM, b2, I2) == 0))
      {
        p2.gravity = 630;
        p2.jumpspeed = 20;
        jumpin(&p2, &I2);
        gravity(&p2, &I2);
      }
      else
      {
        p2.gravity = 100;
        p2.jumpspeed = 1;
        jumpin(&p2, &I2);
        gravity(&p2, &I2);
      }
      if ((p2.direction == 0) && (collisionPP1(p2, b2.imageM, b2, I2) == 1))
      {
       
        v2++;
        p2.poshero.x -= 100;
        ts -= 10;
      }
      else if ((p2.direction == 1) && (collisionPP1(p2, b2.imageM, b2, I2) == 1))
      {
        
        v2++;
        p2.poshero.x += 100;
        ts -= 10;
      }
    }
    animerperso(&p, ecran, v, &I);
    animerperso(&p1, ecran, v1, &I1);
    animerperso(&p2, ecran, v2, &I2);

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
  freesurface(p1, ecran);
  freesurface(p2, ecran);
  TTF_Quit;
  SDL_FreeSurface(ecran);
  SDL_FreeSurface(b.imgBack1);

  SDL_Quit;
  free_enigmealf(&ealf);
  free_enigmestat(&enig);
  free_enigmealea(&e1);
}