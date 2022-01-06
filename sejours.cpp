/*************************************************************************
                           Code Main 
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
//g++ -o TP2 Trajet.cpp Main.cpp
#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>
#include "Trajet.h"
#include "Catalogue.h"
#include "TS.h"
#include "TC.h"
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
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void lireLigne(char * fichier){
  //Mode d'emploi:  Lecture d'une ligne jusqu'au retour à la ligne
  //                et pointeur de chaine entré en paramètre
  //Contrat:        L'allocation de l'espace de la chaine de
  //                caractères est déjà faite et l'espace prévu est
  //                suffisant pour ce que va entrer l'utilisateur
  char lecture;
  lecture=fgetc(stdin);
  int i=0;
  while(lecture!='\n' && lecture!=EOF && lecture!=';'){
    fichier[i]=lecture;
    i++;
    lecture=fgetc(stdin);
  }
  fichier[i]='\0';
} //----- Fin de lireLigne

int atoi(char * nombre){
  //Mode d'emploi:  Entrée d'une chaine de caractère de chiffres
  //                en paramètre, sortie de l'entier correspondant 
  //                en return
  //                La lecture de la chaine s'arrete au caractère \0
  //                ou pour tout caractère invalide
  //Contrat:        La chaine de caractère est une suite de chiffres
  //                ASCII terminant par le caractère \0
  int res=0;
  int i=0;
  int puissance=1;
  while(nombre[i]!='\0'&& nombre[i]>=48 && nombre[i]<=57){
    res=(nombre[i]-48)*puissance;
    puissance=puissance*10;
    i++;
  }
  return res;
} //----- Fin de atoi





int main()
// Algorithme :
// Classe Main permettant de faire la démo du TP 
// 'POO1-TP2-B3207-FLANDRE-THOMAS'  
{
  //10 décembre 12h00, dans le zip : code source + doc
  // make + ./sejours valgrind + ./sejours
  //cout <<"DEBUT DEMOs;lfjkkghslkd"<< endl; 
  Catalogue catalogue;
  /*TS TS1("Paris", "Marseille", "Bateau");
  Trajet * ptTS1 = & TS1;
  TS TS2("Lyon", "NLF", "Roulade arriere");
  Trajet * ptTS2 = & TS2;
  // TS1.Affichage();
  catalogue.AjouterUnTrajet(ptTS1);
  catalogue.AjouterUnTrajet(ptTS2);
  //catalogue.AffichageCatalogue();

  TC TC1("Paris", "NLF");
  TC1.AjouterTC(ptTS1);
  TC1.AjouterTC(ptTS2);
  //TC1.AfficherTC();

  catalogue.AjouterUnTrajet( & TC1);
  catalogue.AjouterUnTrajet(ptTS1);*/
  //catalogue.AffichageCatalogue();
  //cout <<"FIN DEMO"<< endl; 
  char lecture[100] ="_";
  char lectureDepart[100] ="_";
  char lectureArrivee[100] ="_";
  char stockChar[100];
  char lectureLocomotion[100] ="_";
  char lectureModeChargement[100] ="_";
  MONAFFICHAGE;
  cout << left << "Etirez votre terminal pour voir 70 caractrères"<<endl;
  MONAFFICHAGE;
  cout << left <<"Ecrivez le chiffre correspondant à l'action voulue"<<endl;
  cout << left<<vert  << "1" << reset;
  MATAILLE(68);
  cout<< left << " -Imprimer Catalogue" <<  internal <<endl;
  cout<< left <<vert  << "2" << reset;
  MATAILLE(68);
  cout<< left << " -Ajouter un Trajet Simple" <<  internal <<endl;
  cout << left<<vert  << "3" << reset;
  MATAILLE(68);
  cout<< left << " -Ajouter un Trajet Complexe" <<  internal <<endl;
  cout << left<<vert  << "4" << reset;
  MATAILLE(68);
  cout << left<< " -Chercher un Trajet" <<  internal <<endl;
  cout<< left <<vert  << "5" << reset;
  MATAILLE(68);
  cout<< left << " -Charger une sauvegarde" <<  internal <<endl;
  cout<< left <<vert  << "6" << reset;
  MATAILLE(68);
  cout<< left << " -Sauvegarder des trajets actuels" <<  internal <<endl;
  cout << left<<vert  << "q" << reset;
  MATAILLE(68);
  cout<< left << " -Quitter l'application" <<  internal <<endl;
  MONAFFICHAGE;
    cout << left << ""<< endl;
  lireLigne(lecture);
  while (strcmp(lecture, "q") != 0) {
    
    if (strcmp(lecture, "1") == 0) {
      catalogue.AffichageCatalogue();

    } else if (strcmp(lecture, "2") == 0) {
      MONAFFICHAGE;
      cout <<left<< "Entrez un départ : " << endl;
      lireLigne(lectureDepart);
      MONAFFICHAGE;
      cout <<left<< "Entrez une arrivée : " << endl;
      lireLigne(lectureArrivee);
      MONAFFICHAGE;
      cout <<left<< "Entrez un moyen de locomotion : " << endl;
      lireLigne(lectureLocomotion);

      Trajet * ptTS1 = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
      catalogue.AjouterUnTrajet(ptTS1);

    } else if (strcmp(lecture, "3") == 0) {
      MONAFFICHAGE;
      cout <<left<< "Entrez un départ : " << endl;
      lireLigne(lectureDepart);
      MONAFFICHAGE;
      cout <<left<< "Entrez une arrivée : " << endl;
      lireLigne(lectureArrivee);

      TC * ptTC1 = new TC(lectureDepart, lectureArrivee);
      strcpy(stockChar, lectureArrivee);
      MONAFFICHAGE;
      cout <<left<< "Entrez le nombre de sous-trajets : " << endl;
      lireLigne(lecture);
      int val=atoi(lecture);
      TS * ptTS;

      for (int i = 0; i < val - 1; i++) {
        MONAFFICHAGE;
        cout <<left<< "Entrez l'arrivée du sous-trajet :" << i + 1 << endl;
        lireLigne(lectureArrivee);
        MONAFFICHAGE;
        cout <<left<< "Entrez le moyen de locomotion du sous trajet :" << i + 1 << endl;
        lireLigne(lectureLocomotion);

        ptTS = new TS(lectureDepart, lectureArrivee, lectureLocomotion);
        ptTC1 -> AjouterTC(ptTS);
        strcpy(lectureDepart, lectureArrivee);
      }
      MONAFFICHAGE;
      cout <<left<< "Entrez le moyen de locomotion du sous trajet :" << val << endl;
      lireLigne(lectureLocomotion);

      ptTS = new TS(lectureDepart, stockChar, lectureLocomotion);
      ptTC1 -> AjouterTC(ptTS);
      catalogue.AjouterUnTrajet(ptTC1);

    } else if (strcmp(lecture, "4") == 0) {

      char lectureDepart[100];
      char lectureArrivee[100];
      MONAFFICHAGE;
      cout << left<<"Entrez le départ du trajet cherché :" << endl;
      lireLigne(lectureDepart);
      MONAFFICHAGE;
      cout << left<<"Entrez l'arrivée du trajet cherché :" << endl;
      lireLigne(lectureArrivee);
      catalogue.Chercher(lectureDepart, lectureArrivee);
    } else if (strcmp(lecture, "5") == 0) {
      MONAFFICHAGE;
      cout << left<<"Voulez-vous faire un chargement avec critères de sélection ? (Y/N)" << endl;
      lireLigne(lectureModeChargement);
      if(strcmp(lectureModeChargement,"Y") == 0){
        MONAFFICHAGE;
        cout <<left<< "Vous voulez faire un chargement en fonction de :"<< endl;
        MONAFFICHAGE;
        cout << left<< "....Du type de trajet :"<< endl;
        MONAFFICHAGE;
        cout << left <<"........S -pour des trajets Simples"<< endl;
        MONAFFICHAGE;
        cout << left<< "........C -pour des trajets Complexes"<< endl;
        MONAFFICHAGE;
        cout << left << "....D -De la ville de départ"<< endl;
        MONAFFICHAGE;
        cout <<left << "....A -De la ville d'arrivée"<< endl;
        MONAFFICHAGE;
        cout << left << "....AD -Des villes de départ et d'arrivée "<< endl;
        MONAFFICHAGE;
        cout << left << "....I -De l'intervalle de trajets"<< endl<< endl;
        MONAFFICHAGE;
        lireLigne(lectureModeChargement);
        string leModeSelectionne = catalogue.ModeChargement(lectureModeChargement);
        if(leModeSelectionne=="S" || leModeSelectionne=="C"){
          cout << "Entrez le nom du fichier sauvegarde à charger :" << endl;
          lireLigne(stockChar);
          catalogue.Charger(stockChar, lectureModeChargement,"0", "0");
        }else if(leModeSelectionne=="D"){
          MONAFFICHAGE;
          cout <<left<< "Entrez le nom de ville de départ pour les trajets à charger: "<<endl;
          lireLigne(lectureDepart); 
          MONAFFICHAGE;
          cout << left<<"Entrez le nom du fichier sauvegarde à charger :" << endl;
          lireLigne(stockChar);
          catalogue.Charger(stockChar, lectureModeChargement,lectureDepart, "0");
        }else if(leModeSelectionne=="A"){
          MONAFFICHAGE;
          cout <<left<< "Entrez le nom de ville d'arrivee pour les trajets à charger: "<<endl;
          lireLigne(lectureArrivee);
          MONAFFICHAGE;
          cout << left<<"Entrez le nom du fichier sauvegarde à charger :" << endl;
          lireLigne(stockChar);
          catalogue.Charger(stockChar, lectureModeChargement,"0", lectureArrivee);
        }else if(leModeSelectionne=="AD"){
          MONAFFICHAGE;
          cout <<left<< "Entrez le nom de ville de départ pour les trajets à charger: "<<endl;
          lireLigne(lectureDepart);
          MONAFFICHAGE;
          cout << left<<"Entrez le nom de ville d'arrivee pour les trajets à charger: "<<endl;
          lireLigne(lectureArrivee);
          MONAFFICHAGE;
          cout << left<<"Entrez le nom du fichier sauvegarde à charger :" << endl;
          lireLigne(stockChar);
          catalogue.Charger(stockChar, lectureModeChargement,lectureDepart, lectureArrivee);
        }else if(leModeSelectionne=="I"){
          MONAFFICHAGE;
          cout << left<<"Entrez le numéro du premier trajet à enregistrer: "<<endl;
          lireLigne(lectureDepart);
          MONAFFICHAGE;
          cout << left<<"Entrez le numéro du dernier trajet à enregistrer: "<<endl;
          lireLigne(lectureArrivee);
          MONAFFICHAGE;
          cout <<left<< "Entrez le nom du fichier sauvegarde à charger :" << endl;
          lireLigne(stockChar);
          if(catalogue.ModeIntervalle(lectureDepart, lectureArrivee)){
            catalogue.Charger(stockChar, lectureModeChargement,lectureDepart, lectureArrivee);
          }
        }
      }else if(strcmp(lectureModeChargement,"N")==0){
        MONAFFICHAGE;
        cout << left<< "Entrez le nom du fichier sauvegarde à charger :" << endl;
        lireLigne(stockChar);
        catalogue.Charger(stockChar,"T","0", "0");
      }




    }else if (strcmp(lecture, "6") == 0)
    {
      bool erreurEntree = false;      //permet d'enregistrer une erreur d'entree
      bool erreurIntervalle = false;  //permet d'enregistrer une erreur d'intervalle
      char condition[100];            //la suite de caractère enregistrant tous les choix de l'utilisateur
      MONAFFICHAGE;
      cout << left << "Voulez-vous faire une sauvegarde avec critères de sélection ? (Y/N)" << endl;
      lireLigne(condition);
      if (strcmp(condition, "Y") == 0)
      {
        MONAFFICHAGE;
        cout << left << "Vous voulez faire une sauvegarde en fonction de :" << endl;
        MONAFFICHAGE;
        cout << left << "....Du type de trajet :" << endl;
        MONAFFICHAGE;
        cout << left << "........S -pour des trajets Simples" << endl;
        MONAFFICHAGE;
        cout << left << "........C -pour des trajets Complexes" << endl;
        MONAFFICHAGE;
        cout << left << "....D -De la ville de départ" << endl;
        MONAFFICHAGE;
        cout << left << "....A -De la ville d'arrivée" << endl;
        MONAFFICHAGE;
        cout << left << "....AD -Des villes de départ et d'arrivée" << endl;
        MONAFFICHAGE;
        cout << left << "....I -De l'intervalle de trajets" << endl;
        lireLigne(condition);
        if (strcmp(condition, "D") == 0)
        {
          MONAFFICHAGE;
          cout << left << "Quel départ voulez-vous enregistrer ?" << endl;
          char depart[100];
          lireLigne(depart);
          strcat(condition, ",");
          strcat(condition, depart);
        }
        else if (strcmp(condition, "A") == 0)
        {
          MONAFFICHAGE;
          cout << left << "Quel arrivée voulez-vous enregistrer ?" << endl;
          char arrivee[100];
          lireLigne(arrivee);
          strcat(condition, ",");
          strcat(condition, arrivee);
        }
        else if (strcmp(condition, "AD") == 0)
        {
          MONAFFICHAGE;
          cout << left << "Quel départ voulez-vous enregistrer ?" << endl;
          char depart[100];
          lireLigne(depart);
          strcat(condition, depart);
          strcat(condition, ",");
          MONAFFICHAGE;
          cout << left << "Quel arrivée voulez-vous enregistrer ?" << endl;
          char arrivee[100];
          lireLigne(arrivee);
          strcat(condition, arrivee);
        }
        else if (strcmp(condition, "I") == 0)
        {
          MONAFFICHAGE;
          cout << left << "A partir de quel trajet voulez vous enregistrer ?" << endl;
          char depart[100];
          lireLigne(depart);
          strcat(condition, depart);
          strcat(condition, ",");
          MONAFFICHAGE;
          cout << left << "Combien de trajets ?" << endl;
          char nbrTraj[100];
          lireLigne(nbrTraj);
          strcat(condition, nbrTraj);
          if(atoi(depart)<1 || atoi(nbrTraj)<1){
            erreurIntervalle=true;
            cerr<< rouge<< "Erreur"<<reset; 
            cout<< left  <<" -> il y a incohérence avec l'intervalle [";
            cout << left << depart;
            cout <<";";
            cout << left << (atoi(depart)+atoi(nbrTraj));
            MATAILLE(70-6-43-6);
            cout.fill('.');
            cout <<left << "]" << endl;
          }
        }
        else if (strcmp(condition, "S") != 0 && strcmp(condition, "C") != 0)
        {
          erreurEntree = true;
        }
      }else if (strcmp(condition, "N") != 0)
      {
        erreurEntree = true;
      }
      if (!erreurEntree && !erreurIntervalle)
      {
        MONAFFICHAGE;
        cout << left << "Entrez le nom du fichier de sauvegarde :" << endl;
        lireLigne(stockChar);

        string nomFichierSauvegarde = (string)stockChar;
        nomFichierSauvegarde = nomFichierSauvegarde + ".csv";
        fstream fic1;
        fic1.open(nomFichierSauvegarde);
        if (!fic1.fail())
        {
          MONAFFICHAGE;
          cout << left << "Le fichier existe, voulez vous l'écraser ? (Y/N)" << endl;
          lireLigne(lecture);
          if (strcmp(lecture, "Y") == 0)
          {
            catalogue.Sauvegarder(stockChar, condition);
          }
        }
        else
        {
          catalogue.Sauvegarder(stockChar, condition);
        }
      }
      else if(!erreurIntervalle){                     catalogue.ModeChargement(condition);
      }
    } else {
      
      cerr <<left<<rouge<< "Erreur"<<reset;
      MATAILLE(70-6);
      cout.fill('.');
      cout <<left << " -> Commande/Requête non reconnue" << endl;
    }
    MONAFFICHAGE;
    cout << left << ""<< endl;
    MONAFFICHAGE;
    MONAFFICHAGE;
  cout << left <<"Ecrivez le chiffre correspondant à l'action voulue"<<endl;
  cout << left<<vert  << "1" << reset;
  MATAILLE(68);
  cout<< left << " -Imprimer Catalogue" <<  internal <<endl;
  cout << left<<vert  << "2" << reset;
  MATAILLE(68);
  cout << left<< " -Ajouter un Trajet Simple" <<  internal <<endl;
  cout << left<<vert  << "3" << reset;
  MATAILLE(68);
  cout<< left << " -Ajouter un Trajet Complexe" <<  internal <<endl;
  cout << left<<vert  << "4" << reset;
  MATAILLE(68);
  cout<< left << " -Chercher un Trajet" <<  internal <<endl;
  cout<< left <<vert  << "5" << reset;
  MATAILLE(68);
  cout << left<< " -Charger une sauvegarde" <<  internal <<endl;
  cout<< left<<vert  << "6" << reset;
  MATAILLE(68);
  cout<< left << " -Sauvegarder des trajets actuels" <<  internal <<endl;
  cout<< left <<vert  << "q" << reset;
  MATAILLE(68);
  cout<< left << " -Quitter l'application" <<  internal <<endl;
    MONAFFICHAGE;
    cout << left << ""<< endl;
    lireLigne(lecture);
  }
  return 0;
} //----- fin de Main


