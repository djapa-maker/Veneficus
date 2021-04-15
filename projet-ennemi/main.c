#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "ennemi.h"
int main(int argc, char *argv[])
{
    SDL_Surface *ecran;
    SDL_Surface *imgbackground;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Game", NULL);
    Ennemi e;
    back b;
    personne p;
    SDL_Event event;
    int collision;
    int continuer=1;
    int nbre_vie=6;
    int score=5;
    initEnnemi(&e);
    initback(&b);
    initperso(&p);
    while(continuer)
    {
        while ((SDL_PollEvent(&event)))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    p.poshero.x+=30;
                    break;
                }
                break;
            }
        }
        afficherback(b,ecran);
        afficherEnnemi(e,ecran);
        afficherperso(p,ecran);
        deplacer(&e);
        animerEnnemi(&e,ecran);
        collision = collisionBB(p,e,collision);
        if(collision)
        {
            nbre_vie--;
            score--;
            if((nbre_vie==0)||(score<0))
            {
                continuer=0;
            }
        }
        else
        {
            continuer= 1;
        }
        SDL_Flip(ecran);
    }
    SDL_Quit;
}
