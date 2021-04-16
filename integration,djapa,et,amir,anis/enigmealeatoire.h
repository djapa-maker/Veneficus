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

TTF_Font *police,*policequestion;;
    SDL_Surface *textequestion,*texterep1,*texterep2,*texterep3;
SDL_Rect posquestion,posreponse1,posreponse2,posreponse3;                 //ce qui concerne l'affichage de l'enigme//
SDL_Rect posimg,posboard; 
SDL_Surface *imgboard;


SDL_Rect posbravo;  //ce qui concerne l'affichage de la reponse vraie//
  SDL_Surface *textebravo;
  TTF_Font *policebravo;



  SDL_Rect posincorrecte;
TTF_Font *policeincorrecte;        //ce qui concerne l'affichage de la reponse fausse//
SDL_Surface *texteincorrecte;

}enigme1;


enigme1 generer();
void afficherenigme(enigme1 e1,SDL_Surface *ecran);
void affichage_repvraie(  SDL_Surface *ecran,enigme1 e1);
void affichage_repfausse(  SDL_Surface *ecran,enigme1 e1);
void init_enigme1(enigme1 *e1);




#endif // ENIGME_ALEATOIRE_SANS_FICHIERS_H_INCLUDED
