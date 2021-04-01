#ifndef BACKGROUNG_H_INCLUDED
#define BACKGROUNG_H_INCLUDED
typedef struct 
{
  SDL_Surface *imgBack1;
  SDL_Rect posBack1;
  SDL_Rect scroll;
}Background;

void initBack(Background *b);
void afficherBack(Background b,SDL_Surface *ecran,SDL_Surface *hero,SDL_Rect poshero);
void scrollingBack(Background *b,int direction);
#endif