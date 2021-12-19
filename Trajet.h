/*************************************************************************
                           Trajet  -  Objet Trajet
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <TS> (fichier TS.h) -------------------

#if ! defined ( Trajet_H )
#define Trajet_H
#include <string>
using namespace std;
class Trajet
{
//------------------------------------------------------------------------
// Rôle du module <Trajet>
//    Classe mère reliant TS et TC
//    Sert à pouvoir utiliser les TS et TC en même temps dans les listes de Trajets
//      dans les TC et le Catalogue
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
public:
//---------------------------------------------------- Fonctions publiques
Trajet(const char* $Depart, const char* $Arrivee);
// Mode d'emploi :
// Constructeur de Trajet composée d'une ville de départ et d'une   //  ville et d'une ville d'arrivée
// Contrat : Rentrer des tableaux de caractères constants et
//  terminant par '\0' en entrée

virtual ~Trajet();
// Mode d'emploi :
// Destructeur d'un Trajet 
// Contrat : Pas de contrat
//

virtual const void Affichage();
// Mode d'emploi :
// Réalise l'affichage d'un trajet  
// Contrat : Pas de contrat
//

char * getDepart();
// Mode d'emploi :
// Renvoie le départ du trajet
// Contrat : pas de contrat

char * getArrivee();
// Mode d'emploi :
// Renvoie l'arrivée du trajet
// Contrat : pas de contrat

virtual string LigneSauvegarde();
// Mode d'emploi : 
// Renvoi de la ligne formatée pour la sauvegarde du Trajet
// Contrat : Pas de contrat

///////////////////////////////////////////////////////////////  PROTECTED
protected:
  char* Depart;   //Depart du trajet
  char* Arrivee;  //Arrivee du trajet
};
#endif // Trajet_H

