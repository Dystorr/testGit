/*************************************************************************
                           ListeTrajet  -  Objet Liste Trajet
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <ListeTrajet> (fichier ListeTrajet.h) -----------
#if ! defined ( ListeTrajet_H )
#define ListeTrajet_H
#include "MaillonTrajet.h"
class ListeTrajet{
//------------------------------------------------------------------------
// Rôle du module <ListeTrajet>
//    ListeTrajet est l'objet liste simplement chainée qui sert dans le Catalogue et 
//      dans TC
//    Il utilise MaillonTrajet comme maillons et a un pointeur Tail pour ajouter en fin
//      de liste et un Head pour lire à partir du début
//    
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
public:
ListeTrajet();
// Mode d'emploi :
// Constructeur d'un trajet
// Contrat : Pas de contrat
//

~ListeTrajet();
// Mode d'emploi :
// Destructeur de tous les MaillonTrajet de la liste chainée
// Contrat : Pas de contrat
//
const void Affichage();
// Mode d'emploi :
// Affichage du Trajet contenu par le Maillon, en format d'affichage de Catalogue
// Contrat : Pas de contrat
//
const void AffichageTC();
// Mode d'emploi :
// Affichage du Trajet contenu par le Maillon, en format d'affichage de Trajet Complexe
// Contrat : Pas de contrat
//

void Chercher(const char * Depart, const char * Arrivee);
// Mode d'emploi : 
// Cherche et affiche le trajet avec le Depart et l'Arrivee 
//  correspondant aux parametres
// Contrat :
// Entrer un Départ et une Arrivee qui sont des tableaux de char 
//  constants et se terminant par \0



void Ajouter(Trajet * next);
// Mode d'emploi :
// Ajoute un trajet (un TC ou un TS) à la fin de la liste
//  Crée le Head et le Tail si la liste est vide
//  Remet le Tail à la fin
// Contrat : Un pointeur de Trajet en paramètre; qui peut pointer 
//  un TC ou un TS

MaillonTrajet * getHead();
// Mode d'emploi :
// Recuperation du premier maillon
// Contrat : Pas de contrat

int getSize();
// Mode d'emploi :
// Recuperation de la taille
// Contrat : Pas de contrat



void Charger(ifstream & monfic, string mode);
// Mode d'emploi :
// 
// Contrat : Pas de contrat


string TexteSauvegarde();
// Mode d'emploi : 
// Renvoie le texte à écrire dans le fichier de sauvegarde
// Contrat : Pas de contrat

protected:
  MaillonTrajet * Head; //Pointeur du premier MaillonTrajet
  MaillonTrajet * Tail; //Pointeur du dernier MaillonTrajet
  int sizeListe; //Taille de la liste chaînée
};
#endif // ListeTrajet_H