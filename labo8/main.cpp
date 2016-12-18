
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

using namespace std;

enum class Etats {VIDE = 0, ENLEVE = 1, PLEIN = 2};

// Constantes
const int NB_COLONNES = 7,
          NB_LIGNES = 7;

void retraitPion(int indice_largeur, int indice_hauteur);
void aide(Etats surfaceJeu[][7]);
void initialisationJeu(int tableau[][NB_LIGNES]);
bool saisieUtilisateur(string& saisieUtilisateur, Etats surfaceJeu[][7]);
void afficher(Etats surfaceJeu[][7]);
int char2int(char c);
void recherchePion(Etats surfaceJeu[][7], int position[][7]);
bool positionCorrect(string& saisie, int x, unsigned int y);
bool deplacementValide(Etats surfaceJeu[][7], string saisieUtilisateur);
void sautRetraitPion(Etats surfaceJeu[NB_LIGNES][NB_COLONNES], string saisieUtilisateur);


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
   aide(surfaceJeu);
   cout << boolalpha << deplacementValide(surfaceJeu, "10u") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "71d") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "12l") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "72r") << endl;
   cout << boolalpha << deplacementValide(surfaceJeu, "64u") << endl;

   
   return EXIT_SUCCESS;
}


bool deplacementValide(Etats surfaceJeu[][NB_COLONNES], string saisieUtilisateur)
{
   char ligne = saisieUtilisateur.at(0),
        colonne = saisieUtilisateur.at(1),
        directionDeplacement = saisieUtilisateur.at(2);
   bool deplacementValide = false;

   switch (directionDeplacement) 
   { // check naïvement que le déplacement ne déborde pas de la surface de jeu
      case 'u':
         if (ligne >= 2 && colonne >= 0 && colonne <= 6 && ligne >= 0 && ligne <= 6)
            deplacementValide = true;
         break;
      case 'd':
         if (ligne <= 4 && colonne >= 0 && colonne <= 6 && ligne >= 0 && ligne <= 6)
            deplacementValide = true;
         break;
      case 'l':
         if (colonne >= 2 && colonne >= 0 && colonne <= 6 && ligne >= 0 && ligne <= 6)
            deplacementValide = true;
         break;
      case 'r':
         if (colonne <= 4 && colonne >= 0 && colonne <= 6 && ligne >= 0 && ligne <= 6)
            deplacementValide = true;
         break;
      default: break;
   }

   if (deplacementValide) 
   {
      switch (directionDeplacement) 
      {
         case 'u'://Up
            return (surfaceJeu[colonne - 1][ligne - 1] == Etats::PLEIN && surfaceJeu[colonne - 1][ligne - 2] == Etats::PLEIN
                    && surfaceJeu[colonne - 1][ligne - 3] == Etats::ENLEVE);
            break;
         case 'd':
            return (surfaceJeu[colonne - 1][ligne - 1] == Etats::ENLEVE && surfaceJeu[colonne - 1][ligne] == Etats::ENLEVE
                    && surfaceJeu[colonne - 1][ligne + 1] == Etats::VIDE);
            break;
         case 'l':
            return (surfaceJeu[colonne - 1][ligne - 1] == Etats::ENLEVE && surfaceJeu[colonne][ligne - 1] == Etats::ENLEVE
                    && surfaceJeu[colonne][ligne + 2] == Etats::VIDE);
            break;
         case'r':
            return (surfaceJeu[colonne - 1][ligne - 1] == Etats::ENLEVE && surfaceJeu[colonne][ligne - 1] == Etats::ENLEVE
                    && surfaceJeu[colonne + 1][ligne - 1] == Etats::VIDE);
            break;
         default:
            return false;
      }
   }
   else
   {
      return false;
   }
}



void retraitPion(int indice_largeur, int indice_hauteur)
{
   
}


void aide(Etats surfaceJeu[7][7])
{
   int compteur = 1;
   cout << "Deplacements possibles:";
   for (int i = 0; i < NB_COLONNES; i++) {
      for (int j = 0; j < NB_LIGNES; j++) {
         if(surfaceJeu[i][j] == Etats::VIDE)
         {
            cout << i + 1 << j + 1 << "lol" << " " << endl;
         }
      }
   }
}


void initialisationJeu(int tableau[][NB_LIGNES])
{
   
   
}


void afficher(Etats surfaceJeu[][7])
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


bool saisieUtilisateur(string& saisieUtilisateur, Etats surfaceJeu[][NB_COLONNES]) 
{

    const string MESSAGE_ERREUR = "Entree non valide";
    const char LETTRE_QUITTER = 'Q';
    bool ContinuerlaPartie = true;

    //si l'utilisateur quitte le programme
    if (saisieUtilisateur[0] == LETTRE_QUITTER) {
        ContinuerlaPartie = false;
    } else {
        if (saisieUtilisateur.length() == 3) {
            for (int i = 0; i <= 2; i++) {
                char saisie = saisieUtilisateur[i];
                if (saisie > '0' or saisie < '7') {
                    ContinuerlaPartie = true;
                } else //mauvaise saisie
                {
                    cout << MESSAGE_ERREUR << endl;
                }

            }
        } else {
            cout << MESSAGE_ERREUR << endl;
        }
    }
}


void recherchePion(Etats surfaceJeu[][NB_COLONNES], int position[][NB_COLONNES]) {

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


bool positionCorrect(string& saisie, int& x, unsigned int& y) {

    //Mettre en majuscule ladirection
    y = toupper(saisie[2]);

    if (y != string::npos) {
        //Cordonnée des lignes
        x = saisie[1] - '0';

        if (x >= 1 and x <= 7) {
            //Permet d'avoir les valeurs exactes des positions
            x = abs(x - 7);
            return true;
        } else//lignes fausses
        {
            return false;
        }
    } else//colonne fausse
    {
        return false;
    }
}

void sautRetraitPion(int surfaceJeu[NB_LIGNES][NB_COLONNES], string saisieUtilisateur) {
 
    char depl = saisieUtilisateur[2];
    switch (depl) {
        case 'U': //Up
            surfaceJeu[NB_LIGNES][NB_COLONNES] = 1;
            surfaceJeu[NB_LIGNES - 1][NB_COLONNES] = 1;
            surfaceJeu[NB_LIGNES - 2][NB_COLONNES] = 2;
            break;
        case 'D': //Down
            surfaceJeu[NB_LIGNES][NB_COLONNES] = 1;
            surfaceJeu[NB_LIGNES + 1][NB_COLONNES] = 1;
            surfaceJeu[NB_LIGNES + 2][NB_COLONNES] = 2;
            break;
        case 'L': //Left
            surfaceJeu[NB_LIGNES][NB_COLONNES] = 1;
            surfaceJeu[NB_LIGNES][NB_COLONNES + 1] = 1;
            surfaceJeu[NB_LIGNES][NB_COLONNES + 2] = 2;
            break;
        case 'R': //Right
            surfaceJeu[NB_LIGNES][NB_COLONNES] = 1;
            surfaceJeu[NB_LIGNES][NB_COLONNES - 1] = 1;
            surfaceJeu[NB_LIGNES][NB_COLONNES - 2] = 2;
            break;
        default: cout << "Non valide";
            break;
    }
 
}