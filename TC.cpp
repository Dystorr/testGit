/*************************************************************************
                           TC  -  Objet Trajet Complexe
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <TC> (fichier TC.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "TC.h"
#include "Trajet.h"
#include "TS.h"
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
TC::TC(const char* $Depart, const char* $Arrivee)
// Algorithme :
//   
: Trajet($Depart, $Arrivee)
{
  
  #ifdef MAP
    cout << "Construction de TC" << endl;
  #endif
} //----- fin de constructeur

TC::~TC()
{

  #ifdef MAP
    cout << "Destruction de TC" << endl;
  #endif
} //----- fin de destructeur

void TC::AjouterTC(Trajet * $unTrajet)
{
  maListeTrajet.Ajouter($unTrajet);
} //----- fin de AjouterTC

const void TC::Affichage(){
  Trajet::Affichage();
  cout << "  Trajet Complexe composé de : "<< endl;
  maListeTrajet.AffichageTC();
} 

string TC::LigneSauvegarde()
//Algorithme: pas d'algorithme
{
  string ligne;

  ligne+="Complexe;";
  ligne+=Depart;
  ligne+=";";
  ligne+=Arrivee;
  ligne+=";";

  string ligneTS = maListeTrajet.TexteSauvegarde();
  //On réutilise la méthode de formatage des trajets simples
  //  prévue pour le catalogue
  //On reformate le string obtenu pour convenir à notre TCw
  //  ci-dessous
  ligneTS.erase(0,7);
  for(unsigned int i=0; i< ligneTS.size(); i++){
    if(ligneTS[i] == '\n')     //Si c'est un retour chariot
    {
      ligneTS.erase(i,8);   //Efface le i-ème caractère
    }
  }

  ligne+=ligneTS;
  
  return ligne;
}
