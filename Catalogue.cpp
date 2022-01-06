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
#define MONAFFICHAGE cout.width(70); cout.fill('.')
#define MATAILLE(n) cout.width(n);
#define PASMONAFFICAHGE cout.fill(' ');
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
const char ROUGE [] = { 033, '[','3', '1', 'm'};
const char RESET [ ] = { 033,'[','m',017 };
const char VERT[] = {033, '[','3', '2', 'm'};

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static ostream & rouge ( ostream & os){
    os.write(ROUGE, sizeof(ROUGE));
    return os;
}
static ostream & vert ( ostream & os){
    os.write(VERT, sizeof(VERT));
    return os;
}
static ostream & reset ( ostream & os){
    os.write(RESET, sizeof(RESET));
    return os;
}

// static int atoi(char * nombre)
//   //Mode d'emploi:  Entrée d'une chaine de caractère de chiffres
//   //                en paramètre, sortie de l'entier correspondant 
//   //                en return
//   //                La lecture de la chaine s'arrete au caractère \0
//   //                ou pour tout caractère invalide
//   //Contrat:        La chaine de caractère est une suite de chiffres
//   //                ASCII terminant par le caractère \0
//   {
//   int res=0;
//   int i=0;
//   int puissance=1;
//   while(nombre[i]!='\0'&& nombre[i]>=48 && nombre[i]<=57){
//     res=(nombre[i]-48)*puissance;
//     puissance=puissance*10;
//     i++;
//   }
//   return res;
// } //----- Fin de atoi
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



//PARTIE CHARGEMENT 
void Catalogue::Charger(const char * nomCharge, const char * mode, const char* parametre1, const char* parametre2){
  int memSizeCatalogue = size;
  string nomFichierSauvegarde = (string) nomCharge;
  string modeSelectionne = (string) mode;
  string param1 = (string) parametre1;
  string param2 = (string) parametre2;
  
  cout <<left<< "Mode de sélection : ";
  MATAILLE(70-20);
  cout.fill('.');
  cout << left <<modeSelectionne << endl; 
  nomFichierSauvegarde = nomFichierSauvegarde + ".csv";
  //cout << "STRING "<< nomFichierSauvegarde << endl;
  ifstream fic;
  fic.open(nomFichierSauvegarde);
  if(!fic){
    // MESSAGE ERREUR
      cerr <<left<<rouge<< "Erreur"<<reset;
      MATAILLE(70-6);
      cout.fill('.');
      cout <<left << " -> Le fichier est introuvable" << endl;
    fic.close();
    return;
  }

  // cout << "debut charger liste" <<endl;
  maListeTrajet.Charger(fic, modeSelectionne, param1, param2);
  // cout << "fin charger liste" << endl;
  fic.close();
  size = maListeTrajet.getSize();
  MONAFFICHAGE;
  cout << "Fichier existant et chargé correctement" <<endl;

  cout<<left<<"..";
  cout <<left<< size -memSizeCatalogue;
  MATAILLE(70-4);
  cout.fill('.');
  cout <<left<< " trajets chargés selon les critères de selections" <<endl;
}


string Catalogue::ModeChargement(const char * mode){
  string modeSelectionne = (string) mode;
  if(modeSelectionne!="S" && modeSelectionne!="D" && modeSelectionne!="A" && modeSelectionne!="AD" && modeSelectionne!="C" && modeSelectionne!="I" && modeSelectionne!="T"){
    // Traiter l'exception où le mode n'existe pas
    cerr <<left<<rouge<< "Erreur"<<reset;
      cout <<left << " -> Le mode de chargement ";
      cout <<left<< mode<< endl;
       MATAILLE(70-6-27);
       cout.fill('.');
       cout << left << " est invalide\n" << endl;
  }
  return modeSelectionne;
}

bool Catalogue::ModeIntervalle (const char* n, const char* m){
  int numeron = atoi(n);
  int numerom = atoi(m);
  if(!(numerom-numeron+1>=1)){
    cerr<< rouge<< "Erreur"<<reset; 
    cout<< left  <<" -> il y a incohérence avec l'intervalle [";
    cout << left << numeron;
    cout <<";";
    cout << left << numerom;
    MATAILLE(70-6-43-6);
    cout.fill('.');
    cout <<left << "]" << endl;
    return false;
  }
  return true;
}








