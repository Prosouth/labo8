
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

bool mouvementValide(string deplacement);
void retraitPion(int indice_largeur, int indice_hauteur);
void aide(Etats surfaceJeu[7][7]);
void initialisationJeu(int tableau[][NB_LIGNES]);
bool saisieUtilisateur(string& saisieUtilisateur, int surfaceJeu[][7]);
void afficher(Etats surfaceJeu[7][7]);
int char2int(char c);
void recherchePion(int surfaceJeu[][7], int position[][7]);
bool positionCorrect(string& saisie, int x, unsigned int y);
void deplacementValide(int surfaceJeu[][7], string saisieUtilisateur);


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
   mouvementValide("12u");
   cout << mouvementValide("11u") << endl;
   cout <<  mouvementValide("71d") << endl;
   cout <<  mouvementValide("12l") << endl;
   cout <<  mouvementValide("72r") << endl;


   
   return EXIT_SUCCESS;
}


bool mouvementValide(string deplacement)
{
   char premier_char = deplacement.at(0);
   char deuxieme_char = deplacement.at(1);
   char troisieme_char = deplacement.at(2);
   int colonne = char2int(premier_char);
   int ligne = char2int(deuxieme_char);
      
   return ((troisieme_char == 'u' && ligne > 1) || (troisieme_char == 'd' && ligne < 7)
       || (troisieme_char == 'l' && colonne > 1) || (troisieme_char == 'r' && colonne < 7));
}

int lign = 0, colonne = 0;
bool DeplacementValide = true;

bool deplacementValide(Etats surfaceJeu[][NB_COLONNES], string saisieUtilisateur) {

    char depl = saisieUtilisateur[2];
    bool deplacementValide = true;

    switch (depl) {
        case 'U':
            if (NB_LIGNES == 0 or NB_LIGNES == 1
                    or (NB_LIGNES == 2 && NB_COLONNES == 0) or (NB_LIGNES == 2 && NB_COLONNES == 1)
                    or (NB_LIGNES == 2 && NB_COLONNES == 5) or (NB_LIGNES == 2 && NB_COLONNES == 6)
                    or (NB_LIGNES == 3 && NB_COLONNES == 0) or (NB_LIGNES == 3 && NB_COLONNES == 1)
                    or (NB_LIGNES == 3 && NB_COLONNES == 5) or (NB_LIGNES == 3 && NB_COLONNES == 6))
                deplacementValide = false;

            break;
        case 'D':
        {
            if (NB_LIGNES == 5 or NB_LIGNES == 6
                    or (NB_LIGNES == 4 && NB_COLONNES == 0) or (NB_LIGNES == 4 && NB_COLONNES == 1)
                    or (NB_LIGNES == 4 && NB_COLONNES == 5) or (NB_LIGNES == 4 && NB_COLONNES == 6)
                    or (NB_LIGNES == 3 && NB_COLONNES == 0) or (NB_LIGNES == 3 && NB_COLONNES == 1)
                    or (NB_LIGNES == 3 && NB_COLONNES == 5) or (NB_LIGNES == 3 && NB_COLONNES == 6))
                deplacementValide = false;
            break;
            case 'L':
            if (NB_COLONNES == 5 or NB_COLONNES == 6
                    or (NB_LIGNES == 0 && NB_COLONNES == 3) or (NB_LIGNES == 1 && NB_COLONNES == 3)
                    or (NB_LIGNES == 5 && NB_COLONNES == 3) or (NB_LIGNES == 6 && NB_COLONNES == 3)
                    or (NB_LIGNES == 0 && NB_COLONNES == 4) or (NB_LIGNES == 1 && NB_COLONNES == 4)
                    or (NB_LIGNES == 5 && NB_COLONNES == 4) or (NB_LIGNES == 6 && NB_COLONNES == 4))
                deplacementValide = false;
            break;

            case 'R':
            if (NB_COLONNES == 0 or NB_COLONNES == 1
                    or (NB_LIGNES == 0 && NB_COLONNES == 3) or (NB_LIGNES == 1 && NB_COLONNES == 3)
                    or (NB_LIGNES == 5 && NB_COLONNES == 3) or (NB_LIGNES == 6 && NB_COLONNES == 3)
                    or (NB_LIGNES == 0 && NB_COLONNES == 2) or (NB_LIGNES == 1 && NB_COLONNES == 2)
                    or (NB_LIGNES == 5 && NB_COLONNES == 2) or (NB_LIGNES == 6 && NB_COLONNES == 2))
                deplacementValide = false;
            break;
            default: break;
        }

            if (deplacementValide) {

                switch (depl) {
                    case 'U'://Up
                        if (surfaceJeu[NB_LIGNES][NB_COLONNES] == Etats::ENLEVE && surfaceJeu[NB_LIGNES - 1][NB_COLONNES] == Etats::ENLEVE 
                                && surfaceJeu[NB_LIGNES - 2][NB_COLONNES] == Etats::VIDE) return true;
                        else return false;
                        break;
                    case 'D':
                        if (surfaceJeu[NB_LIGNES][NB_COLONNES] == Etats::ENLEVE && surfaceJeu[NB_LIGNES + 1][NB_COLONNES] == Etats::ENLEVE 
                                && surfaceJeu[NB_LIGNES + 2][NB_COLONNES] == Etats::VIDE) return true;
                        else return false;
                        break;
                    case 'L':
                        if (surfaceJeu[NB_LIGNES][NB_COLONNES] == Etats::ENLEVE && surfaceJeu[NB_LIGNES][NB_COLONNES + 1] == Etats::ENLEVE 
                                && surfaceJeu[NB_LIGNES][NB_COLONNES + 2] == Etats::VIDE) return true;
                        else return false;
                        break;
                    case'R':
                        if (surfaceJeu[NB_LIGNES][NB_COLONNES] == Etats::ENLEVE && surfaceJeu[NB_LIGNES][NB_COLONNES - 1] == Etats::ENLEVE 
                                && surfaceJeu[NB_LIGNES][NB_COLONNES - 2] == Etats::VIDE) return true;
                        else return false;
                        break;
                    default:
                        return false;
                }
            }
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


bool saisieUtilisateur(string& saisieUtilisateur, int surfaceJeu[][NB_COLONNES]) 
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

void recherchePion(int surfaceJeu[][NB_COLONNES], int position[][NB_COLONNES]) {

    int trouve = 0, j = 0, i = 0, y = 0;
    for (; y < 7 && !trouve; y++) {
        for (; i < 7 && !trouve; i++) {
            if (surfaceJeu[y][i] == 1) {
                surfaceJeu[y][i] = 2;
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
