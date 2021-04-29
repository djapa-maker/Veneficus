#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "jeux.h"

int main(int argc, char *argv[])
{
  int t, continuer=1,page=0; //page=0(menu) page=1(jeu newgame) page=2(jeu loadgame) page=3(multijoueur)
  SDL_Surface *ecran;
  SDL_Surface *imgbackground;
  Mix_Music *musique;
  Mix_Chunk *son;
  menu m;
  /*background bg;
  perso p1,p2;
  enemie e1,e2,e3,e4,e5,lich;
  enigmest es; (enigme statique)
  enigmed ed; (enigme dynamique)
  enigmea ea; (enigme aléatoire)
  int ea1=1,ea2=1,ea3=1,ea4=1,ea5=1,licha=1; //enemie alive (1=alive,0=mort)
  int enigmeR=0 (enigme résolu 0=non résolu/1=résolu)*/
  //initialisation
  
  //SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
  intialiser(&m);
  //initanim(m.imgbackground);
  
  
  /*void initback(background *b);
   void initPerso(personne *p);
   void initEnnemi(ennemi *e);
   void initmap(minimap *m);
   */
   
   
  SDL_EnableKeyRepeat(70, 70);
  //while (continuer)
 // {
  if (page==0)
  {
  menu1(&page,&continuer,m);
  }
 /* else if(page==1)
  {
  
  }
  else if(page==2)
  {
  
  }*/
 // };
    
   /*freemenu(m,ecran,musique,son); */
   return 0;
  }
 

