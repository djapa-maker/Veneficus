#include "hero.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define vitesse_max 40
#define G 16

void init(back *b)
{
    b->imgbackground = NULL;
    b->imgbackground = IMG_Load("imgbackground.png");

    b->posbackground.x = 0;
    b->posbackground.y = 0;
}
void aff(back b, SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
    //  SDL_Flip(ecran);
}

void initPerso(perso *p)
{
   
    p->X = 0;
    p->Y = 0;
    p->tab1[7] = NULL;
    p->tab2[7] = NULL;
    p->tab3[7] = NULL;
    p->tab4[7] = NULL;
    p->tab5[7] = NULL;
    p->tab6[7] = NULL;
    p->tab7[7] = NULL;
    p->tab8[7] = NULL;
    p->direction = 0;
    p->num1 = 8;
    p->num2 = 8;
    p->num3 = 8;
    p->num4 = 8;
    p->num5 = 8;
    p->num6 = 8;
    p->num7 = 8;
    p->num8 = 8;
    p->numvie = 8;
    p->frame = 1;
    p->frame1 = 1;
    p->frame2 = 1;
    p->frame3 = 1;
    p->frame4 = 1;
    p->frame5 = 1;
    p->frame6 = 1;
    p->frame7 = 1;
    p->poshero.x = 150;
    p->poshero.y = 400;
    p->poshero.w = 100;
    p->poshero.h = 100;
    p->posimgvie.x = 1160;
    p->posimgvie.y = 10;
    p->posimgscore.x = 1200;
    p->posimgscore.y = 70;
    p->posimgscore.w = 200;
    p->posimgscore.h = 500;
    p->imgscore = NULL;
    char char1[20], char2[20], char3[20], char4[20], char5[20], char6[20], char7[20], char8[20], char9[20]; // char pour stocker les no;s des images
    int t;
    for (t = 1; t < p->num1; t++)
    {
        sprintf(char1, "1%d.png", t);
        p->tab1[t] = IMG_Load(char1);
    }

    for (t = 1; t < p->num2; t++)
    {
        sprintf(char2, "2%d.png", t);
        p->tab2[t] = IMG_Load(char2);
    }
    for (t = 1; t < p->num4; t++)
    {
        sprintf(char4, "4%d.png", t);
        p->tab4[t] = IMG_Load(char4);
    }
    for (t = 1; t < p->num3; t++)
    {
        sprintf(char5, "3%d.png", t);
        p->tab3[t] = IMG_Load(char5);
    }
    for (t = 1; t < p->num5; t++)
    {
        printf("tsab %d\n", t);
        sprintf(char6, "5%d.png", t);
        p->tab5[t] = IMG_Load(char6);
    }
    for (t = 1; t < p->num6; t++)
    {
        printf("tsab %d\n", t);
        sprintf(char7, "6%d.png", t);
        p->tab6[t] = IMG_Load(char7);
    }
    for (t = 1; t < p->num7; t++)
    {
        sprintf(char8, "7%d.png", t);
        p->tab7[t] = IMG_Load(char8);
    }
    for (t = 1; t < p->num8; t++)
    {
        sprintf(char9, "8%d.png", t);
        p->tab8[t] = IMG_Load(char9);
    }

    for (t = 1; t < p->numvie; t++)
    {
        sprintf(char3, "vie%d.png", t);
        p->tabvie[t] = IMG_Load(char3);
    }
}

