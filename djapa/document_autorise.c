#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
int main(void)
{
SDL_Event event; //pour quitter le jeu
SDL_Surface *ecran = NULL, *imgplay = NULL, *background = NULL;
SDL_Rect posplay, posbackground,postexte;
Mix_Music *musique;
  Mix_Chunk *son;
  int continuer = 1;
  SDL_Init(SDL_INIT_VIDEO);
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
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
  /*image*/
  imgplay = IMG_Load("imgplay1.png");
  background = IMG_Load("background.png");
  //POSITION
  posbackground.x = 0;
  posbackground.y = 0;
  posplay.x = 100;
  posplay.y = 370;
  /*texte*/
  TTF_Font *police = NULL;
  SDL_Color couleurblanche = {255, 255, 255}; /*noire 0,0,0*/
  TTF_Init();
  SDL_WM_SetCaption("GAME", NULL);
  police = TTF_OpenFont("texxte.ttf", 20);
  textecm = TTF_RenderText_Blended(police, "by:Computer Wizards", couleurblanche);
  postexte.x = 1230;
  postexte.y = 770;
  /*Music*/
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }
  musique = Mix_LoadMUS("scarymusic.mp3");
  Mix_PlayMusic(musique, -1);
  son = Mix_LoadWAV("clic.wav");
  Mix_PlayChannel(1, son, 0);
  //event
  SDL_EnableKeyRepeat(70, 70);
  while (continuer)
  {
  SDL_BlitSurface(imgbackground, NULL, ecran, &posbackground);
  SDL_Flip(ecran);
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        continuer = 0;
        break;
      case SDL_MOUSEMOTION:
      if ((event.motion.x <= 428 && event.motion.x >= 100) && (event.motion.y <= 479 && event.motion.y >= 370))
          {
          
          }
      case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button)
        {
         case SDL_BUTTON_LEFT:
         
          break;
        }
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE: 
        
          break;
        case SDLK_RETURN: //echap
              continuer = 0;
          break;
        case SDLK_UP:
        
          break;
        case SDLK_DOWN:
        
          break;
        case SDLK_RIGHT:
        
          break;
        case SDLK_LEFT:
        
          break;
        }//fermuture switch(key event)//
      }//fermuture switch(type event)//
  }//fermeture while continuer
}//fermeture main
SDL_FreeSurface(surface);
SDL_FreeSurface(ay taswira);
  TTF_CloseFont(police);
  TTF_Quit;
  Mix_FreeChunk(son);
  Mix_FreeMusic(musique);
  SDL_Quit();
return 0;
}



