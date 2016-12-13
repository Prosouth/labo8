
/* ---------------------------
 Laboratoire : 
 Fichier :     main.cpp
 Auteur(s) : Samuel Yao  
 Date      : 12 December 2016, 10:16
 
 But :          
 
 Remarque(s) :
 
 Compilateur :gcc g++ 5.4.0
 --------------------------- */
#include <cstdlib>
#include <iostream>

using namespace std;


// Constantes 
const int NB_COLONNES = 7,
          NB_LIGNES = 7;

bool mouvementValide(string deplacement);
void retraitPion(int indice_largeur, int indice_hauteur);
void aide();
void initialisationJeu(int tableau[][NB_LIGNES]);
void afficher(int surfaceJeu[7][7]);


int main() 
{
   int surfaceJeu[NB_COLONNES][NB_LIGNES] = {{0,0,2,2,2,0,0},
                                             {0,0,2,2,2,0,0},
                                             {2,2,2,2,2,2,2},
                                             {2,2,2,1,2,2,2},
                                             {2,2,2,2,2,2,2},
                                             {0,0,2,2,2,0,0},
                                             {0,0,2,2,2,0,0}};

   afficher(surfaceJeu);
   
   
   return EXIT_SUCCESS;
}


bool mouvementValide(string deplacement)
{
   
}


void retraitPion(int indice_largeur, int indice_hauteur)
{
   
}


void aide()
{
   
}


void initialisationJeu(int tableau[][NB_LIGNES])
{
   


}

void afficher(int surfaceJeu[][7])
{
   for (int i = 0; i < NB_COLONNES; i++) {
      for (int j = 0; j < NB_LIGNES; j++) {
         cout << surfaceJeu[i][j] << " ";
      }
      cout << endl;
   }
}