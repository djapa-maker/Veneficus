#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "background.h"
void initBack(Background *b)
{
  b->imgBack1 = IMG_Load("ice level.png");
  b->posBack1.x = 0;
  b->posBack1.y = 0;
  b->scroll.x = 0;
  b->scroll.y = 220;
  b->scroll.w = 12098;
  b->scroll.h = 1007;
}
void afficherBack(Background b,SDL_Surface *ecran,Personne p)
{
  
  SDL_BlitSurface(b.imgBack1, &(b.scroll),ecran, NULL);
  SDL_BlitSurface(p.perso, NULL,ecran, &p.posperso);
   
}
void scrollingBack(Background *b,Personne p)
{
  if(p.direction==1) //droite
  {
b->scroll.x+=50;
b->posBack1.x+=50;
if(b->scroll.x>=10699)
b->scroll.x=10699;
printf("scroll right abcisse cam: %d abcisse bg %d\n",b->scroll.x,b->posBack1.x);
  }
  else if(p.direction==2) //gauche
  {
b->scroll.x-=50;
b->posBack1.x-=50;
if(b->scroll.x<=0)
b->scroll.x=0;
printf("scroll left abcisse cam: %d abcisse bg %d\n",b->scroll.x,b->posBack1.x);
  }
  else if(p.direction==3) //up
  {
b->scroll.y-=50;
b->posBack1.y-=50;
if(b->scroll.y<=0)
b->scroll.y=0;
  }
}


void affichertemps (int  temps,SDL_Surface *screen)
{

    TTF_Font *police=NULL;
    police=TTF_OpenFont("Urusans.TTF",40);
    SDL_Color couleur= {255,255,255};
SDL_Rect postemps;
postemps.x=0;
    postemps.y=0;
    char s[19];
    
      sprintf(s,"Temps: %d",temps);
    SDL_Surface *txt;
    txt=TTF_RenderText_Blended(police,s,couleur);
    SDL_BlitSurface(txt,NULL,screen,&postemps);
    
}
void initmap( minimap * m)
{
m->minimap=IMG_Load ("minimap.PNG");
m->posminimap.x=100;
m->posminimap.y=40;
m->point=IMG_Load ("point.png");
m->pospoint.x=100;
m->pospoint.y=80;
}
void afficherminimap (minimap m, SDL_Surface * screen)
{
    SDL_BlitSurface(m.minimap,NULL,screen,&m.posminimap);
    SDL_BlitSurface(m.point,NULL,screen,&m.pospoint);
}
//x+imin y+tahbet

SDL_Color GetPixel (SDL_Surface* pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}
int collisionPP( Personne p, SDL_Surface * Masque,Background b)
{
SDL_Color col;
if(p.direction==1)//imin
col=GetPixel(Masque,p.posperso.x+p.posperso.w+b.scroll.x,p.posperso.y+(p.perso->h/2)+b.scroll.y);
printf("abcisse point: %d ordonne point: %d",p.posperso.x+b.scroll.x,p.posperso.y+(p.perso->h/2)+b.scroll.y);
if(p.direction==2)//isar
col=GetPixel(Masque,p.posperso.x,p.posperso.y+(p.perso->h/2));
//lfou9
//col=GetPixel(Masque,p.posperso.x+(p.perso->w/2) ,p.posperso.y); 
//louta 
   // col=GetPixel(Masque,p.posperso.x+(p.perso->w/2),p.posperso.y+p.perso->h); 
if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
  return 1;
}

else return 0;
}