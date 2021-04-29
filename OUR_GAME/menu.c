
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "menu.h"

void animback(menu *m)
{   if (m->frame == 10)
            (m->frame) = 1;
        else
            (m->frame)++;
  }

void intialisermenu(menu *m)
{


  m->imgplay = NULL;
  m->imgoption = NULL;
  m->imgbackground[12] = NULL;
  m->imgquit = NULL;
  m->imgcurseur = NULL;
  m->textecm = NULL;
  m->imgplay2 = NULL;
  m->imgoption2 = NULL;
  m->imgquit2 = NULL;
  m->imgv100 = NULL;
  m->imgfullscreen = NULL;
  m->imgnormalscreen = NULL;
  m->imgfullscreen2 = NULL;
  m->imgnormalscreen2 = NULL;
  m->imgtxtaffichaage = NULL;
  m->imgtxtvolume = NULL;
  m->imgoption3 = NULL;
  m->imgv0 = NULL;
  m->imgv25 = NULL;
  m->imgv75 = NULL;
  m->imgv50 = NULL;
  m->imgicon = NULL;  
  m->imgnewgame = NULL;
m->imgloadgame = NULL;
m->imgmultijoueur = NULL;
m->imgnewgame2 = NULL;
m->imgloadgame2 = NULL;
m->imgmultijoueur2 = NULL;
  SDL_Surface *ecran = NULL;
  SDL_WM_SetCaption("GAME", NULL);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }
    TTF_Font *police = NULL;
  SDL_Color couleurblanche = {255, 255, 255};
  TTF_Init();
  SDL_WM_SetCaption("GAME", NULL);
  police = TTF_OpenFont("texxte.ttf", 20);
   m->textecm = TTF_RenderText_Blended(police, "by:Computer Wizards", couleurblanche);

  m->musique = Mix_LoadMUS("scarymusic.mp3");
  Mix_PlayMusic(m->musique, -1);
  m->son = Mix_LoadWAV("clic.wav");
  m->imgplay = IMG_Load("imgplay1.png");
  m->imgoption = IMG_Load("imgoption1.png");
  m->imgquit = IMG_Load("imgquit1.png");

  m->imgplay2 = IMG_Load("imgplay2.png");
  m->imgoption2 = IMG_Load("imgoption2.png");
  m->imgquit2 = IMG_Load("imgquit2.png");

  m->imgfullscreen = IMG_Load("bouton full screen.png");
  m->imgnormalscreen = IMG_Load("bouton normal.png");
  m->imgfullscreen2 = IMG_Load("bouton full screen secondaire.png");
  m->imgnormalscreen2 = IMG_Load("bouton normal secondaire.png");

  m->imgtxtaffichaage = IMG_Load("texte affichage.png");
  m->imgtxtvolume = IMG_Load("texte volume.png");
  m->imgoption3 = IMG_Load("barre option.png");

  m->imgv0 = IMG_Load("barre de volume 0_.png");
  m->imgv25 = IMG_Load("barre de volume 25_.png");
  m->imgv50 = IMG_Load("barre de volume 50_.png");
  m->imgv75 = IMG_Load("barre de volume 75_.png");
  m->imgv100 = IMG_Load("barre de volume 100_.png");

  m->imgbackfull = IMG_Load("backround full screen.png");


 m->imgnewgame = IMG_Load("imgnewgame.png");
  m->imgloadgame = IMG_Load("imgloadgame.png");
   m->imgmultijoueur = IMG_Load("imgmultiplayer.png");
    m->imgnewgame2= IMG_Load("imgnewgame2.png");
  m->imgloadgame2 = IMG_Load("imgloadgame2.png");
   m->imgmultijoueur2 = IMG_Load("imgmultiplayer2.png");
   
  m->posbackground.x = 0;
  m->posbackground.y = 0;
  m->posbackground1.x = 0;
  m->posbackground1.y = 0;
  //m->posbackground2.x = 0;
  //m->posbackground2.y = 0;
  m->posvolume.x = 100;
  m->posvolume.y = 400;
  m->posplay.x = 100;
  m->posplay.y = 370;
  m->posoption.x = 100;
  m->posoption.y = 500;
  m->posquit.x = 90;
  m->posquit.y = 600;
  m->posnewgame.x = 100;
  m->posnewgame.y = 370;
  m->posloadgame.x = 100;
  m->posloadgame.y = 500;
  m->posmultijoueur.x = 90;
  m->posmultijoueur.y = 600;
  //POSITION INTERFACE = 1 , MENU OPTION
  m->posaffichage.x = 290;
  m->posaffichage.y = 480;
  m->postextevolume.x = 290;
  m->postextevolume.y = 300;
  m->posfullscreen.x = 70;
  m->posfullscreen.y = 600;
  m->posnormalscreen.x = 450;
  m->posnormalscreen.y = 600;
  m->posoption2.x = 150;
  m->posoption2.y = 70;
  m->postextecm.x = 1230;
   m->postextecm.y = 770;
  


  char char1[20]; // char pour stocker les no;s des images
    int t;
    for (t = 1; t < 10; t++)
    {
        sprintf(char1, "%d.png", t);
        m->imgbackground[t] = IMG_Load(char1);
    }
}


