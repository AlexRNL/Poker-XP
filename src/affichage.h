#ifndef DEF_AFFICHAGEH
#define DEF_AFFICHAGEH

#ifdef _WIN32
	#define CLEAR_CONSOLE() system("cls")
#else
	#define CLEAR_CONSOLE() system("clear")
#endif

//Prototype des fonctions :
void afficher (Carte jeu[], int nb_cartes);
void nom_cartes (int valeur_carte, char nom[7]);
void nom_carte (int valeur_carte, char nom[6]);
void arrondir (double *mise, int precision);

// Accent
/** é */
extern const char e;
/** è */
extern const char ee;
/** ê */
extern const char eee;
/** à */
extern const char a;

#endif
