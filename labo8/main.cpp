
/* ---------------------------
 Laboratoire: 8 - Solitaire
 Fichier    : main.cpp
 Auteur(s)  : Sébastien Saez et Samuel Yao Yao 
 Date       : 12 Décembre 2016
 
 But        : Mettre en oeuvre le jeu du solitaire dans sa version à 32 billes.       
 
 Remarque(s) :
 
 Compilateur : g++ 6.2.1 20160830
 --------------------------- */
#include <cstdlib>
#include <iostream>

using namespace std;


// Constantes 
const int NB_COLONNES = 7,
          NB_LIGNES = 7;

bool mouvementValide(string deplacement);
void retraitPion(int indice_largeur, int indice_hauteur);
void aide(int surfaceJeu[7][7]);
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
   aide(surfaceJeu);
   
   
   return EXIT_SUCCESS;
}


bool mouvementValide(string deplacement)
{
   
}


void retraitPion(int indice_largeur, int indice_hauteur)
{
   
}


void aide(int surfaceJeu[7][7])
{
   int compteur = 1;
   cout << "Deplacements possibles:";
   for (int i = 0; i < NB_COLONNES; i++) {
      for (int j = 0; j < NB_LIGNES; j++) {
         if(surfaceJeu[i][j] == 0)
         {
            cout << i + 1 << j + 1 << "lol" << " " << endl;
         }
      }
   }
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