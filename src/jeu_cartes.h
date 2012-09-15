#ifndef DEF_JEU_CARTESH
#define DEF_JEU_CARTESH

//Prototype des fonctions :
void creer (Carte jeu[52]) ;
void melanger (Carte jeu[52], Carte jeu_classe[52]) ;
void distribuer1 (Carte jeu[52], Carte donne[5]) ;
void distribuer2 (Carte jeu[52], Carte donne[5], int cartes_gardees[5]) ;
void remettre (Carte donne[5], Carte jeu[52], Carte jeu_classe[52], int tours) ;

#endif
