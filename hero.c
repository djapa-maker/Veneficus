#include "hero.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(back *b){
b->imgbackground= NULL;
b->imgbackground= IMG_Load("imgbackground.png");

    b->posbackground.x=0;
    b->posbackground.y=0;
} 
void aff(back b,SDL_Surface *ecran){
          SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
      //  SDL_Flip(ecran);
}

void initPerso(perso *p){
p->tab1[7] = NULL;
p->tab2[7] = NULL;
p->tab3[7] = NULL;
p->tab4[7] = NULL;
p->vitesse=0.5; 
p->acceleration=0;
p->direction=0;
p->num1=8;
p->num2=8;
p->num3=8;
p->num4=8;
p->numvie=8;
p->up=0;
p->poshero.x=150;
p->poshero.y=400;
p->poshero.w=100;
p->poshero.h=100;
p->posimgvie.x=1160;
p->posimgvie.y=10;
p->posimgscore.x=1200;
p->posimgscore.y=70;
p->posimgscore.w=200;
p->posimgscore.h=500;
 //p->imgvie = IMG_Load("vie1.png");
 // p->imgscore = IMG_Load("score1.png");
 p->imgscore = NULL;
char char1[20],char2[20],char3[20],char4[20],char5[20];// char pour stocker les no;s des images
  int t;
  for (t = 1; t < p->num1; t++)
  {
    sprintf(char1, "1%d.png",t);
    p->tab1[t] = IMG_Load(char1);
  }

for (t= 1; t< p->num2; t++)
  {
    sprintf(char2, "2%d.png",t);
    p->tab2[t] = IMG_Load(char2);
  }
  for (t = 1; t < p->num4; t++)
  {
    sprintf(char4, "4%d.png",t);
    p->tab4[t] = IMG_Load(char4);
  }
  for (t = 1; t < p->num3; t++)
  {
    sprintf(char5, "3%d.png",t);
    p->tab3[t] = IMG_Load(char5);
  }
  
  
  for (t = 1; t < p->numvie; t++)
  {
    sprintf(char3, "vie%d.png",t);
    p->tabvie[t] = IMG_Load(char3);
  }
  
  


}

void afficherPerso(perso p,SDL_Surface *ecran, int dx ,int ts,int v){

char char1[10000],char2[10000],char3[100000],char4[10000];
  TTF_Init();
  /*persostop*/
if ((p.direction==0)&&(dx==0)&&(v!=p.numvie-1))
 SDL_BlitSurface(p.tab1[1], NULL, ecran, &p.poshero);
 else if ((p.direction==1)&&(dx==0)&&(v!=p.numvie-1))
{SDL_BlitSurface(p.tab2[1], NULL, ecran, &p.poshero);}

  /*vie*/
  SDL_BlitSurface(p.tabvie[v], NULL, ecran, &p.posimgvie);
 
 /*score*/
 TTF_Font *police = NULL;
  SDL_Color couleurnoire= {0, 0, 0};
     police = TTF_OpenFont("texxte.ttf", 90);
    if (ts<10)
    {sprintf(char1, "000%d",ts);
  p.imgscore=TTF_RenderText_Blended(police, char1, couleurnoire);
   SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);}
      else if (ts<100)
    {sprintf(char2, "00%d",ts);
  p.imgscore= TTF_RenderText_Blended(police, char2, couleurnoire);
   SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);}
      else if (ts<1000)
    {sprintf(char3, "0%d",ts);
  p.imgscore= TTF_RenderText_Blended(police, char3, couleurnoire);
   SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);}
     else if (ts<10000)
    {sprintf(char4, "%d",ts);
  p.imgscore= TTF_RenderText_Blended(police, char4, couleurnoire);
   SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);}
        TTF_CloseFont(police);
        TTF_Quit;
//SDL_Flip(ecran);
}


void deplacerPerso(perso *p,Uint32 dt,int *dx){

*dx=((p->acceleration)*dt*dt)/2+((p->vitesse)*dt);
p->poshero.x+=*dx;
//pow(dt,2)
}

void animerperso(perso p,SDL_Surface *ecran,int *t1,int *t,int *t2,int *t3,int dx,int v,int ts)
 { 
 afficherPerso(p,ecran,dx,ts,v);
 
 if ((p.direction==0)&&(dx!=0)&&(v!=p.numvie)){
    SDL_BlitSurface(p.tab1[*t], NULL, ecran, &p.poshero);
    SDL_Delay(70);
    (*t)++;
    if (*t == p.num1)
      (*t) = 1;
      }
    
    else if ((p.direction==1)&&(dx!=0)&&(v!=p.numvie)){
 SDL_BlitSurface(p.tab2[*t1], NULL, ecran, &p.poshero);
    SDL_Delay(70);
    (*t1)++;
    if (*t1 == p.num2)
      (*t1) = 1;
      }
   else if ((p.direction==0)&&(v==p.numvie-1))
      {  
         SDL_BlitSurface(p.tab3[*t2], NULL, ecran, &p.poshero);
    SDL_Delay(70);
         if (*t2 < 7)
     (*t2)++;
  
     
else if (*t2 == p.num3)
      SDL_BlitSurface(p.tab3[7], NULL, ecran, &p.poshero);
     printf("temchi");
     
      }
      
      else if ((p.direction==1)&&(v==p.numvie-1)){
 SDL_BlitSurface(p.tab4[*t3], NULL, ecran, &p.poshero);
    SDL_Delay(80);
     if (*t3 < 7)
    (*t3)++;
     if (*t3 == p.num4)
      SDL_BlitSurface(p.tab4[7], NULL, ecran, &p.poshero);
        }
      SDL_Flip(ecran);
      }

/*
void saut(perso *p,Uint32 dt,int *dy){
*dy=((p->acceleration)*dt*dt)/2+((p->vitesse)*dt);
p->poshero.y-=*dy;
}*/

