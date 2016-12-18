#include "reglesDuJeu.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
using namespace std;


bool deplacementValide(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur)
{
   if (saisieUtilisateur.length() != 3)
   {
      return false;
   }
   char ligne = char2int(saisieUtilisateur.at(0)), // parse la ligne
        colonne = char2int(saisieUtilisateur.at(1)), // parse la colonne
        directionDeplacement = saisieUtilisateur.at(2); // parse le direction du déplacement
   colonne --; // pour matcher le tableau d'enum directement
   ligne --;
   bool deplacementValide = false;
   
   // Si la surface du jeu contient une boule
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

   // si le déplacement n'est pas valide, pas besoin de tester plus loin.
   if (!deplacementValide) 
   {
      return false;
   }
   // on teste maintenant qu'on puisse se déplacer comme il faut
   // une boule pleine puis une boule enlevée
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
   // On itère à travers la surface de jeu pour chercher les mouvements possibles
   // en cherchant dans les 4 directions et ensuite on affiche les possiblités
   for (int i = 0; i < NB_LIGNES; i++)
   {
      for (int j = 0; j < NB_COLONNES; j++) 
      {
         // on teste d'abord que la case soit bien pleine, sinon ça sert à rien...
         if (surfaceJeu[i][j] == Etats::PLEIN) 
         {
            // ensuite on regarde les cases avoisinantes
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

   // Même principe que pour la fonction aide sauf que là on quitte la boucle
   // pour pas itérer pour rien.
   int compteur = 0;
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
            
            compteur++;
         }
      }
   }

   return true; // S'il ne trouve pas de possiblités, on a fini le jeu
   
   if(compteur == 1) {
       
       if(surfaceJeu[3][3] == Etats::PLEIN) {
          cout << "Parfait, il ne reste qu'une bille au centre" << endl;
       }
       else {
          cout << "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait" << endl;
       }
       
   }
   else if(compteur >= 2 && compteur <= 5) {
       cout << "Pas mal, il ne reste que N billes" << endl;
   }
   else {
       cout << "Vous pouvez faire mieux, il reste N billes " << endl;
   }
   
   return true;
}


int char2int(char c) // utilisée pour parser les déplacements
{
   return c - '0'; // décalage nécessaire pour trouver le char en valeur entière
}




string saisieUtilisateur()
{
   string valeur;
   char direction;
   bool entree_invalide = true;
   do {
      cout << QUESTION;
      cin >> valeur;
      if (valeur == "q") 
      {
         return valeur;
      }
      if (valeur == "h") 
      {
         return valeur;
      }
      if (valeur.length() == 3 && isdigit(valeur[0]) && isdigit(valeur[1])) {
         direction = valeur[2];
         switch (direction) 
         {
            case 'u':
            case'd':
            case 'l':
            case 'r':
               return valeur; 
               break;
            default:
               // autrement, on affiche le message d'erreur et on vide le buffer
               cout << MESSAGE_ERREUR << endl;
               cin.clear();
               cin.ignore(numeric_limits<int>::max(), '\n');
         }
      }
      else 
      {
         // on vide le buffer pour pas qu'il reste des caractères
         cout << MESSAGE_ERREUR << endl;
         cin.clear();
         cin.ignore(numeric_limits<int>::max(), '\n');
      }
   } while (entree_invalide); // tant que l'entrée est invalide, on garde l'utilisateur captif   

   return valeur;
}


void sautRetraitPion(Etats surfaceJeu[][NB_LIGNES], string saisieUtilisateur)
{

   char ligne = char2int(saisieUtilisateur.at(0)), // Même principe, on parse
        colonne = char2int(saisieUtilisateur.at(1)),
        deplacement = saisieUtilisateur.at(2);
   ligne --; // on réduit les indices de 1 pour matcher avec les indices du tableau
   colonne --;
   switch (deplacement) 
   {
      case 'u': //Up
         surfaceJeu[ligne][colonne] = Etats::ENLEVE; // On enlève le pion qu'on mange, puis
         surfaceJeu[ligne - 1][colonne] = Etats::ENLEVE; // on déplace le pion utilisé 2 cases plus loin
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