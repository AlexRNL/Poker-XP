/*Programme qui permet de jouer au poker seul :
            5 cartes distribuées, le joueur choisit celles qu'il garde.
            On redistribue les cartes non gardées.
            On détecte la combinaison pour indiquer au joueur ce qu'il a gagné.
ATTENTION : JEU DE 52 CARTES
                                                    Alex Barféty, 14/02/2008*/

#include "main.h"

int main(int argc, char *argv[])
{
    //     DECLARATIONS DES VARIABLES

    Carte jeu1[52], jeu[52], donne[5] ; // jeu1 <=> jeu avec les cartes classées. // jeu <=> jeu avec les cartes mélangées.
    int rate = 0, tours = 0,  i = 0, j = 0, cartes_gardees[5] = {0} ; // rate <=> compte le nombre de fois où le joueur fait une mauvaise mise.
    double argent = ARGENT_DEBUT, mise = 0, maximum = ARGENT_DEBUT, scores[5] = {0} ;
    char continuer = 'o', nom_joueur[13] = "", meilleure_combinaison[34] = "", numero[10] = "", nom_score[5][13] = {{""}}, jetable[13] = "" ;

    //     INITIALISATION

    srand(time(NULL)) ;
    creer(jeu1) ;
    melanger(jeu, jeu1) ; //On mélange le jeu.

    //     OUVERTURE DU FICHIER highscores.txt ET TEST

    FILE *highscores = NULL ;
    highscores = fopen("highscores.hsc", "r") ;
    if (highscores == NULL)
    {
                 do
                 {
                     CLEAR_CONSOLE();
                     printf("\n\n\tAttention, en raison d'une erreur d'ouverture les meilleurs scores\n\tne pourrons ni %ctre enregistr%cs ni %ctre affich%cs.\n\nVoulez continuer tout de m%cme ('o' ou 'n') ? ", eee, e, eee, e, eee) ;
                     scanf("%c", &continuer) ;
                     getchar() ;
                 } while ((continuer != 'o') && (continuer != 'n')) ;
                 if (continuer == 'n') {exit(0) ;}
    }

    //     ON COMMENCE A JOUER

    CLEAR_CONSOLE();
    printf("\t\t\t\t\tPOKER\n\n\n\tVeuillez entrez votre nom de joueur (12 carct%cres max.) : ", ee) ;
    fgets(nom_joueur, 12, stdin) ;
    do
    {
                if (argent > maximum) {maximum = argent ;} //On met à jour le maximum.
                tours++ ; //Nombre de tours.
                rate = 0 ;
                do
                {
                            system ("CLS") ;
                            printf("\t\t\t\t\tPOKER\n\n\n\t%s\n", nom_joueur) ;
                            switch (rate) //Remarques si l'entrée est fausse
                            {
                                   case 0 : printf ("\n\n\n\n") ;
                                            break ;
                                   case 1 : printf ("\nAttention : vous ne pouvez pas miser plus que vous n'avez ni ne rien miser.\n\n\n") ;
                                            break ;
                                   case 2 : printf ("\nAttention : vous ne pouvez pas miser plus que vous n'avez ni ne rien miser.\n\n\n") ;
                                            break ;
                                   default : printf ("\n\nVous le faites expr%cs ou quoi ??\n\n", ee) ;
                                             break ;
                            }
                            printf("\n\tVous avez %3.2lf euro(s).\n\tCombien misez vous ? ", argent) ;
                            scanf("%lf", &mise) ;
                            arrondir(&mise, 2) ; //On arrondi le résultat pour éviter les erreurs des précision des double.
                            rate++ ; //On compte le nombre de fois ou le joueur rate sa mise.
                } while ((mise<=0) || (mise>argent)) ; //On vérifie la validité de l'entrée.
                argent -= mise ;
                distribuer1(jeu, donne) ; //On distribue 5 cartes.
                combinaison(donne, meilleure_combinaison) ; //On détecte la combinaison.
                i = 0 ;
                do
                {
                    do
                    {
                         CLEAR_CONSOLE();
                         printf("\t\t\t\t\tPOKER\n\n\tMise : %3.2lf euro(s)\n\nNum%cro de la carte :\t\t1.\t2.\t3.\t4.\t5.", mise, e) ;
                         printf("\nVoici les cartes :\t\t") ;
                         afficher(donne, 5) ;
                         printf("\n\n%s\n", meilleure_combinaison) ;
                         switch (i)
                         {
                                case 0 : printf ("\n") ;
                                         break ;
                                case 1 : printf("Carte gard%ce : %d.\n", e, cartes_gardees[0]) ;
                                         break ;
                                default : printf("Cartes gard%ces : ", e) ;
                                          for (j=0 ; j<i-1 ; j++)
                                          {
                                              printf("%d, ", cartes_gardees[j]) ;
                                          }
                                          printf("et %d.\n", cartes_gardees[i-1]) ;
                                          break ;
                         }
                         switch (i)
                         {
                                case 0 : sprintf(numero, "premi%cre", ee) ;
                                         break ;
                                case 1 : sprintf(numero, "deuxi%cme", ee) ;
                                         break ;
                                case 2 : sprintf(numero, "troisi%cme", ee) ;
                                         break ;
                                case 3 : sprintf(numero, "quatri%cme", ee) ;
                                         break ;
                                case 4 : sprintf(numero, "cinqui%cme", ee) ;
                                         break ;
                         }
                         printf("\n\nEntrer la %s carte %c garder (-1 pour finir) :\n", numero, a) ;
                         scanf("%d", &cartes_gardees[i]) ;
                         while (getchar() != '\n') ;
                    } while ((cartes_gardees[i] != 1) && (cartes_gardees[i] != 2) && (cartes_gardees[i] != 3) && (cartes_gardees[i] != 4) && (cartes_gardees[i] != 5) && (cartes_gardees[i] != -1)) ;
                i++ ;
                } while ((cartes_gardees[i-1] != -1) && (i < 5)) ;
                distribuer2(jeu, donne, cartes_gardees) ; //On remplace les cartes qu'on ne garde pas.
                combinaison(donne, meilleure_combinaison) ; //On détecte la nouvelle combinaison.
                CLEAR_CONSOLE();
                printf("\t\t\t\t\tPOKER\n\n\n\tArgent : %3.2lf euro(s).\n\tMise : %3.2lf euro(s)\n\n\n\n", fabs(argent), mise) ;
                printf("\nVoici les cartes :\t\t") ;
                afficher(donne, 5) ;
                printf("\n\n%s\n\n", meilleure_combinaison) ;
                gagne(meilleure_combinaison, mise, &argent) ;
                remettre(donne, jeu, jeu1, tours) ;
                system("PAUSE") ;
    } while (argent > 0) ;

    //      FIN DU JEU

    CLEAR_CONSOLE();
    printf("\t\t\t\t\tPOKER\n\n\n\n\n\tVous avez perdu apr%cs %d tours !!\n\n\tMaximum atteint : %3.2lf euro(s).", ee, tours, maximum) ;
    if (highscores == NULL) {printf("Malheureusement, il ne vous est pas possible de consulter les meilleurs scores !!\n\n\n\n\n\n") ;}
    else //Si on a accès aux meilleurs score :
    {
        rewind(highscores) ; //On revient au début du fichier :
        for (i=0 ; i<5 ; i++)
        {
            fgets(nom_score[i], 100, highscores) ; //On enregistre les noms des gagnants dans un tableau.
            nom_score[i][strlen(nom_score[i])-1] = '\0' ;
            fscanf(highscores, "%lf", &scores[i]) ;//On enregistre les scores des gagnants dans un tableau.
            fgets(jetable, 100, highscores) ;
        }
        fclose(highscores) ; //On ferme le fichier.
        if (maximum > scores[4]) {new_highscore(maximum, scores, nom_score, nom_joueur) ;} //On regarde si l'utilisateur a battu le 5e highscore.
        else
        {
            printf("\n\n") ;
            print_highscore(scores, nom_score, -1) ; //Affichage des Highscores
        }
    }
    printf("\n\n\n\t\t\t\t\t    Cr%c%c par Alex Barf%cty le 02/11/2007.\n\n\t", e, e, e) ;
    system("PAUSE") ;
    return 0 ;
}
