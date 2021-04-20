#include "background.h"
#include "hero.h"
void affichertemps(int temps, SDL_Surface *screen)
{

  TTF_Font *police = NULL;
  police = TTF_OpenFont("Urusans.TTF", 40);
  SDL_Color couleur = {255, 255, 255};
  SDL_Rect postemps;
  postemps.x = 0;
  postemps.y = 0;
  char s[19];

  sprintf(s, "Temps: %d", temps);
  SDL_Surface *txt;
  txt = TTF_RenderText_Blended(police, s, couleur);
  SDL_BlitSurface(txt, NULL, screen, &postemps);
}
void initmap(minimap *m)
{
  m->minimap = IMG_Load("minimap.PNG");
  m->posminimap.x = 100;
  m->posminimap.y = 40;
  m->point = IMG_Load("point.png");
  m->pospoint.x = 100;
  m->pospoint.y = 80;
}
void afficherminimap(minimap m, SDL_Surface *screen)
{
  SDL_BlitSurface(m.minimap, NULL, screen, &m.posminimap);
  SDL_BlitSurface(m.point, NULL, screen, &m.pospoint);
}
//x+imin y+tahbet

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
  SDL_Color color;
  Uint32 col = 0;
  char *pPosition = (char *)pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
  SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
  return (color);
}
int collisionPP(perso p, SDL_Surface *Masque, Background b)
{
  SDL_Color col;
  if (p.direction == 0) //imin
    col = GetPixel(Masque, p.poshero.x + (p.poshero.w-30) + b.scroll.x, p.poshero.y + (p.tab1[5]->h / 2) + b.scroll.y);
  else if (p.direction == 1) //isar
    col = GetPixel(Masque, p.poshero.x + (p.poshero.w-70) + b.scroll.x, p.poshero.y + (p.tab1[5]->h )/ 2+ b.scroll.y);
  //lfou9
  //col=GetPixel(Masque,p.posperso.x+(p.perso->w/2) ,p.posperso.y);
  //louta
  else if(p.Y!=0)
  {printf("collision verticale\n");
   col=GetPixel(Masque,p.poshero.x+(p.tab1[1]->w/2),p.poshero.y+p.tab1[5]->h);
  }
  if ((col.r == 0) && (col.b == 0) && (col.g == 0))
  {
    return 1;
  }

  else
    return 0;
}