//PARTIE SAUVEGARDE
void Catalogue::Sauvegarder(const char * nomSauvegarde, const char * condition)
{
  string nomFichierSauvegarde = (string) nomSauvegarde;
  nomFichierSauvegarde = nomFichierSauvegarde + ".csv"; 
  ofstream fic ( nomFichierSauvegarde );
  streambuf *oldCoutBuffer = cout.rdbuf ( fic.rdbuf ( ) ); // On envoie cout sur le fichier ouvert
  string texteSauvegarde = maListeTrajet.TexteSauvegarde(); // On récupère tout ce qu'on va écrire dans le fichier de sauvegarde

  //FORMATAGE DE LA SAUVEGARDE EN FONCTION DE L'OPTION : 
    //TRAJETS SIMPLES : 
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
        nvTexte+="\n";
      }
      start=end+1;
    }
    cout << nvTexte << endl;

    //TRAJETS COMPLEXES : 
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
        nvTexte+="\n";
      }
      start=end+1;
    }
    cout << nvTexte << endl;

    //EN FONCTION DU DEPART : 
  }else if(condition[0]=='D'){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;
    string depart=(string) condition;
    depart=depart.substr(2,depart.length());
    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if(buffer.find("Simple;"+depart,0)<100 || buffer.find("Complexe;"+depart,0)<100){
        nvTexte+=buffer;
        nvTexte+="\n";
      }
      start=end+1;
    }
    cout << nvTexte << endl;

    //EN FONCTION DE L'ARRIVEE : 
  }else if(condition[0]=='A' && condition[1]!='D'){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;
    string arrivee=(string) condition;
    arrivee=arrivee.substr(2,arrivee.length());
    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if( !(buffer.find("Simple;"+arrivee,0)<100 || buffer.find("Complexe;"+arrivee,0)<100) &&(buffer.find(arrivee,0)<100)){
        nvTexte+=buffer;
        nvTexte+="\n";
      }
      start=end+1;
    }
    cout << nvTexte << endl;
    
    //EN FONCTION DU DEPART ET DE L'ARRIVEE : 
  }else if(condition[0]=='A' && condition[1]=='D'){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;
    string depart=(string) condition;
    string arrivee=(string) condition;
    depart=depart.substr(2,depart.find(",")-2);
    arrivee=arrivee.substr(arrivee.find(",")+1,arrivee.length());
    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if(buffer.find("Simple;"+depart,0)<100 || buffer.find("Complexe;"+depart,0)<100){
        if( !(buffer.find("Simple;"+arrivee,0)<100 || buffer.find("Complexe;"+arrivee,0)<100) &&(buffer.find(arrivee,0)<100)){
          nvTexte+=buffer;
          nvTexte+="\n";
        }
      }
      start=end+1;
    }
    cout << nvTexte << endl;

    //EN FONCTION DE l'INTERVALLE : 
  }else if(condition[0]=='I'){
    string nvTexte;
    string buffer;
    unsigned int start = 0;
    unsigned int end = 0;
    string trajDepart=(string) condition;
    string nmbreTraj=(string) condition;
    trajDepart=trajDepart.substr(1,trajDepart.find(",")-1);
    nmbreTraj=nmbreTraj.substr(nmbreTraj.find(",")+1,nmbreTraj.length());
    int trajDepartInt=stoi(trajDepart)-1;
    int nmbreTrajInt=stoi(nmbreTraj);
    int i=0;

    while (start!= texteSauvegarde.length()){
      end = texteSauvegarde.find('\n', start);
      buffer=(texteSauvegarde.substr(start, end - start));
      if(i>=trajDepartInt && i<(trajDepartInt+nmbreTrajInt)){
        nvTexte+=buffer;
        nvTexte+="\n";
      }
      i++;
      start=end+1;
    }
    cout << nvTexte << endl;

    //SANS CONDITIONS : 
  }else if (strcmp(condition,"N")==0){
    cout << texteSauvegarde << endl; //A CHANGER ??
  }
  cout.rdbuf ( oldCoutBuffer ); // remise en place de cout sur la sortie standard
  fic.close ( );
}

const void Catalogue::AffichageCatalogue(){
  cout.fill('*');
  cout.width(70);
  cout << left<<"*" <<endl;
  cout << left << vert <<"DEBUT CATALOGUE DU GROUPE B3207"<<reset;
  cout.fill('*');
  cout.width(70-31);
  cout << "*"<<endl;
  cout <<"Composé" ;
  ((size>1) ? ( cout<< "s ") : (cout<< " "));
  cout<<"de " << size << " trajet";
  ((size>1) ? ( cout<< "s ") : (cout<< "  "));
  cout.fill('*');
  cout.width(70-22);
  cout<<left<< " " <<endl;
  maListeTrajet.Affichage();
  cout.fill('*');
  cout.width(70);
  cout <<left<<"*" <<endl;

  cout <<left<<vert<<"FIN CATALOGUE DU GROUPE B3207"<< reset;
  cout.fill('*');
  cout.width(70-29);
  cout <<endl;
  cout.fill('*');
  cout.width(70);
  cout <<left<< "*" <<endl;
}
//----- fin de AffichageCatalogue

