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

    e->noeng = NULL;
    e->yeseng = NULL;
    e->imgeng = NULL;
    e->texteng = NULL;

    e->posimg.x = 0;
    e->posimg.y = 0;

    e->poseng.x = 80;
    e->poseng.y = 150;

    e->posyes.x = 100;
    e->posyes.y = 500;

    e->posno.x = 400;
    e->posno.y = 500;



    e->imgeng = IMG_Load("enigme.png");
}
void afficherEnigme(enigme e, SDL_Surface *ecran)
{

    TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color couleurblanche = {255, 255, 255};
    police = TTF_OpenFont("texxte.ttf", 70);

    e.texteng = TTF_RenderText_Blended(police,e.question, couleurblanche);
    e.yeseng = TTF_RenderText_Blended(police, "YES", couleurblanche);
    e.noeng = TTF_RenderText_Blended(police, "NO", couleurblanche);
    SDL_BlitSurface(e.imgeng, NULL, ecran, &(e.posimg));
    SDL_BlitSurface(e.texteng, NULL, ecran, &(e.poseng));
    SDL_BlitSurface(e.yeseng, NULL, ecran, &(e.posyes));
    SDL_BlitSurface(e.noeng, NULL, ecran, &(e.posno));
    SDL_Flip(ecran);

    TTF_CloseFont(police);
    TTF_Quit;
}

void genererEnigme(enigme *e)
{
    int i;
    FILE *enigmeal = NULL;
    enigmeal = fopen("enigmee.txt", "r");
    if (enigmeal != NULL)
    {
     
        
        fscanf(enigmeal, "%s\n%d", e->question, &e->reponse);
        printf("\n%s",e->question);

        fclose(enigmeal);
    }
    else
        printf("\n ERREUR : verifier le nom du enigmeal :");
}
/*void sauvegarder(personne p,background)
{

}
void charger(personne*p,background*b)
{
  
}*/