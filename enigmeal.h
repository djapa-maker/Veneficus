#ifndef T_H_INCLUDED
#define T_H_INCLUDED

typedef struct
{
    char question[50];
    int  reponse;
    

}enigme;



Void afficherEnigme(enigme e,SDL_Surface*ecran);
Void genererEnigme(enigme *e,char *nomficher);
#endif