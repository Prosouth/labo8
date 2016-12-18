#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <string>
using namespace std;

// Enum class des états du tableau de jeu
enum class Etats {VIDE = 0, ENLEVE = 1, PLEIN = 2};


// Constantes
const int NB_COLONNES = 7,
          NB_LIGNES = 7;
const string QUESTION = "Entrez votre deplacement souhaite: ",
             MESSAGE_ERREUR = "Entree non valide";
const char LETTRE_QUITTER = 'q';


#endif /* CONSTANTES_H */

