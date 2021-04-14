#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"string.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigmealeatoire.h"

void init_enigme(enigme *e )
{
    
 e->police=TTF_OpenFont("texxte.ttf",41);
e->policequestion=TTF_OpenFont("texxte.ttf",50);




e->posquestion.x=570;
e->posquestion.y=310;


e->posreponse1.x=533;
e->posreponse1.y=450;

e->posreponse2.x=e->posreponse1.x;
e->posreponse2.y=550;

e->posreponse3.x=e->posreponse1.x;
e->posreponse3.y=650;


e->posimg.x=393;
e->posimg.y=0;

e->posboard.x=500;
e->posboard.y=260;

    e->img=IMG_Load("enigme.png");
e->imgboard=IMG_Load("board.png");

SDL_Color couleurvert={0,100,0};  
SDL_Color couleurnoir={10,10,10};
SDL_Color couleurrouge={107,19,125};
SDL_Color couleurgris={107,13,13};





e->textequestion=TTF_RenderText_Blended(e->policequestion,e->question,couleurgris);
e->texterep1=TTF_RenderText_Blended(e->police,e->reponse1,couleurnoir);
e->texterep2=TTF_RenderText_Blended(e->police,e->reponse2,couleurnoir);
e->texterep3=TTF_RenderText_Blended(e->police,e->reponse3,couleurnoir);


e->policebravo=TTF_OpenFont("texxte.ttf",100);
e->textebravo=TTF_RenderText_Blended(e->policebravo,"BRAVO !",couleurvert);   //initialistion de tout ce qui concerne affichge reponse juste//
e->posbravo.x=570;
e->posbravo.y=140;






e->policeincorrecte=TTF_OpenFont("texxte.ttf",80);
e->texteincorrecte=TTF_RenderText_Blended(e->policeincorrecte,"INCORRECTE !",couleurrouge);  //initialistion de tout ce qui concerne affichge reponse fausse//
e->posincorrecte.x=525;
e->posincorrecte.y=140;







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
                                       
 






  SDL_BlitSurface(e.img, NULL, ecran,&(e.posimg));

  SDL_BlitSurface(e.imgboard,NULL, ecran,&(e.posboard));

SDL_BlitSurface(e.textequestion,NULL,ecran,&(e.posquestion));

SDL_BlitSurface(e.texterep1,NULL,ecran,&(e.posreponse1));

SDL_BlitSurface(e.texterep2,NULL,ecran,&(e.posreponse2));

SDL_BlitSurface(e.texterep3,NULL,ecran,&(e.posreponse3));

   



}




void affichage_repvraie(  SDL_Surface *ecran,enigme e)
{

SDL_BlitSurface(e.textebravo,NULL,ecran,&(e.posbravo));  


}



void affichage_repfausse( SDL_Surface *ecran,enigme e)
{

SDL_BlitSurface(e.texteincorrecte,NULL,ecran,&(e.posincorrecte));

}


