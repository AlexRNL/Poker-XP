#include "main.h"

/*Contient les fonctions qui gèrent l'affichage, l'écriture des cartes dans des chaînes de caractères.*/

/*Fonction qui affiche un jeu de cartes*/
void afficher (Carte jeu[], int nb_cartes)
{
     int i ;
     char couleur_prov = ' ', valeur_prov[2] = "" ;
     //On créé des variable pour contenir la valeur et la couleur de la carte à afficher.
     for (i=0 ; i<nb_cartes ; i++)
     {
         switch (jeu[i].couleur)
         {
                case 'h' : couleur_prov = '\x3' ; //Si la carte est un coeur.
                           break ;
                case 's' : couleur_prov = '\x6' ; //Si la carte est un pique.
                           break ;
                case 'd' : couleur_prov = '\x4' ; //Si la carte est un carreau.
                           break ;
                case 'c' : couleur_prov = '\x5' ; //Si la carte est un trefle.
                           break ;
                case 'v' : couleur_prov = '\xB0' ; //S'il n'y a pas de carte.
                           break ;
         }
         switch (jeu[i].valeur)
         {
                case 0 : sprintf(valeur_prov,"Rien") ; //S'il n'y a pas de carte.
                         break ;
                case 1 : sprintf (valeur_prov,"As") ; //Si la carte est un As.
                         break ;
                case 11 : sprintf (valeur_prov,"V") ; //Si la carte est un valet.
                          break ;
                case 12 : sprintf (valeur_prov,"D") ; //Si la carte est une dame.
                          break ;
                case 13 : sprintf (valeur_prov,"R") ; //Si la carte est un roi.
                          break ;
                default : sprintf (valeur_prov,"%d", jeu[i].valeur) ; //Si la carte est quelconque.
                          break ;
         }
         printf("%s %c\t", valeur_prov, couleur_prov) ;
         if ((i+1)%10 == 0) {printf("\n") ;}
     }
}

/*Fonction qui écrit dans une chaîne de caractère le nom de la carte (plusieurs cartes)*/
void nom_cartes(int valeur_carte, char nom[7])
{
     switch (valeur_carte)
     {
            case 1 : sprintf(nom, "As") ;
                     break ;
            case 11 : sprintf(nom, "Valets") ;
                      break ;
            case 12 : sprintf(nom, "Dames") ;
                      break ;
            case 13 : sprintf(nom, "Rois") ;
                      break ;
            default : sprintf(nom, "%d", valeur_carte) ;
                      break ;
     }
}

/*Fonction qui écrit dans une chaîne de caractère le nom de la carte (une seule carte)*/
void nom_carte(int valeur_carte, char nom[6])
{
     switch (valeur_carte)
     {
            case 1 : sprintf(nom, "As") ;
                     break ;
            case 11 : sprintf(nom, "Valet") ;
                      break ;
            case 12 : sprintf(nom, "Dame") ;
                      break ;
            case 13 : sprintf(nom, "Roi") ;
                      break ;
            default : sprintf(nom, "%d", valeur_carte) ;
                      break ;
     }
}

//Fontion qui arrondi un double*/
void arrondir (double *mise, int precision)
{
     double test = pow(10, precision) * *mise ;
     if (test - (int) test >= 0.5)
     {
              *mise = ((int) test + 1)/pow(10, precision) ;
     }
     else
     {
         *mise = ((int) test)/pow(10, precision) ;
     }
}
