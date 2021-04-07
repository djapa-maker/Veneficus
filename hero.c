#include "hero.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(back *b)
{
    b->imgbackground= NULL;
    b->imgbackground= IMG_Load("imgbackground.png");

    b->posbackground.x=0;
    b->posbackground.y=0;
}
void aff(back b,SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
    //  SDL_Flip(ecran);
}

void initPerso(perso *p)
{p->jump=0;
p->distanceup=0;
p->distancedown=0;
p->fall=1;
p->gravity=400;
p->jumpspeed=19;
p->jumpheight=7;
    p->tab1[7] = NULL;
    p->tab2[7] = NULL;
    p->tab3[7] = NULL;
    p->tab4[7] = NULL;
    p->tab5[7] = NULL;
    p->tab6[7] = NULL;
    p->tab7[7] = NULL;
    p->tab8[7] = NULL;
    p->vitesse=0.5;
    p->vitessesaut=0.2;
    p->acceleration=0;
    p->accelerationsaut=0;
    p->direction=0;
    p->num1=8;
    p->num2=8;
    p->num3=8;
    p->num4=8;
    p->num5=8;
    p->num6=8;
    p->num7=8;
    p->num8=8;
    p->numvie=8;
     p->frame=1;
      p->frame1=1;
      p->frame2=1;
      p->frame3=1;
      p->frame4=1;
      p->frame5=1;
      p->frame6=1;
      p->frame7=1;
    p->poshero.x=150;
    p->poshero.y=400;
    p->poshero.w=100;
   /* p->up=0;
        p->down=0;*/
    p->frapper=0;
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
    char char1[20],char2[20],char3[20],char4[20],char5[20],char6[20],char7[20],char8[20],char9[20];// char pour stocker les no;s des images
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
    for (t = 1; t < p->num5; t++)
    {
        printf("tsab %d\n",t);
        sprintf(char6, "5%d.png",t);
        p->tab5[t] = IMG_Load(char6);
    }
    for (t = 1; t < p->num6; t++)
    {
        printf("tsab %d\n",t);
        sprintf(char7, "6%d.png",t);
        p->tab6[t] = IMG_Load(char7);
    }
    for (t = 1; t < p->num7; t++)
    {
        sprintf(char8, "7%d.png",t);
        p->tab7[t] = IMG_Load(char8);
    }
    for (t = 1; t < p->num8; t++)
    {
        sprintf(char9, "8%d.png",t);
        p->tab8[t] = IMG_Load(char9);
    }

    for (t = 1; t < p->numvie; t++)
    {
        sprintf(char3, "vie%d.png",t);
        p->tabvie[t] = IMG_Load(char3);
    }




}

