#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>



void menu()
{
  SDL_Event event;
  SDL_Surface *ecran = NULL, *imgplay = NULL, *imgoption = NULL, *imgbackground[11] = {NULL}, *imgquit = NULL, *imgcurseur = NULL, *textecm = NULL, *imgplay2 = NULL, *imgoption2 = NULL, *imgquit2 = NULL, *seq = NULL, *imgv100 = NULL, *imgfullscreen = NULL, *imgnormalscreen = NULL, *imgfullscreen2 = NULL, *imgnormalscreen2 = NULL, *imgtxtaffichaage = NULL, *imgtxtvolume = NULL, *imgoption3 = NULL, *imgv0 = NULL, *imgv25 = NULL, *imgv75 = NULL, *imgv50 = NULL;

  SDL_Rect posplay, posoption, posbackground, posquit, poscurseur, postextecm, posvolume, posfullscreen, posnormalscreen, postextevolume, posaffichage, posoption2;
  
  Mix_Music *musique;
  Mix_Chunk *son;
  int continuer = 1;
  char char1[20];
  int x = 0, y = 0, z = 0, i = 0, interface = 0, k = 4, volume = 100, n,f;
  



  /*init*/
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());

  }

  ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());

  }

  /*image*/
  imgplay = IMG_Load("imgplay1.png");
  imgoption = IMG_Load("imgoption1.png");
  imgquit = IMG_Load("imgquit1.png");
  imgcurseur = IMG_Load("imgcurseur1.png");
  imgcurseur = IMG_Load("imgcurseur1.png");
  imgplay2 = IMG_Load("imgplay2.png");
  imgoption2 = IMG_Load("imgoption2.png");
  imgquit2 = IMG_Load("imgquit2.png");

  imgfullscreen = IMG_Load("bouton full screen.png");
  imgnormalscreen = IMG_Load("bouton normal.png");
  imgfullscreen2 = IMG_Load("bouton full screen secondaire.png");
  imgnormalscreen2 = IMG_Load("bouton normal secondaire.png");

  imgtxtaffichaage = IMG_Load("texte affichage.png");
  imgtxtvolume = IMG_Load("texte volume.png");
  imgoption3 = IMG_Load("barre option.png");

  imgv0 = IMG_Load("barre de volume 0_.png");
  imgv25 = IMG_Load("barre de volume 25_.png");
  imgv50 = IMG_Load("barre de volume 50_.png");
  imgv75 = IMG_Load("barre de volume 75_.png");
  imgv100 = IMG_Load("barre de volume 100_.png");
  //POSITION INTERFACE = 0 , MAIN MENU
  posbackground.x = 0;
  posbackground.y = 0;
  posvolume.x = 100;
  posvolume.y = 400;
  posplay.x = 100;
  posplay.y = 370;
  posoption.x = 100;
  posoption.y = 500;
  posquit.x = 90;
  posquit.y = 600;
  //POSITION INTERFACE = 1 , MENU OPTION
  posaffichage.x = 290;
  posaffichage.y = 480;
  postextevolume.x = 290;
  postextevolume.y = 300;
  posfullscreen.x = 70;
  posfullscreen.y = 600;
  posnormalscreen.x = 450;
  posnormalscreen.y = 600;
  posoption2.x = 150;
  posoption2.y = 70;

  for (i = 0; i < 11; i++)
  {
    sprintf(char1, "%d.png", i);
    imgbackground[i] = IMG_Load(char1);
  }

  /*texte*/
  TTF_Font *police = NULL;
  SDL_Color couleurblanche = {255, 255, 255};
  TTF_Init();
  SDL_WM_SetCaption("GAME", NULL);
  police = TTF_OpenFont("texxte.ttf", 20);
  textecm = TTF_RenderText_Blended(police, "by:Computer Wizards", couleurblanche);
  postextecm.x = 1230;
  postextecm.y = 770;

  /*Music*/
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }
  musique = Mix_LoadMUS("scarymusic.mp3");
  Mix_PlayMusic(musique, -1);
  son = Mix_LoadWAV("clic.wav");

  /*evenements*/
  SDL_EnableKeyRepeat(70, 70);
  while (continuer)
  {
 
    if (interface == 0)
    {
      SDL_BlitSurface(imgbackground[i], NULL, ecran, &posbackground);
      SDL_Delay(100);
      if (i == 11)
        i = 0;
      else
        i++;

      if (y == 0)
      {

        SDL_BlitSurface(imgplay, NULL, ecran, &posplay);
        SDL_BlitSurface(imgoption, NULL, ecran, &posoption);
        SDL_BlitSurface(imgquit, NULL, ecran, &posquit);
        SDL_BlitSurface(textecm, NULL, ecran, &postextecm);
      }
      else if (y == 1)
      {
        Mix_PlayChannel(1, son, 0);

        SDL_BlitSurface(imgplay2, NULL, ecran, &posplay);
        SDL_BlitSurface(imgoption, NULL, ecran, &posoption);
        SDL_BlitSurface(imgquit, NULL, ecran, &posquit);
        SDL_BlitSurface(textecm, NULL, ecran, &postextecm);
      }
      else if (y == 2)
      {
        Mix_PlayChannel(0, son, 0);

        SDL_BlitSurface(imgplay, NULL, ecran, &posplay);
        SDL_BlitSurface(imgoption2, NULL, ecran, &posoption);
        SDL_BlitSurface(imgquit, NULL, ecran, &posquit);
        SDL_BlitSurface(textecm, NULL, ecran, &postextecm);
      }

      else if (y == 3)
      {
        Mix_PlayChannel(1, son, 0);

        SDL_BlitSurface(imgplay, NULL, ecran, &posplay);
        SDL_BlitSurface(imgoption, NULL, ecran, &posoption);
        SDL_BlitSurface(imgquit2, NULL, ecran, &posquit);
        SDL_BlitSurface(textecm, NULL, ecran, &postextecm);
      }
      SDL_Flip(ecran);
    }
    else if (interface == 1)
    {
      if (y == 0)
      {
        SDL_BlitSurface(imgbackground[1], NULL, ecran, &posbackground);
        SDL_BlitSurface(imgv100, NULL, ecran, &posvolume);
        SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
        SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
        SDL_BlitSurface(imgtxtvolume, NULL, ecran, &postextevolume);
        SDL_BlitSurface(imgtxtaffichaage, NULL, ecran, &posaffichage);
        SDL_BlitSurface(imgoption3, NULL, ecran, &posoption2);
      }
      else if (y == 1)
      {
        switch (k)
        {
        case 0:
          SDL_BlitSurface(imgbackground[1], NULL, ecran, &posbackground);
          SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
          SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
          SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
          SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
          SDL_BlitSurface(imgtxtvolume, NULL, ecran, &postextevolume);
          SDL_BlitSurface(imgtxtaffichaage, NULL, ecran, &posaffichage);
          SDL_BlitSurface(imgoption3, NULL, ecran, &posoption2);
          SDL_BlitSurface(imgv0, NULL, ecran, &posvolume);
          volume = 0;
          Mix_PauseMusic();

          break;
        case 1:
          SDL_BlitSurface(imgbackground[1], NULL, ecran, &posbackground);
          SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
          SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
          SDL_BlitSurface(imgtxtvolume, NULL, ecran, &postextevolume);
          SDL_BlitSurface(imgtxtaffichaage, NULL, ecran, &posaffichage);
          SDL_BlitSurface(imgoption3, NULL, ecran, &posoption2);
          SDL_BlitSurface(imgv25, NULL, ecran, &posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

          break;
        case 2:
          SDL_BlitSurface(imgbackground[1], NULL, ecran, &posbackground);
          SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
          SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
          SDL_BlitSurface(imgtxtvolume, NULL, ecran, &postextevolume);
          SDL_BlitSurface(imgtxtaffichaage, NULL, ecran, &posaffichage);
          SDL_BlitSurface(imgoption3, NULL, ecran, &posoption2);
          SDL_BlitSurface(imgv50, NULL, ecran, &posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
          break;
        case 3:
          SDL_BlitSurface(imgbackground[1], NULL, ecran, &posbackground);
          SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
          SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
          SDL_BlitSurface(imgtxtvolume, NULL, ecran, &postextevolume);
          SDL_BlitSurface(imgtxtaffichaage, NULL, ecran, &posaffichage);
          SDL_BlitSurface(imgoption3, NULL, ecran, &posoption2);
          SDL_BlitSurface(imgv75, NULL, ecran, &posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
          break;
        case 4:
          SDL_BlitSurface(imgbackground[1], NULL, ecran, &posbackground);
          SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
          SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
          SDL_BlitSurface(imgtxtvolume, NULL, ecran, &postextevolume);
          SDL_BlitSurface(imgtxtaffichaage, NULL, ecran, &posaffichage);
          SDL_BlitSurface(imgoption3, NULL, ecran, &posoption2);
          SDL_BlitSurface(imgv100, NULL, ecran, &posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME);
          break;
        }
      }
      else if (y == 2)
      {

        switch (n)
        {
        case 1:
          /*SDL_BlitSurface(imgfullscreen2, NULL, ecran, &posfullscreen);*/
SDL_WM_ToggleFullScreen(ecran);



                   

          break;
        case 2:
          SDL_BlitSurface(imgnormalscreen2, NULL, ecran, &posnormalscreen);
          break;
        }
        
        switch (f)
        {
        case 0:
          SDL_BlitSurface(imgnormalscreen, NULL, ecran, &posnormalscreen);
          SDL_BlitSurface(imgfullscreen2, NULL, ecran, &posfullscreen);

          break;
        case 1:
          SDL_BlitSurface(imgfullscreen, NULL, ecran, &posfullscreen);
          SDL_BlitSurface(imgnormalscreen2, NULL, ecran, &posnormalscreen);
          break;
        }
         }

      SDL_Flip(ecran);
    }



    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        continuer = 0;
        break;

      case SDL_MOUSEMOTION:
        poscurseur.x = event.motion.x;
        poscurseur.y = event.motion.y;
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
          {y=1;
            z = 0;
          }
          else if ((event.motion.x < 420 && event.motion.x >= 260) && (event.motion.y <= 420 && event.motion.y > 380))
          {y=1;
            z = 1;
          }
          else if ((event.motion.x <= 580 && event.motion.x >= 420) && (event.motion.y <= 420 && event.motion.y >= 380))
          {y=1;
            z = 2;
          }
          if ((event.motion.x <= 740 && event.motion.x >= 580) && (event.motion.y <= 420 && event.motion.y >= 380))
          {y=1;
            z = 3;
          }
          else if ((event.motion.x < 860 && event.motion.x >= 740) && (event.motion.y < 420 && event.motion.y > 380))
          {y=1;
            z = 4;
          }
          
          
          
          
          //curseur dans interval des images "fullscreen"/"fenetre"// 
          else if ((event.motion.x <=415 && event.motion.x >=94) && (event.motion.y <=687 && event.motion.y >=613))
          {y=2;
            f=0;
          }
          else if ((event.motion.x <804 && event.motion.x >=471) && (event.motion.y <= 687 && event.motion.y >613))
          {y=2;
            f=1;
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
             { k = 0;
                            y = 1;}
            else if (z == 1)
             { k = 1;
                            y = 1;}
            else if (z == 2)
              {k = 2;
                            y = 1;}
            else if (z == 3)
             { k = 3;
                            y = 1;}
            else if (z == 4)
              {k = 4;
                            y = 1;}
              
              
             else if (f==0)
             { n=1;
                            y = 2;}
              else if (f==1)
             { n=2;
                            y = 2;}
                   

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
else if (interface == 1) {
if (y==2)
switch(f){
case 0:
n=1;
break;
case 1:
n=2;
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
            if (f== 0)
            {
              f = 0;
              break;
            }
            if (f== 1)
            {
              f= 0;
              break;
            }
        ///fermuture if(n==2)//
        } //fermuture switch(key event)//
      }//fermuture switch(type event)//
    }
  }

  TTF_CloseFont(police);
  TTF_Quit;
  Mix_FreeChunk(son);
  Mix_FreeMusic(musique);
}

//version TEST  ADAM
