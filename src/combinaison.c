#include "main.h"

/*Contient les fonctions qui permmettent de détecter la combinaison*/

/*Fonction permettant la detection de la meilleure combinaison possible avec 5 cartes.*/
void combinaison (Carte donne[5], char meilleure_combinaison[34])
{
     int nombre_de[14] = {0}, coeur = 0, pique = 0, carreau = 0, trefle = 0, i = 0, meilleure_carte = 0 ;
     char c_brelan[7] = "", c_paire[7] = "", c_couleur = ' ', c_carte_haute[6] = "" ; //Variable dans lesquelles on stocke les valeurs, couleurs des combinaisons temporairement.
     for (i=0 ; i<5 ; i++)
     {
         nombre_de[donne[i].valeur]++ ; //On remplit un tableau avec le nombre de cartes de chaque valeur.
         switch (donne[i].couleur) //On fait pareil avec les couleurs.
         {
                case 'h' : coeur++ ;
                           break ;
                case 's' : pique++ ;
                           break ;
                case 'd' : carreau++ ;
                           break ;
                case 'c' : trefle++ ;
                           break ;
         }
     }
     /*printf("coeurs = %d ; piques = %d ; carreaux = %d ; trefles = %d\n",coeur, pique, carreau, trefle) ;
     printf("Valeurs : ") ;
     for (i=1 ; i<14 ; i++) {printf("%d | ",nombre_de[i]) ;}*/
     if ((suite(donne) == 1) && (couleur(coeur, pique, carreau, trefle) == 1)) //Si on a une suite et une couleur.
     {
                           if ((nombre_de[1] == 1) && (nombre_de[13] == 1)) {sprintf(meilleure_combinaison, "Quinte Flush Royale !!!!") ;} //S'il y a un Roi et un As.
                                             else {sprintf(meilleure_combinaison, "Quinte Flush !!") ;} //Sinon.
     }
     else if (carre(nombre_de, meilleure_combinaison) == 1) {} //Si on a un carré.
     else if ((brelan(nombre_de, meilleure_combinaison) == 1) && (paire(nombre_de, meilleure_combinaison) == 1)) //Si on a un full
     {
          for (i=1 ; i<14 ; i++)
          {
              if (nombre_de[i]==3)
              {
                                  nom_carte(i, c_brelan) ;
              }
              if (nombre_de[i] == 2)
              {
                                  nom_carte(i, c_paire) ;
              }
          }
          sprintf(meilleure_combinaison, "Full aux %s par les %s.", c_brelan, c_paire) ;
     }
     else if (couleur(coeur, pique, carreau, trefle) == 1) //Si on a une couleur.
     {
          switch (donne[0].couleur)
          {
                 case 'h' : c_couleur = '\x3' ; //Si la carte est un coeur.
                            break ;
                 case 's' : c_couleur = '\x6' ; //Si la carte est un pique.
                            break ;
                 case 'd' : c_couleur = '\x4' ; //Si la carte est un carreau.
                            break ;
                 case 'c' : c_couleur = '\x5' ; //Si la carte est un trefle.
                            break ;
          }
          sprintf(meilleure_combinaison, "Couleur (%c).", c_couleur) ;
     }
     else if (suite(donne) == 1) {sprintf(meilleure_combinaison, "Suite.") ;} //Si on a une suite.
     else if (brelan(nombre_de, meilleure_combinaison) == 1) {} //Si on a un brelan.
     else if (paire(nombre_de, meilleure_combinaison) == 2) {} //Si on a une double paire.
     else if (paire(nombre_de, meilleure_combinaison) == 1) {}//Si on a une paire.
     else //Si on a une carte haute
     {
         for (i=2 ; i<14 ; i++)
         {
             if (nombre_de[i] != 0) {meilleure_carte = i ;}
         }
         if (nombre_de[1] != 0) {meilleure_carte = 1;}
         nom_carte(meilleure_carte, c_carte_haute) ;
         sprintf(meilleure_combinaison, "Carte haute : %s.", c_carte_haute) ;
     }

}