void afficherPerso(perso p,SDL_Surface *ecran, int dx,int ts,int v,int dy)
{

    char char1[10000],char2[10000],char3[100000],char4[10000];
    TTF_Init();
    /*persostop*/
    if ((p.direction==0)&&(dx==0)&&(v!=p.numvie-1)&&(p.frapper==0)&&(p.jump==0))//stop0
        {SDL_BlitSurface(p.tab1[1], NULL, ecran, &p.poshero);}
        
     else if ((p.direction==1)&&(dx==0)&&(v!=p.numvie-1)&&(p.frapper==0)&&(p.jump==0))//stop1
    {SDL_BlitSurface(p.tab2[1], NULL, ecran, &p.poshero);
    }
  else if ((p.direction==0)&&(dx!=0)&&(v!=p.numvie)&&(p.jump==0)) //marcher0
    {
        SDL_BlitSurface(p.tab1[p.frame], NULL, ecran, &p.poshero);

    }

    else if ((p.direction==1)&&(dx!=0)&&(v!=p.numvie)&&(p.jump==0)) //marcher1
    {
        SDL_BlitSurface(p.tab2[p.frame1], NULL, ecran, &p.poshero);

       
    }
    else if ((p.direction==0)&&(v==p.numvie-1)&&(p.jump==0))//mort0
    {SDL_Delay(20);
        SDL_BlitSurface(p.tab3[p.frame2], NULL, ecran, &p.poshero);
          if (p.frame2 == p.num3)
            SDL_BlitSurface(p.tab3[7], NULL, ecran, &p.poshero);
            }

    else if ((p.direction==1)&&(v==p.numvie-1)&&(p.jump==0)) //mort1
    {SDL_Delay(20);
        SDL_BlitSurface(p.tab4[p.frame3], NULL, ecran, &p.poshero);
         if (p.frame3 == p.num4)
            SDL_BlitSurface(p.tab4[7], NULL, ecran, &p.poshero);
        
    }
    else if ((p.direction==0)&&(p.frapper==1)&&(v!=p.numvie)&&(p.jump==0)) //frapper0
    {        SDL_Delay(200);
        SDL_BlitSurface(p.tab5[p.frame4], NULL, ecran, &p.poshero);
      
    }
    else if ((p.direction==1)&&(p.frapper==1)&&(v!=p.numvie)&&(p.jump==0)) //frapper1
    {         //SDL_Delay(200);
    p.poshero.x-=105;
        SDL_BlitSurface(p.tab6[p.frame5], NULL, ecran, &p.poshero);
        printf("poshero %d",p.poshero.x);
          SDL_Delay(200);
       
    }
      else if ((p.direction==0)&&(v!=p.numvie)&&(p.jump==1))    // saut0up
    {                              SDL_Delay(70);
        SDL_BlitSurface(p.tab7[p.frame6], NULL, ecran, &p.poshero);

       
    }
    else if((p.direction==0)&&(v!=p.numvie)&&(p.jump==1)&&(p.distancedown)==1)  // saut0down
    {                                SDL_Delay(70);
        SDL_BlitSurface(p.tab1[1], NULL, ecran, &p.poshero);
       
    }
    else if ((p.direction==1)&&(v!=p.numvie)&&(p.jump==1)) //saut1up
    {                                SDL_Delay(70);
        SDL_BlitSurface(p.tab8[p.frame7], NULL, ecran, &p.poshero);

    }
 else if((p.direction==1)&&(v!=p.numvie)&&(p.jump==1)&&(p.distancedown)==1)  //saut1down
   {                                   SDL_Delay(70);
        SDL_BlitSurface(p.tab2[1], NULL, ecran, &p.poshero);

    }

    /*vie*/
    SDL_BlitSurface(p.tabvie[v], NULL, ecran, &p.posimgvie);

    /*score*/
    TTF_Font *police = NULL;
    SDL_Color couleurnoire= {0, 0, 0};
    police = TTF_OpenFont("texxte.ttf", 90);
    if (ts<10)
    {
        sprintf(char1, "000%d",ts);
        p.imgscore=TTF_RenderText_Blended(police, char1, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (ts<100)
    {
        sprintf(char2, "00%d",ts);
        p.imgscore= TTF_RenderText_Blended(police, char2, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (ts<1000)
    {
        sprintf(char3, "0%d",ts);
        p.imgscore= TTF_RenderText_Blended(police, char3, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (ts<10000)
    {
        sprintf(char4, "%d",ts);
        p.imgscore= TTF_RenderText_Blended(police, char4, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    TTF_CloseFont(police);

}


void deplacerPerso(perso *p,Uint32 dt,int *dx)
{

    *dx=((p->acceleration)*dt*dt)/2+((p->vitesse)*dt);
    p->poshero.x+=*dx;

}

void animerperso(perso *p,SDL_Surface *ecran,int dx,int dy,int v)
{

    if ((p->direction==0)&&(dx!=0)&&(v!=p->numvie)&&(p->jump==0)) //marcher0
    {
      SDL_Delay(70);
      if (p->frame == p->num1-1)
            (p->frame) = 1;
        else 
        (p->frame)++;
        
    }

    else if ((p->direction==1)&&(dx!=0)&&(v!=p->numvie)&&(p->jump==0)) //marcher1
    {

        SDL_Delay(70);
        if (p->frame1 == p->num2-1)
            (p->frame1) = 1;
            else
            
        (p->frame1)++;
        
    }
    else if ((p->direction==0)&&(v==p->numvie-1)&&(p->jump==0))//mort0
    {
       SDL_Delay(60);
        if (p->frame2 < p->num3-1)
            (p->frame2)++;
      
        printf("temchi");
    }

    else if ((p->direction==1)&&(v==p->numvie-1)&&(p->jump==0)) //mort1
    {

        SDL_Delay(60);
        if (p->frame3 < p->num4-1)
            (p->frame3)++;
       
    }
    else if ((p->direction==0)&&(p->frapper==1)&&(v!=p->numvie)&&(p->jump==0)) //frapper0
    {

        SDL_Delay(70);
        printf("anim");
         if (p->frame4== p->num5-1)
            (p->frame4) = 1;
            else
            
        (p->frame4)++;
       
    }
    else if ((p->direction==1)&&(p->frapper==1)&&(v!=p->numvie)&&(p->jump==0)) //frapper1
    {

        printf("poshero %d",p->poshero.x);
        if (p->frame5== p->num6-1)
            (p->frame5) = 1;
            else
        (p->frame5)++;
        
            SDL_Delay(70);
    }
   else if ((p->direction==0)&&(v!=p->numvie)&&(p->jump==1))   // saut0
    {

      SDL_Delay(70);
      if (p->frame6== p->num7-2)
            (p->frame6) = 1;
       else 
          (p->frame6)++;
        
    }
    else if ((p->direction==1)&&(v!=p->numvie)&&(p->jump==1) ) //saut1
    {     SDL_Delay(70);
       if (p->frame7== p->num8-2)
            (p->frame7) = 1;
            else
             (p->frame7)++;
        
    }

        
    
}

/*
void saut(perso *p,Uint32 dt,int *dy,int posint,int poslimit)
{
    int test=0;
    p->up=1;
    if(test==0)
    {
        posint=p->poshero.y;
        printf("posinit %d\n",posint);
        poslimit=(posint-100);
        test=1;
    }
    printf("pos up %d\n",p->up);
    printf("poslimit ;%d\n",poslimit);
   
        if((p->up==1)&&(p->poshero.y>poslimit))
        {
                // p->accelerationsaut+=0.001;
                *dy=((p->accelerationsaut)*dt*dt)/2+((p->vitessesaut)*dt);
                p->poshero.y-=*dy;
                printf("posherosaut %d\n",p->poshero.y);
                SDL_Delay(70);
                if(p->poshero.y>poslimit)
                p->up=1;
                else 
                {p->down=1;
                p->up=0;}
        }

        else if((p->poshero.y<=posint-5)&&(p->down==1))
        {
                printf("pos up %d\n",p->up);
                p->accelerationsaut+=0.0002;
                printf("accsaut %f\n",p->accelerationsaut);
                *dy=((p->accelerationsaut)*dt*dt)/2+((p->vitessesaut)*dt);
                p->poshero.y+=*dy;
                SDL_Delay(70);
                printf("posherosaut %d\n",p->poshero.y);
if(p->poshero.y<=posint-5)
p->down=1;
else 
p->down=0;
            }


        

          
    printf("pos up %d\n",p->up); 
    }*/
 void jumpin(perso *p,Uint32 dt,int dx){
  //dx=30;
if((p->jump==1||(p->distanceup)!=0)&&((p->distanceup)<p->jumpheight)&&(p->distancedown)==0){
	p->poshero.y-=p->jumpspeed-(p->distanceup);
	(p->distanceup)++;
	//deplacerPerso(p,dt,&dx);
}else{
	(p->distanceup)=0;
	(p->distancedown)=1;
}
}
void gravity(perso *p){
if((p->distancedown)==1){	

	 if(p->poshero.y<p->gravity)
{
	      printf("meni\n");

	p->poshero.y+=p->jumpspeed;

	p->fall=1;
}       else
	 	(p->distancedown)=0;
	 	p->jump=0;
}
}

   

 








