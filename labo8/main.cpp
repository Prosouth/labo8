
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
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "affichage.h"
#include "constantes.h"
#include "reglesDuJeu.h"
using namespace std;


int main() 
{
   // Enum de l'état du jeu de chaque case
   Etats surfaceJeu[NB_LIGNES][NB_COLONNES] = 
   {{Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE},
   {Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE},
   {Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN},
   {Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::ENLEVE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN},
   {Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN},
   {Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE},
   {Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE}};

   string saisie;
   afficher(surfaceJeu);
   do
   {
     saisie = saisieUtilisateur();
     if(deplacementValide(surfaceJeu, saisie))
     {
        sautRetraitPion(surfaceJeu,saisie);
     }
     else {
         cout << "Deplacement non valide" << endl;
     }
     
     if(saisie == "h")
     {
        aide(surfaceJeu);
     }
     afficher(surfaceJeu);
     //finirJeu(surfaceJeu);
   }
   while (saisie != "q" && !finirJeu(surfaceJeu));
   
   
   return EXIT_SUCCESS;
}