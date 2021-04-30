#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"string.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigmealeatoire.h"

void init_enigme1(enigme1 *e1 )
{
    
 e1->police=TTF_OpenFont("texxte.ttf",41);
e1->policequestion=TTF_OpenFont("texxte.ttf",50);




e1->posquestion.x=570;
e1->posquestion.y=310;


e1->posreponse1.x=533;
e1->posreponse1.y=450;

e1->posreponse2.x=e1->posreponse1.x;
e1->posreponse2.y=550;

e1->posreponse3.x=e1->posreponse1.x;
e1->posreponse3.y=650;


e1->posimg.x=393;
e1->posimg.y=0;

e1->posboard.x=500;
e1->posboard.y=260;

    e1->img=IMG_Load("enigme1.png");
e1->imgboard=IMG_Load("board.png");

SDL_Color couleurvert={0,100,0};  
SDL_Color couleurnoir={10,10,10};
SDL_Color couleurrouge={107,19,125};
SDL_Color couleurgris={107,13,13};





e1->textequestion=TTF_RenderText_Blended(e1->policequestion,e1->question,couleurgris);
e1->texterep1=TTF_RenderText_Blended(e1->police,e1->reponse1,couleurnoir);
e1->texterep2=TTF_RenderText_Blended(e1->police,e1->reponse2,couleurnoir);
e1->texterep3=TTF_RenderText_Blended(e1->police,e1->reponse3,couleurnoir);


e1->policebravo=TTF_OpenFont("texxte.ttf",100);
e1->textebravo=TTF_RenderText_Blended(e1->policebravo,"BRAVO !",couleurvert);   //initialistion de tout ce qui concerne affichge reponse juste//
e1->posbravo.x=570;
e1->posbravo.y=140;






e1->policeincorrecte=TTF_OpenFont("texxte.ttf",80);
e1->texteincorrecte=TTF_RenderText_Blended(e1->policeincorrecte,"INCORRECTE !",couleurrouge);  //initialistion de tout ce qui concerne affichge reponse fausse//
e1->posincorrecte.x=525;
e1->posincorrecte.y=140;







}




enigme1 generer()
{float a,b;
char k;
float rep1,rep2;
enigme1  e1;
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





strcpy(e1.question,"");

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


strcat(e1.question,ch1);








rep1=rand()*(155.5/ RAND_MAX);                                              //generer aleatoirement des reponses fausses///
rep2=rand()*(155.5/ RAND_MAX);




  //mettre la reponse juste aleatoirement parmi les reponses proposees   //
int alea;
alea=rand()%3;
e1.numrepjuste=alea; //la reponse juste est affectee a l'enigme//


switch (alea)
{  case 0:


sprintf(e1.reponse1,"1) %.2f",reponsev);
sprintf(e1.reponse2,"2) %.2f",rep1);
sprintf(e1.reponse3,"3) %.2f",rep2); break;                     //convertir les reponses qui sont de type float en des chaines de caracteres



case 1:


sprintf(e1.reponse1," 1) %.2f",rep1);
sprintf(e1.reponse2,"2) %.2f",reponsev);
sprintf(e1.reponse3,"3) %.2f",rep2); break;

case 2 :
        sprintf(e1.reponse1,"1) %.2f",rep1);
        sprintf(e1.reponse2,"2) %.2f",rep2);
         sprintf(e1.reponse3,"3) %.2f",reponsev);
break;
}


return e1 ;



}




void afficherenigme(enigme1 e1,SDL_Surface *ecran)

{
                                       
 






  SDL_BlitSurface(e1.img, NULL, ecran,&(e1.posimg));

  SDL_BlitSurface(e1.imgboard,NULL, ecran,&(e1.posboard));

SDL_BlitSurface(e1.textequestion,NULL,ecran,&(e1.posquestion));

SDL_BlitSurface(e1.texterep1,NULL,ecran,&(e1.posreponse1));

SDL_BlitSurface(e1.texterep2,NULL,ecran,&(e1.posreponse2));

SDL_BlitSurface(e1.texterep3,NULL,ecran,&(e1.posreponse3));

   



}




void affichage_repvraie(  SDL_Surface *ecran,enigme1 e1)
{

SDL_BlitSurface(e1.textebravo,NULL,ecran,&(e1.posbravo));  


}



void affichage_repfausse( SDL_Surface *ecran,enigme1 e1)
{

SDL_BlitSurface(e1.texteincorrecte,NULL,ecran,&(e1.posincorrecte));

}

void free_enigmealea(enigme1 *e1)
{
    SDL_FreeSurface(e1->img);
    SDL_FreeSurface(e1->textequestion);
    SDL_FreeSurface(e1->texterep1);
    SDL_FreeSurface(e1->texterep2);
     SDL_FreeSurface(e1->texterep3);
     SDL_FreeSurface(e1->imgboard);
    SDL_FreeSurface(e1->textebravo);
    SDL_FreeSurface(e1->texteincorrecte);
    TTF_CloseFont(e1->police);
}


