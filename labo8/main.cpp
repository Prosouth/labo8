
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
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

enum class Etats {VIDE = 0, ENLEVE = 1, PLEIN = 2};

// Constantes
const int NB_COLONNES = 7,
          NB_LIGNES = 7;
const string QUESTION = "Entrez votre deplacement souhaite: ",
             MESSAGE_ERREUR = "Entree non valide";
const char LETTRE_QUITTER = 'q';

void aide(Etats surfaceJeu[][NB_LIGNES]);
string saisieUtilisateur(Etats surfaceJeu[][NB_LIGNES]);
void afficher(Etats surfaceJeu[][NB_LIGNES]);
int char2int(char c);
void recherchePion(Etats surfaceJeu[][NB_LIGNES], int position[][NB_LIGNES]);
bool deplacementValide(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur);
void sautRetraitPion(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur);
string saisieDuGhetto(Etats surfaceJeu[][NB_LIGNES]);


int main() 
{
   Etats surfaceJeu[NB_COLONNES][NB_LIGNES] = 
   {{Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE},
   {Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE},
   {Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN},
   {Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::ENLEVE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN},
   {Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN},
   {Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE},
   {Etats::VIDE,Etats::VIDE,Etats::PLEIN,Etats::PLEIN,Etats::PLEIN,Etats::VIDE,Etats::VIDE}};

   afficher(surfaceJeu);
   
  //saisieUtilisateur(surfaceJeu);
   
   cout << boolalpha << deplacementValide(surfaceJeu, "10u") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "71d") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "12l") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "72r") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "64u") << endl;
   
   aide(surfaceJeu);
   
   return EXIT_SUCCESS;
}

bool deplacementValide(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur)
{
   char ligne = char2int(saisieUtilisateur.at(0)),
           colonne = char2int(saisieUtilisateur.at(1)),
           directionDeplacement = saisieUtilisateur.at(2);
   colonne--; // pour matcher le tableau d'enum directement
   ligne--;
   bool deplacementValide = false;

   if (surfaceJeu[colonne][ligne] == Etats::PLEIN) 
   {
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

      if (deplacementValide) 
      {
         switch (directionDeplacement) 
         {
            case 'u':// up
               return (surfaceJeu[colonne][ligne - 1] == Etats::PLEIN
                       && surfaceJeu[colonne][ligne - 2] == Etats::ENLEVE);
               break;
            case 'd': // down
               return (surfaceJeu[colonne][ligne + 1] == Etats::PLEIN
                       && surfaceJeu[colonne][ligne + 2] == Etats::ENLEVE);
               break;
            case 'l': // left
               return (surfaceJeu[colonne - 1][ligne] == Etats::PLEIN
                       && surfaceJeu[colonne - 2][ligne] == Etats::ENLEVE);
               break;
            case'r': // right
               return (surfaceJeu[colonne + 1][ligne] == Etats::PLEIN
                       && surfaceJeu[colonne + 2][ligne] == Etats::ENLEVE);
               break;
            default:
               return false;
         }
      }
   } 
   else 
   {
      return false;
   }
}


void aide(Etats surfaceJeu[][NB_LIGNES])
{
   int compteur = 0;
   cout << "Deplacements possibles:";
   for (int i = 0; i < NB_COLONNES; i++) {
      for (int j = 0; j < NB_LIGNES; j++) {
         if(surfaceJeu[i - 2][j] == Etats::ENLEVE && i >= 2 && surfaceJeu[i - 1][j] == Etats::PLEIN)
         {
            cout << i + 1 << j + 1 << "u ";
            compteur++;
         }
         if(surfaceJeu[i + 2][j] == Etats::ENLEVE && i <= 5 && surfaceJeu[i + 1][j] == Etats::PLEIN)
         {
            cout << i + 1 << j + 1 << "d ";
            compteur++;
         }
         if(surfaceJeu[i][j + 2] == Etats::ENLEVE && j <= 5 && surfaceJeu[i][j - 1] == Etats::PLEIN)
         {
            cout << i + 1 << j + 1 << "r "; 
            compteur++;
         }
         if(surfaceJeu[i][j - 2] == Etats::ENLEVE && j >= 2 && surfaceJeu[i][j - 1] == Etats::PLEIN)
         {
            cout << i + 1 << j + 1 << "l ";
            compteur ++;
         }   
      }
   }
   cout << endl << "Nombre de coups possibles : "<< compteur << endl;
}


