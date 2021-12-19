/*************************************************************************
                           Code Catalogue 
                             -------------------
    début                : 13/11/2021
    copyright            : (C) 2021 par fLANDRE Corentin et THOMAS Colin
    e-mail               : corentin.flandre@insa-lyon.fr 
                           colin.thomas1@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <Xxx> (fichier Xxx.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <istream>
#include "Catalogue.h"
#include "ListeTrajet.h"
// #include "Xxx.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
Catalogue::Catalogue()
// Algorithme :
{
  size=0;
  maListeTrajet=ListeTrajet();

  #ifdef MAP
    cout << "Construction de Catalogue" << endl;
  #endif
}
Catalogue::~Catalogue()
// Algorithme :
{

  #ifdef MAP
    cout << "Destruction de Catalogue" << endl;
  #endif
}

void Catalogue::AjouterUnTrajet( Trajet * $unTrajet)
// Algorithme :
{
    size++; 
    maListeTrajet.Ajouter($unTrajet);
}

void Catalogue::Chercher(const char * Depart, const char * Arrivee)
{
  maListeTrajet.Chercher(Depart, Arrivee);
}

void Catalogue::Charger(const char * nomCharge){
  string nomFichierSauvegarde = (string) nomCharge;
  nomFichierSauvegarde = nomFichierSauvegarde + ".csv";
  //cout << "STRING "<< nomFichierSauvegarde << endl;
  ifstream fic;
  fic.open(nomFichierSauvegarde);
  if(!fic){
    cerr << "Erreur d'ouverture du fichier " << nomCharge << endl;
    fic.close();
    return;
  }
  cout << "Fichier existant" <<endl;
  cout << "debut charger liste" <<endl;
  maListeTrajet.Charger(fic);
  cout << "fin charger liste" << endl;
  fic.close();
  size = maListeTrajet.getSize();
}

void Catalogue::Sauvegarder(const char * nomSauvegarde, const char * condition)
{
  string nomFichierSauvegarde = (string) nomSauvegarde;
  nomFichierSauvegarde = nomFichierSauvegarde + ".csv";
  ofstream fic ( nomFichierSauvegarde );
  streambuf *oldCoutBuffer = cout.rdbuf ( fic.rdbuf ( ) );
  string texteSauvegarde = maListeTrajet.TexteSauvegarde();
  if(strcmp(condition,"S")==0){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;

    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if(buffer.find("Simple",0)<100){
        nvTexte+=buffer;
      }
      start=end+1;
    }
    cout << nvTexte << endl;
  }else if(strcmp(condition,"C")==0){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;

    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if(buffer.find("Complexe",0)<100){
        nvTexte+=buffer;
      }
      start=end+1;
    }
    cout << nvTexte << endl;
  }else if(condition[0]=='D'){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;
    string depart=(string) condition;
    depart=depart.substr(1,depart.length());
    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if(buffer.find("Simple;"+depart,0)<100 || buffer.find("Complexe;"+depart,0)<100){
        nvTexte+=buffer;
      }
      start=end+1;
    }
    cout << nvTexte << endl;
  }else if(condition[0]=='A'){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;
    string arrivee=(string) condition;
    arrivee=arrivee.substr(1,arrivee.length());
    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if( !(buffer.find("Simple;"+arrivee,0)<100 || buffer.find("Complexe;"+arrivee,0)<100) &&(buffer.find(arrivee,0)<100)){
        nvTexte+=buffer;
      }
      start=end+1;
    }
    cout << nvTexte << endl;
  }else{
    cout << texteSauvegarde << endl; //A CHANGER ??
  }
  cout.rdbuf ( oldCoutBuffer );
  fic.close ( );
}

const void Catalogue::AffichageCatalogue(){
  cout << "\n\n*************************************************" <<endl;
  cout <<     "******** DEBUT CATALOGUE DU GROUPE B3207 ********" <<endl;
  cout <<     "************* Composé" ;
  ((size>1) ? ( cout<< "s ") : (cout<< " "));
  cout<<"de " << size << " trajet";
  ((size>1) ? ( cout<< "s ") : (cout<< "  "));
  cout<< "*************" <<endl;
  maListeTrajet.Affichage();
  cout << "\n-------------------------------------------" << endl;
      cout << "-------------------------------------------" << endl;
  cout <<     "\n*************************************************" <<endl;
  cout <<     "******** FIN CATALOGUE DU GROUPE B3207 **********" <<endl;
  cout <<     "*************************************************\n\n" <<endl;
}
//----- fin de AffichageCatalogue

