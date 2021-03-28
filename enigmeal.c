#include "enigmeal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Void afficherEnigme(enigme e,SDL_Surface*ecran)
{
     int i ;
  
    FILE *fichier = NULL;
    fichier = fopen(nom_fich, "r");
    if (fichier != NULL)
    {
      for (i = 0; (i < 2) && (!feof(fichier)); i++) 
        {
            fscanf(fichier, "%s \n %d  ", e.question, &e.reponse);
             printf("\n la question est %s \n la reponse est %d  ", e.question,e.reponse);
        }

       
        fclose(fichier);
    }
    else
        printf("\n ERREUR : verifier le nom du fichier :");
}
}