#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "hero.h"

void intialiser(menu *m)
{
  m->imgnewgame = NULL;
  m->imgloadgame = NULL;
  m->imgmultijoueur = NULL;
  m->imgnewgame2 = NULL;
  m->imgloadgame2 = NULL;
  m->imgmultijoueur2 = NULL;
  m->imgplay = NULL;
  m->imgoption = NULL;
 // m->imgbackground[12] = NULL;
  m->imgquit = NULL;
  m->imgcurseur = NULL;
  m->textecm = NULL;
  m->imgplay2 = NULL;
  m->imgoption2 = NULL;
  m->imgquit2 = NULL;
  m->seq = NULL;
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

  m->imgfullscreen = IMG_Load("bouton_full_screen.png");
  m->imgnormalscreen = IMG_Load("bouton_normal.png");
  m->imgfullscreen2 = IMG_Load("bouton_full_screen_secondaire.png");
  m->imgnormalscreen2 = IMG_Load("bouton_normal_secondaire.png");

  m->imgtxtaffichaage = IMG_Load("texte_affichage.png");
  m->imgtxtvolume = IMG_Load("texte_volume.png");
  m->imgoption3 = IMG_Load("barre_option.png");

  m->imgv0 = IMG_Load("barre_de_volume0.png");
  m->imgv25 = IMG_Load("barre_de_volume25.png");
  m->imgv50 = IMG_Load("barre_de_volume_50.png");
  m->imgv75 = IMG_Load("barre_de_volume_75.png");
  m->imgv100 = IMG_Load("barre_de_volume100.png");

  m->imgbackfull = IMG_Load("backround_full_screen.png");
  m->imgbackloading = IMG_Load("backround_loading.png");
  m->imgnewgame = IMG_Load("imgnewgame.png");
  m->imgnewgame2 = IMG_Load("imgnewgame2.png");
  m->imgloadgame = IMG_Load("imgloadgame.png");
  m->imgloadgame2 = IMG_Load("imgloadgame2.png");
  m->imgmultijoueur = IMG_Load("imgmultiplayer.png");
  m->imgmultijoueur2 = IMG_Load("imgmultiplayer2.png"); 
  m->posbackground.x = 0;
  m->posbackground.y = 0;
  m->posbackground1.x = 0;
  m->posbackground1.y = 0;
  m->posbackground2.x = 0;
  m->posbackground2.y = 0;
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
  SDL_WM_SetIcon(IMG_Load("icon.png"), NULL);
}
void affichagemenuanim (menu m, SDL_Surface *ecran,int *continuer)
{
int y,p,f, interface=0, n, z;
    int page=0;
    int fullscren=2;
m.imgbackground1= NULL;
  m.imgbackground2= NULL;
  m.imgbackground3= NULL;
  m.imgbackground4= NULL;
  m.imgbackground5= NULL;
  m.imgbackground6= NULL;
  m.imgbackground7= NULL;
  m.imgbackground8= NULL;
  m.imgbackground9= NULL;
  m.imgbackground10= NULL;
  m.imgbackground11= NULL;


m.imgbackground1 = IMG_Load("A1.png");
       m.imgbackground2 = IMG_Load("A2.png");
        m.imgbackground3 = IMG_Load("A3.png");
       m.imgbackground4 = IMG_Load("A4.png");
        m.imgbackground5 = IMG_Load("A5.png");
         m.imgbackground6 = IMG_Load("A6.png");
        m.imgbackground7 = IMG_Load("A7.png");
        m.imgbackground8 = IMG_Load("A8.png");
        m.imgbackground9 = IMG_Load("A9.png");
        m.imgbackground10 = IMG_Load("A10.png");
         m.imgbackground11 = IMG_Load("A11.png");


   SDL_BlitSurface(m.imgbackground1, NULL, ecran, &m.posbackground); 
    SDL_BlitSurface(m.imgbackground2, NULL, m.imgbackground1, &m.posbackground);
   SDL_BlitSurface(m.imgbackground3, NULL, m.imgbackground2, &m.posbackground);
    SDL_BlitSurface(m.imgbackground4, NULL, m.imgbackground3, &m.posbackground);
    SDL_BlitSurface(m.imgbackground5, NULL, m.imgbackground4, &m.posbackground);
    SDL_BlitSurface(m.imgbackground6, NULL, m.imgbackground5, &m.posbackground);
    SDL_BlitSurface(m.imgbackground7, NULL, m.imgbackground6, &m.posbackground);
    SDL_BlitSurface(m.imgbackground8, NULL, m.imgbackground7, &m.posbackground);
    SDL_BlitSurface(m.imgbackground9, NULL, m.imgbackground8, &m.posbackground);
    SDL_BlitSurface(m.imgbackground10, NULL, m.imgbackground9, &m.posbackground);
   SDL_BlitSurface(m.imgbackground10, NULL, m.imgbackground10, &m.posbackground);
              
               //  motion(&page,continuer, m);
          
              
    
  
}
void affichage(int interface, int y, int f, int k, menu m, SDL_Surface *ecran, int n)
{


  if (interface == 0)
  {
     printf("interface 0\n");
    if (y == 0)
    {
       printf("y=0\n");
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

   // SDL_Flip(ecran);
  }
  
  
  else if (interface == 1)
  {
    
    if (y == 0)
    {
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
    
    else if (y == 2) // son
    {
      switch (f)
      {
      case 0:

        switch (k)
        {
        case 0:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

          Mix_PauseMusic();

          break;
        case 1:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

          break;
        case 2:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
          break;
        case 3:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
          break;
        case 4:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME);
          break;
        }
        
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen2 , NULL, ecran, &m.posfullscreen);
        Mix_PlayChannel(0, m.son, 0);
      
        break;
      
      case 1:

        switch (k)
        {
        case 0:
          SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
          SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

          Mix_PauseMusic();

          break;
        case 1:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

          break;
        case 2:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
          break;
        case 3:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
          break;
        case 4:
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
      case 1: // affichage fullscreen
  
            //ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
	    SDL_WM_ToggleFullScreen(ecran);
           //SDL_BlitSurface(m.imgbackfull, NULL, ecran, &m.posbackground1);
           //ecran= SDL_SetVideoMode(1399,787,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
           //SDL_BlitSurface(m.imgbackfull, NULL, ecran, &m.posbackground1);
        break;
      
      case 2:
        
          ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
         //ecran= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);        
       // SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
       // SDL_BlitSurface(m.imgnormalscreen2, NULL, ecran, &m.posnormalscreen);
        break;
      }
    }
   
    //SDL_Flip(ecran);
  }
  
  
  
  ///////////////////////////////////////////////////////////////////////
  
  
  else if (interface == 2)
  {
  
    if (y == 0)   //0 bouton active
    {

      SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame); //new game Normal
      SDL_BlitSurface(m.imgloadgame, NULL, ecran, &m.posloadgame); //load game Normal
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur); //multijoueurs Normal
    }
    else if (y == 1) //new game
    {
      
      SDL_BlitSurface(m.imgnewgame2, NULL, ecran, &m.posnewgame); //new game bleu
      SDL_BlitSurface(m.imgloadgame, NULL, ecran, &m.posloadgame); //load game Normal
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur); //multijoueurs NaNormal
      Mix_PlayChannel(0, m.son, 0);
    }
    else if (y == 2)  //load game
    {

      
      SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame);
      SDL_BlitSurface(m.imgloadgame2, NULL, ecran, &m.posloadgame);
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur);
      Mix_PlayChannel(0, m.son, 0);
    }

    else if (y == 3) //multijoueur
    {

      SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame);
      SDL_BlitSurface(m.imgloadgame, NULL, ecran, &m.posloadgame);
      SDL_BlitSurface(m.imgmultijoueur2, NULL, ecran, &m.posmultijoueur);
      Mix_PlayChannel(0, m.son, 0);
    }
 }
 
  SDL_Flip(ecran);
 
}




