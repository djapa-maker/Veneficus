#ifndef ENIGME_ALEATOIRE_SANS_FICHIERS_H_INCLUDED
#define ENIGME_ALEATOIRE_SANS_FICHIERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<math.h>




typedef struct
{char question[200];
    char reponse1[200];
    char reponse2[200];
    char reponse3[200];
     SDL_Surface *img;
    int numrepjuste;
}enigme;


enigme generer();
void afficherenigme(enigme e,SDL_Surface *ecran);
void affichage_repvraie(  SDL_Surface *ecran);
void affichage_repfausse(  SDL_Surface *ecran);
void init_enigme(enigme e );




#endif // ENIGME_ALEATOIRE_SANS_FICHIERS_H_INCLUDED
