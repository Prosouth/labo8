/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reglesDuJeu.cpp
 * Author: prosouth
 *
 * Created on 18 December 2016, 08:43
 */
#include "reglesDuJeu.h"
#include <cstdlib>
#include <string>
#include<iostream>
#include <limits>
using namespace std;


bool deplacementValide(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur)
{
   if (saisieUtilisateur.length() != 3)
   {
      return false;
   }
   char ligne = char2int(saisieUtilisateur.at(0)),
        colonne = char2int(saisieUtilisateur.at(1)),
        directionDeplacement = saisieUtilisateur.at(2);
   colonne --; // pour matcher le tableau d'enum directement
   ligne --;
   bool deplacementValide = false;

   if(surfaceJeu[ligne][colonne] != Etats::PLEIN)
   {
      return false;
   }

   switch (directionDeplacement) 
   { // check naïvement que le déplacement ne déborde pas de la surface de tableau
      case 'u':
         if (ligne >= 2 && ligne <= 6 && colonne >= 0 && colonne <= 6)
            deplacementValide = true;
         break;
      case 'd':
         if (ligne <= 4 && ligne >= 0 && colonne >= 0 && colonne <= 6)
            deplacementValide = true;
         break;
      case 'l':
         if (colonne >= 2 && colonne <= 6 && ligne >= 0 && ligne <= 6)
            deplacementValide = true;
         break;
      case 'r':
         if (colonne <= 4 && colonne >= 0 && ligne >= 0 && ligne <= 6)
            deplacementValide = true;
         break;
      default: 
         break;
   }

   if (!deplacementValide) 
   {
      return false;
   }
   switch (directionDeplacement)
   {
      case 'u':// up
         return (surfaceJeu[ligne - 1][colonne] == Etats::PLEIN
                 && surfaceJeu[ligne - 2][colonne] == Etats::ENLEVE);
         break;
      case 'd': // down
         return (surfaceJeu[ligne + 1][colonne] == Etats::PLEIN
                 && surfaceJeu[ligne + 2][colonne] == Etats::ENLEVE);
         break;
      case 'l': // left
         return (surfaceJeu[ligne][colonne - 1] == Etats::PLEIN
                 && surfaceJeu[ligne][colonne - 2] == Etats::ENLEVE);
         break;
      case'r': // right
         return (surfaceJeu[ligne][colonne + 1] == Etats::PLEIN
                 && surfaceJeu[ligne][colonne + 2] == Etats::ENLEVE);
         break;
      default:
         break;
   }
}

void aide(Etats surfaceJeu[][NB_LIGNES])
{
   cout << "Deplacements possibles: ";
   for (int i = 0; i < NB_LIGNES; i++)
   {
      for (int j = 0; j < NB_COLONNES; j++) 
      {
         if (surfaceJeu[i][j] == Etats::PLEIN) 
         {
            if (i >= 2 && surfaceJeu[i - 2][j] == Etats::ENLEVE && surfaceJeu[i - 1][j] == Etats::PLEIN) 
            {
               cout << i + 1 << j + 1 << "u ";
            }
            if (i <= 4 && surfaceJeu[i + 2][j] == Etats::ENLEVE && surfaceJeu[i + 1][j] == Etats::PLEIN) 
            {
               cout << i + 1 << j + 1 << "d ";
            }
            if (j <= 4 && surfaceJeu[i][j + 2] == Etats::ENLEVE && surfaceJeu[i][j + 1] == Etats::PLEIN) 
            {
               cout << i + 1 << j + 1 << "r ";
            }
            if (j >= 2 && surfaceJeu[i][j - 2] == Etats::ENLEVE && surfaceJeu[i][j - 1] == Etats::PLEIN) 
            {
               cout << i + 1 << j + 1 << "l ";
            }
         }
      }
   } 
   cout << endl;
}


bool finirJeu(Etats surfaceJeu[][NB_LIGNES])
{

   for (int i = 0; i < NB_LIGNES; i++) 
   {
      for (int j = 0; j < NB_COLONNES; j++) 
      {
         if (surfaceJeu[i][j] == Etats::PLEIN) 
         {
            if (i >= 2 && surfaceJeu[i - 2][j] == Etats::ENLEVE && surfaceJeu[i - 1][j] == Etats::PLEIN) 
            {
               return false;
            }
            if (i <= 4 && surfaceJeu[i + 2][j] == Etats::ENLEVE && surfaceJeu[i + 1][j] == Etats::PLEIN) 
            {
               return false;
            }
            if (j <= 4 && surfaceJeu[i][j + 2] == Etats::ENLEVE && surfaceJeu[i][j + 1] == Etats::PLEIN) 
            {
               return false;
            }
            if (j >= 2 && surfaceJeu[i][j - 2] == Etats::ENLEVE && surfaceJeu[i][j - 1] == Etats::PLEIN) 
            {
               return false;
            }
         }
      }
   }
   return true;
}


int char2int(char c) // utilisée pour parser les déplacements
{
   return c - '0';
}




string saisieUtilisateur()
{
   string valeur;
   char direction;
   bool entree_invalide = true;
   do {
      cout << QUESTION;
      cin >> valeur;
      if (valeur == "q") {
         return valeur;
      }
      if (valeur == "h") {
         return valeur;
      }
      if (valeur.length() == 3 && isdigit(valeur[0]) && isdigit(valeur[1])) {
         direction = valeur[2];
         switch (direction) {
            case 'u':
            case'd':
            case 'l':
            case 'r':
               return valeur;
            default:
               cout << MESSAGE_ERREUR << endl;
               cin.clear();
               cin.ignore(numeric_limits<int>::max(), '\n');
         }
      }
      else 
      {
         cout << MESSAGE_ERREUR << endl;
         cin.clear();
         cin.ignore(numeric_limits<int>::max(), '\n');
      }
   } while (entree_invalide); // tant que l'entrée est invalide, on garde l'utilisateur captif   

   return valeur;
}


void sautRetraitPion(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur)
{

   char ligne = char2int(saisieUtilisateur.at(0)),
        colonne = char2int(saisieUtilisateur.at(1)),
        deplacement = saisieUtilisateur.at(2);
   ligne --;
   colonne --;
   switch (deplacement) 
   {
      case 'u': //Up
         surfaceJeu[ligne][colonne] = Etats::ENLEVE;
         surfaceJeu[ligne - 1][colonne] = Etats::ENLEVE;
         surfaceJeu[ligne - 2][colonne] = Etats::PLEIN;
         break;
      case 'd': //Down
         surfaceJeu[ligne][colonne] = Etats::ENLEVE;
         surfaceJeu[ligne + 1][colonne] = Etats::ENLEVE;
         surfaceJeu[ligne + 2][colonne] = Etats::PLEIN;
         break;
      case 'l': //Left
         surfaceJeu[ligne][colonne] = Etats::ENLEVE;
         surfaceJeu[ligne][colonne - 1] = Etats::ENLEVE;
         surfaceJeu[ligne][colonne - 2] = Etats::PLEIN;
         break;
      case 'r': //Right
         surfaceJeu[ligne][colonne] = Etats::ENLEVE;
         surfaceJeu[ligne][colonne + 1] = Etats::ENLEVE;
         surfaceJeu[ligne][colonne + 2] = Etats::PLEIN;
         break;
      default: 
         break;
   }
}