/*Fonction qui indique si les cartes forment une suite*/
int suite (Carte donne[5])
{
    int res = 1, nb_ech, i ;
    Carte donne_classee[5], intermediaire ;
    for (i=0 ; i<5 ; i++) //On recopie les cartes données dans un nouveau tableau.
    {
        donne_classee[i] = donne[i] ;
    }
    do //On commence par classer les cartes.
    {
          nb_ech = 0 ;
          for (i=0 ; i<4 ; i++)
          {
              if (donne_classee[i].valeur > donne_classee[i+1].valeur)
                 {
                                                    nb_ech++ ;
                                                    intermediaire = donne_classee[i+1] ;
                                                    donne_classee[i+1] = donne_classee[i] ;
                                                    donne_classee[i] = intermediaire ;
                 }
          }
    } while (nb_ech != 0) ;
    //Cas des suites classiques
    for (i=0 ; i<4 ; i++)
    {
        if (donne_classee[i].valeur+1 != donne_classee[i+1].valeur) {res = 0 ;}
    }
    //Cas particulier : As-Roi-Dame-Valet-10
    if ((donne_classee[0].valeur == 10) && (donne_classee[1].valeur == 11) && (donne_classee[2].valeur == 12) && (donne_classee[3].valeur == 13) && (donne_classee[4].valeur == 1))
    {res = 1 ;}
    return res ;
}

/*Fonction qui indique si les cartes forment une couleur*/
int couleur (int coeur, int pique, int carreau, int trefle)
{
    int res = 0 ;
    if ((coeur == 5) || (pique == 5) || (carreau == 5) || (trefle == 5)) {res = 1 ;} //On regarde si une couleur apparaît 5 fois.
    return res ;
}

/*Fonction qui indique si les cartes font un carré*/
int carre (int nombre_de[14], char meilleure_combinaison[34])
{
    int i, res = 0 ;
    char valeur_carre[7] ;
    for (i=1 ; i<14 ; i++)
    {
        if (nombre_de[i] == 4) //On regarde si une valeur apparait 4 fois.
        {
                         res = 1 ;
                         nom_cartes(i, valeur_carre) ;
                         sprintf(meilleure_combinaison, "Carr%c de %s !", e, valeur_carre) ;
        }
    }
    return res ;
}

/*Fonction qui indique s'il y a un brelan dans la donne*/
int brelan (int nombre_de[14], char meilleure_combinaison[34])
{
    int i, res = 0 ;
    char valeur_brelan[7] ;
    for (i=1 ; i<14 ; i++)
    {
        if (nombre_de[i] == 3) //On regarde si une valeur apparait 3 fois.
        {
                         res = 1 ;
                         nom_cartes(i, valeur_brelan) ;
                         sprintf(meilleure_combinaison, "Brelan de %s.", valeur_brelan) ;
        }
    }
    return res ;
}

/*Fonction qui indique s'il y a une ou plusieurs paires dans la donne*/
int paire (int nombre_de[14], char meilleure_combinaison[34])
{
    int i, res = 0 ;
    char valeur_paire[2][7] ;
    for (i=1 ; i<14 ; i++)
    {
        if (nombre_de[i] == 2) //On regarde si une valeur apparait 2 fois.
        {
                         nom_cartes(i, valeur_paire[res]) ; //Comme il peut y avoir deux paires, on prévoit un tableau de chaîne de caractères.
                         res++ ;
        }
        switch (res)
        {
               case 1 : sprintf(meilleure_combinaison, "Paire de %s.", valeur_paire[0]) ;
                        break ;
               case 2 : sprintf(meilleure_combinaison, "Double paire : %s et %s.", valeur_paire[0], valeur_paire[1]) ;
                        break ;
        }
    }
    return res ;
}
