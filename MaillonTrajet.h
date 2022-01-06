/*************************************************************************
                           MaillonTrajet  -  Objet Maillon Trajet
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <MaillonTrajet> (fichier MaillonTrajet.h) -----------
#if ! defined ( MaillonTrajet_H )
#define MaillonTrajet_H
#include "Trajet.h"
class MaillonTrajet{
//------------------------------------------------------------------------
// Rôle du module <MaillonTrajet>
//    Maillon de la liste simplement chainée ListeTrajet
//      Il contient un pointeur de Trajet et pointe vers le maillon suivant
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
public:
MaillonTrajet(Trajet * $data);
// Mode d'emploi :
// Constructeur d'un trajet
// Contrat : Pas de contrat
//

~MaillonTrajet();
// Mode d'emploi :
// Destructeur d'un MaillonTrajet
// Contrat : Pas de contrat
//
const void Affichage();
// Mode d'emploi :
// Affichage du Trajet contenu par le Maillon
// Contrat : Pas de contrat
//

MaillonTrajet * getNext();
// Mode d'emploi :
// Obtention du pointeur vers le trajet suivant
// Contrat : Pas de contrat
//

char * getDepart();
// Mode d'emploi :
// Obtention du départ du trajet contenu par le pointeur
// Contrat : Pas de contrat
//

char * getArrivee();
// Mode d'emploi :
// Obtention de l'arrivée du trajet contenu par le pointeur
// Contrat : Pas de contrat
//

void setNext(MaillonTrajet * next);
// Mode d'emploi :
// Changement du Maillon suivant
// Contrat : Un pointeur de MaillonTrajet en paramètre
//

string LigneSauvegarde();
// Mode d'emploi : 
// Renvoi du string au format de sauvegarde du 
//   trajet contenu
// Contrat : Pas de contrat

protected:
  Trajet * data;
  MaillonTrajet * next;
};
#endif // TC_H