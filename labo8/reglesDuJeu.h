/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   regleDuJeu.h
 * Author: prosouth
 *
 * Created on 18 December 2016, 08:44
 */

#ifndef REGLEDUJEU_H
#define REGLEDUJEU_H
#include "constantes.h"
/**
 Fonction qui affiche les mouvements possibles 
 
 @param Tableau d'enum à traiter pour trouver les mouvements possibles 
 */
void aide(Etats surfaceJeu[][NB_COLONNES]);


/**
 Fonction qui retire le pion du damier et déplace le pion qui passe au-dessus. 
 
 @param Tableau d'enum contenant l'état du jeu
 @param saisieUtilisateur contient la saisie de l'utilisateur
 */
void sautRetraitPion(Etats surfaceJeu[][NB_COLONNES], string saisieUtilisateur);


/**
Fonction qui transforme un char en int, basé sur la table ASCII 
 @param char c est le caractère à convertir
 */
int char2int(char c);


/**
Fonction qui détermine si un déplacement est valide ou pas 
 @param Tableau d'enum contenant l'état du jeu
 @param string saisieUtilisateur qui contient la saisie de l'utilisateur
 @return bool qui est vrai si le déplacement est valide
 */
bool deplacementValide(Etats surfaceJeu[][NB_COLONNES], string saisieUtilisateur);


/**
Fonction qui vérifie l'état du jeu en cours et termine la partie si plus aucun 
mouvement n'est disponible.
 
 @param Tableau d'enum contenant l'état du jeu
 */
bool finirJeu(Etats surfaceJeu[][NB_COLONNES]);


/**
Fonction qui vérifie la saisie d'un joueur
 
 */
string saisieUtilisateur();




#endif /* REGLEDUJEU_H */

