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
      cout<< endl;
      cout.width(70);
       cout.fill('-');
      cout << left<< "-" << endl;
      cout<< endl;
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
    ptrMaillon = ptrMaillon->getNext();
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
   
  void ListeTrajet::Charger(ifstream & monfic, string mode, string param1, string param2){
    char * buffer = new char[100];
    monfic.getline(buffer,100, ';');
    int nbTrajetParcouru = 0;
    while(!monfic.eof()){
      if((strcmp(buffer,"Simple")==0 || strcmp(buffer,"\nSimple")==0)){
        nbTrajetParcouru++;
        char lectureDepart[100]; 
        monfic.getline(buffer,100, ';');
        strcpy(lectureDepart,buffer);
        // cout<< "Simple depart " << buffer <<endl;
        char lectureArrivee[100]; 
        monfic.getline(buffer,100, ';');
        strcpy(lectureArrivee,buffer);
        // cout<< "Simple arrivee " << buffer <<endl;
        char lectureLocomotion[100]; 
        monfic.getline(buffer,100, ';');
        strcpy(lectureLocomotion,buffer);
        // cout<< "Simple locomotion " << buffer <<endl;
        if(mode=="T" || mode=="S"){
          Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
          this->Ajouter(ptTS1);
        }
        else if(mode=="D" && param1==(string) lectureDepart){
          Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
          this->Ajouter(ptTS1);
        }
        else if(mode=="A" && param2==(string) lectureArrivee){
          Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
          this->Ajouter(ptTS1);
        }
        else if(mode=="AD" && param1==(string) lectureDepart && param2==(string) lectureArrivee){
          Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
          this->Ajouter(ptTS1);
        }
        else if(mode=="I"){
          int numeron = stoi(param1);
          int numerom = stoi(param2);
          if(nbTrajetParcouru<=numerom && nbTrajetParcouru>=numeron){
            Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
            this->Ajouter(ptTS1);
          }
        }
        monfic.getline(buffer,100);
        monfic.getline(buffer,100,';');
      } else if((strcmp(buffer,"Complexe")==0 || strcmp(buffer,"\nComplexe")==0)){
          nbTrajetParcouru++;
          char lectureDepart[100]; 
          monfic.getline(buffer,100, ';');
          strcpy(lectureDepart,buffer);
          char lectureDepartInitiale[100]; 
          strcpy(lectureDepartInitiale,lectureDepart);
          // cout<<"TOTAL Depart: " << buffer<<endl;
          char lectureArrivee[100]; 
          monfic.getline(buffer,100, ';');
          strcpy(lectureArrivee,buffer);
          char lectureArriveeFinale[100]; 
          strcpy(lectureArriveeFinale,lectureArrivee);
          // cout<<"TOTAL ARRIVEE " << buffer<<endl;
          TC * ptTC1 = new TC(lectureDepart, lectureArrivee);
          monfic.getline(buffer,100, ';');//Buffer apres l'arrivee total
          while(strcmp(buffer,"\nComplexe")!=0 && strcmp(buffer,"\nSimple")!=0){
            // cout<<"depart sous trajet" << buffer<<endl;
            char lectureDepart[100]; 
            strcpy(lectureDepart,buffer);
            char lectureArrivee[100]; 
            monfic.getline(buffer,100, ';');
            strcpy(lectureArrivee,buffer);
            // cout<<"arrivee sous trajet" << buffer<<endl;
            char lectureLocomotion[100]; 
            monfic.getline(buffer,100, ';');
            strcpy(lectureLocomotion,buffer);
            // cout<<"locomotion sous trajet" << buffer<<endl;
            TS * ptTS = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
            ptTC1 -> AjouterTC(ptTS);
            monfic.getline(buffer,100, ';');
          }

          if(mode=="T" || mode=="C"){
            this->Ajouter(ptTC1);
          }else if(mode=="D" && param1==(string) lectureDepartInitiale){
            this->Ajouter(ptTC1);
          }else if(mode=="A" && param2==(string) lectureArriveeFinale){
            this->Ajouter(ptTC1);
          }else if(mode=="AD" && param1==(string) lectureDepartInitiale && param2==(string) lectureArriveeFinale){
            this->Ajouter(ptTC1);
          }else if(mode=="I"){
            int numeron = stoi(param1);
            int numerom = stoi(param2);
            if(nbTrajetParcouru<=numerom && nbTrajetParcouru>=numeron){
              this->Ajouter(ptTC1);
            }
          }
      }
    }
    delete[] buffer;
    // cout << "FIN BUFFER" << endl;
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