/*void menu1(int *page,int *continuer, menu m)
{

  SDL_Surface *ecran;

  if(*page==0) 
  {   
    animation(m);
  }
}
*/

void motion(int *page,int *continuer, menu m)
{

	int y;     //pour détecter l'evenement du bouton gauche de la sourie
	int k;   //4 pour afficher les bouton de la resolution de l'ecran (full screen, normal screen, ... ) elle peut avoir a*quatre valeurs, (1,2,3,4)
	int f; //resolution
	int interface;//0
	int n; 
	int z;
	int t;

	Mix_Music *musique;
        Mix_Chunk *son;
	SDL_Surface *ecran;
	SDL_Surface *imgbackground;
  
  SDL_Event event;
  if(*page==0) 
  //printf("in page =0");
  {     

   while (SDL_PollEvent(&event))
    {
       
      switch (event.type)
      {
      case SDL_QUIT:
        *continuer = 0;
        break;

      case SDL_MOUSEMOTION:
        m.poscurseur.x = event.motion.x;
        m.poscurseur.y = event.motion.y;
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
              *continuer = 0;
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
          {printf("la page est : %d ",*page);
            if (y == 1)
              *page=1;
              
              else if (y == 2)
              *page=2;
              else if (y == 3)
              *page=3;
          }
        }
        break;

      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
          if (interface == 0)
          {
            *continuer = 0;
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
              *continuer = 0;
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
              *page=1;
              else if (y == 2)
              *page=2;
              else if (y == 3)
              *page=3;
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
       affichage(interface, y, f, k, m, ecran, n);
        
    }
    
}
/*void freemenu(menu m, SDL_Surface *ecran,Mix_Music *musique,Mix_Chunk *son)
{
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
  }*/
