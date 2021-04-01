#ifndef BACKGROUNG_H_INCLUDED
#define BACKGROUNG_H_INCLUDED
typedef struct
{
SDL_Surface *perso;
SDL_Rect posperso;
int direction;
}Personne;
typedef struct 
{
  SDL_Surface *imgBack1;
  SDL_Rect posBack1;
  SDL_Rect scroll;
}Background;

typedef struct
{SDL_Surface *minimap;
SDL_Surface *point;
SDL_Rect posminimap;
SDL_Rect pospoint;
}minimap;

void initBack(Background *b);
void afficherBack(Background b,SDL_Surface *ecran,Personne p);
void scrollingBack(Background *b,Personne p);

void initmap( minimap * m); 
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemps (int temps, SDL_Surface * screen);
int collisionPP( Personne p, SDL_Surface * Masque,Background b);
#endif