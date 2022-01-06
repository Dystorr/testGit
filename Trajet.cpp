/*************************************************************************
                           Trajet  -  Objet Trajet
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <Trajet> (fichier Trajet.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
//#define MAP
//------------------------------------------------------ Include personnel
#include "Trajet.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
Trajet::Trajet(const char* $Depart, const char* $Arrivee)
{
  Depart = new char[strlen($Depart)+1];
  Arrivee = new char[strlen($Arrivee)+1];

  strcpy(Depart,$Depart);
  strcpy(Arrivee,$Arrivee);

  #ifdef MAP
    cout << "Construction de trajet" << endl;
  #endif
  
  return ;
} //----- fin de Trajet::Trajet

Trajet::~Trajet(){
  delete[](Depart);
  delete[](Arrivee);
  #ifdef MAP
    cout << "Destructeur de trajet" << endl;
  #endif
} //----- fin de Trajet::~Trajet
 
const void Trajet::Affichage(){
  cout.width(70);
  cout.fill('*');
  cout << left << "*" << endl;
  cout <<"  " <<Depart << " -> " << Arrivee << endl;
} //----- fin de Trajet::Affichage

char * Trajet::getDepart(){
  return Depart;
} //----- fin de getDepart

char * Trajet::getArrivee(){
  return Arrivee;
} //----- fin de getDepart

string Trajet::LigneSauvegarde(){
  string ligne = "Trajet;";
  ligne+=Depart;
  ligne+=";";
  ligne+=Arrivee;
  ligne+=";";
  return ligne;
} //----- fin de LigneSauvegarde



