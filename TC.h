
/*************************************************************************
                           TC  -  Objet Trajet Complexe
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <TC> (fichier TC.h) -------------------
#if ! defined ( TC_H )
#define TC_H
#include "ListeTrajet.h"

class TC:public Trajet{
//------------------------------------------------------------------------
// Rôle du module <TC>
//    C'est une classe fille de Trajet et soeur de TS
//    Elle possède une liste simplement chainee ListeTrajet de TS ou TC
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
public:
  TC(const char* $Depart, const char* $Arrivee);
// Mode d'emploi :
// Constructeur d'un TC
// Contrat : Pas de contrat
//
  virtual ~TC();
// Mode d'emploi :
// Destructeur d'un TC
// Contrat : Pas de contrat
//
  void AjouterTC(Trajet * $unTrajet);
// Mode d'emploi :
// Ajoute un Trajet TC ou TS dans le Trajet complexe
// Contrat : Pointeur de Trajet en entrée, pointant un TC ou un TS
//
  const void Affichage();
// Mode d'emploi :
// Affiche un trajet
// Contrat : Pas de contrat
//

  string LigneSauvegarde();
// Mode d'emploi : 
// Renvoi de la ligne de sauvegarde du TC
// Contrat : Pas de contrat

protected:
  ListeTrajet maListeTrajet; // La liste de trajets composant le TC
};
#endif // TC_H