bool finirJeu(Etats surfaceJeu[][NB_LIGNES])
{
   int compteur = 0;
   cout << "Deplacements possibles:";
   for (int i = 0; i < NB_COLONNES; i++) {
      for (int j = 0; j < NB_LIGNES; j++) {
         if(surfaceJeu[i - 2][j] == Etats::ENLEVE && i >= 2 && surfaceJeu[i - 1][j] == Etats::PLEIN)
         {
            compteur++;
         }
         if(surfaceJeu[i + 2][j] == Etats::ENLEVE && i <= 5 && surfaceJeu[i + 1][j] == Etats::PLEIN)
         {
            compteur++;
         }
         if(surfaceJeu[i][j + 2] == Etats::ENLEVE && j <= 5 && surfaceJeu[i][j - 1] == Etats::PLEIN)
         {
            compteur++;
         }
         if(surfaceJeu[i][j - 2] == Etats::ENLEVE && j >= 2 && surfaceJeu[i][j - 1] == Etats::PLEIN)
         {
            compteur ++;
         }   
      }
   }
   return !(compteur);
}





void afficher(Etats surfaceJeu[][NB_LIGNES])
{
   for (int i = 0; i < NB_COLONNES; i++) {
      for (int j = 0; j < NB_LIGNES; j++) {
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


string saisieUtilisateur(Etats surfaceJeu[][NB_LIGNES]) 
{
   string valeur;
   bool entree_invalide = false;
   do
   {
     cout << QUESTION;
     cin >> valeur;
     entree_invalide = !(!valeur.empty() || isdigit(valeur[0]) && isdigit(valeur[1]) && isalpha(valeur[2]));
     if (entree_invalide) // si entrée est invalide, on affiche erreur, vide buffer et affiche question
      {
         cout << MESSAGE_ERREUR << endl;
         cin.clear();
         cin.ignore(numeric_limits<int>::max(), '\n');
      }
   }
   while(entree_invalide); // tant que l'entrée est invalide, on garde l'utilisateur captif   
   
   //deplacementValide(surfaceJeu, saisieUtilisateur);
 
return valeur;
}


string saisieDuGhetto(Etats surfaceJeu[][NB_LIGNES])
{
   string saisie;
   cout << QUESTION << endl;
   cin >> saisie;
   
   return saisie;
}


void recherchePion(Etats surfaceJeu[][NB_LIGNES], int position[][NB_COLONNES]) {

    int trouve = 0, j = 0, i = 0, y = 0;
    for (; y < 7 && !trouve; y++) {
        for (; i < 7 && !trouve; i++) {
            if (surfaceJeu[y][i] == Etats::ENLEVE) {
                surfaceJeu[y][i] = Etats::PLEIN;
                position[j][j] = y + 1;
                position[j][j + 1] = i + 1;
                trouve = 1;
            }
        }
    }
    if (!trouve)
        return;
}


void sautRetraitPion(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur)
{

   char ligne = char2int(saisieUtilisateur.at(0)),
        colonne = char2int(saisieUtilisateur.at(1)),
        deplacement = saisieUtilisateur.at(2);
   switch (deplacement) {
      case 'u': //Up
         surfaceJeu[colonne][ligne] = Etats::ENLEVE;
         surfaceJeu[colonne][ligne - 1] = Etats::ENLEVE;
         surfaceJeu[colonne][ligne - 2] = Etats::PLEIN;
         break;
      case 'd': //Down
         surfaceJeu[colonne][ligne] = Etats::ENLEVE;
         surfaceJeu[colonne][ligne + 1] = Etats::ENLEVE;
         surfaceJeu[colonne][ligne + 2] = Etats::PLEIN;
         break;
      case 'l': //Left
         surfaceJeu[colonne][ligne] = Etats::ENLEVE;
         surfaceJeu[colonne - 1][ligne] = Etats::ENLEVE;
         surfaceJeu[colonne - 2][ligne] = Etats::PLEIN;
         break;
      case 'r': //Right
         surfaceJeu[colonne][ligne] = Etats::ENLEVE;
         surfaceJeu[colonne + 1][ligne] = Etats::ENLEVE;
         surfaceJeu[colonne + 2][ligne] = Etats::PLEIN;
         break;
      default: 
         cout << "";
         break;
   }
}