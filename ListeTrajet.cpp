/*************************************************************************
                           ListeTrajet  -  Objet Liste Trajet
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par FLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr                
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <ListeTrajet> (fichier ListeTrajet.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
using namespace std;
#include <iostream>
#include <cstring>
#include <istream>
#include <fstream>
#include "ListeTrajet.h"
#include "Trajet.h"
#include "TC.h"
#include "TS.h"
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
  ListeTrajet::ListeTrajet()
  // Algorithme :
  // 
  {
    sizeListe =0;
    Head = NULL;
    Tail =  NULL;

  #ifdef MAP
    cout << "Construction de ListeTrajet" << endl;
  #endif
  } //----- fin de constructeur

  ListeTrajet::~ListeTrajet(){
    // Algorithme:  Parcours de la liste en partant du pointeur
    //              Head, suppression de l'espace alloué aux 
    //              MaillonTrajets un à un
    MaillonTrajet * suppr;
    
    for(int i=0;i<sizeListe-1;i++){
      suppr = Head;
      Head=Head->getNext();
      delete suppr;
    }
    suppr = Head;
    delete suppr;

  #ifdef MAP
    cout << "Destruction de ListeTrajet" << endl;
  #endif
  } //----- fin de destructreur

  const void ListeTrajet::Affichage(){
    MaillonTrajet * ptrMaillon = Head;
    for (int i=0;i<sizeListe;i++){
      cout << "\n-------------------------------------------" << endl;
      cout << "-------------------------------------------\n" << endl;
      ptrMaillon->Affichage();
      ptrMaillon = ptrMaillon->getNext();
    }
  } //----- fin de Affichage

  const void ListeTrajet::AffichageTC(){
    MaillonTrajet * ptrMaillon = Head;
    for (int i=0;i<sizeListe;i++){
      ptrMaillon->Affichage();
      ptrMaillon = ptrMaillon->getNext();
    }
  } //----- fin de AffichageTC

  void ListeTrajet::Chercher(const char * Depart, const char * Arrivee){
    // Algorithme:  Parcours de la liste chainée en partant de Head
    //              et affichage direct de chaque trajet 
    //              correspondant
    int i=1;
    bool aff=false;
    int c1, c2;
    MaillonTrajet * ptrMaillon = Head;
    c1=strcmp(Depart, ptrMaillon->getDepart());
    c2=strcmp(Arrivee, ptrMaillon->getArrivee());
    if(c1==0 && c2==0){
      cout <<endl << "---------------------------------------"<<endl;
      ptrMaillon->Affichage();
      aff=true;
    }
    while (i<sizeListe){

      c1=strcmp(Depart, ptrMaillon->getDepart());
      c2=strcmp(Arrivee, ptrMaillon->getArrivee());
      if(c1==0 && c2==0){
        
        cout << endl <<"-------------------------------------"<<endl;
        ptrMaillon->Affichage();
        aff=true;
      }
      ptrMaillon = ptrMaillon->getNext();
      i++;
    }

    if(aff==false){
      cout << "Aucun Trajet Trouvé"<< endl;
    }else{
      cout <<endl <<"-------------------------------------";
    }
    cout << endl;
  }

  void ListeTrajet::Ajouter(Trajet * trajetAjoutee){
    // Algorithme : Si la liste n'a encore aucun élément, on mets le Head et le Tail
    //      sur l'unique maillon que l'on vient d'ajouter
    //    Si la liste a déjà des éléments, on ajoute l'élément à la fin et il devient
    //      le Tail.
      sizeListe++;
      MaillonTrajet * maillonAjoutee = new MaillonTrajet(trajetAjoutee);

      if(sizeListe==1){
        Tail=maillonAjoutee;
        Head=maillonAjoutee;
      }else{
        Tail->setNext(maillonAjoutee);
        Tail=maillonAjoutee;
      }
  } //----- fin de Ajouter

  MaillonTrajet * ListeTrajet::getHead(){
    return Head;
  }
  
  int ListeTrajet::getSize(){
    return sizeListe;
  }
   
  void ListeTrajet::Charger(ifstream & monfic){
    char * buffer = new char[100];
    cout << "DEBUT BUFFER" << endl;
    monfic.getline(buffer,100, ';');
    while(!monfic.eof()){
      cout<< buffer <<endl;
      cout<< "bloque" << endl;
      if(strcmp(buffer,"Simple")==0){
        char lectureDepart[100]; 
        monfic.getline(buffer,100, ';');
        strcpy(lectureDepart,buffer);
        char lectureArrivee[100]; 
        monfic.getline(buffer,100, ';');
        strcpy(lectureArrivee,buffer);
        char lectureLocomotion[100]; 
        monfic.getline(buffer,100, ';');
        strcpy(lectureLocomotion,buffer);
        Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
        this->Ajouter(ptTS1);
        monfic.getline(buffer,100);
        monfic.getline(buffer,100); // 2 fois ??
      } else if(strcmp(buffer,"Complexe")==0){
          
      //     char lectureDepart[100]; 
      //     monfic.getline(buffer,100, ';');
      //     strcpy(lectureDepart,buffer);
      //     char lectureArrivee[100]; 
      //     monfic.getline(buffer,100, ';');
      //     strcpy(lectureArrivee,buffer);
      //     TC * ptTC1 = new TC(lectureDepart, lectureArrivee);
      //     while(strcmp(buffer,"\n[]")!=0 && strcmp(buffer,"[]")!=0 ){
      //       cout<<buffer<<endl;
      //       char lectureDepart[100]; 
      //       monfic.getline(buffer,100, ';');
      //       strcpy(lectureDepart,buffer);
      //       char lectureArrivee[100]; 
      //       monfic.getline(buffer,100, ';');
      //       strcpy(lectureArrivee,buffer);
      //       char lectureLocomotion[100]; 
      //       monfic.getline(buffer,100, ';');
      //       strcpy(lectureLocomotion,buffer);
      //       TS * ptTS = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
      //       ptTC1 -> AjouterTC(ptTS);
      //     }
      //     this->Ajouter(ptTC1);
        
      }
    }
    delete[] buffer;
    cout << "FIN BUFFER" << endl;
  }


  string ListeTrajet::TexteSauvegarde(){
    string texte;
    MaillonTrajet * ptrMaillon = Head;
    for (int i =0; i < sizeListe; i++){
      texte+=ptrMaillon->LigneSauvegarde();
      ptrMaillon=ptrMaillon->getNext();
      texte+="\n";
    }
    return texte;
  }