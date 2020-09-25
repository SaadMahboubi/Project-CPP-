#include <iostream>
#include <string>
#include <unordered_map>
#include "ticket.hpp"
#include "vconsigne.hpp"

using namespace std;

/*
//Bagage
typedef struct {
  unsigned int volume;
  string nom;
} BAG;
*/

string boolAuString(bool Bool){
    if(Bool){
        return "Oui";
    }else{
        return "Non";
    }
}

int main(){

    Ticket ticket1 = Ticket();
    Ticket ticket2 = Ticket();

    size_t tick1Hash = ticket1.hash_code();
    size_t tick2Hash = ticket2.hash_code();

    bool testEga12 = ticket1==(ticket2);
    bool testEga11 = ticket1==(ticket1);

    bool testDiff12 = ticket2!=(ticket1);
    bool testDiff22 = ticket2!=(ticket2);

    cout << "Bonjour" << endl << endl << endl;

    cout << "après code de hashage ticket 1 devient " << tick1Hash << endl;
    cout << "après code de hashage ticket 2 devient " << tick2Hash << endl << endl;

    cout << "ticket 1 et ticket 2 sont-ils égaux : " << boolAuString(testEga12) << endl;
    cout << "ticket 1 et ticket 1 sont-ils égaux : " << boolAuString(testEga11) << endl;

    cout << "ticket 1 et ticket 2 sont-ils différents : " << boolAuString(testDiff12) << endl;
    cout << "ticket 2 et ticket 2 sont-ils différents : " << boolAuString(testDiff22) << endl << endl;

    vector<pair<unsigned int,unsigned int> > listeCasier { make_pair<unsigned int,unsigned  int>(50, 4), make_pair<unsigned int,unsigned int>(70, 5) };

    Vconsigne Vcons = Vconsigne(listeCasier);

    try {
        unsigned int volumen1;    
        BAG bagageX;
        cout << "Bonjour Mr/Mde entrez le volume de votre bagage (volume dispo inferieur ou egale à 4 ou 5): " << endl << endl;
        cin >> volumen1;
        bagageX.nom = "Bagage n1";
        bagageX.volume = volumen1;
        Ticket tickX = Vcons.ajoutBagage(bagageX);

        string rep1;

        cout << "Mr/Mme voulez vous retirez votre bagage? (oui/non)" << endl;
        cin >> rep1;
        if(rep1 == "oui"){
            Vcons.retraitBagage(tickX);
            cout << "veuillez récupérer votre bagage..." << endl;
        }else{
            cout << "le bagage ne va pas être récupéré " << endl << endl;
        }
    } catch(exception const& e){
        cerr << e.what() << endl;
    }

    try {
        BAG bagageY;
        bagageY.nom = "Bagage de Mme Y";
        bagageY.volume = 5;
        Ticket tickY = Vcons.ajoutBagage(bagageY);
        Vcons.retraitBagage(tickY);
        cout << "Madame Y veuillez récupérer votre bagage..." << endl <<endl;;
    } catch(exception const& e){
        cerr << e.what() << endl;
    }

    
    
    try {
        cout << "il y a au moins un casier avec un volume d'au moins 4 ? " << endl;
        cout << boolAuString(Vcons.testVolumeCasier(4)) << endl;;
        cout << "il y a au moins un casier avec un volume d'au moins 7 ? " << endl;
        cout << boolAuString(Vcons.testVolumeCasier(7)) << endl;;
        cout << "il y a au moins un casier avec un volume d'au moins 5 ? " << endl;
        cout << boolAuString(Vcons.testVolumeCasier(5)) << endl;;
    } catch(exception const& e){
        cerr << e.what() << endl;
    }

}

/* après éxécution : 
Bonjour


après code de hashage ticket 1 devient 1316
après code de hashage ticket 2 devient 1963

ticket 1 et ticket 2 sont-ils égaux : Non
ticket 1 et ticket 1 sont-ils égaux : Oui
ticket 1 et ticket 2 sont-ils différents : Oui
ticket 2 et ticket 2 sont-ils différents : Non

Bonjour Mr/Mde entrez le volume de votre bagage (volume dispo : 4 ou 5):

5
Mr/Mme voulez vous retirez votre bagage? (oui/non)
non
le bagage ne va pas être récupéré

veuillez récupérer votre bagage...

il y a au moins un casier avec un volume d'au moins 4 ?
Oui
il y a au moins un casier avec un volume d'au moins 7 ?
Non
il y a au moins un casier avec un volume d'au moins 5 ?
Oui

*/