void afficherPerso(perso p, SDL_Surface *ecran, int ts, int v, Input I)
{

    char char1[100], char2[100], char3[100], char4[100];
    TTF_Init();
    /*persostop*/
    if ((p.direction == 0)  && (I.fight == 0) && (v != p.numvie - 1)&&(I.right==0)&&(I.jump==0)) //stop
    {
        SDL_BlitSurface(p.tab1[1], NULL, ecran, &p.poshero);
    }

    else if ((p.direction == 1) && (I.fight == 0) && (v != p.numvie - 1)&&(I.left==0)&&(I.jump==0)) //stop1
    {
        SDL_BlitSurface(p.tab2[1], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 0) && (I.right == 1) && (I.jump == 0)) //marcher0
    {
        SDL_Delay(20);
        SDL_BlitSurface(p.tab1[p.frame], NULL, ecran, &p.poshero);
    }

    else if ((p.direction == 1) && (I.left == 1) && (I.jump == 0)) //marcher1
    {
        SDL_Delay(20);
        SDL_BlitSurface(p.tab2[p.frame1], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 0) && (v == p.numvie - 1) ) //mort0
    {
        SDL_BlitSurface(p.tab3[p.frame2], NULL, ecran, &p.poshero);
        if (p.frame2 == p.num3)
            SDL_BlitSurface(p.tab3[7], NULL, ecran, &p.poshero);
        printf("mort dhaher");
    }

    else if ((p.direction == 1) && (v == p.numvie - 1) ) //mort1
    {
        SDL_BlitSurface(p.tab4[p.frame3], NULL, ecran, &p.poshero);
        if (p.frame3 == p.num4)
            SDL_BlitSurface(p.tab4[7], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 0) && (I.fight == 1) ) //frapper0
    {
        SDL_Delay(100);
        SDL_BlitSurface(p.tab5[p.frame4], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 1) && (I.fight == 1)) //frapper1
    {                                                            //SDL_Delay(200);
        p.poshero.x -= 105;
        SDL_BlitSurface(p.tab6[p.frame5], NULL, ecran, &p.poshero);
        printf("poshero %d", p.poshero.x);
        SDL_Delay(100);
    }
   else if ((p.direction == 0) && (v != p.numvie)   && (I.jump==1))// saut0up
    {printf("affichage saut \n");
        SDL_Delay(100);
        SDL_BlitSurface(p.tab7[p.frame6], NULL, ecran, &p.poshero);
    }

    else if ((p.direction == 1) && (v != p.numvie) &&  (I.jump==1)) //saut1up
    {
        SDL_Delay(100);
        SDL_BlitSurface(p.tab8[p.frame7], NULL, ecran, &p.poshero);
    }

    /*vie*/
    SDL_BlitSurface(p.tabvie[v], NULL, ecran, &p.posimgvie);

    /*score*/
    TTF_Font *police = NULL;
    SDL_Color couleurnoire = {0, 0, 0};
    police = TTF_OpenFont("texxte.ttf", 90);
    if (ts < 10)
    {
        sprintf(char1, "000%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char1, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (ts < 100)
    {
        sprintf(char2, "00%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char2, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (ts < 1000)
    {
        sprintf(char3, "0%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char3, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (ts < 10000)
    {
        sprintf(char4, "%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char4, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    TTF_CloseFont(police);
}

void mouvementright(perso *p)
{

    if (p->X >= vitesse_max)
        p->X = vitesse_max;
    if (p->poshero.x < 1399)
    {

        p->poshero.x = p->poshero.x + p->X;
        p->direction = 0;
    }
}

void mouvementleft(perso *p)
{
    if (p->X >= vitesse_max)
        p->X = vitesse_max;
    if (p->poshero.x > 0)
    {
        p->poshero.x = p->poshero.x - p->X;
        p->direction = 1;
    }
}

void initialiser_input(Input *I)
{
    I->left = 0;
    I->right = 0;
    I->fight = 0;
}

void saut(perso *p)
{
    p->Y = -50;
}

void animerperso(perso *p, SDL_Surface *ecran, int v, Input *I)
{

    if ((p->direction == 0) && (I->right == 1) && (I->jump == 0) && (p->Y == 0)) //marcher0
    {
        SDL_Delay(70);
        if (p->frame == p->num1 - 1)
            (p->frame) = 1;
        else
            (p->frame)++;
    }

    else if ((p->direction == 1) && (I->left == 1) && (I->jump == 0) && (p->Y == 0)) //marcher1
    {

        SDL_Delay(70);
        if (p->frame1 == p->num2 - 1)
            (p->frame1) = 1;
        else

            (p->frame1)++;
    }
    else if ((p->direction == 0) && (v == p->numvie - 1) ) //mort0
    {
        SDL_Delay(70);
        if (p->frame2 < p->num3 - 1)
            (p->frame2)++;
        printf("temchi");
    }

    else if ((p->direction == 1) && (v == p->numvie - 1) ) //mort1
    {

        SDL_Delay(60);
        if (p->frame3 < p->num4 - 1)
            (p->frame3)++;
    }
    else if ((p->direction == 0) && (I->fight == 1) ) //frapper0
    {

        SDL_Delay(20);
        printf("anim");
        if (p->frame4 == p->num5 - 1)
            (p->frame4) = 1;
        else

            (p->frame4)++;
    }
    else if ((p->direction == 1) && (I->fight == 1) ) //frapper1
    {

        printf("poshero %d", p->poshero.x);
        if (p->frame5 == p->num6 - 1)
            (p->frame5) = 1;
        else
            (p->frame5)++;

        SDL_Delay(20);
    }
    else if ((p->direction == 0) && (v != p->numvie)  &&(I->jump==1))  // saut0
    {
printf("\nanimation saut\n");
        if (p->frame6 == p->num7 - 2)
            (p->frame6) = 1;
        else
           { (p->frame6)++;
printf("num frame saut =%d\n",p->frame6);}
    }
    else if ((p->direction == 1) && (v != p->numvie)&&(I->jump==1)) //saut1
    {
        if (p->frame7 == p->num8 - 2)
            (p->frame7) = 1;
        else
            (p->frame7)++;

    }
}

void freesurface(perso p, SDL_Surface *ecran)
{
    int i;
    for (i = 1; i < 7; i++)
    {
        SDL_FreeSurface(p.tab1[i]);
        SDL_FreeSurface(p.tab2[i]);
        SDL_FreeSurface(p.tab3[i]);
        SDL_FreeSurface(p.tab4[i]);
        SDL_FreeSurface(p.tab5[i]);
        SDL_FreeSurface(p.tab6[i]);
        SDL_FreeSurface(p.tab7[i]);
        SDL_FreeSurface(p.tab8[i]);
        SDL_FreeSurface(p.tabvie[i]);
    }
   
    SDL_FreeSurface(ecran);
}