
#include "hero.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define vitesse_max 40
#define G 10

int main(int argc, char *argv[])
{
    SDL_Event event;
    SDL_Surface *ecran, *imgbackground;
    perso p;
    back b;
    Input I;
    int v = 1, ts = 0;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    TTF_Init();
    ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    initialiser_input(&I);
    initPerso(&p);
    init(&b);
    SDL_EnableKeyRepeat(90, 90);
    while (continuer)
    {

        aff(b, ecran);
        afficherPerso(p, ecran, ts, v, I);

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                case SDLK_RIGHT:
                    if (v != 7)
                    {
                        I.right = 1;
                        p.direction = 0;
                    }
                    break;
                case SDLK_LEFT:
                    if (v != 7)
                    {
                        I.left = 1;
                        p.direction = 1;
                    }
                    break;
                case SDLK_SPACE:
                    if (v != 7)
                    {
                        I.fight = 1;
                        printf("frapper1\n");
                    }

                    break;

                case SDLK_UP:
                    if ((p.poshero.y == 400) && (v != 7))
                    {
                        I.jump = 1;
                        saut(&p);
                    }

                    break;
                case SDLK_KP_PLUS:
                    if (ts < 9999)
                        ts++;
                    break;
                case SDLK_KP_MINUS:
                    if (ts < 9999)
                        ts--;
                    break;
                case SDLK_LCTRL:
                    if (v < 7)
                        v++;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    initialiser_input(&I);
                    break;
                case SDLK_LEFT:
                    initialiser_input(&I);
                    break;
                case SDLK_SPACE:
                    initialiser_input(&I);
                    break;
                }
                break;
            }
        }
        if ((I.right == 1) && (v != 7))
        {
            p.X++;
            mouvementright(&p);
            p.direction = 0;
        }
        else if ((I.left == 1) && (v != 7))
        {
            p.X++;
            mouvementleft(&p);
            p.direction = 1;
        }

        p.poshero.y += p.Y;
        p.Y += G;
        if (p.poshero.y > 400)
        {
            p.Y = 0;
            p.poshero.y = 400;
            I.jump = 0;
        }

        animerperso(&p, ecran, v, &I);

        SDL_Flip(ecran);
    }

    freesurface(p, ecran);

    TTF_Quit;
    SDL_Quit();
}