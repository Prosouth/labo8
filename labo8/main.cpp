
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
using namespace std;

enum class Etats {VIDE = 0, ENLEVE = 1, PLEIN = 2};

// Constantes
const int NB_COLONNES = 7,
          NB_LIGNES = 7;
const string QUESTION = "Entrez votre deplacement souhaite: ",
             MESSAGE_ERREUR = "Entree non valide";
const char LETTRE_QUITTER = 'q';

void aide(Etats surfaceJeu[][NB_COLONNES]);
void sautRetraitPion(Etats surfaceJeu[][NB_COLONNES], string saisieUtilisateur);
void afficher(Etats surfaceJeu[][NB_COLONNES]);
int char2int(char c);
bool deplacementValide(Etats surfaceJeu[][NB_COLONNES], string saisieUtilisateur);
bool finirJeu(Etats surfaceJeu[][NB_COLONNES]);
string saisieUtilisateur();

int main() 
{
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
     if(saisie == "h")
     {
        aide(surfaceJeu);
     }
     afficher(surfaceJeu);
     finirJeu(surfaceJeu);
   }
   while (saisie != "q" || !finirJeu(surfaceJeu));
   
   
   return EXIT_SUCCESS;
}


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
   int compteur = 0;
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
               compteur++;
            }
            if (i <= 5 && surfaceJeu[i + 2][j] == Etats::ENLEVE && surfaceJeu[i + 1][j] == Etats::PLEIN) 
            {
               cout << i + 1 << j + 1 << "d ";
               compteur++;
            }
            if (j <= 5 && surfaceJeu[i][j + 2] == Etats::ENLEVE && surfaceJeu[i][j - 1] == Etats::PLEIN) 
            {
               cout << i + 1 << j + 1 << "r ";
               compteur++;
            }
            if (j >= 2 && surfaceJeu[i][j - 2] == Etats::ENLEVE && surfaceJeu[i][j + 1] == Etats::PLEIN) 
            {
               cout << i + 1 << j + 1 << "l ";
               compteur++;
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
            if (surfaceJeu[i - 2][j] == Etats::ENLEVE && i >= 2 && surfaceJeu[i - 1][j] == Etats::PLEIN) 
            {
               return false;
            }
            if (surfaceJeu[i + 2][j] == Etats::ENLEVE && i <= 5 && surfaceJeu[i + 1][j] == Etats::PLEIN) 
            {
               return false;
            }
            if (surfaceJeu[i][j + 2] == Etats::ENLEVE && j <= 5 && surfaceJeu[i][j - 1] == Etats::PLEIN) 
            {
               return false;
            }
            if (surfaceJeu[i][j - 2] == Etats::ENLEVE && j >= 2 && surfaceJeu[i][j - 1] == Etats::PLEIN) 
            {
               return false;
            }
         }
      }
   }
   return true;
}


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
            cout << " " << i + 1 << j+ 1 << " ";
         }
      }
      cout << endl;
   }
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