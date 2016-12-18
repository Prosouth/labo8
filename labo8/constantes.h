/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   constantes.h
 * Author: prosouth
 *
 * Created on 18 December 2016, 23:35
 */

#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <string>
using namespace std;

// Enum class des états du tableau de jeu
enum class Etats {VIDE = 0, ENLEVE = 1, PLEIN = 2};


// Constantes
const int NB_COLONNES = 7,
          NB_LIGNES = 7;
const string QUESTION = "Entrez votre deplacement souhaite: ",
             MESSAGE_ERREUR = "Entree non valide";
const char LETTRE_QUITTER = 'q';


#endif /* CONSTANTES_H */

