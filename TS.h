/*************************************************************************
                           TS  -  Objet Trajet Simple
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <TS> (fichier TS.h) -------------------
#if ! defined ( TS_H )
#define TS_H
class TS:public Trajet{
//------------------------------------------------------------------------
// Rôle du module <TS>
//    Classe fille de Trajet et soeur de TC
//    Implémente un trajet de base, avec un départ, une arrivée et un moyen de transport
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
public:
//---------------------------------------------------- Fonctions 
TS(const char* $Depart, const char* $Arrivee, const char* 
$Locomotion );
// Mode d'emploi : 
// Réalise la construction d'un TS
// Contrat : 
// Entrer des chaines de caractères constantes se terminant par le 
//  caractère '\0'

virtual ~TS();
//Mode d'emploi : 
// Réalise la destruction d'un TS
// Contrat : Pas de contrat

virtual const void Affichage();
// Mode d'emploi :
// Réalise l'affichage d'un trajet simple 
// Contrat : Pas de contrat
//

string LigneSauvegarde();

///////////////////////////////////////////////////////////////  PROTECTED
protected:
  char* Locomotion; // Moyen de locomotion utilisé pour le trajet
};
#endif // TS_H

