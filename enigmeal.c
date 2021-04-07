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

    SDL_Color couleurblanche = {255, 255, 255};

    e->poscurseur.x = 0;
    e->poscurseur.y = 0;
    e->police = NULL;
    e->imgbutton = NULL;
    e->passeng = NULL;
    e->faileng = NULL;

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

    e->posfail.x = 300;
    e->posfail.y = 3500;

    e->pospass.x = 300;
    e->pospass.y = 350;

    e->police = TTF_OpenFont("texxte.ttf", 70);

    e->yeseng = TTF_RenderText_Blended(e->police, "YES", couleurblanche);
    e->noeng = TTF_RenderText_Blended(e->police, "NO", couleurblanche);

    e->passeng = TTF_RenderText_Blended(e->police, "PASS", couleurblanche);
    e->faileng = TTF_RenderText_Blended(e->police, "FAIL", couleurblanche);

    e->imgeng = IMG_Load("enigme.png");
    e->imgbutton = IMG_Load("Button.png");
}
void afficherEnigme(enigme e, SDL_Surface *ecran)
{

    SDL_BlitSurface(e.imgeng, NULL, ecran, &(e.posimg));
    SDL_BlitSurface(e.texteng, NULL, ecran, &(e.poseng));
    SDL_BlitSurface(e.imgbutton, NULL, ecran, &(e.posyes));
    SDL_BlitSurface(e.yeseng, NULL, ecran, &(e.posyes));
    //SDL_BlitSurface(e.imgbutton, NULL, ecran, &(e.posno));
    SDL_BlitSurface(e.noeng, NULL, ecran, &(e.posno));
}

void genererEnigme(enigme *e)
{
    SDL_Color couleurblanche = {255, 255, 255};
    int i, al, trouve = 0, j;
    srand(time(NULL));
    al = rand() % 4;
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
        e->texteng = TTF_RenderText_Blended(e->police, e->question, couleurblanche);

        fclose(enigmeal);
    }
    else
        printf("\n ERREUR : verifier le nom du enigmeal :");
}
/*int resolution(int *running, int *run)
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
}*/

void afficher_true(SDL_Surface *ecran, enigme e)
{
    SDL_BlitSurface(e.imgeng, NULL, ecran, &(e.posimg));
    SDL_BlitSurface(e.passeng, NULL, ecran, &(e.pospass));
    
}
void afficher_false(SDL_Surface *ecran, enigme e)
{
    SDL_BlitSurface(e.imgeng, NULL, ecran, &(e.posimg));
    SDL_BlitSurface(e.faileng, NULL, ecran, &(e.pospass));
    
}
void save(personnage p)
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
void load(personnage *p)
{
    FILE *saveF = NULL;
    saveF = fopen("sauvegarde.txt", "r"); // Ouverture du fichier sauvegarde en lecture

    if (saveF != NULL)
    { // Recuperation des positions du joueur
        fscanf(saveF, "%d", &p->numvie);

        fscanf(saveF, "%d", &p->score);
        fscanf(saveF, "%hd", &p->poshero.x);
        fscanf(saveF, "%hd", &p->poshero.x);
    }

    fclose(saveF); // Fermeture du fichier
}
void free_enigme(enigme *e)
{
    SDL_FreeSurface(e->faileng);
    SDL_FreeSurface(e->imgbutton);
    SDL_FreeSurface(e->noeng);
    SDL_FreeSurface(e->texteng);
    SDL_FreeSurface(e->yeseng);
    TTF_CloseFont(e->police);
}