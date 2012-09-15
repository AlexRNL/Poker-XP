#ifndef H_MAIN
#define H_MAIN

//       BIBLIOTHEQUES STANDARD

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//       DEFINE

#define ARGENT_DEBUT 100 //euro.

//       STRUCTURE
/*On défini une carte à jouer : une valeur et une couleur.*/
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
/** é */
const char e = '\x82';
/** è */
const char ee = '\x8A';
/** ê */
const char eee = '\x88';
/** à */
const char a = '\x85' ;

#endif
