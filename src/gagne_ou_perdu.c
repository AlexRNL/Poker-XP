#include "main.h"

/*       GAINS EN FONCTION DE LA COMBINAISON
Quinte Flush Royale        <=> 100 * Mise.
Quinte Flush               <=> 50 * Mise.
Carré                      <=> 20 * Mise.
Full                       <=> 10 * Mise.
Couleur                    <=> 8 * Mise.
Suite                      <=> 5 * Mise.
Brelan                     <=> 3 * Mise.
Double Paire               <=> 2 * Mise.
Paire (Valet ou plus)      <=> 1 * Mise.
Paire (10 ou moins)        <=> 0 * Mise.
Carte Haute                <=> 0 * Mise.
*/

/*Fonction qui détermine le gain du joueur en fonction de la combinaison, cette fonction mets également l'argent du joueur à jour.*/
void gagne (char meilleure_combinaison[34], double mise, double *p_argent)
{
     float gain = 0 ;
     switch (meilleure_combinaison[0]) //On regarde la première lettre de la chaîne de caractère.
     {
            case 'Q' : gain = royale_ou_pas(meilleure_combinaison) * mise ; //Cas pour une Quinte Flush (Royale ou pas).
                       break ;
            case 'F' : gain = 10 * mise ; //Cas pour un Full.
                       break ;
            case 'S' : gain = 5 * mise ; //Cas pour une Suite.
                       break ;
            case 'B' : gain = 3 * mise ; //Cas pour un Brelan.
                       break ;
            case 'D' : gain = 2 * mise ; //Cas pour une Double Paire.
                       break ;
            case 'P' : gain = valet_ou_plus(meilleure_combinaison) * mise ; //Cas pour une Paire.
                       break ;
            case 'C' : gain = carte_haute__couleur_ou_carre(meilleure_combinaison) * mise ; //Cas pour une Carte haute, une Couleur ou un Carré.
                       break ;
     }
     *p_argent += gain ;
     if (gain > 0) {printf("\n\t\tVous gagnez %3.2lf euro(s) !\n", gain) ;}
     else {printf("\n\t\tVous perdez.\n") ;}
     printf("\n\t\tNouvel avoir : %3.2lf euro(s).\n\n", fabs(*p_argent)) ;
}

/*Fonction qui détermine si on a affaire à une Quinte Flush Royale ou pas.*/
int royale_ou_pas (char meilleure_combinaison[34])
{
      int res ;
      if (meilleure_combinaison[13] == 'R') {res = 100 ;}
      else {res = 50 ;}
      return res ;
}

/*Fonction qui détermine si on a affaire à une paire de valet ou plus.*/
int valet_ou_plus (char meilleure_combinaison[34])
{
    int res = 0 ;
    if ((meilleure_combinaison[9] == 'V') || (meilleure_combinaison[9] == 'D') || (meilleure_combinaison[9] == 'R') || (meilleure_combinaison[9] == 'A'))
       {res = 1 ;}
    return res ;
}

/*Fonction qui détermine si on a affaire à une carte haute, couleur ou un carré.*/
int carte_haute__couleur_ou_carre (char meilleure_combinaison[34])
{
    int res = 0 ;
    switch (meilleure_combinaison[3])
    {
           case 't' : res = 0 ;
                      break ;
           case 'l' : res = 8 ;
                      break ;
           case 'r' : res = 20 ;
                      break ;
    }
    return res ;
}
