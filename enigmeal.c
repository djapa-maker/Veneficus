#include "enigmeal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
void initPerso(personnage *p)
{
    p->direction = 0;
    p->numvie = 0;
    p->poshero.x = 0;
    p->poshero.y = 0;
}
void initialiser_enigme(enigme *e)
{
    e->imgbutton = NULL;

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
    e->imgbutton = IMG_Load("Button.png");
}
void afficherEnigme(enigme e, SDL_Surface *ecran)
{

    TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color couleurblanche = {255, 255, 255};
    police = TTF_OpenFont("texxte.ttf", 70);

    e.texteng = TTF_RenderText_Blended(police, e.question, couleurblanche);
    e.yeseng = TTF_RenderText_Blended(police, "YES", couleurblanche);
    e.noeng = TTF_RenderText_Blended(police, "NO", couleurblanche);
    SDL_BlitSurface(e.imgeng, NULL, ecran, &(e.posimg));
    SDL_BlitSurface(e.texteng, NULL, ecran, &(e.poseng));
    SDL_BlitSurface(e.imgbutton, NULL, ecran, &(e.posyes));
    SDL_BlitSurface(e.yeseng, NULL, ecran, &(e.posyes));
    //SDL_BlitSurface(e.imgbutton, NULL, ecran, &(e.posno));
    SDL_BlitSurface(e.noeng, NULL, ecran, &(e.posno));
    SDL_Flip(ecran);

    TTF_CloseFont(police);
    TTF_Quit;
}

void genererEnigme(enigme *e)
{
    int i, al, trouve = 0, j;
    srand(time(NULL));
    al = rand() % 4;
    printf("\n%d", i);
    FILE *enigmeal = NULL;
    enigmeal = fopen("enigmee.txt", "r");
    if (enigmeal != NULL)
    {
        for (i = 0; !feof(enigmeal) && !trouve; i++)
        {
            fscanf(enigmeal, "%s\n%d\n%d", e->question, &e->reponse, &j);

            if (j == al)
            {

                trouve = 1;
            }
        }

        fclose(enigmeal);
    }
    else
        printf("\n ERREUR : verifier le nom du enigmeal :");
}
void sauvegarder(personnage p)
{
    FILE *saveF = NULL;
    saveF = fopen("sauvegarde.txt", "w+"); // Ouverture en écriture du fichier sauvegarde.txt

    if (saveF != NULL)
    { // Ecriture dans le fichier des positions du joueur et score

        if (p.numvie = 0)

            fprintf(saveF, "**** DEAD***\n");
        if (p.numvie > 0)
            fprintf(saveF, "**** Alive ***\n");

        fprintf(saveF, "** health points: %d\n", p.numvie);

        fprintf(saveF, "** Score :%d\n", p.score);

        fprintf(saveF, "** positionv : %d \npositionh : %d \n", p.poshero.x, p.poshero.y);
    }

    fclose(saveF); // Fermeture du fichier
}
void charger(personnage *p)
{
    FILE *saveF = NULL;
    saveF = fopen("sauvegarde.txt", "r"); // Ouverture du fichier sauvegarde en lecture

    if (saveF != NULL)
    { // Recuperation des positions du joueur
        fscanf(saveF, "%d", &p->numvie);

       
        fscanf(saveF, "%d", &p->score);
        fscanf(saveF, "%d", &p->poshero.x);
        fscanf(saveF, "%d", &p->poshero.x);
        
    }

    fclose(saveF); // Fermeture du fichier
}