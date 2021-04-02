#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"string.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigmealeatoire.h"

void init_enigme(enigme e )
{




}




enigme generer()
{float a,b;
char k;
float rep1,rep2;
enigme e;
int i;

char ch1[20];
char ch2[20];


char operateur[]={'-','/','+','*'};

float reponsev;

srand(time(NULL));
a=rand()%100;
b=rand()%100;


i=rand()%4;
k=operateur[i];



sprintf(ch1,"%.2f",a);
sprintf(ch2,"%.2f",b);//*  //convertir les reponses qui sont de type float en des chaines de caracteres//





strcpy(e.question,"");

switch(k)
{   //calcul de la vraie reponse ///////
    case '-':reponsev=a-b;
 strcat(ch1,"-");
strcat(ch1,ch2);
strcat(ch1,"=");
strcat(ch1,"?");

    break;


    case '/':reponsev=a/b;
    strcat(ch1,"/");
strcat(ch1,ch2);
strcat(ch1,"=");
strcat(ch1,"?");

break;



    case '+':
    reponsev=a+b;
    strcat(ch1,"+");
strcat(ch1,ch2);
strcat(ch1,"=");
strcat(ch1,"?");



    break;



    case '*':reponsev=a*b;
       strcat(ch1,"*");
strcat(ch1,ch2);
strcat(ch1,"=");
strcat(ch1,"?");






    break;


}


strcat(e.question,ch1);








rep1=rand()*(155.5/ RAND_MAX);                                              //generer aleatoirement des reponses fausses///
rep2=rand()*(155.5/ RAND_MAX);




  //mettre la reponse juste aleatoirement parmi les reponses proposees   //
int alea;
alea=rand()%3;
e.numrepjuste=alea; //la reponse juste est affectee a l'enigme//


switch (alea)
{  case 0:


sprintf(e.reponse1,"1) %.2f",reponsev);
sprintf(e.reponse2,"2) %.2f",rep1);
sprintf(e.reponse3,"3) %.2f",rep2); break;                     //convertir les reponses qui sont de type float en des chaines de caracteres



case 1:


sprintf(e.reponse1," 1) %.2f",rep1);
sprintf(e.reponse2,"2) %.2f",reponsev);
sprintf(e.reponse3,"3) %.2f",rep2); break;

case 2 :
        sprintf(e.reponse1,"1) %.2f",rep1);
        sprintf(e.reponse2,"2) %.2f",rep2);
         sprintf(e.reponse3,"3) %.2f",reponsev);
break;
}


return e ;



}




void afficherenigme(enigme e,SDL_Surface *ecran)

{
    
SDL_Rect posquestion,posreponse1,posreponse2,posreponse3;   // position de la question + reponses 1,2,3 l'enigme//
SDL_Rect posimg,posboard;                                         // position d'image de background de l'enigme//

 SDL_Surface *textequestion,*texterep1,*texterep2,*texterep3;
  SDL_Surface *imgboard;

TTF_Init();
TTF_Font *police,*policequestion;

posimg.x=600;
posimg.y=0;

posboard.x=660;
posboard.y=250;

imgboard=IMG_Load("board.png");



    e.img = IMG_Load("enigme.png");
    
    SDL_BlitSurface(e.img, NULL, ecran,&posimg);

  SDL_BlitSurface(imgboard,NULL, ecran,&posboard);

SDL_Color couleurnoir={0,0,0};
SDL_Color couleurbleu={20,0,180};



police=TTF_OpenFont("texxte.ttf",41);
policequestion=TTF_OpenFont("texxte.ttf",50);



textequestion=TTF_RenderText_Blended(policequestion,e.question,couleurbleu);
texterep1=TTF_RenderText_Blended(police,e.reponse1,couleurnoir);
texterep2=TTF_RenderText_Blended(police,e.reponse2,couleurnoir);
texterep3=TTF_RenderText_Blended(police,e.reponse3,couleurnoir);

posquestion.x=780;
posquestion.y=310;


posreponse1.x=800;
posreponse1.y=450;

posreponse2.x=posreponse1.x;
posreponse2.y=550;

posreponse3.x=posreponse1.x;
posreponse3.y=650;



SDL_BlitSurface(textequestion,NULL,ecran,&posquestion);

SDL_BlitSurface(texterep1,NULL,ecran,&posreponse1);

SDL_BlitSurface(texterep2,NULL,ecran,&posreponse2);

SDL_BlitSurface(texterep3,NULL,ecran,&posreponse3);



SDL_Flip(ecran);





    

    SDL_FreeSurface(e.img); 
   
TTF_CloseFont(policequestion);


}



void affichage_repvraie(  SDL_Surface *ecran)
{
    


SDL_Rect posbravo;



TTF_Font *policebravo;

SDL_Surface *textebravo;
posbravo.x=770;
posbravo.y=140;

TTF_Init();
SDL_Color couleurrouge={107,19,125};
policebravo=TTF_OpenFont("texxte.ttf",100);
textebravo=TTF_RenderText_Blended(policebravo,"BRAVO !",couleurrouge);



SDL_BlitSurface(textebravo,NULL,ecran,&posbravo);



}



void affichage_repfausse( SDL_Surface *ecran)
{
SDL_Rect posincorrecte;



TTF_Font *policeincorrecte;

SDL_Surface *texteincorrecte;



posincorrecte.x=730;
posincorrecte.y=140;
SDL_Color couleurmauve={107,0,0};
policeincorrecte=TTF_OpenFont("texxte.ttf",80);
texteincorrecte=TTF_RenderText_Blended(policeincorrecte,"INCORRECTE !",couleurmauve);

SDL_BlitSurface(texteincorrecte,NULL,ecran,&posincorrecte);




}


