#include "main.h"

/*Contient les fonctions qui gèrent les jeu de cartes (créer, distribuer, etc.)*/

/*Fonction qui créé un jeu de carte ordonné.*/
void creer (Carte jeu[52])
{
     int i ;
     for (i=1 ; i<=13 ; i++)
     {
         jeu[i-1].valeur = i ;
         jeu[i-1].couleur = 'h' ; // h <=> hearts (coeurs)
         jeu[i+12].valeur = i ;
         jeu[i+12].couleur = 's' ; // s <=> spades (piques)
         jeu[i+25].valeur = i ;
         jeu[i+25].couleur = 'd' ; // d <=> diamonds (carreaux)
         jeu[i+38].valeur = i ;
         jeu[i+38].couleur = 'c' ; // c <=> clubs (tr�fles)
     }
}

/*Fonction qui mélange un jeu de cartes*/
void melanger (Carte jeu[52], Carte jeu_classe[52])
{
     int i, j, positions_prises[52], presence, position, derniere_position = 50*51/2 ;
     //Positions_prises est un tableau qui regroupe les position déjà occupées par des cartes.
     //Presence est une variable qui indique si la position à déjà été prise par une carte précédente.
     //Position stocke la position (déterminée aléatoirement) de la carte à placer.
     for (i=0 ; i<52 ; i++) {positions_prises[i] = -1 ;} //On initialise les positions_prises à -1.
     for (i=0 ; i<51 ; i++)
     {
         do
         {
              presence = 0 ;
              position = rand()%(52) ; //On détermine une position de manière aléatoire.
              for (j=0 ; j<52 ; j++)
              {
                  if (position == positions_prises[j]) {presence = 1 ;} //On vérifie si elle est déjà prise
              }
         } while (presence == 1) ;
         jeu[i] = jeu_classe[position] ;
         positions_prises[i] = position ;
     }
     //Pour la dernière carte, on la place nous même :
     for (i=0 ; i<51 ; i++) {derniere_position -= positions_prises[i] ;} //On calcule la dernière position.
     jeu[51] = jeu_classe[derniere_position] ;
}

/*Fonction qui distribue cinq cartes*/
void distribuer1 (Carte jeu[52], Carte donne [5])
{
     int i ;
     for (i=0 ; i<5 ; i++) {donne[i] = jeu[i] ;} //On met les cartes sur la table.
     for (i=0 ; i<47 ; i++) {jeu[i] = jeu[i+5] ;} //On enlève les cartes prises du tas.
     for (i=47 ; i<52 ; i++) {jeu[i].valeur = 0 ; jeu[i].couleur = 'v' ;} //On met des cartes nulles en dessous du tas.
}

/*Fonction qui remplace les cartes que l'on a pas choisit de garder*/
void distribuer2 (Carte jeu[52], Carte donne[5], int cartes_gardees[5])
{
     int i, j = 0, nb_cartes_gardees = 0 ;
     Carte nouvelle_donne[5] ;
     for (i=0 ; i<5 ; i++) {nouvelle_donne[i].valeur = 0 ; nouvelle_donne[i].couleur = 'v' ;} //On met des cartes nulles dans la nouvelle donne.
     i = 0 ;
     while ((i<5) && (cartes_gardees[i]!=-1))
     {
           if (cartes_gardees[i] != -1) {nouvelle_donne[cartes_gardees[i]-1] = donne[cartes_gardees[i]-1] ;} //Si on garde la carte, on la copie dans le nouveau tableau.
           i++ ;
           nb_cartes_gardees++ ;
     }
     for (i=0 ; i<5 ; i++)
     {
         if (nouvelle_donne[i].valeur == 0)
         {
                                      nouvelle_donne[i] = jeu[j] ; //Si la carte est nulle on la remplace par une du jeu original.
                                      jeu[47+j] = donne[i] ; //On remet la carte qu'on ne garde pas en dessous du tas.
                                      j++ ;
         }
     }
     for (i=0 ; i<52-nb_cartes_gardees ; i++) {jeu[i] = jeu[i+nb_cartes_gardees] ;} //On enlève les cartes prises du tas.
     for (i=52-nb_cartes_gardees ; i<52 ; i++) {jeu[i].valeur = 0 ; jeu[i].couleur = 'v' ;} //On met des cartes nulles en dessous du tas. 
     for (i=0 ; i<5 ; i++) {donne[i] = nouvelle_donne[i] ;}
}

/*Fonction qui remet la donne en dessous du paquet de cartes.*/
void remettre (Carte donne[5], Carte jeu[52], Carte jeu_classe[52], int tours)
{
     int i ;
     for (i=0 ; i<5 ; i++)
     {
         jeu[47+i] = donne[i] ;
     }
     if (tours % 5 == 0) {melanger (jeu, jeu_classe) ;}
}
