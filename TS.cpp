
/*************************************************************************
                           TS  -  Objet Trajet Simple
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <TS> (fichier TS.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TS.h"
using namespace std;
#include <iostream>
#include <cstring>
 
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
TS::TS(const char* $Depart, const char* $Arrivee, const char* 
$Locomotion )
: Trajet($Depart, $Arrivee)
{
  Locomotion = new char[strlen($Locomotion)+1];
  strcpy(Locomotion,$Locomotion); 
  return ;
  #ifdef MAP
    cout << "Construction de TS" << endl;
  #endif
} //----- fin de definition d'un TS

TS::~TS(){
  // Algorithme : 
  // Pas d'algorithme
  delete[](Locomotion);
  #ifdef MAP
    cout << "Destruction de TS" << endl;
  #endif
} //----- fin de destruction d'un TS

const void TS::Affichage()
//Algorithme: pas d'algorithmes
{
  Trajet::Affichage();
  cout<< "    Moyen de transport: "<< Locomotion << endl; 
  cout << "***********************************" <<endl;
}

string TS::LigneSauvegarde()
//Algorithme: pas d'algorithme
{
  string ligne;

  ligne+="Simple;";
  ligne+=Depart;
  ligne+=";";
  ligne+=Arrivee;
  ligne+=";";
  ligne+=Locomotion;
  ligne+=";";
  
  return ligne;
}
