#include "enigmeal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void initialiser_enigme(enigme *e)
{
     TTF_Init();
    e->police = NULL;
    e->faileng = NULL;
    e->passeng = NULL;

    e->noeng = NULL;
    e->yeseng = NULL;
    e->imgeng = NULL;
    e->texteng = NULL;

    e->posimg.x = 0;
    e->posimg.y = 0;

    e->poseng.x = 150;
    e->poseng.y = 150;

    e->posyes.x = 100;
    e->posyes.y = 500;

    e->posno.x = 400;
    e->posno.y = 500;

    e->pospass.x = 300;
    e->pospass.y = 400;

     

     e->posfail.x = 300;
     e->posfail.y = 400;

    e->imgeng = IMG_Load("enigme.png");
    e->police = TTF_OpenFont("texxte.ttf", 90);

    
    
}
void afficherEnigme(enigme e, SDL_Surface *ecran)
{

    
    SDL_Color couleurblanche = {255, 255, 255};
    
    

    e.texteng = TTF_RenderText_Blended(e.police, e.question, couleurblanche);
    e.yeseng = TTF_RenderText_Blended(e.police, "YES", couleurblanche);
    e.noeng = TTF_RenderText_Blended(e.police, "NO", couleurblanche);
   
    SDL_BlitSurface(e.imgeng, NULL, ecran, &(e.posimg));
    SDL_BlitSurface(e.texteng, NULL, ecran, &(e.poseng));
    SDL_BlitSurface(e.yeseng, NULL, ecran, &(e.posyes));
    SDL_BlitSurface(e.noeng, NULL, ecran, &(e.posno));
    printf("%d", e.reponse);
    SDL_Flip(ecran);

    TTF_CloseFont(e.police);
    TTF_Quit;
}

void genererEnigme(enigme *e)
{
    int i;
    FILE *enigmeal = NULL;
    enigmeal = fopen("enigme.txt", "r");
    if (enigmeal != NULL)
    {
        /*for (i = 0; (i < 2) && (!feof(enigmeal)); i++) 
        {
           
            
        }*/
        fscanf(enigmeal, "%s \n%d", e->question, &e->reponse);

        fclose(enigmeal);
    }
    else
        printf("\n ERREUR : verifier le nom du enigmeal :");
}
int resolution(int *running, int *run)
{
    SDL_Event event;
    int r = 0;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        *running = 0;
        *run = 0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_a:
            r = 1;
            break;
        case SDLK_z:
            r = 2;
            break;
        case SDLK_e:
            r = 3;
            break;
        }
        break;
    }
    return r;
}
void afficher_resultat(SDL_Surface *ecran, int s, int r, enigme e)
{
    SDL_Color white= {255, 255, 255};

     TTF_Init();
    if (r == s)
    {
         e.passeng = TTF_RenderText_Blended(e.police, "PASS", white);
   

        SDL_Flip(ecran);
    }
    else
    {
         e.faileng = TTF_RenderText_Blended(e.police, "FAIL", white);

        SDL_Flip(ecran);
    }

    TTF_Quit;
    
}
/*void sauvegarder(personne p,background)
{

}
void charger(personne*p,background*b)
{
  
}*/