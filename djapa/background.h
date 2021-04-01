#ifndef BACKGROUNG_H_INCLUDED
#define BACKGROUNG_H_INCLUDED
typedef struct 
{
  SDL_Surface *imgBack1;
  SDL_Rect posBack1;
  SDL_Rect scroll;
}Background;

void initBack(Background *b);
void afficherBack(Background b,SDL_Surface *ecran);
void scrollingBack(Background *b,SDL_Rect poshero,int direction);
#endif
