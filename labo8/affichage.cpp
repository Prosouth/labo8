#include "affichage.h"
#include <iostream>
#include <iomanip>
using namespace std;

// On itère à travers le tableau 
void afficher(Etats surfaceJeu[][NB_LIGNES])
{
   for (int i = 0; i < NB_COLONNES; i++) 
   {
      for (int j = 0; j < NB_LIGNES; j++) 
      {
         if(surfaceJeu[i][j] == Etats::VIDE)
         {
            cout << setw(4) << "";
         }
         else if (surfaceJeu[i][j] == Etats::ENLEVE)
         {
            cout << setw(4) << " .. "; 
         }
         else
         {
            cout << " " << i + 1 << j + 1 << " "; // décalage entre le tableau et l'affichage
         }
      }
      cout << endl; 
   }
}