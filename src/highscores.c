#include "main.h"

/*Fonction si l'utilisateur a fait un meilleur score, on réécrit tout le fichier highscore.*/
void new_highscore (double maximum, double scores[5], char nom_score[5][13], char nom[13])
{
     int i, place = 0 ;
     char *nom_precedent = NULL ;
     FILE *highscores = NULL ;
     highscores = fopen("highscores.hsc", "w+") ;
     if (highscores == NULL) //Si l'ouverture a échoué :
     {
                    printf("\n\nEn raison d'une erreur d'ouverture les meilleurs scores ne peuvent\n%ctre enregitr%c.", eee, e) ;
     }
     else
     {
         for (i=0 ; i<5 ; i++)
         {
             if (scores[i] >= maximum) {place = i+1 ;} //On cherche la place du nouveau meilleur score.
         }
         nom_precedent = nom_score[5] ;
         for (i=4 ; place<i ; i--)
         {
             scores[i] = scores[i-1] ;
             sprintf(nom_score[i], "%s", nom_precedent) ;
             nom_precedent = nom_score[i] ;
         }
         scores[place] = maximum ;
         sprintf(nom_score[place], "%s", nom) ;
         printf("\n\n\t\t\t\tNOUVEAU MEILLEUR SCORE !!") ;
         for(i=0 ; i<5 ; i++)
         {
                 fprintf(highscores, "%s\n%lf\n", nom_score[i], scores[i]) ;
         }
         print_highscore(scores, nom_score, place) ;
         fclose(highscores) ;
     }
     //Afficher les highscores modifiés
}

/*Fonction si l'utilisateur n'a pas fait de meilleur score, on affiche juste les highscores.*/
void print_highscore (double scores[5], char nom_score[5][13], int position)
{
     int i;
     size_t taille_nom ;
     printf("\n\n\tMeilleurs scores :\n") ;
     for (i=0 ; i<5 ; i++)
     {
         printf("\n\t\t") ;
         if (i == position) {printf("^^") ;}
         printf("\t%s", nom_score[i]) ;
         taille_nom = strlen(nom_score[i]) ;
         if (taille_nom < 6) {printf("\t") ;}
         printf("\t\t\t") ;
         printf("%5.2lf", scores[i]) ;
         if (i == position) {printf("\t\t^^") ;}
     }
     printf("\n\n") ;
}