void affichagemenuanim (menu m, SDL_Surface *ecran)
{
    SDL_BlitSurface(m.imgbackground[m.frame], NULL, ecran, &m.posbackground);
}


void affichage(int interface, int y, int f, int k, menu m, SDL_Surface *ecran, int n)
{

  if (interface == 0)
  {
    
    if (y == 0)
    {

      SDL_BlitSurface(m.imgplay, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
    }
    else if (y == 1)
    {

      SDL_BlitSurface(m.imgplay2, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
      Mix_PlayChannel(0, m.son, 0);
    }
    else if (y == 2)
    {

      Mix_PlayChannel(0, m.son, 0);
      SDL_BlitSurface(m.imgplay, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption2, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
    }

    else if (y == 3)
    {

      SDL_BlitSurface(m.imgplay, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit2, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
      Mix_PlayChannel(0, m.son, 0);
    }

    //SDL_Flip(ecran);
  }
  else if (interface == 1)
  {

    if (y == 0)
    {
      //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);
      SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
      SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
      SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
      SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
      SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
      SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
    }
    else if (y == 1)
    {
      switch (k)
      {
      case 0:
        //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

        Mix_PauseMusic();

        break;
      case 1:
        //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

        break;
      case 2:
        //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
        break;
      case 3:
       // SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
        break;
      case 4:
        //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic(MIX_MAX_VOLUME);
        break;
      }
    }
    else if (y == 2)
    {
      switch (f)
      {
      case 0:

        switch (k)
        {
        case 0:
         // SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

          Mix_PauseMusic();

          break;
        case 1:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

          break;
        case 2:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
          break;
        case 3:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
          break;
        case 4:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME);
          break;
        }
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen2, NULL, ecran, &m.posfullscreen);
        Mix_PlayChannel(0, m.son, 0);
        break;
      case 1:

        switch (k)
        {
        case 0:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
          SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

          Mix_PauseMusic();

          break;
        case 1:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

          break;
        case 2:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
          break;
        case 3:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
          break;
        case 4:
          //SDL_BlitSurface(m.imgbackground[1], NULL, ecran, &m.posbackground);

          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME);
          break;
        }
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgnormalscreen2, NULL, ecran, &m.posnormalscreen);
        Mix_PlayChannel(0, m.son, 0);
        break;
      }

      switch (n)
      {
      case 1:
        /*SDL_BlitSurface(imgfullscreen2, NULL, ecran, &posfullscreen);*/
        ecran = SDL_SetVideoMode(1440, 900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        SDL_WM_ToggleFullScreen(ecran);
        // ecran= SDL_SetVideoMode(1320,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
        // SDL_BlitSurface(m.imgbackfull, NULL, ecran, &m.posbackground1);
        break;
      case 2:
        //ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgnormalscreen2, NULL, ecran, &m.posnormalscreen);
        break;
      }
    }

    //SDL_Flip(ecran);
  }
   else if (interface == 2)
  {
    y=0;
    if (y == 0)   //0 bouton active
    { SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame); //new game Na
      SDL_BlitSurface(m.imgloadgame , NULL, ecran, &m.posloadgame); //load game Na
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur); //multijoueurs Na
    }
    else if (y == 1) //new game
    {
      SDL_BlitSurface(m.imgnewgame2, NULL, ecran, &m.posnewgame); //new game Na
      SDL_BlitSurface(m.imgloadgame , NULL, ecran, &m.posloadgame); //load game Na
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur); //multijoueurs Na
      Mix_PlayChannel(0, m.son, 0);
    }
    else if (y == 2)  //load game
    {
      Mix_PlayChannel(0, m.son, 0);
     SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame); //new game Na
      SDL_BlitSurface(m.imgloadgame2 , NULL, ecran, &m.posloadgame); //load game Na
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur); //multijoueurs Na
    }

    else if (y == 3) //multijoueur
    {

      SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame); //new game Na
      SDL_BlitSurface(m.imgloadgame , NULL, ecran, &m.posloadgame); //load game Na
      SDL_BlitSurface(m.imgmultijoueur2, NULL, ecran, &m.posmultijoueur); //multijoueurs Na
      Mix_PlayChannel(0, m.son, 0);
    }

    //SDL_Flip(ecran);
  }
}

void freesurfacemenu(menu m, SDL_Surface *ecran)
    {SDL_FreeSurface(ecran );
    SDL_FreeSurface(m.imgplay) ;
    SDL_FreeSurface(m.imgoption);
  int i;
    for (i = 1; i < 10; i++)
    {SDL_FreeSurface(m.imgbackground[i]) ;}
    SDL_FreeSurface(m.imgquit) ;
    SDL_FreeSurface(m.imgcurseur) ;
    SDL_FreeSurface(m.textecm );
    SDL_FreeSurface(m.imgplay2 );
    SDL_FreeSurface(m.imgoption2) ;
    SDL_FreeSurface(m.imgquit2) ;
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
    SDL_FreeSurface(m.imgnewgame);
    SDL_FreeSurface(m.imgloadgame);
    SDL_FreeSurface(m.imgmultijoueur);
    SDL_FreeSurface(m.imgnewgame2);
    SDL_FreeSurface(m.imgloadgame2);
    SDL_FreeSurface(m.imgmultijoueur2);
    }