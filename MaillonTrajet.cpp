/*************************************************************************
                           MaillonTrajet  -  Objet Maillon Trajet
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <MaillonTrajet> (fichier MaillonTrajet.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
using namespace std;
#include <iostream>
#include <cstring>
#include "MaillonTrajet.h"
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
  MaillonTrajet::MaillonTrajet(Trajet * $data)
  {
    data=$data;
    next = NULL;

  #ifdef MAP
    cout << "Construction de MaillonTrajet" << endl;
  #endif
  } //----- fin de constructreur

  MaillonTrajet::~MaillonTrajet(){
    delete data;

  #ifdef MAP
    cout << "Destruction de MaillonTrajet" << endl;
  #endif
  } //----- fin de destructreur

  MaillonTrajet* MaillonTrajet::getNext(){
    return next;
  } //----- fin de getNext

  char * MaillonTrajet::getDepart(){
    return data->getDepart();
  } //----- fin de getNext

  char * MaillonTrajet::getArrivee(){
    return data->getArrivee();
  } //----- fin de getNext

  void MaillonTrajet::setNext(MaillonTrajet * $next){
    next=$next;
  } //----- fin de setNext

  const void MaillonTrajet::Affichage(){
    data->Affichage();
  } //----- fin de Affichage

  string MaillonTrajet::LigneSauvegarde(){
    string ligne = data->LigneSauvegarde();
    return ligne;
  } //----- fin de LigneSauvegarde

