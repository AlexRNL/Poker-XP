#ifndef DEF_MAINH
#define DEF_MAINH

//       BIBLIOTHEQUES STANDARD

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//       DEFINE

#define ARGENT_DEBUT 100 //�uro.

//       STRUCTURE
/*On d�fini une carte � jouer : une valeur et une couleur.*/
typedef struct
{
        int valeur ;
        char couleur ;
} Carte ;

//       BIBLIOTHEQUES PERSONNELLES

#include "combinaison.h"
#include "affichage.h"
#include "jeu_cartes.h"
#include "gagne_ou_perdu.h"
#include "highscores.h"

//      VARIABLES GLOBALES

//const char e = '\x82', ee = '\x8A', eee = '\x88', a = '\x85' ; // e <=> '�' ; ee <=> '�' ; eee <=> '�' ; a <=> '�'

#endif
