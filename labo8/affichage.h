/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   affichage.h
 * Author: prosouth
 *
 * Created on 18 December 2016, 08:43
 */

#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "constantes.h"

/**
 Affiche le tableau de jeu avec l'état actuel
 
 @param Tableau d'enum contenant l'état du jeu
 */
void afficher(Etats surfaceJeu[][NB_COLONNES]);

#endif /* AFFICHAGE_H */

